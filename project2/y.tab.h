/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y" /* yacc.c:1915  */

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

struct VariableInstance;
struct ScriptObject;

struct Result {
	bool isObject;
	union {
		Value value;
		ScriptObject* obj;
	};
};


#line 71 "y.tab.h" /* yacc.c:1915  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 37 "parser.y" /* yacc.c:1915  */

	char* string_val;
	int int_val;
	Value value;
	Pair fieldVal;
	ScriptObject* obj;
	Result* res;

#line 144 "y.tab.h" /* yacc.c:1915  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
