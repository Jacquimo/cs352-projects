parser:y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o parser -lfl
y.tab.c: parser.y
	bison -y -d -g -t --debug parser.y
lex.yy.c: yacc_example_lex.l
	lex parser.l

clean:
	rm -f lex.yy.c y.tab.c y.tab.h y.dot y.output
