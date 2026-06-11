
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sql.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
    NODE_SELECT, NODE_INSERT, NODE_UPDATE, NODE_DELETE,
    NODE_CREATE_TABLE, NODE_DROP_TABLE, NODE_SHOW_TABLES
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char *table;
    char *columns;
    char *where;
    char *col_defs;
    char *set_items;
    char *values;
    char *order_by;
    char *limit;
    char *group_by;
    char *having;
    char *join_clause;
    int distinct;
} ASTNode;

extern FILE *yyin;
extern int yylex();
extern int yylineno;
void yyerror(const char *s);
void print_ast(ASTNode *node);
void free_ast(ASTNode *node);

#define YYSTYPE char*

// 字符串拼接工具函数
char* concat(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    
    char *res = malloc(len + 1);
    va_start(args, fmt);
    vsnprintf(res, len + 1, fmt, args);
    va_end(args);
    return res;
}


/* Line 189 of yacc.c  */
#line 125 "sql.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SELECT = 258,
     FROM = 259,
     WHERE = 260,
     AND = 261,
     OR = 262,
     NOT = 263,
     INSERT = 264,
     INTO = 265,
     VALUES = 266,
     UPDATE = 267,
     SET = 268,
     DELETE = 269,
     CREATE = 270,
     TABLE = 271,
     DROP = 272,
     SHOW = 273,
     TABLES = 274,
     INT = 275,
     VARCHAR = 276,
     CHAR = 277,
     DATE = 278,
     FLOAT = 279,
     DOUBLE = 280,
     NULL_LITERAL = 281,
     EQUALS = 282,
     NOT_EQUALS = 283,
     LT = 284,
     GT = 285,
     LTE = 286,
     GTE = 287,
     LPAREN = 288,
     RPAREN = 289,
     COMMA = 290,
     STAR = 291,
     SEMICOLON = 292,
     DOT = 293,
     NUMBER = 294,
     STRING = 295,
     IDENTIFIER = 296,
     ORDER = 297,
     BY = 298,
     LIMIT = 299,
     DISTINCT = 300,
     COUNT = 301,
     SUM = 302,
     AVG = 303,
     MIN = 304,
     MAX = 305,
     LIKE = 306,
     BETWEEN = 307,
     ASC = 308,
     DESC = 309,
     AS = 310,
     GROUP = 311,
     HAVING = 312,
     JOIN = 313,
     INNER = 314,
     LEFT = 315,
     RIGHT = 316,
     ON = 317,
     CASE = 318,
     WHEN = 319,
     THEN = 320,
     ELSE = 321,
     END = 322,
     INTERVAL = 323,
     YEAR = 324,
     ANY = 325,
     ALL = 326,
     IN = 327,
     MINUS = 328,
     PLUS = 329,
     DIV = 330
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 242 "sql.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   977

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNRULES -- Number of states.  */
#define YYNSTATES  285

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    14,    16,    18,    20,
      22,    24,    26,    38,    50,    52,    56,    59,    66,    72,
      80,    87,    88,    90,    92,    94,    95,    97,    98,   100,
     102,   104,   108,   110,   114,   117,   118,   122,   123,   125,
     129,   132,   133,   137,   138,   140,   143,   146,   150,   155,
     160,   163,   168,   169,   180,   182,   186,   188,   192,   197,
     204,   208,   214,   218,   224,   231,   233,   237,   240,   246,
     251,   259,   261,   263,   265,   267,   269,   271,   275,   278,
     280,   282,   284,   288,   292,   294,   296,   298,   302,   306,
     310,   314,   318,   322,   326,   330,   336,   340,   344,   350,
     356,   363,   370,   377,   384,   388,   392,   396,   400,   404,
     407,   413,   420,   425,   431,   436,   441,   446,   451,   456,
     461,   465,   470,   475,   482,   491,   502,   504,   506
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      77,     0,    -1,    78,    -1,    79,    37,    -1,    78,    79,
      37,    -1,    80,    -1,    96,    -1,    99,    -1,   101,    -1,
     102,    -1,   106,    -1,   107,    -1,     3,    85,    86,     4,
      82,    83,    89,    90,    92,    93,    95,    -1,     3,    85,
      86,     4,    82,    83,    89,    90,    92,    93,    95,    -1,
      41,    -1,    41,    55,    41,    -1,    41,    41,    -1,    84,
      58,    41,    41,    62,   108,    -1,    84,    58,    41,    62,
     108,    -1,    83,    84,    58,    41,    41,    62,   108,    -1,
      83,    84,    58,    41,    62,   108,    -1,    -1,    59,    -1,
      60,    -1,    61,    -1,    -1,    45,    -1,    -1,    36,    -1,
      87,    -1,    88,    -1,    87,    35,    88,    -1,   108,    -1,
     108,    55,    41,    -1,     5,   108,    -1,    -1,    56,    43,
      91,    -1,    -1,   108,    -1,    91,    35,   108,    -1,    57,
     108,    -1,    -1,    42,    43,    94,    -1,    -1,   108,    -1,
     108,    53,    -1,   108,    54,    -1,    94,    35,   108,    -1,
      94,    35,   108,    53,    -1,    94,    35,   108,    54,    -1,
      44,    39,    -1,    44,    39,    35,    39,    -1,    -1,     9,
      10,    41,    33,    97,    34,    11,    33,    98,    34,    -1,
      41,    -1,    97,    35,    41,    -1,   113,    -1,    98,    35,
     113,    -1,    12,    41,    13,   100,    -1,    12,    41,    13,
     100,     5,   108,    -1,    41,    27,   108,    -1,   100,    35,
      41,    27,   108,    -1,    14,     4,    41,    -1,    14,     4,
      41,     5,   108,    -1,    15,    16,    41,    33,   103,    34,
      -1,   104,    -1,   103,    35,   104,    -1,    41,   105,    -1,
      41,   105,    33,    39,    34,    -1,    41,   105,     8,    26,
      -1,    41,   105,    33,    39,    34,     8,    26,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    17,    16,    41,    -1,    18,    19,    -1,   113,    -1,
      41,    -1,    69,    -1,    68,   108,    69,    -1,    41,    38,
      41,    -1,   112,    -1,   111,    -1,   109,    -1,    33,    80,
      34,    -1,   108,    27,   108,    -1,   108,    28,   108,    -1,
     108,    29,   108,    -1,   108,    30,   108,    -1,   108,    31,
     108,    -1,   108,    32,   108,    -1,   108,    51,   108,    -1,
     108,    52,   108,     6,   108,    -1,   108,     6,   108,    -1,
     108,     7,   108,    -1,   108,    72,    33,    98,    34,    -1,
     108,    72,    33,    81,    34,    -1,   108,    29,    70,    33,
      81,    34,    -1,   108,    30,    70,    33,    81,    34,    -1,
     108,    29,    71,    33,    81,    34,    -1,   108,    30,    71,
      33,    81,    34,    -1,   108,    74,   108,    -1,   108,    73,
     108,    -1,   108,    36,   108,    -1,   108,    75,   108,    -1,
      33,   108,    34,    -1,     8,   108,    -1,    63,   110,    66,
     108,    67,    -1,    63,   108,   110,    66,   108,    67,    -1,
      64,   108,    65,   108,    -1,   110,    64,   108,    65,   108,
      -1,    46,    33,    36,    34,    -1,    46,    33,    41,    34,
      -1,    47,    33,   108,    34,    -1,    48,    33,   108,    34,
      -1,    49,    33,   108,    34,    -1,    50,    33,   108,    34,
      -1,    41,    33,    34,    -1,    41,    33,   108,    34,    -1,
      69,    33,   108,    34,    -1,    41,    33,   108,    35,   108,
      34,    -1,    41,    33,   108,    35,   108,    35,   108,    34,
      -1,    41,    33,   108,    35,   108,    35,   108,    35,   108,
      34,    -1,    40,    -1,    39,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    80,    81,    85,    86,    87,    88,    89,
      90,    91,    95,   113,   128,   129,   133,   140,   144,   148,
     152,   156,   160,   161,   162,   163,   167,   168,   172,   173,
     177,   178,   185,   186,   193,   194,   198,   199,   203,   204,
     211,   212,   216,   217,   221,   222,   226,   230,   234,   238,
     245,   249,   253,   257,   269,   270,   277,   278,   285,   293,
     305,   309,   316,   323,   334,   345,   346,   353,   357,   361,
     365,   372,   373,   374,   375,   376,   377,   381,   391,   400,
     401,   402,   403,   407,   411,   412,   413,   414,   415,   419,
     423,   427,   431,   435,   439,   443,   447,   451,   455,   459,
     463,   467,   471,   475,   479,   483,   487,   491,   495,   498,
     505,   509,   516,   520,   527,   528,   532,   536,   540,   544,
     551,   555,   559,   563,   567,   571,   578,   579,   580
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SELECT", "FROM", "WHERE", "AND", "OR",
  "NOT", "INSERT", "INTO", "VALUES", "UPDATE", "SET", "DELETE", "CREATE",
  "TABLE", "DROP", "SHOW", "TABLES", "INT", "VARCHAR", "CHAR", "DATE",
  "FLOAT", "DOUBLE", "NULL_LITERAL", "EQUALS", "NOT_EQUALS", "LT", "GT",
  "LTE", "GTE", "LPAREN", "RPAREN", "COMMA", "STAR", "SEMICOLON", "DOT",
  "NUMBER", "STRING", "IDENTIFIER", "ORDER", "BY", "LIMIT", "DISTINCT",
  "COUNT", "SUM", "AVG", "MIN", "MAX", "LIKE", "BETWEEN", "ASC", "DESC",
  "AS", "GROUP", "HAVING", "JOIN", "INNER", "LEFT", "RIGHT", "ON", "CASE",
  "WHEN", "THEN", "ELSE", "END", "INTERVAL", "YEAR", "ANY", "ALL", "IN",
  "MINUS", "PLUS", "DIV", "$accept", "parse", "statement_list",
  "sql_statement", "select_statement", "subquery", "table_reference",
  "join_clause", "join_type", "optional_distinct", "select_columns",
  "select_list", "select_item", "optional_where", "optional_group_by",
  "expression_list", "optional_having", "optional_order_by", "order_list",
  "optional_limit", "insert_statement", "column_list", "value_list",
  "update_statement", "set_clause", "delete_statement", "create_statement",
  "column_definitions", "column_definition", "type_name", "drop_statement",
  "show_statement", "expression", "case_expression", "case_when_list",
  "aggregate_function", "function_call", "literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   103,   103,   104,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   106,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   112,   113,   113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,    11,    11,     1,     3,     2,     6,     5,     7,
       6,     0,     1,     1,     1,     0,     1,     0,     1,     1,
       1,     3,     1,     3,     2,     0,     3,     0,     1,     3,
       2,     0,     3,     0,     1,     2,     2,     3,     4,     4,
       2,     4,     0,    10,     1,     3,     1,     3,     4,     6,
       3,     5,     3,     5,     6,     1,     3,     2,     5,     4,
       7,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     3,     5,     5,
       6,     6,     6,     6,     3,     3,     3,     3,     3,     2,
       5,     6,     4,     5,     4,     4,     4,     4,     4,     4,
       3,     4,     4,     6,     8,    10,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     5,     6,     7,     8,     9,    10,    11,    26,     0,
       0,     0,     0,     0,     0,    78,     1,     0,     3,     0,
     128,     0,    28,   127,   126,    80,     0,     0,     0,     0,
       0,     0,     0,    81,     0,    29,    30,    32,    86,    85,
      84,    79,     0,     0,    62,     0,    77,     4,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,    87,   108,   120,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,    14,    21,    31,    96,    97,    88,    89,
       0,     0,    90,     0,     0,    91,    92,    93,   106,    94,
       0,    33,     0,   105,   104,   107,    54,     0,     0,     0,
       0,    63,     0,     0,    65,   121,     0,   114,   115,   116,
     117,   118,   119,     0,     0,     0,     0,   122,    16,     0,
      22,    23,    24,    35,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    56,     0,     0,    60,    59,     0,    71,
      72,    73,    74,    75,    76,    67,    64,     0,     0,   112,
       0,     0,   110,    15,     0,     0,    37,     0,     0,     0,
       0,     0,    95,     0,    99,    98,     0,     0,    55,     0,
       0,     0,    66,   123,     0,   111,   113,    34,     0,     0,
      41,     0,   100,   102,   101,   103,     0,    57,     0,    61,
      69,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,    68,   124,     0,     0,     0,    36,    38,    40,     0,
      52,     0,    18,    21,    53,     0,     0,     0,    20,     0,
       0,     0,    12,    17,    35,    70,   125,    19,    39,    42,
      44,    50,    37,     0,    45,    46,     0,    41,    47,    51,
      43,    48,    49,    52,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,   171,   114,   163,   164,    19,
      44,    45,    46,   196,   220,   246,   236,   250,   269,   262,
      12,   137,   172,    13,    93,    14,    15,   143,   144,   185,
      16,    17,    47,    48,    70,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
