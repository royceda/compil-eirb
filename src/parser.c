/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table.h"

/* 
 * %eba sert aux calculs : résultat courant 
 * %ebx sert aux calculs : on y charge les valeurs à utiliser pour eax
 * %ecx sert aux calculs d'adresses
 * %edx sert à rien pour le moment...
 */

  int n;
  char* s;
  extern char yytext[];
  extern int column, yylineno;
  extern FILE *yyin;  
  char *file_name = NULL;
  struct table *T;
  struct type * type;
  enum _type retour;
  FILE *output = NULL;

  int yylex ();
  int yyerror ();
  void *malloc(size_t size);

  void printint(int a){
    printf("%d",a);
  }

  void printfloat(float f){
    printf("%f",f);
  }

void swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(str+start, str+end);
        start++;
        end--;
    }
}
char * itoa(int input, char *str, int base) {
    int i = 0;
    int isNegative = 0;
 
    if (input == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (input < 0 && base == 10) {
        isNegative = 1;
        input = -input;
    }
 
    while (input != 0) {
        int rem = input % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        input = input/base;
    }
 
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0';
    reverse(str, i);
 
    return str;   
}

char * concat(char * pre, const char * add) {
    if(!pre) {
	perror("pre == NULL");
	 pre = malloc(sizeof(char));
          *(pre)='\0';
	  char* add2 = malloc(strlen(add)+1);
	  strcpy(add2,add);
	  return add2;
 //	exit(EXIT_FAILURE);
    } else if(!add) {
	perror("add == NULL");
	return pre;
	//	exit(EXIT_FAILURE);
    }
    else{
      //printf("pre: \n%s\nadd: \n%s\n\n",pre?pre:"<NULL>",add?add:"<NULL>");
      char * tmp = malloc(sizeof(char) * (strlen(pre) + strlen(add) + 1));
      strcpy(tmp, pre);
      strcat(tmp, add);
      //free(pre);
      pre = tmp;
      return pre;
    }
}

char * nextLabel() {
  static int next = 1;
  char * buff = malloc(11*sizeof(char));
  itoa(next, buff, 16);
  next ++;
  return buff;
}

#line 184 "parser.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    ICONSTANT = 259,
    FCONSTANT = 260,
    INC_OP = 261,
    DEC_OP = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    INT = 267,
    FLOAT = 268,
    VOID = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    RETURN = 273,
    FOR = 274,
    DO = 275
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define ICONSTANT 259
#define FCONSTANT 260
#define INC_OP 261
#define DEC_OP 262
#define LE_OP 263
#define GE_OP 264
#define EQ_OP 265
#define NE_OP 266
#define INT 267
#define FLOAT 268
#define VOID 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define RETURN 273
#define FOR 274
#define DO 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 151 "parser.y" /* yacc.c:355  */

  struct data{
    int val;
    float valf;
    char *str;
    char *code;
    char *code_out;
    int next_adr;
    struct type{
      enum _type {_INT,_FLOAT,_VOID} t; //0:int,1:float,2:void
      int dimension;//0:primitif,>0: tableau
      struct type * retour;//null sauf pour les fonctions
      int nb_parametres;
      struct type * parametres;//null sauf pour les fonctions
      char * adresse;
    }*type;
    struct symbole{
      char * str;
      char * offset;
      struct type *t;
      struct symbole *suivant;
    }*sym;
  }data;

#line 289 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 304 "parser.c" /* yacc.c:358  */

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
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,     2,     2,     2,
      21,    22,    28,    29,    25,    26,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      30,    32,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   180,   180,   203,   221,   235,   246,   276,   308,   333,
     360,   398,   404,   416,   420,   439,   459,   464,   501,   504,
     541,   581,   584,   629,   674,   718,   763,   808,   856,   890,
     939,   945,   963,   971,   983,   991,   999,  1010,  1021,  1032,
    1043,  1054,  1068,  1077,  1089,  1100,  1103,  1106,  1109,  1112,
    1118,  1122,  1122,  1126,  1126,  1136,  1139,  1145,  1148,  1154,
    1158,  1164,  1179,  1201,  1227,  1253,  1280,  1307,  1317,  1328,
    1336,  1343,  1365,  1384,  1384
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "ICONSTANT", "FCONSTANT",
  "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "INT", "FLOAT",
  "VOID", "IF", "ELSE", "WHILE", "RETURN", "FOR", "DO", "'('", "')'",
  "'['", "']'", "','", "'-'", "'!'", "'*'", "'+'", "'<'", "'>'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "argument_expression_list", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "comparison_expression", "expression", "declaration", "declarator_list",
  "type_name", "declarator", "parameter_list", "parameter_declaration",
  "statement", "compound_statement", "$@1", "$@2", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "program",
  "external_declaration", "function_definition", "$@3", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    40,    41,    91,    93,    44,    45,    33,    42,    43,
      60,    62,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      61,   -68,   -68,   -68,   -68,     7,   108,   -68,   -68,    -1,
      10,    -9,     0,   -68,   -68,    45,   -68,     7,   -68,     5,
       9,    32,    37,   -68,     7,   -10,   -68,   161,   -68,   -68,
      37,   -68,    61,   -68,   112,    61,   -68,    34,   -68,   -68,
      42,    46,   131,    48,   112,   150,   165,   165,   -68,   -68,
     -68,    51,   179,   -68,    50,   -68,   -68,    27,   -68,   -68,
     -68,   -68,   -68,     7,    92,   -68,   -68,   158,   150,   165,
     150,   150,   -68,    56,   139,    86,   101,   176,   -68,   -68,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   -68,
     -68,   -68,    37,   -68,    67,   -68,    11,   -68,    90,   -68,
     102,   106,   -68,   139,   116,   -68,   150,   -68,    39,    39,
      39,    39,    51,    51,    39,    39,   -68,   -68,   150,   109,
     112,   112,   150,   150,   123,   -68,   165,   124,   -68,   126,
     127,   -68,   -68,   112,   112,   -68,   -68,    50,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,    36,    34,    72,     0,     0,    69,    71,    37,
       0,     0,    32,     1,    70,     0,    38,     0,    31,     0,
       0,     0,    33,    41,     0,     0,    42,    51,    74,    39,
      44,    40,     0,    50,     0,     0,    43,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    13,
      16,    18,    21,    30,     0,    57,    45,     0,    46,    47,
      48,    49,    55,     0,     0,     8,     9,     0,     0,     0,
       0,     0,    67,     0,     0,     0,     0,     2,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      52,    58,    32,    56,     0,     6,     0,    11,     0,    28,
       0,     0,    68,     0,     0,     5,     0,    17,    24,    25,
      26,    27,    20,    19,    22,    23,    54,     7,     0,    10,
       0,     0,     0,     0,     0,    12,     0,    61,    63,     0,
       0,    10,    29,     0,     0,    66,    62,    65,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -41,    13,   119,   -67,   -42,   -27,   -68,
     -12,   -13,   -68,   118,   -43,   136,   -68,   -68,   -68,    87,
     -65,   -68,   -68,   -68,   -68,   153,   -68,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    49,    96,    50,    51,    52,    53,    54,     4,    11,
       5,    12,    25,    26,    55,    56,    34,    35,    64,    57,
      58,    59,    60,    61,     6,     7,     8,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    75,    99,    76,    22,    78,    79,    24,    62,   103,
       9,    30,    31,    16,    91,    32,    17,     1,     2,     3,
      24,    19,    15,    63,    18,    97,    98,    23,   100,   101,
      37,    38,    39,   117,   -73,    10,   118,    93,   122,   107,
      65,    66,    40,    27,    41,    42,    43,    44,    45,    21,
      92,    91,    63,    46,    47,    67,    29,    68,    19,   132,
      48,    27,    90,    70,   124,    85,    69,    71,    86,    74,
      37,    38,    39,     1,     2,     3,   125,   127,   128,    80,
     129,   130,    40,    89,    41,    42,    43,    44,    45,   102,
     136,   138,   137,    46,    47,    37,    38,    39,   112,   113,
      48,    27,   116,   104,     1,     2,     3,    40,    13,    41,
      42,    43,    44,    45,   119,    37,    38,    39,    46,    47,
       1,     2,     3,   105,   120,    48,    27,    40,   121,    41,
      42,    43,    44,    45,    37,    38,    39,   123,    46,    47,
     133,   126,    37,    38,    39,    48,    27,   131,   134,   135,
      36,    94,    45,    37,    38,    39,    28,    46,    47,    14,
      45,    37,    38,    39,    72,    46,    47,     0,    77,    38,
      39,    45,    48,   -53,   -53,   -53,    46,    47,     0,    45,
      95,     0,    65,    66,    46,    47,    45,    81,    82,    83,
      84,    46,    47,     0,     0,     0,    33,    67,     0,   106,
     108,   109,   110,   111,     0,    85,   114,   115,    86,    87,
      88
};

