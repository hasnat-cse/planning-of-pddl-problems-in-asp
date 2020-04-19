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
#define yyparse dis_ops_pddlparse
#define yylex   dis_ops_pddllex
#define yyerror dis_ops_pddlerror
#define yylval  dis_ops_pddllval
#define yychar  dis_ops_pddlchar
#define yydebug dis_ops_pddldebug
#define yynerrs dis_ops_pddlnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINE_TOK = 258,
     DOMAIN_TOK = 259,
     REQUIREMENTS_TOK = 260,
     TYPES_TOK = 261,
     EITHER_TOK = 262,
     CONSTANTS_TOK = 263,
     PREDICATES_TOK = 264,
     FUNCTIONS_TOK = 265,
     ACTION_TOK = 266,
     VARS_TOK = 267,
     IMPLIES_TOK = 268,
     PRECONDITION_TOK = 269,
     PARAMETERS_TOK = 270,
     EFFECT_TOK = 271,
     dis_AND_TOK = 272,
     dis_NOT_TOK = 273,
     dis_WHEN_TOK = 274,
     Fdis_ORdis_ALL_TOK = 275,
     IMPLY_TOK = 276,
     dis_OR_TOK = 277,
     dis_EXISTS_TOK = 278,
     LE_TOK = 279,
     LEQ_TOK = 280,
     EQ_TOK = 281,
     GEQ_TOK = 282,
     GE_TOK = 283,
     MINUS_TOK = 284,
     AD_TOK = 285,
     MU_TOK = 286,
     DI_TOK = 287,
     ASSIGN_TOK = 288,
     SCALE_UP_TOK = 289,
     SCALE_DOWN_TOK = 290,
     INCREASE_TOK = 291,
     DECREASE_TOK = 292,
     NAME = 293,
     VARIABLE = 294,
     NUM = 295,
     OPEN_PAREN = 296,
     CLOSE_PAREN = 297,
     CONSTRAINTS_TOK = 298,
     PREFERENCE_TOK = 299,
     WITHIN_TOK = 300,
     SOMETIME_TOK = 301,
     ALWAYS_TOK = 302,
     AT_MOST_ONCE_TOK = 303,
     SOMETIME_AFTER_TOK = 304,
     SOMETIME_BEFORE_TOK = 305,
     ALWAYS_WITHIN_TOK = 306,
     HOLD_DURING_TOK = 307,
     HOLD_AFTER_TOK = 308,
     DERIVED_TOK = 309,
     AT_START = 310,
     AT_END = 311,
     OVER_ALL = 312,
     DURATION_TOK = 313,
     DURATIVE_ACTION_TOK = 314,
     DURATION_VAR_TOK = 315,
     CONDITION_TOK = 316,
     TIME_TOK = 317,
     PLUS_TOK = 318,
     DIV_TOK = 319,
     MUL_TOK = 320,
     UMINUS = 321
   };
#endif
#define DEFINE_TOK 258
#define DOMAIN_TOK 259
#define REQUIREMENTS_TOK 260
#define TYPES_TOK 261
#define EITHER_TOK 262
#define CONSTANTS_TOK 263
#define PREDICATES_TOK 264
#define FUNCTIONS_TOK 265
#define ACTION_TOK 266
#define VARS_TOK 267
#define IMPLIES_TOK 268
#define PRECONDITION_TOK 269
#define PARAMETERS_TOK 270
#define EFFECT_TOK 271
#define dis_AND_TOK 272
#define dis_NOT_TOK 273
#define dis_WHEN_TOK 274
#define Fdis_ORdis_ALL_TOK 275
#define IMPLY_TOK 276
#define dis_OR_TOK 277
#define dis_EXISTS_TOK 278
#define LE_TOK 279
#define LEQ_TOK 280
#define EQ_TOK 281
#define GEQ_TOK 282
#define GE_TOK 283
#define MINUS_TOK 284
#define AD_TOK 285
#define MU_TOK 286
#define DI_TOK 287
#define ASSIGN_TOK 288
#define SCALE_UP_TOK 289
#define SCALE_DOWN_TOK 290
#define INCREASE_TOK 291
#define DECREASE_TOK 292
#define NAME 293
#define VARIABLE 294
#define NUM 295
#define OPEN_PAREN 296
#define CLOSE_PAREN 297
#define CONSTRAINTS_TOK 298
#define PREFERENCE_TOK 299
#define WITHIN_TOK 300
#define SOMETIME_TOK 301
#define ALWAYS_TOK 302
#define AT_MOST_ONCE_TOK 303
#define SOMETIME_AFTER_TOK 304
#define SOMETIME_BEFORE_TOK 305
#define ALWAYS_WITHIN_TOK 306
#define HOLD_DURING_TOK 307
#define HOLD_AFTER_TOK 308
#define DERIVED_TOK 309
#define AT_START 310
#define AT_END 311
#define OVER_ALL 312
#define DURATION_TOK 313
#define DURATIVE_ACTION_TOK 314
#define DURATION_VAR_TOK 315
#define CONDITION_TOK 316
#define TIME_TOK 317
#define PLUS_TOK 318
#define DIV_TOK 319
#define MUL_TOK 320
#define UMINUS 321




/* Copy the first part of user declarations.  */
#line 1 "scan-ops_pddl.y"

#ifdef YYDEBUG
  extern int yydebug=1;
#endif


#include <stdio.h>
#include <string.h> 
#include "dis_ff.h"
#include "dis_memory.h"
#include "dis_parse.h"
#include "lpg.h"
#include "dis_constraints.h"

#ifndef SCAN_ERR
#define SCAN_ERR
#define DOMDEF_dis_EXPECTED            0
#define DOMAIN_dis_EXPECTED            1
#define DOMNAME_dis_EXPECTED           2
#define LBRACKET_dis_EXPECTED          3
#define RBRACKET_dis_EXPECTED          4
#define DOMDEFS_dis_EXPECTED           5
#define REQUIREM_dis_EXPECTED          6
#define TYPEDLIST_dis_EXPECTED         7
#define LITERAL_dis_EXPECTED           8
#define PRECONDDEF_UNCdis_ORRECT       9
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
#define ACTION                    20
#define CONSTRAINTLIST_EXPECTED	  21
#endif


#define dis_NAME_STR "name\0"
#define dis_VARIABLE_STR "variable\0"
#define dis_STdis_ANDARD_TYPE "OBJECT\0"
 

static char *serrmsg[] = {
  "domain definition expected",
  "'domain' expected",
  "domain name expected",
  "'(' expected",
  "')' expected",
  "additional domain definitions expected",
  "requirements (e.g. ':STRIPS') expected",
  "typed list of <%s> expected",
  "literal expected",
  "uncorrect precondition definition",
  "type definition expected",
  "list of constants expected",
  "predicate definition expected",
  "<name> expected",
  "<variable> expected",
  "action functor expected",
  "atomic formula expected",
  "effect definition expected",
  "negated atomic formula expected",
  "requirement %s not dis_supported by this FF version",  
  "action definition is not correct",
  "constraint definition is not correct",
  NULL
};


void dis_opserr( int errno, char *par );


static int sact_err;
static char *sact_err_par = NULL;
static dis_Pldis_Operator *scur_op = NULL, *scur_op1 = NULL;
static dis_Bool sis_negated = dis_FALSE;
static char *preference_pointer = NULL;
static char *preference_pointer1 = NULL;
static dis_TypedList *forall_tl = NULL;
static dis_Parsedis_ExpNode *duration_exp = NULL;

int dis_supported( char *str )

