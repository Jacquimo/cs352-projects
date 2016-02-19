%{
#include<stdio.h>
int yylex();
int yyerror(char*);
%}

%token ASSIGN ID NUM PLUS MINUS SLASH MULT EQUAL NEWLINE QUOTE LBRAK RBRAK SCRIPT OPENTAG SEMICOLON OPENPAREN CLOSEPAREN
%start script

%%
script		: OPENTAG newlines statements closetag newlines
        	;

closetag	: LBRAK SLASH SCRIPT RBRAK newlines
			;

statements	: statements statement
			| statement
			;

statement	: action SEMICOLON newlines
			;

action		: assignment
			;

assignment	: ID EQUAL expr
			;

expr		: OPENPAREN expr CLOSEPAREN
			| expr operator term
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
