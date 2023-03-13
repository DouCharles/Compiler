/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */

    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
	int LabelNum = 0;
	int level = 0;
	int addr = 0;

    typedef struct entry{
		int level;
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
	static void create_symbol(/* ... */);
    static void insert_symbol(/* ... */);
    static ENTRY* lookup_symbol(/* ... */);
    static void dump_symbol(/* ... */);
    static void type_error();
	
	ENTRY *lookup = NULL;
	char *sub_str = NULL;
	char *instruction = NULL;
	char *str2 = NULL;
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
    /* ... */
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING 
%token INC DEC GEQ LOR LAND LEQ EQU NEQ
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token IF ELSE FOR SWITCH CASE
%token PRINT PRINTLN
%token TRUE FALSE
%token PACKAGE FUNC ID
%token RETURN DEFAULT


/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT
%token <f_val> FLOAT_LIT

/* Nonterminal with return, which need to sepcify type */
/*%type <s_val> Type*/

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : GlobalStatementList
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : PackageStmt NEWLINE
    | FunctionDeclStmt
    | NEWLINE
;


PackageStmt
    :PACKAGE ID {create_symbol(level++); }
;

Type
	:INT 		{$<s_val>$ = strdup("I"); }
	|FLOAT		{$<s_val>$ = strdup("F"); }
	|STRING		{$<s_val>$ = strdup("S"); }
	|BOOL		{$<s_val>$ = strdup("B"); }
/*	|*/
;
Expression
	:Assignment_expression	{$<s_val>$ = $<s_val>1;}
;

Assignment_expression
	:Lor_expression 								{$<s_val>$ = $<s_val>1;}
	|UnaryExpr assignment_op Assignment_expression	{$<s_val>$=$<s_val>3;	CODEGEN("istore %d\n",0);
													}
;

Lor_expression
	:Land_expression						{$<s_val>$ = $<s_val>1;}
	|Lor_expression LOR Land_expression		{CODEGEN("ior\n"); $<s_val>$ = "bool";}
;

Land_expression
	:Cmp_expression							{$<s_val>$ = $<s_val>1;}
	|Land_expression LAND Cmp_expression	{CODEGEN("iand\n"); $<s_val>$ = "bool";}
;

Cmp_expression
	:Add_expression							{$<s_val>$ = $<s_val>1;}
	|Cmp_expression cmp_op Add_expression	{	int numtemp = LabelNum;
												if(strcmp($<s_val>1,"I") == 0){
													CODEGEN("isub\n");
													CODEGEN("ifgt L_cmp_%d\n",LabelNum++);
												}
												else{
													CODEGEN("fcmpl\n");
													CODEGEN("iflt L_cmp%d\n",LabelNum++);
												}
												CODEGEN("iconst_0\n");
												CODEGEN("goto L_cmp_%d\n",LabelNum);
												CODEGEN("L_cmp_%d:\n",numtemp);
												CODEGEN("iconst_1\n");
												CODEGEN("L_cmp_%d:\n",LabelNum++);
												$<s_val>$ = "bool";
											}
;

Add_expression
	:Mul_expression							{$<s_val>$ = $<s_val>1;}
	|Add_expression add_op Mul_expression	{	printf("addddddd\n");
												printf("%s %s %s\n",$<s_val>1,$<s_val>2,$<s_val>3);
												if(sub_str = strstr($<s_val>1,"_id")){
													printf("testing");
													str2 = strdup($<s_val>1);
													sub_str = strstr(str2,"_id");
													sub_str[0] = '\0';
													lookup = lookup_symbol(str2);
													instruction = strdup(lookup->type);
													instruction[0] = instruction[0] + 32;
													strcat(instruction,$<s_val>2);
													CODEGEN("%s\n",instruction);
												}
												else{
													printf("else\n");
												}
											}
;

Mul_expression
	:Cast_expression						{$<s_val>$ = $<s_val>1;}
	|Mul_expression	mul_op Cast_expression	
;

Cast_expression
	:UnaryExpr		{$<s_val>$ = $<s_val>1;}
	|ConversionExpr					
;

UnaryExpr
	:PrimaryExpr					{$<s_val>$ = $<s_val>1;}
	|unary_op Cast_expression 		{$<s_val>$ = $<s_val>2;}
;

assignment_op
	:'='
	|ADD_ASSIGN
	|SUB_ASSIGN
	|MUL_ASSIGN
	|QUO_ASSIGN
	|REM_ASSIGN
;

cmp_op
	:EQU
	|NEQ
	|'<'
	|LEQ
	|'>'
	|GEQ
;

add_op
	:'+'	{$<s_val>$ = "add"; }
	|'-'	{$<s_val>$ = "sub"; }
;

mul_op
	:'*'	{$<s_val>$ = "mul"; }
	|'/'	{$<s_val>$ = "div"; }
	|'%'	{$<s_val>$ = "irem"; }
;

unary_op
	:'+'	{$<s_val>$ = "";}
	|'-'	{$<s_val>$ = "neg\n";}
	|'!'	{$<s_val>$ = "";}
;

PrimaryExpr
	:Operand {$<s_val>$ = $<s_val>1;}
;

Operand
	:Literal		{$<s_val>$ = $<s_val>1;}
	|ID				{
						lookup = lookup_symbol(yylval.s_val);
						if(!lookup){
							$<s_val>$ = strdup(yylval.s_val);
							strcat($<s_val>$,"_id");
						}
						else{
							$<s_val>$ = strdup(lookup->name);
							strcat($<s_val>$,"_id");
						}
						printf("IDID\n");
						if(strcmp(lookup->type,"I") == 0)
							CODEGEN("iload %d\n", lookup->addr);
						else if (strcmp(lookup->type, "F") == 0)
							CODEGEN("fload %d\n", lookup->addr);
					}
	|'(' Expression ')'
	|TRUE			{ $<s_val>$ = "bool"; CODEGEN("iconst_1\n"); }
	|FALSE 			{ $<s_val>$ = "bool"; CODEGEN("iconst_0\n"); }
;

Literal
	:INT_LIT 		{ $<s_val>$ = "I"; CODEGEN("ldc %d\n",yylval.i_val); }
	|FLOAT_LIT		{ $<s_val>$ = "F"; CODEGEN("ldc %f\n",yylval.f_val); }
	|'"' Str '"'	{ $<s_val>$ = "S"; CODEGEN("ldc \"%s\"", yylval.s_val); }
;

Str
	:Str STRING_LIT
	|STRING_LIT
;

ConversionExpr
	:Type '(' Expression ')'
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
	:ID '(' ')'
	|ID '(' Parameters_call ')'
;

Parameters_call
	:Operand
	|Parameters_call ',' Operand
;

SimpleStmt
	/*:AssignmentStmt
	|ExpressionStmt*/
	:Expression
	|IncDecStmt
;

DeclarationStmt
	:VAR VarID VarType					{
										lookup = lookup_symbol($<s_val>2);
										if(lookup && lookup->level == level-1){
											printf("error:%d: %s redeclared in this bloc    k. previous declaration at line %d\n",yylineno, $<s_val>2 ,123);
											g_has_error = true;
										}
										insert_symbol($<s_val>2,addr++,level-1,$<s_val>3,"-",yylineno);
										
										}
	|VAR VarID VarType '=' Expression	{
                                        ENTRY *lookup = lookup_symbol($<s_val>2);
                                        if(lookup && lookup->level == level-1){
                                          printf("error:%d: %s redeclared in this bloc    k. previous de    claration at line %d\n",yylineno, $<s_val>2 ,123);
                                            g_has_error = true;
                                        }
                                        insert_symbol($<s_val>2,addr++,level-1,$<s_val>3,"-",yylineno);
                                        instruction = strdup($<s_val>3);
										instruction[0] = instruction[0] + 32;
										CODEGEN("%sstore %d\n",instruction, addr-1 );
                                        }

	|VAR VarID VarType '=' FunctionCall	{
                                        ENTRY *lookup = lookup_symbol($<s_val>2);
                                        if(lookup && lookup->level == level-1){
                                          printf("error:%d: %s redeclared in this bloc    k. previous de    claration at line %d\n",yylineno, $<s_val>2 ,123);
                                            g_has_error = true;
                                        }
                                        insert_symbol($<s_val>2,addr++,level-1,$<s_val>3,"-",yylineno);
                                        instruction = strdup($<s_val>3);
										instruction[0] = instruction[0] + 32;
										CODEGEN("%sstore %d\n",instruction, addr-1);
                                        
                                        }

;

VarID
	:ID 	{$<s_val>$=strdup(yylval.s_val);}
;

VarType
	:Type	{ $<s_val>$ = $<s_val>1; }
;

IncDecStmt
	:Expression INC {
						if(sub_str = strstr($<s_val>1,"_id")){
							str2 = strdup($<s_val>1);
							sub_str = strstr(str2,"_id");
							sub_str[0] = '\0';
							lookup = lookup_symbol(str2);
							CODEGEN("ldc 1\n");
							CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
							CODEGEN("%cadd\n",lookup->type[0]+32);
							CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
						}
					}
	|Expression DEC	{
                        if(sub_str = strstr($<s_val>1,"_id")){
                            str2 = strdup($<s_val>1);
                            sub_str = strstr(str2,"_id");
                            sub_str[0] = '\0';
                            lookup = lookup_symbol(str2);
                            CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
                            CODEGEN("ldc 1\n");
							CODEGEN("%csub\n",lookup->type[0]+32);
                            CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
                        }
                    }

;

Block
	:LParantheses StatementList RParantheses
;

LParantheses
	:'{'  {  create_symbol(level++);}
;

RParantheses
	:'}'
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
	|ELSE IfStmt
	|ELSE Block
;

Condition
	:Expression
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
	:CASE INT_LIT ':' Block
	|DEFAULT ':' Block
;

FunctionDeclStmt
    :FuncPrototype FuncBlock
;

FuncPrototype 
	:FuncTitle FuncParameters Type LParantheses 	{	CODEGEN(".method public static %s(%s)%s\n",$<s_val>1, strcmp($<s_val>1,"main") == 0?"[Ljava/lang/String;":$<s_val>2, $<s_val>3);
													CODEGEN(".limit stack 100\n");
													CODEGEN(".limit locals 100\n");
												}
	|FuncTitle FuncParameters LParantheses		{	CODEGEN(".method public static %s(%s)V\n",$<s_val>1, strcmp($<s_val>1,"main") == 0?"[Ljava/lang/String;":$<s_val>2);
                                    			CODEGEN(".limit stack 100\n");
	                                            CODEGEN(".limit locals 100\n");
												}
;

FuncParameters
	:'(' ParameterList ')' 	{$<s_val>$ = $<s_val>2;}
	|'(' ')'				{$<s_val>$ = malloc(sizeof(char)); $<s_val>$[0] = '\0';}
;

FuncTitle
	:FUNC ID {$<s_val>$ = yylval.s_val;}
;

ParameterList
	:ID Type	{$<s_val>$ = $<s_val>2;}
	|ParameterList ',' ID Type	{strcat($<s_val>$,$<s_val>4);}
;

FuncBlock
	:StatementList	'}'		{CODEGEN(".end method\n");}
;

ReturnStmt
	:RETURN		{CODEGEN("return\n");}
	|RETURN Expression
;

PrintStmt			/*not setting print(bool) yet*/
	:PRINT '(' Expression ')'	{	if(strcmp($<s_val>3,"S") != 0) {
										if (sub_str = strstr($<s_val>3,"_id")){
											printf("innnnnnn\n");
											str2 = strdup($<s_val>3);
											sub_str = strstr(str2,"_id");
											sub_str[0] = '\0';
											lookup = lookup_symbol(str2);
											instruction = lookup->type;
										}
										else{
											printf("innnnnnn2\n");
											instruction = $<s_val>3;
										}
										CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(%s)V\n",instruction);
									}
									else CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
								}
	|PRINTLN '(' Expression ')'		{	if(strcmp($<s_val>3, "S") != 0) {
											if (sub_str = strstr($<s_val>3,"_id")){
                                        	//    printf("innnnnnn\n");
                                    	        str2 = strdup($<s_val>3);
                                	            sub_str = strstr(str2,"_id");
                            	                sub_str[0] = '\0';
                        	                    lookup = lookup_symbol(str2);
                    	                        instruction = lookup->type;
                	                        }
            	                            else{
        	                                  //  printf("innnnnnn2\n");
    	                                         instruction = $<s_val>3;
	                                        }
											CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(%s)V\n",instruction);
										}
										else CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
									}

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
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
        remove(bytecode_filename);
    }
    yylex_destroy();
    return 0;
}

