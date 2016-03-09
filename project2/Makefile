# Makefile for Miniscript language

CC=g++
CFLAGS= -Wno-write-strings -std=c++11

parser:y.tab.c lex.yy.c
	$(CC) $(CFLAGS) -g y.tab.c lex.yy.c -o parser -lfl
y.tab.c: parser.y
	bison -y -d -g -t --debug --verbose parser.y
lex.yy.c: parser.l
	lex parser.l

clean:
	rm -f lex.yy.c* y.tab.c y.tab.h y.dot y.output *.o
