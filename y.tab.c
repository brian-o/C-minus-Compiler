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
#line 15 "lab9.y" /* yacc.c:339  */


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
static int maxoffset=0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf (stderr,"%s On Line: %d\n", s, lineNum);
}

/*Definition of start, tokens, and left association*/

#line 89 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    STRING = 271,
    NUM = 272,
    ID = 273,
    STRINGTEXT = 274
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
#define STRING 271
#define NUM 272
#define ID 273
#define STRINGTEXT 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "lab9.y" /* yacc.c:355  */

    int value;
    char * string;
    ASTnode * node;  /* so we can build an AST */
    enum OPERATORS op;

#line 174 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 191 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     9,     4,     2,
      30,    31,     7,     5,    32,     6,     2,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      36,    35,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     3,    34,     2,     2,     2,     2,
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
      22,    23,    24,    25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    67,    68,    75,    76,    79,   112,   143,
     144,   145,   149,   163,   148,   201,   210,   221,   222,   229,
     251,   275,   275,   301,   302,   313,   314,   325,   335,   344,
     354,   364,   373,   382,   391,   402,   414,   417,   425,   437,
     447,   448,   456,   464,   472,   475,   501,   524,   551,   552,
     577,   578,   579,   580,   581,   582,   585,   586,   611,   612,
     615,   616,   641,   642,   645,   646,   658,   659,   660,   669,
     704,   705,   708,   713
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "IF", "WHILE", "ELSE", "RETURN", "GE", "LE", "EQ", "NE",
  "READ", "WRITE", "INT", "VOID", "STRING", "NUM", "ID", "STRINGTEXT",
  "';'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "'<'",
  "'>'", "$accept", "program", "declarationList", "decl", "varDecl",
  "typeSpec", "funDecl", "$@1", "$@2", "params", "paramList", "param",
  "compoundStmt", "$@3", "localDecls", "stmtList", "stmt", "expStmt",
  "selectStmt", "iterStmt", "returnStmt", "readStmt", "writeStmt",
  "expression", "assignStmt", "var", "simpleExpression", "relop",
  "addExpression", "addOP", "term", "multOP", "factor", "call", "args",
  "argList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   124,    38,    43,    45,    42,    47,    37,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,    59,    91,    93,
      40,    41,    44,   123,   125,    61,    60,    62
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      41,   -97,   -97,   -97,     2,   -97,    41,   -97,   -14,   -97,
     -97,   -97,   -23,   -97,     5,   -97,   -13,    45,    42,    39,
      50,   -97,   -97,    47,   -97,    49,    51,    41,    52,    53,
     -97,   -97,   -97,   -97,    41,    41,    58,    -2,   -97,    -8,
      48,    54,    19,    60,    35,   -97,    46,   -97,   -97,    35,
     -97,    55,    -2,   -97,   -97,   -97,   -97,   -97,   -97,    61,
     -97,    56,    21,    27,    34,   -97,   -97,    35,    35,   -97,
      63,   -97,    59,    65,    66,    35,    35,    64,   -97,   -97,
     -97,    26,   -97,   -97,   -97,   -97,   -97,   -97,    35,   -97,
     -97,    35,   -97,   -97,    35,    67,    68,   -97,   -97,   -97,
      71,    62,    70,   -97,   -97,   -97,    27,    34,   -97,    -2,
      -2,   -97,    35,   -97,    83,   -97,   -97,    -2,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     3,     5,     0,     6,
       1,     4,     0,     7,     0,    12,     0,     0,     0,    10,
       0,    13,    16,    17,     8,    19,     0,     0,     0,     0,
      18,    20,    21,    14,    23,    23,     0,    25,    24,     0,
       0,     0,     0,     0,     0,    65,    46,    68,    36,     0,
      28,     0,    25,    27,    29,    30,    32,    33,    34,     0,
      31,    66,    44,    48,    56,    60,    67,     0,     0,    40,
       0,    66,    46,     0,     0,     0,    70,     0,    22,    26,
      35,     0,    53,    50,    54,    55,    51,    52,     0,    58,
      59,     0,    62,    63,     0,     0,     0,    41,    42,    43,
       0,    72,     0,    71,    64,    45,    49,    57,    61,     0,
       0,    47,     0,    69,    37,    39,    73,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,    91,   -97,    20,    13,   -97,   -97,   -97,   -97,
      75,   -97,    74,   -97,    69,    57,   -96,    24,   -97,   -97,
     -97,   -97,   -97,   -41,   -97,   -37,   -97,   -97,    18,   -97,
      16,   -97,    14,   -97,   -97,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    17,    26,    21,
      22,    23,    50,    34,    37,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    71,    62,    88,    63,    91,
      64,    94,    65,    66,   102,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    70,    10,    74,    13,    14,    73,    15,    77,    40,
      41,    12,    42,   114,   115,    61,    18,    43,    44,    13,
      14,   118,    45,    46,    47,    48,    95,    96,    49,    16,
      20,    32,    89,    90,   100,   101,    82,    83,    84,    85,
      20,    92,    93,    45,    46,    47,    69,    36,    36,    49,
      45,    46,    47,    48,    35,    35,    49,    86,    87,    45,
      46,    47,     1,     2,     3,    49,     1,    19,     3,    24,
     -15,   101,    61,    61,    75,    25,    76,    28,    67,    27,
      61,    31,    29,    39,    68,    72,    32,    75,    80,    78,
      97,    81,    98,    99,   112,   104,   117,    11,   109,   110,
     111,   113,    30,    33,    38,   105,   106,   107,   108,    79,
       0,   116
};

