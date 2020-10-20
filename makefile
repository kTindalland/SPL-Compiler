spl-parser: spl.tab.c
	gcc spl.c spl.tab.c -lfl -o spl-parser

spl.tab.c: lex.yy.c
	bison spl.y

lex.yy.c:
	flex spl.l

clean:
	rm lex.yy.c spl.tab.c spl-parser
