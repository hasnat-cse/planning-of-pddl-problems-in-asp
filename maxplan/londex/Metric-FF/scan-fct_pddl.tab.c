/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse dis_fct_pddlparse
#define yylex   dis_fct_pddllex
#define yyerror dis_fct_pddlerror
#define yylval  dis_fct_pddllval
#define yychar  dis_fct_pddlchar
#define yydebug dis_fct_pddldebug
#define yynerrs dis_fct_pddlnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINE_TOK = 258,
     PROBLEM_TOK = 259,
     SITUATION_TOK = 260,
     BSITUATION_TOK = 261,
     OBJECTS_TOK = 262,
     BDOMAIN_TOK = 263,
     INIT_TOK = 264,
     GOAL_TOK = 265,
     METRIC_TOK = 266,
     dis_AND_TOK = 267,
     dis_NOT_TOK = 268,
     NAME = 269,
     VARIABLE = 270,
     NUM = 271,
     LE_TOK = 272,
     LEQ_TOK = 273,
     EQ_TOK = 274,
     GEQ_TOK = 275,
     GE_TOK = 276,
     MINUS_TOK = 277,
     AD_TOK = 278,
     MU_TOK = 279,
     DI_TOK = 280,
     Fdis_ORdis_ALL_TOK = 281,
     IMPLY_TOK = 282,
     dis_OR_TOK = 283,
     dis_EXISTS_TOK = 284,
     EITHER_TOK = 285,
     OPEN_PAREN = 286,
     CLOSE_PAREN = 287,
     AT_TOK = 288,
     CONSTRAINTS_TOK = 289,
     PREFERENCE_TOK = 290,
     WITHIN_TOK = 291,
     SOMETIME_TOK = 292,
     ALWAYS_TOK = 293,
     AT_MOST_ONCE_TOK = 294,
     SOMETIME_AFTER_TOK = 295,
     SOMETIME_BEFORE_TOK = 296,
     ALWAYS_WITHIN_TOK = 297,
     HOLD_DURING_TOK = 298,
     HOLD_AFTER_TOK = 299,
     IS_VIOLATED_TOK = 300,
     AT_END_TOK = 301
   };
#endif
#define DEFINE_TOK 258
#define PROBLEM_TOK 259
#define SITUATION_TOK 260
#define BSITUATION_TOK 261
#define OBJECTS_TOK 262
#define BDOMAIN_TOK 263
#define INIT_TOK 264
#define GOAL_TOK 265
#define METRIC_TOK 266
#define dis_AND_TOK 267
#define dis_NOT_TOK 268
#define NAME 269
#define VARIABLE 270
#define NUM 271
#define LE_TOK 272
#define LEQ_TOK 273
#define EQ_TOK 274
#define GEQ_TOK 275
#define GE_TOK 276
#define MINUS_TOK 277
#define AD_TOK 278
#define MU_TOK 279
#define DI_TOK 280
#define Fdis_ORdis_ALL_TOK 281
#define IMPLY_TOK 282
#define dis_OR_TOK 283
#define dis_EXISTS_TOK 284
#define EITHER_TOK 285
#define OPEN_PAREN 286
#define CLOSE_PAREN 287
#define AT_TOK 288
#define CONSTRAINTS_TOK 289
#define PREFERENCE_TOK 290
#define WITHIN_TOK 291
#define SOMETIME_TOK 292
#define ALWAYS_TOK 293
#define AT_MOST_ONCE_TOK 294
#define SOMETIME_AFTER_TOK 295
#define SOMETIME_BEFORE_TOK 296
#define ALWAYS_WITHIN_TOK 297
#define HOLD_DURING_TOK 298
#define HOLD_AFTER_TOK 299
#define IS_VIOLATED_TOK 300
#define AT_END_TOK 301




/* Copy the first part of user declarations.  */
#line 2 "scan-fct_pddl.y"

//#define YYDEBUG 1
#ifdef YYDEBUG
  extern int yydebug=1;
#endif


#include <stdio.h>
#include <string.h> 
#include "dis_ff.h"
#include "dis_memory.h"
#include "dis_parse.h"
#include "dis_constraints.h"

#ifndef SCAN_ERR
#define SCAN_ERR
#define DEFINE_dis_EXPECTED            0
#define PROBLEM_dis_EXPECTED           1
#define PROBNAME_dis_EXPECTED          2
#define LBRACKET_dis_EXPECTED          3
#define RBRACKET_dis_EXPECTED          4
#define DOMDEFS_dis_EXPECTED           5
#define REQUIREM_dis_EXPECTED          6
#define TYPEDLIST_dis_EXPECTED         7
#define DOMdis_EXT_dis_EXPECTED            8
#define DOMdis_EXTNAME_dis_EXPECTED        9
#define TYPEDEF_dis_EXPECTED          10
#define CONSTLIST_dis_EXPECTED        11
#define PREDDEF_dis_EXPECTED          12 
#define NAME_dis_EXPECTED             13
#define VARIABLE_dis_EXPECTED         14
#define ACTIONFUNCTdis_OR_dis_EXPECTED    15
#define dis_ATOM_Fdis_ORMULA_dis_EXPECTED     16
#define EFFECT_DEF_dis_EXPECTED       17
#define NEG_Fdis_ORMULA_dis_EXPECTED      18
#define dis_NOT_SUPPdis_ORTED             19
#define SITUATION_dis_EXPECTED        20
#define SITNAME_dis_EXPECTED          21
#define BDOMAIN_dis_EXPECTED          22
#define BADDOMAIN                 23
#define INIFACTS                  24
#define GOALDEF                   25
#define ADLGOAL                   26
#define CONSTRAINTLIST_EXPECTED	  27
#endif


static char * serrmsg[] = {
  "'define' expected",
  "'problem' expected",
  "problem name expected",
  "'(' expected",
  "')' expected",
  "additional domain definitions expected",
  "requirements (e.g. ':strips') expected",
  "typed list of <%s> expected",
  "domain extension expected",
  "domain to be extented expected",
  "type definition expected",
  "list of constants expected",
  "predicate definition expected",
  "<name> expected",
  "<variable> expected",
  "action functor expected",
  "atomic formula expected",
  "effect definition expected",
  "negated atomic formula expected",
  "requirement %s not supported by this IPP version",  
  "'situation' expected",
  "situation name expected",
  "':domain' expected",
  "this problem needs another domain file",
  "initial facts definition expected",
  "goal definition expected",
  "first order logic expression expected",
  "constraint list expected",
  NULL
};


void dis_fcterr( int errno, char *par );


