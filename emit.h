#ifndef EMTAST
#define EMTAST
#define WORDSIZE 4
#include<stdio.h>
static int debug;
static char s[100];
FILE * fp;
void emit(FILE * fp, char * label, char * cmd, char * comment);
void emit_ident(ASTnode * p);
void emit_expr(ASTnode * p);
void emitAST(ASTnode * p);

#endif /* of EMTAST */
