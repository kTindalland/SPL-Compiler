/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "spl.y" /* yacc.c:337  */


/* Import c standard libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *s);
int yylex(void);

/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define TYPELENGTH     10
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

enum ParseTreeNodeType { PROGRAM, BLOCK, NUMBER_CONSTANT, CONSTANT, VALUE, EXPRESSION, TERM, COMPARATOR, CONDITIONAL, OUTPUT_LIST, FOR_STATEMENT, WHILE_STATEMENT, FOR_EXPRESSIONS, DO_STATEMENT, IF_STATEMENT, ASSIGNMENT_STATEMENT, STATEMENT_LIST, TYPENODE, DECLARATION_BLOCK, WRITE_STATEMENT, READ_STATEMENT, STATEMENT, DECLARATION, IDENTIFIERS_LIST, INTEGER_NODE, REAL_NODE, IDENNODE } ;  


char *NodeNames[] = { "PROGRAM", "BLOCK", "NUMBER_CONSTANT", "CONSTANT", "VALUE", "EXPRESSION", "TERM", "COMPARATOR", "CONDITIONAL", "OUTPUT_LIST", "FOR_STATEMENT", "WHILE_STATEMENT", "FOR_EXPRESSIONS", "DO_STATEMENT", "IF_STATEMENT", "ASSIGNMENT_STATEMENT", "STATEMENT_LIST", "TYPENODE", "DECLARATION_BLOCK", "WRITE_STATEMENT", "READ_STATEMENT", "STATEMENT", "DECLARATION", "IDENTIFIERS_LIST", "INTEGER_NODE", "REAL_NODE", "IDENNODE" };
                          /* Add more types here, as more nodes
                                           added to tree */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
void PrintTree(TERNARY_TREE, int);
void CodeGen(TERNARY_TREE);
void GenerateForLoop(TERNARY_TREE for_node, TERNARY_TREE for_statements);
void SymbolTablePopulateTypes(TERNARY_TREE iden_list, int type);
void SymbolTablePopulateSingleType(TERNARY_TREE iden_list, int type);
void GetExpressionType(TERNARY_TREE, char*);

void ScanTreeForForLoops(TERNARY_TREE);
void GenForDeclarations();
void GetCurrentForByVariable(char*);

int _totalFors;
int _usedFors;

unsigned char GetIfIdenDeclared(TERNARY_TREE idennode);
void PrintIdentifierForDeclaration(TERNARY_TREE idennode);
void PrintIdentifierForDeclaration(TERNARY_TREE idennode);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
    char typeSymbol[TYPELENGTH];
    char new_identifier[IDLENGTH];
    unsigned char is_declared;
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

void GetIdentifier(int number, char* result);
void GetType(int number, char* result);

int currentSymTabSize = 0;


#line 165 "spl.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    IDEN = 258,
    COLON = 259,
    SEMICOLON = 260,
    DOT = 261,
    COMMA = 262,
    APOST = 263,
    ASSIGN = 264,
    BRA = 265,
    KET = 266,
    PLUS = 267,
    MINUS = 268,
    TIMES = 269,
    DIV = 270,
    EQUAL = 271,
    NOTEQ = 272,
    LESSTHAN = 273,
    MORETHAN = 274,
    LESSEQUAL = 275,
    MOREEQUAL = 276,
    ENDP = 277,
    CODE = 278,
    OF = 279,
    TYPE = 280,
    DECL = 281,
    IF = 282,
    THEN = 283,
    ELSE = 284,
    ENDIF = 285,
    DO = 286,
    WHILE = 287,
    ENDDO = 288,
    ENDWHILE = 289,
    FOR = 290,
    IS = 291,
    BY = 292,
    TO = 293,
    ENDFOR = 294,
    WRITE = 295,
    NEWL = 296,
    READ = 297,
    CHAR = 298,
    REAL = 299,
    INT = 300,
    NUMBER = 301,
    CHARCONST = 302,
    AND = 303,
    OR = 304,
    NOT = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 98 "spl.y" /* yacc.c:352  */

	int iVal;
	TERNARY_TREE tVal;