static int sact_err;
static char *sact_err_par = NULL;
static dis_Bool sis_negated = dis_FALSE;
static dis_Pldis_Operator *scur_op = NULL;
static dis_TypedList *forall_tl = NULL;



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 97 "scan-fct_pddl.y"
typedef union YYSTYPE {

  char string[dis_MAX_LENGTH];
  char* pstring;
  dis_Parsedis_ExpNode *pdis_Parsedis_ExpNode;
  dis_PlNode* pdis_PlNode;
  dis_FactList* pdis_FactList;
  dis_TokenList* pdis_TokenList;
  dis_TypedList* pdis_TypedList;
  /* PDDL 3 */
  dis_ConNode* pdis_ConNode;

} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 281 "scan-fct_pddl.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 293 "scan-fct_pddl.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   339

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  45
/* YYNRULES -- Number of rules. */
#define YYNRULES  119
/* YYNRULES -- Number of states. */
#define YYNSTATES  299

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    15,    20,    25,    26,
      29,    32,    35,    38,    41,    44,    49,    50,    56,    57,
      63,    64,    70,    73,    75,    80,    81,    90,    96,   101,
     103,   104,   107,   112,   113,   122,   128,   133,   135,   136,
     139,   141,   146,   154,   159,   164,   169,   175,   180,   186,
     192,   199,   206,   212,   213,   216,   222,   224,   229,   237,
     243,   249,   255,   261,   267,   269,   274,   279,   285,   293,
     294,   297,   299,   302,   304,   313,   319,   324,   326,   331,
     336,   342,   348,   354,   360,   362,   367,   372,   378,   384,
     390,   396,   401,   403,   406,   408,   411,   416,   418,   423,
     428,   429,   432,   434,   436,   438,   441,   442,   448,   453,
     456,   457,   463,   468,   471,   473,   478,   480,   485,   486
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      48,     0,    -1,    -1,    49,    48,    -1,    -1,    31,     3,
      50,    51,    53,    32,    -1,    31,     4,    14,    32,    -1,
      31,     8,    14,    32,    -1,    -1,    53,    54,    -1,    53,
      55,    -1,    53,    57,    -1,    53,    52,    -1,    53,    71,
      -1,    53,    59,    -1,    31,     7,    86,    32,    -1,    -1,
      31,     9,    56,    75,    32,    -1,    -1,    31,    10,    58,
      61,    32,    -1,    -1,    31,    34,    60,    65,    32,    -1,
      31,    32,    -1,    63,    -1,    31,    12,    64,    32,    -1,
      -1,    31,    26,    31,    87,    62,    32,    61,    32,    -1,
      31,    35,    14,    72,    32,    -1,    31,    35,    72,    32,
      -1,    73,    -1,    -1,    64,    61,    -1,    31,    12,    67,
      32,    -1,    -1,    31,    26,    31,    87,    66,    32,    65,
      32,    -1,    31,    35,    14,    68,    32,    -1,    31,    35,
      68,    32,    -1,    69,    -1,    -1,    65,    67,    -1,    69,
      -1,    31,    12,    70,    32,    -1,    31,    26,    31,    87,
      32,    69,    32,    -1,    31,    46,    72,    32,    -1,    31,
      38,    72,    32,    -1,    31,    37,    72,    32,    -1,    31,
      36,    16,    72,    32,    -1,    31,    39,    72,    32,    -1,
      31,    40,    72,    72,    32,    -1,    31,    41,    72,    72,
      32,    -1,    31,    42,    16,    72,    72,    32,    -1,    31,
      43,    16,    16,    72,    32,    -1,    31,    44,    16,    72,
      32,    -1,    -1,    69,    70,    -1,    31,    11,    14,    78,
      32,    -1,    73,    -1,    31,    12,    74,    32,    -1,    31,
      26,    31,    87,    32,    72,    32,    -1,    31,    17,    77,
      77,    32,    -1,    31,    18,    77,    77,    32,    -1,    31,
      19,    77,    77,    32,    -1,    31,    20,    77,    77,    32,
      -1,    31,    21,    77,    77,    32,    -1,    81,    -1,    31,
      28,    74,    32,    -1,    31,    13,    72,    32,    -1,    31,
      27,    72,    72,    32,    -1,    31,    29,    31,    87,    32,
      72,    32,    -1,    -1,    72,    74,    -1,    76,    -1,    75,
      76,    -1,    89,    -1,    31,    19,    31,    14,    91,    32,
      16,    32,    -1,    31,    19,    14,    16,    32,    -1,    31,
      33,    89,    32,    -1,    16,    -1,    31,    14,    83,    32,
      -1,    31,    22,    77,    32,    -1,    31,    23,    77,    77,
      32,    -1,    31,    22,    77,    77,    32,    -1,    31,    24,
      77,    77,    32,    -1,    31,    25,    77,    77,    32,    -1,
      16,    -1,    31,    14,    91,    32,    -1,    31,    22,    78,
      32,    -1,    31,    23,    78,    79,    32,    -1,    31,    24,
      78,    80,    32,    -1,    31,    22,    78,    78,    32,    -1,
      31,    25,    78,    78,    32,    -1,    31,    45,    14,    32,
      -1,    78,    -1,    79,    78,    -1,    78,    -1,    80,    78,
      -1,    31,    13,    82,    32,    -1,    82,    -1,    31,    88,
      83,    32,    -1,    31,    19,    83,    32,    -1,    -1,    84,
      83,    -1,    14,    -1,    15,    -1,    14,    -1,    14,    85,
      -1,    -1,    14,    30,    85,    32,    86,    -1,    14,    22,
      14,    86,    -1,    14,    86,    -1,    -1,    15,    30,    85,
      32,    87,    -1,    15,    22,    14,    87,    -1,    15,    87,
      -1,    14,    -1,    31,    13,    90,    32,    -1,    90,    -1,
      31,    88,    91,    32,    -1,    -1,    14,    91,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   197,   197,   200,   207,   206,   222,   232,   243,   247,
     250,   253,   256,   259,   262,   268,   278,   277,   292,   291,
     305,   304,   323,   328,   333,   341,   339,   360,   381,   402,
     411,   415,   432,   440,   438,   462,   477,   492,   510,   514,
     527,   532,   538,   550,   556,   562,   568,   575,   581,   588,
     595,   603,   611,   621,   625,   635,   656,   661,   667,   684,
     692,   700,   708,   716,   724,   737,   743,   749,   759,   782,
     786,   805,   811,   821,   826,   843,   860,   906,   914,   923,
     929,   936,   943,   950,   961,   969,   978,   984,   991,   998,
    1005,  1012,  1022,  1027,  1035,  1040,  1049,  1055,  1064,  1071,
    1084,  1088,  1099,  1105,  1115,  1122,  1134,  1136,  1145,  1156,
    1176,  1178,  1187,  1198,  1219,  1243,  1253,  1263,  1275,  1277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE_TOK", "PROBLEM_TOK", 
  "SITUATION_TOK", "BSITUATION_TOK", "OBJECTS_TOK", "BDOMAIN_TOK", 
  "INIT_TOK", "GOAL_TOK", "METRIC_TOK", "dis_AND_TOK", "dis_NOT_TOK", 
  "NAME", "VARIABLE", "NUM", "LE_TOK", "LEQ_TOK", "EQ_TOK", "GEQ_TOK", 
  "GE_TOK", "MINUS_TOK", "AD_TOK", "MU_TOK", "DI_TOK", 
  "Fdis_ORdis_ALL_TOK", "IMPLY_TOK", "dis_OR_TOK", "dis_EXISTS_TOK", 
  "EITHER_TOK", "OPEN_PAREN", "CLOSE_PAREN", "AT_TOK", "CONSTRAINTS_TOK", 
  "PREFERENCE_TOK", "WITHIN_TOK", "SOMETIME_TOK", "ALWAYS_TOK", 
  "AT_MOST_ONCE_TOK", "SOMETIME_AFTER_TOK", "SOMETIME_BEFORE_TOK", 
  "ALWAYS_WITHIN_TOK", "HOLD_DURING_TOK", "HOLD_AFTER_TOK", 
  "IS_VIOLATED_TOK", "AT_END_TOK", "$accept", "file", 
  "problem_definition", "@1", "problem_name", "base_domain_name", 
  "problem_defs", "objects_def", "init_def", "@2", "goal_def", "@3", 
  "constraints_def", "@4", "pre_GD", "@5", "pref_GD", "pre_GD_star", 
  "pref_con_GD", "@6", "pref_con_GD_star", "con_GD", "con_GD1", 
  "con_GD_star", "metric_def", "adl_goal_description", 
  "adl_goal_description1", "adl_goal_description_star", "init_el_plus", 
  "init_el", "f_exp", "ground_f_exp", "plus_ground_f_exp_plus", 
  "mul_ground_f_exp_plus", "literal_term", "atomic_formula_term", 
  "term_star", "term", "name_plus", "typed_list_name", 
  "typed_list_variable", "predicate", "literal_name", 
  "atomic_formula_name", "name_star", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    47,    48,    48,    50,    49,    51,    52,    53,    53,
      53,    53,    53,    53,    53,    54,    56,    55,    58,    57,
      60,    59,    61,    61,    61,    62,    61,    63,    63,    63,
      64,    64,    65,    66,    65,    65,    65,    65,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    86,    86,
      87,    87,    87,    87,    88,    89,    89,    90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     0,     6,     4,     4,     0,     2,
       2,     2,     2,     2,     2,     4,     0,     5,     0,     5,
       0,     5,     2,     1,     4,     0,     8,     5,     4,     1,
       0,     2,     4,     0,     8,     5,     4,     1,     0,     2,
       1,     4,     7,     4,     4,     4,     5,     4,     5,     5,
       6,     6,     5,     0,     2,     5,     1,     4,     7,     5,
       5,     5,     5,     5,     1,     4,     4,     5,     7,     0,
       2,     1,     2,     1,     8,     5,     4,     1,     4,     4,
       5,     5,     5,     5,     1,     4,     4,     5,     5,     5,
       5,     4,     1,     2,     1,     2,     4,     1,     4,     4,
       0,     2,     1,     1,     1,     2,     0,     5,     4,     2,
       0,     5,     4,     2,     1,     4,     1,     4,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     0,     2,     4,     1,     3,     0,     0,     8,
       0,     0,     0,     0,     5,    12,     9,    10,    11,    14,
      13,     6,   106,     0,    16,    18,     0,    20,   106,     0,
       0,     0,     0,     0,     0,     0,     0,   109,    15,     7,
       0,     0,    71,    73,   116,     0,     0,    23,    29,    64,
      97,    84,     0,     0,     0,     0,    37,   106,   104,     0,
       0,   114,     0,     0,   118,    17,    72,    30,     0,     0,
       0,   100,     0,     0,     0,     0,    69,     0,    22,     0,
     100,    19,   118,     0,     0,     0,     0,     0,    55,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,   108,   105,   106,     0,     0,     0,     0,
       0,     0,   118,     0,     0,     0,     0,    56,     0,    77,
       0,     0,     0,   102,   103,     0,     0,   100,     0,     0,
     110,     0,    69,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,   110,     0,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   115,     0,   118,    76,   119,   117,    24,    31,
      69,     0,    66,    96,   100,     0,     0,     0,     0,     0,
       0,     0,    99,   101,     0,     0,   110,    25,     0,    70,
      65,     0,     0,    28,    98,    85,    86,     0,    92,     0,
      94,     0,     0,    91,    39,    32,    33,     0,    53,     0,
      36,     0,    45,    44,    47,     0,     0,     0,     0,     0,
      43,    75,     0,     0,   110,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,   113,     0,    67,
       0,    27,    89,    87,    93,    88,    95,    90,     0,    35,
       0,    53,     0,   110,    46,    48,    49,     0,     0,    52,
       0,    57,     0,    78,    79,     0,     0,     0,     0,   110,
       0,     0,     0,     0,    54,    41,     0,    50,    51,     0,
       0,    81,    80,    82,    83,   112,   110,     0,    68,     0,
       0,    74,     0,   111,    26,    34,     0,    58,    42
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,     7,     9,    15,    11,    16,    17,    31,
      18,    32,    19,    34,    46,   238,    47,   114,   144,   248,
     145,   149,    56,   252,    20,   132,   117,   133,    41,    42,
     121,    53,   199,   201,    49,    50,   126,   127,    59,    29,
     187,    64,    43,    44,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const short yypact[] =
{
     -20,    15,    16,   -20,  -125,  -125,  -125,    -8,    33,  -125,
      34,   -17,    41,    47,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,    36,    65,  -125,  -125,    84,  -125,   127,    77,
      91,    98,   117,    76,   128,   144,   147,  -125,  -125,  -125,
      53,    13,  -125,  -125,  -125,   171,   135,  -125,  -125,  -125,
    -125,  -125,    38,   137,    75,   141,  -125,    36,   147,   148,
     150,  -125,    11,   155,   165,  -125,  -125,  -125,   156,   139,
     139,    18,   139,   139,   162,   156,   156,   163,  -125,    12,
      61,  -125,   165,    76,    76,    76,    76,   181,  -125,   128,
     170,    37,   180,   156,   156,   156,   156,   156,   188,   189,
     191,   156,  -125,  -125,  -125,    36,   194,   177,   197,   207,
      92,   190,   165,   200,   140,   198,   201,  -125,   202,  -125,
     206,   139,   139,  -125,  -125,   139,   203,    61,   139,   139,
     208,   156,   156,   204,   208,   156,   218,   220,   221,    72,
      76,    76,    76,   222,   128,   223,   208,   225,    96,   226,
    -125,   156,   227,   228,   229,   156,   156,   156,   241,   156,
     230,  -125,  -125,   231,   165,  -125,  -125,  -125,  -125,  -125,
     156,   233,  -125,  -125,    61,   139,   139,   139,   139,   234,
     235,   236,  -125,  -125,   237,   238,   138,  -125,   239,  -125,
    -125,   240,   242,  -125,  -125,  -125,  -125,   243,  -125,   112,
    -125,   114,   244,  -125,  -125,  -125,  -125,   245,   247,   248,
    -125,   249,  -125,  -125,  -125,   250,   251,   156,   156,   252,
    -125,  -125,   253,   254,   208,   255,   134,   139,   139,   139,
    -125,  -125,  -125,  -125,  -125,   224,   147,  -125,   256,  -125,
     156,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   257,  -125,
     205,   247,   258,   208,  -125,  -125,  -125,   259,   260,  -125,
     264,  -125,   261,  -125,  -125,   262,   263,   265,   266,   208,
     267,   117,   268,   128,  -125,  -125,   269,  -125,  -125,   270,
     156,  -125,  -125,  -125,  -125,  -125,   208,   271,  -125,   272,
     247,  -125,   273,  -125,  -125,  -125,   274,  -125,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -125,   293,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -109,  -125,  -125,  -125,   -33,  -125,
      93,   118,   -88,    22,  -125,   -66,   -32,  -124,  -125,   275,
     -51,   -45,  -125,  -125,  -125,   246,   -74,  -125,   -54,   -21,
    -122,   -35,   276,   277,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      48,    55,   116,   150,   104,   169,   137,    37,   189,   131,
      80,     1,   191,   136,    13,    14,     5,   138,     4,   122,
     125,   128,   129,     8,   206,   108,   135,   152,   153,   154,
     155,   156,   123,   124,   119,   160,   103,    10,   139,   140,
     141,   142,   109,   115,    40,    65,   223,   166,    12,   120,
      28,   147,    82,   183,    22,    23,    24,    25,    26,   150,
      83,    84,    85,    86,   237,   188,    60,    61,   148,   192,
     179,   180,    62,    21,   181,   123,   124,   184,   185,    30,
      80,    27,    48,    87,   161,   211,    63,    89,    51,   215,
     216,   217,    51,   219,   197,   198,   200,   202,    33,   222,
     225,    90,   262,    52,   196,    60,    61,    52,   208,    38,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     251,   101,   209,    39,   226,   227,   228,   229,    51,    40,
      51,   276,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    28,   101,    52,   243,    52,   245,   285,    45,    35,
     119,   257,   258,   186,   244,   119,   246,    36,    57,    54,
     235,    58,   287,   251,   293,   120,   264,    81,   236,    88,
     120,    45,   168,   102,   272,   265,   266,   267,   268,   112,
     105,   106,   270,    67,    68,    61,   110,   115,    69,    70,
      71,    72,    73,   130,   134,   143,   151,    74,    75,    76,
      77,   146,   296,    78,   157,   158,    79,   159,    61,   162,
     170,    68,    61,   163,   292,    69,    70,    71,    72,    73,
     174,   164,   165,   186,   171,    75,    76,    77,   175,   176,
     177,   178,   167,   172,   173,   182,   190,   204,   269,    48,
     289,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     193,   101,   194,   195,   203,   205,   148,   218,   210,   212,
     213,   214,   220,   221,   224,   207,   230,   231,   232,   233,
     234,   239,   240,   274,   241,   242,   247,   249,   250,   253,
     279,   254,   255,   256,   259,   260,   261,   263,   271,   273,
     275,   277,   278,   280,   281,   282,     6,   283,   284,   286,
     288,   290,   291,   294,   295,   297,   298,     0,     0,     0,
       0,     0,     0,     0,   118,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,   111
};

