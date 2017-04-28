all: lab9

lab9: y.tab.c lex.yy.c oldsymtable.o
	gcc y.tab.c -o lab9

y.tab.c: lab9.y symtable.c ast.o lex.yy.c
	yacc -d lab9.y

lex.yy.c: lab9.l
	lex lab9.l

ast.o: ast.c ast.h
	gcc -c ast.c

symtable.o: symtable.c symtable.h
	gcc -c symtable.c

clean:
	rm lab9 y.tab.h y.tab.c lex.yy.c ast.o symtable.o