#line 261 "spl.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   135

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

#define YYUNDEFTOK  2
#define YYMAXUTOK   305

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   110,   110,   120,   121,   124,   125,   128,   131,   132,
     135,   136,   137,   140,   141,   144,   145,   146,   147,   148,
     149,   150,   153,   156,   157,   160,   163,   166,   169,   170,
     173,   176,   177,   179,   180,   181,   182,   185,   186,   187,
     188,   189,   190,   193,   194,   195,   198,   199,   200,   203,
     204,   205,   208,   209,   212,   213,   214,   215,   218,   228,
     231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDEN", "COLON", "SEMICOLON", "DOT",
  "COMMA", "APOST", "ASSIGN", "BRA", "KET", "PLUS", "MINUS", "TIMES",
  "DIV", "EQUAL", "NOTEQ", "LESSTHAN", "MORETHAN", "LESSEQUAL",
  "MOREEQUAL", "ENDP", "CODE", "OF", "TYPE", "DECL", "IF", "THEN", "ELSE",
  "ENDIF", "DO", "WHILE", "ENDDO", "ENDWHILE", "FOR", "IS", "BY", "TO",
  "ENDFOR", "WRITE", "NEWL", "READ", "CHAR", "REAL", "INT", "NUMBER",
  "CHARCONST", "AND", "OR", "NOT", "$accept", "program", "block",
  "identifiers_list", "declaration", "declaration_block", "type",
  "statement_list", "statement", "assignment_statement", "if_statement",
  "do_statement", "while_statement", "for_statement", "write_statement",
  "read_statement", "output_list", "conditional", "comparator",
  "expression", "term", "value", "constant", "number_constant", "integer",
  "real_number", "identifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,   -51,    27,    25,   -51,    -7,    80,    18,    15,    35,
     -12,    30,    80,    30,    18,    48,   -51,    56,   -51,   -51,
      57,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,    11,
      77,   -51,   -51,   -51,    78,   -51,   -51,    64,   -51,    12,
     -51,    18,    83,    78,   -51,    30,   -17,   112,    17,    38,
      53,    35,    18,    80,    18,    35,    35,    35,    35,   -12,
      18,    73,    80,   -51,   102,   -51,   -51,    80,    30,    30,
     -51,   -51,   -51,   -51,   -51,   -51,    35,    30,    80,    35,
      19,   -51,    99,   -51,   -51,    77,    77,   -51,   -51,   -51,
     -51,    61,    57,   -51,    23,   -51,   -51,   104,    52,    13,
      62,    35,   -51,   -51,   -51,   -51,   -51,   108,    80,   -51,
     -51,   -51,    35,   -51,   -51,    20,     1,   -51,    35,    66,
      80,     7,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    60,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    58,    53,
       3,    13,    15,    16,    17,    18,    19,    20,    21,     0,
      43,    46,    50,    52,    54,    55,    49,     0,     8,     0,
       5,     0,     0,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    51,    34,     0,     0,     0,
      37,    38,    39,    40,    41,    42,     0,     0,     0,     0,
       0,    31,     0,    14,    22,    44,    45,    47,    48,    59,
       6,     0,     4,     2,     0,    35,    36,    33,     0,     0,
       0,     0,    28,    30,    10,    12,    11,     0,     0,    23,
      25,    26,     0,    32,     7,     0,     0,    24,     0,     0,
       0,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -51,    84,   -51,   -51,    -6,    81,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    -4,   -51,    -9,
      63,   -50,   -51,   -51,    -5,   125,     3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    37,    38,    39,   107,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    80,    46,    76,    29,
      30,    31,    32,    33,    34,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    81,    47,     3,    47,    43,    48,    87,    88,    49,
      40,    67,    53,    55,    56,     1,     6,    50,    53,     7,
      54,     1,    53,    55,    56,    53,   101,     4,    53,     5,
     102,    68,    69,     1,    18,    62,    47,    41,     1,   118,
       9,    66,    40,    10,    64,     9,   122,   111,    10,    77,
     117,   113,   108,   109,    89,    82,    92,    84,    51,    47,
      47,    94,    53,    90,    95,    96,    52,    97,    47,    78,
     100,    60,    99,    98,    55,    56,    18,    19,    55,    56,
      45,    18,    19,     1,    59,   110,    68,    69,    61,    79,
       9,    57,    58,    10,    65,    55,    56,   120,    91,   112,
      68,    69,   115,   116,   104,   105,   106,    11,    93,   119,
     103,    12,    13,   114,   121,    14,    55,    56,    85,    86,
      15,    16,    17,    63,    55,    56,    18,    19,    70,    71,
      72,    73,    74,    75,    83,    44
};