static const yytype_int16 yycheck[] =
{
      42,    44,    69,    45,    17,    46,    47,    19,    35,    74,
       3,    24,    22,     3,    57,    25,    25,    12,    13,    14,
      32,    21,    23,    35,    33,    67,    68,    22,    70,    71,
       3,     4,     5,    22,    34,    28,    25,    64,   103,    80,
       6,     7,    15,    34,    17,    18,    19,    20,    21,     4,
      63,    94,    64,    26,    27,    21,    24,    23,    21,   126,
      33,    34,    35,    21,   106,    26,    32,    21,    29,    21,
       3,     4,     5,    12,    13,    14,   118,   120,   121,    28,
     122,   123,    15,    33,    17,    18,    19,    20,    21,    33,
     133,   134,   134,    26,    27,     3,     4,     5,    85,    86,
      33,    34,    35,    17,    12,    13,    14,    15,     0,    17,
      18,    19,    20,    21,    24,     3,     4,     5,    26,    27,
      12,    13,    14,    22,    22,    33,    34,    15,    22,    17,
      18,    19,    20,    21,     3,     4,     5,    21,    26,    27,
      16,    32,     3,     4,     5,    33,    34,    24,    22,    22,
      32,    64,    21,     3,     4,     5,    20,    26,    27,     6,
      21,     3,     4,     5,    33,    26,    27,    -1,     3,     4,
       5,    21,    33,    12,    13,    14,    26,    27,    -1,    21,
      22,    -1,     6,     7,    26,    27,    21,     8,     9,    10,
      11,    26,    27,    -1,    -1,    -1,    35,    21,    -1,    23,
      81,    82,    83,    84,    -1,    26,    87,    88,    29,    30,
      31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    14,    44,    46,    60,    61,    62,     3,
      28,    45,    47,     0,    61,    23,     3,    25,    33,    21,
      63,     4,    47,    22,    46,    48,    49,    34,    51,    24,
      47,    22,    25,    35,    52,    53,    49,     3,     4,     5,
      15,    17,    18,    19,    20,    21,    26,    27,    33,    37,
      39,    40,    41,    42,    43,    50,    51,    55,    56,    57,
      58,    59,    44,    46,    54,     6,     7,    21,    23,    32,
      21,    21,    33,    43,    21,    50,    43,     3,    39,    39,
      28,     8,     9,    10,    11,    26,    29,    30,    31,    33,
      35,    50,    47,    44,    55,    22,    38,    43,    43,    42,
      43,    43,    33,    56,    17,    22,    23,    39,    41,    41,
      41,    41,    40,    40,    41,    41,    35,    22,    25,    24,
      22,    22,    56,    21,    43,    43,    32,    50,    50,    43,
      43,    24,    42,    16,    22,    22,    50,    43,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    39,    39,    39,    40,    40,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    42,    43,    43,
      43,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    48,    48,    49,    50,    50,    50,    50,    50,
      51,    52,    51,    53,    51,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    63,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     4,     2,     2,
       4,     1,     3,     1,     2,     2,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     6,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     4,
       4,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       2,     0,     4,     0,     5,     1,     2,     1,     2,     1,
       2,     5,     7,     5,     7,     7,     6,     2,     3,     1,
       2,     1,     1,     0,     4
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
#line 180 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
  (yyval.data).str = (yyvsp[0].data.str);
  struct type *t=cherche_symbole(T,(yyvsp[0].data.str));
  if(t == NULL){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  else{
    (yyval.data).type = malloc(sizeof(struct type));
    memcpy((yyval.data).type,t,sizeof(struct type));
    char addr[10];
    strcpy(addr,itoa((yyval.data).next_adr, addr, 10));
   
    (yyval.data).code = concat((yyval.data).code, "\tmovl\t");
    (yyval.data).code = concat((yyval.data).code, addr);
    (yyval.data).code = concat((yyval.data).code, "(%ebp), %ebx\n");
  }
}
#line 1513 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 203 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
  (yyval.data).type=malloc(sizeof(struct type));
  (yyval.data).type->t=_INT;
  (yyval.data).type->dimension=0;
  (yyval.data).type->retour=NULL;
  (yyval.data).type->parametres=NULL;
  (yyval.data).type->nb_parametres=0;
  
  char addr[10];
  itoa((yyvsp[0].data.val), addr, 10);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t$");
  (yyval.data).code = concat((yyval.data).code, addr);
  (yyval.data).code = concat((yyval.data).code, ", %ebx\n");
}
#line 1536 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 221 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
  (yyval.data).type=malloc(sizeof(struct type));
  (yyval.data).type->t=_FLOAT;
  (yyval.data).type->dimension=0;
  (yyval.data).type->retour=NULL;
  (yyval.data).type->parametres=NULL;
  (yyval.data).type->nb_parametres=0;
  
  n++;  
}
#line 1555 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 235 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[-1].data);
  char * tmp = malloc(sizeof(char));
  *(tmp) = '\0';
