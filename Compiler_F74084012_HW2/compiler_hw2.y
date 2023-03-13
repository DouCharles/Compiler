/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
//     #define YYDEBUG 1
//     int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
	extern char id[100];

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();

    extern FILE *yyin;
	extern char *yytext;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static int lookup_symbol();
    static void dump_symbol();
	static void type_error();
    /* Global variables */
    bool HAS_ERROR = false;
	int level = 0;
	int addr = 0;
	typedef struct entry{
		int index;
		char name[100];
		char type[10];
		int addr;
		int lineno;
		char func_sig[100];
		struct entry* next;
	}ENTRY;

	typedef struct table{
		int level;
		struct entry* entry_first;
		struct table* next;
	}TABLE;

	TABLE *head = NULL;
	char func_sig[100];

	char type[10];
	char *typeid;
	int ti;
	char operand[10];
	char parameters[1000];
	int parameters_num = 0;
	int atlineno, symbol_level;
	char *sub_str;
/*	ENTRY *type_1;
	ENTRY *type_2;*/
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
	bool b_val;
	char func_name[100];
	char type_name[20];
	char id_name[100];	
    /* ... */
}

/* Token without return */
%token VAR NEWLINE  
%token INT FLOAT BOOL STRING /*type*/
%token INC DEC GEQ LOR LAND /*operator*/
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN /*+= -= ...*/
%token IF ELSE FOR SWITCH CASE /*basic language*/
%token PRINT PRINTLN  /*print*/
%token LESS_EQU EQU NOT_EQU /*EQU*/
%token TRUE FALSE
%token PACKAGE FUNC ID
%token RETURN DEFAULT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT 
%token <f_val> FLOAT_LIT
/*%token <s_val> ID*/

/* Nonterminal with return, which need to sepcify type */
/*%type <f_val> Mul_Quo;*/
/*%type <f_val> Literal;*/

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : GlobalStatementList   {dump_symbol(--level);}
;

GlobalStatementList 
	: GlobalStatement 
    | GlobalStatementList GlobalStatement
;

GlobalStatement
    : PackageStmt NEWLINE	
    | FunctionDeclStmt	
    | NEWLINE	
;


PackageStmt
    :PACKAGE ID 	{ create_symbol(level++); printf("package: %s\n", yytext); }
;


Type
	:INT 		{$<s_val>$ = "int32"; strcpy(type, yytext); strcat(func_sig,"I");}
	|FLOAT  	{$<s_val>$ = "float32"; strcpy(type, yytext); strcat(func_sig,"F");}
	|STRING 	{$<s_val>$ = "string"; strcpy(type, yytext); strcat(func_sig,"S");}
	|BOOL 		{$<s_val>$ = "bool"; strcpy(type, yytext); strcat(func_sig,"B");}
;

Expression
	/*:UnaryExpr 
	|Expression binary_op Expression {printf("%s\n", $<s_val>2);}*/
	:Assignment_expression {$<s_val>$ = $<s_val>1;}
/*	|Expression Assignment_expression*/
;
Assignment_expression
	:Lor_expression	{$<s_val>$ = $<s_val>1;}
	|UnaryExpr assignment_op Assignment_expression {if(strcmp($<s_val>1,"error_id")==0)
														printf("error:%d: invalid operation: %s (mismatched types ERROR and %s)\n", yylineno, $<s_val>2, $<s_val>3);
	type_error($<s_val>1,$<s_val>2,$<s_val>3);
													printf("%s\n",$<s_val>2);}
;

Lor_expression
	:Lor_expression LOR Land_expression		{
	type_error($<s_val>1,"LOR",$<s_val>3);
$<s_val>$ = "bool"; printf("LOR\n");}
	|Land_expression	{$<s_val>$ = $<s_val>1;}
;

Land_expression
	:Cmp_expression		{$<s_val>$ = $<s_val>1;}
	|Land_expression LAND Cmp_expression {
	type_error($<s_val>1,"LAND",$<s_val>3);
$<s_val>$ = "bool"; printf("LAND\n");}
;

Cmp_expression
	:Add_expression		{$<s_val>$ = $<s_val>1;}
	|Cmp_expression cmp_op Add_expression	{
											type_error($<s_val>1,$<s_val>2,$<s_val>3);
											printf("%s\n",$<s_val>2);
											$<s_val>$ = "bool";
											}
;

Add_expression
	:Mul_expression		{$<s_val>$ = $<s_val>1;}
	|Add_expression add_op Mul_expression 	
		{
	type_error($<s_val>1,$<s_val>2,$<s_val>3);
												printf("%s\n",$<s_val>2);}
