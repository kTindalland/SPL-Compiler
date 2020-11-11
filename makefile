spl-parser: source/spl.tab.c
	mkdir -p bin
	gcc source/spl.c source/spl.tab.c -lfl -o bin/spl-parser -ggdb

source/spl.tab.c: source/lex.yy.c
	cd source; bison spl.y;

source/lex.yy.c:
	cd source; flex spl.l;

clean:
	cd source; rm lex.yy.c spl.tab.c;
	rm -r bin/

testa: spl-parser
	cd bin; ./spl-parser < ../spl-progs/a.spl 2> output.txt > output.c; gcc -o output output.c


testb: spl-parser
	cd bin; ./spl-parser < ../spl-progs/b.spl 2> output.txt > output.c; gcc -o output output.c
