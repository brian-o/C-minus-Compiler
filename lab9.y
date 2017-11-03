/*
lab5.y
Brian O'Dell
February 2017
                    ************
This code is the implementation of the Context Free Grammar of "Cminus"
It is a simplification of the C language.

if -v or --verbose is entered the debug option will be set

Semantic actions all involve dubgging or handling the AST
It also works with the symbol table to store Identifiers and
the propertiesthey have.
*/
%{

    /* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symtable.c"
#include "ast.c"
#include "emit.c"
#include "lex.yy.c"
static int level=0;
static int offset=0;
static int goffset=0;
static int maxoffset=0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf (stderr,"%s On Line: %d\n", s, lineNum);
}

/*Definition of start, tokens, and left association*/
%}
%start program

%union {
    int value;
    char * string;
    ASTnode * node;  /* so we can build an AST */
    enum OPERATORS op;
}

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%token IF WHILE ELSE RETURN GE LE EQ NE READ WRITE INT VOID STRING
%token <value> NUM
%token <string> ID STRINGTEXT
%type <node> declarationList decl varDecl funDecl params
%type <node> paramList param compoundStmt localDecls stmtList stmt expStmt
%type <node> selectStmt iterStmt returnStmt readStmt writeStmt expression
%type <node> assignStmt var simpleExpression addExpression term factor
%type <node> call args argList
%type <op> relop addOP multOP typeSpec


%%
program         : declarationList {prog=$1;}
                ;

declarationList : decl {$$=$1;}
                | decl declarationList
                {
                    $1->left=$2;
                    $$=$1;
                }
                ;

decl            : varDecl {$$=$1;}
                | funDecl {$$=$1;}
                ;

varDecl         : typeSpec ID ';'
                {
                    /* search symbol table for ID
                    insert if not found, then add the pointer from
                    insertion into the  ASTnode to have reference
                    to the symbol table entry */
                    if(Search($2,level,0))
                    {
                        fprintf(stderr,"\n\tThe name %s exists at level %d ",$2,level);
                        fprintf(stderr,"already in the symbol table\n");
                        fprintf(stderr,"\tDuplicate can.t be inserted(found in search)");
                        yyerror();
                        exit(1);
                    }

                    $$=ASTCreateNode(VARDEC);
                    $$->name=$2;
                    /* we use the op to determine its type while printing*/
                    $$->op=$1;
                    $$->symbol=Insert($2,$1,0,level,1,offset,NULL);
                    $$->isType=$1;
                    offset += 1;
                    if(offset > maxoffset)
                        maxoffset = offset;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making VarDec with name: %s",$2);
                        yyerror(" ");
                    }
                }
                | typeSpec ID '[' NUM ']' ';'
                {   /* search for symbol, if we find it error*/
                    if(Search($2,level,0))
                    {
                        fprintf(stderr,"\n\tThe name %s exists at level %d ",$2,level);
                        fprintf(stderr,"already in the symbol table\n");
                        fprintf(stderr,"\tDuplicate can.t be inserted(found in search)");
                        yyerror();
                        exit(1);
                    }

                    $$=ASTCreateNode(VARDEC);
                    $$->name=$2;
                    /* we use the op to determine its type while printing*/
                    $$->op=$1;
                    /* value links to the NUM nod to store the dimension*/
                    $$->value=$4;
                    $$->symbol=Insert($2,$1,2,level,$4,offset,NULL);
                    $$->isType=$1;
                    offset += $4;
                    if (offset>maxoffset)
                        maxoffset = offset;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making VarDec[] with name: %s",$2);
                        yyerror(" ");
                    }
                }
                ;

typeSpec        : INT   { $$=INTDEC;}
                | VOID  { $$=VOIDDEC;}
                | STRING{ $$=STRINGDEC;}
                ;

funDecl         : typeSpec ID '('
                {   /*name already used, cant make new dec*/
                    if(Search($2,level,0))
                    {
                        yyerror($2);
                        yyerror("Name already used ");
                        exit(1);
                    }
                    Insert($2,$1,1,level,1,0,NULL);
                    goffset=offset;
                    offset=2;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
                    params
                {   /*need the formal params to compare later */
                    (Search($2,0,0))->fparms = $5;
                    if (debug) Display();
                }
                  ')' compoundStmt
                {
                    $$=ASTCreateNode(FUNCTIONDEC);
                    $$->name=$2;
                    /* we use the op to determine its type while printing*/
                    $$->op=$1;
                    /* s1 links to the params which can be void
                        or a paramList */
                    $$->s1=$5;
                    /* right links to the compund statement,
                        called a BLOCK in the enumerated type */
                    $$->right=$8;
                    /*get the symbtab entry we made earlier*/
                    $$->symbol=Search($2,0,0);
                    /*Remove symbols put in, in the function call*/
                    offset -=Delete(1);
                    level = 0;
                    $$->value=maxoffset;
                    //we change this in the symbol table because it is not used
                    //anywhere else for functions. We have access to this
                    //in calls, so we can use it to determine where the
                    //stack pointer is going to have to be
                    $$->symbol->mysize = maxoffset;
                    /*change the offset back to the global offset*/
                    offset=goffset;
                    maxoffset=0;

                    if (debug){
                        Display();
                        fprintf(stderr, "Making FunDec with name: %s",$2);
                        yyerror(" ");
                    }
                }
                ;

params          : VOID
                {   /* no params */
                    $$ = NULL;

                    if (debug){
                        fprintf(stderr, "Params were void ");
                        yyerror(" ");
                    }
                }
                | paramList
                {   /* params found */
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Making non void paramList");
                        yyerror(" ");
                    }
                }
                ;

