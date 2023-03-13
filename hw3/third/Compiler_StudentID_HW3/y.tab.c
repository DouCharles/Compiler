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
//     #define YYDEBUG 1
//     int yydebug = 1;

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
	static void CODEBOOL();
	static void FUNCPARAMETERS();
	
	ENTRY *lookup = NULL;
	char *sub_str = NULL;
	char *instruction = NULL;
	char *str2 = NULL;
	char *parameters = NULL;
	int parameters_num = 0;
	char *func_sig = NULL;
	char func_return[1];
	int *cases = NULL;
	int case_num = 0;

#line 145 "y.tab.c" /* yacc.c:339  */

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
#line 89 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
   	char *s_val;
    /* ... */

#line 268 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 285 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,   123,   123,   127,   128,   132,   133,   134,   139,   143,
     144,   145,   146,   150,   154,   155,   179,   180,   184,   185,
     189,   190,   223,   224,   245,   246,   268,   269,   273,   274,
     294,   295,   296,   297,   298,   299,   303,   304,   305,   306,
     307,   308,   312,   313,   317,   318,   319,   323,   324,   325,
     329,   333,   334,   353,   354,   355,   359,   360,   361,   365,
     366,   370,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   400,   406,   414,   418,   419,   425,   426,
     430,   453,   477,   505,   509,   513,   528,   548,   552,   556,
     560,   561,   565,   568,   570,   571,   575,   580,   581,   585,
     589,   593,   597,   612,   626,   629,   633,   640,   644,   648,
     657,   668,   669,   673,   685,   694,   706,   710,   714,   715,
     719,   754
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
  "CallID", "Parameters_call", "SimpleStmt", "DeclarationStmt", "VarID",
  "VarType", "IncDecStmt", "Block", "LParantheses", "RParantheses",
  "StatementList", "IfStmt", "ElseStmt", "Condition", "ForStmt",
  "ForClause", "InitStmt", "PostStmt", "SwitchStmt", "SwitchPrototype",
  "CaseStmt", "Case", "Default", "FunctionDeclStmt", "FuncPrototype",
  "FuncParameters", "FuncTitle", "ParameterList", "ParID", "FuncBlock",
  "ReturnStmt", "PrintStmt", YY_NULLPTR
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

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,  -118,   -12,    -8,    37,    47,  -118,    46,  -118,   140,
       8,  -118,  -118,  -118,  -118,  -118,    26,  -118,  -118,  -118,
    -118,  -118,   188,   188,   188,    30,     9,    14,  -118,  -118,
      38,   188,  -118,  -118,  -118,  -118,  -118,  -118,   188,    48,
    -118,    39,    45,  -118,    76,    77,    24,     3,   -14,  -118,
      63,   188,  -118,  -118,  -118,  -118,  -118,    85,    43,    94,
      95,  -118,  -118,   140,    89,  -118,  -118,  -118,    49,  -118,
      50,    51,  -118,    96,    99,   -25,    21,  -118,    36,  -118,
    -118,    49,     6,  -118,    49,    49,    53,  -118,  -118,   188,
     188,  -118,    55,  -118,   -17,   188,  -118,  -118,   188,   188,
    -118,  -118,  -118,  -118,  -118,  -118,   188,  -118,  -118,   188,
    -118,  -118,  -118,   188,  -118,  -118,  -118,  -118,  -118,  -118,
     188,  -118,  -118,  -118,   220,  -118,  -118,    89,  -118,  -118,
    -118,  -118,    49,    49,  -118,  -118,  -118,  -118,   -15,    36,
      49,  -118,  -118,    69,    87,  -118,  -118,   188,    71,    72,
    -118,  -118,  -118,    80,    77,    24,     3,   -14,  -118,  -118,
    -118,  -118,    -2,  -118,  -118,  -118,  -118,    97,  -118,  -118,
     204,    -4,  -118,    79,  -118,  -118,  -118,  -118,   242,    36,
    -118,  -118,  -118,  -118,   188,  -118,  -118,  -118,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     2,     4,     0,     6,     0,
       0,     8,   113,     1,     3,     5,     0,    72,     9,    10,
      12,    11,     0,     0,     0,     0,     0,     0,    54,    55,
      52,   118,   107,    56,    57,    47,    48,    49,     0,     0,
      88,     0,    78,    13,    14,    16,    18,    20,    22,    24,
      26,     0,    28,    50,    51,    27,    90,     0,     0,     0,
       0,    79,    65,     0,     0,    66,    67,    68,     0,    69,
       0,     0,   108,     0,     0,     0,     0,    83,     0,    52,
      96,     0,    78,   100,     0,     0,     0,   103,   106,     0,
       0,   119,     0,    60,     0,     0,    85,    86,     0,     0,
      41,    39,    36,    37,    38,    40,     0,    42,    43,     0,
      44,    45,    46,     0,    31,    32,    33,    34,    35,    30,
       0,    29,    26,    63,     0,    64,    62,     0,    89,    91,
     117,   102,     0,     0,    71,    70,   116,   112,     0,     0,
       0,   110,    84,    80,    93,    97,    98,     0,     0,     0,
      53,    59,    58,     0,    17,    19,    21,    23,    25,    15,
      73,    76,     0,    87,   104,   105,   111,     0,   114,   109,
       0,     0,    92,     0,   120,   121,    61,    74,     0,     0,
      81,    82,    95,    94,     0,    77,   115,   101,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,   129,  -118,   -67,   -21,    15,  -118,    40,
      41,    44,    42,   -38,   -46,  -118,  -118,  -118,  -118,  -118,
    -118,  -117,  -118,  -118,  -118,   -50,   -18,  -118,  -118,   -23,
    -118,  -118,  -118,  -118,   -62,   -64,    27,    90,   -16,  -118,
     -19,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,   -11,  -118,  -118,  -118
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   120,   106,   109,   113,    51,
      52,    53,    54,    94,    55,    56,    57,    58,   162,    59,
      60,    78,   143,    61,    62,    63,   130,    64,    65,   172,
      81,    66,    85,    86,   188,    67,    68,    69,    70,    71,
       8,     9,    76,    10,   138,   139,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    80,    82,    87,    84,   122,   131,   161,   136,   140,
      91,   142,   141,   121,   129,    96,    97,    92,    22,   144,
     151,    11,   145,   146,   137,    12,    18,    19,    20,    21,
     110,   111,   112,   152,   166,   100,   167,    13,   101,   102,
     103,    18,    19,    20,    21,   107,   108,   177,    40,   178,
      15,     1,   122,   122,    96,    97,    75,    89,   -96,    77,
     122,   185,    90,   122,   104,   105,    88,   122,   148,   149,
     164,   165,   168,    40,   153,   158,   169,   129,     2,     3,
     114,   115,   116,   117,   118,    93,   -75,    95,    98,   123,
      99,   124,    16,    17,    18,    19,    20,    21,   125,   126,
     134,    40,   119,   135,   150,   132,   133,   147,   170,   182,
     171,    22,   186,    23,    24,    25,    26,    27,    28,    29,
     174,   175,    30,    31,    32,    33,    80,    34,   173,   176,
     136,    35,    36,   184,    14,   159,    37,    38,   154,    39,
     155,    40,   128,    16,    17,    18,    19,    20,    21,   180,
     156,   157,   181,   127,   163,   183,   179,     0,     0,     0,
       0,   187,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,     0,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,     0,     0,     0,    37,    38,     0,
      39,     0,    40,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,     0,     0,     0,     0,    28,    29,     0,
       0,    79,     0,     0,    33,     0,    34,     0,     0,     0,
      35,    36,     0,    28,    29,    37,    38,    30,    39,     0,
      33,     0,    34,     0,     0,     0,    35,    36,     0,    28,
      29,    37,    38,    79,    39,     0,    33,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,   160,
      39,    28,    29,     0,     0,    79,     0,     0,    33,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    39
};

