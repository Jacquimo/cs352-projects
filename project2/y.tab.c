/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

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
#line 68 "y.tab.c"

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 1 "parser.y"

struct Value {
	char* type;
	union {
		char* string_val;
		int int_val;
	};
};

struct VariableInstance;
struct ScriptObject;

struct Pair {
	char* name;
	VariableInstance* instance;
};

struct Result {
	bool isObject;
	union {
		Value value;
		ScriptObject* obj;
	};
};

struct Assign {
	bool typeFail;
	Pair* pair;
};



/* Line 387 of yacc.c  */
#line 133 "y.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     ID = 259,
     PLUS = 260,
     MINUS = 261,
     ASSIGN = 262,
     SLASH = 263,
     MULT = 264,
     EQUAL = 265,
     NEWLINE = 266,
     STRING = 267,
     LBRAK = 268,
     RBRAK = 269,
     SCRIPT = 270,
     OPENTAG = 271,
     SEMICOLON = 272,
     OPENPAREN = 273,
     CLOSEPAREN = 274,
     VAR = 275,
     DOCWRITE = 276,
     COMMA = 277,
     COLON = 278,
     OPENCURL = 279,
     CLOSECURL = 280,
     DOT = 281
   };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define MINUS 261
#define ASSIGN 262
#define SLASH 263
#define MULT 264
#define EQUAL 265
#define NEWLINE 266
#define STRING 267
#define LBRAK 268
#define RBRAK 269
#define SCRIPT 270
#define OPENTAG 271
#define SEMICOLON 272
#define OPENPAREN 273
#define CLOSEPAREN 274
#define VAR 275
#define DOCWRITE 276
#define COMMA 277
#define COLON 278
#define OPENCURL 279
#define CLOSECURL 280
#define DOT 281



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 43 "parser.y"

	char* string_val;
	int int_val;
	Value value;
	Pair* fieldVal;
	ScriptObject* obj;
	Result* res;
	Assign* assign;


/* Line 387 of yacc.c  */
#line 211 "y.tab.c"
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
#line 54 "parser.y"

// Include statements and necessary function prototypes
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <typeinfo>
using namespace std;

int yylex();
int yyerror(char*);
extern int yylineno;


/*
 * Global Variables, Constants, and Data Structures
 */

// Constant Values and Basic Functions (defined with preprocessor directives)
// type constants
#define WORD_STRING "string"
#define WORD_INT "int"
#define WORD_TYPE_ERROR "type error"
#define WORD_OBJECT "object"
#define WORD_NO_TYPE "none"

#define UNKNOWN_TYPE_EXPL "Unknown variable type. Likely programmer error."
#define BREAKLINE "<br />"

#define VERBOSE false

// value arbitrarily chosen; more nested scope has larger value
#define OUTER_SCOPE 1

// determines if 2 c language strings are equal
#define streq(A, B) (strcmp(A, B) == 0)

// performs the "write" semantic action of document.write
#define writeToDoc(X) 	{\
							if (streq((X).type, WORD_STRING)) {\
								if (streq((X).string_val, BREAKLINE))\
									printf("\n");\
								else\
									printf("%s", (X).string_val);\
							}\
							else if (streq((X).type, WORD_INT))\
								printf("%d", (X).int_val);\
							else\
								typeError(UNKNOWN_TYPE_EXPL);\
						}

// Global Variables
/*
 * Global scope of the compiler. The most outer scope has the smallest value
 * and is denoted with the OUTER_SCOPE constant. A scope is said to be more
 * nested than another scope if it has a larger scope value.
 */
int scopeLevel = OUTER_SCOPE;

// Data Structures
// Class that represents an instantiated variable and its value based on scope
struct VariableInstance {
	int scope;
	Value value;

	VariableInstance(char* val) {
		this->value.type = WORD_STRING;
		this->scope = scopeLevel;
		this->value.string_val = val;
	}

	VariableInstance(int val) {
		this->value.type = WORD_INT;
		this->scope = scopeLevel;
		this->value.int_val = val;
	}

	VariableInstance() {
		this->value.type = WORD_NO_TYPE;
		this->scope = scopeLevel;
	}

	virtual void addField(Pair* pair) { }
};

/*
 * Class that represents a script object and therefore has a vector of fields.
 * The type of this object will be WORD_OBJECT.
*/
struct ScriptObject: public VariableInstance {
	vector<Pair> fieldlist;

