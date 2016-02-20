%{
#include<stdio.h>
int yylex();
int yyerror(char*);
%}

%token ASSIGN ID NUM PLUS MINUS SLASH MULT EQUAL NEWLINE STRING LBRAK RBRAK SCRIPT OPENTAG SEMICOLON OPENPAREN CLOSEPAREN VAR DOCWRITE COMMA

%start script

%%
script		: OPENTAG newlines statements closetag emptySpace
        	;

closetag	: emptySpace closetag
			| LBRAK SLASH SCRIPT RBRAK
			;

statements	: statements newlines statements
			| statements SEMICOLON statements
			| action
			|
			;

action		: declaration
			| assignment
			| docwrite
			;

declaration	: VAR assignment
			;

assignment	: ID EQUAL expr
			;

docwrite	: DOCWRITE OPENPAREN paramList CLOSEPAREN
			;

paramList	: paramList COMMA term
			| term
			|
			;

expr		: OPENPAREN expr CLOSEPAREN
			| expr operator expr
			| term
			;

term		: NUM
			| ID
			| STRING
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