static const yytype_uint8 yycheck[] =
{
       9,    51,    11,     0,    13,    10,    12,    57,    58,    13,
       7,    28,     5,    12,    13,     3,    23,    14,     5,    26,
       9,     3,     5,    12,    13,     5,     7,     0,     5,     4,
      11,    48,    49,     3,    46,    23,    45,    22,     3,    38,
      10,    45,    39,    13,    41,    10,    39,    34,    13,    32,
      30,   101,    29,    30,    59,    52,    62,    54,    10,    68,
      69,    67,     5,    60,    68,    69,    10,    76,    77,    31,
      79,     7,    78,    77,    12,    13,    46,    47,    12,    13,
      50,    46,    47,     3,     6,    33,    48,    49,    24,    36,
      10,    14,    15,    13,    11,    12,    13,    31,    25,    37,
      48,    49,   108,   112,    43,    44,    45,    27,     6,   118,
      11,    31,    32,     5,   120,    35,    12,    13,    55,    56,
      40,    41,    42,    39,    12,    13,    46,    47,    16,    17,
      18,    19,    20,    21,    53,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    77,     0,     4,    23,    26,    53,    10,
      13,    27,    31,    32,    35,    40,    41,    42,    46,    47,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    70,
      71,    72,    73,    74,    75,    76,    77,    54,    55,    56,
      77,    22,    70,    75,    76,    50,    68,    70,    58,    68,
      77,    10,    10,     5,     9,    12,    13,    14,    15,     6,
       7,    24,    23,    55,    77,    11,    68,    28,    48,    49,
      16,    17,    18,    19,    20,    21,    69,    32,    31,    36,
      67,    72,    77,    59,    77,    71,    71,    72,    72,    75,
      77,    25,    58,     6,    58,    68,    68,    70,    68,    58,
      70,     7,    11,    11,    43,    44,    45,    57,    29,    30,
      33,    34,    37,    72,     5,    58,    70,    30,    38,    70,
      31,    58,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    74,    74,    75,    76,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     4,     1,     3,     5,     1,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     7,     5,     5,    11,     4,     1,
       4,     1,     3,     3,     2,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     1,     2,     2,     1,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 110 "spl.y" /* yacc.c:1652  */
    { TERNARY_TREE ParseTree;
						ParseTree = create_node(NOTHING, PROGRAM, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal));
						#ifdef DEBUG
						PrintTree(ParseTree, 0);
						#else
						CodeGen(ParseTree);
						#endif
						}
