/*
    filename: compiler_hw1.l
*/

/* Definition section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #define print_token(token) \
        printf("%-8s \t %s\n", strcmp(token, "NEWLINE")? yytext: "", token)

    int line_num = 0;
    int comment_num = 0;
    int last_comment_line = -1;
	int is_str;
%}


/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
add [+]
inc {add}{add}
sub [-]
mul [*]
quo [/]
rem [%]
dec {sub}{sub}
gtr [>]
lss [<]
assign [=]
excl [!]
geq {gtr}{assign}
leq {lss}{assign}
eql {assign}{assign}
neq {excl}{assign}
add_assign {add}{assign}
sub_assign {sub}{assign}
mul_assign {mul}{assign}
quo_assign {quo}{assign}
rem_assign {rem}{assign}
and [&]
or [|]
land {and}{and}
lor {or}{or}

id {letter}+({letter}|{digit})*
inumber {digit}+
fnumber ({digit}*\.{digit}+)


/* Rules section */
%x COMMENT COMMENT2 str
%%

"+"         { print_token("ADD"); }
"-"         { print_token("SUB"); }
"*"         { print_token("MUL"); }
"/"         { print_token("QUO"); }
"%"         { print_token("REM"); }
">"         { print_token("GTR"); }		
"<"         { print_token("LSS"); }
"!"			{ print_token("NOT"); }
"("			{ print_token("LPAREN"); }
")"			{ print_token("RPAREN"); }
"["			{ print_token("LBRACK"); }
"]"			{ print_token("RBRACK"); }
"{"			{ print_token("LBRACE"); }
"}"			{ print_token("RBRACE"); }
";"			{ print_token("SEMICOLON"); }
","			{ print_token("COMMA"); }
"\""		{ print_token("QUOTA"); 
			  BEGIN str;}
<str>[^\"]*		{print_token("STRING_LIT");}
<str>"\""	{BEGIN 0;print_token("QUOTA");}
"\n"		{ print_token("NEWLINE");line_num++; }
":"			{ print_token("COLON"); }

"print"	{ print_token("PRINT"); }
"println"	{ print_token("PRINTLN"); }
"if"	{ print_token("IF"); }
"else"	{ print_token("ELSE"); }
"for"	{ print_token("FOR"); }
"int32"	{ print_token("INT"); }
"float32"	{ print_token("FLOAT"); }
"string"	{ print_token("STRING"); }
"bool"	{ print_token("BOOL"); }
"true"	{ print_token("TRUE"); }
"false"	{ print_token("FALSE"); }
"var"	{ print_token("VAR"); }
"func"	{ print_token("FUNC"); }
"package"	{ print_token("PACKAGE"); }
"return"	{ print_token("RETURN"); }
"switch"	{ print_token("SWITCH"); }
"case"	{ print_token("CASE"); }
"default"	{ print_token("DEFAULT"); }

{assign}	{ print_token("ASSIGN"); }
{inc}		{ print_token("INC"); }
{dec}		{ print_token("DEC"); }
{geq}		{ print_token("GEQ"); }
{leq}		{ print_token("LEQ"); }
{eql}		{ print_token("EQL"); }
{neq}		{ print_token("NEQ"); }
{land}		{ print_token("LAND"); }
{lor}		{ print_token("LOR"); }

{add_assign}		{ print_token("ADD_ASSIGN"); }
{sub_assign}		{ print_token("SUB_ASSIGN"); }
{mul_assign}		{ print_token("MUL_ASSIGN"); }
{quo_assign}		{ print_token("QUO_ASSIGN"); }
{rem_assign}		{ print_token("REM_ASSIGN"); }

"//" { ECHO; BEGIN COMMENT;}

<COMMENT>[^\n]*	{BEGIN 0; print_token("C++ Comment"); comment_num++;}

"/*" {ECHO; BEGIN COMMENT2;}
<COMMENT2>. {ECHO;}
<COMMENT2>"\n" {print_token("C Comment");line_num++;comment_num++;}
<COMMENT2>"*/" {BEGIN 0; print_token("C Comment");comment_num++;}
{inumber}	{ print_token("INT_LIT");}
{fnumber}	{ print_token("FLOAT_LIT");}
{id}        { print_token("IDENT");}



<<EOF>>     { line_num++; yyterminate(); }
[ \t]+      {;}
.           {;}
%%

/*  C Code section */
int yywrap(void)
{
    return 1;
}


int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}