{

  int i;
	/* derived predicates */
	/* timed initial literals */
  char * sup[] = { ":STRIPS", ":TYPING", ":NEGATIVE-PRECONDITIONS",
		   ":DISJUNCTIVE-PRECONDITIONS", ":EQUALITY", 
		   ":EXISTENTIAL-PRECONDITIONS", ":UNIVERSAL-PRECONDITIONS", 
		   ":QUANTIFIED-PRECONDITIONS", ":CONDITIONAL-EFFECTS", 
		   ":FLUENTS", ":ADL", ":DURATIVE-ACTIONS", 
		   ":DERIVED-PREDICATES", ":TIMED-INITIAL-LITERALS", 
		   ":PREFERENCES", ":CONSTRAINTS", NULL };    

  for (i=0; NULL != sup[i]; i++) {
    if ( SAME == strcmp(sup[i], str) ) {
	switch(i)
	{
	case 2:
		GpG.is_negative = TRUE;
		break;
	case 3:
		GpG.is_disjunctive = TRUE;
		break;
	case 4:
		GpG.is_equality = TRUE;
		break;
	case 5:
		GpG.is_existential = TRUE;
		break;
	case 6:
		GpG.is_universal = TRUE;
		break;
	case 7:
		GpG.is_existential = GpG.is_universal = TRUE;
		break;
	case 8:
		GpG.is_conditional = TRUE;
		break;
	case 9:
		GpG.is_fluents = TRUE;
		break;
	case 10:
		GpG.is_negative = GpG.is_disjunctive = GpG.is_equality = 
		GpG.is_conditional = TRUE;
		break;
	case 11:
		GpG.is_durative = TRUE;
		break;
	case 12:
		GpG.is_deripred = TRUE;
		break;
	case 13:
		GpG.is_til = TRUE;
		break;
	case 14:
		GpG.is_preferences = TRUE;
		break;
	case 15:
		GpG.is_constraints = TRUE;
		break;
	}
      return dis_TRUE;
    }
  }
  return dis_FALSE;

}



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
#line 162 "scan-ops_pddl.y"
typedef union YYSTYPE {

  char string[dis_MAX_LENGTH];
  char *pstring;
  dis_Parsedis_ExpNode *pdis_Parsedis_ExpNode;
  dis_PlNode *pdis_PlNode;
  dis_FactList *pdis_FactList;
  dis_TokenList *pdis_TokenList;
  dis_TypedList *pdis_TypedList;
  /* PDDL 3 */
  dis_ConNode *pdis_ConNode;
  
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 387 "scan-ops_pddl.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 399 "scan-ops_pddl.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   532

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  76
/* YYNRULES -- Number of rules. */
#define YYNRULES  188
/* YYNRULES -- Number of states. */
#define YYNSTATES  511

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    67,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    14,    19,    21,    24,
      27,    30,    33,    36,    39,    42,    45,    48,    49,    55,
      56,    57,    64,    65,    71,    72,    73,    80,    81,    82,
      90,    91,    98,    99,   100,   104,   107,   108,   114,   115,
     121,   122,   128,   130,   135,   136,   145,   150,   155,   160,
     166,   171,   177,   183,   190,   197,   203,   204,   207,   208,
     209,   218,   219,   224,   225,   231,   232,   237,   238,   243,
     246,   248,   253,   261,   262,   265,   271,   276,   278,   287,
     289,   294,   302,   308,   314,   320,   326,   332,   334,   339,
     344,   350,   358,   359,   362,   368,   374,   380,   386,   392,
     394,   399,   407,   413,   414,   417,   422,   424,   426,   428,
     433,   439,   445,   451,   457,   462,   464,   469,   474,   475,
     478,   480,   482,   484,   487,   489,   490,   496,   501,   504,
     505,   511,   516,   519,   520,   521,   530,   531,   532,   541,
     544,   546,   551,   559,   560,   563,   569,   574,   576,   578,
     583,   585,   588,   593,   598,   603,   609,   612,   617,   619,
     627,   633,   639,   645,   651,   657,   663,   665,   668,   673,
     678,   683,   688,   694,   700,   706,   712,   718,   724,   730,
     736,   742,   748,   754,   759,   761,   763,   769,   775
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      69,     0,    -1,    -1,    70,    71,    -1,    -1,    41,     3,
      73,    72,    74,    -1,    41,     4,    38,    42,    -1,    42,
      -1,    83,    74,    -1,    91,    74,    -1,    89,    74,    -1,
      75,    74,    -1,    79,    74,    -1,    99,    74,    -1,   125,
      74,    -1,   109,    74,    -1,    93,    74,    -1,    -1,    41,
       9,    77,    76,    42,    -1,    -1,    -1,    41,    38,   124,
      42,    78,    77,    -1,    -1,    41,    10,    81,    80,    42,
      -1,    -1,    -1,    41,    38,   124,    42,    82,    81,    -1,
      -1,    -1,    41,     5,    84,    38,    85,    87,    42,    -1,
      -1,    41,     5,    86,    43,    87,    42,    -1,    -1,    -1,
      38,    88,    87,    -1,    43,    87,    -1,    -1,    41,     6,
      90,   123,    42,    -1,    -1,    41,     8,    92,   123,    42,
      -1,    -1,    41,    43,    94,    95,    42,    -1,    97,    -1,
      41,    17,    98,    42,    -1,    -1,    41,    20,    41,   124,
      96,    42,    95,    42,    -1,    41,    56,   110,    42,    -1,
      41,    47,   110,    42,    -1,    41,    46,   110,    42,    -1,
      41,    45,    40,   110,    42,    -1,    41,    48,   110,    42,
      -1,    41,    49,   110,   110,    42,    -1,    41,    50,   110,
     110,    42,    -1,    41,    51,    40,   110,   110,    42,    -1,
      41,    52,    40,    40,   110,    42,    -1,    41,    53,    40,
     110,    42,    -1,    -1,    95,    98,    -1,    -1,    -1,    41,
      11,   100,    38,   101,   102,   103,    42,    -1,    -1,    15,
      41,   124,    42,    -1,    -1,    12,    41,   124,    42,   103,
      -1,    -1,    14,   106,   104,   103,    -1,    -1,    16,   113,
     105,   103,    -1,    41,    42,    -1,   108,    -1,    41,    17,
     107,    42,    -1,    41,    20,    41,   124,    42,   106,    42,
      -1,    -1,   106,   107,    -1,    41,    44,    38,   110,    42,
      -1,    41,    44,   110,    42,    -1,   111,    -1,    41,    54,
      41,   122,   124,    42,   110,    42,    -1,   111,    -1,    41,
      17,   112,    42,    -1,    41,    20,    41,   124,    42,   111,
      42,    -1,    41,    24,   116,   116,    42,    -1,    41,    25,
     116,   116,    42,    -1,    41,    26,   116,   116,    42,    -1,
      41,    27,   116,   116,    42,    -1,    41,    28,   116,   116,
      42,    -1,   117,    -1,    41,    22,   112,    42,    -1,    41,
      18,   110,    42,    -1,    41,    21,   110,   110,    42,    -1,
      41,    23,    41,   124,    42,   110,    42,    -1,    -1,   110,
     112,    -1,    41,    33,   115,   116,    42,    -1,    41,    34,
     115,   116,    42,    -1,    41,    35,   115,   116,    42,    -1,
      41,    36,   115,   116,    42,    -1,    41,    37,   115,   116,
      42,    -1,   117,    -1,    41,    17,   114,    42,    -1,    41,
      20,    41,   124,    42,   113,    42,    -1,    41,    19,   110,
     113,    42,    -1,    -1,   113,   114,    -1,    41,    38,   119,
      42,    -1,    38,    -1,    40,    -1,   115,    -1,    41,    29,
     116,    42,    -1,    41,    30,   116,   116,    42,    -1,    41,
      29,   116,   116,    42,    -1,    41,    31,   116,   116,    42,
      -1,    41,    32,   116,   116,    42,    -1,    41,    18,   118,
      42,    -1,   118,    -1,    41,   122,   119,    42,    -1,    41,
      26,   119,    42,    -1,    -1,   120,   119,    -1,    38,    -1,
      39,    -1,    38,    -1,    38,   121,    -1,    38,    -1,    -1,
      38,     7,   121,    42,   123,    -1,    38,    29,    38,   123,
      -1,    38,   123,    -1,    -1,    39,     7,   121,    42,   124,
      -1,    39,    29,    38,   124,    -1,    39,   124,    -1,    -1,
      -1,    41,    59,   126,    38,   127,   102,   128,    42,    -1,
      -1,    -1,    58,   137,   129,    61,   131,   130,    16,   138,
      -1,    41,    42,    -1,   133,    -1,    41,    17,   132,    42,
      -1,    41,    20,    41,   124,    42,   131,    42,    -1,    -1,
     131,   132,    -1,    41,    44,    38,   134,    42,    -1,    41,
      44,   134,    42,    -1,   136,    -1,   136,    -1,    41,    17,
     135,    42,    -1,   136,    -1,   136,   135,    -1,    41,    55,
     110,    42,    -1,    41,    56,   110,    42,    -1,    41,    57,
     110,    42,    -1,    41,    26,    60,   116,    42,    -1,    41,
      42,    -1,    41,    17,   139,    42,    -1,   140,    -1,    41,
      20,    41,   124,    42,   138,    42,    -1,    41,    19,   134,
     140,    42,    -1,    41,    33,   115,   142,    42,    -1,    41,
      34,   115,   142,    42,    -1,    41,    35,   115,   142,    42,
      -1,    41,    36,   115,   142,    42,    -1,    41,    37,   115,
     142,    42,    -1,   140,    -1,   140,   139,    -1,    41,    55,
     113,    42,    -1,    41,    56,   113,    42,    -1,    41,    55,
     141,    42,    -1,    41,    56,   141,    42,    -1,    41,    36,
     115,   143,    42,    -1,    41,    37,   115,   143,    42,    -1,
      41,    33,   115,   142,    42,    -1,    41,    34,   115,   142,
      42,    -1,    41,    35,   115,   142,    42,    -1,    41,    36,
     115,   142,    42,    -1,    41,    37,   115,   142,    42,    -1,
      41,    30,   142,   142,    42,    -1,    41,    29,   142,   142,
      42,    -1,    41,    31,   142,   142,    42,    -1,    41,    32,
     142,   142,    42,    -1,    41,    29,   142,    42,    -1,    60,
      -1,   116,    -1,    41,    67,   116,    62,    42,    -1,    41,
      67,    62,   116,    42,    -1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   291,   291,   291,   302,   301,   315,   325,   327,   329,
     331,   333,   335,   337,   340,   343,   346,   353,   352,   362,
     365,   364,   394,   393,   403,   406,   405,   435,   439,   434,
     448,   447,   459,   463,   462,   471,   481,   480,   494,   493,
     506,   505,   524,   539,   546,   545,   567,   573,   579,   585,
     592,   598,   605,   612,   620,   628,   638,   642,   656,   660,
     655,   708,   712,   725,   728,   749,   748,   755,   754,   762,
     767,   772,   778,   796,   800,   813,   837,   861,   870,   914,
     919,   925,   942,   950,   958,   966,   974,   982,   995,  1001,
    1007,  1017,  1036,  1040,  1052,  1060,  1068,  1076,  1084,  1092,
    1105,  1111,  1126,  1145,  1149,  1161,  1170,  1182,  1190,  1195,
    1201,  1208,  1215,  1222,  1233,  1239,  1248,  1255,  1268,  1270,
    1281,  1287,  1297,  1304,  1315,  1326,  1328,  1338,  1349,  1369,
    1371,  1380,  1391,  1410,  1414,  1409,  1463,  1468,  1462,  1478,
    1483,  1488,  1494,  1512,  1516,  1529,  1553,  1577,  1584,  1590,
    1598,  1603,  1611,  1618,  1625,  1634,  1714,  1718,  1724,  1730,
    1743,  1758,  1766,  1774,  1782,  1790,  1800,  1805,  1813,  1820,
    1827,  1834,  1841,  1849,  1859,  1867,  1875,  1883,  1891,  1901,
    1908,  1915,  1922,  1929,  1935,  1942,  1946,  1953,  1960
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE_TOK", "DOMAIN_TOK", 
  "REQUIREMENTS_TOK", "TYPES_TOK", "EITHER_TOK", "CONSTANTS_TOK", 
  "PREDICATES_TOK", "FUNCTIONS_TOK", "ACTION_TOK", "VARS_TOK", 
  "IMPLIES_TOK", "PRECONDITION_TOK", "PARAMETERS_TOK", "EFFECT_TOK", 
  "dis_AND_TOK", "dis_NOT_TOK", "dis_WHEN_TOK", "Fdis_ORdis_ALL_TOK", 
  "IMPLY_TOK", "dis_OR_TOK", "dis_EXISTS_TOK", "LE_TOK", "LEQ_TOK", 
  "EQ_TOK", "GEQ_TOK", "GE_TOK", "MINUS_TOK", "AD_TOK", "MU_TOK", 
  "DI_TOK", "ASSIGN_TOK", "SCALE_UP_TOK", "SCALE_DOWN_TOK", 
  "INCREASE_TOK", "DECREASE_TOK", "NAME", "VARIABLE", "NUM", "OPEN_PAREN", 
  "CLOSE_PAREN", "CONSTRAINTS_TOK", "PREFERENCE_TOK", "WITHIN_TOK", 
  "SOMETIME_TOK", "ALWAYS_TOK", "AT_MOST_ONCE_TOK", "SOMETIME_AFTER_TOK", 
  "SOMETIME_BEFORE_TOK", "ALWAYS_WITHIN_TOK", "HOLD_DURING_TOK", 
  "HOLD_AFTER_TOK", "DERIVED_TOK", "AT_START", "AT_END", "OVER_ALL", 
  "DURATION_TOK", "DURATIVE_ACTION_TOK", "DURATION_VAR_TOK", 
  "CONDITION_TOK", "TIME_TOK", "PLUS_TOK", "DIV_TOK", "MUL_TOK", "UMINUS", 
  "'*'", "$accept", "file", "@1", "domain_definition", "@2", 
  "domain_name", "optional_domain_defs", "predicates_def", "@3", 
  "predicates_list", "@4", "functions_def", "@5", "functions_list", "@6", 
  "require_def", "@7", "@8", "@9", "require_key_star", "@10", "types_def", 
  "@11", "constants_def", "@12", "constraints_def", "@13", "con_GD", 
  "@14", "con_GD1", "con_GD_star", "action_def", "@15", "@16", 
  "param_def", "action_def_body", "@17", "@18", "pre_GD", "pre_GD_star", 
  "pref_GD", "derived_def", "adl_goal_description", 
  "adl_goal_description1", "adl_goal_description_star", "adl_effect", 
  "adl_effect_star", "f_head", "f_exp", "literal_term", 
  "atomic_formula_term", "term_star", "term", "name_plus", "predicate", 
  "typed_list_name", "typed_list_variable", "durative_action_def", "@19", 
  "@20", "durative_action_def_body", "@21", "@22", "da_GD", "da_GD_star", 
  "pref_timed_GD", "da_adl_goal_description", 
  "timed_adl_goal_description_plus", "timed_adl_goal_description", 
  "duration_constraint", "da_adl_effect", "timed_adl_effect_plus", 
  "timed_adl_effect", "f_assign_da", "f_exp_da", "f_exp_t", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    68,    70,    69,    72,    71,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    76,    75,    77,
      78,    77,    80,    79,    81,    82,    81,    84,    85,    83,
      86,    83,    87,    88,    87,    87,    90,    89,    92,    91,
      94,    93,    95,    95,    96,    95,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,   100,   101,
      99,   102,   102,   103,   103,   104,   103,   105,   103,   106,
     106,   106,   106,   107,   107,   108,   108,   108,   109,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   123,   123,   123,   123,   124,
     124,   124,   124,   126,   127,   125,   129,   130,   128,   131,
     131,   131,   131,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   136,   136,   136,   137,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   141,   141,   142,
     142,   142,   142,   142,   142,   142,   143,   143,   143
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     0,     5,     4,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     5,     0,
       0,     6,     0,     5,     0,     0,     6,     0,     0,     7,
       0,     6,     0,     0,     3,     2,     0,     5,     0,     5,
       0,     5,     1,     4,     0,     8,     4,     4,     4,     5,
       4,     5,     5,     6,     6,     5,     0,     2,     0,     0,
       8,     0,     4,     0,     5,     0,     4,     0,     4,     2,
       1,     4,     7,     0,     2,     5,     4,     1,     8,     1,
       4,     7,     5,     5,     5,     5,     5,     1,     4,     4,
       5,     7,     0,     2,     5,     5,     5,     5,     5,     1,
       4,     7,     5,     0,     2,     4,     1,     1,     1,     4,
       5,     5,     5,     5,     4,     1,     4,     4,     0,     2,
       1,     1,     1,     2,     1,     0,     5,     4,     2,     0,
       5,     4,     2,     0,     0,     8,     0,     0,     8,     2,
       1,     4,     7,     0,     2,     5,     4,     1,     1,     4,
       1,     2,     4,     4,     4,     5,     2,     4,     1,     7,
       5,     5,     5,     5,     5,     5,     1,     2,     4,     4,
       4,     4,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     4,     1,     1,     5,     5,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     0,     4,     0,
       0,     0,     0,     7,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,    27,    36,    38,    19,    24,
      58,    40,     0,   133,    11,    12,     8,    10,     9,    16,
      13,    15,    14,     0,     0,   125,   125,     0,    17,     0,
      22,     0,     0,     0,     0,    28,    32,   125,     0,     0,
     129,     0,   129,     0,    59,     0,     0,    42,   124,   129,
     134,    32,    33,    32,     0,     0,     0,   128,    37,    39,
     129,     0,    18,     0,    23,    61,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
      61,     0,    32,    35,    31,   122,     0,   125,     0,     0,
     132,    20,    25,     0,    63,    56,     0,   129,     0,     0,
       0,    79,    87,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    34,   123,   125,   127,     0,
     129,    19,    24,   129,     0,     0,     0,     0,    57,    43,
      44,     0,    92,     0,     0,     0,    92,     0,     0,     0,
     118,     0,     0,   118,    48,    47,    50,     0,     0,     0,
       0,     0,    46,     0,     0,     0,   126,   129,   131,    21,
      26,     0,   129,     0,    65,    70,    77,     0,    67,    99,
      60,     0,    49,    92,     0,     0,     0,   129,     0,     0,
     129,   106,   107,     0,   108,     0,     0,   106,   121,     0,
       0,   118,     0,     0,   120,     0,    51,    52,     0,     0,
      55,    78,     0,   136,   135,   130,    62,     0,    73,     0,
      69,     0,    63,   103,     0,     0,     0,   118,     0,     0,
       0,     0,     0,    63,     0,    93,    80,    89,   114,     0,
       0,    88,     0,     0,     0,     0,     0,   118,     0,     0,
       0,   117,   119,     0,     0,   116,    53,    54,     0,     0,
      63,    73,     0,   129,     0,     0,    66,   103,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,     0,    68,
       0,     0,    90,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,     0,     0,    64,    74,    71,     0,
       0,    76,   104,   100,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,   109,     0,     0,     0,     0,
     105,     0,     0,   137,   140,   147,     0,    75,   102,     0,
      94,    95,    96,    97,    98,    81,    91,   111,   110,   112,
     113,   155,   143,     0,   139,     0,     0,     0,     0,     0,
       0,     0,   143,     0,   129,     0,     0,     0,   148,     0,
       0,     0,     0,    72,   101,   144,   141,     0,     0,     0,
     146,   152,   153,   154,     0,   138,   158,     0,   145,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,   149,   151,     0,     0,   166,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,   157,   167,     0,     0,     0,   184,
     185,     0,     0,     0,     0,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,   170,   169,   171,     0,
       0,   160,     0,     0,     0,     0,     0,   161,   162,   163,
       0,   164,   172,   165,   173,     0,     0,     0,     0,     0,
       0,     0,   185,     0,   185,     0,   185,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   183,     0,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   180,   179,   181,   182,   187,
     186
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     5,    10,     8,    14,    15,    61,    48,
     141,    16,    63,    50,   142,    17,    43,    71,    44,    74,
     102,    18,    45,    19,    46,    20,    52,   115,   191,    67,
     116,    21,    51,    85,   114,   147,   232,   243,   271,   272,
     185,    22,   193,   121,   194,   277,   278,   204,   430,   122,
     123,   210,   211,   106,   163,    58,    81,    23,    54,   100,
     175,   269,   359,   362,   363,   334,   367,   390,   335,   223,
     385,   407,   386,   418,   431,   437
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -410
static const short yypact[] =
{
    -410,    12,    22,  -410,    53,  -410,    31,    79,  -410,    74,
     142,    43,    37,  -410,  -410,   142,   142,   142,   142,   142,
     142,   142,   142,   142,  -410,    71,  -410,  -410,    88,    93,
    -410,  -410,   105,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,    84,   114,   110,   110,   131,  -410,   160,
    -410,   176,   151,   184,   186,  -410,    15,    28,   193,   195,
     187,   201,   187,   202,  -410,   221,   212,  -410,  -410,   187,
    -410,    15,  -410,    15,   217,   190,   223,  -410,  -410,  -410,
      47,   234,  -410,   238,  -410,   275,   151,   260,   266,   271,
     271,   271,   271,   271,   267,   273,   274,   271,  -410,   284,
     275,   286,    15,  -410,  -410,   190,   288,   110,   190,   294,
    -410,  -410,  -410,   306,    76,   151,   307,   187,   271,   261,
     313,  -410,  -410,  -410,   314,   327,   271,   271,   271,   330,
     271,   329,   271,   321,  -410,  -410,  -410,   110,  -410,   338,
     187,    88,    93,   187,   345,   359,   360,   339,  -410,  -410,
    -410,   361,   271,   271,   363,   271,   271,   365,   120,   120,
     257,   120,   120,   169,  -410,  -410,  -410,   366,   367,   271,
     271,   368,  -410,   369,   377,   378,  -410,   187,  -410,  -410,
    -410,   380,   187,   340,  -410,  -410,  -410,   357,  -410,  -410,
    -410,   381,  -410,   271,   382,   383,   384,   187,   271,   385,
     187,  -410,  -410,   262,  -410,   120,   120,    82,  -410,   120,
     386,   169,   120,   120,  -410,   387,  -410,  -410,   388,   389,
    -410,  -410,   376,  -410,  -410,  -410,  -410,   390,   359,   392,
    -410,   135,    76,   360,   393,   271,   394,   169,   159,   159,
     159,   159,   159,    76,   151,  -410,  -410,  -410,  -410,   395,
     396,  -410,   397,   120,   120,   120,   120,   169,   398,   399,
     400,  -410,  -410,   401,   402,  -410,  -410,  -410,   391,   346,
      76,   359,   403,   187,   271,   404,  -410,   360,   405,    81,
     384,   360,   187,   410,   120,   120,   120,   120,   120,  -410,
     407,   409,  -410,   271,   347,   120,   120,   120,   411,  -410,
    -410,  -410,  -410,  -410,   120,   413,  -410,  -410,  -410,   414,
     415,  -410,  -410,  -410,   416,   417,   418,   419,   420,   421,
     422,  -410,   224,   423,   424,  -410,   425,   426,   427,   428,
    -410,   429,   111,  -410,  -410,  -410,   359,  -410,  -410,   360,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,   413,   431,  -410,   198,   271,   271,   271,   436,
     432,   433,   413,   434,   187,   437,    -6,   435,  -410,   438,
     439,   440,   442,  -410,  -410,  -410,  -410,   443,   444,   446,
    -410,  -410,  -410,  -410,   317,  -410,  -410,   413,  -410,   -34,
     447,   446,   449,   437,   450,   159,   159,   159,   159,   159,
    -410,   451,   451,   452,  -410,  -410,   154,   453,   449,   449,
     187,   215,   215,   215,    65,    65,   379,   454,   455,   456,
     457,  -410,   159,   159,  -410,  -410,   458,   459,   287,  -410,
    -410,   460,   461,   462,    -5,  -410,   463,   464,   465,   466,
     159,   159,   159,   159,   159,  -410,  -410,  -410,  -410,    85,
      85,  -410,   442,   215,   215,   215,   215,  -410,  -410,  -410,
     134,  -410,  -410,  -410,  -410,   215,   215,   215,   215,   215,
     352,   467,   347,   139,   120,   215,   120,   215,   120,   215,
     120,   374,   418,   468,   419,   469,   420,   470,   421,   471,
     422,   472,  -410,  -410,   473,   474,   475,   476,   477,   478,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -410,  -410,  -410,  -410,  -410,  -410,   323,  -410,  -410,   280,
    -410,  -410,  -410,   331,  -410,  -410,  -410,  -410,  -410,    11,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,   -51,  -410,  -410,
     364,  -410,  -410,  -410,   355,  -173,  -410,  -410,  -142,   213,
    -410,  -410,   -53,  -135,  -122,  -137,   211,  -210,  -145,  -144,
    -133,  -159,  -410,   155,   479,   -38,   -62,  -410,  -410,  -410,
    -410,  -410,  -410,  -300,   161,  -410,  -270,   102,  -261,  -410,
      69,   116,  -238,   123,  -250,  -409
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -121
static const short yytable[] =
{
      83,    66,   189,   184,   215,   333,   439,    99,    59,   188,
     186,   379,     3,   205,   206,   209,   212,   213,   110,    77,
     196,   356,   357,   358,   453,   454,   455,   456,   284,   285,
     286,   287,   288,   257,   199,    75,   120,   124,   125,   126,
     127,   439,    25,    26,   131,    27,    28,    29,    30,   356,
     357,   358,   262,    72,   108,   150,     6,    76,    73,   276,
     258,   259,   460,     4,   260,   151,    57,   263,   264,   138,
     289,   245,     7,   167,   168,   169,   109,   171,   178,   173,
      31,   181,   101,     9,   103,    24,    80,   403,   144,   189,
     145,    32,   146,   186,   368,   378,    33,   306,   298,   176,
     195,   280,   198,   201,   368,   202,   434,   237,   294,   295,
     296,   297,    11,   135,   -30,   225,   218,   219,   391,    68,
     227,  -120,    55,   409,  -120,   429,   470,   435,   352,    47,
     391,   353,   368,   189,    49,   249,   186,   189,   252,   316,
     317,   318,   319,   320,   314,   250,    53,   435,    57,   326,
     327,   328,   329,   354,   408,   355,   323,    56,   201,   331,
     202,   203,   432,   433,   436,   438,   356,   357,   358,    60,
     408,   426,   201,   274,   202,   203,   119,   201,   275,   202,
     428,   493,   281,    12,    13,   411,   412,   413,   414,   415,
     422,   423,    65,   290,   360,   189,   480,   201,    62,   429,
     283,   186,   361,   473,   475,   477,   479,   214,   208,   401,
     402,   309,   449,   450,    64,   483,   485,   487,   489,   491,
     315,   310,    68,   494,    70,   495,    80,   496,   105,   497,
     465,   466,   467,   468,   469,    78,   365,    79,    86,   366,
     324,    87,   153,    82,    84,   155,   156,   157,   158,   159,
     160,   161,   162,   201,    98,   202,   428,   189,   189,   104,
     136,   107,    68,   139,   417,   419,    88,    89,    90,    91,
      92,    93,    94,    95,    96,   429,   111,    97,   152,   153,
     112,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     113,   253,   254,   255,   256,   207,   208,   202,   203,    68,
     257,   117,   377,   369,   370,   371,   118,   128,   472,   474,
     476,   478,   119,   129,   130,   481,   453,   454,   455,   456,
     482,   484,   486,   488,   490,   257,   132,   326,   134,   327,
     137,   328,   140,   329,   392,   498,   393,   394,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   143,   427,   149,
     395,   396,   397,   398,   399,   164,   165,   228,   153,   400,
     229,   155,   156,   157,   158,   159,   160,   161,   162,   166,
     170,   172,   401,   402,   233,   234,   235,   236,    68,   174,
     177,   190,   230,   237,   231,   201,   182,   202,   203,   325,
     238,   239,   240,   241,   242,    68,   233,   234,   235,   236,
     183,   187,   268,   192,   197,   237,   200,   305,   216,   217,
     220,   221,   440,   441,   442,   443,   444,    68,   222,   460,
     224,   179,   226,   244,   246,   247,   248,   251,   261,   265,
     266,   267,   270,   273,   279,   282,   499,   291,   292,   293,
     299,   300,   301,   302,   303,   308,   311,   313,   257,   321,
     322,   304,   372,   330,   332,   133,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   364,   180,   373,   374,   376,   380,   366,   148,
     381,   382,   383,   384,   307,   387,   388,   389,   312,   404,
     406,   410,   416,   405,   421,   424,   445,   446,   447,   448,
     451,   452,   457,   458,   459,   461,   462,   463,   464,   492,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   471,     0,   375,   425,   420,     0,     0,     0,     0,
       0,     0,    69
};

static const short yycheck[] =
{
      62,    52,   146,   145,   163,   305,   415,    69,    46,   146,
     145,    17,     0,   158,   159,   160,   161,   162,    80,    57,
     153,    55,    56,    57,    29,    30,    31,    32,   238,   239,
     240,   241,   242,    38,   156,     7,    89,    90,    91,    92,
      93,   450,     5,     6,    97,     8,     9,    10,    11,    55,
      56,    57,   211,    38,     7,   117,     3,    29,    43,   232,
     205,   206,    67,    41,   209,   118,    38,   212,   213,   107,
     243,   193,    41,   126,   127,   128,    29,   130,   140,   132,
      43,   143,    71,     4,    73,    42,    39,   387,    12,   233,
      14,    54,    16,   228,   355,   365,    59,   270,   257,   137,
     153,   234,   155,    38,   365,    40,    41,    26,   253,   254,
     255,   256,    38,   102,    43,   177,   169,   170,   379,    38,
     182,    39,    38,   393,    42,    60,    41,    62,    17,    41,
     391,    20,   393,   277,    41,   197,   271,   281,   200,   284,
     285,   286,   287,   288,   281,   198,    41,    62,    38,   294,
     295,   296,   297,    42,   392,    44,   291,    43,    38,   304,
      40,    41,   412,   413,   414,   415,    55,    56,    57,    38,
     408,   409,    38,    38,    40,    41,    41,    38,   231,    40,
      41,    42,   235,    41,    42,   395,   396,   397,   398,   399,
      36,    37,    41,   244,   336,   339,    62,    38,    38,    60,
      41,   336,   339,   453,   454,   455,   456,    38,    39,    55,
      56,   273,   422,   423,    38,   465,   466,   467,   468,   469,
     282,   274,    38,   473,    38,   475,    39,   477,    38,   479,
     440,   441,   442,   443,   444,    42,    38,    42,    17,    41,
     293,    20,    18,    42,    42,    21,    22,    23,    24,    25,
      26,    27,    28,    38,    42,    40,    41,   401,   402,    42,
     105,    38,    38,   108,   401,   402,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    60,    42,    56,    17,    18,
      42,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      15,    29,    30,    31,    32,    38,    39,    40,    41,    38,
      38,    41,   364,   356,   357,   358,    40,    40,   453,   454,
     455,   456,    41,    40,    40,   460,    29,    30,    31,    32,
     465,   466,   467,   468,   469,    38,    42,   472,    42,   474,
      42,   476,    38,   478,    17,   480,    19,    20,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    41,   410,    42,
      33,    34,    35,    36,    37,    42,    42,    17,    18,    42,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    42,
      40,    42,    55,    56,    17,    18,    19,    20,    38,    58,
      42,    42,    42,    26,    44,    38,    41,    40,    41,    42,
      33,    34,    35,    36,    37,    38,    17,    18,    19,    20,
      41,    41,    26,    42,    41,    26,    41,    61,    42,    42,
      42,    42,    33,    34,    35,    36,    37,    38,    41,    67,
      42,   141,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    41,    41,    41,    62,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    38,    42,
      41,    60,    16,    42,    41,   100,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    41,   142,    42,    42,    42,    42,    41,   115,
      42,    42,    42,    41,   271,    42,    42,    41,   277,    42,
      41,    41,    41,   391,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,   452,    -1,   362,   408,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    69,    70,     0,    41,    71,     3,    41,    73,     4,
      72,    38,    41,    42,    74,    75,    79,    83,    89,    91,
      93,    99,   109,   125,    42,     5,     6,     8,     9,    10,
      11,    43,    54,    59,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    84,    86,    90,    92,    41,    77,    41,
      81,   100,    94,    41,   126,    38,    43,    38,   123,   123,
      38,    76,    38,    80,    38,    41,    95,    97,    38,   122,
      38,    85,    38,    43,    87,     7,    29,   123,    42,    42,
      39,   124,    42,   124,    42,   101,    17,    20,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    56,    42,   124,
     127,    87,    88,    87,    42,    38,   121,    38,     7,    29,
     124,    42,    42,    15,   102,    95,    98,    41,    40,    41,
     110,   111,   117,   118,   110,   110,   110,   110,    40,    40,
      40,   110,    42,   102,    42,    87,   121,    42,   123,   121,
      38,    78,    82,    41,    12,    14,    16,   103,    98,    42,
     124,   110,    17,    18,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   122,    42,    42,    42,   110,   110,   110,
      40,   110,    42,   110,    58,   128,   123,    42,   124,    77,
      81,   124,    41,    41,   106,   108,   111,    41,   113,   117,
      42,    96,    42,   110,   112,   110,   118,    41,   110,   112,
      41,    38,    40,    41,   115,   116,   116,    38,    39,   116,
     119,   120,   116,   116,    38,   119,    42,    42,   110,   110,
      42,    42,    41,   137,    42,   124,    42,   124,    17,    20,
      42,    44,   104,    17,    18,    19,    20,    26,    33,    34,
      35,    36,    37,   105,    42,   112,    42,    42,    42,   124,
     110,    42,   124,    29,    30,    31,    32,    38,   116,   116,
     116,    42,   119,   116,   116,    42,    42,    42,    26,   129,
      42,   106,   107,    41,    38,   110,   103,   113,   114,    41,
     118,   110,    41,    41,   115,   115,   115,   115,   115,   103,
      95,    42,    42,    42,   116,   116,   116,   116,   119,    42,
      42,    42,    42,    42,    60,    61,   103,   107,    42,   124,
     110,    42,   114,    42,   113,   124,   116,   116,   116,   116,
     116,    42,    41,   111,   110,    42,   116,   116,   116,   116,
      42,   116,    41,   131,   133,   136,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    17,    20,    42,    44,    55,    56,    57,   130,
     106,   113,   131,   132,    41,    38,    41,   134,   136,   110,
     110,   110,    16,    42,    42,   132,    42,   124,   134,    17,
      42,    42,    42,    42,    41,   138,   140,    42,    42,    41,
     135,   136,    17,    19,    20,    33,    34,    35,    36,    37,
      42,    55,    56,   131,    42,   135,    41,   139,   140,   134,
      41,   115,   115,   115,   115,   115,    41,   113,   141,   113,
     141,    42,    36,    37,    42,   139,   140,   124,    41,    60,
     116,   142,   142,   142,    41,    62,   142,   143,   142,   143,
      33,    34,    35,    36,    37,    42,    42,    42,    42,   115,
     115,    42,    42,    29,    30,    31,    32,    42,    42,    42,
      67,    42,    42,    42,    42,   115,   115,   115,   115,   115,
      41,   138,   116,   142,   116,   142,   116,   142,   116,   142,
      62,   116,   116,   142,   116,   142,   116,   142,   116,   142,
     116,   142,    42,    42,   142,   142,   142,   142,   116,    62,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42
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
        case 2:
#line 291 "scan-ops_pddl.y"
    { 
  dis_opserr( DOMDEF_dis_EXPECTED, NULL ); 
;}
    break;

  case 4:
#line 302 "scan-ops_pddl.y"
    { 
;}
    break;

  case 5:
#line 305 "scan-ops_pddl.y"
    {
  if ( dis_gcmd_line.display_info >= 1 ) {
    /*printf("\ndomain '%s' defined\n", dis_gdomain_name);*/
  } 
;}
    break;

  case 6:
#line 316 "scan-ops_pddl.y"
    { 
  dis_gdomain_name = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( dis_gdomain_name, yyvsp[-1].string);
;}
    break;

  case 17:
#line 353 "scan-ops_pddl.y"
    {
;}
    break;

  case 18:
#line 356 "scan-ops_pddl.y"
    { 
;}
    break;

  case 19:
#line 362 "scan-ops_pddl.y"
    {;}
    break;

  case 20:
#line 365 "scan-ops_pddl.y"
    {

  dis_TypedListList *tll;

  if ( dis_gparse_predicates ) {
    tll = dis_gparse_predicates;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = dis_new_dis_TypedListList();
    tll = tll->next;
  } else {
    tll = dis_new_dis_TypedListList();
    dis_gparse_predicates = tll;
  }

  tll->predicate = dis_new_dis_Token( strlen( yyvsp[-2].string ) + 1);
  strcpy( tll->predicate, yyvsp[-2].string );

  tll->args = yyvsp[-1].pdis_TypedList;

;}
    break;

  case 22:
#line 394 "scan-ops_pddl.y"
    {
;}
    break;

  case 23:
#line 397 "scan-ops_pddl.y"
    { 
;}
    break;

  case 24:
#line 403 "scan-ops_pddl.y"
    {;}
    break;

  case 25:
#line 406 "scan-ops_pddl.y"
    {

  dis_TypedListList *tll;

  if ( dis_gparse_functions ) {
    tll = dis_gparse_functions;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = dis_new_dis_TypedListList();
    tll = tll->next;
  } else {
    tll = dis_new_dis_TypedListList();
    dis_gparse_functions = tll;
  }

  tll->predicate = dis_new_dis_Token( strlen( yyvsp[-2].string ) + 1);
  strcpy( tll->predicate, yyvsp[-2].string );

  tll->args = yyvsp[-1].pdis_TypedList;

;}
    break;

  case 27:
#line 435 "scan-ops_pddl.y"
    { 
  dis_opserr( REQUIREM_dis_EXPECTED, NULL ); 
;}
    break;

  case 28:
#line 439 "scan-ops_pddl.y"
    { 
  if ( !dis_supported( yyvsp[0].string ) ) {
    dis_opserr( dis_NOT_SUPPdis_ORTED, yyvsp[0].string );
    yyerror();
  }
;}
    break;

  case 30:
#line 448 "scan-ops_pddl.y"
    { 
  dis_opserr( REQUIREM_dis_EXPECTED, NULL ); 
;}
    break;

  case 31:
#line 452 "scan-ops_pddl.y"
    {
	GpG.is_constraints = TRUE;
;}
    break;

  case 33:
#line 463 "scan-ops_pddl.y"
    { 
  if ( !dis_supported( yyvsp[0].string ) ) {
    dis_opserr( dis_NOT_SUPPdis_ORTED, yyvsp[0].string );
    yyerror();
  }
;}
    break;

  case 35:
#line 472 "scan-ops_pddl.y"
    {
	GpG.is_constraints = TRUE;
;}
    break;

  case 36:
#line 481 "scan-ops_pddl.y"
    { 
  dis_opserr( TYPEDEF_dis_EXPECTED, NULL ); 
;}
    break;

  case 37:
#line 485 "scan-ops_pddl.y"
    {
  dis_gparse_types = yyvsp[-1].pdis_TypedList;
;}
    break;

  case 38:
#line 494 "scan-ops_pddl.y"
    { 
  dis_opserr( CONSTLIST_dis_EXPECTED, NULL ); 
;}
    break;

  case 39:
#line 498 "scan-ops_pddl.y"
    {
  dis_gparse_constants = yyvsp[-1].pdis_TypedList;
;}
    break;

  case 40:
#line 506 "scan-ops_pddl.y"
    {
	dis_opserr( CONSTRAINTLIST_EXPECTED, NULL ); 
;}
    break;

  case 41:
#line 510 "scan-ops_pddl.y"
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

  case 42:
#line 525 "scan-ops_pddl.y"
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

  case 43:
#line 540 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_AND_c_c);  
	yyval.pdis_ConNode->sons_c = yyvsp[-1].pdis_ConNode;
;}
    break;

  case 44:
#line 546 "scan-ops_pddl.y"
    {
	forall_tl = yyvsp[0].pdis_TypedList;
;}
    break;

  case 45:
#line 550 "scan-ops_pddl.y"
    {
	dis_ConNode *pln;
	
	if (yyvsp[-1].pdis_ConNode)
	{
	pln = new_dis_ConNode(dis_ALL_c_c);
	pln->parse_vars = yyvsp[-4].pdis_TypedList;
	forall_tl = NULL;
	yyval.pdis_ConNode = pln;
	pln->sons_c = yyvsp[-1].pdis_ConNode;
	}
	else
		yyval.pdis_ConNode = NULL;
;}
    break;

  case 46:
#line 568 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_AT_END_c);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 47:
#line 574 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_ALWAYS_c);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 48:
#line 580 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_SOMETIME_c);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 49:
#line 586 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_WITHIN_c);
	yyval.pdis_ConNode->number = atof(yyvsp[-2].string);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 50:
#line 593 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_AT_MOST_ONCE_c);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 51:
#line 599 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_SOMETIME_AFTER_c);
	yyval.pdis_ConNode->sons = yyvsp[-2].pdis_PlNode;
	yyval.pdis_ConNode->sons2 = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 52:
#line 606 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_SOMETIME_BEFORE_c);
	yyval.pdis_ConNode->sons = yyvsp[-2].pdis_PlNode;
	yyval.pdis_ConNode->sons2 = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 53:
#line 613 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_ALWAYS_WITHIN_c);
	yyval.pdis_ConNode->number = atof(yyvsp[-3].string);
	yyval.pdis_ConNode->sons = yyvsp[-2].pdis_PlNode;
	yyval.pdis_ConNode->sons2 = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 54:
#line 621 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_HOLD_DURING_c);
	yyval.pdis_ConNode->number = atof(yyvsp[-3].string);
	yyval.pdis_ConNode->number2 = atof(yyvsp[-2].string);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 55:
#line 629 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = new_dis_ConNode(dis_HOLD_AFTER_c);
	yyval.pdis_ConNode->number = atof(yyvsp[-2].string);
	yyval.pdis_ConNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 56:
#line 638 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = NULL;
;}
    break;

  case 57:
#line 643 "scan-ops_pddl.y"
    {
	yyval.pdis_ConNode = NULL;
//	$1->next = $2;
//	$$ = $1;
;}
    break;

  case 58:
#line 656 "scan-ops_pddl.y"
    { 
  dis_opserr( ACTION, NULL ); 
;}
    break;

  case 59:
#line 660 "scan-ops_pddl.y"
    { 
  scur_op = dis_new_dis_Pldis_Operator( yyvsp[0].string );
  preference_pointer = NULL;
;}
    break;

  case 60:
#line 665 "scan-ops_pddl.y"
    {
  dis_PlNode *p;
  char temp[128]; 
  
  if (preference_pointer)
  {
    p = dis_new_dis_PlNode(dis_AND);
    p->sons = dis_new_dis_PlNode(dis_NOT);
    p->sons->sons = dis_new_dis_PlNode(dis_ATOM);
    p->sons->sons->atom = dis_new_dis_TokenList();
    p->sons->sons->atom->item = dis_copy_dis_Token(preference_pointer);
  
    sprintf(temp, "_%s_VIO", preference_pointer1);
    p->sons->next = dis_new_dis_PlNode(dis_NEF);
    p->sons->next->neft = ASSIGN;
    p->sons->next->lh = dis_new_dis_Parsedis_ExpNode( FHEAD ); 
    p->sons->next->lh->atom = dis_new_dis_TokenList();
    p->sons->next->lh->atom->item = dis_copy_dis_Token(temp);
    p->sons->next->rh = dis_new_dis_Parsedis_ExpNode( NUMBER );
    p->sons->next->rh->atom = dis_new_dis_TokenList();
    p->sons->next->rh->atom->item = dis_copy_dis_Token("1");
    p->sons->next->next = copy_dis_PlNode(scur_op->effects);  

    sprintf(temp, "+%s_%s", preference_pointer, scur_op->name);
    scur_op1 = dis_new_dis_Pldis_Operator( temp );
    scur_op1->params = scur_op->params;
    scur_op1->number_of_real_params = scur_op->number_of_real_params;
    scur_op1->parse_params = copy_dis_TypedList(scur_op->parse_params);
    scur_op1->preconds = copy_dis_PlNode(scur_op->preconds);
    scur_op1->effects = p;
    scur_op1->next = dis_gloaded_ops;
    dis_gloaded_ops = scur_op1; 
  }
  scur_op->next = dis_gloaded_ops;
  dis_gloaded_ops = scur_op; 
  scur_op = NULL;
;}
    break;

  case 61:
#line 708 "scan-ops_pddl.y"
    { 
  scur_op->params = NULL; 
;}
    break;

  case 62:
#line 713 "scan-ops_pddl.y"
    {
  dis_TypedList *tl;
  scur_op->parse_params = yyvsp[-1].pdis_TypedList;
  for (tl = scur_op->parse_params; tl; tl = tl->next) {
    /* to be able to distinguish params from :VARS 
     */
    scur_op->number_of_real_params++;
  }
;}
    break;

  case 64:
#line 729 "scan-ops_pddl.y"
    {
  dis_TypedList *tl = NULL;

  /* add vars as parameters 
   */
  if ( scur_op->parse_params ) {
    for( tl = scur_op->parse_params; tl->next; tl = tl->next ) {
      /* empty, get to the end of list 
       */
    }
    tl->next = yyvsp[-2].pdis_TypedList;
    tl = tl->next;
  } else {
    scur_op->parse_params = yyvsp[-2].pdis_TypedList;
  }
;}
    break;

  case 65:
#line 749 "scan-ops_pddl.y"
    { 
  scur_op->preconds = yyvsp[0].pdis_PlNode; 
;}
    break;

  case 67:
#line 755 "scan-ops_pddl.y"
    { 
  scur_op->effects = yyvsp[0].pdis_PlNode; 
;}
    break;

  case 69:
#line 763 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = NULL;
;}
    break;

  case 70:
#line 768 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 71:
#line 773 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
        yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 72:
#line 781 "scan-ops_pddl.y"
    { 
  
  dis_PlNode *pln;
  
  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-3].pdis_TypedList; 

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 73:
#line 796 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = NULL;
;}
    break;

  case 74:
#line 801 "scan-ops_pddl.y"
    {
        if (yyvsp[-1].pdis_PlNode)
        {
                yyvsp[-1].pdis_PlNode->next = yyvsp[0].pdis_PlNode;
                yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
        }
        else
                yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 75:
#line 814 "scan-ops_pddl.y"
    {
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];

        sprintf(temp, "%s%d", yyvsp[-2].string, dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, yyvsp[-2].string);
	else
	        pref = new_dis_PrefNode(temp, "CONSTRAINTS", yyvsp[-2].string);

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = yyvsp[-1].pdis_PlNode;
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
        yyval.pdis_PlNode->value = -1;
;}
    break;

  case 76:
#line 838 "scan-ops_pddl.y"
    {
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];

        sprintf(temp, "ANONYMOUS%d", dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, "ANONYMOUS");
	else
	        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "ANONYMOUS");

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = yyvsp[-1].pdis_PlNode;
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
        yyval.pdis_PlNode->value = -1;
;}
    break;

  case 77:
#line 862 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 78:
#line 872 "scan-ops_pddl.y"
    {
	char temp[200];
	dis_TypedList *tl;
	dis_TokenList *t;
	sprintf(temp, "deripred-%d>%s", ++dis_gnum_deripreds, yyvsp[-4].pstring);
	scur_op = dis_new_dis_Pldis_Operator(temp);

	scur_op->effects = dis_new_dis_PlNode(dis_AND);   
	scur_op->effects->parse_vars = NULL;
	scur_op->effects->next = NULL;    
	scur_op->effects->atom = NULL;
	scur_op->effects->sons = dis_new_dis_PlNode(dis_ATOM);
	scur_op->effects->sons->parse_vars = NULL;
	scur_op->effects->sons->next = NULL;
	scur_op->effects->sons->atom = dis_new_dis_TokenList();
	scur_op->effects->sons->atom->item = yyvsp[-4].pstring;
	scur_op->effects->sons->sons = NULL;

	t = scur_op->effects->sons->atom;
  scur_op->parse_params = yyvsp[-3].pdis_TypedList;
  for (tl = scur_op->parse_params; tl; tl = tl->next) {
    /* to be able to distinguish params from :VARS
     */  
    scur_op->number_of_real_params++;
	t->next = dis_new_dis_TokenList();
	t->next->item = dis_new_dis_Token(strlen(tl->name)+1);
	strcpy(t->next->item, tl->name);
	t = t->next;
  }
	 	
	scur_op->preconds = yyvsp[-1].pdis_PlNode;
	scur_op->next = dis_gloaded_ops;
	dis_gloaded_ops = scur_op; 
;}
    break;

  case 79:
#line 915 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 80:
#line 920 "scan-ops_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 81:
#line 928 "scan-ops_pddl.y"
    { 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-3].pdis_TypedList;

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 82:
#line 943 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = LE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 83:
#line 951 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = LEQ;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 84:
#line 959 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = EQ;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 85:
#line 967 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = GEQ;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 86:
#line 975 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = GE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 87:
#line 983 "scan-ops_pddl.y"
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

  case 88:
#line 996 "scan-ops_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_OR);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 89:
#line 1002 "scan-ops_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_NOT);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 90:
#line 1008 "scan-ops_pddl.y"
    { 
  dis_PlNode *np = dis_new_dis_PlNode(dis_NOT);
  np->sons = yyvsp[-2].pdis_PlNode;
  np->next = yyvsp[-1].pdis_PlNode;

  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_OR);
  yyval.pdis_PlNode->sons = np;
;}
    break;

  case 91:
#line 1020 "scan-ops_pddl.y"
    { 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_EX);
  pln->parse_vars = yyvsp[-3].pdis_TypedList;

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 92:
#line 1036 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = NULL;
;}
    break;

  case 93:
#line 1041 "scan-ops_pddl.y"
    {
  yyvsp[-1].pdis_PlNode->next = yyvsp[0].pdis_PlNode;
  yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 94:
#line 1053 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = ASSIGN;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 95:
#line 1061 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = SCALE_UP;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 96:
#line 1069 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = SCALE_DOWN;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 97:
#line 1077 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = INCREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 98:
#line 1085 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = DECREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 99:
#line 1093 "scan-ops_pddl.y"
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

  case 100:
#line 1106 "scan-ops_pddl.y"
    { 
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 101:
#line 1114 "scan-ops_pddl.y"
    { 

  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-3].pdis_TypedList;

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 102:
#line 1127 "scan-ops_pddl.y"
    {
  /* This will be conditional effects in FF representation, but here
   * a formula like (dis_WHEN p q) will be saved as:
   *  [dis_WHEN]
   *  [sons]
   *   /  \
   * [p]  [q]
   * That means, the first son is p, and the second one is q. 
   */
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_WHEN);
  yyvsp[-2].pdis_PlNode->next = yyvsp[-1].pdis_PlNode;
  yyval.pdis_PlNode->sons = yyvsp[-2].pdis_PlNode;
;}
    break;

  case 103:
#line 1145 "scan-ops_pddl.y"
    { 
  yyval.pdis_PlNode = NULL; 
;}
    break;

  case 104:
#line 1150 "scan-ops_pddl.y"
    {
  yyvsp[-1].pdis_PlNode->next = yyvsp[0].pdis_PlNode;
  yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 105:
#line 1162 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( FHEAD );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[-2].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[-2].string );
  yyval.pdis_Parsedis_ExpNode->atom->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 106:
#line 1171 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( FHEAD );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[0].string );
;}
    break;

  case 107:
#line 1183 "scan-ops_pddl.y"
    { 
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( NUMBER );
  yyval.pdis_Parsedis_ExpNode->atom = dis_new_dis_TokenList();
  yyval.pdis_Parsedis_ExpNode->atom->item = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pdis_Parsedis_ExpNode->atom->item, yyvsp[0].string );
;}
    break;

  case 108:
#line 1191 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = yyvsp[0].pdis_Parsedis_ExpNode;
;}
    break;

  case 109:
#line 1196 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MINUS );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 110:
#line 1202 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( AD );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 111:
#line 1209 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( SU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 112:
#line 1216 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 113:
#line 1223 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( DI );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 114:
#line 1234 "scan-ops_pddl.y"
    { 
  yyval.pdis_TokenList = yyvsp[-1].pdis_TokenList;
  sis_negated = dis_TRUE;
;}
    break;

  case 115:
#line 1240 "scan-ops_pddl.y"
    {
  yyval.pdis_TokenList = yyvsp[0].pdis_TokenList;
;}
    break;

  case 116:
#line 1249 "scan-ops_pddl.y"
    { 
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = yyvsp[-2].pstring;
  yyval.pdis_TokenList->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 117:
#line 1256 "scan-ops_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token( 5 );
  yyval.pdis_TokenList->item = "=";
  yyval.pdis_TokenList->next = yyvsp[-1].pdis_TokenList;
;}
    break;

  case 118:
#line 1268 "scan-ops_pddl.y"
    { yyval.pdis_TokenList = NULL; ;}
    break;

  case 119:
#line 1271 "scan-ops_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = yyvsp[-1].pstring;
  yyval.pdis_TokenList->next = yyvsp[0].pdis_TokenList;