static void create_symbol(int level) {
    printf("> Create symbol table (scope level %d)\n", level);

    if(!head){
        head = (TABLE *)malloc(sizeof(TABLE));
        head->level = level;
        head->next = NULL;
        head->entry_first = NULL;
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
    }

}

static void insert_symbol(char *name, int addr, int level, char *type, char *func_sig, int lineno) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, level);
	ENTRY *newEntry = (ENTRY *)malloc(sizeof(ENTRY));
    newEntry->index = 0;
    strcpy(newEntry->name ,name);
    strcpy(newEntry->type, type); 
    newEntry->addr = addr;
	newEntry->level = level;
    newEntry->lineno = lineno;
    strcpy(newEntry->func_sig, func_sig);
    newEntry->next = NULL;

    TABLE *tabletmp = head;
    while(tabletmp->level != level){
        tabletmp = tabletmp->next;
    }
    if(!tabletmp->entry_first){
        tabletmp->entry_first = newEntry; 
        newEntry->index = 0;
    }
	else{
        ENTRY *tmp;
        tmp = tabletmp->entry_first;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = newEntry;
        newEntry->index = tmp->index + 1;
    }

}

static ENTRY*  lookup_symbol(char *symbol) {
	printf("lookup = %s\n",symbol);
    TABLE *look_table = head;
    int level_tmp = level-1;
    while(1){
        while(look_table->level != level_tmp){
            look_table = look_table->next;
            if(!look_table){
//                return -1;
				return NULL;
            }
        }
        ENTRY *look_entry = look_table->entry_first;
        while(look_entry){
            if(strcmp(look_entry->name,symbol) == 0){
/*                strcpy(type, look_entry->type);
                atlineno = look_entry->lineno;
                symbol_level = look_table->level;
                strcpy(func_sig, look_entry->func_sig);
                return look_entry->addr;*/
				return look_entry;
            }
            look_entry = look_entry->next;
        }
        look_table = head;
        level_tmp --;
        if(level == -1)
            break;
    }
//    return -1;
	return NULL;

}

static void dump_symbol(int level) {

    TABLE *tabletmp = head;
    TABLE *null_next = tabletmp;
    while(tabletmp->level != level){
        null_next = tabletmp;
        tabletmp = tabletmp->next;
    }
    ENTRY *entrytmp = tabletmp->entry_first;

    null_next->next = NULL;

}



