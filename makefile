all: lab9

lab9: y.tab.c y.tab.h lex.yy.c symtable.c symtable.h ast.c ast.h emit.c emit.h
	gcc y.tab.c -o lab9

y.tab.c: lab9.y lex.yy.c
	yacc -d lab9.y

lex.yy.c: lab9.l
	lex lab9.l

clean:
	rm lab9 y.tab.h y.tab.c lex.yy.c