static const yytype_int8 yycheck[] =
{
      37,    42,     0,    44,    27,    28,    43,    30,    49,    11,
      12,    25,    14,   109,   110,    52,    29,    19,    20,    27,
      28,   117,    24,    25,    26,    27,    67,    68,    30,    24,
      17,    33,     5,     6,    75,    76,    15,    16,    17,    18,
      27,     7,     8,    24,    25,    26,    27,    34,    35,    30,
      24,    25,    26,    27,    34,    35,    30,    36,    37,    24,
      25,    26,    21,    22,    23,    30,    21,    22,    23,    27,
      31,   112,   109,   110,    28,    25,    30,    28,    30,    32,
     117,    29,    31,    25,    30,    25,    33,    28,    27,    34,
      27,    35,    27,    27,    32,    31,    13,     6,    31,    31,
      29,    31,    27,    29,    35,    81,    88,    91,    94,    52,
      -1,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    23,    39,    40,    41,    42,    43,    44,
       0,    40,    25,    27,    28,    30,    24,    45,    29,    22,
      43,    47,    48,    49,    27,    25,    46,    32,    28,    31,
      48,    29,    33,    50,    51,    42,    43,    52,    52,    25,
      11,    12,    14,    19,    20,    24,    25,    26,    27,    30,
      50,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    66,    68,    70,    71,    30,    30,    27,
      61,    63,    25,    63,    61,    28,    30,    61,    34,    53,
      27,    35,    15,    16,    17,    18,    36,    37,    65,     5,
       6,    67,     7,     8,    69,    61,    61,    27,    27,    27,
      61,    61,    72,    73,    31,    55,    66,    68,    70,    31,
      31,    29,    32,    31,    54,    54,    73,    13,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    43,    45,    46,    44,    47,    47,    48,    48,    49,
      49,    51,    50,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      58,    58,    59,    60,    61,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    71,
      72,    72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     1,     0,     0,     8,     1,     1,     1,     3,     2,
       4,     0,     5,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     5,     7,     5,
       2,     3,     3,     3,     1,     3,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     4,
       0,     1,     1,     3
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
#line 64 "lab9.y" /* yacc.c:1646  */
    {prog=(yyvsp[0].node);}
#line 1352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 69 "lab9.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].node)->left=(yyvsp[0].node);
                    (yyval.node)=(yyvsp[-1].node);
                }