static const yytype_int16 yycheck[] =
{
      23,    22,    23,    24,    23,    51,    68,   124,    33,    76,
      31,    78,    76,    51,    64,     9,    10,    38,    22,    81,
      37,    33,    84,    85,    49,    33,     5,     6,     7,     8,
      44,    45,    46,    50,    49,    11,    51,     0,    14,    15,
      16,     5,     6,     7,     8,    42,    43,    49,    52,    51,
       4,     4,    98,    99,     9,    10,    48,    48,    52,    33,
     106,   178,    48,   109,    40,    41,    36,   113,    89,    90,
     132,   133,   139,    52,    95,   113,   140,   127,    31,    32,
      17,    18,    19,    20,    21,    37,    48,    48,    12,     4,
      13,    48,     3,     4,     5,     6,     7,     8,     4,     4,
       4,    52,    39,     4,    49,    55,    55,    54,    39,   171,
      23,    22,   179,    24,    25,    26,    27,    28,    29,    30,
      49,    49,    33,    34,    35,    36,   147,    38,   147,    49,
      33,    42,    43,    54,     5,   120,    47,    48,    98,    50,
      99,    52,    53,     3,     4,     5,     6,     7,     8,   170,
     106,   109,   170,    63,   127,   171,   167,    -1,    -1,    -1,
      -1,   184,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    43,    -1,    29,    30,    47,    48,    33,    50,    -1,
      36,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,    29,
      30,    47,    48,    33,    50,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    29,    30,    -1,    -1,    33,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    31,    32,    57,    58,    59,    60,   106,   107,
     109,    33,    33,     0,    59,     4,     3,     4,     5,     6,
       7,     8,    22,    24,    25,    26,    27,    28,    29,    30,
      33,    34,    35,    36,    38,    42,    43,    47,    48,    50,
      52,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    75,    76,    77,    78,    80,    81,    82,    83,    85,
      86,    89,    90,    91,    93,    94,    97,   101,   102,   103,
     104,   105,   112,   113,   114,    48,   108,    33,    87,    33,
      62,    96,    62,    85,    96,    98,    99,    62,    36,    48,
      48,    62,    62,    37,    79,    48,     9,    10,    12,    13,
      11,    14,    15,    16,    40,    41,    72,    42,    43,    73,
      44,    45,    46,    74,    17,    18,    19,    20,    21,    39,
      71,    69,    70,     4,    48,     4,     4,    93,    53,    81,
      92,    90,    55,    55,     4,     4,    33,    49,   110,   111,
      61,    91,    61,    88,    90,    90,    90,    54,    62,    62,
      49,    37,    50,    62,    65,    66,    67,    68,    69,    63,
      49,    77,    84,    92,    90,    90,    49,    51,    61,    91,
      39,    23,    95,    96,    49,    49,    49,    49,    51,   111,
      62,    82,    90,    94,    54,    77,    61,    85,   100
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
      81,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      86,    86,    86,    87,    88,    89,    89,    90,    91,    92,
      93,    93,    94,    95,    95,    95,    96,    97,    97,    98,
      99,   100,   101,   102,   103,   103,   104,   105,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   112,   113,   113,
     114,   114
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
       2,     2,     1,     3,     4,     1,     1,     3,     1,     1,
       3,     5,     5,     1,     1,     2,     2,     3,     1,     1,
       1,     2,     4,     0,     2,     2,     1,     3,     3,     5,
       1,     1,     2,     2,     3,     3,     2,     1,     2,     4,
       3,     3,     2,     2,     2,     4,     1,     2,     1,     2,
       4,     4
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
        case 2:
#line 123 "compiler_hw3.y" /* yacc.c:1646  */
    {dump_symbol(--level);}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 139 "compiler_hw3.y" /* yacc.c:1646  */
    {create_symbol(level++); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("I"); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("F"); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("S"); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 146 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = strdup("B"); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=(yyvsp[0].s_val);	
														//CODEGEN("istore %d\n",0);
													str2 = strdup((yyvsp[-2].s_val));
													sub_str = strstr(str2,"_id");
													sub_str[0] = '\0';
													lookup = lookup_symbol(str2);
													if(strcmp((yyvsp[-1].s_val), "assign") != 0){
														CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
														CODEGEN("swap\n");
														CODEGEN("%c%s\n",lookup->type[0]+32,(yyvsp[-1].s_val));
													}
													if(lookup->type[0] == 'S')
														CODEGEN("astore %d\n",lookup->addr);
													else if(lookup->type[0] == 'B'){
														CODEBOOL();
														CODEGEN("astore %d\n",lookup->addr);
															
													}
													else
														CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
													}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 179 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 180 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("ior\n"); (yyval.s_val) = "bool";}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 185 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("iand\n"); (yyval.s_val) = "bool";}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 190 "compiler_hw3.y" /* yacc.c:1646  */
    {	int numtemp = LabelNum;
												if (sub_str = strstr((yyvsp[-2].s_val),"_id")){
													str2 = strdup((yyvsp[-2].s_val));
													sub_str = strstr(str2,"_id");
													sub_str[0] = '\0';
													lookup = lookup_symbol(str2);
													if(lookup->type[0] == 'I'){
														CODEGEN("isub\n");
														CODEGEN("%s L_cmp_%d\n",(yyvsp[-1].s_val),LabelNum++);
													}
													else{
														CODEGEN("fcmpl\n");
														CODEGEN("%s L_cmp_%d\n", (yyvsp[-1].s_val),LabelNum++);
													}
												}
												else if(strcmp((yyvsp[-2].s_val),"I") == 0){
													CODEGEN("isub\n");
													CODEGEN("%s L_cmp_%d\n",(yyvsp[-1].s_val),LabelNum++);
												}
												else{
													CODEGEN("fcmpl\n");
													CODEGEN("%s L_cmp_%d\n",(yyvsp[-1].s_val),LabelNum++);
												}
												CODEGEN("iconst_0\n");
												CODEGEN("goto L_cmp_%d\n",LabelNum);
												CODEGEN("L_cmp_%d:\n",numtemp);
												CODEGEN("iconst_1\n");
												CODEGEN("L_cmp_%d:\n",LabelNum++);
												(yyval.s_val) = "bool";
											}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 223 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    {	printf("addddddd11\n");
//												printf("%s %s %s\n",$<s_val>1,$<s_val>2,$<s_val>3);
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
													CODEGEN("%c%s\n",(yyvsp[-2].s_val)[0]+32,(yyvsp[-1].s_val));
													//printf("else\n");
												}
											}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 246 "compiler_hw3.y" /* yacc.c:1646  */
    {
												printf("adddddd22d\n");
                                                printf("%s %s \n",(yyvsp[-2].s_val),(yyvsp[-1].s_val));
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
													CODEGEN("%c%s\n",(yyvsp[-2].s_val)[0]+32,(yyvsp[-1].s_val));
                                                    printf("else\n");
                                                }
											}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 268 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 269 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 273 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 274 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);printf("negggggggggggggggg\n");
									if(strcmp((yyvsp[-1].s_val),"neg") == 0){
										if(sub_str = strstr((yyvsp[0].s_val),"_id")){
											str2 = strdup((yyvsp[0].s_val));
											sub_str = strstr(str2,"_id");
											sub_str[0] = '\0';
											lookup = lookup_symbol(str2);
											CODEGEN("%cneg\n",lookup->type[0]+32);
										}
										else{
											CODEGEN("%cneg\n",(yyvsp[0].s_val)[0]+32);
										}
									}
									else if(strcmp((yyvsp[-1].s_val),"!") == 0){
										CODEGEN("ixor\n");
									}
									}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 294 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "assign";}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 295 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "add";}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 296 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "sub";}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 297 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "mul";}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 298 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "div";}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 299 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "rem";}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 303 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "ifeq";}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 305 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "iflt";}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 307 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "ifgt";}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 312 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "add"; }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 313 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "sub"; }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 317 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "mul"; }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 318 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "div"; }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 319 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "rem"; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 323 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "";}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 324 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "neg";}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "!";CODEGEN("iconst_1\n");}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 329 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 333 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 334 "compiler_hw3.y" /* yacc.c:1646  */
    {
						lookup = lookup_symbol(yylval.s_val);
						if(!lookup){
							(yyval.s_val) = strdup(yylval.s_val);
							strcat((yyval.s_val),"_id");
						}
						else{
							(yyval.s_val) = strdup(lookup->name);
							strcat((yyval.s_val),"_id");
						
						printf("IDID\n");
						if(strcmp(lookup->type,"I") == 0)
							CODEGEN("iload %d\n", lookup->addr);
						else if (strcmp(lookup->type, "F") == 0)
							CODEGEN("fload %d\n", lookup->addr);
						else
							CODEGEN("aload %d\n", lookup->addr);
						}
					}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 354 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; CODEGEN("iconst_1\n"); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 355 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; CODEGEN("iconst_0\n"); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "I"; CODEGEN("ldc %d\n",yylval.i_val); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "F"; CODEGEN("ldc %f\n",yylval.f_val); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "S"; CODEGEN("ldc \"%s\"\n", yylval.s_val); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[-3].s_val);
								if (sub_str = strstr((yyvsp[-1].s_val),"_id")){
									str2 = strdup((yyvsp[-1].s_val));
									sub_str = strstr(str2,"_id");
									sub_str[0] = '\0';
									lookup = lookup_symbol(str2);
									CODEGEN("%c2%c\n",lookup->type[0]+32,(yyvsp[-3].s_val)[0]+32);
								}
								else{
									CODEGEN("%c2%c\n",(yyvsp[-1].s_val)[0]+32,(yyvsp[-3].s_val)[0]+32);
								}
					
								}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 400 "compiler_hw3.y" /* yacc.c:1646  */
    {
										lookup = lookup_symbol((yyvsp[-2].s_val));	
										CODEGEN("invokestatic Main/%s%s\n",lookup->name,lookup->func_sig);

										}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 406 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        lookup = lookup_symbol((yyvsp[-3].s_val));
                                        CODEGEN("invokestatic Main/%s%s\n",lookup->name,lookup->func_sig);
                                        }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 414 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = yylval.s_val;}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 430 "compiler_hw3.y" /* yacc.c:1646  */
    {
										lookup = lookup_symbol((yyvsp[-1].s_val));
										if(lookup && lookup->level == level-1){
											printf("error:%d: %s redeclared in this bloc    k. previous declaration at line %d\n",yylineno, (yyvsp[-1].s_val) ,123);
											g_has_error = true;
										}
										insert_symbol((yyvsp[-1].s_val),addr++,level-1,(yyvsp[0].s_val),"-",yylineno);
										if((yyvsp[0].s_val)[0] == 'F'){
											CODEGEN("ldc 0.0\n");
											CODEGEN("fstore %d\n",addr-1);
										}
										else if ((yyvsp[0].s_val)[0] == 'I'){
											CODEGEN("ldc 0\n");
											CODEGEN("istore %d\n",addr-1);
										}
										else{
											if((yyvsp[0].s_val)[0] == 'B')
												CODEBOOL();
											else
												CODEGEN("ldc \"\"\n");
											CODEGEN("astore %d\n",addr-1);
										}
										}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 453 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        ENTRY *lookup = lookup_symbol((yyvsp[-3].s_val));
                                        if(lookup && lookup->level == level-1){
                                          printf("error:%d: %s redeclared in this bloc    k. previous de    claration at line %d\n",yylineno, (yyvsp[-3].s_val) ,123);
                                            g_has_error = true;
                                        }
                                        insert_symbol((yyvsp[-3].s_val),addr++,level-1,(yyvsp[-2].s_val),"-",yylineno);
                                        instruction = strdup((yyvsp[-2].s_val));
										if(instruction[0] == 'S'|| instruction[0] == 'B'){
											if(instruction[0] == 'B'){
												CODEGEN("ifne L_cmp_%d\n",LabelNum++);
												CODEGEN("ldc \"false\"\n");
												CODEGEN("goto L_cmp_%d\n",LabelNum++);
												CODEGEN("L_cmp_%d:\n",LabelNum-2);
												CODEGEN("ldc \"true\"\n");
												CODEGEN("L_cmp_%d:\n",LabelNum-1);
											}
											instruction[0] = 'a';
										}
										else
											instruction[0] = instruction[0] + 32;
										CODEGEN("%sstore %d\n",instruction, addr-1 );
                                        }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 477 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        ENTRY *lookup = lookup_symbol((yyvsp[-3].s_val));
                                        if(lookup && lookup->level == level-1){
                                          printf("error:%d: %s redeclared in this bloc    k. previous de    claration at line %d\n",yylineno, (yyvsp[-3].s_val) ,123);
                                            g_has_error = true;
                                        }
                                        insert_symbol((yyvsp[-3].s_val),addr++,level-1,(yyvsp[-2].s_val),"-",yylineno);
                                        instruction = strdup((yyvsp[-2].s_val));
										if(instruction[0] == 'S' || instruction[0] == 'B'){
											if(instruction[0] == 'B'){
                                                CODEGEN("ifne L_cmp_%d\n",LabelNum++);
                                                CODEGEN("ldc \"false\"\n");
                                                CODEGEN("goto L_cmp_%d\n",LabelNum++);
                                                CODEGEN("L_cmp_%d:\n",LabelNum-2);
                                                CODEGEN("ldc \"true\"\n");
                                                CODEGEN("L_cmp_%d:\n",LabelNum-1);
                                            }
                                            instruction[0] = 'a';
										}
                                        else
											instruction[0] = instruction[0] + 32;
										CODEGEN("%sstore %d\n",instruction, addr-1);
                                        
                                        }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 505 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=strdup(yylval.s_val);}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 509 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 513 "compiler_hw3.y" /* yacc.c:1646  */
    {
						if(sub_str = strstr((yyvsp[-1].s_val),"_id")){
							str2 = strdup((yyvsp[-1].s_val));
							sub_str = strstr(str2,"_id");
							sub_str[0] = '\0';
							lookup = lookup_symbol(str2);
							if(lookup->type[0] == 'I')
								CODEGEN("ldc 1\n");
							else
								CODEGEN("ldc 1.0\n");
							CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
							CODEGEN("%cadd\n",lookup->type[0]+32);
							CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
						}
					}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 528 "compiler_hw3.y" /* yacc.c:1646  */
    {
                        if(sub_str = strstr((yyvsp[-1].s_val),"_id")){
                            str2 = strdup((yyvsp[-1].s_val));
                            sub_str = strstr(str2,"_id");
                            sub_str[0] = '\0';
                            lookup = lookup_symbol(str2);
                            CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
							if(lookup->type[0] == 'I')
                                CODEGEN("ldc 1\n");
                            else
                                CODEGEN("ldc 1.0\n");

							CODEGEN("%csub\n",lookup->type[0]+32);
                            CODEGEN("%cstore %d\n",lookup->type[0]+32,lookup->addr);
                        }
                    }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 552 "compiler_hw3.y" /* yacc.c:1646  */
    {  create_symbol(level++);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 556 "compiler_hw3.y" /* yacc.c:1646  */
    {dump_symbol(--level);}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 597 "compiler_hw3.y" /* yacc.c:1646  */
    {

								CODEGEN("L_switch_begin_%d:\n",LabelNum -1);
								CODEGEN("lookupswitch\n");
								for(int i =0;i<case_num;i++){
									CODEGEN("%d: L_case_%d%d\n", cases[i],LabelNum-1, i);
									
								}
								CODEGEN("default: L_case_%d%d\n",LabelNum -1, case_num);
								CODEGEN("L_switch_end_%d:\n",LabelNum-1);
								CODEGEN("return\n");
							}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 612 "compiler_hw3.y" /* yacc.c:1646  */
    {
						printf("switch\n");
						str2 = strdup((yyvsp[0].s_val));
						sub_str = strstr(str2,"_id");
						sub_str[0] = '\0';
						lookup = lookup_symbol(str2);
						CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
						CODEGEN("goto L_switch_begin_%d\n",LabelNum++);
						case_num = 0;
						cases = malloc(sizeof(int) * 100);
						}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 626 "compiler_hw3.y" /* yacc.c:1646  */
    {
							CODEGEN("goto L_switch_end_%d\n",LabelNum-1);
						}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 629 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("goto L_switch_end_%d\n",LabelNum -1 );}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 633 "compiler_hw3.y" /* yacc.c:1646  */
    {	printf("case\n");
						CODEGEN("L_case_%d%d:\n",LabelNum -1, case_num);
						cases[case_num++] = yylval.i_val;
					}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 640 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("L_case_%d%d:\n",LabelNum -1, case_num);}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 648 "compiler_hw3.y" /* yacc.c:1646  */
    {	CODEGEN(".method public static %s(%s)%s\n",(yyvsp[-3].s_val), strcmp((yyvsp[-3].s_val),"main") == 0?"[Ljava/lang/String;":(yyvsp[-2].s_val), (yyvsp[-1].s_val));
													CODEGEN(".limit stack 100\n");
													CODEGEN(".limit locals 100\n");
													FUNCPARAMETERS();
													strcat(func_sig,(yyvsp[-1].s_val));
													insert_symbol((yyvsp[-3].s_val),-1,level-2,"func",func_sig,yylineno+1);
														printf("func finish\n");
													func_return[0] = (yyvsp[-1].s_val)[0]+32;
												}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 657 "compiler_hw3.y" /* yacc.c:1646  */
    {	CODEGEN(".method public static %s(%s)V\n",(yyvsp[-2].s_val), strcmp((yyvsp[-2].s_val),"main") == 0?"[Ljava/lang/String;":(yyvsp[-1].s_val));
                                    			CODEGEN(".limit stack 100\n");
	                                            CODEGEN(".limit locals 100\n");
												FUNCPARAMETERS();
												strcat(func_sig,"V");
												insert_symbol((yyvsp[-2].s_val),-1,level-2,"func",func_sig,yylineno+1);
												func_return[0] = '\0';
												}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 668 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[-1].s_val);strcat(func_sig,")");}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 669 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = "";strcat(func_sig,")");/*$<s_val>$ = malloc(sizeof(char)); $<s_val>$[0] = '\0';*/}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 673 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = yylval.s_val;
