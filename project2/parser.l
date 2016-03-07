%{
#include "y.tab.h"

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
%}

%option yylineno

/* regular definitions */
delim		[ \t]
ws			{delim}+
letter		[A-Za-z]
digit		[0-9]
id			{letter}({letter}|{digit}|"_")*
num			{digit}+
opentag		"<script type=\"text/JavaScript\">"
string		\"(\\.|[^\"\n:])*\"
docwrite	"document.write"


%%
{opentag}		{return(OPENTAG);}
{docwrite}		{return(DOCWRITE);}
"script"		{return(SCRIPT);}
"var"			{return(VAR);}
","				{return(COMMA);}
";"				{return(SEMICOLON);}

"+"				{
					yylval.string_val = strdup(yytext);
					return(PLUS);
				}
"-"				{
					yylval.string_val = strdup(yytext);
					return(MINUS);
					}
"/"				{
					yylval.string_val = strdup(yytext);
					return(SLASH);
				}
"*"				{
					yylval.string_val = strdup(yytext);
					return(MULT);
				}

"\n"			{return(NEWLINE);}
"<"				{return(LBRAK);}
">"				{return(RBRAK);}
"="				{return(EQUAL);}
"("				{return(OPENPAREN);}
")"				{return(CLOSEPAREN);}
":"				{return(COLON);}
"{"				{return(OPENCURL);}
"}"				{return(CLOSECURL);}
"."				{return(DOT);}

{string}		{
					// remove quotation marks from string value
					yylval.string_val = strdup(yytext);
					yylval.string_val++;
					yylval.string_val[strlen(yylval.string_val)-1] = 0;
					
					return(STRING);
				}

{id}			{
					yylval.string_val = strdup(yytext);
					return(ID);
				}
{num}			{
					yylval.int_val = atoi(yytext);
					return(NUM);
				}
{ws}			{}
%%
