%{
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int yylex();
int yyerror(char*);

// Global Variables
int scopeLevel = 1;

#define stringLiteral "string"
#define intString "int"
#define noType "none"

// Class that represents an instantiated variable and its value based on scope
class VariableInstance {
	public:
		char* type;
		int scope;
		union {
			char* string_val;
			int int_val;
		};

		VariableInstance(char* val) {
			this->type = stringLiteral;
			this->scope = scopeLevel;
			this->string_val = val;
		}

		VariableInstance(int val) {
			this->type = intString;
			this->scope = scopeLevel;
			this->int_val = val;
		}

		VariableInstance() {
			this->type = noType;
			this->scope = scopeLevel;
		}
};

// Helper functions
void typeError(char*) {
	// TODO: implement this function completely
}

/*
int eval(int first, int sec, char* op) {
	int ret = 0;
	switch(*op) {
		case '*':
			ret = first * sec;
			break;

		case '/'
	}

	return ret;
}
*/

unordered_map <string, vector<VariableInstance> > symbolTable;

%}

%token <string_val> ID
%token <number_val> NUM
%token ASSIGN PLUS MINUS SLASH MULT EQUAL NEWLINE STRING LBRAK RBRAK SCRIPT OPENTAG SEMICOLON OPENPAREN CLOSEPAREN VAR DOCWRITE COMMA COLON OPENCURL CLOSECURL DOT

%union {
	char*	string_val;
	int		number_val;
}

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
			}
			statements CLOSECURL
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

field		: ID fieldAssign
			;

fieldAssign	: COLON expr
			|
			;

docwrite	: DOCWRITE OPENPAREN paramList CLOSEPAREN
			;

paramList	: paramList COMMA expr
			| expr
			|
			;

expr		: OPENPAREN expr CLOSEPAREN
			| sum
			;

sum			: sum smallOp sum
			| factor
			;

factor		: factor bigOp factor
			| term
			;

term		: NUM
			| ID
			| STRING
			;

bigOp		: SLASH
			| MULT
			;

smallOp		: PLUS
			| MINUS
			;

emptySpace	: newlines
			|
			;

newlines	: newlines NEWLINE
			| NEWLINE
			;
%%

extern FILE *yyin;
extern int yylineno;
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