//sauvegarde de %eax
  tmp = concat(tmp, "\tpushl\t%eax\n");
  tmp = concat(tmp, (yyval.data).code);
  free((yyval.data).code);
//restauration finale de %eax
  (yyval.data).code = concat(tmp, "\tmovl\t%eax, %ebx\n\tpopl\t%eax\n");
  }
#line 1571 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 246 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';

  struct type* t= cherche_symbole(T,(yyvsp[-2].data.str));
  if (NULL==t){    
    char s[] = "Fonction non déclarée.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->retour == NULL){
    char s[] = "Incompatibilité des déclarations.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->nb_parametres!=0){
    char s[] = "Nombre de paramètres incompatible. Attendu : 0.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
   
  (yyval.data).code = concat((yyval.data).code, "\tcall\t");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data.str));
  (yyval.data).code = concat((yyval.data).code, "\n");//Potentiellement agir sur esp ici, mais je ne sais pas dans quelles conditions...

  (yyval.data).type = t->retour;
  (yyval.data).str = (yyvsp[-2].data.str);
}
#line 1606 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 276 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
  struct type* t= cherche_symbole(T,(yyvsp[-3].data.str));
  if (NULL==t){    
    char s[] = "Fonction non déclarée.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  int i;
  for (i=0;i<t->nb_parametres;i++){
    if(!compare_type_arguments(&t->parametres[i],&(yyvsp[-1].data).type->parametres[i])){
      char s[] = "Nombre de paramètres incompatible.";
      yyerror(s);
      exit(EXIT_FAILURE);
    }
  }

//calcul adresse à push

//faire push

//Appeler la fonction
  (yyval.data).code = concat((yyval.data).code, "\tcall\t");   
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-3].data.str));
  (yyval.data).code = concat((yyval.data).code, "\n");//Potentiellement agir sur %esp ici, mais je ne sais pas dans quelles conditions...

  (yyval.data).type = t->retour;
  (yyval.data).str = (yyvsp[-3].data.str);
}
#line 1643 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 308 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
  struct type *t=cherche_symbole(T,(yyvsp[-1].data.str));
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if (t->t != _INT){
    char s[] = "Type incompatible.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  (yyval.data).type=malloc(sizeof(struct type));
  memcpy((yyval.data).type,t,sizeof(struct type));
  (yyval.data).str = (yyvsp[-1].data.str);
   
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t");
  (yyval.data).code = concat((yyval.data).code, "(%ebp), %ebx\n\tadd\t$1, %ebx\n\tmovl\t%ebx, ");
  (yyval.data).code = concat((yyval.data).code, (yyval.data).type->adresse);
  (yyval.data).code = concat((yyval.data).code, "(%ebp)\n");
}
#line 1673 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 333 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
  struct type *t=cherche_symbole(T,(yyvsp[-1].data.str));
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if (t->t != _INT){
    char s[] = "Type incompatible.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  (yyval.data).type=malloc(sizeof(struct type));
  memcpy((yyval.data).type,t,sizeof(struct type));
  (yyval.data).str = (yyvsp[-1].data.str);
  
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t");
  (yyval.data).code = concat((yyval.data).code, (yyval.data).type->adresse);
  (yyval.data).code = concat((yyval.data).code, "(%ebp), %ebx\n\tsub\t$1, %ebx\n\tmovl\t%ebx, ");
  (yyval.data).code = concat((yyval.data).code, (yyval.data).type->adresse);
  (yyval.data).code = concat((yyval.data).code, "(%ebp)\n");
  
}
#line 1705 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 360 "parser.y" /* yacc.c:1646  */
    {
  struct type *t=cherche_symbole(T,(yyvsp[-3].data.str));
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  /* if(t->dimension > 0){ */
  /*   char s[] = "Mauvaise déclaration : attendu tableau."; */
  /*   yyerror(s); */
  /*   exit(EXIT_FAILURE); */
  /* } */
  if( (yyvsp[-1].data).type->t != _INT ){
    char s[] = "Pas un entier.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  //  Extension : tester si expression appartient aux bornes : entre 0 et dimension(inclus pour 0)
  if( ((yyvsp[-1].data).val > t->dimension) || ((yyvsp[-1].data).val < 0) ){
    char s[] = "Débordement de tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  (yyval.data).type=malloc(sizeof(struct type));
  memcpy((yyval.data).type,t,sizeof(struct type));
  (yyval.data).str = (yyvsp[-3].data.str);
    
  (yyval.data).code = concat((yyvsp[-1].data).code, (yyval.data).code);

  (yyval.data).code_out=malloc(sizeof(char));
  *((yyval.data).code_out)='\0';
//calculer adresse dans ecx. utiliser cette adresse pour accéder à la valeur


}
#line 1745 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 398 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->nb_parametres = 1;
  (yyval.data).type->parametres = (yyvsp[0].data).type;
//TODO
}
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 404 "parser.y" /* yacc.c:1646  */
    {
  int k=(yyvsp[-2].data).type->nb_parametres+1;
  struct type *t=malloc(sizeof(struct type)*k);
  memcpy(t,(yyvsp[-2].data).type->parametres,sizeof(struct type)*(k-1));
  t[k-1]=*((yyvsp[0].data).type);
  (yyval.data).type->parametres=t;
  (yyval.data).type->nb_parametres=k;
//TODO
  }
#line 1770 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 416 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);

}
#line 1779 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 420 "parser.y" /* yacc.c:1646  */
    {
  if( (yyvsp[0].data).type->t != _INT && (yyvsp[0].data).type->t != _FLOAT ){
    char s[] = "Opposé d'un type interdit.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( (yyvsp[0].data).type->t == _INT ){
    (yyvsp[0].data).val = -(yyvsp[0].data).val;
  }
  else{
    (yyvsp[0].data).valf = -(yyvsp[0].data).valf;
  }
  (yyval.data) = (yyvsp[0].data);

  if( (yyval.data).type->t == _INT )
      (yyval.data).code = concat((yyval.data).code, "\tneg\t%ebx\n");
  else
;//à faire... Mais ej ne sais pas comment...
}
#line 1803 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 439 "parser.y" /* yacc.c:1646  */
    {
  if( (yyvsp[0].data).type->t != _INT && (yyvsp[0].data).type->t != _FLOAT ){
    char s[] = "Opposé d'un type interdit.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( (yyvsp[0].data).type->t == _INT ){
    (yyvsp[0].data).val = !(yyvsp[0].data).val;
  }
  else{
    (yyvsp[0].data).valf = !(yyvsp[0].data).valf;
  }
  (yyval.data) = (yyvsp[0].data);

  (yyval.data).code = concat((yyval.data).code, "\tnot\t%ebx\n");

}
#line 1825 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 459 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);

  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%ebx, %eax\n");
}
#line 1835 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 464 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val * (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).valf = (yyvsp[-2].data).valf * (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[0].data);

    (yyval.data).code = (yyvsp[-2].data).code;
    (yyval.data).valf = (yyvsp[-2].data).val * (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).valf = (yyvsp[-2].data).valf * (yyvsp[0].data).valf;
  }

  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%ebx, %eax\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmul\t%ebx\n");
  free((yyvsp[0].data).code);
}
#line 1874 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 501 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
}
#line 1882 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 504 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val + (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).valf = (yyvsp[-2].data).valf + (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[0].data);
    (yyval.data).code = (yyvsp[-2].data).code;
    //code
    (yyval.data).valf = (yyvsp[-2].data).val + (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).valf = (yyvsp[-2].data).valf + (yyvsp[0].data).valf;
  }