#line 1453 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 120 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[0].tVal), NULL, NULL); }
#line 1459 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 121 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1465 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 124 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, IDENTIFIERS_LIST, (yyvsp[0].tVal), NULL, NULL); }
#line 1471 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 125 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, IDENTIFIERS_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1477 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 128 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, DECLARATION, (yyvsp[-4].tVal), (yyvsp[-1].tVal), NULL); }
#line 1483 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 131 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[0].tVal), NULL, NULL); }
#line 1489 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 132 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[-1].tVal), (yyvsp[0].tVal), NULL); }
#line 1495 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 135 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(CHAR, TYPENODE, NULL, NULL, NULL); }
#line 1501 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 136 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(INT, TYPENODE, NULL, NULL, NULL); }
#line 1507 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 137 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(REAL, TYPENODE, NULL, NULL, NULL); }
#line 1513 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 140 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[0].tVal), NULL, NULL); }
#line 1519 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 141 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1525 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 144 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(ASSIGNMENT_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1531 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 145 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(IF_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1537 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 146 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(DO_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1543 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 147 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(WHILE_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1549 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 148 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(FOR_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1555 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 149 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(WRITE_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1561 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 150 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(READ_STATEMENT, STATEMENT, (yyvsp[0].tVal), NULL, NULL); }
#line 1567 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 153 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, ASSIGNMENT_STATEMENT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1573 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 156 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL); }
#line 1579 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 157 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal)); }
#line 1585 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 160 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL); }
#line 1591 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 163 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL); }
#line 1597 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 166 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, FOR_STATEMENT,(yyvsp[-9].tVal), create_node(NOTHING, FOR_EXPRESSIONS, (yyvsp[-7].tVal), (yyvsp[-5].tVal), (yyvsp[-3].tVal) ),(yyvsp[-1].tVal) ); }
#line 1603 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 169 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, (yyvsp[-1].tVal), NULL, NULL); }
#line 1609 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 170 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, NULL, NULL, NULL); }
#line 1615 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 173 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, READ_STATEMENT, (yyvsp[-1].tVal), NULL, NULL); }
#line 1621 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 176 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[0].tVal), NULL, NULL); }
#line 1627 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 177 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1633 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 179 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[-1].tVal), (yyvsp[0].tVal)); }
#line 1639 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 180 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOT, CONDITIONAL, (yyvsp[0].tVal), NULL, NULL); }
#line 1645 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 181 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(AND, CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1651 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 182 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(OR, CONDITIONAL, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1657 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 185 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(EQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1663 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 186 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTEQ, COMPARATOR, NULL, NULL, NULL); }
#line 1669 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 187 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(LESSTHAN, COMPARATOR, NULL, NULL, NULL); }
#line 1675 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 188 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(MORETHAN, COMPARATOR, NULL, NULL, NULL); }
#line 1681 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 189 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(LESSEQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1687 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 190 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(MOREEQUAL, COMPARATOR, NULL, NULL, NULL); }
#line 1693 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 193 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[0].tVal), NULL, NULL); }
#line 1699 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 194 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(PLUS, EXPRESSION, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1705 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 195 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(MINUS, EXPRESSION, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1711 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 198 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, TERM, (yyvsp[0].tVal), NULL, NULL); }
#line 1717 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 199 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(TIMES, TERM, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1723 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 200 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(DIV, TERM, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1729 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 203 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(IDEN, VALUE, (yyvsp[0].tVal), NULL, NULL); }
#line 1735 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 204 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(CONSTANT, VALUE, (yyvsp[0].tVal), NULL, NULL); }
#line 1741 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 205 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(EXPRESSION, VALUE, (yyvsp[-1].tVal), NULL, NULL); }
#line 1747 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 208 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1753 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 209 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node((yyvsp[0].iVal), CONSTANT, NULL, NULL, NULL); }
#line 1759 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 212 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, NUMBER_CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1765 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 213 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, NUMBER_CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1771 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 214 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(MINUS, NUMBER_CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1777 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 215 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(MINUS, NUMBER_CONSTANT, (yyvsp[0].tVal), NULL, NULL); }
#line 1783 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 218 "spl.y" /* yacc.c:1652  */
    { 
			int value;
			value = (yyvsp[0].iVal);

			if (value < 0) value *= -1;

			(yyval.tVal) = create_node(value, INTEGER_NODE, NULL, NULL, NULL); 
			}
#line 1796 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 228 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node(NOTHING, REAL_NODE, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); }
#line 1802 "spl.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 231 "spl.y" /* yacc.c:1652  */
    { (yyval.tVal) = create_node((yyvsp[0].iVal), IDENNODE, NULL, NULL, NULL); }
#line 1808 "spl.tab.c" /* yacc.c:1652  */
    break;


#line 1812 "spl.tab.c" /* yacc.c:1652  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 234 "spl.y" /* yacc.c:1918  */



TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;

    if (case_identifier == DECLARATION) {
    	
    	SymbolTablePopulateTypes(t->first, t->second->item);

    }
    return (t);
}