;

Mul_expression
	:Cast_expression	{$<s_val>$ = $<s_val>1;}
	|Mul_expression mul_op Cast_expression	{
	type_error($<s_val>1,$<s_val>2,$<s_val>3);
printf("%s\n", $<s_val>2);}
;

Cast_expression
	:UnaryExpr			{$<s_val>$ = $<s_val>1;}
	|ConversionExpr  {/*$<s_val>$ = $<s_val>1*/}
;

UnaryExpr
	:PrimaryExpr	{$<s_val>$ = $<s_val>1;}
	|unary_op Cast_expression {$<s_val>$ = $<s_val>2; printf("%s\n",$<s_val>1);}
;

/*binary_op
	:LOR
	|LAND
	|cmp_op
	|mul_op
	|add_op
;*/

assignment_op
	:'='			{$<s_val>$ = "ASSIGN";}
	|ADD_ASSIGN		{$<s_val>$ = "ADD";	}
	|SUB_ASSIGN		{$<s_val>$ = "SUB";	}
	|MUL_ASSIGN		{$<s_val>$ = "MUL";	}
	|DIV_ASSIGN		{$<s_val>$ = "QUO";	}
	|MOD_ASSIGN		{$<s_val>$ = "REM";	}
;
cmp_op
	:EQU		 {$<s_val>$ = "EQL";}
	|NOT_EQU	
	|'<'
	|LESS_EQU
	|'>'		{$<s_val>$ = "GTR";}
	|GEQ
;

add_op
	:'+'	{$<s_val>$ = "ADD";}
	|'-'	{$<s_val>$ = "SUB";}
;

mul_op
	:'*'	{$<s_val>$ = "MUL";}
	|'/'	{$<s_val>$ = "QUO";}
	|'%'	{$<s_val>$ = "REM";}
;

unary_op
	:'+'	{$<s_val>$ = "POS";}
	|'-' 	{$<s_val>$ = "NEG";}
	|'!'	{$<s_val>$ = "NOT";}
;

PrimaryExpr
	:Operand	{$<s_val>$ = $<s_val>1;}
/*	|IndexExpr*/
	|ConversionExpr
;

Operand
	:Literal	{$<s_val>$ = $<s_val>1;}
	|ID 		
					{
					ti = lookup_symbol(id)	;
					if (ti != -1)
					{
						printf("IDENT (name=%s, address=%d)\n", id, ti);
						typeid = malloc(sizeof(char) * 100);
						strcat(typeid,type);
						strcat(typeid,"_id");
						$<s_val>$ = typeid; 
					}
					else{
						printf("error:%d: undefined: %s\n", yylineno + 1, id);
						typeid = malloc(sizeof(char) *100);
						strcat(typeid,"ERROR_id");
						$<s_val>$ = typeid;
					}
					} 
	|'(' Expression ')' {$<s_val>$ = $<s_val>2;}
	|TRUE			{ $<s_val>$ = "bool"; printf("TRUE 1\n");}
	|FALSE			{ $<s_val>$ = "bool"; printf("FALSE 0\n");}
;

/*FOperand
	:FLOAT_LIT		{ $$ = $<f_val>1; printf("FLOAT_LIT %f\n", $<f_val>1);}
	|ID
	|'(' Expression ')' 
;*/

Literal
	:INT_LIT 		{ $<s_val>$ = "int32"; printf("INT_LIT %d\n",$<i_val>1);}
	|FLOAT_LIT		{ $<s_val>$ = "float32"; printf("FLOAT_LIT %f\n", $<f_val>1);}
	|'"'  Str '"'	{ $<s_val>$ = "string"; printf("STRING_LIT %s\n", $<s_val>2);}
;

Str
	:Str STRING_LIT {$<s_val>$ = $<s_val>2;}
	|STRING_LIT		{$<s_val>$ = $<s_val>1;}
;

ConversionExpr
	:Type '(' Expression ')' {printf("%c2%c\n",strcmp($<s_val>3,"ID") == 0? type[0] :$<s_val>3[0],$<s_val>1[0]);}
;



Statement
	:DeclarationStmt NEWLINE
	|FunctionCall NEWLINE
	|SimpleStmt NEWLINE
	|Block
	|IfStmt
	|ForStmt
	|SwitchStmt
	|CaseStmt
	|PrintStmt NEWLINE
	|ReturnStmt NEWLINE
	|NEWLINE
;