#line 1367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "lab9.y" /* yacc.c:1646  */
    {
                    /* search symbol table for ID
                    insert if not found, then add the pointer from
                    insertion into the  ASTnode to have reference
                    to the symbol table entry */
                    if(Search((yyvsp[-1].string),level,0))
                    {
                        fprintf(stderr,"\n\tThe name %s exists at level %d ",(yyvsp[-1].string),level);
                        fprintf(stderr,"already in the symbol table\n");
                        fprintf(stderr,"\tDuplicate can.t be inserted(found in search)");
                        yyerror();
                        exit(1);
                    }

                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->name=(yyvsp[-1].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[-2].op);
                    (yyval.node)->symbol=Insert((yyvsp[-1].string),(yyvsp[-2].op),0,level,1,offset,NULL);
                    (yyval.node)->isType=(yyvsp[-2].op);
                    offset += 1;
                    if(offset > maxoffset)
                        maxoffset = offset;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making VarDec with name: %s",(yyvsp[-1].string));
                        yyerror(" ");
                    }


                }
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "lab9.y" /* yacc.c:1646  */
    {   /* search for symbol, if we find it error*/
                    if(Search((yyvsp[-4].string),level,0))
                    {
                        fprintf(stderr,"\n\tThe name %s exists at level %d ",(yyvsp[-4].string),level);
                        fprintf(stderr,"already in the symbol table\n");
                        fprintf(stderr,"\tDuplicate can.t be inserted(found in search)");
                        yyerror();
                        exit(1);
                    }

                    (yyval.node)=ASTCreateNode(VARDEC);
                    (yyval.node)->name=(yyvsp[-4].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[-5].op);
                    /* value links to the NUM nod to store the dimension*/
                    (yyval.node)->value=(yyvsp[-2].value);
                    (yyval.node)->symbol=Insert((yyvsp[-4].string),(yyvsp[-5].op),2,level,(yyvsp[-2].value),offset,NULL);
                    (yyval.node)->isType=(yyvsp[-5].op);
                    offset += (yyvsp[-2].value);
                    if (offset>maxoffset)
                        maxoffset = offset;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making VarDec[] with name: %s",(yyvsp[-4].string));
                        yyerror(" ");
                    }
                }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "lab9.y" /* yacc.c:1646  */
    { (yyval.op)=INTDEC;}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "lab9.y" /* yacc.c:1646  */
    { (yyval.op)=VOIDDEC;}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "lab9.y" /* yacc.c:1646  */
    { (yyval.op)=STRINGDEC;}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "lab9.y" /* yacc.c:1646  */
    {   /*name already used, cant make new dec*/
                    if(Search((yyvsp[-1].string),level,0))
                    {
                        yyerror((yyvsp[-1].string));
                        yyerror("Name already used ");
                        exit(1);
                    }
                    Insert((yyvsp[-1].string),(yyvsp[-2].op),1,level,1,0,NULL);
                    goffset=offset;
                    offset=2;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "lab9.y" /* yacc.c:1646  */
    {   /*need the formal params to compare later */
                    (Search((yyvsp[-3].string),0,0))->fparms = (yyvsp[0].node);
                    if (debug) Display();
                }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node)=ASTCreateNode(FUNCTIONDEC);
                    (yyval.node)->name=(yyvsp[-6].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[-7].op);
                    /* s1 links to the params which can be void
                        or a paramList */
                    (yyval.node)->s1=(yyvsp[-3].node);
                    /* right links to the compund statement,
                        called a BLOCK in the enumerated type */
                    (yyval.node)->right=(yyvsp[0].node);
                    /*get the symbtab entry we made earlier*/
                    (yyval.node)->symbol=Search((yyvsp[-6].string),0,0);
                    /*Remove symbols put in, in the function call*/
                    offset -=Delete(1);
                    level = 0;
                    (yyval.node)->value=maxoffset;
                    //we change this in the symbol table because it is not used
                    //anywhere else. We have access to this in calls, so we can
                    //use it to determine where the stack pointer is going to have to be
                    (yyval.node)->symbol->mysize = maxoffset;
                    /*change the offset back to the global offset*/
                    offset=goffset;
                    maxoffset=0;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making FunDec with name: %s",(yyvsp[-6].string));
                        yyerror(" ");
                    }
                }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "lab9.y" /* yacc.c:1646  */
    {   /* no params */
                    (yyval.node) = NULL;

                    if (debug){
                        fprintf(stderr, "Params were void ");
                        yyerror(" ");
                    }
                }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 211 "lab9.y" /* yacc.c:1646  */
    {   /* params found */
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Making non void paramList");
                        yyerror(" ");
                    }
                }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 223 "lab9.y" /* yacc.c:1646  */
    {   /* attach the param to the list */
                    (yyvsp[-2].node)->left=(yyvsp[0].node);
                    (yyval.node) = (yyvsp[-2].node);
                }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "lab9.y" /* yacc.c:1646  */
    {   /*dont want overlap between params and vars*/
                    if(Search((yyvsp[0].string),level,0))
                    {
                       yyerror((yyvsp[0].string));
                       yyerror("\tDuplicate can.t be inserted(found in search)");
                       exit(1);
                    }
                    (yyval.node) = ASTCreateNode(PARAM);
                    (yyval.node)->name=(yyvsp[0].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[-1].op);
                    /* if value is 0 it is not an array, used for printing */
                    (yyval.node)->value=0;
                    /*inherit the type*/
                    (yyval.node)->isType=(yyvsp[-1].op);
                    (yyval.node)->symbol=Insert((yyvsp[0].string),(yyvsp[-1].op),0,level+1,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                    if(debug) Display();
                }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "lab9.y" /* yacc.c:1646  */
    {
                    if(Search((yyvsp[-2].string),level,0))
                    {
                       yyerror((yyvsp[-2].string));
                       yyerror("\tDuplicate can.t be inserted(found in search)");
                       exit(1);
                    }
                    (yyval.node) = ASTCreateNode(PARAM);
                    (yyval.node)->name=(yyvsp[-2].string);
                    /* we use the op to determine its type while printing*/
                    (yyval.node)->op=(yyvsp[-3].op);
                    /* there was an array param */
                    (yyval.node)->value=1;
                    /*inherit the type*/
                    (yyval.node)->isType=(yyvsp[-3].op);
                    /*2 is used for IsAFunc to show its an array ref*/
                    (yyval.node)->symbol=Insert((yyvsp[-2].string),(yyvsp[-3].op),2,level+1,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 275 "lab9.y" /* yacc.c:1646  */
    { level++; }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 277 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node)=ASTCreateNode(BLOCK);
                    if((yyvsp[-2].node) == NULL) /*dont add decls if null*/
                        (yyval.node)->right=(yyvsp[-1].node);
                    else {
                        /* add the stmtList to the end of the localDecls
                        and then make the link to the right of BLOCK
                        be the whole decls and stmtList*/
                        ASTattachleft((yyvsp[-2].node),(yyvsp[-1].node));
                        (yyval.node)->right=(yyvsp[-2].node);
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
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 301 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 303 "lab9.y" /* yacc.c:1646  */
    {   /*check for null, if not attach it*/
                    if((yyvsp[-1].node) != NULL){
                        (yyvsp[-1].node)->left=(yyvsp[0].node);
                        (yyval.node)=(yyvsp[-1].node);
                    }
                    else
                        (yyval.node)=(yyvsp[0].node);
                }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 313 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 315 "lab9.y" /* yacc.c:1646  */
    {   /*check for null, if not attch it*/
                    if((yyvsp[-1].node) != NULL) {
                        (yyvsp[-1].node)->left=(yyvsp[0].node);
                        (yyval.node)=(yyvsp[-1].node);
                    }
                    else
                        (yyval.node)=(yyvsp[0].node);
                }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "lab9.y" /* yacc.c:1646  */
    { /*everything here is just the simplification to general stmt
                    to be put into a stmtList above */
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a expression Statement");
                        yyerror(" ");
                    }
                }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 336 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a compound Statement");
                        yyerror(" ");
                    }
                }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 345 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a selection Statement");
                        yyerror(" ");
                    }

                }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 355 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a iteration Statement");
                        yyerror(" ");
                    }

                }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 365 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a assign Statement");
                        yyerror(" ");
                    }
                }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 374 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a return Statement");
                        yyerror(" ");
                    }
                }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 383 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a read Statement");
                        yyerror(" ");
                    }
                }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 392 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);

                    if (debug){
                        fprintf(stderr, "Converting a write Statement");
                        yyerror(" ");
                    }
                }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 403 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node)=ASTCreateNode(EXPRSTMT);
                    (yyval.node)->right=(yyvsp[-1].node);
                    (yyval.node)->isType=(yyvsp[-1].node)->isType;


                    if (debug){
                        fprintf(stderr, "Finished creating an expression Statement");
                        yyerror(" ");
                    }
                }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 414 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = ASTCreateNode(IFSTMT);
                    /* right is the expression to be evaluated*/
                    (yyval.node)->right=(yyvsp[-2].node);
                    /* s1 is link to statment (it can be a block)*/
                    (yyval.node)->s1=(yyvsp[0].node);
                }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 426 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = ASTCreateNode(IFSTMT);
                    /* right is the expression to be evaluated*/
                    (yyval.node)->right=(yyvsp[-4].node);
                    /* s1 is link to statment (it can be a block)*/
                    (yyval.node)->s1=(yyvsp[-2].node);
                    /* s2 holds the link to the else statment (can be a block)*/
                    (yyval.node)->s2=(yyvsp[0].node);
                }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 438 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = ASTCreateNode(ITERSTMT);
                    /* right holds expression to be evaluated*/
                    (yyval.node)->right=(yyvsp[-2].node);
                    /* s1 holds the stmt to execute, can be block*/
                    (yyval.node)->s1=(yyvsp[0].node);
                }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 447 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(RETURNSTMT);}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 449 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = ASTCreateNode(RETURNSTMT);
                    /*expression to return*/
                    (yyval.node)->s2=(yyvsp[-1].node);
                }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 457 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = ASTCreateNode(READSTMT);
                    /*expression to read*/
                    (yyval.node)->right=(yyvsp[-1].node);
                }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 465 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node) = ASTCreateNode(WRITESTMT);
                    /*expression to write*/
                    (yyval.node)->right=(yyvsp[-1].node);
                }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 472 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 476 "lab9.y" /* yacc.c:1646  */
    {
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[-2].node)->isType != (yyvsp[0].node)->isType) || ((yyvsp[-2].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in Assignment");
                        exit(1);
                    }
                    (yyval.node)=ASTCreateNode(ASSIGN);
                    /* hold the link to the var node*/
                    (yyval.node)->right=(yyvsp[-2].node);
                    /* hold the link to the expression statement*/
                    (yyval.node)->s1=(yyvsp[0].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[-2].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 502 "lab9.y" /* yacc.c:1646  */
    {
                    struct SymbTab * p;
                    if ((p=Search((yyvsp[0].string),level,1)) != NULL)
                    {
                        (yyval.node) = ASTCreateNode(IDENT);
                        (yyval.node)->name=(yyvsp[0].string);
                        (yyval.node)->symbol=p;
                        /*give the node op Type, based on SymbTab*/
                        (yyval.node)->isType=p->Type;
                        if (p->IsAFunc == 2)
                        {
                            yyerror((yyvsp[0].string));
                            yyerror("Variable is an array, syntax error");
                        }
                    }
                    else
                    {
                        yyerror((yyvsp[0].string));
                        yyerror("undeclared variable used");
                        exit(1);
                    }
                }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 525 "lab9.y" /* yacc.c:1646  */
    {
                    struct SymbTab * p;
                    if ((p=Search((yyvsp[-3].string),level,1)) != NULL)
                    {
                        (yyval.node) = ASTCreateNode(IDENT);
                        (yyval.node)->name=(yyvsp[-3].string);
                        /* hold expression inside of array reference */
                        (yyval.node)->right=(yyvsp[-1].node);
                        (yyval.node)->symbol=p;
                        /*capital Type is enum op*/
                        (yyval.node)->isType=p->Type;
                        if (p->IsAFunc != 2)
                        {
                            yyerror((yyvsp[-3].string));
                            yyerror("Variable is not an array, syntax error");
                        }
                    }
                    else
                    {
                        yyerror((yyvsp[-3].string));
                        yyerror("undeclared variable used");
                        exit(1);
                    }
                }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 551 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 553 "lab9.y" /* yacc.c:1646  */
    {  /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[-2].node)->isType != (yyvsp[0].node)->isType) || ((yyvsp[-2].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in simpleExpression");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(EXPR);
                    (yyval.node)->op=(yyvsp[-1].op);
                    (yyval.node)->left=(yyvsp[-2].node);
                    (yyval.node)->right=(yyvsp[0].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[-2].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 577 "lab9.y" /* yacc.c:1646  */
    {(yyval.op)=LESSTHANEQUAL;}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 578 "lab9.y" /* yacc.c:1646  */
    {(yyval.op)=LESSTHAN;}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 579 "lab9.y" /* yacc.c:1646  */
    {(yyval.op)=GREATERTHAN;}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 580 "lab9.y" /* yacc.c:1646  */
    {(yyval.op)=GREATERTHANEQUAL;}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 581 "lab9.y" /* yacc.c:1646  */
    {(yyval.op)=EQUAL;}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 582 "lab9.y" /* yacc.c:1646  */
    {(yyval.op)=NOTEQUAL;}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 585 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 587 "lab9.y" /* yacc.c:1646  */
    {   /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[-2].node)->isType != (yyvsp[0].node)->isType) || ((yyvsp[-2].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in additive exp");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(EXPR);
                    (yyval.node)->op=(yyvsp[-1].op);
                    (yyval.node)->left=(yyvsp[-2].node);
                    (yyval.node)->right=(yyvsp[0].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[-2].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 611 "lab9.y" /* yacc.c:1646  */
    {(yyval.op) = PLUS;}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 612 "lab9.y" /* yacc.c:1646  */
    {(yyval.op) = MINUS;}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 615 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 617 "lab9.y" /* yacc.c:1646  */
    {  /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (((yyvsp[-2].node)->isType != (yyvsp[0].node)->isType) || ((yyvsp[-2].node)->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in term/factor exp");
                        exit(1);
                    }
                    (yyval.node) = ASTCreateNode(EXPR);
                    (yyval.node)->op=(yyvsp[-1].op);
                    (yyval.node)->left=(yyvsp[-2].node);
                    (yyval.node)->right=(yyvsp[0].node);
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    (yyval.node)->isType=(yyvsp[-2].node)->isType;
                    (yyval.node)->name=CreateTemp();
                    (yyval.node)->symbol=Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 641 "lab9.y" /* yacc.c:1646  */
    {(yyval.op) = TIMES;}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 642 "lab9.y" /* yacc.c:1646  */
    {(yyval.op) = DIVIDE;}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 645 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 647 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node)=ASTCreateNode(NUMBER);
                    (yyval.node)->value=(yyvsp[0].value);
                    /*numbers are always ints here*/
                    (yyval.node)->isType=INTDEC;

                    if (debug){
                        fprintf(stderr, "The Number is: %d",(yyvsp[0].value));
                        yyerror(" ");
                    }
                }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 658 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 659 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 661 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node)=ASTCreateNode(STRINGNODE);
                    (yyval.node)->name = CreateTemp();
                    (yyval.node)->isType=STRINGDEC;
                    (yyval.node)->str = (yyvsp[0].string);
                }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 670 "lab9.y" /* yacc.c:1646  */
    {
                    struct SymbTab * p;
                    if ((p=Search((yyvsp[-3].string),0,1)) != NULL)
                    {   /*make sure symbol is a function*/
                        if(p->IsAFunc != 1)
                        {
                            yyerror((yyvsp[-3].string));
                            yyerror("Is a variable, but was called as function");
                            exit(1);
                        }
                        /*have to make sure we are calling with right params*/
                        if (compareFormals(p->fparms,(yyvsp[-1].node)) != 1)
                        {
                            yyerror((yyvsp[-3].string));
                            yyerror("mismatch between formal and actual params");
                            exit(1);
                        }
                        (yyval.node)=ASTCreateNode(CALLSTMT);
                        /* hold the link to args in right*/
                        (yyval.node)->right=(yyvsp[-1].node);
                        (yyval.node)->name=(yyvsp[-3].string);
                        (yyval.node)->symbol=p;
                        (yyval.node)->isType=p->Type;
                    }
                    else
                    {
                        yyerror((yyvsp[-3].string));
                        yyerror("Function not defined in symbol table");
                        exit(1);
                    }
                }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 704 "lab9.y" /* yacc.c:1646  */
    { /*there were no arguments*/ (yyval.node) = NULL;}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 705 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 709 "lab9.y" /* yacc.c:1646  */
    {
                    (yyval.node)=ASTCreateNode(ARGLIST);
                    (yyval.node)->right=(yyvsp[0].node);
                }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 714 "lab9.y" /* yacc.c:1646  */
    {  /*attach the expressions to the tree in order
                    the use of the argList is handled above */
                    (yyval.node)=ASTCreateNode(ARGLIST);
                    (yyval.node)->left=(yyvsp[0].node);
                    (yyval.node)->right=(yyvsp[-2].node);
                }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2263 "y.tab.c" /* yacc.c:1646  */
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
#line 723 "lab9.y" /* yacc.c:1906  */


int main(int argc, char const *argv[]) {
    int i;
    /*cylce through the argument array, and check for -v or
    --verbose, to turn on debug*/
    for(i=0; i < argc; i++){
        char * test = strdup(argv[i]);
        char * v1 = "-v";
        char * v2 = "--verbose";
        char * v3 = "-o";
        if(strcmp(test,v1)==0 || strcmp(test,v2)==0)
            debug=1;
        if(strcmp(test,v3)==0)
        {
            char f[100];
            fprintf(stderr,"file name is %s\n",argv[++i]);
            strcpy(f,argv[i]);
            strcat(f,".asm");
            fprintf(stderr,"opening %s\n",f);
            fp = fopen(f,"w");
            if (fp==NULL)
            {
                fprintf(stderr,"Cannot open %s\n",f);
                exit(1);
            }
        }//end if -o set
    }//end loop
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