void PrintTree(TERNARY_TREE t, int tabbingAmount)
{
	int i;
	int namesLength;
	if (t == NULL) return;

	/* Do tabbing */
	for (i = 0; i < tabbingAmount; i++) {
		printf("    ");
	}

	if (t->item != NOTHING || t->nodeIdentifier == REAL_NODE) {
		
		if (t->nodeIdentifier == INTEGER_NODE) { /* Integer Number */
			printf("Integer Item: %d", t->item);
		}
		else if (t->nodeIdentifier == REAL_NODE) { /* Real Number */
			printf("Real Number Item: %d.%d", t->first->item, t->second->item);
		}
		else if (t->nodeIdentifier == CONSTANT && t->first == NULL) { /* Character Constant */
			printf("Character Constant: %c", t->item);
		}
		else if (t->nodeIdentifier == NUMBER_CONSTANT && t->item == MINUS) {
			printf("Number Constant Item: Minus");
		}
		else if (t->nodeIdentifier == IDENNODE) { /* Identifier */
			if (t->item < 0 || t->item >= SYMTABSIZE) {
				printf("Unknown identifier item: %d", t->item);
			}
			else {
				printf("Identifier Item: %s", symTab[t->item]->identifier);
			}
			
		}
		else if (t->nodeIdentifier == STATEMENT) {
			switch (t->item) {
				case ASSIGNMENT_STATEMENT:
					printf("Statement Item: assignment_statement");
				break;
				
				case IF_STATEMENT:
					printf("Statement Item: if_statement");
				break;

				case DO_STATEMENT:
					printf("Statement Item: do_statement");
				break;

				case WHILE_STATEMENT:
					printf("Statement Item: while_statement");
				break;

				case FOR_STATEMENT:
					printf("Statement Item: for_statement");
				break;

				case WRITE_STATEMENT:
					printf("Statement Item: write_statement");
				break;

				case READ_STATEMENT:
					printf("Statement Item: read_statement");
				break;

				default:
					printf("Statement Item: default");
				break;
			}

		}
		else if (t->nodeIdentifier == TYPENODE) {
			switch (t->item) {
				case CHAR:
					printf("TypeNode Item: char");
				break;

				case INT:
					printf("TypeNode Item: int");
				break;

				case REAL:
					printf("TypeNode Item: real");
				break;
			}
		}
		else if (t->nodeIdentifier == COMPARATOR) {
			switch (t->item) {
				case EQUAL:
					printf("Comparator Item: equal");
				break;
				case NOTEQ:
					printf("Comparator Item: noteq");
				break;
				case LESSTHAN:
					printf("Comparator Item: lessthan");
				break;
				case MORETHAN:
					printf("Comparator Item: morethan");
				break;
				case LESSEQUAL:
					printf("Comparator Item: lessequal");
				break;
				case MOREEQUAL:
					printf("Comparator Item: moreequal");
				break;

			}
		}
		else {
			printf("Unknown Item: %d", t->item);
		}


	}


	namesLength = sizeof(NodeNames) / sizeof(NodeNames[0]);
	if (t->nodeIdentifier < 0 || t->nodeIdentifier >= namesLength) {
		printf(" unknown nodeIdentifier: %d\n", t->nodeIdentifier);
	}
	else {
		printf(" nodeIdentifier: %s\n", NodeNames[t->nodeIdentifier]);
	}


	PrintTree(t->first, tabbingAmount + 1);
	PrintTree(t->second, tabbingAmount + 1);
	PrintTree(t->third, tabbingAmount + 1);
}