FunctionCall
	:ID '(' ')'	{lookup_symbol($<s_val>1); printf("123135555555555\n");}
	|ID '(' Parameters_call ')'	{printf("2232232323231231213213\n");}
;

Parameters_call
	:Operand
	|Parameters_call Operand
;


SimpleStmt
	:AssignmentStmt
	|ExpressionStmt
	|IncDecStmt
;

DeclarationStmt
	:VAR VarID VarType	{
						if(lookup_symbol($<id_name>2) != -1 && symbol_level == level-1)
							printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno, $<id_name>2 ,atlineno);
						insert_symbol($<id_name>2, addr++, level-1, $<s_val>3, "-", yylineno ); 
						//else
						}
	|VAR VarID VarType '=' Expression 	{
										if(lookup_symbol($<id_name>2) != -1 && symbol_level == level-1)
											printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno, $<id_name>2 ,atlineno);
										 insert_symbol($<id_name>2, addr++, level-1,$<s_val>3 , "-", yylineno);  
						//else
						}
;

VarID
	:ID {strcpy($<id_name>$, yytext);}
;

VarType
	:Type {$<s_val>$ = $<s_val>1;}
;

AssignmentStmt
	:Expression assign_op Expression
;

assign_op
	: '='
	|ADD_ASSIGN
	|SUB_ASSIGN
	|MUL_ASSIGN
	|DIV_ASSIGN
	|MOD_ASSIGN
;

ExpressionStmt
	:Expression
;

IncDecStmt
	:Expression INC	{printf("INC\n");}
	|Expression DEC {printf("DEC\n");}
;

Block
	:LParantheses Block2
;

Block2
	: StatementList RParantheses
	|RParantheses
;

StatementList
	:Statement
	|StatementList Statement
;

IfStmt
	:IF Condition Block ElseStmt
;

ElseStmt
	:
	| ELSE IfStmt
	| ELSE Block
;

Condition
	:Expression {if(strcmp($<s_val>1,"bool")!=0)	{
				if(sub_str = strstr($<s_val>1,"_id"))
					sub_str[0] = '\0';
				printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, $<s_val>1);}}
;

ForStmt
	:FOR Condition Block
	|FOR ForClause Block
;

ForClause
	:InitStmt ';' Condition ';' PostStmt
;

InitStmt
	:SimpleStmt
;

PostStmt
	:SimpleStmt
;

SwitchStmt
	:SWITCH Expression Block
;

CaseStmt
	:Case ':' Block 
	|DEFAULT ':' Block
;

Case
	:CASE INT_LIT	{printf("case %d\n",yylval.i_val);}
;

FunctionDeclStmt
	:FuncPrototype FuncBlock
;
/*	:FuncTitle FuncParameters ReturnType FuncBlock 
	|FuncTitle FuncParameters FuncBlock 
;*/

/*FuncProto
	:FuncPrototype LParantheses*/

FuncPrototype
	:FuncTitle FuncParameters ReturnType LParantheses {
											/*create_symbol(level);*/
//								printf("ssss = %s\n",parameters);
								int n = 0;
								for(int i =0;i<parameters_num;i++){
									char parameter_name[100], parameter_type[10];
									int name_len = 0, type_len = 0;
/*									parameter_name[0] = '\0';
									parameter_type[0] = '\0';*/
									memset(parameter_name,0,100);
									memset(parameter_type,0,10);
									while(parameters[n]!=' '){
//										strcat(parameter_name,parameters[n]);
										parameter_name[name_len++] = parameters[n];
										n++;
									}
									n++;
									while(parameters[n]!='/'){
//										strcat(parameter_type,parameters[n]);
										parameter_type[type_len++] = parameters[n];
										n++;
									}
									n++;
									printf("param %s, type: %c\n", parameter_name, parameter_type[0]-32);
									insert_symbol(&parameter_name[0], addr++, level-1, &parameter_type[0],"-", yylineno + 1);
								}
											printf("func_signature: %s\n", func_sig); 
											insert_symbol(&$<func_name>1[0], -1, level-2, "func", func_sig, yylineno+1);
											
											}
	|FuncTitle FuncParameters LParantheses	{
								/*create_symbol(level);*/
								int n = 0;
								for(int i =0;i<parameters_num;i++){
									char parameter_name[100], parameter_type[10];
									int name_len = 0, type_len = 0;
/*									parameter_name[0] = '\0';
									parameter_type[0] = '\0';*/
									memset(parameter_name,0,100);
									memset(parameter_type,0,10);
									while(parameters[n]!=' '){
//										strcat(parameter_name,parameters[n]);
										parameter_name[name_len++] = parameters[n];
										n++;
									}
									n++;
									while(parameters[n]!='/'){
//										strcat(parameter_type,parameters[n]);
										parameter_type[type_len++] = parameters[n];
										n++;
									}
									n++;
									printf("param %s, type: %c\n", parameter_name, parameter_type[0]-32);
									insert_symbol(&parameter_name[0], addr++, level-1, &parameter_type[0],"-", yylineno + 1);
								}
								strcat(func_sig,"V");
								printf("func_signature: %s\n", func_sig);
								insert_symbol(&$<func_name>1[0], -1, level-2, "func", func_sig, yylineno+1);
								}
