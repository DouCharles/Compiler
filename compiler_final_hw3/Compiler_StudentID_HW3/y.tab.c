/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "compiler_hw3.y" /* yacc.c:339  */

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

#line 137 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 81 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
   	char *s_val;
    /* ... */

#line 260 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 277 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    50,     2,     2,    46,     2,     2,
      48,    49,    44,    42,    51,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    54,
      40,    39,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   119,   120,   124,   125,   126,   131,   135,
     136,   137,   138,   142,   146,   147,   152,   153,   157,   158,
     162,   163,   182,   183,   203,   204,   208,   209,   213,   214,
     218,   219,   220,   221,   222,   223,   227,   228,   229,   230,
     231,   232,   236,   237,   241,   242,   243,   247,   248,   249,
     253,   257,   258,   274,   275,   276,   280,   281,   282,   286,
     287,   291,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   309,   310,   314,   315,   321,   322,   326,
     335,   347,   363,   367,   371,   383,   399,   403,   407,   411,
     412,   416,   419,   421,   422,   426,   431,   432,   436,   440,
     444,   448,   452,   453,   457,   461,   465,   472,   473,   477,
     481,   482,   486,   490,   491,   495,   512
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NEWLINE", "INT", "FLOAT", "BOOL",
  "STRING", "INC", "DEC", "GEQ", "LOR", "LAND", "LEQ", "EQU", "NEQ",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN",
  "IF", "ELSE", "FOR", "SWITCH", "CASE", "PRINT", "PRINTLN", "TRUE",
  "FALSE", "PACKAGE", "FUNC", "ID", "RETURN", "DEFAULT", "INT_LIT",
  "STRING_LIT", "FLOAT_LIT", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'('", "')'", "'\"'", "','", "'{'", "'}'", "';'",
  "':'", "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "PackageStmt", "Type", "Expression", "Assignment_expression",
  "Lor_expression", "Land_expression", "Cmp_expression", "Add_expression",
  "Mul_expression", "Cast_expression", "UnaryExpr", "assignment_op",
  "cmp_op", "add_op", "mul_op", "unary_op", "PrimaryExpr", "Operand",
  "Literal", "Str", "ConversionExpr", "Statement", "FunctionCall",
  "Parameters_call", "SimpleStmt", "DeclarationStmt", "VarID", "VarType",
  "IncDecStmt", "Block", "LParantheses", "RParantheses", "StatementList",
  "IfStmt", "ElseStmt", "Condition", "ForStmt", "ForClause", "InitStmt",
  "PostStmt", "SwitchStmt", "CaseStmt", "FunctionDeclStmt",
  "FuncPrototype", "FuncParameters", "FuncTitle", "ParameterList",
  "FuncBlock", "ReturnStmt", "PrintStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
      60,    62,    43,    45,    42,    47,    37,    33,    40,    41,
      34,    44,   123,   125,    59,    58
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -96

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,   -82,    -9,     7,    63,    49,   -82,    75,   -82,   205,
      40,   -82,   -82,   -82,   -82,   -82,    59,   -82,   -82,   -82,
     -82,   -82,   253,   253,   253,    58,    47,    51,   -82,   -82,
      61,   253,    56,   -82,   -82,   -82,   -82,   -82,   253,    69,
     -82,    64,    68,   -82,   101,   102,    11,    44,     3,   -82,
      15,   253,   -82,   -82,   -82,   -82,   -82,   110,   112,   113,
     -82,   -82,   205,    97,   -82,   -82,   -82,   -82,   -82,   124,
     125,   -10,    23,   -82,    77,   -82,   -82,    82,     9,   -82,
      82,    82,    83,    82,    81,   253,   253,     8,   -82,    82,
      89,   -82,     5,   253,   -82,   -82,   253,   253,   -82,   -82,
     -82,   -82,   -82,   -82,   253,   -82,   -82,   253,   -82,   -82,
     -82,   253,   -82,   -82,   -82,   -82,   -82,   -82,   253,   -82,
     -82,   -82,   -82,   -82,   154,   -82,   -82,   -82,   -82,    77,
     -82,    -6,    82,   -82,   -82,   103,   118,   -82,   -82,   253,
     -82,    82,    99,   104,   -82,   -82,    17,   -82,   -82,   -82,
     -82,   105,   102,    11,    44,     3,   -82,   -82,   -82,   -82,
     -82,   -82,   119,   -82,   269,    -2,   -82,    92,   -82,   -82,
     -82,   -82,    60,   -82,    77,   -82,   -82,   -82,   -82,   253,
     -82,   -82,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     2,     4,     0,     6,     0,
       0,     8,   109,     1,     3,     5,     0,    72,     9,    10,
      12,    11,     0,     0,     0,     0,     0,     0,    54,    55,
      52,   113,     0,    56,    57,    47,    48,    49,     0,     0,
      87,     0,    77,    13,    14,    16,    18,    20,    22,    24,
      26,     0,    28,    50,    51,    27,    89,     0,     0,     0,
      78,    65,     0,     0,    66,    67,    68,    69,   104,     0,
       0,     0,     0,    82,     0,    52,    95,     0,    77,    99,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,    60,     0,     0,    84,    85,     0,     0,    41,    39,
      36,    37,    38,    40,     0,    42,    43,     0,    44,    45,
      46,     0,    31,    32,    33,    34,    35,    30,     0,    29,
      26,    63,    64,    62,     0,   112,    90,    71,    70,     0,
     108,     0,     0,   106,    83,    79,    92,    96,    97,     0,
     101,     0,     0,     0,    73,    75,     0,   103,    53,    59,
      58,     0,    17,    19,    21,    23,    25,    15,    88,    86,
     110,   107,     0,   105,     0,     0,    91,     0,   102,   115,
     116,    74,     0,    61,     0,    80,    81,    94,    93,     0,
      76,   111,   100,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   146,   -82,   -67,   -21,    37,   -82,    67,
      70,    62,    57,   -40,   -37,   -82,   -82,   -82,   -82,   -82,
     -82,   -81,   -82,   -82,   -82,   -55,     1,   -82,   -23,   -82,
     -82,   -82,   -82,   -68,   -56,   -82,   106,     4,   -82,   -19,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   118,   104,   107,   111,    51,
      52,    53,    54,    92,    55,    56,    57,   146,    58,    59,
      74,   135,    60,    61,    62,   159,    63,    64,   166,    77,
      65,    81,    82,   183,    66,    67,     8,     9,    72,    10,
     131,    68,    69,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    76,    78,    83,    80,   132,   145,   134,   126,   136,
      88,   119,   137,   138,   120,   140,   133,    90,    94,    95,
      22,   147,    98,   129,    11,    99,   100,   101,    18,    19,
      20,    21,   112,   113,   114,   115,   116,    28,    29,   130,
      12,    75,   149,   161,    33,   162,    34,   108,   109,   110,
      40,   102,   103,     1,   117,   150,    38,   144,    39,   120,
     120,   -95,   160,    13,   142,   143,   171,   120,   172,   126,
     120,   156,   151,   168,   120,    40,   163,    94,    95,    15,
       2,     3,    18,    19,    20,    21,   105,   106,    71,    28,
      29,   180,    73,    75,    84,    85,    33,   177,    34,    86,
      16,    17,    18,    19,    20,    21,    91,   181,    38,    87,
      39,    89,    93,    96,   121,    97,   122,   123,    76,    22,
     167,    23,    24,    25,    26,    27,    28,    29,   127,   128,
      30,    31,    32,    33,    40,    34,   141,   139,   148,    35,
      36,   165,   164,   175,    37,    38,   179,    39,   169,    40,
     125,    14,   174,   170,   173,   157,   182,    16,    17,    18,
      19,    20,    21,   152,   155,   176,   154,   153,   124,   178,
       0,     0,     0,     0,     0,     0,    22,     0,    23,    24,
      25,    26,    27,    28,    29,     0,     0,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,     0,     0,
       0,    37,    38,     0,    39,     0,    40,   158,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,    23,
      24,    25,    26,    27,    28,    29,     0,     0,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,     0,
       0,     0,    37,    38,     0,    39,     0,    40,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,     0,     0,
       0,     0,    28,    29,     0,     0,    75,     0,     0,    33,
       0,    34,     0,     0,     0,    35,    36,     0,    28,    29,
      37,    38,    30,    39,     0,    33,     0,    34,     0,     0,
       0,    35,    36,     0,     0,     0,    37,    38,     0,    39
};