void CodeGen(TERNARY_TREE t) {

	char typesymbol[TYPELENGTH];
	char idensymbol[IDLENGTH];
	if (t == NULL) return; /* Null node */




	switch (t->nodeIdentifier) {

		case PROGRAM:
			_totalFors = 0;
			_usedFors = 0;

			ScanTreeForForLoops(t);


			printf("#include <stdio.h>\n");
			printf("int main(int argc, char* argv[]) {\n");

			GenForDeclarations();
			
			CodeGen(t->second);

			printf("\nreturn 0; \n}\n");
			break;

		case BLOCK:
			CodeGen(t->first);
			CodeGen(t->second);
			break;

		case IDENTIFIERS_LIST:
			/* If there's not a second node, first is iden, if not, first is list */
			if (t->second == NULL) { /* Iden */
				PrintIdentifierForDeclaration(t->first);
			}
			else { /* Iden list, iden */
				PrintIdentifierForDeclaration(t->second);
				printf(",");
				CodeGen(t->first);
			}
			break;

		case DECLARATION:
			CodeGen(t->second); /* Type */
			printf(" ");

			CodeGen(t->first); /* Iden list */
			printf(";\n"); /* End the line */
			break;

		case DECLARATION_BLOCK:
			CodeGen(t->first);
			CodeGen(t->second);
			break;

		case TYPENODE:
			switch(t->item) {
				case CHAR:
					printf("char");
					break;
				case INT:
					printf("int");
					break;
				case REAL:
					printf("double");

			}
			break;

		case STATEMENT_LIST:
			CodeGen(t->first);
			CodeGen(t->second);
			break;

		case STATEMENT:
			CodeGen(t->first);
			printf("\n");
			break;

		case ASSIGNMENT_STATEMENT:

			CodeGen(t->second);
			printf(" = ");
			CodeGen(t->first);
			printf(";");
			break;

		case IF_STATEMENT:
			printf("if (");
			CodeGen(t->first);
			printf(") {\n");
			CodeGen(t->second);
			printf("}");

			if( t->third != NULL) {
				printf("else {\n");
				CodeGen(t->third);
				printf("}");
			}
			
			break;

		case DO_STATEMENT:
			printf("do {\n");
			CodeGen(t->first);
			printf("} while(");
			CodeGen(t->second);
			printf(");");

			break;

		case WHILE_STATEMENT:
			printf("while (");
			CodeGen(t->first);
			printf(") {\n");
			CodeGen(t->second);
			printf("}");
			break;

		case FOR_STATEMENT:
			GenerateForLoop(t, t->second);
			break;

		case WRITE_STATEMENT:
			if (t->first == NULL) {
				/* NEWL */
				printf("printf(\"\\n\");\n");
			}
			else {
				/* Normal Write */
				CodeGen(t->first);

			}
			break;

		case OUTPUT_LIST:
			if (t->second == NULL) { /* Single Value */
				if (t->first->item == CONSTANT) { /* If a constant */
					if (t->first->first->first == NULL) { /* Char */
						printf("printf(\"%c\");", t->first->first->item);
					}
					else {
						printf("printf(\"");
						CodeGen(t->first->first);
						printf("\");\n");
					}
				}
				else if (t->first->item == EXPRESSION) {
					/* Expression */
					char expressionString[TYPELENGTH];

					GetExpressionType(t->first->first, expressionString);

					printf("printf(\"%%%s\",", expressionString);

					CodeGen(t->first->first);
					printf(");\n");


				}
				else { /* if a iden */
					/* Get Iden */
					char identifierString[IDLENGTH];
					char identifierType[TYPELENGTH];

					TERNARY_TREE iden = t->first->first;

					GetIdentifier(iden->item, identifierString);
					GetType(iden->item, identifierType);

					printf("printf(\"");
					printf("%%%s", identifierType);
					printf("\", ");
					printf("%s", identifierString);
					printf(");\n");

				}
			}
			else { /* Still a list */
				
				CodeGen(t->first);
				if (t->second->item == CONSTANT) { /* If a constant */
					if (t->second->first->first == NULL) { /* Char */
						printf("printf(\"%c\");", t->second->first->item);
					}
					else {
						printf("printf(\"");
						CodeGen(t->second->first);
						printf("\");\n");
					}
				}
				else { /* if a iden */
					/* Get Iden */
					char identifierString[IDLENGTH];
					char identifierType[TYPELENGTH];
					TERNARY_TREE iden = t->second->first;

					GetIdentifier(iden->item, identifierString);
					GetType(iden->item, identifierType);

					printf("printf(\"");
					printf("%%%s", identifierType);
					printf("\", ");
					printf("%s", identifierString);
					printf(");\n");
				}

			}
			break;

		case READ_STATEMENT:
			printf("scanf(\"");
			GetType(t->first->item, typesymbol);
			printf(" %%%s\",", typesymbol);    /* Type */

			GetIdentifier(t->first->item, idensymbol);
			printf("&%s);",idensymbol);    /* Variable */
			break;
		
		case CONDITIONAL:
			if (t->item == NOT) {
				printf("!(");
				CodeGen(t->first);
				printf(")");
			}
			else if (t->item == AND || t->item == OR) {
				printf("(");
				CodeGen(t->first);
				printf(")");

				if (t->item == AND) { printf("&&"); }
				else { printf("||"); }

				printf("(");
				CodeGen(t->second);
				printf(")");

			}
			else { /* Normal */
				printf("(");
				CodeGen(t->first);
				printf(")");
				
				CodeGen(t->second);

				printf("(");
				CodeGen(t->third);
				printf(")");
			}

			break;

		case COMPARATOR:
			switch (t->item) {

				case EQUAL:
					printf("==");
					break;
				case NOTEQ:
					printf("!=");
					break;
				case LESSTHAN:
					printf("<");
					break;
				case MORETHAN:
					printf(">");
					break;
				case LESSEQUAL:
					printf("<=");
					break;
				case MOREEQUAL:
					printf(">=");
					break;
				

			}
			break;

		case EXPRESSION:
			if (t->second == NULL) { /* Term */
				CodeGen(t->first);
			}
			else {
				printf("(");
				CodeGen(t->first);

				if (t->item == PLUS) {
					printf(") + (");
				} else {
					printf(") - (");
				}

				CodeGen(t->second);
				printf(")");
					
			}
			break;

		case TERM:
			if (t->second == NULL) { /* Value */
				CodeGen(t->first);
			}
			else {
				printf("(");
				CodeGen(t->first);

				if (t->item == TIMES) {
					printf(") * (");
				} else {
					printf(") / (");
				}

				CodeGen(t->second);
				printf(")");
					
			}
			break;
			

		case VALUE:
			CodeGen(t->first);
			break;


		case INTEGER_NODE:
			printf("%d", t->item);
			break;

		case REAL_NODE:
			printf("%d.%d", t->first->item, t->second->item);
			break;

		case NUMBER_CONSTANT:
			if (t->item == MINUS) printf("-");
			CodeGen(t->first);
			break;

		case CONSTANT:
			if (t->first != NULL) { /* Number */
				CodeGen(t->first);
			} else { /* Char */
				printf("'%c'", t->item);
			}
			break;

		case IDENNODE: ;
			if (GetIfIdenDeclared(t) == 1) {
				GetIdentifier(t->item, idensymbol);
				printf("%s", idensymbol);
			}
			else {
				fprintf(stderr, "Variable used that hasn't been defined.");
			}
			break;


	}

}


