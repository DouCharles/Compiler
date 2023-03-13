/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LOR = 267,
    LAND = 268,
    LEQ = 269,
    EQU = 270,
    NEQ = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    QUO_ASSIGN = 275,
    REM_ASSIGN = 276,
    IF = 277,
    ELSE = 278,
    FOR = 279,
    SWITCH = 280,
    CASE = 281,
    PRINT = 282,
    PRINTLN = 283,
    TRUE = 284,
    FALSE = 285,
    PACKAGE = 286,
    FUNC = 287,
    ID = 288,
    RETURN = 289,
    DEFAULT = 290,
    INT_LIT = 291,
    STRING_LIT = 292,
    FLOAT_LIT = 293
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LOR 267
#define LAND 268
#define LEQ 269
#define EQU 270
#define NEQ 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define QUO_ASSIGN 275
#define REM_ASSIGN 276
#define IF 277
#define ELSE 278
#define FOR 279
#define SWITCH 280
#define CASE 281
#define PRINT 282
#define PRINTLN 283
#define TRUE 284
#define FALSE 285
#define PACKAGE 286
#define FUNC 287
#define ID 288
#define RETURN 289
#define DEFAULT 290
#define INT_LIT 291
#define STRING_LIT 292
#define FLOAT_LIT 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 91 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
   	char *s_val;
    /* ... */

#line 137 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