static const yytype_int16 yypact[] =
{
       7,   -19,    20,   -30,    54,    26,    48,    63,    75,     7,
      52,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   812,
      60,    80,    65,    82,    96,  -163,  -163,   101,  -163,   908,
    -163,   734,  -163,  -163,  -163,    33,    64,   106,   108,   127,
     128,   838,   908,   130,   144,   129,  -163,   277,  -163,  -163,
    -163,  -163,   135,   140,   164,   137,  -163,  -163,   661,   148,
     288,   864,   142,    38,   908,   908,   908,   908,   908,   337,
      12,   347,   908,   143,   908,   908,   908,   908,   908,   760,
     786,   908,   908,   908,   908,   908,   145,   138,   908,   908,
     908,   150,   165,    10,   908,   158,  -163,  -163,  -163,    56,
    -163,   169,   170,   396,   407,   456,   466,   515,    34,   908,
     908,  -163,   526,   -32,    73,  -163,    84,   689,   714,   714,
     174,   175,    21,   177,   178,    21,    21,    21,   161,   661,
     679,  -163,     1,   -31,   -31,   161,  -163,   -17,   908,   908,
     172,   661,   154,    -1,  -163,  -163,   908,  -163,  -163,  -163,
    -163,  -163,  -163,   908,   908,   543,   575,  -163,  -163,   179,
    -163,  -163,  -163,     9,   157,   216,   216,   216,   216,   908,
     -19,   187,    69,  -163,   212,   185,   661,   661,   200,  -163,
    -163,  -163,  -163,  -163,  -163,    -2,  -163,   158,   115,   661,
     603,   908,  -163,  -163,   908,   171,   176,   192,   202,   203,
     208,   209,    84,   812,  -163,  -163,    79,   219,  -163,   908,
     225,   214,  -163,  -163,   908,  -163,   661,   661,   220,   222,
     205,   -34,  -163,  -163,  -163,  -163,   259,  -163,    79,   661,
    -163,   232,   166,   -33,   908,   908,   226,   211,   908,   143,
      92,   266,  -163,   908,   213,   908,   241,   661,   661,   224,
     233,   908,   661,    73,  -163,   252,   630,   908,   661,   908,
     908,   246,  -163,   661,     9,  -163,  -163,   661,   661,   251,
     218,   253,   176,   908,  -163,  -163,   248,   205,   228,  -163,
     226,  -163,  -163,   233,  -163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   280,   265,   -13,    58,    45,  -162,   141,
     107,  -163,   238,    35,    42,  -163,    44,    43,  -163,    47,
    -163,  -163,    97,  -163,  -163,  -163,  -163,  -163,   139,  -163,
    -163,  -163,   -29,  -163,   258,  -163,  -163,  -129
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      58,   195,    60,   173,   170,    83,   210,   237,   244,   158,
       1,    21,    69,    71,   194,   139,     2,   174,   175,     3,
      84,     4,     5,   159,     6,     7,    18,    30,   238,   245,
      20,   211,    99,   186,   187,   103,   104,   105,   106,   107,
      33,    34,    23,   112,    90,   140,   116,   117,   118,   119,
     122,   125,   126,   127,   128,   129,   130,    83,    22,   133,
     134,   135,    75,    76,    24,   141,    61,   -25,   160,   161,
     162,    62,    84,    85,   101,    26,   109,   227,   110,   102,
     155,   156,    25,    77,    78,    79,    80,    81,    82,    28,
     145,   146,    83,    53,    88,    89,    90,    63,   109,   173,
     154,    52,   195,   205,   206,    30,    54,    84,    85,   176,
     177,    77,    78,    79,    80,    81,    82,   188,    33,    34,
      83,    75,    76,    55,   189,   190,   254,   206,    87,    88,
      89,    90,   160,   161,   162,    84,    85,    56,    57,    64,
     202,    65,    77,    78,    79,    80,    81,    82,    73,   213,
     214,    83,   198,   199,   200,   201,    87,    88,    89,    90,
      66,    67,   216,    72,    74,   217,    84,    85,    91,    94,
      95,   132,    75,    76,   179,   180,   181,   182,   183,   184,
     229,    92,    96,   100,   113,   232,   131,    87,    88,    89,
      90,   136,   138,    77,    78,    79,    80,    81,    82,   142,
     242,   243,    83,   147,   148,   247,   248,   165,   166,   252,
     167,   168,    84,   178,   256,   197,   258,    84,    85,   170,
     193,   204,   263,   207,    75,    76,   208,   209,   267,   218,
     268,   270,   219,   221,    75,    76,   222,   223,    87,    88,
      89,    90,   224,   225,   278,    77,    78,    79,    80,    81,
      82,   230,   228,   231,    83,    77,    78,    79,    80,    81,
      82,   233,   235,   239,    83,   234,   241,   260,   249,    84,
      85,   274,   275,   251,   255,   257,   259,   261,   265,    84,
      85,   281,   282,    75,    76,   271,   273,   279,   276,    27,
      87,    88,    89,    90,    75,    76,    59,   253,   264,   272,
      87,    88,    89,    90,    77,    78,    79,    80,    81,    82,
     226,   203,   115,    83,   277,    77,    78,    79,    80,    81,
      82,   280,    97,   283,    83,   240,   212,   108,    84,    85,
     284,     0,    86,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,    75,    76,     0,     0,     0,     0,    87,
      88,    89,    90,    75,    76,     0,     0,     0,     0,     0,
      87,    88,    89,    90,    77,    78,    79,    80,    81,    82,
       0,     0,     0,    83,    77,    78,    79,    80,    81,    82,
       0,     0,     0,    83,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,    68,    75,    76,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    75,    76,     0,   111,     0,     0,    87,
      88,    89,    90,    77,    78,    79,    80,    81,    82,     0,
     149,     0,    83,     0,    77,    78,    79,    80,    81,    82,
       0,   150,     0,    83,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,    75,    76,     0,     0,     0,     0,    87,    88,
      89,    90,    75,    76,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    77,    78,    79,    80,    81,    82,     0,
     151,     0,    83,    77,    78,    79,    80,    81,    82,     0,
     152,     0,    83,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,    75,    76,     0,     0,     0,     0,     0,    87,    88,
      89,    90,    75,    76,     0,     0,     0,     0,    87,    88,
      89,    90,    77,    78,    79,    80,    81,    82,     0,    75,
      76,    83,     0,    77,    78,    79,    80,    81,    82,     0,
     157,     0,    83,     0,     0,     0,    84,    85,     0,     0,
      77,    78,    79,    80,    81,    82,     0,    84,    85,    83,
     153,    75,    76,     0,     0,     0,     0,    87,    88,    89,
      90,     0,     0,     0,    84,    85,     0,     0,    87,    88,
      89,    90,    77,    78,    79,    80,    81,    82,   191,    75,
      76,    83,     0,     0,     0,    87,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
      77,    78,    79,    80,    81,    82,    75,    76,     0,    83,
       0,     0,   192,     0,     0,     0,     0,    87,    88,    89,
      90,     0,     0,     0,    84,    85,     0,    77,    78,    79,
      80,    81,    82,     0,   266,     0,    83,    75,    76,     0,
     215,     0,     0,     0,     0,    87,    88,    89,    90,     0,
       0,    84,    85,     0,     0,   169,    76,     0,    77,    78,
      79,    80,    81,    82,     0,    75,     0,    83,     0,     0,
       0,     0,    87,    88,    89,    90,    77,    78,    79,    80,
      81,    82,    84,    85,     0,    83,    77,    78,    79,    80,
      81,    82,     0,     0,     0,    83,     0,     0,     0,     0,
      84,    85,     0,    87,    88,    89,    90,     1,     0,     0,
      84,    85,    29,    79,    80,    81,    82,     0,     0,     0,
      83,    87,    88,    89,    90,     0,     0,     0,     0,     0,
      30,    87,    88,    89,    90,    84,    85,    31,    29,     0,
       0,     0,     0,    33,    34,    35,     0,     0,     0,     0,
      36,    37,    38,    39,    40,     0,    30,    88,    89,    90,
       0,     0,     0,    31,    29,     0,     0,    41,     0,    33,
      34,    35,    42,    43,     0,     0,    36,    37,    38,    39,
      40,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      29,     0,     0,    41,     0,    33,    34,    35,    42,    43,
     120,   121,    36,    37,    38,    39,    40,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    29,     0,    32,    41,
       0,    33,    34,    35,    42,    43,   123,   124,    36,    37,
      38,    39,    40,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    29,     0,     0,    41,     0,    33,    34,    35,
      42,    43,     0,     0,    36,    37,    38,    39,    40,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    98,     0,
       0,    41,    68,    33,    34,    35,    42,    43,     0,     0,
      36,    37,    38,    39,    40,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,    42,    43,    30,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,    33,    34,    35,
       0,     0,     0,     0,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,    42,    43
};