;

FuncParameters
	:'(' ParameterList ')'	{ strcat(func_sig, ")");}
	|'(' ')'				{ strcat(func_sig, ")");}
;

ReturnType
	:Type 	/*	{
					if(strcmp(yytext, "int32") == 0) strcat(funcsig,"I");
					else if (strcmp(yytext, "float32") == 0) strcat(funcsig,"F");
				}*/
;

FuncTitle
	:FUNC ID 	{
					printf("func: %s\n",yytext); 
					func_sig[0] = '('; 
					func_sig[1] = '\0';
					parameters[0] = '\0';
					parameters_num = 0;
					strcpy($<func_name>$, id);
				}
;

ParameterList
	:ID Type	{strcat(parameters,id); strcat(parameters," "); strcat(parameters,$<s_val>2); strcat(parameters,"/"); parameters_num++;}
	|ParameterList ',' ID Type	{strcat(parameters,id); strcat(parameters," "); strcat(parameters,$<s_val>4); strcat(parameters,"/"); parameters_num++;}
;

FuncBlock
	:StatementList RParantheses 
;

ReturnStmt
	:RETURN 				{printf("return\n");}
	|RETURN Expression		{printf("%creturn\n",$<s_val>2[0]);}
;

PrintStmt
	:PRINT '(' Expression ')' 	
								{ sub_str = NULL;
								if(sub_str = strstr($<s_val>3, "_id")) {
									sub_str[0] = '\0';
									printf("PRINT %s\n",$<s_val>3);}
								else printf("PRINT %s\n",$<s_val>3);}
	|PRINTLN '(' Expression ')'	{ sub_str = NULL;
								if(sub_str = strstr($<s_val>3, "_id")) {
									sub_str[0] = '\0';
									printf("PRINTLN %s\n", $<s_val>3);}
								else printf("PRINTLN %s\n", $<s_val>3);}
;
	
LParantheses
	:'{' 	{ create_symbol(level++);}
;

RParantheses
	:'}'	{ dump_symbol(--level);}
;




%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(int level) {
    printf("> Create symbol table (scope level %d)\n", level);
	if(!head){
		head = (TABLE *)malloc(sizeof(TABLE));
		head->level = level;
		head->next = NULL;
		head->entry_first = NULL;
	//	printf("no head\n");
	}
	else{
		TABLE *temp = head;
		while(temp->next){
			temp = temp->next;
		}
		TABLE *new = (TABLE *)malloc(sizeof(TABLE));
		new->level = level;
		new->next = NULL;
		new->entry_first = NULL;
		temp->next = new;
	//	printf("head exist\n");
	}
	

}

static void insert_symbol(char* name, int addr, int level, char *type, char *func_sig, int lineno) {
	
    printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, level);
    //printf("> Insert `%s` (addr: %d) to scope level %d,type=%s,func_sig=%s,no=%d\n", name, addr, level,type,func_sig,lineno);
	ENTRY *newEntry = (ENTRY *)malloc(sizeof(ENTRY));
	newEntry->index = 0;
	strcpy(newEntry->name ,name);
	strcpy(newEntry->type, type); // same as above
	newEntry->addr = addr;
	newEntry->lineno = lineno;
	strcpy(newEntry->func_sig, func_sig);
	newEntry->next = NULL;
	
	TABLE *tabletmp = head;
	while(tabletmp->level != level){
//		printf("tabletmp->level = %d\n ",tabletmp->level);	
		tabletmp = tabletmp->next;
	}
	/*printf("tabeltmp11->level = %d,,, entrtfirst.name = %s\n",tabletmp->level,tabletmp->entry_first->name);
	if(!(tabletmp->entry_first)){
		printf("tmppp=%p,level = %d,entry_first=%p\n",tabletmp,tabletmp->level, tabletmp->entry_first);
	}*/
	if(tabletmp->entry_first == NULL){
//		printf("inin");
		tabletmp->entry_first = newEntry; ///problem line
		newEntry->index = 0;
	}
	else{
//		printf("222222");
		ENTRY *tmp;
		tmp = tabletmp->entry_first;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = newEntry;
		newEntry->index = tmp->index + 1;
	}
	
}