	ScriptObject(vector<Pair>* list) {
		VariableInstance();
		this->value.type = WORD_OBJECT;
		this->fieldlist = *list;
	}

	ScriptObject() {
		ScriptObject(new vector<Pair>());
	}

	// Adds field to list if it doesn't exist, otherwise it updates the value
	void addField(Pair* pair) {
		if (!this->updateField(pair->name, pair->instance))
			fieldlist.push_back(*pair);
	}

	bool updateField(char* name, VariableInstance* instance) {
		for (int i = 0; i < fieldlist.size(); ++i) {
			if (streq(name, fieldlist[i].name)) {
				fieldlist[i].instance = instance;
				return true;
			}
		}

		return false;
	}

	void replaceFields(vector<Pair>* list) {
		this->fieldlist = *list;
	}

	virtual ~ScriptObject() { }
};

// declaring type of symbol table and initializing as global variable
typedef unordered_map <string, vector<VariableInstance> > SymbolTable;
SymbolTable symbolTable;

// Helper functions
void typeError(char* message) {
	/* TODO: implement this function completely. This function should cause the
	 * interpreter to end execution and therefore should never return to its
	 * calling function.
	*/

	char buf[256];
	buf[0] = 0;
	sprintf(buf, "%s: %s | line %d\n", WORD_TYPE_ERROR, message, yylineno);
	printf("%s", buf);

	exit(1);
}