static const yytype_int16 yycheck[] =
{
      29,   163,    31,   132,     3,    36,     8,    41,    41,    41,
       3,    41,    41,    42,     5,     5,     9,    34,    35,    12,
      51,    14,    15,    55,    17,    18,    45,    26,    62,    62,
      10,    33,    61,    34,    35,    64,    65,    66,    67,    68,
      39,    40,    16,    72,    75,    35,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    36,     4,    88,
      89,    90,     6,     7,    16,    94,    33,    58,    59,    60,
      61,    38,    51,    52,    36,     0,    64,   206,    66,    41,
     109,   110,    19,    27,    28,    29,    30,    31,    32,    37,
      34,    35,    36,    13,    73,    74,    75,    33,    64,   228,
      66,    41,   264,    34,    35,    26,    41,    51,    52,   138,
     139,    27,    28,    29,    30,    31,    32,   146,    39,    40,
      36,     6,     7,    41,   153,   154,    34,    35,    72,    73,
      74,    75,    59,    60,    61,    51,    52,    41,    37,    33,
     169,    33,    27,    28,    29,    30,    31,    32,     4,    34,
      35,    36,   165,   166,   167,   168,    72,    73,    74,    75,
      33,    33,   191,    33,    35,   194,    51,    52,    33,     5,
      33,    33,     6,     7,    20,    21,    22,    23,    24,    25,
     209,    41,    34,    41,    41,   214,    41,    72,    73,    74,
      75,    41,    27,    27,    28,    29,    30,    31,    32,    41,
      34,    35,    36,    34,    34,   234,   235,    33,    33,   238,
      33,    33,    51,    41,   243,    58,   245,    51,    52,     3,
      41,    34,   251,    11,     6,     7,    41,    27,   257,    58,
     259,   260,    56,    41,     6,     7,    34,    34,    72,    73,
      74,    75,    34,    34,   273,    27,    28,    29,    30,    31,
      32,    26,    33,    39,    36,    27,    28,    29,    30,    31,
      32,    41,    57,     4,    36,    43,    34,    43,    42,    51,
      52,    53,    54,    62,     8,    62,    35,    44,    26,    51,
      52,    53,    54,     6,     7,    39,    35,    39,    35,     9,
      72,    73,    74,    75,     6,     7,    31,   239,   253,   264,
      72,    73,    74,    75,    27,    28,    29,    30,    31,    32,
     203,   170,    74,    36,   272,    27,    28,    29,    30,    31,
      32,   277,    34,   280,    36,   228,   187,    69,    51,    52,
     283,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,     6,     7,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    64,     6,     7,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,     6,     7,    -1,    69,    -1,    -1,    72,
      73,    74,    75,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    36,    -1,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,     6,     7,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    36,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    36,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,     6,     7,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    27,    28,    29,    30,    31,    32,    -1,     6,
       7,    36,    -1,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    36,    -1,    -1,    -1,    51,    52,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    51,    52,    36,
      65,     6,     7,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    51,    52,    -1,    -1,    72,    73,
      74,    75,    27,    28,    29,    30,    31,    32,    65,     6,
       7,    36,    -1,    -1,    -1,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      27,    28,    29,    30,    31,    32,     6,     7,    -1,    36,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    51,    52,    -1,    27,    28,    29,
      30,    31,    32,    -1,    34,    -1,    36,     6,     7,    -1,
      67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    -1,
      -1,    51,    52,    -1,    -1,     6,     7,    -1,    27,    28,
      29,    30,    31,    32,    -1,     6,    -1,    36,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    27,    28,    29,    30,
      31,    32,    51,    52,    -1,    36,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      51,    52,    -1,    72,    73,    74,    75,     3,    -1,    -1,
      51,    52,     8,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      26,    72,    73,    74,    75,    51,    52,    33,     8,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    26,    73,    74,    75,
      -1,    -1,    -1,    33,     8,    -1,    -1,    63,    -1,    39,
      40,    41,    68,    69,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
       8,    -1,    -1,    63,    -1,    39,    40,    41,    68,    69,
      70,    71,    46,    47,    48,    49,    50,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,     8,    -1,    36,    63,
      -1,    39,    40,    41,    68,    69,    70,    71,    46,    47,
      48,    49,    50,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,     8,    -1,    -1,    63,    -1,    39,    40,    41,
      68,    69,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    63,    64,    39,    40,    41,    68,    69,    -1,    -1,
      46,    47,    48,    49,    50,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    68,    69,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    68,    69
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    12,    14,    15,    17,    18,    77,    78,
      79,    80,    96,    99,   101,   102,   106,   107,    45,    85,
      10,    41,     4,    16,    16,    19,     0,    79,    37,     8,
      26,    33,    36,    39,    40,    41,    46,    47,    48,    49,
      50,    63,    68,    69,    86,    87,    88,   108,   109,   111,
     112,   113,    41,    13,    41,    41,    41,    37,   108,    80,
     108,    33,    38,    33,    33,    33,    33,    33,    64,   108,
     110,   108,    33,     4,    35,     6,     7,    27,    28,    29,
      30,    31,    32,    36,    51,    52,    55,    72,    73,    74,
      75,    33,    41,   100,     5,    33,    34,    34,    34,   108,
      41,    36,    41,   108,   108,   108,   108,   108,   110,    64,
      66,    69,   108,    41,    82,    88,   108,   108,   108,   108,
      70,    71,   108,    70,    71,   108,   108,   108,   108,   108,
     108,    41,    33,   108,   108,   108,    41,    97,    27,     5,
      35,   108,    41,   103,   104,    34,    35,    34,    34,    34,
      34,    34,    34,    65,    66,   108,   108,    34,    41,    55,
      59,    60,    61,    83,    84,    33,    33,    33,    33,     6,
       3,    81,    98,   113,    34,    35,   108,   108,    41,    20,
      21,    22,    23,    24,    25,   105,    34,    35,   108,   108,
     108,    65,    67,    41,     5,    84,    89,    58,    81,    81,
      81,    81,   108,    85,    34,    34,    35,    11,    41,    27,
       8,    33,   104,    34,    35,    67,   108,   108,    58,    56,
      90,    41,    34,    34,    34,    34,    86,   113,    33,   108,
      26,    39,   108,    41,    43,    57,    92,    41,    62,     4,
      98,    34,    34,    35,    41,    62,    91,   108,   108,    42,
      93,    62,   108,    82,    34,     8,   108,    62,   108,    35,
      43,    44,    95,   108,    83,    26,    34,   108,   108,    94,
     108,    39,    89,    35,    53,    54,    35,    90,   108,    39,
      92,    53,    54,    93,    95
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 12:

/* Line 1455 of yacc.c  */
#line 95 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_SELECT;
        n->columns = strdup((yyvsp[(3) - (11)]));
        n->table = strdup((yyvsp[(5) - (11)]));
        n->distinct = ((yyvsp[(2) - (11)]) != NULL);
        if ((yyvsp[(6) - (11)])) n->join_clause = strdup((yyvsp[(6) - (11)]));
        if ((yyvsp[(7) - (11)])) n->where = strdup((yyvsp[(7) - (11)]));
        if ((yyvsp[(8) - (11)])) n->group_by = strdup((yyvsp[(8) - (11)]));
        if ((yyvsp[(9) - (11)])) n->having = strdup((yyvsp[(9) - (11)]));
        if ((yyvsp[(10) - (11)])) n->order_by = strdup((yyvsp[(10) - (11)]));
        if ((yyvsp[(11) - (11)])) n->limit = strdup((yyvsp[(11) - (11)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 113 "sql.y"
    {
        if ((yyvsp[(2) - (11)])) free((yyvsp[(2) - (11)]));
        if ((yyvsp[(3) - (11)])) free((yyvsp[(3) - (11)]));
        if ((yyvsp[(5) - (11)])) free((yyvsp[(5) - (11)]));
        if ((yyvsp[(6) - (11)])) free((yyvsp[(6) - (11)]));
        if ((yyvsp[(7) - (11)])) free((yyvsp[(7) - (11)]));
        if ((yyvsp[(8) - (11)])) free((yyvsp[(8) - (11)]));
        if ((yyvsp[(9) - (11)])) free((yyvsp[(9) - (11)]));
        if ((yyvsp[(10) - (11)])) free((yyvsp[(10) - (11)]));
        if ((yyvsp[(11) - (11)])) free((yyvsp[(11) - (11)]));
        (yyval) = strdup("(subquery)");
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 128 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 129 "sql.y"
    { 
        (yyval) = concat("%s AS %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 133 "sql.y"
    { 
        (yyval) = concat("%s %s", (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        free((yyvsp[(1) - (2)])); free((yyvsp[(2) - (2)]));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 140 "sql.y"
    {
        (yyval) = concat("%s JOIN %s %s ON %s", (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(6) - (6)]));
        free((yyvsp[(1) - (6)]));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 144 "sql.y"
    {
        (yyval) = concat("%s JOIN %s ON %s", (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
        free((yyvsp[(1) - (5)]));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 148 "sql.y"
    {
        (yyval) = concat("%s %s JOIN %s %s ON %s", (yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
        free((yyvsp[(1) - (7)])); free((yyvsp[(2) - (7)]));
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 152 "sql.y"
    {
        (yyval) = concat("%s %s JOIN %s ON %s", (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(6) - (6)]));
        free((yyvsp[(1) - (6)])); free((yyvsp[(2) - (6)]));
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 156 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 160 "sql.y"
    { (yyval) = strdup("INNER"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 161 "sql.y"
    { (yyval) = strdup("LEFT"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 162 "sql.y"
    { (yyval) = strdup("RIGHT"); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 163 "sql.y"
    { (yyval) = strdup(""); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 167 "sql.y"
    { (yyval) = strdup("DISTINCT"); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 168 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 172 "sql.y"
    { (yyval) = strdup("*"); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 173 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 177 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 178 "sql.y"
    {
        (yyval) = concat("%s, %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 185 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 186 "sql.y"
    {
        (yyval) = concat("%s AS %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)]));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 193 "sql.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 194 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 198 "sql.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 199 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 203 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 204 "sql.y"
    {
        (yyval) = concat("%s, %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 211 "sql.y"
    { (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 212 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 216 "sql.y"
    { (yyval) = (yyvsp[(3) - (3)]); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 217 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 221 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 222 "sql.y"
    { 
        (yyval) = concat("%s ASC", (yyvsp[(1) - (2)]));
        free((yyvsp[(1) - (2)]));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 226 "sql.y"
    { 
        (yyval) = concat("%s DESC", (yyvsp[(1) - (2)]));
        free((yyvsp[(1) - (2)]));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 230 "sql.y"
    {
        (yyval) = concat("%s, %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 234 "sql.y"
    {
        (yyval) = concat("%s, %s ASC", (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
        free((yyvsp[(1) - (4)])); free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 238 "sql.y"
    {
        (yyval) = concat("%s, %s DESC", (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
        free((yyvsp[(1) - (4)])); free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 245 "sql.y"
    { 
        (yyval) = concat("LIMIT %s", (yyvsp[(2) - (2)]));
        free((yyvsp[(2) - (2)]));
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 249 "sql.y"
    { 
        (yyval) = concat("LIMIT %s, %s", (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
        free((yyvsp[(2) - (4)])); free((yyvsp[(4) - (4)]));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 253 "sql.y"
    { (yyval) = NULL; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 257 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_INSERT;
        n->table = strdup((yyvsp[(3) - (10)]));
        n->columns = strdup((yyvsp[(5) - (10)]));
        n->values = strdup((yyvsp[(9) - (10)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 269 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 270 "sql.y"
    {
        (yyval) = concat("%s, %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)]));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 277 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 278 "sql.y"
    {
        (yyval) = concat("%s, %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)]));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 285 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_UPDATE;
        n->table = strdup((yyvsp[(2) - (4)]));
        n->set_items = strdup((yyvsp[(4) - (4)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 293 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_UPDATE;
        n->table = strdup((yyvsp[(2) - (6)]));
        n->set_items = strdup((yyvsp[(4) - (6)]));
        n->where = strdup((yyvsp[(6) - (6)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 305 "sql.y"
    {
        (yyval) = concat("%s = %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 309 "sql.y"
    {
        (yyval) = concat("%s, %s = %s", (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
        free((yyvsp[(1) - (5)])); free((yyvsp[(5) - (5)]));
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 316 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_DELETE;
        n->table = strdup((yyvsp[(3) - (3)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 323 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_DELETE;
        n->table = strdup((yyvsp[(3) - (5)]));
        n->where = strdup((yyvsp[(5) - (5)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 334 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_CREATE_TABLE;
        n->table = strdup((yyvsp[(3) - (6)]));
        n->col_defs = strdup((yyvsp[(5) - (6)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 345 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 346 "sql.y"
    {
        (yyval) = concat("%s, %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)]));
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 353 "sql.y"
    {
        (yyval) = concat("%s %s", (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        free((yyvsp[(1) - (2)])); free((yyvsp[(2) - (2)]));
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 357 "sql.y"
    {
        (yyval) = concat("%s %s(%s)", (yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
        free((yyvsp[(1) - (5)])); free((yyvsp[(2) - (5)])); free((yyvsp[(4) - (5)]));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 361 "sql.y"
    {
        (yyval) = concat("%s %s NOT NULL", (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
        free((yyvsp[(1) - (4)])); free((yyvsp[(2) - (4)]));
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 365 "sql.y"
    {
        (yyval) = concat("%s %s(%s) NOT NULL", (yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]));
        free((yyvsp[(1) - (7)])); free((yyvsp[(2) - (7)])); free((yyvsp[(4) - (7)]));
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 372 "sql.y"
    { (yyval) = strdup("INT"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 373 "sql.y"
    { (yyval) = strdup("VARCHAR"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 374 "sql.y"
    { (yyval) = strdup("CHAR"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 375 "sql.y"
    { (yyval) = strdup("DATE"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 376 "sql.y"
    { (yyval) = strdup("FLOAT"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 377 "sql.y"
    { (yyval) = strdup("DOUBLE"); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 381 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_DROP_TABLE;
        n->table = strdup((yyvsp[(3) - (3)]));
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 391 "sql.y"
    {
        ASTNode *n = calloc(1, sizeof(ASTNode));
        n->type = NODE_SHOW_TABLES;
        print_ast(n);
        free_ast(n);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 400 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 401 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 402 "sql.y"
    { (yyval) = strdup("YEAR"); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 403 "sql.y"
    { 
        (yyval) = concat("INTERVAL %s YEAR", (yyvsp[(2) - (3)]));
        free((yyvsp[(2) - (3)]));
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 407 "sql.y"
    {
        (yyval) = concat("%s.%s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 411 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 412 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 413 "sql.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 414 "sql.y"
    { (yyval) = strdup("(subquery)"); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 415 "sql.y"
    {
        (yyval) = concat("%s = %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 419 "sql.y"
    {
        (yyval) = concat("%s <> %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 423 "sql.y"
    {
        (yyval) = concat("%s < %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 427 "sql.y"
    {
        (yyval) = concat("%s > %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 431 "sql.y"
    {
        (yyval) = concat("%s <= %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 435 "sql.y"
    {
        (yyval) = concat("%s >= %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 439 "sql.y"
    {
        (yyval) = concat("%s LIKE %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 443 "sql.y"
    {
        (yyval) = concat("%s BETWEEN %s AND %s", (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
        free((yyvsp[(1) - (5)])); free((yyvsp[(3) - (5)])); free((yyvsp[(5) - (5)]));
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 447 "sql.y"
    {
        (yyval) = concat("%s AND %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 451 "sql.y"
    {
        (yyval) = concat("%s OR %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 455 "sql.y"
    {
        (yyval) = concat("%s IN (%s)", (yyvsp[(1) - (5)]), (yyvsp[(4) - (5)]));
        free((yyvsp[(1) - (5)])); free((yyvsp[(4) - (5)]));
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 459 "sql.y"
    {
        (yyval) = concat("%s IN (subquery)", (yyvsp[(1) - (5)]));
        free((yyvsp[(1) - (5)]));
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 463 "sql.y"
    {
        (yyval) = concat("%s < ANY (subquery)", (yyvsp[(1) - (6)]));
        free((yyvsp[(1) - (6)]));
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 467 "sql.y"
    {
        (yyval) = concat("%s > ANY (subquery)", (yyvsp[(1) - (6)]));
        free((yyvsp[(1) - (6)]));
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 471 "sql.y"
    {
        (yyval) = concat("%s < ALL (subquery)", (yyvsp[(1) - (6)]));
        free((yyvsp[(1) - (6)]));
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 475 "sql.y"
    {
        (yyval) = concat("%s > ALL (subquery)", (yyvsp[(1) - (6)]));
        free((yyvsp[(1) - (6)]));
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 479 "sql.y"
    {
        (yyval) = concat("%s + %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 483 "sql.y"
    {
        (yyval) = concat("%s - %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 487 "sql.y"
    {
        (yyval) = concat("%s * %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 491 "sql.y"
    {
        (yyval) = concat("%s / %s", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
        free((yyvsp[(1) - (3)])); free((yyvsp[(3) - (3)]));
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 495 "sql.y"
    {
        (yyval) = (yyvsp[(2) - (3)]);
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 498 "sql.y"
    {
        (yyval) = concat("NOT %s", (yyvsp[(2) - (2)]));
        free((yyvsp[(2) - (2)]));
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 505 "sql.y"
    {
        (yyval) = concat("CASE %s ELSE %s END", (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
        free((yyvsp[(2) - (5)])); free((yyvsp[(4) - (5)]));
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 509 "sql.y"
    {
        (yyval) = concat("CASE %s %s ELSE %s END", (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
        free((yyvsp[(2) - (6)])); free((yyvsp[(3) - (6)])); free((yyvsp[(5) - (6)]));
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 516 "sql.y"
    {
        (yyval) = concat("WHEN %s THEN %s", (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
        free((yyvsp[(2) - (4)])); free((yyvsp[(4) - (4)]));
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 520 "sql.y"
    {
        (yyval) = concat("%s WHEN %s THEN %s", (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
        free((yyvsp[(1) - (5)])); free((yyvsp[(3) - (5)])); free((yyvsp[(5) - (5)]));
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 527 "sql.y"
    { (yyval) = strdup("COUNT(*)"); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 528 "sql.y"
    { 
        (yyval) = concat("COUNT(%s)", (yyvsp[(3) - (4)]));
        free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 532 "sql.y"
    { 
        (yyval) = concat("SUM(%s)", (yyvsp[(3) - (4)]));
        free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 536 "sql.y"
    { 
        (yyval) = concat("AVG(%s)", (yyvsp[(3) - (4)]));
        free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 540 "sql.y"
    { 
        (yyval) = concat("MIN(%s)", (yyvsp[(3) - (4)]));
        free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 544 "sql.y"
    { 
        (yyval) = concat("MAX(%s)", (yyvsp[(3) - (4)]));
        free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 551 "sql.y"
    { 
        (yyval) = concat("%s()", (yyvsp[(1) - (3)]));
        free((yyvsp[(1) - (3)]));
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 555 "sql.y"
    { 
        (yyval) = concat("%s(%s)", (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
        free((yyvsp[(1) - (4)])); free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 559 "sql.y"
    { 
        (yyval) = concat("YEAR(%s)", (yyvsp[(3) - (4)]));
        free((yyvsp[(3) - (4)]));
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 563 "sql.y"
    { 
        (yyval) = concat("%s(%s, %s)", (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
        free((yyvsp[(1) - (6)])); free((yyvsp[(3) - (6)])); free((yyvsp[(5) - (6)]));
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 567 "sql.y"
    { 
        (yyval) = concat("%s(%s, %s, %s)", (yyvsp[(1) - (8)]), (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
        free((yyvsp[(1) - (8)])); free((yyvsp[(3) - (8)])); free((yyvsp[(5) - (8)])); free((yyvsp[(7) - (8)]));
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 571 "sql.y"
    { 
        (yyval) = concat("%s(%s, %s, %s, %s)", (yyvsp[(1) - (10)]), (yyvsp[(3) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(9) - (10)]));
        free((yyvsp[(1) - (10)])); free((yyvsp[(3) - (10)])); free((yyvsp[(5) - (10)])); free((yyvsp[(7) - (10)])); free((yyvsp[(9) - (10)]));
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 578 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 579 "sql.y"
    { (yyval) = strdup((yyvsp[(1) - (1)])); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 580 "sql.y"
    { (yyval) = strdup("NULL"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2922 "sql.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 583 "sql.y"


void yyerror(const char *s) {
    fprintf(stderr, "Line %d: Error: %s\n", yylineno, s);
    yyclearin;  // 清除当前的 lookahead token
}

void print_ast(ASTNode *node) {
    switch (node->type) {
        case NODE_SELECT:
            printf("SELECT Statement:\n");
            if (node->distinct) printf("  Distinct: YES\n");
            printf("  Columns: %s\n", node->columns);
            printf("  From: %s\n", node->table);
            if (node->join_clause) printf("  Join: %s\n", node->join_clause);
            if (node->where) printf("  Where: %s\n", node->where);
            if (node->group_by) printf("  Group By: %s\n", node->group_by);
            if (node->having) printf("  Having: %s\n", node->having);
            if (node->order_by) printf("  Order By: %s\n", node->order_by);
            if (node->limit) printf("  Limit: %s\n", node->limit);
            break;
            
        case NODE_INSERT:
            printf("INSERT Statement:\n");
            printf("  Into: %s\n", node->table);
            printf("  Columns: %s\n", node->columns);
            printf("  Values: %s\n", node->values);
            break;
            
        case NODE_UPDATE:
            printf("UPDATE Statement:\n");
            printf("  Table: %s\n", node->table);
            printf("  Set: %s\n", node->set_items);
            if (node->where) printf("  Where: %s\n", node->where);
            break;
            
        case NODE_DELETE:
            printf("DELETE Statement:\n");
            printf("  From: %s\n", node->table);
            if (node->where) printf("  Where: %s\n", node->where);
            break;
            
        case NODE_CREATE_TABLE:
            printf("CREATE TABLE:\n");
            printf("  Table: %s\n", node->table);
            printf("  Columns: %s\n", node->col_defs);
            break;
            
        case NODE_DROP_TABLE:
            printf("DROP TABLE:\n");
            printf("  Table: %s\n", node->table);
            break;
            
        case NODE_SHOW_TABLES:
            printf("SHOW TABLES\n");
            break;
    }
    printf("\n");
}

void free_ast(ASTNode *node) {
    if (!node) return;
    if (node->table) free(node->table);
    if (node->columns) free(node->columns);
    if (node->where) free(node->where);
    if (node->col_defs) free(node->col_defs);
    if (node->set_items) free(node->set_items);
    if (node->values) free(node->values);
    if (node->order_by) free(node->order_by);
    if (node->limit) free(node->limit);
    if (node->group_by) free(node->group_by);
    if (node->having) free(node->having);
    if (node->join_clause) free(node->join_clause);
    free(node);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) { perror("Cannot open file"); return 1; }
        yyin = file;
        yyparse();
        fclose(file);
    } else {
        printf("SQL Parser - Enter SQL statements (type 'exit' to quit)\n");
        char line[4096];
        while (1) {
            printf("sql> ");
            if (!fgets(line, sizeof(line), stdin)) break;
            if (strcmp(line, "exit\n") == 0) break;
            
            FILE *tmp = tmpfile();
            fputs(line, tmp);
            rewind(tmp);
            yyin = tmp;
            yyparse();
            yyrestart(yyin);  // 重置解析器状态，避免错误状态污染
            fclose(tmp);
        }
    }
    return 0;
}