paramList       : param {$$ = $1;}
                | param ',' paramList
                {   /* attach the param to the list */
                    $1->left=$3;
                    $$ = $1;
                }
                ;

param           : typeSpec ID
                {   /*dont want overlap between params and vars*/
                    if(Search($2,level,0))
                    {
                       yyerror($2);
                       yyerror("\tDuplicate can.t be inserted(found in search)");
                       exit(1);
                    }
                    $$ = ASTCreateNode(PARAM);
                    $$->name=$2;
                    /* we use the op to determine its type while printing*/
                    $$->op=$1;
                    /* if value is 0 it is not an array, used for printing */
                    $$->value=0;
                    /*inherit the type*/
                    $$->isType=$1;
                    $$->symbol=Insert($2,$1,0,level+1,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                    if(debug) Display();
                }
                | typeSpec ID '[' ']'
                {
                    if(Search($2,level,0))
                    {
                       yyerror($2);
                       yyerror("\tDuplicate can.t be inserted(found in search)");
                       exit(1);
                    }
                    $$ = ASTCreateNode(PARAM);
                    $$->name=$2;
                    /* we use the op to determine its type while printing*/
                    $$->op=$1;
                    /* there was an array param */
                    $$->value=1;
                    /*inherit the type*/
                    $$->isType=$1;
                    /*2 is used for IsAFunc to show its an array ref*/
                    $$->symbol=Insert($2,$1,2,level+1,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
                ;

compoundStmt    : '{' { level++; }
                   localDecls stmtList '}'
                {
                    $$=ASTCreateNode(BLOCK);
                    if($3 == NULL) /*dont add decls if null*/
                        $$->right=$4;
                    else {
                        /* add the stmtList to the end of the localDecls
                        and then make the link to the right of BLOCK
                        be the whole decls and stmtList*/
                        ASTattachleft($3,$4);
                        $$->right=$3;
                   }
                   if(debug) {
                       fprintf(stderr,"\ntable before deleting");
                       Display();/*Display before*/
                   }
                   /*delete the old symbols from this block so they can
                   be used in a different block later on*/
                   offset -=Delete(level);
                   level--;
                   if (debug) {
                       fprintf(stderr,"\nEnd of compoundStmt, deleting symbols");
                       fprintf(stderr,"     current table...");
                       Display();/*Display after*/
                   }
                }
                ;

localDecls      : /*Empty*/ {$$ = NULL;}
                | varDecl localDecls
                {   /*check for null, if not attach it*/
                    if($1 != NULL){
                        $1->left=$2;
                        $$=$1;
                    }
                    else
                        $$=$2;
                }
                ;

stmtList        : /*Empty*/ {$$ = NULL;}
                | stmt stmtList
                {   /*check for null, if not attch it*/
                    if($1 != NULL) {
                        $1->left=$2;
                        $$=$1;
                    }
                    else
                        $$=$2;
                }
                ;

stmt            : expStmt
                { /*everything here is just the simplification to general stmt
                    to be put into a stmtList above */
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a expression Statement");
                        yyerror(" ");
                    }
                }
                | compoundStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a compound Statement");
                        yyerror(" ");
                    }
                }
                | selectStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a selection Statement");
                        yyerror(" ");
                    }
                }
                | iterStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a iteration Statement");
                        yyerror(" ");
                    }
                }
                | assignStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a assign Statement");
                        yyerror(" ");
                    }
                }
                | returnStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a return Statement");
                        yyerror(" ");
                    }
                }
                | readStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a read Statement");
                        yyerror(" ");
                    }
                }
                | writeStmt
                {
                    $$ = $1;

                    if (debug){
                        fprintf(stderr, "Converting a write Statement");
                        yyerror(" ");
                    }
                }
                ;