static int lookup_symbol(char *symbol) {
	//printf("s = %s\n",symbol);
	TABLE *look_table = head;
	int level_tmp = level-1;
	while(1){
		while(look_table->level != level_tmp){
			look_table = look_table->next;
			if(!look_table){
//				printf("error\n");
				return -1;
			}
		}
		ENTRY *look_entry = look_table->entry_first;
		while(look_entry){
/*			if(look_table->level == 0 && look_entry->index == 0){
//			printf("level = %d , index = %d , entry = %s\n",look_table->level,look_entry->index,look_entry->name);
//			printf("symbol = %s   \n", symbol);
//			printf("-----------------------------\n");
			}*/
			if(strcmp(look_entry->name,symbol) == 0){
				strcpy(type, look_entry->type);
				atlineno = look_entry->lineno;
				symbol_level = look_table->level;
				strcpy(func_sig, look_entry->func_sig);
				return look_entry->addr;
			}
			look_entry = look_entry->next;
		}
//		look_table = look_table->next;
		look_table = head;
		level_tmp --;
		if(level == -1)
			break;
	}
	return -1;
}



static void dump_symbol(int level) {
    printf("\n> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");

	TABLE *tabletmp = head;
	TABLE *null_next = tabletmp;
	while(tabletmp->level != level){
		null_next = tabletmp;
		tabletmp = tabletmp->next;	
	}
	ENTRY *entrytmp = tabletmp->entry_first;
	
	while(entrytmp){
   	 	printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",
            	entrytmp->index, entrytmp->name, entrytmp->type, entrytmp->addr, entrytmp->lineno, entrytmp->func_sig);
		entrytmp = entrytmp->next;
	}
	printf("\n");
	null_next->next = NULL;
	// may need to free
}

static void type_error(char *first, char *op, char *second){
	char *sub1 = NULL;
	char *sub2 = NULL;
	sub1 = strstr(first,"_id");
	sub2 = strstr(second,"_id");
	if(sub1) {
		sub1[0] = '\0';
	}
	if(sub2){
		sub2[0] = '\0';		
	}
	if(strcmp(op,"REM")==0 && (strcmp(first,"float32") == 0 || strcmp(second,"float32") == 0)){
		char error_txt[1000];
		memset(error_txt, 0, 1000);
		strcat(error_txt,"invalid operation: (operator ");
		strcat(error_txt,op);
		strcat(error_txt," not defined on ");
		strcat(error_txt,strcmp(first,"float32") ==0? first:second);
		strcat(error_txt,")");
//		yyerror(error_txt);
        printf("error:%d: %s\n", yylineno+1, error_txt);
		return;
	}
	if((strcmp(op,"LAND")==0||strcmp(op,"LOR")==0) && (strcmp(first,"int32") == 0 || strcmp(second,"int32") == 0)){
		char error_txt[1000];
		memset(error_txt, 0, 1000);
		strcat(error_txt,"invalid operation: (operator ");
		strcat(error_txt,op);
		strcat(error_txt," not defined on ");
		strcat(error_txt,strcmp(first,"int32") ==0? first:second);
		strcat(error_txt,")");
//		yyerror(error_txt);
        printf("error:%d: %s\n", yylineno, error_txt);
		return;
	}
	if((strcmp(op,"GTR")==0) && (strcmp(first,second) != 0 )){
		char error_txt[1000];
		memset(error_txt, 0, 1000);
		strcat(error_txt,"invalid operation: ");
		strcat(error_txt,op);
		strcat(error_txt," (mismatched types ERROR and ");
		strcat(error_txt,second);
		strcat(error_txt,")");
//		yyerror(error_txt);
        printf("error:%d: %s\n", yylineno, error_txt);
		return;
	}
	if(strcmp(first,second) != 0){
		char error_txt[1000] ;
		memset(error_txt, 0, 1000);
		strcat(error_txt,"invalid operation: ");
		strcat(error_txt,op);
		strcat(error_txt," (mismatched types ");
		strcat(error_txt,first);
		strcat(error_txt," and ");
		strcat(error_txt,second);
		strcat(error_txt,")");
		yyerror(error_txt);
	}

}
