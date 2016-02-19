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


%%
{opentag}		{return(OPENTAG);}
"script"		{return(SCRIPT);}
";"				{return(SEMICOLON);}
"+"				{return(PLUS);}
"-"				{return(MINUS);}
"/"				{return(SLASH);}
"*"				{return(MULT);}
"\n"			{return(NEWLINE);}
"\""			{return(QUOTE);}
"<"				{return(LBRAK);}
">"				{return(RBRAK);}
"="				{return(EQUAL);}
"("				{return(OPENPAREN);}
")"				{return(CLOSEPAREN);}
{id}			{return(ID);}
{num}			{return(NUM);}
{ws}			{}
%%