expStmt         : expression ';'
                {
                    $$=ASTCreateNode(EXPRSTMT);
                    $$->right=$1;
                    $$->isType=$1->isType;


                    if (debug){
                        fprintf(stderr, "Finished creating an expression Statement");
                        yyerror(" ");
                    }
                }
                | ';' {$$ = NULL;}
                ;

selectStmt      : IF '(' expression ')' stmt
                {
                    $$ = ASTCreateNode(IFSTMT);
                    /* right is the expression to be evaluated*/
                    $$->right=$3;
                    /* s1 is link to statment (it can be a block)*/
                    $$->s1=$5;
                }
                | IF '(' expression ')' stmt ELSE stmt
                {
                    $$ = ASTCreateNode(IFSTMT);
                    /* right is the expression to be evaluated*/
                    $$->right=$3;
                    /* s1 is link to statment (it can be a block)*/
                    $$->s1=$5;
                    /* s2 holds the link to the else statment (can be a block)*/
                    $$->s2=$7;
                }
                ;

iterStmt        : WHILE '(' expression ')' stmt
                {
                    $$ = ASTCreateNode(ITERSTMT);
                    /* right holds expression to be evaluated*/
                    $$->right=$3;
                    /* s1 holds the stmt to execute, can be block*/
                    $$->s1=$5;
                }
                ;

returnStmt      : RETURN ';' {$$ = ASTCreateNode(RETURNSTMT);}
                | RETURN expression ';'
                {
                    $$ = ASTCreateNode(RETURNSTMT);
                    /*expression to return*/
                    $$->s2=$2;
                }
                ;

readStmt        : READ var ';'
                {
                    $$ = ASTCreateNode(READSTMT);
                    /*expression to read*/
                    $$->right=$2;
                }
                ;

writeStmt       : WRITE expression ';'
                {
                    $$ = ASTCreateNode(WRITESTMT);
                    /*expression to write*/
                    $$->right=$2;
                }
                ;

expression      : simpleExpression {$$ = $1;}
                ;