//sauvegarde de %eax
  (yyval.data).code = concat((yyval.data).code, "\tpushl\t%eax\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
//restauration finale de %eax
  (yyval.data).code = concat((yyval.data).code, "\tpopl\t%eax\n\tadd\t%ebx, %eax\n");

  free((yyvsp[0].data).code);
}
#line 1924 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 541 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val - (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).valf = (yyvsp[-2].data).valf - (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[0].data);
    (yyval.data).code = (yyvsp[-2].data).code;
    //code
    (yyval.data).valf = (yyvsp[-2].data).val - (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).valf = (yyvsp[-2].data).valf - (yyvsp[0].data).valf;
  }

//sauvegarde de %eax
  (yyval.data).code = concat((yyval.data).code, "\tpushl\t%eax\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
//restauration finale de %eax
  (yyval.data).code = concat((yyval.data).code, "\tpopl\t%eax\n\tsub\t%ebx, %eax\n");
  free((yyvsp[0].data).code);

}
#line 1966 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 581 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
}
#line 1974 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 584 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val < (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[0].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).valf < (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).val < (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    (yyval.data).type = _INT;
    //code
    (yyval.data).val = (yyvsp[-2].data).valf < (yyvsp[0].data).valf;
  }

  char * vrai = nextLabel(), * end = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tpushl\t%eax\n");
  free((yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, %ebx\n\tpop\t%eax\n\tcmp\t%eax, %ebx\n\t");
  (yyval.data).code = concat((yyval.data).code, "jl");
  (yyval.data).code = concat((yyval.data).code, "\tLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, "\n\tmovl\t$0, %eax\n\tjmp\t");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, ":\n\tmovl\t$1, %eax\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
}
#line 2024 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 629 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val > (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[0].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).valf > (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).val > (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    (yyval.data).val = _INT;
    //code
    (yyval.data).val = (yyvsp[-2].data).valf > (yyvsp[0].data).valf;
  }

  char * vrai = nextLabel(), * end = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tpushl\t%eax\n");
  free((yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, %ebx\n\tpop\t%eax\n\tcmp\t%eax, %ebx\n\t");
  (yyval.data).code = concat((yyval.data).code, "jg");
  (yyval.data).code = concat((yyval.data).code, "\tLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, "\n\tmovl\t$0, %eax\n\tjmp\t");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, ":\n\tmovl\t$1, %eax\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
}
#line 2074 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 674 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val <= (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[0].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).valf <= (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).val <= (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    (yyval.data).type = _INT;
    //code
    (yyval.data).val = (yyvsp[-2].data).valf <= (yyvsp[0].data).valf;
  }
  char * vrai = nextLabel(), * end = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tpushl\t%eax\n");
  free((yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, %ebx\n\tpop\t%eax\n\tcmp\t%eax, %ebx\n\t");
  (yyval.data).code = concat((yyval.data).code, "jle");
  (yyval.data).code = concat((yyval.data).code, "\tLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, "\n\tmovl\t$0, %eax\n\tjmp\t");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, ":\n\tmovl\t$1, %eax\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
}
#line 2123 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 718 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val >= (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[0].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).valf >= (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).val >= (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    (yyval.data).type = _INT;
    //code
    (yyval.data).val = (yyvsp[-2].data).valf >= (yyvsp[0].data).valf;
  }

  char * vrai = nextLabel(), * end = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tpushl\t%eax\n");
  free((yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, %ebx\n\tpop\t%eax\n\tcmp\t%eax, %ebx\n\t");
  (yyval.data).code = concat((yyval.data).code, "jge");
  (yyval.data).code = concat((yyval.data).code, "\tLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, "\n\tmovl\t$0, %eax\n\tjmp\t");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, ":\n\tmovl\t$1, %eax\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
}
#line 2173 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 763 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val == (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[0].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).valf == (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).val == (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    (yyval.data).type = _INT;
    //code
    (yyval.data).val = (yyvsp[-2].data).valf == (yyvsp[0].data).valf;
  }

  char * vrai = nextLabel(), * end = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tpushl\t%eax\n");
  free((yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, %ebx\n\tpop\t%eax\n\tcmp\t%eax, %ebx\n\t");
  (yyval.data).code = concat((yyval.data).code, "jeq");
  (yyval.data).code = concat((yyval.data).code, "\tLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, "\n\tmovl\t$0, %eax\n\tjmp\t");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, ":\n\tmovl\t$1, %eax\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
}
#line 2223 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 808 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-2].data).type->t == _VOID) || ((yyvsp[0].data).type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code ?
    (yyval.data).val = (yyvsp[-2].data).val != (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _INT) ){
    (yyval.data) = (yyvsp[0].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).valf != (yyvsp[0].data).val;
  }
  else if( ((yyvsp[-2].data).type->t == _INT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    //code
    (yyval.data).val = (yyvsp[-2].data).val != (yyvsp[0].data).valf;
  }
  else if( ((yyvsp[-2].data).type->t == _FLOAT) && ((yyvsp[0].data).type->t == _FLOAT) ){
    (yyval.data) = (yyvsp[-2].data);
    (yyval.data).type = _INT;
    //code
    (yyval.data).val = (yyvsp[-2].data).valf != (yyvsp[0].data).valf;
  }

  char * vrai = nextLabel(), * end = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tpushl\t%eax\n");
  free((yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, %ebx\n\tpop\t%eax\n\tcmp\t%eax, %ebx\n\t");
  (yyval.data).code = concat((yyval.data).code, "jne");
  (yyval.data).code = concat((yyval.data).code, "\tLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, "\n\tmovl\t$0, %eax\n\tjmp\t");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, vrai);
  (yyval.data).code = concat((yyval.data).code, ":\n\tmovl\t$1, %eax\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
}
#line 2273 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 856 "parser.y" /* yacc.c:1646  */
    {
  struct type *t=cherche_symbole(T,(yyvsp[-2].data.str));
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->t == _VOID){
    char s[] = "Type VOID non compatible avec affectation.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  /* if( $3.type->dimension > 0 ){ */
  /*   char s[] = "Assignation invalide (tableau)."; */
  /*   yyerror(s); */
  /*   exit(EXIT_FAILURE); */
  /* } */

  (yyval.data).type = malloc(sizeof(struct type));
  memcpy((yyval.data).type,t,sizeof(struct type));

  if( t->t == _INT ){
    (yyval.data).val = (yyvsp[0].data).val;
  }
  else if( t->t == _FLOAT ){
    (yyval.data).valf = (yyvsp[0].data).val;
  }

  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  free((yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, ");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).type->adresse);
  (yyval.data).code = concat((yyval.data).code, "\n");
}
#line 2312 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 890 "parser.y" /* yacc.c:1646  */
    {
  struct type *t=cherche_symbole(T,(yyvsp[-5].data.str));
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->t == _VOID){
    char s[] = "Type VOID non compatible avec comparaison.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( t->dimension == 0 ){
    char s[] = "Pas un tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  /* if( $6.type->dimension > 0 ){ */
  /*   char s[] = "Assignation invalide (tableau)."; */
  /*   yyerror(s); */
  /*   exit(EXIT_FAILURE); */
  /* } */
  //EXTENSION expression doit être compris entre 0 et dimension, 0 inclus
  if( ((yyvsp[-3].data).val > t->dimension) || ((yyvsp[-3].data).val < 0) ){
    char s[] = "Débordement de tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( t->t == _INT ){
    (yyval.data).type = malloc(sizeof(struct type));
    memcpy((yyval.data).type,t,sizeof(struct type));
    //code
    (yyval.data).val = (yyvsp[-3].data).val;
  }
  else if( t->t == _FLOAT ){
    (yyval.data).type = malloc(sizeof(struct type));
    memcpy((yyval.data).type,t,sizeof(struct type));
    //code
    (yyval.data).valf = (yyvsp[-3].data).val;
  }

//Calcul de l'adresse. 
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-3].data).code);
  free((yyvsp[-3].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tmovl\t%eax, ");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-3].data).type->adresse);
  (yyval.data).code = concat((yyval.data).code, "\n");
}
#line 2366 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 939 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
}
#line 2374 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 945 "parser.y" /* yacc.c:1646  */
    {
  //code
  struct symbole *s=(yyvsp[-1].data).sym;
  enum _type type_name;
   
  type_name = (yyvsp[-2].data).type->t;
  
  while(s!=NULL){
    s->t->t=type_name;
    ajout_symbole(T,s->str,s->t);
    s = s->suivant;
  }

  (yyval.data).code = (yyvsp[-1].data).code;
}
#line 2394 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 963 "parser.y" /* yacc.c:1646  */
    {
  //code
  (yyval.data).sym=malloc(sizeof(struct symbole));
  (yyval.data).sym->str=(yyvsp[0].data).str;
  (yyval.data).sym->t=(yyvsp[0].data).type;
  (yyval.data).sym->suivant=NULL;
  (yyval.data).code = (yyvsp[0].data).code;
}
#line 2407 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 971 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).sym=malloc(sizeof(struct symbole));
  (yyval.data).sym->str=(yyvsp[0].data).str;
  (yyval.data).sym->t=(yyvsp[0].data).type; 
  (yyval.data).sym->suivant=(yyvsp[-2].data).sym;
  //code
  (yyval.data).code = concat((yyvsp[-2].data).code, (yyvsp[0].data).code);
  free((yyvsp[0].data).code);
}
#line 2421 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 983 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->t = _VOID;
  (yyval.data).type->dimension = 0;

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2434 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 991 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->t = _INT;
  (yyval.data).type->dimension = 0;

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2447 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 999 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->t = _FLOAT;
  (yyval.data).type->dimension = 0;

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2460 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1010 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->dimension = 0;
  (yyval.data).type->retour = NULL;
  (yyval.data).type->parametres = NULL;
  (yyval.data).type->nb_parametres = 0; 
  (yyval.data).str = (yyvsp[0].data.str);

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2476 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1021 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->dimension = 42; //Ceci est un pointeur. Nous ne savons pas gérer les malloc
  (yyval.data).type->retour = NULL;
  (yyval.data).type->parametres = NULL;
  (yyval.data).type->nb_parametres = 0;
  (yyval.data).str = (yyvsp[0].data.str);

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2492 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1032 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->dimension = (yyvsp[-1].data.val); //Là on peut !
  (yyval.data).type->retour = NULL;
  (yyval.data).type->parametres = NULL;
  (yyval.data).type->nb_parametres = 0;
  (yyval.data).str = (yyvsp[-3].data.str);

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2508 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->dimension = 0;
  (yyval.data).type->retour = NULL;
  (yyval.data).type->parametres = (yyvsp[-1].data).type->parametres;
  (yyval.data).type->nb_parametres = (yyvsp[-1].data).type->nb_parametres;
  (yyval.data).str = (yyvsp[-3].data).str;

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2524 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1054 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).type = malloc(sizeof(struct type));
  (yyval.data).type->dimension = 0;
  (yyval.data).type->retour = NULL;
  (yyval.data).type->parametres = NULL;
  (yyval.data).type->nb_parametres = 0;
  (yyval.data).str = (yyvsp[-2].data).str;

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2540 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1068 "parser.y" /* yacc.c:1646  */
    {
  struct type *param = malloc(sizeof(struct type));
  param->t = (yyvsp[0].data).type->t;
  param->dimension = 0;
  param->retour = NULL;
  param->parametres = NULL;
  param->nb_parametres = 0;
  (yyval.data).type->parametres = param;
}
#line 2554 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
  int k = (yyvsp[-2].data).type->nb_parametres+1;
  struct type *t = malloc(sizeof(struct type)*k);
  memcpy(t,(yyvsp[-2].data).type->parametres,sizeof(struct type)*(k-1));
  t[k-1] = *((yyvsp[0].data).type);
  (yyval.data).type->parametres = t;
  (yyval.data).type->nb_parametres = k;
  //code
}
#line 2568 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1089 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
  (yyval.data).type->t = (yyvsp[-1].data).type->t;
  ajout_symbole(T,(yyvsp[0].data).str,(yyval.data).type);

  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
}
#line 2581 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1100 "parser.y" /* yacc.c:1646  */
    {  //A voir en fonction de la suite
  (yyval.data) = (yyvsp[0].data);
  }
#line 2589 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1103 "parser.y" /* yacc.c:1646  */
    { 
  (yyval.data) = (yyvsp[0].data);
  }
#line 2597 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1106 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
  }
#line 2605 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1109 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
  }
#line 2613 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1112 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);
  }
#line 2621 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1118 "parser.y" /* yacc.c:1646  */
    {  
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
 }
#line 2630 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1122 "parser.y" /* yacc.c:1646  */
    { T = nouvelle_table(T);}
#line 2636 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1122 "parser.y" /* yacc.c:1646  */
    { 
  T = T->englobante;
  (yyval.data).code = (yyvsp[-1].data).code;
 }
#line 2645 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1126 "parser.y" /* yacc.c:1646  */
    {T = nouvelle_table(T);}
#line 2651 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1126 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
  T = T->englobante;  
  (yyval.data).code = concat((yyvsp[-2].data).code, (yyvsp[-1].data).code);
  free((yyvsp[-1].data).code);
  }
#line 2663 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1136 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data); //TODO
 }
