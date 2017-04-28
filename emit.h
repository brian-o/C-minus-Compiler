#ifndef EMTAST
#define EMTAST
#define WORDSIZE 4

static int debug;
FILE * fp;
char s[120]; //char array s for doing sprintf
void emitf(char * label, char * cmd, char * comment);
void emit_ident (ASTnode * p);
void emitAST(ASTnode * p);

#endif /* of EMTAST */