;}
    break;

  case 120:
#line 1282 "scan-ops_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pstring, yyvsp[0].string );
;}
    break;

  case 121:
#line 1288 "scan-ops_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pstring, yyvsp[0].string );
;}
    break;

  case 122:
#line 1298 "scan-ops_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pdis_TokenList->item, yyvsp[0].string );
;}
    break;

  case 123:
#line 1305 "scan-ops_pddl.y"
    {
  yyval.pdis_TokenList = dis_new_dis_TokenList();
  yyval.pdis_TokenList->item = dis_new_dis_Token( strlen(yyvsp[-1].string)+1 );
  strcpy( yyval.pdis_TokenList->item, yyvsp[-1].string );
  yyval.pdis_TokenList->next = yyvsp[0].pdis_TokenList;
;}
    break;

  case 124:
#line 1316 "scan-ops_pddl.y"
    { 
  yyval.pstring = dis_new_dis_Token( strlen(yyvsp[0].string)+1 );
  strcpy( yyval.pstring, yyvsp[0].string );
;}
    break;

  case 125:
#line 1326 "scan-ops_pddl.y"
    { yyval.pdis_TypedList = NULL; ;}
    break;

  case 126:
#line 1329 "scan-ops_pddl.y"
    { 

  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-4].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-4].string );
  yyval.pdis_TypedList->type = yyvsp[-2].pdis_TokenList;
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 127:
#line 1339 "scan-ops_pddl.y"
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

  case 128:
#line 1350 "scan-ops_pddl.y"
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

  case 129:
#line 1369 "scan-ops_pddl.y"
    { yyval.pdis_TypedList = NULL; ;}
    break;

  case 130:
#line 1372 "scan-ops_pddl.y"
    { 
  yyval.pdis_TypedList = dis_new_dis_TypedList();
  yyval.pdis_TypedList->name = dis_new_dis_Token( strlen(yyvsp[-4].string)+1 );
  strcpy( yyval.pdis_TypedList->name, yyvsp[-4].string );
  yyval.pdis_TypedList->type = yyvsp[-2].pdis_TokenList;
  yyval.pdis_TypedList->next = yyvsp[0].pdis_TypedList;
;}
    break;

  case 131:
#line 1381 "scan-ops_pddl.y"
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

  case 132:
#line 1392 "scan-ops_pddl.y"
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

  case 133:
#line 1410 "scan-ops_pddl.y"
    {                  
  dis_opserr( ACTION, NULL );
;}
    break;

  case 134:
#line 1414 "scan-ops_pddl.y"
    {                  
  scur_op = dis_new_dis_Pldis_Operator( yyvsp[0].string );
  preference_pointer = NULL;
;}
    break;

  case 135:
#line 1419 "scan-ops_pddl.y"
    {                  
  char temp[128];
  dis_PlNode *p;
  
  if (preference_pointer)
  {
    p = dis_new_dis_PlNode(dis_AND);
    p->sons = dis_new_dis_PlNode(dis_NOT);
    p->sons->sons = dis_new_dis_PlNode(dis_ATOM);
    p->sons->sons->atom = dis_new_dis_TokenList();
    p->sons->sons->atom->item = dis_copy_dis_Token(preference_pointer);
  
    sprintf(temp, "_%s_VIO", preference_pointer1);
    p->sons->next = dis_new_dis_PlNode(dis_NEF);
    p->sons->next->neft = ASSIGN;
    p->sons->next->lh = dis_new_dis_Parsedis_ExpNode( FHEAD ); 
    p->sons->next->lh->atom = dis_new_dis_TokenList();
    p->sons->next->lh->atom->item = dis_copy_dis_Token(temp);
    p->sons->next->rh = dis_new_dis_Parsedis_ExpNode( NUMBER );
    p->sons->next->rh->atom = dis_new_dis_TokenList();
    p->sons->next->rh->atom->item = dis_copy_dis_Token("1");
    p->sons->next->next = copy_dis_PlNode(scur_op->effects);  

    sprintf(temp, "+%s_%s", preference_pointer, scur_op->name);
    scur_op1 = dis_new_dis_Pldis_Operator( temp );
    scur_op1->params = scur_op->params;
    scur_op1->number_of_real_params = scur_op->number_of_real_params;
    scur_op1->parse_params = copy_dis_TypedList(scur_op->parse_params);
    scur_op1->preconds = copy_dis_PlNode(scur_op->preconds);
    scur_op1->duration = copy_dis_PlNode(scur_op->duration);
    scur_op1->effects = p;
    scur_op1->next = dis_gloaded_ops;
    dis_gloaded_ops = scur_op1; 
    gnum_das++;
  }
  scur_op->next = dis_gloaded_ops;
  dis_gloaded_ops = scur_op;
  scur_op = NULL;
  gnum_das++;
;}
    break;

  case 136:
#line 1463 "scan-ops_pddl.y"
    {                  
	scur_op->duration = yyvsp[0].pdis_PlNode
;}
    break;

  case 137:
#line 1468 "scan-ops_pddl.y"
    {                  
	scur_op->preconds = yyvsp[0].pdis_PlNode;
;}
    break;

  case 138:
