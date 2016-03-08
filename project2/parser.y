%code requires {
struct Value {
	char* type;
	union {
		char* string_val;
		int int_val;
	};
};

struct Pair {
	char* name;
	Value value;
};

}

%token <int_val> NUM
%token <string_val> ID PLUS MINUS ASSIGN SLASH MULT EQUAL NEWLINE STRING LBRAK RBRAK SCRIPT OPENTAG SEMICOLON OPENPAREN CLOSEPAREN VAR DOCWRITE COMMA COLON OPENCURL CLOSECURL DOT

%type <value> expr sum factor term fieldAssign
%type <fieldVal> field
%type <string_val> bigOp smallOp emptySpace newlines

%union {
	char* string_val;
	int int_val;
	Value value;
	Pair fieldVal;
}


%{
// Include statements and necessary function prototypes
#include <stdio.h>
#include <string>
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
#define WORD_STRING "string"
#define WORD_INT "int"
#define WORD_NO_TYPE "none"
#define WORD_TYPE_ERROR "type error"
#define UNKNOWN_TYPE_EXPL "Unknown variable type. Likely programmer error."
#define BREAKLINE "<br />"

#define VERBOSE true

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
}

%}



%start script

%%
script		: OPENTAG emptySpace statements closetag emptySpace
        	;

closetag	: LBRAK SLASH SCRIPT RBRAK
			;

statements	: action delimiter statements
			|
			;

delimiter	: newlines
			| SEMICOLON emptySpace
			;

action		: declaration
			| assignment
			| docwrite
			| scopeChange
			;

scopeChange	: OPENCURL newlines
 			{
				scopeLevel++;
			}
			statements CLOSECURL
			{
				scopeLevel--;
			}
			;

declaration	: VAR ID
			{
				// Only reset symbol table entry if it has not been declared
				if (symbolTable.find($2) == symbolTable.end()) {
					vector<VariableInstance> vec;
					vec.push_back(*(new VariableInstance()));
					symbolTable[$2] = vec;
				}
				//$$ = false; // if it's declared, there can't be a type error
			}
			| VAR assignment
			;

assignment	: varId EQUAL result
			;

varId		: varId DOT ID
			| ID
			;

result		: expr
			| objdec
			;

objdec		: OPENCURL newlines fieldlist emptySpace CLOSECURL
			;

fieldlist	: fieldlist COMMA emptySpace field
			| field
			;

/* "field" rule has type Pair */
field		: ID fieldAssign
			{
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
			}
			;

/* "fieldAssign" rule has type Value */
fieldAssign	: COLON expr
			{
				$$ = $2;
			}
			|
			{
				Value* ret = new Value();
				ret->type = WORD_NO_TYPE;
				$$ = *ret;
			}
			;

docwrite	: DOCWRITE OPENPAREN paramList CLOSEPAREN
			;

paramList	: paramList COMMA expr
			{
				writeToDoc($3);
			}
			| expr
			{
				writeToDoc($1);
			}
			|
			;

/* "expr" rule has type Value */
expr		: OPENPAREN expr CLOSEPAREN
			{
				$$ = $2;
			}
			| sum
			{
				$$ = $1;
			}
			;

/* "sum" rule has type Value */
sum			: sum smallOp sum
			{
				// check that types are the same
				if (!streq($1.type, $3.type))
					typeError("Variables must be of the same type.");

				// check that if it's a string, it must use '+' operator
				if (streq($1.type, WORD_STRING)) {
					if (!streq($2, "+"))
						typeError("Strings can only use the '+' operator.");

					string concatVal = *(new string($1.string_val)) + *(new string ($3.string_val));
					//printf("string: %s\n", concatVal.c_str());

					// return the Value object to a higher grammar rule
					Value* val = new Value();
					val->type = WORD_STRING;
					val->string_val = (char*)concatVal.c_str();
					$$ = *val;

				} else if (streq($1.type, WORD_INT)) {
					int first = $1.int_val;
					int sec = $3.int_val;
					int result = 0;

					switch(*($2)) {
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
					$$ = *ret;

					if (VERBOSE)
						printf("Line %d,\tFirst = %d,\tSecond = %d,\tOperator: '%c',\tResult = %d\n", yylineno, first, sec, *($2), result);

				} else {
					typeError(UNKNOWN_TYPE_EXPL);
				}
			}
			| factor
			{
				$$ = $1;
			}
			;

/* "factor" rule has type Value */
factor		: factor bigOp factor
			{
				// only integers can use the "*" and "/" operators
				if (!streq($1.type, WORD_INT) || !streq($3.type, WORD_INT))
					typeError("Improper operator for variable type.");

				int first = $1.int_val;
				int sec = $3.int_val;
				int result = 0;

				switch(*($2)) {
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
				$$ = *ret;

				if (VERBOSE)
					printf("Line %d,\tFirst = %d,\tSecond = %d,\tOperator: '%c',\tResult = %d\n", yylineno, first, sec, *($2), result);
			}
			| term
			{
				$$ = $1;
			}
			;

/* "term" rule has type Value */
term		: NUM
			{
				Value* val = new Value();
				val->type = WORD_INT;
				val->int_val = $1;
				$$ = *val;
			}
			| ID
			{
				// This ID must represent an already assigned variable, or it's an error

				if (symbolTable.find($1) == symbolTable.end() || symbolTable.at($1).empty()) {
					typeError("Variable used before it is declared.");
				}
				else {
					vector<VariableInstance> vec = symbolTable.at($1);
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
					if (streq(var->value.type, WORD_NO_TYPE))
						typeError("Variable used before value assigned");

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

					$$ = *ret;
				}
			}
			| STRING
			{
				Value* val = new Value();
				val->type = WORD_STRING;
				val->string_val = $1;
				$$ = *val;
			}
			;

/* "bigOp" rule has type char* (String) */
bigOp		: SLASH
			{
				$$ = $1;
			}
			| MULT
			{
				$$ = $1;
			}
			;

/* "smallOp" rule has type char* (String) */
smallOp		: PLUS
			{
				$$ = $1;
			}
			| MINUS
			{
				$$ = $1;
			}
			;

/* "emptySpace" rule has type char* (String) */
emptySpace	: newlines
			|
			;

/* "newlines" rule has type char* (String) */
newlines	: newlines NEWLINE
			| NEWLINE
			;
%%

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
