%{
#include<stdio.h>
int yylex();
int yyerror(char*);
%}

%token ASSIGN ID NUM PLUS MINUS SLASH MULT EQUAL NEWLINE QUOTE LBRAK RBRAK SCRIPT OPENTAG SEMICOLON OPENPAREN CLOSEPAREN
%start script

%%
script		: OPENTAG emptySpace statements closetag emptySpace
        	;

closetag	: emptySpace closetag
			| LBRAK SLASH SCRIPT RBRAK
			;

statements	: statements newlines statements
			| statements SEMICOLON statements
			| statement
			|
			;

statement	: action
			;

action		: assignment
			;

assignment	: ID EQUAL expr
			;

expr		: OPENPAREN expr CLOSEPAREN
			| expr operator expr
			| term
			;

term		: NUM
			| ID
			;

operator	: PLUS
			| MINUS
			| SLASH
			| MULT
			;

newlines	: newlines NEWLINE
			| NEWLINE
			;

emptySpace	: emptySpace NEWLINE
			| NEWLINE
			|
			;
%%

FILE *yyin;
int yylineno;
int yyerror(char *s)
{
    fprintf(stderr, "error: %s, line: %d\n", s, yylineno);
		return 0;
}

int main(int argc, char *argv[])
{
    //yydebug = 1;
    if (argc == 2) {
        FILE *file;

        file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "could not open %s\n", argv[1]);
        } else{
            yyin = file;
            //yyparse() will call yylex()
            yyparse();
        }
    } else{
        fprintf(stderr, "format: ./parser [filename]");
    }
}