static const short yycheck[] =
{
      32,    34,    68,    91,    58,   114,    80,    28,   132,    75,
      45,    31,   134,    79,    31,    32,     0,    82,     3,    70,
      71,    72,    73,    31,   146,    14,    14,    93,    94,    95,
      96,    97,    14,    15,    16,   101,    57,     4,    83,    84,
      85,    86,    31,    31,    31,    32,   170,   112,    14,    31,
      14,    14,    14,   127,     7,     8,     9,    10,    11,   147,
      22,    23,    24,    25,   186,   131,    13,    14,    31,   135,
     121,   122,    19,    32,   125,    14,    15,   128,   129,    14,
     115,    34,   114,    45,   105,   151,    33,    12,    16,   155,
     156,   157,    16,   159,   139,   140,   141,   142,    14,   164,
     174,    26,   224,    31,    32,    13,    14,    31,    12,    32,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
     208,    46,    26,    32,   175,   176,   177,   178,    16,    31,
      16,   253,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    14,    46,    31,    32,    31,    32,   269,    31,    22,
      16,   217,   218,    15,   199,    16,   201,    30,    14,    31,
      22,    14,   271,   251,   286,    31,    32,    32,    30,    32,
      31,    31,    32,    32,   240,   226,   227,   228,   229,    14,
      32,    31,   236,    12,    13,    14,    31,    31,    17,    18,
      19,    20,    21,    31,    31,    14,    16,    26,    27,    28,
      29,    31,   290,    32,    16,    16,    35,    16,    14,    32,
      12,    13,    14,    16,   280,    17,    18,    19,    20,    21,
      14,    14,    32,    15,    26,    27,    28,    29,    22,    23,
      24,    25,    32,    32,    32,    32,    32,   144,    14,   271,
     273,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      32,    46,    32,    32,    32,    32,    31,    16,    32,    32,
      32,    32,    32,    32,    31,   147,    32,    32,    32,    32,
      32,    32,    32,   251,    32,    32,    32,    32,    31,    31,
      16,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,     3,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    31,    48,    49,     3,     0,    48,    50,    31,    51,
       4,    53,    14,    31,    32,    52,    54,    55,    57,    59,
      71,    32,     7,     8,     9,    10,    11,    34,    14,    86,
      14,    56,    58,    14,    60,    22,    30,    86,    32,    32,
      31,    75,    76,    89,    90,    31,    61,    63,    73,    81,
      82,    16,    31,    78,    31,    65,    69,    14,    14,    85,
      13,    14,    19,    33,    88,    32,    76,    12,    13,    17,
      18,    19,    20,    21,    26,    27,    28,    29,    32,    35,
      88,    32,    14,    22,    23,    24,    25,    45,    32,    12,
      26,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    46,    32,    86,    85,    32,    31,    90,    14,    31,
      31,    89,    14,    91,    64,    31,    72,    73,    82,    16,
      31,    77,    77,    14,    15,    77,    83,    84,    77,    77,
      31,    72,    72,    74,    31,    14,    72,    83,    91,    78,
      78,    78,    78,    14,    65,    67,    31,    14,    31,    68,
      69,    16,    72,    72,    72,    72,    72,    16,    16,    16,
      72,    86,    32,    16,    14,    32,    91,    32,    32,    61,
      12,    26,    32,    32,    14,    22,    23,    24,    25,    77,
      77,    77,    32,    83,    77,    77,    15,    87,    72,    74,
      32,    87,    72,    32,    32,    32,    32,    78,    78,    79,
      78,    80,    78,    32,    67,    32,    87,    68,    12,    26,
      32,    72,    32,    32,    32,    72,    72,    72,    16,    72,
      32,    32,    91,    74,    31,    83,    77,    77,    77,    77,
      32,    32,    32,    32,    32,    22,    30,    87,    62,    32,
      32,    32,    32,    32,    78,    32,    78,    32,    66,    32,
      31,    69,    70,    31,    32,    32,    32,    72,    72,    32,
      32,    32,    87,    32,    32,    77,    77,    77,    77,    14,
      85,    32,    72,    32,    70,    32,    87,    32,    32,    16,
      32,    32,    32,    32,    32,    87,    32,    61,    32,    65,
      32,    32,    72,    87,    32,    32,    69,    32,    32
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 4:
#line 207 "scan-fct_pddl.y"
    { 
  dis_fcterr( PROBNAME_dis_EXPECTED, NULL ); 
;}
    break;

  case 5:
#line 211 "scan-fct_pddl.y"
    {  
  dis_gproblem_name = yyvsp[-2].pstring;
  if ( dis_gcmd_line.display_info >= 1 ) {
    printf("\n problem '%s' defined\n", dis_gproblem_name);
  }
;}
    break;

  case 6:
#line 223 "scan-fct_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy(yyval.pstring, yyvsp[-1].string);
;}
    break;

  case 7:
#line 233 "scan-fct_pddl.y"
    { 
  if ( dis_SAME != strcmp(yyvsp[-1].string, dis_gdomain_name) ) {
    dis_fcterr( BADDOMAIN, NULL );
    yyerror();
  }
;}
    break;

  case 15:
#line 269 "scan-fct_pddl.y"
    { 
  dis_gparse_objects = yyvsp[-1].pdis_TypedList;
;}
    break;

  case 16:
#line 278 "scan-fct_pddl.y"
    {
  dis_fcterr( INIFACTS, NULL ); 
;}
    break;

  case 17:
#line 282 "scan-fct_pddl.y"
    {
  dis_gorig_initial_facts = dis_new_dis_PlNode(dis_AND);
  dis_gorig_initial_facts->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 18:
#line 292 "scan-fct_pddl.y"
    { 
  dis_fcterr( GOALDEF, NULL ); 
;}
    break;

  case 19:
#line 297 "scan-fct_pddl.y"
    {
  yyvsp[-1].pdis_PlNode->next = dis_gorig_goal_facts;
  dis_gorig_goal_facts = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 20:
#line 305 "scan-fct_pddl.y"
    {
        dis_opserr( CONSTRAINTLIST_EXPECTED, NULL );
;}
    break;

  case 21:
#line 309 "scan-fct_pddl.y"
    { 
        dis_ConNode *p;
        if (dis_gloaded_constraints)
        {
                for (p=dis_gloaded_constraints;p->next;p=p->next)
                        ;
                p->next = yyvsp[-1].pdis_ConNode;
        }
        else
                p = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 22:
#line 324 "scan-fct_pddl.y"
    {
        yyval.pdis_PlNode = NULL;
;}
    break;

  case 23:
#line 329 "scan-fct_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 24:
#line 334 "scan-fct_pddl.y"
    {
        yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
        yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 25:
#line 341 "scan-fct_pddl.y"
    {
  forall_tl = yyvsp[0].pdis_TypedList;
;}
    break;

  case 26:
#line 345 "scan-fct_pddl.y"
    {
 
  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-4].pdis_TypedList; 
  forall_tl = NULL;

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;
 
;}
    break;

  case 27:
#line 361 "scan-fct_pddl.y"
    {
        dis_PrefNode *pref;
        dis_ConNode *con; 
        char temp[128];

	sprintf(temp, "%s%d", yyvsp[-2].string, dis_num_preference);
        pref = new_dis_PrefNode(temp, "GOALS", yyvsp[-2].string);
        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = yyvsp[-1].pdis_PlNode;
        pref->body = con;
        pref->args = copy_dis_TypedList(forall_tl);
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        if (forall_tl)
        	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_TRU);
        else
	        yyval.pdis_PlNode = NULL;
;}
    break;

  case 28:
#line 382 "scan-fct_pddl.y"
    {
        dis_PrefNode *pref;
        dis_ConNode *con;  
        char temp[128];

	sprintf(temp, "ANONYMOUS%d", dis_num_preference);
        pref = new_dis_PrefNode(temp, "GOALS", "ANONYMOUS");
        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = yyvsp[-1].pdis_PlNode;
        pref->body = con;
        pref->args = copy_dis_TypedList(forall_tl);
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        if (forall_tl)
        	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_TRU);
        else
	        yyval.pdis_PlNode = NULL;
;}
    break;

  case 29:
#line 403 "scan-fct_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 30:
#line 411 "scan-fct_pddl.y"
    {
        yyval.pdis_PlNode = NULL;
;}
    break;

  case 31:
#line 416 "scan-fct_pddl.y"
    {
	dis_PlNode *p;
	
	if (yyvsp[-1].pdis_PlNode)
	{
		for (p=yyvsp[-1].pdis_PlNode;p->next;p=p->next)
			;
		p->next = yyvsp[0].pdis_PlNode;
		yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
	}
	else	
		yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 32:
#line 433 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_AND_c_c);
        yyval.pdis_ConNode->sons_c = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 33:
#line 440 "scan-fct_pddl.y"
    {
  forall_tl = yyvsp[0].pdis_TypedList;
;}
    break;

  case 34:
#line 444 "scan-fct_pddl.y"
    { 
  
  dis_ConNode *pln;

        if (yyvsp[-1].pdis_ConNode)
        {
  pln = new_dis_ConNode(dis_ALL_c_c);
  pln->parse_vars = yyvsp[-4].pdis_TypedList;    
  forall_tl = NULL;

  yyval.pdis_ConNode = pln;
  pln->sons_c = yyvsp[-1].pdis_ConNode;
  yyval.pdis_ConNode = pln;
        }  
        else
                yyval.pdis_ConNode = NULL;
;}
    break;

  case 35:
#line 463 "scan-fct_pddl.y"
    {
        dis_PrefNode *pref;
        char temp[128];

	sprintf(temp, "%s%d", yyvsp[-2].string, dis_num_preference);
        pref = new_dis_PrefNode(temp, "CONSTRAINTS", yyvsp[-2].string);
        pref->body = yyvsp[-1].pdis_ConNode;
        pref->args = copy_dis_TypedList(forall_tl);
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref;
        dis_num_preference++;
        yyval.pdis_ConNode = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 36:
#line 478 "scan-fct_pddl.y"
    {
        dis_PrefNode *pref;
        char temp[128];

        sprintf(temp, "ANONYMOUS%d", dis_num_preference);
        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "ANONYMOUS");
        pref->body = yyvsp[-1].pdis_ConNode;
	pref->args = copy_dis_TypedList(forall_tl);        
	pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        yyval.pdis_ConNode = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 37:
#line 493 "scan-fct_pddl.y"
    {
	dis_PrefNode *pref;
        char temp[128];

        sprintf(temp, "CONSTRAINTS%d", dis_num_preference);
        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "CONSTRAINTS");
        pref->body = yyvsp[0].pdis_ConNode;
        pref->args = copy_dis_TypedList(forall_tl);
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref;
        dis_num_preference++;
        yyval.pdis_ConNode = NULL;
;}
    break;

  case 38:
#line 510 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = NULL;
;}
    break;

  case 39:
#line 515 "scan-fct_pddl.y"
    {
        if (yyvsp[-1].pdis_ConNode)
        {
                yyvsp[-1].pdis_ConNode->next = yyvsp[0].pdis_ConNode;
                yyval.pdis_ConNode = yyvsp[-1].pdis_ConNode;
        }
        else
                yyval.pdis_ConNode = yyvsp[0].pdis_ConNode;
;}
    break;

  case 40:
#line 528 "scan-fct_pddl.y"
    {
	yyval.pdis_ConNode = yyvsp[0].pdis_ConNode;
;}
    break;

  case 41:
#line 533 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_AND_c_c);
        yyval.pdis_ConNode->sons_c = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 42:
#line 540 "scan-fct_pddl.y"
    {
        dis_ConNode *pln;
        pln = new_dis_ConNode(dis_ALL_c_c);
        pln->parse_vars = yyvsp[-3].pdis_TypedList;
        yyval.pdis_ConNode = pln;
        pln->sons_c = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 43:
#line 551 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_AT_END_c);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 44:
#line 557 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_ALWAYS_c);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 45:
#line 563 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_SOMETIME_c);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 46:
#line 569 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_WITHIN_c);
        yyval.pdis_ConNode->number = atof(yyvsp[-2].string);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 47:
#line 576 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_AT_MOST_ONCE_c);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 48:
#line 582 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_SOMETIME_AFTER_c);
        yyval.pdis_ConNode->sons = yyvsp[-2].pdis_PlNode;
        yyval.pdis_ConNode->sons2 = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 49:
#line 589 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_SOMETIME_BEFORE_c);
        yyval.pdis_ConNode->sons = yyvsp[-2].pdis_PlNode;
        yyval.pdis_ConNode->sons2 = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 50:
#line 596 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_ALWAYS_WITHIN_c);
        yyval.pdis_ConNode->number = atof(yyvsp[-3].string);
        yyval.pdis_ConNode->sons = yyvsp[-2].pdis_PlNode;  
        yyval.pdis_ConNode->sons2 = yyvsp[-1].pdis_PlNode; 
;}
    break;

  case 51:
#line 604 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_HOLD_DURING_c);
        yyval.pdis_ConNode->number = atof(yyvsp[-3].string);
        yyval.pdis_ConNode->number2 = atof(yyvsp[-2].string);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;   
;}
    break;

  case 52:
#line 612 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = new_dis_ConNode(dis_HOLD_AFTER_c);
        yyval.pdis_ConNode->number = atof(yyvsp[-2].string);
        yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;  
;}
    break;

  case 53:
#line 621 "scan-fct_pddl.y"
    {
        yyval.pdis_ConNode = NULL;
;}
    break;

  case 54:
#line 626 "scan-fct_pddl.y"
    {
	yyval.pdis_ConNode = NULL;
//        $1->next = $2;
//        $$ = $1;
;}
    break;

  case 55:
#line 636 "scan-fct_pddl.y"
    {

  if ( dis_gparse_metric != NULL ) {
    printf("\n\ndouble metric specification!\n\n");
    exit( 1 );
  }

  dis_gparse_optimization = dis_copy_dis_Token(yyvsp[-2].string);
  dis_gparse_metric = yyvsp[-1].pdis_Parsedis_ExpNode;

;}
    break;

  case 56:
#line 657 "scan-fct_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 57:
#line 662 "scan-fct_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 58:
#line 670 "scan-fct_pddl.y"
    { 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-3].pdis_TypedList;

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 59:
#line 685 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = LE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 60:
#line 693 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = LEQ;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 61:
#line 701 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = EQ;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 62:
#line 709 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = GEQ;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 63:
#line 717 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = GE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 64:
#line 725 "scan-fct_pddl.y"
    { 
  if ( sis_negated ) {
    yyval.pdis_PlNode = dis_new_dis_PlNode(dis_NOT);
    yyval.pdis_PlNode->sons = dis_new_dis_PlNode(dis_ATOM);
    yyval.pdis_PlNode->sons->atom = yyvsp[0].pdis_TokenList;
    sis_negated = dis_FALSE;
  } else {
    yyval.pdis_PlNode = dis_new_dis_PlNode(dis_ATOM);
    yyval.pdis_PlNode->atom = yyvsp[0].pdis_TokenList;
  }
;}
    break;

  case 65:
#line 738 "scan-fct_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_OR);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 66:
#line 744 "scan-fct_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_NOT);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 67:
#line 750 "scan-fct_pddl.y"
    { 
  dis_PlNode *np = dis_new_dis_PlNode(dis_NOT);
  np->sons = yyvsp[-2].pdis_PlNode;
  np->next = yyvsp[-1].pdis_PlNode;

  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_OR);
  yyval.pdis_PlNode->sons = np;
;}
    break;

  case 68:
#line 762 "scan-fct_pddl.y"
    { 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_EX);
  pln->parse_vars = yyvsp[-3].pdis_TypedList;

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 69:
#line 782 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = NULL;
;}
    break;

  case 70:
#line 787 "scan-fct_pddl.y"
    {
  yyvsp[-1].pdis_PlNode->next = yyvsp[0].pdis_PlNode;
  yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 71:
#line 806 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 72:
#line 812 "scan-fct_pddl.y"
    {
   yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
   yyval.pdis_PlNode->next = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 73:
#line 822 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 74:
#line 827 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_COMP );
  yyval.pdis_PlNode->comp = EQ;

  yyval.pdis_PlNode->lh = dis_new_dis_Parsedis_ExpNode( FHEAD );
  yyval.pdis_PlNode->lh->atom = dis_new_dis_TokenList();
  yyval.pdis_PlNode->lh->atom->item = dis_new_dis_Token( strlen(yyvsp[-4].string)+1 );
  strcpy( yyval.pdis_PlNode->lh->atom->item, yyvsp[-4].string );
  yyval.pdis_PlNode->lh->atom->next = yyvsp[-3].pdis_TokenList;

  yyval.pdis_PlNode->rh = dis_new_dis_Parsedis_ExpNode( NUMBER );
  yyval.pdis_PlNode->rh->atom = dis_new_dis_TokenList();
  yyval.pdis_PlNode->rh->atom->item = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_PlNode->rh->atom->item, yyvsp[-1].string );
;}
    break;

  case 75:
#line 844 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_COMP );
  yyval.pdis_PlNode->comp = EQ;

  yyval.pdis_PlNode->lh = dis_new_dis_Parsedis_ExpNode( FHEAD );
  yyval.pdis_PlNode->lh->atom = dis_new_dis_TokenList();
  yyval.pdis_PlNode->lh->atom->item = dis_new_dis_Token( strlen(yyvsp[-2].string)+1 );
  strcpy( yyval.pdis_PlNode->lh->atom->item, yyvsp[-2].string );

  yyval.pdis_PlNode->rh = dis_new_dis_Parsedis_ExpNode( NUMBER );
  yyval.pdis_PlNode->rh->atom = dis_new_dis_TokenList();
  yyval.pdis_PlNode->rh->atom->item = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_PlNode->rh->atom->item, yyvsp[-1].string );
;}
    break;

  case 76:
#line 861 "scan-fct_pddl.y"
    {
	int n;
	dis_TimedInitial *til;
	char name[32];
	if (dis_gnum_tils%128 == 0)
	{
		n = (dis_gnum_tils + 128)/128*128;
		dis_gtils = (dis_TimedInitial *) realloc(dis_gtils, sizeof(dis_TimedInitial)*n); 
	}
	til = &dis_gtils[dis_gnum_tils++];
	sscanf(yyvsp[-2].string, "%s %f", name, &(til->time));
	if (yyvsp[-1].pdis_PlNode->connective == dis_NOT)
	{
		til->negated = dis_TRUE;
		til->literal = yyvsp[-1].pdis_PlNode->sons;
	}
	else
	{
		til->negated = dis_FALSE;
		til->literal = yyvsp[-1].pdis_PlNode;
	}
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_TRU);

	sprintf(name, "timed-initial-literals-%d", dis_gnum_tils);
	scur_op = dis_new_dis_Pldis_Operator(name);
	scur_op->effects = dis_new_dis_PlNode(dis_AND);
    scur_op->effects->parse_vars = NULL;
    scur_op->effects->sons = yyvsp[-1].pdis_PlNode;

	scur_op->next = dis_gloaded_ops;
	dis_gloaded_ops = scur_op;
	scur_op = NULL;
;}
    break;

  case 77:
#line 907 "scan-fct_pddl.y"
    { 
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( NUMBER );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[0].string );
;}
    break;

  case 78:
#line 915 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( FHEAD );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[-2].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[-2].string );
  yyval.pdis_Parsedis_ExpNode->atom->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 79:
#line 924 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MINUS );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 80:
#line 930 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( AD );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 81:
#line 937 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( SU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 82:
#line 944 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 83:
#line 951 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( DI );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 84:
#line 962 "scan-fct_pddl.y"
    { 
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( NUMBER );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[0].string );
;}
    break;

  case 85:
#line 970 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( FHEAD );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[-2].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[-2].string );
  yyval.pdis_Parsedis_ExpNode->atom->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 86:
#line 979 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MINUS );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 87:
#line 985 "scan-fct_pddl.y"
    { 
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( AD );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 88:
#line 992 "scan-fct_pddl.y"
    { 
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 89:
#line 999 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( SU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 90:
#line 1006 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( DI );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 91:
#line 1013 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode(VIO);
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token(strlen(yyvsp[-1].string) + 1);
  strcpy(yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[-1].string);
;}
    break;

  case 92:
#line 1023 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = yyvsp[0].pdis_Parsedis_ExpNode;
;}
    break;

  case 93:
#line 1028 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( AD );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-1].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[0].pdis_Parsedis_ExpNode;
;}
    break;

  case 94:
#line 1036 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = yyvsp[0].pdis_Parsedis_ExpNode;
;}
    break;

  case 95:
#line 1041 "scan-fct_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-1].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[0].pdis_Parsedis_ExpNode;
;}
    break;

  case 96:
#line 1050 "scan-fct_pddl.y"
    { 
  yyval.pdis_TokenList = yyvsp[-1].pdis_TokenList;
  sis_negated = dis_TRUE;
;}
    break;

  case 97:
#line 1056 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = yyvsp[0].pdis_TokenList;
;}
    break;

  case 98:
#line 1065 "scan-fct_pddl.y"
    { 
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = yyvsp[-2].pstring;
  yyval.pdis_TokenList->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 99:
#line 1072 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token( 5 );
  yyval.pdis_TokenList->item = "=";
  yyval.pdis_TokenList->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 100:
#line 1084 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = NULL;
;}
    break;

  case 101:
#line 1089 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = yyvsp[-1].pstring;
  yyval.pdis_TokenList->next = yyvsp[0].pdis_TokenList;
;}
    break;

  case 102:
#line 1100 "scan-fct_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token(strlen(yyvsp[0].string) + 1);
  strcpy(yyval.pstring, yyvsp[0].string);
;}
    break;

  case 103:
#line 1106 "scan-fct_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token(strlen(yyvsp[0].string) + 1);
  strcpy(yyval.pstring, yyvsp[0].string);
;}
    break;

  case 104:
#line 1116 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token(strlen(yyvsp[0].string) + 1);
  strcpy(yyval.pdis_TokenList->item, yyvsp[0].string);
;}
    break;

  case 105:
#line 1123 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token(strlen(yyvsp[-1].string) + 1);
  strcpy(yyval.pdis_TokenList->item, yyvsp[-1].string);
  yyval.pdis_TokenList->next = yyvsp[0].pdis_TokenList;
;}
    break;

  case 106:
#line 1134 "scan-fct_pddl.y"
    { yyval.pdis_TypedList = NULL; ;}
    break;

  case 107:
#line 1137 "scan-fct_pddl.y"
    { 
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-4].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-4].string );
  yyval.pdis_TypedList->type = yyvsp[-2].pdis_TokenList;
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 108:
#line 1146 "scan-fct_pddl.y"
    {
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-3].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-3].string );
  yyval.pdis_TypedList->type = dis_new_dis_TokenList();
  yyval.pdis_TypedList->type->item = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_TypedList->type->item, yyvsp[-1].string );
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 109:
#line 1157 "scan-fct_pddl.y"
    {
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-1].string );
  if ( yyvsp[0].pdis_TypedList ) {/* another element (already typed) is following */
    yyval.pdis_TypedList->type = dis_copy_dis_TokenList( yyvsp[0].pdis_TypedList->type );
  } else {/* no further element - it must be an untyped list */
    yyval.pdis_TypedList->type = dis_new_dis_TokenList();
    yyval.pdis_TypedList->type->item = dis_new_dis_Token( strlen(dis_STdis_ANDARD_TYPE)+1 );
    strcpy( yyval.pdis_TypedList->type->item, dis_STdis_ANDARD_TYPE );
  }
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 110:
#line 1176 "scan-fct_pddl.y"
    { yyval.pdis_TypedList = NULL; ;}
    break;

  case 111:
#line 1179 "scan-fct_pddl.y"
    { 
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-4].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-4].string );
  yyval.pdis_TypedList->type = yyvsp[-2].pdis_TokenList;
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 112:
#line 1188 "scan-fct_pddl.y"
    {
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-3].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-3].string );
  yyval.pdis_TypedList->type = dis_new_dis_TokenList();
  yyval.pdis_TypedList->type->item = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_TypedList->type->item, yyvsp[-1].string );
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 113:
#line 1199 "scan-fct_pddl.y"
    {
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-1].string );
  if ( yyvsp[0].pdis_TypedList ) {/* another element (already typed) is following */
    yyval.pdis_TypedList->type = dis_copy_dis_TokenList( yyvsp[0].pdis_TypedList->type );
  } else {/* no further element - it must be an untyped list */
    yyval.pdis_TypedList->type = dis_new_dis_TokenList();
    yyval.pdis_TypedList->type->item = dis_new_dis_Token( strlen(dis_STdis_ANDARD_TYPE)+1 );
    strcpy( yyval.pdis_TypedList->type->item, dis_STdis_ANDARD_TYPE );
  }
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 114:
#line 1220 "scan-fct_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token(strlen(yyvsp[0].string) + 1);
  strcpy(yyval.pstring, yyvsp[0].string);
;}
    break;

  case 115:
#line 1244 "scan-fct_pddl.y"
    { 
  dis_PlNode *tmp;

  tmp = dis_new_dis_PlNode(dis_ATOM);
  tmp->atom = yyvsp[-1].pdis_TokenList;
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_NOT);
  yyval.pdis_PlNode->sons = tmp;
;}
    break;

  case 116:
#line 1254 "scan-fct_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_ATOM);
  yyval.pdis_PlNode->atom = yyvsp[0].pdis_TokenList;
;}
    break;

  case 117:
#line 1264 "scan-fct_pddl.y"
    { 
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = yyvsp[-2].pstring;
  yyval.pdis_TokenList->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 118:
#line 1275 "scan-fct_pddl.y"
    { yyval.pdis_TokenList = NULL; ;}
    break;

  case 119:
#line 1278 "scan-fct_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token(strlen(yyvsp[-1].string) + 1);
  strcpy(yyval.pdis_TokenList->item, yyvsp[-1].string);
  yyval.pdis_TokenList->next = yyvsp[0].pdis_TokenList;
;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 2553 "scan-fct_pddl.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1287 "scan-fct_pddl.y"



#include "lex.dis_fct_pddl.c"


/**********************************************************************
 * Functions
 **********************************************************************/


/* 
 * call	bison -pfct -bscan-fct scan-fct.y
 */
void dis_fcterr( int errno, char *par ) {

  sact_err = errno;

  if ( sact_err_par ) {
    free( sact_err_par );
  }
  if ( par ) {
    sact_err_par = dis_new_dis_Token( strlen(par)+1 );
    strcpy( sact_err_par, par);
  } else {
    sact_err_par = NULL;
  }

}



int yyerror( char *msg )

{
  fflush( stdout );
  fprintf(stderr,"\n%s: syntax error in line %d, '%s':\n", 
	  dis_gact_filename, dis_lineno, yytext );

  if ( sact_err_par ) {
    fprintf(stderr, "%s%s\n", serrmsg[sact_err], sact_err_par );
  } else {
    fprintf(stderr,"%s\n", serrmsg[sact_err] );
  }

  exit( 1 );

}



void dis_load_fct_file( char *filename ) 

{

  FILE *fp;/* pointer to input files */
  char tmp[dis_MAX_LENGTH] = "";

  /* open fact file 
   */
  if( ( fp = fopen( filename, "r" ) ) == NULL ) {
    sprintf(tmp, "\nff: can't find fact file: %s\n\n", filename );
    perror(tmp);
    exit ( 1 );
  }

  dis_gact_filename = filename;
  dis_lineno = 1; 
  yyin = fp;

  yyparse();

  fclose( fp );/* and close file again */

}



