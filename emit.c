

#include "emit.h"
#include <stdlib.h>
int stackval;
static int LTEMP=0;

/**
  * Helper function to generate labels for jumps
  */
char * genLabel()
{
    char hold[100];
    char *a;
    sprintf(hold,"_L%d",LTEMP++);
    a=strdup(hold);
    return (a);
}

/**
 * Helper function to emit a line to a file, accepts:
 * a file pointer, a label, a command, and a comment
 * will use stdout for now instead of fp
 */
void emit(FILE * fp, char * label, char * cmd, char * comment)
{
    char x[100];
    sprintf(x,"%s\t%s\t\t%s\n",label,cmd,comment);
    fprintf(fp,"%s",x);
}

//function to emit edentifier code so that t2 is the direct
//access into memory for the identifier
void emit_ident(ASTnode * p)
{
    //check for scalar vs array
    if (p->right == NULL)
    {
        sprintf(s,"li  $t2, %d",p->symbol->offset*WORDSIZE);
        emit(fp, "",s,"# Load ID offset into $t2");
        emit(fp, "","add $t2, $t2, $sp","# Create exact mem location for ID");
    }
    else
    {
        //is an array
        switch(p->right->type){
            //will load array offset, id offset and add them to get final offset
            case NUMBER:
            sprintf(s,"li  $t2, %d",p->symbol->offset*WORDSIZE);
            emit(fp,"",s,"#Get base offset for ID");
            sprintf(s,"li  $t3, %d",p->right->value*WORDSIZE);
            emit(fp,"",s,"#Get array offset for the ID");
            emit(fp,"","add $t2, $t2, $t3","#Add array offset to ID offset");
            emit(fp,"","add $t2, $t2, $sp","#Add the stack poitner in");
            break;

            //do the expression, get id offset, get array offset*WORDSIZE
            //add them, and value will be final offset
            case EXPR:
            emit_expr(p->right);
            sprintf(s,"li  $t2, %d",p->symbol->offset*WORDSIZE);
            emit(fp,"",s,"#Load initial offset for the ID");
            sprintf(s,"li  $t3, %d($sp)",p->right->symbol->offset*WORDSIZE);
            emit(fp,"",s,"#Load array offset for the array");
            sprintf(s,"sll $t3, $t3, %d",WORDSIZE/2);
            emit(fp,"",s,"#Mutliply array offset by WORDSIZE");
            emit(fp,"","add $t2, $t2, $t3","#Add array offset to ID offset");
            emit(fp,"","add $t2, $t2, $sp","#Add the stack poitner in");
            break;

            //get the id, its loc is in t2, move it to t3 and mult by WORDSIZE
            //add id offset and array offset, result is final offset
            case IDENT:
            emit_ident(p->right);
            emit(fp,"","lw  $t3, ($t2)","#Move the ID value out of the way");
            sprintf(s,"sll $t3, $t3, %d",WORDSIZE/2);
            emit(fp,"",s,"#Mutliply array offset by WORDSIZE");
            sprintf(s,"li  $t2, %d",p->symbol->offset*WORDSIZE);
            emit(fp,"",s,"#Load initial offset for the ID");
            emit(fp,"","add $t2, $t2, $t3","#Add array offset to ID offset");
            emit(fp,"","add $t2, $t2, $sp","#Add the stack poitner in");
            break;
        }//end switch
    }//end else is an array
}//end emit_ident

/**
  * The goal is to have the value of the evaluated expression in its
  * place in the stack, to use it later
 */
void emit_expr(ASTnode * p)
{
    //left hand side first
    switch(p->left->type) {
        case NUMBER:
        sprintf(s,"li  $t0, %d",p->left->value);
        emit(fp,"",s," #Load imeddiate into t0 FROM EXPR");
        break;

        case IDENT:
        emit_ident(p->left);
        emit(fp,"","lw  $t0, ($t2)"," #LHS is an ID load into t0");
        break;

        default:
        fprintf(stderr,"unhandled type in emit_expr");
        exit(1);
    }
    //need to store t0 bc RHS could mess it up
    //TODO: figure out where this is stored
    sprintf(s,"sw  $t0, %d($sp)",p->symbol->offset*WORDSIZE);
    emit(fp,"",s,"#store t0 to use later");

    switch(p->right->type) {
        case NUMBER:
        sprintf(s, "li  $t1, %d", p->right->value);
        emit(fp,"",s," #Load immediate into t1 FROM EXPR");
        break;

        case IDENT:
        emit_ident(p->right);
        emit(fp,"","lw  $t1, ($t2)"," #RHS is an ID load into t0");
        break;

        default:
        fprintf(stderr,"unhandled type in emit_expr");
        exit(1);
    }

    //restore t0 after handling RHS
    sprintf(s,"lw  $t0, %d($sp)",p->symbol->offset*WORDSIZE);
    emit(fp,"",s,"#Get what was in t0 back form the stack");

    switch (p->op) {
        case PLUS:
        emit(fp,"","add $t0, $t0, $t1","#add the LHS and RHS");
        break;
    }
    /*
                //switch through the different ops in an expression
                switch (p->op){
                    case PLUS: printf("+");
                    break;

                    case MINUS: printf("-");
                    break;

                    case TIMES: printf("*");
                    break;

                    case DIVIDE: printf("/");
                    break;

                    case LESSTHANEQUAL: printf("<=");
                    break;

                    case LESSTHAN: printf("<");
                    break;

                    case GREATERTHAN: printf(">");
                    break;

                    case GREATERTHANEQUAL: printf(">=");
                    break;

                    case NOTEQUAL: printf("!=");
                    break;

                    case EQUAL: printf("==");
                    break;

                    case INTDEC:
                    case VOIDDEC:
                    case null:
                    //we should never be here since these are not in expression
                    break;

               } //end switch (p->op)
               printf("\n");
               //recursively print left and right side of expression
               ASTprint(level+1, p->left);
               ASTprint(level+1, p->right);
    	   */
}//end emit_expr

