/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 15 "lab9.y"


    /* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symtable.c"
#include "ast.c"
#include "emit.c"
#include "lex.yy.c"
static int level=0;
static int offset=0;
static int goffset=0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s On Line: %d\n", s, lineNum);
}

/*Definition of start, tokens, and left association*/

/* Line 371 of yacc.c  */
#line 90 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     UMINUS = 258,
     IF = 259,
     WHILE = 260,
     ELSE = 261,
     RETURN = 262,
     GE = 263,
     LE = 264,
     EQ = 265,
     NE = 266,
     READ = 267,
     WRITE = 268,
     INT = 269,
     VOID = 270,
     NUM = 271,
     ID = 272
   };
#endif
/* Tokens.  */
#define UMINUS 258
#define IF 259
#define WHILE 260
#define ELSE 261
#define RETURN 262
#define GE 263
#define LE 264
#define EQ 265
#define NE 266
#define READ 267
#define WRITE 268
#define INT 269
#define VOID 270
#define NUM 271
#define ID 272



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 38 "lab9.y"

    int value;
    char * string;
    ASTnode * node;  /* so we can build an AST */
    enum OPERATORS op;


/* Line 387 of yacc.c  */
#line 175 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "y.tab.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     9,     4,     2,
      28,    29,     7,     5,    30,     6,     2,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      34,    33,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     3,    32,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    25,
      27,    29,    30,    31,    40,    42,    44,    46,    50,    53,
      58,    59,    65,    66,    69,    70,    73,    75,    77,    79,
      81,    83,    85,    87,    89,    92,    94,   100,   108,   114,
     117,   121,   125,   129,   131,   135,   137,   142,   144,   148,
     150,   152,   154,   156,   158,   160,   162,   166,   168,   170,
     172,   176,   178,   180,   184,   186,   188,   190,   195,   196,
     198,   200
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    39,    -1,    39,    38,    -1,
      40,    -1,    42,    -1,    41,    24,    25,    -1,    41,    24,
      26,    23,    27,    25,    -1,    21,    -1,    22,    -1,    -1,
      -1,    41,    24,    28,    43,    45,    44,    29,    48,    -1,
      22,    -1,    46,    -1,    47,    -1,    47,    30,    46,    -1,
      41,    24,    -1,    41,    24,    26,    27,    -1,    -1,    31,
      49,    50,    51,    32,    -1,    -1,    40,    50,    -1,    -1,
      52,    51,    -1,    53,    -1,    48,    -1,    54,    -1,    55,
      -1,    60,    -1,    56,    -1,    57,    -1,    58,    -1,    59,
      25,    -1,    25,    -1,    11,    28,    59,    29,    52,    -1,
      11,    28,    59,    29,    52,    13,    52,    -1,    12,    28,
      59,    29,    52,    -1,    14,    25,    -1,    14,    59,    25,
      -1,    19,    61,    25,    -1,    20,    59,    25,    -1,    62,
      -1,    61,    33,    53,    -1,    24,    -1,    24,    26,    59,
      27,    -1,    64,    -1,    62,    63,    64,    -1,    16,    -1,
      34,    -1,    35,    -1,    15,    -1,    17,    -1,    18,    -1,
      66,    -1,    64,    65,    66,    -1,     5,    -1,     6,    -1,
      68,    -1,    66,    67,    68,    -1,     7,    -1,     8,    -1,
      28,    59,    29,    -1,    23,    -1,    61,    -1,    69,    -1,
      24,    28,    70,    29,    -1,    -1,    71,    -1,    59,    -1,
      59,    30,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    66,    67,    74,    75,    78,   109,   138,
     139,   143,   155,   142,   187,   196,   207,   208,   215,   235,
     257,   257,   283,   284,   295,   296,   307,   317,   326,   336,
     346,   355,   364,   373,   384,   395,   398,   406,   418,   428,
     429,   437,   445,   453,   456,   477,   500,   527,   528,   551,
     552,   553,   554,   555,   556,   559,   560,   583,   584,   587,
     588,   611,   612,   615,   616,   628,   629,   632,   667,   668,
     671,   676
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "IF", "WHILE", "ELSE", "RETURN", "GE", "LE", "EQ", "NE",
  "READ", "WRITE", "INT", "VOID", "NUM", "ID", "';'", "'['", "']'", "'('",
  "')'", "','", "'{'", "'}'", "'='", "'<'", "'>'", "$accept", "program",
  "declarationList", "decl", "varDecl", "typeSpec", "funDecl", "$@1",
  "$@2", "params", "paramList", "param", "compoundStmt", "$@3",
  "localDecls", "stmtList", "stmt", "expStmt", "selectStmt", "iterStmt",
  "returnStmt", "readStmt", "writeStmt", "expression", "assignStmt", "var",
  "simpleExpression", "relop", "addExpression", "addOP", "term", "multOP",
  "factor", "call", "args", "argList", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   124,    38,    43,    45,    42,    47,    37,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,    59,    91,    93,    40,    41,
      44,   123,   125,    61,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    41,
      41,    43,    44,    42,    45,    45,    46,    46,    47,    47,
      49,    48,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    54,    55,    56,
      56,    57,    58,    59,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    70,    70,
      71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     0,     0,     8,     1,     1,     1,     3,     2,     4,
       0,     5,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     2,
       3,     3,     3,     1,     3,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     3,     1,     1,     1,     4,     0,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     3,     5,     0,     6,     1,
       4,     0,     7,     0,    11,     0,     0,     0,    10,     0,
      12,    15,    16,     8,    18,     0,     0,     0,     0,    17,
      19,    20,    13,    22,    22,     0,    24,    23,     0,     0,
       0,     0,     0,     0,    64,    45,    35,     0,    27,     0,
      24,    26,    28,    29,    31,    32,    33,     0,    30,    65,
      43,    47,    55,    59,    66,     0,     0,    39,     0,    65,
      45,     0,     0,     0,    68,     0,    21,    25,    34,     0,
      52,    49,    53,    54,    50,    51,     0,    57,    58,     0,
      61,    62,     0,     0,     0,    40,    41,    42,     0,    70,
       0,    69,    63,    44,    48,    56,    60,     0,     0,    46,
       0,    67,    36,    38,    71,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    16,    25,    20,
      21,    22,    48,    33,    36,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    69,    60,    86,    61,    89,
      62,    92,    63,    64,   100,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int8 yypact[] =
{
     -13,  -104,  -104,     2,  -104,   -13,  -104,    -3,  -104,  -104,
    -104,    31,  -104,     5,  -104,    35,    10,    26,    29,    43,
    -104,  -104,    38,  -104,    47,    40,   -13,    48,    45,  -104,
    -104,  -104,  -104,   -13,   -13,    50,    -1,  -104,    18,    49,
      52,    -8,    54,    25,  -104,    24,  -104,    25,  -104,    51,
      -1,  -104,  -104,  -104,  -104,  -104,  -104,    57,  -104,    53,
      20,    55,    56,  -104,  -104,    25,    25,  -104,    59,  -104,
      61,    60,    63,    25,    25,    62,  -104,  -104,  -104,    17,
    -104,  -104,  -104,  -104,  -104,  -104,    25,  -104,  -104,    25,
    -104,  -104,    25,    64,    65,  -104,  -104,  -104,    68,    66,
      69,  -104,  -104,  -104,    55,    56,  -104,    -1,    -1,  -104,
      25,  -104,    76,  -104,  -104,    -1,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,    85,  -104,    32,    13,  -104,  -104,  -104,  -104,
      71,  -104,    72,  -104,    58,    67,  -103,    22,  -104,  -104,
    -104,  -104,  -104,   -40,  -104,   -36,  -104,  -104,    -5,  -104,
      14,  -104,     7,  -104,  -104,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      59,    68,     9,    72,   112,   113,    71,    75,     1,     2,
      39,    40,   116,    41,    59,    44,    45,    67,    42,    43,
      47,    11,    44,    45,    46,    93,    94,    47,    15,    19,
      31,     1,    18,    98,    99,    80,    81,    82,    83,    19,
      44,    45,    46,    12,    13,    47,    35,    35,    44,    45,
      73,    23,    74,    47,    84,    85,    12,    13,   -14,    14,
      87,    88,    17,    90,    91,    34,    34,    24,    26,    28,
      99,    59,    59,    27,    38,    30,    31,    65,    70,    59,
      66,   104,    78,    76,    95,    96,    79,    73,    97,   115,
      10,   102,    37,   107,   108,   109,   110,    29,   111,   106,
      32,   103,     0,   105,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      36,    41,     0,    43,   107,   108,    42,    47,    21,    22,
      11,    12,   115,    14,    50,    23,    24,    25,    19,    20,
      28,    24,    23,    24,    25,    65,    66,    28,    23,    16,
      31,    21,    22,    73,    74,    15,    16,    17,    18,    26,
      23,    24,    25,    25,    26,    28,    33,    34,    23,    24,
      26,    25,    28,    28,    34,    35,    25,    26,    29,    28,
       5,     6,    27,     7,     8,    33,    34,    24,    30,    29,
     110,   107,   108,    26,    24,    27,    31,    28,    24,   115,
      28,    86,    25,    32,    25,    25,    33,    26,    25,    13,
       5,    29,    34,    29,    29,    27,    30,    26,    29,    92,
      28,    79,    -1,    89,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    37,    38,    39,    40,    41,    42,     0,
      38,    24,    25,    26,    28,    23,    43,    27,    22,    41,
      45,    46,    47,    25,    24,    44,    30,    26,    29,    46,
      27,    31,    48,    49,    40,    41,    50,    50,    24,    11,
      12,    14,    19,    20,    23,    24,    25,    28,    48,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    64,    66,    68,    69,    28,    28,    25,    59,    61,
      24,    61,    59,    26,    28,    59,    32,    51,    25,    33,
      15,    16,    17,    18,    34,    35,    63,     5,     6,    65,
       7,     8,    67,    59,    59,    25,    25,    25,    59,    59,
      70,    71,    29,    53,    64,    66,    68,    29,    29,    27,
      30,    29,    52,    52,    71,    13,    52
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
        case 2:
/* Line 1792 of yacc.c  */
#line 63 "lab9.y"
    {prog=(yyvsp[(1) - (1)].node);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 66 "lab9.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 68 "lab9.y"
    {
                    (yyvsp[(1) - (2)].node)->left=(yyvsp[(2) - (2)].node);
                    (yyval.node)=(yyvsp[(1) - (2)].node);
                }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 74 "lab9.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 75 "lab9.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 79 "lab9.y"
    {
                    /* search symbol table for ID
                    insert if not found, then add the pointer from
                    insertion into the  ASTnode to have reference
                    to the symbol table entry */
                    if(Search((yyvsp[(2) - (3)].string),level,0))
                    {
                        printf("\n\tThe name %s exists at level %d ",(yyvsp[(2) - (3)].string),level);
                        printf("already in the symbol table\n");
                        printf("\tDuplicate can.t be inserted(found in search)");
                        yyerror();
                        exit(1);
                    }

                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->name=(yyvsp[(2) - (3)].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[(1) - (3)].op);
                    (yyval.node)->symbol=Insert((yyvsp[(2) - (3)].string),(yyvsp[(1) - (3)].op),0,level,1,offset,NULL);
                    (yyval.node)->isType=(yyvsp[(1) - (3)].op);
                    offset += 1;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making VarDec with name: %s",(yyvsp[(2) - (3)].string));
                        yyerror(" ");
                    }


                }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 110 "lab9.y"
    {   /* search for symbol, if we find it error*/
                    if(Search((yyvsp[(2) - (6)].string),level,0))
                    {
                        printf("\n\tThe name %s exists at level %d ",(yyvsp[(2) - (6)].string),level);
                        printf("already in the symbol table\n");
                        printf("\tDuplicate can.t be inserted(found in search)");
                        yyerror();
                        exit(1);
                    }

                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->name=(yyvsp[(2) - (6)].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[(1) - (6)].op);
                    /* value links to the NUM nod to store the dimension*/
                    (yyval.node)->value=(yyvsp[(4) - (6)].value);
                    (yyval.node)->symbol=Insert((yyvsp[(2) - (6)].string),(yyvsp[(1) - (6)].op),2,level,(yyvsp[(4) - (6)].value),offset,NULL);
                    (yyval.node)->isType=(yyvsp[(1) - (6)].op);
                    offset += (yyvsp[(4) - (6)].value);

                    if (debug){
                        Display();
                        fprintf(stderr, "Making VarDec[] with name: %s",(yyvsp[(2) - (6)].string));
                        yyerror(" ");
                    }
                }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 138 "lab9.y"
    { (yyval.op)=INTDEC;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 139 "lab9.y"
    { (yyval.op)=VOIDDEC;}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 143 "lab9.y"
    {   /*name already used, cant make new dec*/
                    if(Search((yyvsp[(2) - (3)].string),level,0))
                    {
                        yyerror((yyvsp[(2) - (3)].string));
                        yyerror("Name already used ");
                        exit(1);
                    }
                    Insert((yyvsp[(2) - (3)].string),(yyvsp[(1) - (3)].op),1,level,1,0,NULL);
                    goffset=offset;
                    offset=0;
                }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 155 "lab9.y"
    {   /*need the formal params to compare later */
                    (Search((yyvsp[(2) - (5)].string),0,0))->fparms = (yyvsp[(5) - (5)].node);
                    if (debug) Display();
                }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 160 "lab9.y"
    {
                    (yyval.node)=ASTCreateNode(FUNCTIONDEC);
                    (yyval.node)->name=(yyvsp[(2) - (8)].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[(1) - (8)].op);
                    /* s1 links to the params which can be void
                        or a paramList */
                    (yyval.node)->s1=(yyvsp[(5) - (8)].node);
                    /* right links to the compund statement,
                        called a BLOCK in the enumerated type */
                    (yyval.node)->right=(yyvsp[(8) - (8)].node);
                    /*get the symbtab entry we made earlier*/
                    (yyval.node)->symbol=Search((yyvsp[(2) - (8)].string),0,0);
                    /*Remove symbols put in, in the function call*/
                    offset -=Delete(1);
                    level = 0;
                    /*change the offset back to the global offset*/
                    offset=goffset;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making FunDec with name: %s",(yyvsp[(2) - (8)].string));
                        yyerror(" ");
                    }
                }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 188 "lab9.y"
    {   /* no params */
                    (yyval.node) = NULL;

                    if (debug){
                        fprintf(stderr, "Params were void ");
                        yyerror(" ");
                    }
                }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 197 "lab9.y"
    {   /* params found */
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Making non void paramList");
                        yyerror(" ");
                    }
                }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 207 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 209 "lab9.y"
    {   /* attach the param to the list */
                    (yyvsp[(1) - (3)].node)->left=(yyvsp[(3) - (3)].node);
                    (yyval.node) = (yyvsp[(1) - (3)].node);
                }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 216 "lab9.y"
    {   /*dont want overlap between params and vars*/
                    if(Search((yyvsp[(2) - (2)].string),level,0))
                    {
                       yyerror((yyvsp[(2) - (2)].string));
                       yyerror("\tDuplicate can.t be inserted(found in search)");
                       exit(1);
                    }
                    (yyval.node) = ASTCreateNode(PARAM);
                    (yyval.node)->name=(yyvsp[(2) - (2)].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[(1) - (2)].op);
                    /* if value is 0 it is not an array, used for printing */
                    (yyval.node)->value=0;
                    /*inherit the type*/
                    (yyval.node)->isType=(yyvsp[(1) - (2)].op);
                    (yyval.node)->symbol=Insert((yyvsp[(2) - (2)].string),(yyvsp[(1) - (2)].op),0,level+1,1,offset,NULL);
                    offset+=1;
                    if(debug) Display();
                }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 236 "lab9.y"
    {
                    if(Search((yyvsp[(2) - (4)].string),level,0))
                    {
                       yyerror((yyvsp[(2) - (4)].string));
                       yyerror("\tDuplicate can.t be inserted(found in search)");
                       exit(1);
                    }
                    (yyval.node) = ASTCreateNode(PARAM);
                    (yyval.node)->name=(yyvsp[(2) - (4)].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[(1) - (4)].op);
                    /* there was an array param */
                    (yyval.node)->value=1;
                    /*inherit the type*/
                    (yyval.node)->isType=(yyvsp[(1) - (4)].op);
                    /*2 is used for IsAFunc to show its an array ref*/
                    (yyval.node)->symbol=Insert((yyvsp[(2) - (4)].string),(yyvsp[(1) - (4)].op),2,level+1,1,offset,NULL);
                    offset+=1;
                }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 257 "lab9.y"
    { level++; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 259 "lab9.y"
    {
                    (yyval.node)=ASTCreateNode(BLOCK);
                    if((yyvsp[(3) - (5)].node) == NULL) /*dont add decls if null*/
                        (yyval.node)->right=(yyvsp[(4) - (5)].node);
                    else {
                        /* add the stmtList to the end of the localDecls
                        and then make the link to the right of BLOCK
                        be the whole decls and stmtList*/
                        ASTattachleft((yyvsp[(3) - (5)].node),(yyvsp[(4) - (5)].node));
                        (yyval.node)->right=(yyvsp[(3) - (5)].node);
                   }
                   fprintf(stderr,"\ntable before deleting");
                   Display();/*Display before*/
                   /*delete the old symbols from this block so they can
                   be used in a different block later on*/
                   offset -=Delete(level);
                   level--;
                   fprintf(stderr,"\nEnd of compoundStmt, deleting symbols");
                   fprintf(stderr,"     current table...");
                   Display();/*Display after*/

                }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 283 "lab9.y"
    {(yyval.node) = NULL;}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 285 "lab9.y"
    {   /*check for null, if not attach it*/
                    if((yyvsp[(1) - (2)].node) != NULL){
                        (yyvsp[(1) - (2)].node)->left=(yyvsp[(2) - (2)].node);
                        (yyval.node)=(yyvsp[(1) - (2)].node);
                    }
                    else
                        (yyval.node)=(yyvsp[(2) - (2)].node);
                }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 295 "lab9.y"
    {(yyval.node) = NULL;}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 297 "lab9.y"
    {   /*check for null, if not attch it*/
                    if((yyvsp[(1) - (2)].node) != NULL) {
                        (yyvsp[(1) - (2)].node)->left=(yyvsp[(2) - (2)].node);
                        (yyval.node)=(yyvsp[(1) - (2)].node);
                    }
                    else
                        (yyval.node)=(yyvsp[(2) - (2)].node);
                }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 308 "lab9.y"
    { /*everything here is just the simplification to general stmt
                    to be put into a stmtList above */
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a expression Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 318 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a compound Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 327 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a selection Statement");
                        yyerror(" ");
                    }

                }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 337 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a iteration Statement");
                        yyerror(" ");
                    }

                }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 347 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a assign Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 356 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a return Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 365 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a read Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 374 "lab9.y"
    {
                    (yyval.node) = (yyvsp[(1) - (1)].node);

                    if (debug){
                        fprintf(stderr, "Converting a write Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 385 "lab9.y"
    {
                    (yyval.node)=ASTCreateNode(EXPRSTMT);
                    (yyval.node)->right=(yyvsp[(1) - (2)].node);
                    (yyval.node)->isType=(yyvsp[(1) - (2)].node)->isType;

                    if (debug){
                        fprintf(stderr, "Finished creating an expression Statement");
                        yyerror(" ");
                    }
                }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 395 "lab9.y"
    {(yyval.node) = NULL;}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 399 "lab9.y"
    {
                    (yyval.node) = ASTCreateNode(IFSTMT);
                    /* right is the expression to be evaluated*/
                    (yyval.node)->right=(yyvsp[(3) - (5)].node);
                    /* s1 is link to statment (it can be a block)*/
                    (yyval.node)->s1=(yyvsp[(5) - (5)].node);
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 407 "lab9.y"
    {
                    (yyval.node) = ASTCreateNode(IFSTMT);
                    /* right is the expression to be evaluated*/
                    (yyval.node)->right=(yyvsp[(3) - (7)].node);
                    /* s1 is link to statment (it can be a block)*/
                    (yyval.node)->s1=(yyvsp[(5) - (7)].node);
                    /* s2 holds the link to the else statment (can be a block)*/
                    (yyval.node)->s2=(yyvsp[(7) - (7)].node);
                }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 419 "lab9.y"
    {
                    (yyval.node) = ASTCreateNode(ITERSTMT);
                    /* right holds expression to be evaluated*/
                    (yyval.node)->right=(yyvsp[(3) - (5)].node);
                    /* s1 holds the stmt to execute, can be block*/
                    (yyval.node)->s1=(yyvsp[(5) - (5)].node);
                }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 428 "lab9.y"
    {(yyval.node) = ASTCreateNode(RETURNSTMT);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 430 "lab9.y"
    {
                    (yyval.node) = ASTCreateNode(RETURNSTMT);
                    /*expression to return*/
                    (yyval.node)->right=(yyvsp[(2) - (3)].node);
                }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 438 "lab9.y"
    {
                    (yyval.node) = ASTCreateNode(READSTMT);
                    /*expression to read*/
                    (yyval.node)->right=(yyvsp[(2) - (3)].node);
                }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 446 "lab9.y"
    {
                    (yyval.node) = ASTCreateNode(WRITESTMT);
                    /*expression to write*/
                    (yyval.node)->right=(yyvsp[(2) - (3)].node);
                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 453 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 457 "lab9.y"
    {
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[(1) - (3)].node)->isType != (yyvsp[(3) - (3)].node)->isType) || ((yyvsp[(1) - (3)].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in Assignment");
                        exit(1);
                    }
                    (yyval.node)=ASTCreateNode(ASSIGN);
                    /* hold the link to the var node*/
                    (yyval.node)->right=(yyvsp[(1) - (3)].node);
                    /* hold the link to the expression statement*/
                    (yyval.node)->s1=(yyvsp[(3) - (3)].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[(1) - (3)].node)->isType;
                }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 478 "lab9.y"
    {
                    struct SymbTab * p;
                    if ((p=Search((yyvsp[(1) - (1)].string),level,1)) != NULL)
                    {
                        (yyval.node) = ASTCreateNode(IDENT);
                        (yyval.node)->name=(yyvsp[(1) - (1)].string);
                        (yyval.node)->symbol=p;
                        /*give the node op Type, based on SymbTab*/
                        (yyval.node)->isType=p->Type;
                        if (p->IsAFunc == 2)
                        {
                            yyerror((yyvsp[(1) - (1)].string));
                            yyerror("Variable is an array, syntax error");
                        }
                    }
                    else
                    {
                        yyerror((yyvsp[(1) - (1)].string));
                        yyerror("undeclared variable used");
                        exit(1);
                    }
                }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 501 "lab9.y"
    {
                    struct SymbTab * p;
                    if ((p=Search((yyvsp[(1) - (4)].string),level,1)) != NULL)
                    {
                        (yyval.node) = ASTCreateNode(IDENT);
                        (yyval.node)->name=(yyvsp[(1) - (4)].string);
                        /* hold expression inside of array reference */
                        (yyval.node)->right=(yyvsp[(3) - (4)].node);
                        (yyval.node)->symbol=p;
                        /*capital Type is enum op*/
                        (yyval.node)->isType=p->Type;
                        if (p->IsAFunc != 2)
                        {
                            yyerror((yyvsp[(1) - (4)].string));
                            yyerror("Variable is not an array, syntax error");
                        }
                    }
                    else
                    {
                        yyerror((yyvsp[(1) - (4)].string));
                        yyerror("undeclared variable used");
                        exit(1);
                    }
                }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 527 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 529 "lab9.y"
    {  /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[(1) - (3)].node)->isType != (yyvsp[(3) - (3)].node)->isType) || ((yyvsp[(1) - (3)].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in simpleExpression");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(EXPR);
                    (yyval.node)->op=(yyvsp[(2) - (3)].op);
                    (yyval.node)->left=(yyvsp[(1) - (3)].node);
                    (yyval.node)->right=(yyvsp[(3) - (3)].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[(1) - (3)].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 551 "lab9.y"
    {(yyval.op)=LESSTHANEQUAL;}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 552 "lab9.y"
    {(yyval.op)=LESSTHAN;}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 553 "lab9.y"
    {(yyval.op)=GREATERTHAN;}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 554 "lab9.y"
    {(yyval.op)=GREATERTHANEQUAL;}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 555 "lab9.y"
    {(yyval.op)=EQUAL;}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 556 "lab9.y"
    {(yyval.op)=NOTEQUAL;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 559 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 561 "lab9.y"
    {   /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[(1) - (3)].node)->isType != (yyvsp[(3) - (3)].node)->isType) || ((yyvsp[(1) - (3)].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in additive exp");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(EXPR);
                    (yyval.node)->op=(yyvsp[(2) - (3)].op);
                    (yyval.node)->left=(yyvsp[(1) - (3)].node);
                    (yyval.node)->right=(yyvsp[(3) - (3)].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[(1) - (3)].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 583 "lab9.y"
    {(yyval.op) = PLUS;}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 584 "lab9.y"
    {(yyval.op) = MINUS;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 587 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 589 "lab9.y"
    {  /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[(1) - (3)].node)->isType != (yyvsp[(3) - (3)].node)->isType) || ((yyvsp[(1) - (3)].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in term/factor exp");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(EXPR);
                    (yyval.node)->op=(yyvsp[(2) - (3)].op);
                    (yyval.node)->left=(yyvsp[(1) - (3)].node);
                    (yyval.node)->right=(yyvsp[(3) - (3)].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[(1) - (3)].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 611 "lab9.y"
    {(yyval.op) = TIMES;}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 612 "lab9.y"
    {(yyval.op) = DIVIDE;}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 615 "lab9.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 617 "lab9.y"
    {
                    (yyval.node)=ASTCreateNode(NUMBER);
                    (yyval.node)->value=(yyvsp[(1) - (1)].value);
                    /*numbers are always ints here*/
                    (yyval.node)->isType=INTDEC;

                    if (debug){
                        fprintf(stderr, "The Number is: %d",(yyvsp[(1) - (1)].value));
                        yyerror(" ");
                    }
                }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 628 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 629 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 633 "lab9.y"
    {
                    struct SymbTab * p;
                    if ((p=Search((yyvsp[(1) - (4)].string),0,1)) != NULL)
                    {   /*make sure symbol is a function*/
                        if(p->IsAFunc != 1)
                        {
                            yyerror((yyvsp[(1) - (4)].string));
                            yyerror("Is a variable, but was called as function");
                            exit(1);
                        }
                        /*have to make sure we are calling with right params*/
                        if (compareFormals(p->fparms,(yyvsp[(3) - (4)].node)) != 1)
                        {
                            yyerror((yyvsp[(1) - (4)].string));
                            yyerror("mismatch between formal and actual params");
                            exit(1);
                        }
                        (yyval.node)=ASTCreateNode(CALLSTMT);
                        /* hold the link to args in right*/
                        (yyval.node)->right=(yyvsp[(3) - (4)].node);
                        (yyval.node)->name=(yyvsp[(1) - (4)].string);
                        (yyval.node)->symbol=p;
                        (yyval.node)->isType=p->Type;
                    }
                    else
                    {
                        yyerror((yyvsp[(1) - (4)].string));
                        yyerror("Function not defined in symbol table");
                        exit(1);
                    }
                }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 667 "lab9.y"
    { /*there were no arguments*/ (yyval.node) = NULL;}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 668 "lab9.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 672 "lab9.y"
    {
                    (yyval.node)=ASTCreateNode(ARGLIST);
                    (yyval.node)->right=(yyvsp[(1) - (1)].node);
                }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 677 "lab9.y"
    {  /*attach the expressions to the tree in order
                    the use of the argList is handled above */
                    (yyval.node)=ASTCreateNode(ARGLIST);
                    (yyval.node)->left=(yyvsp[(3) - (3)].node);
                    (yyval.node)->right=(yyvsp[(1) - (3)].node);
                }
    break;


/* Line 1792 of yacc.c  */
#line 2368 "y.tab.c"
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


/* Line 2055 of yacc.c  */
#line 686 "lab9.y"


int main(int argc, char const *argv[]) {
    int i;
    /*cylce through the argument array, and check for -v or
    --verbose, to turn on debug*/
    for(i=0; i < argc; i++){
        char * test = strdup(argv[i]);
        char * v1 = "-v";
        char * v2 = "--verbose";
        if(strcmp(test,v1)==0 || strcmp(test,v2)==0)
            debug=1;
    }
    yyparse();
    /*fprintf(stderr,"\nMain symbol table");
    Display();
    fprintf(stderr,"the input has been syntactically checked\n");
    fprintf(stderr, "starting print\n*\n*\n*\n*\n*\n");
    */
    //ASTprint(0,prog);  /* this is where we can do things with the AST like
                        //print it or process it */;
    printf("\n\n");
    emitAST(prog);
    return(0);
}