/* Line 390 of yacc.c  */
#line 388 "y.tab.c"

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   65

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNRULES -- Number of states.  */
#define YYNSTATES  78

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

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
      25,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    18,    19,    21,    24,    26,
      28,    30,    32,    33,    39,    42,    45,    49,    53,    55,
      57,    59,    65,    70,    72,    75,    78,    79,    84,    88,
      90,    91,    95,    97,   101,   103,   107,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   126,   129
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      28,     0,    -1,    16,    51,    30,    29,    51,    -1,    13,
       8,    15,    14,    -1,    32,    31,    30,    -1,    -1,    52,
      -1,    17,    51,    -1,    35,    -1,    36,    -1,    43,    -1,
      33,    -1,    -1,    24,    52,    34,    30,    25,    -1,    20,
       4,    -1,    20,    36,    -1,    37,    10,    38,    -1,    37,
      26,     4,    -1,     4,    -1,    45,    -1,    39,    -1,    24,
      52,    40,    51,    25,    -1,    40,    22,    51,    41,    -1,
      41,    -1,     4,    42,    -1,    23,    45,    -1,    -1,    21,
      18,    44,    19,    -1,    44,    22,    45,    -1,    45,    -1,
      -1,    18,    45,    19,    -1,    46,    -1,    45,    50,    45,
      -1,    47,    -1,    45,    49,    45,    -1,    48,    -1,     3,
      -1,     4,    -1,    12,    -1,     8,    -1,     9,    -1,     5,
      -1,     6,    -1,    52,    -1,    -1,    52,    11,    -1,    11,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   208,   208,   211,   214,   215,   218,   219,   222,   223,
     229,   230,   234,   233,   243,   258,   282,   340,   363,   400,
     407,   417,   424,   430,   439,   479,   484,   491,   494,   498,
     502,   506,   510,   517,   564,   571,   599,   606,   613,   653,
     663,   667,   674,   678,   685,   686,   690,   691
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MINUS", "ASSIGN",
  "SLASH", "MULT", "EQUAL", "NEWLINE", "STRING", "LBRAK", "RBRAK",
  "SCRIPT", "OPENTAG", "SEMICOLON", "OPENPAREN", "CLOSEPAREN", "VAR",
  "DOCWRITE", "COMMA", "COLON", "OPENCURL", "CLOSECURL", "DOT", "$accept",
  "script", "closetag", "statements", "delimiter", "action", "scopeChange",
  "$@1", "declaration", "assignment", "varId", "result", "objdec",
  "fieldlist", "field", "fieldAssign", "docwrite", "paramList", "expr",
  "sum", "factor", "term", "bigOp", "smallOp", "emptySpace", "newlines", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    27,    28,    29,    30,    30,    31,    31,    32,    32,
      32,    32,    34,    33,    35,    35,    36,    37,    37,    38,
      38,    39,    40,    40,    41,    42,    42,    43,    44,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     1,     2,     1,     1,
       1,     1,     0,     5,     2,     2,     3,     3,     1,     1,
       1,     5,     4,     1,     2,     2,     0,     4,     3,     1,
       0,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    45,     0,    47,     5,    44,     1,    18,     0,     0,
       0,     0,     0,    11,     8,     9,     0,    10,    46,    14,
      15,    30,    12,     0,    45,    45,     5,     6,     0,     0,
      37,    38,    39,     0,     0,    29,    32,    34,    36,     5,
       0,     2,     7,     4,     0,    16,    20,    19,    17,     0,
      27,     0,    42,    43,    40,    41,     0,     0,     0,     0,
       0,    31,    28,    35,    33,    13,     3,    26,    45,    23,
       0,    24,    45,     0,    25,     0,    21,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    24,    11,    26,    12,    13,    39,    14,    15,
      16,    45,    46,    68,    69,    71,    17,    34,    35,    36,
      37,    38,    56,    57,     4,     5
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -26
static const yytype_int8 yypact[] =
{
      -2,    12,    20,   -26,     9,    13,   -26,   -26,    38,    21,
      12,    34,    35,   -26,   -26,   -26,    -1,   -26,   -26,     2,
     -26,    31,    13,    42,    12,    12,     9,    13,     3,    51,
     -26,   -26,   -26,    31,    -3,    48,   -26,   -26,   -26,     9,
      43,   -26,   -26,   -26,    12,   -26,   -26,    48,   -26,    32,
     -26,    31,   -26,   -26,   -26,   -26,    31,    31,    36,    45,
       6,   -26,    48,    48,    48,   -26,   -26,    37,     0,   -26,
      31,   -26,    12,    39,    48,    58,   -26,   -26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,   -21,   -26,   -26,   -26,   -26,   -26,    55,
     -26,   -26,   -26,   -26,   -10,   -26,   -26,   -26,   -25,   -26,
     -26,   -26,   -26,   -26,   -24,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -19
static const yytype_int8 yytable[] =
{
      41,    42,    22,    47,    27,    43,    30,    31,    49,    28,
      67,     3,   -18,     7,     1,    32,    50,    18,    58,    51,
       6,    33,    72,     3,    18,    29,    62,    44,   -18,     8,
       9,    63,    64,    10,    30,    31,    60,    52,    53,    21,
      54,    55,    19,    32,    73,    74,     3,    23,    75,    33,
      40,    61,    25,    52,    53,    48,    54,    55,    59,    66,
      70,    65,    67,    20,    76,    77
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-26)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      24,    25,    10,    28,    12,    26,     3,     4,    33,    10,
       4,    11,    10,     4,    16,    12,    19,    11,    39,    22,
       0,    18,    22,    11,    11,    26,    51,    24,    26,    20,
      21,    56,    57,    24,     3,     4,    44,     5,     6,    18,
       8,     9,     4,    12,    68,    70,    11,    13,    72,    18,
       8,    19,    17,     5,     6,     4,     8,     9,    15,    14,
      23,    25,     4,     8,    25,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    28,    11,    51,    52,     0,     4,    20,    21,
      24,    30,    32,    33,    35,    36,    37,    43,    11,     4,
      36,    18,    52,    13,    29,    17,    31,    52,    10,    26,
       3,     4,    12,    18,    44,    45,    46,    47,    48,    34,
       8,    51,    51,    30,    24,    38,    39,    45,     4,    45,
      19,    22,     5,     6,     8,     9,    49,    50,    30,    15,
      52,    19,    45,    45,    45,    25,    14,     4,    40,    41,
      23,    42,    22,    51,    45,    51,    25,    41
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
  YYUSE (yytype);
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

  YYUSE (yytype);
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
        case 9:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    {
				// check if there is a type error pushed up from the assignment
				if (!((yyvsp[(1) - (1)].assign)))
					typeError("");
			}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 234 "parser.y"
    {
				scopeLevel++;
			}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    {
				scopeLevel--;
			}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 244 "parser.y"
    {
				// Only reset symbol table entry if it has not been declared
				if (symbolTable.find((yyvsp[(2) - (2)].string_val)) == symbolTable.end()) {
					vector<VariableInstance> vec;
					vec.push_back(*(new VariableInstance()));
					symbolTable[(yyvsp[(2) - (2)].string_val)] = vec;
				} else {
					// if it exists, reset its type
					vector<VariableInstance> vec = symbolTable.at((yyvsp[(2) - (2)].string_val));
					vec[vec.size()-1].value.type = WORD_NO_TYPE;
				}

				//$$ = false; // if it's declared, there can't be a type error
			}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 259 "parser.y"
    {
				Assign* ret = (yyvsp[(2) - (2)].assign);
				ret->typeFail = false; // with the redeclaration, there cannot be a type error

				// add variable to symbol table if it isn't in there already
				if (symbolTable.find(ret->pair->name) == symbolTable.end()) {
					vector<VariableInstance>* vec = new vector<VariableInstance>();
					vec->push_back(*(ret->pair->instance));
					symbolTable[*(new string(ret->pair->name))] = *vec;
				} else {
					
				}

				//$$ = ret;
			}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 283 "parser.y"
    {
				Result* res = (yyvsp[(3) - (3)].res);
				Pair* pair = (yyvsp[(1) - (3)].fieldVal);
				//bool ret = false;
				Assign* ret = new Assign();
				ret->typeFail = false;
				ret->pair = pair;

				if (VERBOSE)
					if (!res->isObject && streq(res->value.type, WORD_INT))
						printf("result val = %d\n", res->value.int_val);

				// check if there is a type error for objects
				ScriptObject* obj = dynamic_cast<ScriptObject*>(pair->instance);

				//fprintf(stdout, "before segfault\n"); fflush(stdout);

				// the changes to the variable instance within the pair need to be reimplemented

				if (obj == NULL) {
					if (res->isObject) {
						//ret = true;
						ret->typeFail = true;

						// assign the variable like its an object, in case it's a re-assignment
						*(pair->instance) = *(res->obj);
					}
					else {
						// the instance must be some kind of scalar
						pair->instance->value = res->value;
					}
				} else {
					if (!res->isObject) { // assign the variable like it's a scalar variable
						//ret = true;
						ret->typeFail = true;

						VariableInstance* var;
						if (streq(res->value.type, WORD_STRING))
							var = new VariableInstance(res->value.string_val);
						else
							var = new VariableInstance(res->value.int_val);

						var->scope = pair->instance->scope; // make sure that the scope doesn't change
						*(pair->instance) = *var;
					}
					else // the instance must be a script object
						*(pair->instance) = *(res->obj);
				}

				// at this point, the Pair object should contain the updated information

				(yyval.assign) = ret;
			}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 341 "parser.y"
    {
				// verify that the variable instance is a script object
				ScriptObject* obj = dynamic_cast<ScriptObject*>((yyvsp[(1) - (3)].fieldVal)->instance);
				if (obj == NULL) {
					yyerror("Non-object variable used as an object.");
					exit(2);
				} else {
					// verify that the field exists
					Pair* ret = NULL;
					for (int i = 0; i < obj->fieldlist.size(); i++) {
						if (streq(obj->fieldlist[i].name, (yyvsp[(3) - (3)].string_val))) {
							ret = &(obj->fieldlist[i]);
							break;
						}
					}

					if (ret == NULL)
						typeError("Field used before it was declared.");

					(yyval.fieldVal) = ret;
				}
			}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 364 "parser.y"
    {
				Pair* ret = new Pair();
				ret->name = (yyvsp[(1) - (1)].string_val);

				// if the ID cannot be found in the symbol table
				if (symbolTable.find((yyvsp[(1) - (1)].string_val)) == symbolTable.end())
					ret->instance = new VariableInstance();
				else {
					// get variable instance with tightest scope
					vector<VariableInstance> vec = symbolTable.at((yyvsp[(1) - (1)].string_val));
					VariableInstance* var = NULL;

					// find first variable instance with valid scope
					while (var == NULL && !vec.empty()) {
						var = &vec.back();
						if (var->scope > scopeLevel) {
							var = NULL;
							vec.pop_back();
						}
					}

					// verify that variable instance has valid value
					/*if (var == NULL || streq(var->value.type, WORD_NO_TYPE))
						typeError((char*)(*(new string("Variable '")) + *(new string($1)) + *(new string("' used before it is declared."))).c_str());*/

					if (vec.empty())
						typeError("Variable used outside of scope.");

					ret->instance = var;
				}

				(yyval.fieldVal) = ret;
			}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 401 "parser.y"
    {
				Result* ret = new Result();
				ret->isObject = false;
				ret->value = (yyvsp[(1) - (1)].value);
				(yyval.res) = ret;
			}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 408 "parser.y"
    {
				Result* ret = new Result();
				ret->isObject = true;
				ret->obj = (yyvsp[(1) - (1)].obj);
				(yyval.res) = ret;
			}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 418 "parser.y"
    {
				(yyval.obj) = (yyvsp[(3) - (5)].obj);
			}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 425 "parser.y"
    {
				ScriptObject* ret = (yyvsp[(1) - (4)].obj);
				ret->addField((yyvsp[(4) - (4)].fieldVal));
				(yyval.obj) = ret;
			}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 431 "parser.y"
    {
				ScriptObject* ret = new ScriptObject();
				ret->addField((yyvsp[(1) - (1)].fieldVal));
				(yyval.obj) = ret;
			}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 440 "parser.y"
    {
				/*
				Pair* ret = new Pair();
				ret->name = $1;
				ret->value = $2;
				$$ = *ret;

				if (VERBOSE) {
					printf("ID = \"%s\"\t Value = ", ret->name);
					if (streq(ret->value.type, WORD_INT))
						printf("%d", ret->value.int_val);
					else if (streq(ret->value.type, WORD_STRING))
						printf("\"%s\"", ret->value.string_val);
					else if (streq(ret->value.type, WORD_NO_TYPE))
						printf("(unassigned)");
					printf("\n");
				}
				*/

				Pair* ret = new Pair();
				ret->name = (yyvsp[(1) - (2)].string_val);
				ret->instance = new VariableInstance();
				ret->instance->value = (yyvsp[(2) - (2)].value);
				(yyval.fieldVal) = ret;

				if (VERBOSE) {
					printf("ID = \"%s\"\t Value = ", ret->name);
					if (streq(ret->instance->value.type, WORD_INT))
						printf("%d", ret->instance->value.int_val);
					else if (streq(ret->instance->value.type, WORD_STRING))
						printf("\"%s\"", ret->instance->value.string_val);
					else if (streq(ret->instance->value.type, WORD_NO_TYPE))
						printf("(unassigned)");
					printf("\n");
				}
			}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 480 "parser.y"
    {
				(yyval.value) = (yyvsp[(2) - (2)].value);
			}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 484 "parser.y"
    {
				Value* ret = new Value();
				ret->type = WORD_NO_TYPE;
				(yyval.value) = *ret;
			}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 495 "parser.y"
    {
				writeToDoc((yyvsp[(3) - (3)].value));
			}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 499 "parser.y"
    {
				writeToDoc((yyvsp[(1) - (1)].value));
			}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 507 "parser.y"
    {
				(yyval.value) = (yyvsp[(2) - (3)].value);
			}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 511 "parser.y"
    {
				(yyval.value) = (yyvsp[(1) - (1)].value);
			}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 518 "parser.y"
    {
				// check that types are the same
				if (!streq((yyvsp[(1) - (3)].value).type, (yyvsp[(3) - (3)].value).type))
					typeError("Variables must be of the same type.");

				// check that if it's a string, it must use '+' operator
				if (streq((yyvsp[(1) - (3)].value).type, WORD_STRING)) {
					if (!streq((yyvsp[(2) - (3)].string_val), "+"))
						typeError("Strings can only use the '+' operator.");

					string concatVal = *(new string((yyvsp[(1) - (3)].value).string_val)) + *(new string ((yyvsp[(3) - (3)].value).string_val));
					//printf("string: %s\n", concatVal.c_str());

					// return the Value object to a higher grammar rule
					Value* val = new Value();
					val->type = WORD_STRING;
					val->string_val = (char*)concatVal.c_str();
					(yyval.value) = *val;

				} else if (streq((yyvsp[(1) - (3)].value).type, WORD_INT)) {
					int first = (yyvsp[(1) - (3)].value).int_val;
					int sec = (yyvsp[(3) - (3)].value).int_val;
					int result = 0;

					switch(*((yyvsp[(2) - (3)].string_val))) {
						case '+':
							result = first + sec;
							break;

						case '-':
							result = first - sec;
							break;
					}

					Value* ret = new Value(); // use new keyword to ensure variable doesn't lose scope
					ret->type = WORD_INT;
					ret->int_val = result;
					(yyval.value) = *ret;

					if (VERBOSE)
						printf("Line %d,\tFirst = %d,\tSecond = %d,\tOperator: '%c',\tResult = %d\n", yylineno, first, sec, *((yyvsp[(2) - (3)].string_val)), result);

				} else {
					typeError(UNKNOWN_TYPE_EXPL);
				}
			}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 565 "parser.y"
    {
				(yyval.value) = (yyvsp[(1) - (1)].value);
			}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 572 "parser.y"
    {
				// only integers can use the "*" and "/" operators
				if (!streq((yyvsp[(1) - (3)].value).type, WORD_INT) || !streq((yyvsp[(3) - (3)].value).type, WORD_INT))
					typeError("Improper operator for variable type.");

				int first = (yyvsp[(1) - (3)].value).int_val;
				int sec = (yyvsp[(3) - (3)].value).int_val;
				int result = 0;

				switch(*((yyvsp[(2) - (3)].string_val))) {
					case '*':
						result = first * sec;
						break;

					case '/':
						result = first / sec;
						break;
				}

				Value* ret = new Value(); // use new keyword to ensure variable doesn't lose scope
				ret->type = WORD_INT;
				ret->int_val = result;
				(yyval.value) = *ret;

				if (VERBOSE)
					printf("Line %d,\tFirst = %d,\tSecond = %d,\tOperator: '%c',\tResult = %d\n", yylineno, first, sec, *((yyvsp[(2) - (3)].string_val)), result);
			}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 600 "parser.y"
    {
				(yyval.value) = (yyvsp[(1) - (1)].value);
			}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 607 "parser.y"
    {
				Value* val = new Value();
				val->type = WORD_INT;
				val->int_val = (yyvsp[(1) - (1)].int_val);
				(yyval.value) = *val;
			}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 614 "parser.y"
    {
				// This ID must represent an already assigned variable, or it's an error

				if (symbolTable.find((yyvsp[(1) - (1)].string_val)) == symbolTable.end() || symbolTable.at((yyvsp[(1) - (1)].string_val)).empty()) {
					typeError((char*)(*(new string("Variable '")) + *(new string((yyvsp[(1) - (1)].string_val))) + *(new string("' used before it is declared."))).c_str());
				}
				else {
					vector<VariableInstance> vec = symbolTable.at((yyvsp[(1) - (1)].string_val));
					VariableInstance* var = NULL;

					// find first variable instance with valid scope
					while (var == NULL && !vec.empty()) {
						var = &vec.back();
						if (var->scope > scopeLevel) {
							var = NULL;
							vec.pop_back();
						}
					}

					// verify that variable instance has valid value
					if (var == NULL || streq(var->value.type, WORD_NO_TYPE))
						typeError((char*)(*(new string("Variable '")) + *(new string((yyvsp[(1) - (1)].string_val))) + *(new string("' used before it is declared."))).c_str());

					if (vec.empty())
						typeError("Variable used outside of scope.");

					// the current instance has the tightest scope possible and has a value
					Value* ret = new Value();
					ret->type = var->value.type;
					if (strcmp(var->value.type, WORD_NO_TYPE) == 0)
						typeError("Variable declared but never assigned.");
					else if (strcmp(var->value.type, WORD_STRING) == 0)
						ret->string_val = strdup(var->value.string_val);
					else
						ret->int_val = var->value.int_val;

					(yyval.value) = *ret;
				}
			}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 654 "parser.y"
    {
				Value* val = new Value();
				val->type = WORD_STRING;
				val->string_val = (yyvsp[(1) - (1)].string_val);
				(yyval.value) = *val;
			}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 664 "parser.y"
    {
				(yyval.string_val) = (yyvsp[(1) - (1)].string_val);
			}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 668 "parser.y"
    {
				(yyval.string_val) = (yyvsp[(1) - (1)].string_val);
			}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 675 "parser.y"
    {
				(yyval.string_val) = (yyvsp[(1) - (1)].string_val);
			}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 679 "parser.y"
    {
				(yyval.string_val) = (yyvsp[(1) - (1)].string_val);
			}
    break;


/* Line 1787 of yacc.c  */
#line 2166 "y.tab.c"
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


/* Line 2050 of yacc.c  */
#line 693 "parser.y"


extern FILE *yyin;
int yyerror(char *s)
{
    fprintf(stdout, "syntax error, line %d\n", yylineno);
		return 0;
}

int main(int argc, char *argv[])
{
    //yydebug = 1;
    if (argc == 2) {
        FILE *file;

        file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stdout, "could not open %s\n", argv[1]);
        } else{
            yyin = file;
            //yyparse() will call yylex()
            yyparse();
        }
    } else{
        fprintf(stdout, "format: ./parser [filename]");
    }
}