static const yytype_int16 yycheck[] =
{
      23,    22,    23,    24,    23,    72,    87,    74,    63,    77,
      31,    51,    80,    81,    51,    83,    72,    38,     9,    10,
      22,    89,    11,    33,    33,    14,    15,    16,     5,     6,
       7,     8,    17,    18,    19,    20,    21,    29,    30,    49,
      33,    33,    37,    49,    36,    51,    38,    44,    45,    46,
      52,    40,    41,     4,    39,    50,    48,    49,    50,    96,
      97,    52,   129,     0,    85,    86,    49,   104,    51,   124,
     107,   111,    93,   141,   111,    52,   132,     9,    10,     4,
      31,    32,     5,     6,     7,     8,    42,    43,    48,    29,
      30,   172,    33,    33,    36,    48,    36,   165,    38,    48,
       3,     4,     5,     6,     7,     8,    37,   174,    48,    48,
      50,    55,    48,    12,     4,    13,     4,     4,   139,    22,
     139,    24,    25,    26,    27,    28,    29,    30,     4,     4,
      33,    34,    35,    36,    52,    38,    55,    54,    49,    42,
      43,    23,    39,   164,    47,    48,    54,    50,    49,    52,
      53,     5,    33,    49,    49,   118,   179,     3,     4,     5,
       6,     7,     8,    96,   107,   164,   104,    97,    62,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    53,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    33,    -1,    -1,    36,
      -1,    38,    -1,    -1,    -1,    42,    43,    -1,    29,    30,
      47,    48,    33,    50,    -1,    36,    -1,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    31,    32,    57,    58,    59,    60,   102,   103,
     105,    33,    33,     0,    59,     4,     3,     4,     5,     6,
       7,     8,    22,    24,    25,    26,    27,    28,    29,    30,
      33,    34,    35,    36,    38,    42,    43,    47,    48,    50,
      52,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    75,    76,    77,    78,    80,    81,    82,    84,    85,
      88,    89,    90,    92,    93,    96,   100,   101,   107,   108,
     109,    48,   104,    33,    86,    33,    62,    95,    62,    84,
      95,    97,    98,    62,    36,    48,    48,    48,    62,    55,
      62,    37,    79,    48,     9,    10,    12,    13,    11,    14,
      15,    16,    40,    41,    72,    42,    43,    73,    44,    45,
      46,    74,    17,    18,    19,    20,    21,    39,    71,    69,
      70,     4,     4,     4,    92,    53,    81,     4,     4,    33,
      49,   106,    61,    90,    61,    87,    89,    89,    89,    54,
      89,    55,    62,    62,    49,    77,    83,    89,    49,    37,
      50,    62,    65,    66,    67,    68,    69,    63,    53,    91,
      61,    49,    51,    90,    39,    23,    94,    95,    89,    49,
      49,    49,    51,    49,    33,    62,    82,    89,    93,    54,
      77,    61,    84,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    61,
      61,    61,    61,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      76,    77,    77,    77,    77,    77,    78,    78,    78,    79,
      79,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    87,    88,    88,    89,    90,    91,    92,
      92,    93,    94,    94,    94,    95,    96,    96,    97,    98,
      99,   100,   101,   101,   102,   103,   103,   104,   104,   105,
     106,   106,   107,   108,   108,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     2,
       1,     4,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     3,     4,     1,     3,     1,     1,     3,
       5,     5,     1,     1,     2,     2,     3,     1,     1,     1,
       2,     4,     0,     2,     2,     1,     3,     3,     5,     1,
       1,     3,     4,     3,     2,     4,     3,     3,     2,     2,
       2,     4,     2,     1,     2,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    {create_symbol(level++); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("I"); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("F"); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("S"); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 138 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("B"); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 146 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=(yyvsp[0].s_val);	CODEGEN("istore %d\n",0);
													}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("ior\n"); (yyval.s_val) = "bool";}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("iand\n"); (yyval.s_val) = "bool";}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 162 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 163 "compiler_hw3.y" /* yacc.c:1646  */
    {	int numtemp = LabelNum;
												if(strcmp((yyvsp[-2].s_val),"I") == 0){
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
												(yyval.s_val) = "bool";
											}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 182 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "compiler_hw3.y" /* yacc.c:1646  */
    {	printf("addddddd\n");
												printf("%s %s %s\n",(yyvsp[-2].s_val),(yyvsp[-1].s_val),(yyvsp[0].s_val));
												if(sub_str = strstr((yyvsp[-2].s_val),"_id")){
													printf("testing");
													str2 = strdup((yyvsp[-2].s_val));
													sub_str = strstr(str2,"_id");
													sub_str[0] = '\0';
													lookup = lookup_symbol(str2);
													instruction = strdup(lookup->type);
													instruction[0] = instruction[0] + 32;
													strcat(instruction,(yyvsp[-1].s_val));
													CODEGEN("%s\n",instruction);
												}
												else{
													printf("else\n");
												}
											}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 203 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 213 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "add"; }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 237 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "sub"; }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 241 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "mul"; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 242 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "div"; }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 243 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "irem"; }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 247 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "";}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "neg\n";}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 249 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "";}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 253 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 257 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 258 "compiler_hw3.y" /* yacc.c:1646  */
    {
						lookup = lookup_symbol(yylval.s_val);
						if(!lookup){
							(yyval.s_val) = strdup(yylval.s_val);
							strcat((yyval.s_val),"_id");
						}
						else{
							(yyval.s_val) = strdup(lookup->name);
							strcat((yyval.s_val),"_id");
						}
						printf("IDID\n");
						if(strcmp(lookup->type,"I") == 0)
							CODEGEN("iload %d\n", lookup->addr);
						else if (strcmp(lookup->type, "F") == 0)
							CODEGEN("fload %d\n", lookup->addr);
					}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; CODEGEN("iconst_1\n"); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; CODEGEN("iconst_0\n"); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "I"; CODEGEN("ldc %d\n",yylval.i_val); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 281 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "F"; CODEGEN("ldc %f\n",yylval.f_val); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 282 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "S"; CODEGEN("ldc \"%s\"", yylval.s_val); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 326 "compiler_hw3.y" /* yacc.c:1646  */
    {
										lookup = lookup_symbol((yyvsp[-1].s_val));
										if(lookup && lookup->level == level-1){
											printf("error:%d: %s redeclared in this bloc    k. previous declaration at line %d\n",yylineno, (yyvsp[-1].s_val) ,123);
											g_has_error = true;
										}
										insert_symbol((yyvsp[-1].s_val),addr++,level-1,(yyvsp[0].s_val),"-",yylineno);
										
										}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 335 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        ENTRY *lookup = lookup_symbol((yyvsp[-3].s_val));
                                        if(lookup && lookup->level == level-1){
                                          printf("error:%d: %s redeclared in this bloc    k. previous de    claration at line %d\n",yylineno, (yyvsp[-3].s_val) ,123);
                                            g_has_error = true;
                                        }
                                        insert_symbol((yyvsp[-3].s_val),addr++,level-1,(yyvsp[-2].s_val),"-",yylineno);
                                        instruction = strdup((yyvsp[-2].s_val));
										instruction[0] = instruction[0] + 32;
										CODEGEN("%sstore %d\n",instruction, addr-1 );
                                        }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        ENTRY *lookup = lookup_symbol((yyvsp[-3].s_val));
                                        if(lookup && lookup->level == level-1){
                                          printf("error:%d: %s redeclared in this bloc    k. previous de    claration at line %d\n",yylineno, (yyvsp[-3].s_val) ,123);
                                            g_has_error = true;
                                        }
                                        insert_symbol((yyvsp[-3].s_val),addr++,level-1,(yyvsp[-2].s_val),"-",yylineno);
                                        instruction = strdup((yyvsp[-2].s_val));
										instruction[0] = instruction[0] + 32;
										CODEGEN("%sstore %d\n",instruction, addr-1);
                                        
                                        }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 363 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=strdup(yylval.s_val);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 367 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 371 "compiler_hw3.y" /* yacc.c:1646  */
    {
						if(sub_str = strstr((yyvsp[-1].s_val),"_id")){
							str2 = strdup((yyvsp[-1].s_val));
							sub_str = strstr(str2,"_id");
							sub_str[0] = '\0';
							lookup = lookup_symbol(str2);
							CODEGEN("ldc 1\n");
							CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
							CODEGEN("%cadd\n",lookup->type[0]+32);
							CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
						}
					}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 383 "compiler_hw3.y" /* yacc.c:1646  */
    {
                        if(sub_str = strstr((yyvsp[-1].s_val),"_id")){
                            str2 = strdup((yyvsp[-1].s_val));
                            sub_str = strstr(str2,"_id");
                            sub_str[0] = '\0';
                            lookup = lookup_symbol(str2);
                            CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
                            CODEGEN("ldc 1\n");
							CODEGEN("%csub\n",lookup->type[0]+32);
                            CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
                        }
                    }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 403 "compiler_hw3.y" /* yacc.c:1646  */
    {  create_symbol(level++);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 461 "compiler_hw3.y" /* yacc.c:1646  */
    {	CODEGEN(".method public static %s(%s)%s\n",(yyvsp[-3].s_val), strcmp((yyvsp[-3].s_val),"main") == 0?"[Ljava/lang/String;":(yyvsp[-2].s_val), (yyvsp[-1].s_val));
													CODEGEN(".limit stack 100\n");
													CODEGEN(".limit locals 100\n");
												}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 465 "compiler_hw3.y" /* yacc.c:1646  */
    {	CODEGEN(".method public static %s(%s)V\n",(yyvsp[-2].s_val), strcmp((yyvsp[-2].s_val),"main") == 0?"[Ljava/lang/String;":(yyvsp[-1].s_val));
                                    			CODEGEN(".limit stack 100\n");
	                                            CODEGEN(".limit locals 100\n");
												}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 472 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[-1].s_val);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 473 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = malloc(sizeof(char)); (yyval.s_val)[0] = '\0';}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 477 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = yylval.s_val;}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 481 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 482 "compiler_hw3.y" /* yacc.c:1646  */
    {strcat((yyval.s_val),(yyvsp[0].s_val));}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 486 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN(".end method\n");}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 490 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("return\n");}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 495 "compiler_hw3.y" /* yacc.c:1646  */
    {	if(strcmp((yyvsp[-1].s_val),"S") != 0) {
										if (sub_str = strstr((yyvsp[-1].s_val),"_id")){
											printf("innnnnnn\n");
											str2 = strdup((yyvsp[-1].s_val));
											sub_str = strstr(str2,"_id");
											sub_str[0] = '\0';
											lookup = lookup_symbol(str2);
											instruction = lookup->type;
										}
										else{
											printf("innnnnnn2\n");
											instruction = (yyvsp[-1].s_val);
										}
										CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(%s)V\n",instruction);
									}
									else CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
								}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 512 "compiler_hw3.y" /* yacc.c:1646  */
    {	if(strcmp((yyvsp[-1].s_val), "S") != 0) {
											if (sub_str = strstr((yyvsp[-1].s_val),"_id")){
                                        	//    printf("innnnnnn\n");
                                    	        str2 = strdup((yyvsp[-1].s_val));
                                	            sub_str = strstr(str2,"_id");
                            	                sub_str[0] = '\0';
                        	                    lookup = lookup_symbol(str2);
                    	                        instruction = lookup->type;
                	                        }
            	                            else{
        	                                  //  printf("innnnnnn2\n");
    	                                         instruction = (yyvsp[-1].s_val);
	                                        }
											CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(%s)V\n",instruction);
										}
										else CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
									}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1991 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 535 "compiler_hw3.y" /* yacc.c:1906  */


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