#line 2671 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1139 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[-1].data);//TODO
 }
#line 2679 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1145 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);//TODO
}
#line 2687 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1148 "parser.y" /* yacc.c:1646  */
    {
(yyval.data) = (yyvsp[-1].data);//TODO
}
#line 2695 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1154 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data).code=malloc(sizeof(char));
  *((yyval.data).code)='\0';
 }
#line 2704 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1158 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[-1].data);
}
#line 2712 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1164 "parser.y" /* yacc.c:1646  */
    {
  if( (yyvsp[-2].data).val != 0 )
    (yyval.data) = (yyvsp[0].data);
  //Extension : return
  char * jmp = nextLabel();
  (yyval.data).code = concat((yyvsp[-2].data).code, "\tjz\tLBL");
  (yyval.data).code = concat((yyval.data).code, jmp);
  (yyval.data).code = concat((yyval.data).code, "\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "LBL");
  (yyval.data).code = concat((yyval.data).code, jmp);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  free(jmp);
  free((yyvsp[0].data).code);
}
#line 2732 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1179 "parser.y" /* yacc.c:1646  */
    {
  if( (yyvsp[-4].data).val != 0 )
    (yyval.data) = (yyvsp[-2].data);
  else
    (yyval.data) = (yyvsp[0].data);

  char * jmp = nextLabel();
  (yyval.data).code = concat((yyvsp[-4].data).code, "\tjz\tLBL");
  (yyval.data).code = concat((yyval.data).code, jmp);
  (yyval.data).code = concat((yyval.data).code, "\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, "LBL");
  (yyval.data).code = concat((yyval.data).code, jmp);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  free(jmp);
  free((yyvsp[-2].data).code);
  free((yyvsp[0].data).code);
}
#line 2756 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1201 "parser.y" /* yacc.c:1646  */
    {
  if( (yyvsp[-2].data).val != 0 )
    (yyval.data) = (yyvsp[0].data);

  char * begin = nextLabel();
  char * end = nextLabel();
  (yyval.data).code = malloc(sizeof(char));
  *((yyval.data).code) = '\0';
  (yyval.data).code = concat((yyval.data).code, "LBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjz\tLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjmp\tLBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  free(begin);
  free(end);
  free((yyvsp[0].data).code);
  free((yyvsp[-2].data).code);
}
#line 2787 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1227 "parser.y" /* yacc.c:1646  */
    {
  if( (yyvsp[-3].data).val != 0 )
    (yyval.data) = (yyvsp[0].data);

  char * begin = nextLabel();
  char * end = nextLabel();
  (yyval.data).code = (yyvsp[-4].data).code;
  (yyval.data).code = concat((yyval.data).code, "LBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjz\tLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjmp\tLBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  free(begin);
  free(end);
  free((yyvsp[-2].data).code);
  free((yyvsp[0].data).code);
}
#line 2818 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1253 "parser.y" /* yacc.c:1646  */
    {
  //Règle de grammaire ajoutée pour gérer les for sans accolades
  if( (yyvsp[-3].data).val != 0 )
    (yyval.data) = (yyvsp[0].data);

  char * begin = nextLabel();
  char * end = nextLabel();
  (yyval.data).code = (yyvsp[-4].data).code;
  (yyval.data).code = concat((yyval.data).code, "LBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjz\tLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-2].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjmp\tLBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  free(begin);
  free(end);
  free((yyvsp[-2].data).code);
  free((yyvsp[0].data).code);
}
#line 2850 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1280 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[-4].data);

  char * begin = nextLabel();
  char * end = nextLabel();
  (yyval.data).code = malloc(sizeof(char));
  *((yyval.data).code) = '\0';
  (yyval.data).code = concat((yyval.data).code, "LBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-4].data).code);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[-1].data).code);
  (yyval.data).code = concat((yyval.data).code, "\tjz\tLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, "\n\tjmp\tLBL");
  (yyval.data).code = concat((yyval.data).code, begin);
  (yyval.data).code = concat((yyval.data).code, "\nLBL");
  (yyval.data).code = concat((yyval.data).code, end);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  free(begin);
  free(end);
  free((yyvsp[-1].data).code);
  free((yyvsp[-4].data).code);
}
#line 2879 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1307 "parser.y" /* yacc.c:1646  */
    {
  if( retour != _VOID ){
    char s[] = "Type de retour faux : VOID attendu.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  (yyval.data).code = malloc(sizeof(char));
  *((yyval.data).code) = '\0';
  (yyval.data).code = concat((yyval.data).code, "\tleave\n\tret\n");
}
#line 2894 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1317 "parser.y" /* yacc.c:1646  */
    {
  if( ((yyvsp[-1].data).type->t != retour) && ((yyvsp[-1].data).type->t == _VOID) ){
    char s[] = "Type de retour faux.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  (yyval.data).code = concat((yyvsp[-1].data).code, "\tleave\n\tret\n");
}
#line 2907 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1328 "parser.y" /* yacc.c:1646  */
    {
  s=malloc(sizeof(char)*999999);
  n=0;
  fprintf(output,"%s",s);
  //code remonté à écrire

  fprintf(output, "%s%s", (yyvsp[0].data).code, (yyvsp[0].data).code_out?(yyvsp[0].data).code_out:"");
 }
#line 2920 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1336 "parser.y" /* yacc.c:1646  */
    {
  //code remonté à écrire
  fprintf(output, "%s%s", (yyvsp[0].data).code, (yyvsp[0].data).code_out?(yyvsp[-1].data).code_out:"");
}
#line 2929 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1343 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);//  ajout_symbole(T,$1.str,$1.type->retour);

  (yyval.data).code = malloc(sizeof(char));
  *((yyval.data).code) = '\0';
  (yyval.data).code = concat((yyval.data).code, "\t.globl\t");
  printf("Salut les amis voici le str %s", (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, "\n\t.type\t");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, ", @function\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);
  (yyval.data).code = concat((yyval.data).code, "\t.size\t");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, ", .-");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, "\n");

  free((yyvsp[0].data).code);
}
#line 2956 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1365 "parser.y" /* yacc.c:1646  */
    {
  (yyval.data) = (yyvsp[0].data);

  (yyval.data).code = malloc(sizeof(char));
  *((yyval.data).code) = '\0';
  (yyval.data).code = concat((yyval.data).code, "\t.globl\t");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, "\n\t.type\t");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, ", @object\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).str);
  (yyval.data).code = concat((yyval.data).code, ":\n");
  (yyval.data).code = concat((yyval.data).code, (yyvsp[0].data).code);

  free((yyvsp[0].data).code);
}
#line 2977 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1384 "parser.y" /* yacc.c:1646  */
    { 
  retour = (yyvsp[-1].data).type->t;
  
  if ((yyvsp[-1].data).type->dimension > 0) {
    char s[] = "Retour de tableau invalide";
    yyerror(s);
    exit(EXIT_FAILURE);
  } 
}
#line 2991 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1392 "parser.y" /* yacc.c:1646  */
    {
   (yyval.data).str = (yyvsp[-2].data).str; 
   (yyval.data).type = (yyvsp[-2].data).type;
   (yyval.data).type->retour = malloc(sizeof(struct type));
   (yyval.data).type->retour->dimension = 0;
   (yyval.data).type->retour->retour = NULL;
   (yyval.data).type->retour->nb_parametres = 0;
   (yyval.data).type->retour->parametres = NULL;
   (yyval.data).type->retour->t = retour;
   ajout_symbole(T,(yyvsp[-2].data).str,(yyval.data).type);

   (yyval.data).code = (yyvsp[0].data).code;
}
#line 3009 "parser.c" /* yacc.c:1646  */
    break;


#line 3013 "parser.c" /* yacc.c:1646  */
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
#line 1407 "parser.y" /* yacc.c:1906  */

int yyerror (char *s) {
  fflush (stdout);
  fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
  return 0;
}


int main (int argc, char *argv[]) {
  FILE *input = NULL;
  T=nouvelle_table(NULL);
  if (argc==2) {
    input = fopen (argv[1], "r");
    file_name = strdup (argv[1]);
    if (input) {
      char *output_file_name = strdup (argv[1]);
      yyin = input;
      output_file_name[strlen(output_file_name)-1] = 's';
      output = fopen (output_file_name, "w");
      if (output){
	yyparse();
	fclose(output);
      }
      else{
	fprintf (stderr, "%s: Could not open %s.\n", *argv, output_file_name);
	return 1;
      }
      free(output_file_name);
      fclose(input);
    }
    else {
      fprintf (stderr, "%s: Could not open %s.\n", *argv, argv[1]);
      return 1;
    }
    free(file_name);
  }
  else {
    fprintf (stderr, "%s: error: no input file\n", *argv);
    return 1;
  }
  return 0;
}