/*  Emit the mips code to the file */
void emitAST(ASTnode* p)
{
    if (p == NULL ) return;
    else {
        switch (p->type) {

        case VARDEC :
            if(p->symbol->level == 0)
            {
                //do operations for global variables
            }
            break;

        //right is block, s1 is params
        case FUNCTIONDEC:
            //declare function as global
            emit(fp,".text","            ","# Directive that says we are in code segment");
            sprintf(s,".globl %s",p->name);
            emit(fp,"",s,"#global declaration of function");
            //insert the label for the function
            sprintf(s,"%s:",p->name);
            emit(fp,s,"","");

            //make the activation record
            //stackval = p->value*WORDSIZE;
            sprintf(s,"subu $sp, $sp, %d",p->value*WORDSIZE);
            emit(fp,"",s,"# get some space in the stack for activation record");
            sprintf(s,"sw  $ra, %d($sp)",1*WORDSIZE);
            emit(fp,"",s,"# Store return adress into the stack");

            //TODO: Here is where the params work should go?

            //recursively do the block inside the dec
            emitAST(p->right);

            if (strcmp("main",p->name) == 0)
            {
                sprintf(s,"lw  $ra, %d($sp)",1*WORDSIZE);
                emit(fp,"",s,"# Load the right value back into ra");
                sprintf(s,"addu $sp, $sp, %d",p->value*WORDSIZE);
                emit(fp,"",s,"#add the right value back into sp");
                emit(fp,"","jr  $ra","");
            }
            break;

        case EXPR:
            emit_expr(p);
            break;

        case RETURNSTMT:
            sprintf(s,"lw  $ra, %d($sp)",1*WORDSIZE);
            emit(fp,"",s,"# Load the right value back into ra");
            //TODO: fix this
            sprintf(s,"addu $sp, $sp, %d",p->value*WORDSIZE);
            emit(fp,"",s,"#add the right value back into sp");
            emit(fp,"","jr  $ra","");
            break;

        case IDENT:
            emit_ident(p);
            break;

        case BLOCK:
            //recursively print the contents of the block statement
            emitAST(p->right);
            break;


        case READSTMT:
            emit_ident(p->right);
            emit(fp,"","li  $v0,  5"," # read in an integer");
	        emit(fp,"","syscall"," # call a READ NUMBER FUNCITON");
	        emit(fp,"","sw  $v0, ($t2)"," # store a READ number in t2");
            break;

        case WRITESTMT:
            switch (p->right->type) {
                case NUMBER:
		        sprintf(s,"li  $a0, %d",p->right->value);
		        emit(fp, "",s,"# Write a Number to the screen");
		        break;

                case EXPR:
		        emitAST(p->right);
                sprintf(s, "lw  $a0, %d($sp)",p->right->symbol->offset*WORDSIZE);
		        emit(fp, "",s," #fetch expr value");
		        break;

	            case CALLSTMT:
		        break;

                case IDENT:
		        emit_ident(p->right);
		        emit(fp, "","lw  $a0, ($t2)"," #put stuff in a0");
		        break;
	        }
            emit(fp,"","li  $v0, 1"," #put 1 in v0 to print an integer");
            emit(fp,"","syscall","");
            break;

        case ASSIGN:
            //right = var, s1 = expression
            //Emit the expressionstmt, value will be in t0
            //we use the whole funciton because the node is expresison stmt
            emitAST(p->s1);

            //Emit the ID, address will be in t2 we do this after the expression
            //Because emit_ident does not touch t0
            emit_ident(p->right);
            //Now shove value in t0 into address at t2
            emit(fp,"","sw  $t0, ($t2)","#Store the value in the right place");
            break;

        case NUMBER:
            //want to load the value into t0 so we can use it
            sprintf(s, "li  $t0, %d", p->value);
            emit(fp,"",s," #Load immediate into t1");;
            break;

        case ITERSTMT:
            ;//empty statement to satisfy c semantics
            char * L3;
            char * L4;
            L3 = genLabel();
            L4 = genLabel();

            //print the label we will jump back to each iteration
            sprintf(s,"%s: ", L3);
            emit(fp,s,"   ","#Beginning of WHILE target");

            //handle the expression to be evaluated
            switch(p->right->type){
                case NUMBER:
                sprintf(s,"li  $t0, %d",p->right->value);
                emit(fp,"",s,"#Load number into $t0 for while stmt");
                break;

                case EXPR:
                emitAST(p->right);
                //TODO: move symbol into t0
                break;

                case IDENT:
                emit_ident(p->right);
                emit(fp,"","lw  $t0, ($t2)", "#Load the value from the stack int t0 for while");
                break;

                case CALLSTMT:
                break;
            }
            //condition no satisfied jump out
            sprintf(s,"beq $t0 $0 %s",L4);
            emit(fp,"",s,"#WHILE expression false jump out");

            //recursively emit Statement(can be block) and jump over else stmts
            emitAST(p->s1);
            sprintf(s,"j   %s", L3);
            emit(fp,"",s,"#jump back to beginning of WHILE");

            //make target to jump out
            sprintf(s,"%s:  ",L4);
            emit(fp,s,"  ","#target to stop executing loop");
            break;
/*
        case PARAM:
            printf("PARAMETER ");
            if( p->op == INTDEC )
                printf("INT");

            if( p->op == VOIDDEC )
                printf("VOID");

            printf(" %s ",p->name); //name of the parameter
            if(p->value == -1)
                printf("[]");

            printf("\n");
            break;
*/
        case IFSTMT:
            ;//this an empty statement to satisfy C semantics
            char * L1;
            char * L2;
            L1 = genLabel();
            L2 = genLabel();

            //handle the expression to be evaluated
            switch(p->right->type){
                case NUMBER:
                sprintf(s,"li  $t0, %d",p->right->value);
                emit(fp,"",s,"#Load number into $t0 for if stmt");
                break;

                case EXPR:
                //TODO: move symbol into t0
                emitAST(p->right);
                break;

                case IDENT:
                emit_ident(p->right);
                emit(fp,"","lw  $t0, ($t2)", "#Load the value from the stack into t0 for ifstmt");
                break;

                case CALLSTMT:
                break;
            }
            sprintf(s,"beq $t0 $0 %s",L1);
            emit(fp,"",s,"#If branch to else");

            //recursively emit Statement(can be block) and jump over else stmts
            emitAST(p->s1);
            sprintf(s,"j   %s", L2);
            emit(fp,"",s,"#finished if jump over else stmts");

            //make label for beq to jump to
            sprintf(s,"%s:  ",L1);
            emit(fp,s,"","# ELSE target");

            //handle the else Statement
            if(p->s2 != NULL){
                emitAST(p->s2);
            }
            //label to jump over else stmts
            sprintf(s,"%s:    ",L2);
            emit(fp,s,"","# End of IF");

            break;//end of IFSTMT
/*
        case CALLSTMT:
            printf("Function Call  %s\n" , p->name);
            if (p->right != NULL){
                //recursively print out args
                ASTprint(level+2, p->right);
                printf("\n");
            }
            //args were void
            else{
                PT(level+2);
                printf("(VOID)\n");
            }
            break;
        case ARGLIST:
            printf("ARG\n");
            //this arg's expression is right, the next arg is at left
            //it gets there from the main control
            ASTprint(level+1, p->right);
            break;
*/
        case EXPRSTMT:
            //do the right hand pointer in this node
            //can be NUMBER, EXPR, CALL, or VAR, we need the value to be
            //int t0 when we are done.
            switch (p->right->type) {
                case NUMBER:
                sprintf(s,"li  $t0, %d",p->right->value);
                emit(fp,"",s,"#Load number into $t0 for if stmt");
                break;

                case EXPR:
                emitAST(p->right);
                //TODO: move symbol into t0
                break;

                case IDENT:
                emit_ident(p->right);
                emit(fp,"","lw  $t0, ($t2)", "#Load the value from the stack into t0 for ifstmt");
                break;

                case CALLSTMT:
                break;

            }
            break;

        default: printf("Unknown type in emitAST\n");
        //if we hit default there was an error
            break;

        } //end switch p->type

        if (p->type != EXPR) //go left for all except expression
            emitAST(p->left);
    }//end else
}//end emitAST
/*
int main(){
  int x;
}
*/
