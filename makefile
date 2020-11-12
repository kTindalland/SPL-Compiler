spl-parser: build/spl.tab.c
	mkdir -p bin
	gcc source/source/*.c build/spl.tab.c -lfl -o bin/spl-parser -ggdb -I source/headers/ -I build/

build/spl.tab.c: build/lex.yy.c
	mkdir -p build; cd build; bison ../source/source/spl.y;

build/lex.yy.c:
	mkdir -p build; cd build; flex ../source/source/spl.l;

clean:
	rm -r build/
	rm -r bin/

testa: spl-parser
	cd bin; ./spl-parser < ../spl-progs/a.spl 2> output.txt > output.c; gcc -o output output.c


testb: spl-parser
	cd bin; ./spl-parser < ../spl-progs/b.spl 2> output.txt > output.c; gcc -o output output.c
