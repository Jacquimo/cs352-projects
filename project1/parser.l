%{
#include"y.tab.h"
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
"+"				{return(PLUS);}
"-"				{return(MINUS);}
"/"				{return(SLASH);}
"*"				{return(MULT);}
"\n"			{return(NEWLINE);}
"<"				{return(LBRAK);}
">"				{return(RBRAK);}
"="				{return(EQUAL);}
"("				{return(OPENPAREN);}
")"				{return(CLOSEPAREN);}
{string}		{return(STRING);}
{id}			{return(ID);}
{num}			{return(NUM);}
{ws}			{}
%%
