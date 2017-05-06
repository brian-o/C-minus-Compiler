#ifndef EMTAST
#define EMTAST
#define WORDSIZE 4
#include<stdio.h>
static int debug;
static char s[100];
static int offsetDownFromSP;
FILE * fp;
void emit(FILE * fp, char * label, char * cmd, char * comment);
void emit_ident(ASTnode * p);
void emit_expr(ASTnode * p);
void emit_iteration(ASTnode * p);
void emit_callstmt(ASTnode * p);
void emit_ifstmt(ASTnode * p);
void emit_args(ASTnode * p, int argNum);
void emit_return_stmt(ASTnode * p);
void emit_assignment_stmt(ASTnode * p)
void emitAST(ASTnode * p);

#endif /* of EMTAST */