/*				printf("funcid \n");
				printf("%s\n",$<s_val>$);*/
				parameters = malloc(sizeof(char) * 100);
				parameters_num = 0;
				
				func_sig = malloc(sizeof(char) * 100);
				strcat(func_sig,"(");
}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 685 "compiler_hw3.y" /* yacc.c:1646  */
    {
					(yyval.s_val) = (yyvsp[0].s_val); 
					strcat(parameters,(yyvsp[-1].s_val)); 
					strcat(parameters," "); 
					strcat(parameters,(yyvsp[0].s_val)); 
					strcat(parameters,"/"); 
					parameters_num++;
					strcat(func_sig,(yyvsp[0].s_val));
					}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 694 "compiler_hw3.y" /* yacc.c:1646  */
    {
									strcat((yyval.s_val),(yyvsp[0].s_val));
									strcat(parameters,(yyvsp[-1].s_val)); 
									strcat(parameters," "); 
									strcat(parameters,(yyvsp[0].s_val)); 
									strcat(parameters,"/"); 
									parameters_num++;
									strcat(func_sig,(yyvsp[0].s_val));
									}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 706 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val) = yylval.s_val;}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 710 "compiler_hw3.y" /* yacc.c:1646  */
    {CODEGEN("%sreturn\n.end method\n",func_return);}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 719 "compiler_hw3.y" /* yacc.c:1646  */
    {	if(strcmp((yyvsp[-1].s_val),"S") != 0) {
										if (sub_str = strstr((yyvsp[-1].s_val),"_id")){
											printf("innnnnnn\n");
											str2 = strdup((yyvsp[-1].s_val));
											sub_str = strstr(str2,"_id");
											sub_str[0] = '\0';
											lookup = lookup_symbol(str2);
											if(lookup->type[0]=='F' || lookup->type[0] == 'I'){
//												CODEGEN("%cload %d\n",lookup->type[0]+32,lookup->addr);
												instruction = lookup->type;
											}
											else{
//												CODEGEN("aload %d\n",lookup->addr);
												instruction = "Ljava/lang/String;";
											}
										}
										else if(strcmp((yyvsp[-1].s_val),"bool") == 0 ){
											CODEGEN("ifne L_cmp_%d\n",LabelNum++);
											CODEGEN("ldc \"false\"\n");
											CODEGEN("goto L_cmp_%d\n",LabelNum++);
											CODEGEN("L_cmp_%d:\n",LabelNum-2);
											CODEGEN("ldc \"true\"\n");
											CODEGEN("L_cmp_%d:\n",LabelNum-1);
											instruction = "Ljava/lang/String;";
										}
										else if((yyvsp[-1].s_val)[0] == 'B')
											instruction = "a";
										else{
											printf("innnnnnn2\n");
											instruction = (yyvsp[-1].s_val);
										}
										CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(%s)V\n",instruction);
									}
									else CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
								}
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 754 "compiler_hw3.y" /* yacc.c:1646  */
    {	if(strcmp((yyvsp[-1].s_val), "S") != 0) {
											if (sub_str = strstr((yyvsp[-1].s_val),"_id")){
                                        	//    printf("innnnnnn\n");
                                    	        str2 = strdup((yyvsp[-1].s_val));
                                	            sub_str = strstr(str2,"_id");
                            	                sub_str[0] = '\0';
                        	                    lookup = lookup_symbol(str2);
												
												if(lookup->type[0]=='F' || lookup->type[0] == 'I'){
	//												CODEGEN("%cload %d\n", lookup->type[0]+32, lookup->addr);
												
	                    	                        instruction = lookup->type;
												}
												else{
//													CODEGEN("aload %d\n",lookup->addr);
            	                                	instruction = "Ljava/lang/String;";
												}
                	                    	}
											else if(strcmp((yyvsp[-1].s_val),"bool") == 0){
	                                            CODEGEN("ifne L_cmp_%d\n",LabelNum++);
	                                            CODEGEN("ldc \"false\"\n");
	                                            CODEGEN("goto L_cmp_%d\n",LabelNum++);
	                                            CODEGEN("L_cmp_%d:\n",LabelNum-2);
    	                                        CODEGEN("ldc \"true\"\n");
        	                                    CODEGEN("L_cmp_%d:\n",LabelNum-1);
            	                                instruction = "Ljava/lang/String;";
                	                        }
											else if((yyvsp[-1].s_val)[0] == 'B')
												instruction = "a";

            	                            else{
        	                                  //  printf("innnnnnn2\n");
    	                                         instruction = (yyvsp[-1].s_val);
	                                        }
											CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(%s)V\n",instruction);
										}
										else CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
									}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2370 "y.tab.c" /* yacc.c:1646  */
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
#line 798 "compiler_hw3.y" /* yacc.c:1906  */


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
    printf("insert\n");
//printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, level);
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

    null_next->next = NULL;

}




void CODEBOOL(){

	CODEGEN("ifne L_cmp_%d\n",LabelNum++);
	CODEGEN("ldc \"false\"\n");
	CODEGEN("goto L_cmp_%d\n",LabelNum++);
	CODEGEN("L_cmp_%d:\n",LabelNum-2);
	CODEGEN("ldc \"true\"\n");
	CODEGEN("L_cmp_%d:\n",LabelNum-1);

}


void FUNCPARAMETERS(){
	int n =0;
	for(int i =0;i<parameters_num;i++){
    	char parameter_name[100], parameter_type[10];
        int name_len = 0, type_len = 0;
/*      parameter_name[0] = '\0';
        parameter_type[0] = '\0';*/
        memset(parameter_name,0,100);
        memset(parameter_type,0,10);
        while(parameters[n]!=' '){
//      strcat(parameter_name,parameters[n]);
        	parameter_name[name_len++] = parameters[n];
        	n++;
        }
        n++;
        while(parameters[n]!='/'){
//      	strcat(parameter_type,parameters[n]);
	        parameter_type[type_len++] = parameters[n];
        	n++;
        }
        n++;
        printf("param %s, type: %c\n", parameter_name, parameter_type[0]-32);
        insert_symbol(&parameter_name[0], addr++, level-1, &parameter_type[0],"-", yylineno + 1);	
	}


}