void GetIdentifier(int number, char* result) {
	if (number < SYMTABSIZE) {
		strncpy(result, symTab[number]->new_identifier, IDLENGTH);
	}
	else {
		strncpy(result, "IdenNotFound", IDLENGTH);
	}

}

void GetType(int number, char* result) {
	if (number < SYMTABSIZE) {
		strncpy(result, symTab[number]->typeSymbol, TYPELENGTH);
	}
	else {
		strncpy(result, "NotFound", TYPELENGTH);
	}
}

void GenerateForLoop(TERNARY_TREE for_node, TERNARY_TREE for_statements) {

	char byVar[IDLENGTH];
	TERNARY_TREE ident = for_node->first;
	TERNARY_TREE statements = for_node->third;

	TERNARY_TREE is = for_statements->first;
	TERNARY_TREE by = for_statements->second;
	TERNARY_TREE to = for_statements->third;

	GetCurrentForByVariable(byVar);

	printf("for (");
	CodeGen(ident);
	printf(" = (");
	CodeGen(is);
	printf("); %s = (", byVar);
	
	CodeGen(by);
	printf("), (");
	CodeGen(ident);
	printf("-(");
	CodeGen(to);
	printf("))*((%s > 0) - (%s < 0)) <= 0;", byVar, byVar);
	CodeGen(ident);
	printf("+= %s) {\n", byVar);

	CodeGen(statements);

	printf("}");

}