assignStmt      : var '=' expStmt
                {
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (($1->isType != $3->isType) || ($1->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in Assignment");
                        exit(1);
                    }
                    $$=ASTCreateNode(ASSIGN);
                    /* hold the link to the var node*/
                    $$->right=$1;
                    /* hold the link to the expression statement*/
                    $$->s1=$3;
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    $$->isType=$1->isType;
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name,$$->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
                ;

var             : ID
                {
                    struct SymbTab * p;
                    if ((p=Search($1,level,1)) != NULL)
                    {
                        $$ = ASTCreateNode(IDENT);
                        $$->name=$1;
                        $$->symbol=p;
                        /*give the node op Type, based on SymbTab*/
                        $$->isType=p->Type;
                        if (p->IsAFunc == 2)
                        {
                            yyerror($1);
                            yyerror("Variable is an array, syntax error");
                        }
                    }
                    else
                    {
                        yyerror($1);
                        yyerror("undeclared variable used");
                        exit(1);
                    }
                }
                | ID '[' expression ']'
                {
                    struct SymbTab * p;
                    if ((p=Search($1,level,1)) != NULL)
                    {
                        $$ = ASTCreateNode(IDENT);
                        $$->name=$1;
                        /* hold expression inside of array reference */
                        $$->right=$3;
                        $$->symbol=p;
                        /*capital Type is enum op*/
                        $$->isType=p->Type;
                        if (p->IsAFunc != 2)
                        {
                            yyerror($1);
                            yyerror("Variable is not an array, syntax error");
                        }
                    }
                    else
                    {
                        yyerror($1);
                        yyerror("undeclared variable used");
                        exit(1);
                    }
                }
                ;

simpleExpression: addExpression {$$ = $1;}
                | simpleExpression relop addExpression
                {  /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (($1->isType != $3->isType) || ($1->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in simpleExpression");
                        exit(1);
                    }
                    $$ = ASTCreateNode(EXPR);
                    $$->op=$2;
                    $$->left=$1;
                    $$->right=$3;
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    $$->isType=$1->isType;
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name,$$->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
                ;

relop           : LE    {$$=LESSTHANEQUAL;}
                | '<'   {$$=LESSTHAN;}
                | '>'   {$$=GREATERTHAN;}
                | GE    {$$=GREATERTHANEQUAL;}
                | EQ    {$$=EQUAL;}
                | NE    {$$=NOTEQUAL;}
                ;

addExpression   : term {$$ = $1;}
                | addExpression addOP term
                {   /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (($1->isType != $3->isType) || ($1->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in additive exp");
                        exit(1);
                    }
                    $$ = ASTCreateNode(EXPR);
                    $$->op=$2;
                    $$->left=$1;
                    $$->right=$3;
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    $$->isType=$1->isType;
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name,$$->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
                ;

addOP           : '+' {$$ = PLUS;}
                | '-' {$$ = MINUS;}
                ;

term            : factor {$$ = $1;}
                | term multOP factor
                {  /* must ensure it is left recursive, to work properly */
                    /*we dont have to check both for void because if only one
                    is void there will be a type mismatch, otherwise they are
                    the same. So if one is void the other is also*/
                    if (($1->isType != $3->isType) || ($1->isType == VOIDDEC))
                    {
                        yyerror("Type mismatch or void in term/factor exp");
                        exit(1);
                    }
                    $$ = ASTCreateNode(EXPR);
                    $$->op=$2;
                    $$->left=$1;
                    $$->right=$3;
                    /*inherit the type, already check for equivalence
                    so can just use $1*/
                    $$->isType=$1->isType;
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name,$$->isType,0,level,1,offset,NULL);
                    offset+=1;
                    if(offset>maxoffset)
                        maxoffset = offset;
                }
                ;

multOP          : '*'  {$$ = TIMES;}
                | '/'  {$$ = DIVIDE;}
                ;

factor          : '(' expression ')' {$$ = $2;}
                | NUM
                {
                    $$=ASTCreateNode(NUMBER);
                    $$->value=$1;
                    /*numbers are always ints here*/
                    $$->isType=INTDEC;

                    if (debug){
                        fprintf(stderr, "The Number is: %d",$1);
                        yyerror(" ");
                    }
                }
                | var  {$$ = $1;}
                | call {$$ = $1;}
                | STRINGTEXT
                {
                    $$=ASTCreateNode(STRINGNODE);
                    $$->name = CreateTemp();
                    $$->isType=STRINGDEC;
                    $$->str = $1;
                }
                ;

call            : ID '(' args ')'
                {
                    struct SymbTab * p;
                    if ((p=Search($1,0,1)) != NULL)
                    {   /*make sure symbol is a function*/
                        if(p->IsAFunc != 1)
                        {
                            yyerror($1);
                            yyerror("Is a variable, but was called as function");
                            exit(1);
                        }
                        /*have to make sure we are calling with right params*/
                        if (compareFormals(p->fparms,$3) != 1)
                        {
                            yyerror($1);
                            yyerror("mismatch between formal and actual params");
                            exit(1);
                        }
                        $$=ASTCreateNode(CALLSTMT);
                        /* hold the link to args in right*/
                        $$->right=$3;
                        $$->name=$1;
                        $$->symbol=p;
                        $$->isType=p->Type;
                    }
                    else
                    {
                        yyerror($1);
                        yyerror("Function not defined in symbol table");
                        exit(1);
                    }
                }
                ;

args            : /*Empty*/
                { /*there were no arguments*/ $$ = NULL;}
                | argList   {$$ = $1;}
                ;

argList         : expression
                {
                    $$=ASTCreateNode(ARGLIST);
                    $$->right=$1;

                }
                | expression ',' argList
                {  /*attach the expressions to the tree in order
                    the use of the argList is handled above */
                    $$=ASTCreateNode(ARGLIST);
                    $$->left=$3;
                    $$->right=$1;
                }
                ;


%%

int main(int argc, char const *argv[]) {
    int i;
    /*cylce through the argument array, and check for -v or
    --verbose, to turn on debug*/
    for(i=0; i < argc; i++){
        char * test = strdup(argv[i]);
        char * v1 = "-v";
        char * v2 = "--verbose";
        char * v3 = "-o";
        char * v4 = "-s";
        if(strcmp(test,v1)==0 || strcmp(test,v2)==0)
            debug=1;
        if(strcmp(test,v3)==0)
        {
            char f[100];
            fprintf(stderr,"file name is %s\n",argv[++i]);
            strcpy(f,argv[i]);
            strcat(f,".asm");
            fprintf(stderr,"opening %s\n",f);
            fp = fopen(f,"w");
            if (fp==NULL)
            {
                fprintf(stderr,"Cannot open %s\n",f);
                fprintf(stderr,"It may not exist in this directory\n");
                exit(1);
            }
        }//end if -o set
    }//end loop
    if(fp==NULL){
        fprintf(stderr,"No file selected, emitting to a.out\n");
        fp = fopen("a.out","w");
    }
    if(fp==NULL){
        fprintf(stderr,"Couldn't emit to a.out, try using a file name\n");
        fprintf(stderr,"if this error persists\n");
        exit(1);
    }
    yyparse();
    /*fprintf(stderr,"\nMain symbol table");
    Display();
    fprintf(stderr,"the input has been syntactically checked\n");
    fprintf(stderr, "starting print\n*\n*\n*\n*\n*\n");
    */
    //ASTprint(0,prog);  /* this is where we can do things with the AST like
                        //print it or process it */;
    emitAST(prog);
    fprintf(stderr,"Finished Emitting Successfully\n");
    return(0);
}