#line 1472 "scan-ops_pddl.y"
    {                  
	scur_op->effects = yyvsp[0].pdis_PlNode;
;}
    break;

  case 139:
#line 1479 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = NULL;
;}
    break;

  case 140:
#line 1484 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 141:
#line 1489 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
        yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 142:
#line 1497 "scan-ops_pddl.y"
    { 
  
  dis_PlNode *pln;

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-3].pdis_TypedList; 

  yyval.pdis_PlNode = pln;
  pln->sons = yyvsp[-1].pdis_PlNode;

;}
    break;

  case 143:
#line 1512 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = NULL;
;}
    break;

  case 144:
#line 1517 "scan-ops_pddl.y"
    {
        if (yyvsp[-1].pdis_PlNode)
        {
                yyvsp[-1].pdis_PlNode->next = yyvsp[0].pdis_PlNode;
                yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
        }   
        else
                yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 145:
#line 1530 "scan-ops_pddl.y"
    {
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];

        sprintf(temp, "%s%d", yyvsp[-2].string, dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, yyvsp[-2].string);
	else
	        pref = new_dis_PrefNode(temp,  "CONSTRAINTS", yyvsp[-2].string);

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = yyvsp[-1].pdis_PlNode;  
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref;
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
        yyval.pdis_PlNode->value = -1;
;}
    break;

  case 146:
#line 1554 "scan-ops_pddl.y"
    {
        dis_PrefNode *pref;
        dis_ConNode *con;
        char temp[128];
        
        sprintf(temp, "ANONYMOUS%d", dis_num_preference);
        if (scur_op)
	        pref = new_dis_PrefNode(temp, scur_op->name, "ANONYMOUS");
	else
	        pref = new_dis_PrefNode(temp, "CONSTRAINTS", "ANONYMOUS");

        con = new_dis_ConNode(dis_ATOM_c);
        con->sons = yyvsp[-1].pdis_PlNode;
        pref->body = con;
        pref->next = dis_gloaded_preferences;
        dis_gloaded_preferences = pref; 
        dis_num_preference++;
        preference_pointer = pref->name;
        preference_pointer1 = pref->pname;
        yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
        yyval.pdis_PlNode->value = -1;
;}
    break;

  case 147:
#line 1578 "scan-ops_pddl.y"
    {
        yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;
;}
    break;

  case 148:
#line 1585 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[0].pdis_PlNode;    
;}
    break;

  case 149:
#line 1591 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;    
;}
    break;

  case 150:
#line 1599 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode=yyvsp[0].pdis_PlNode;            
;}
    break;

  case 151:
#line 1604 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;          
  yyval.pdis_PlNode->next = yyvsp[0].pdis_PlNode;    
;}
    break;

  case 152:
#line 1612 "scan-ops_pddl.y"
    {
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AT_START_CONN);                   
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;    
;}
    break;

  case 153:
#line 1619 "scan-ops_pddl.y"
    {                   
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AT_END_CONN);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;    
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 154:
#line 1626 "scan-ops_pddl.y"
    {                   
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_OVER_ALL_CONN);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;    
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 155:
#line 1635 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_COMP);
  yyval.pdis_PlNode->comp = EQ;
  yyval.pdis_PlNode->lh = NULL;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
  duration_exp = copy_dis_Parsedis_ExpNode(yyvsp[-1].pdis_Parsedis_ExpNode);
;}
    break;

  case 156:
#line 1715 "scan-ops_pddl.y"
    {
;}
    break;

  case 157:
#line 1719 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;    
;}
    break;

  case 158:
#line 1725 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AND);
  yyval.pdis_PlNode->sons = yyvsp[0].pdis_PlNode;    
;}
    break;

  case 159:
#line 1733 "scan-ops_pddl.y"
    {                   
  dis_PlNode *pln;      

  pln = dis_new_dis_PlNode(dis_ALL);
  pln->parse_vars = yyvsp[-3].pdis_TypedList;

  yyval.pdis_PlNode = pln;         
  pln->sons = yyvsp[-1].pdis_PlNode;   
;}
    break;

  case 160:
#line 1744 "scan-ops_pddl.y"
    {                   
  /* This will be conditional effects in FF representation, but here
   * a formula like (WHEN p q) will be saved as:
   *  [WHEN]        
   *  [sons]        
   *   /  \         
   * [p]  [q]       
   * That means, the first son is p, and the second one is q.
   */               
  yyval.pdis_PlNode = dis_new_dis_PlNode(dis_WHEN);
  yyvsp[-2].pdis_PlNode->next = yyvsp[-1].pdis_PlNode;    
  yyval.pdis_PlNode->sons = yyvsp[-2].pdis_PlNode;    
;}
    break;

  case 161:
#line 1759 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = ASSIGN;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 162:
#line 1767 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = SCALE_UP;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 163:
#line 1775 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = SCALE_DOWN;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 164:
#line 1783 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = INCREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 165:
#line 1791 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = DECREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 166:
#line 1801 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = yyvsp[0].pdis_PlNode;          
;}
    break;

  case 167:
#line 1806 "scan-ops_pddl.y"
    {                   
  yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;          
  yyval.pdis_PlNode->next = yyvsp[0].pdis_PlNode;    
;}
    break;

  case 168:
#line 1814 "scan-ops_pddl.y"
    {
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AT_START_CONN);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 169:
#line 1821 "scan-ops_pddl.y"
    {
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AT_END_CONN);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 170:
#line 1828 "scan-ops_pddl.y"
    {
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AT_START_CONN);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 171:
#line 1835 "scan-ops_pddl.y"
    {
	yyval.pdis_PlNode = dis_new_dis_PlNode(dis_AT_END_CONN);
  yyval.pdis_PlNode->sons = yyvsp[-1].pdis_PlNode;
	yyval.pdis_PlNode = yyvsp[-1].pdis_PlNode;
;}
    break;

  case 172:
#line 1842 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = INCREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 173:
#line 1850 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = DECREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 174:
#line 1860 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = ASSIGN;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 175:
#line 1868 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = SCALE_UP;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 176:
#line 1876 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = SCALE_DOWN;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 177:
#line 1884 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = INCREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 178:
#line 1892 "scan-ops_pddl.y"
    {
  yyval.pdis_PlNode = dis_new_dis_PlNode( dis_NEF );
  yyval.pdis_PlNode->neft = DECREASE;
  yyval.pdis_PlNode->lh = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_PlNode->rh = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 179:
#line 1902 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( AD );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 180:
#line 1909 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( SU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 181:
#line 1916 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MU );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 182:
#line 1923 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( DI );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
  yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 183:
#line 1930 "scan-ops_pddl.y"
    {
  yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( MINUS );
  yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 184:
#line 1936 "scan-ops_pddl.y"
    {
//	$$ = dis_new_dis_Parsedis_ExpNode( DURATION );
	yyval.pdis_Parsedis_ExpNode = duration_exp;
	duration_exp = NULL;
;}
    break;

  case 186:
#line 1947 "scan-ops_pddl.y"
    {
	yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( EXPT1 );
	yyval.pdis_Parsedis_ExpNode->leftson = yyvsp[-2].pdis_Parsedis_ExpNode;
	yyval.pdis_Parsedis_ExpNode->rightson = NULL;
;}
    break;

  case 187:
#line 1954 "scan-ops_pddl.y"
    {
	yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( EXPT2 );
	yyval.pdis_Parsedis_ExpNode->leftson = NULL;
	yyval.pdis_Parsedis_ExpNode->rightson = yyvsp[-1].pdis_Parsedis_ExpNode;
;}
    break;

  case 188:
#line 1961 "scan-ops_pddl.y"
    {
	yyval.pdis_Parsedis_ExpNode = dis_new_dis_Parsedis_ExpNode( EXPT3 );
	yyval.pdis_Parsedis_ExpNode->leftson = NULL;
	yyval.pdis_Parsedis_ExpNode->rightson = NULL;
;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3463 "scan-ops_pddl.tab.c"

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


#line 1968 "scan-ops_pddl.y"

#include "lex.dis_ops_pddl.c"


/**********************************************************************
 * Functions
 **********************************************************************/

/* 
 * call	bison -pops -bscan-ops scan-ops.y
 */

void dis_opserr( int errno, char *par )

{

  sact_err = errno;

  if ( sact_err_par ) {
    free(sact_err_par);
  }
  if ( par ) {
    sact_err_par = dis_new_dis_Token(strlen(par)+1);
    strcpy(sact_err_par, par);
  } else {
    sact_err_par = NULL;
  }

}
  


int yyerror( char *msg )

{

  fflush(stdout);
  fprintf(stderr, "\n%s: syntax error in line %d, '%s':\n", 
	  dis_gact_filename, dis_lineno, yytext);

  if ( NULL != sact_err_par ) {
    fprintf(stderr, "%s %s\n", serrmsg[sact_err], sact_err_par);
  } else {
    fprintf(stderr, "%s\n", serrmsg[sact_err]);
  }

  exit( 1 );

}



void dis_load_ops_file( char *filename )

{

  FILE * fp;/* pointer to input files */
  char tmp[dis_MAX_LENGTH] = "";

  /* open operator file 
   */
  if( ( fp = fopen( filename, "r" ) ) == NULL ) {
    sprintf(tmp, "\nff: can't find operator file: %s\n\n", filename );
    perror(tmp);
    exit( 1 );
  }

  dis_gact_filename = filename;
  dis_lineno = 1; 
  yyin = fp;

  yyparse();

  fclose( fp );/* and close file again */

}