void SymbolTablePopulateTypes(TERNARY_TREE iden_list, int type) {

	if (iden_list->second == NULL) { /* Single Iden */
		SymbolTablePopulateSingleType(iden_list->first, type);
	}
	else { /* Still a list */
		SymbolTablePopulateTypes(iden_list->first, type);
		SymbolTablePopulateSingleType(iden_list->second, type);
	}

}

void SymbolTablePopulateSingleType(TERNARY_TREE iden_list, int type) {

		switch(type) {
			case INT:
				strncpy(symTab[iden_list->item]->typeSymbol, "d", TYPELENGTH);
				symTab[iden_list->item]->is_declared = 1;
				break;
			case REAL:
				strncpy(symTab[iden_list->item]->typeSymbol, "lf", TYPELENGTH);
				symTab[iden_list->item]->is_declared = 1;
				break;
			case CHAR:
				strncpy(symTab[iden_list->item]->typeSymbol, "c", TYPELENGTH);
				symTab[iden_list->item]->is_declared = 1;
				break;
			default:
				fprintf(stderr, "DEBUG: Hit default case in SymbolTablePopulateSingleType. Type = %d\n", type);
				strncpy(symTab[iden_list->item]->typeSymbol, "notype", TYPELENGTH);
				break;
		}
}

void GetExpressionType(TERNARY_TREE t, char* typeString) {
	
	char left[TYPELENGTH];
	char right[TYPELENGTH];

	strncpy(left, "Default", TYPELENGTH);
	strncpy(right, "Default", TYPELENGTH);

	if (t == NULL) return;

	/* Handle Expression */
	if (t->nodeIdentifier == EXPRESSION || t->nodeIdentifier == TERM) {
	
		GetExpressionType(t->first, left);
		GetExpressionType(t->second, right);

		if (strcmp(right, "Default") == 0 || strcmp(left, right) == 0) { 
			/* Either right not set or left and right are equal.*/
			strncpy(typeString, left, TYPELENGTH);
		}
		else { /* Error */
			strncpy(typeString, "Error", TYPELENGTH);
			fprintf(stderr, "Types do not match in expression.");
		}

	}
	else if (t->nodeIdentifier == VALUE) { /* Handle Value */
		if (t->item == IDEN) { /* If identifier */
			GetType(t->first->item, typeString);
		}
		else if (t->item == CONSTANT) { /* If it's a constant */
			if (t->first->item == CONSTANT) { /* Check if it's char */
				strncpy(typeString, "c", TYPELENGTH);
			}
			else {
				if (t->first->first->first->nodeIdentifier == INTEGER_NODE) {
					strncpy(typeString, "d", TYPELENGTH);
				}
				else { 
					strncpy(typeString, "lf", TYPELENGTH);
				}
			}
		}
		else if (t->item == EXPRESSION) {
			GetExpressionType(t->first, typeString);
		}
	}

}

void ScanTreeForForLoops(TERNARY_TREE t) {
	
	if (t == NULL) return;

	if (t->nodeIdentifier == FOR_STATEMENT) _totalFors++;

	ScanTreeForForLoops(t->first);
	ScanTreeForForLoops(t->second);
	ScanTreeForForLoops(t->third);
}

void GenForDeclarations() {
	int i;

	for (i = 0; i < _totalFors; i++) {
		printf("register int _by%d;\n", i);
	}
}

void GetCurrentForByVariable(char* result) {
	
	sprintf(result, "_by%d", _usedFors);
	_usedFors++;

}

unsigned char GetIfIdenDeclared(TERNARY_TREE idennode) {

	return symTab[idennode->item]->is_declared;
}

void PrintIdentifierForDeclaration(TERNARY_TREE idennode) {
	
	/* Set in symtab */
	symTab[idennode->item]->is_declared = 1;

	printf("%s", symTab[idennode->item]->new_identifier);

}


#include "lex.yy.c"
