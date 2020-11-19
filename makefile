spl-parser: source/spl.tab.c
	mkdir -p bin
<<<<<<< HEAD
	gcc source/spl.c source/spl.tab.c -lfl -o bin/spl-parser -ggdb -Wno-cpp -ansi -pedantic
	cp bin/spl-parser testing/spl-parser
=======
	gcc source/spl.c source/spl.tab.c -lfl -o bin/spl-parser -ggdb -Wno-cpp
>>>>>>> c49bed6fd46a8e079f8e20e93f89fd044538c7e7

source/spl.tab.c: source/lex.yy.c
	cd source; bison spl.y;

source/lex.yy.c:
	cd source; flex spl.l;

clean:
	cd source; rm lex.yy.c spl.tab.c;
	rm -r bin/
<<<<<<< HEAD
	rm testing/spl-parser
=======
>>>>>>> c49bed6fd46a8e079f8e20e93f89fd044538c7e7

testa: spl-parser
	cd bin; ./spl-parser < ../spl-progs/a.spl 2> output.txt > output.c; gcc -o output output.c


testb: spl-parser
	cd bin; ./spl-parser < ../spl-progs/b.spl 2> output.txt > output.c; gcc -o output output.c

testc: spl-parser
	cd bin; ./spl-parser < ../spl-progs/c.spl 2> output.txt > output.c; gcc -o output output.c

teste: spl-parser
	cd bin; ./spl-parser < ../spl-progs/e.spl 2> output.txt > output.c; gcc -o output output.c
	
