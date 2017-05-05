

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
{   //check to see if it is a global
    if(p->symbol->level==0)
    {
        if (p->right == NULL)
        {
            sprintf(s,"la  $t2, %s",p->name);
            emit(fp, "",s,"# Load ID from data segment into $t2");
        }
        else
        {
            //is an array
            switch(p->right->type){
                //will load array offset, id offset and add them to get final offset
                case NUMBER:
                sprintf(s,"la  $t2, %s",p->name);
                emit(fp,"",s,"#Get ID address from data segment");
                sprintf(s,"li  $t3, %d",p->right->value*WORDSIZE);
                emit(fp,"",s,"#Get array offset for the ID");
                emit(fp,"","add $t2, $t2, $t3","#Add array offset to ID address");
                break;

                //do the expression, get id offset, get array offset*WORDSIZE
                //add them, and value will be final offset
                case EXPR:
                emit_expr(p->right);
                sprintf(s,"la  $t2, %s",p->name);
                emit(fp,"",s,"#Get ID address from data segment");
                sprintf(s,"lw  $t3, %d($sp)",p->right->symbol->offset*WORDSIZE);
                emit(fp,"",s,"#Load array offset");
                sprintf(s,"sll $t3, $t3, %d",WORDSIZE/2);
                emit(fp,"",s,"#Mutliply array offset by WORDSIZE");
                emit(fp,"","add $t2, $t2, $t3","#Add array offset to ID address");
                break;

                //get the id, its loc is in t2, move it to t3 and mult by WORDSIZE
                //add id offset and array offset, result is final offset
                case IDENT:
                emit_ident(p->right);
                emit(fp,"","lw  $t3, ($t2)","#Move the ID value out of the way");
                sprintf(s,"sll $t3, $t3, %d",WORDSIZE/2);
                emit(fp,"",s,"#Mutliply array offset by WORDSIZE");
                sprintf(s,"la  $t2, %s",p->name);
                emit(fp,"",s,"#Get ID address from data segment");
                emit(fp,"","add $t2, $t2, $t3","#Add array offset to ID address");
                break;
            }//end switch
        }//end else is an array
    }//end ifis a global

    //is not a global
    else
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
                sprintf(s,"lw  $t3, %d($sp)",p->right->symbol->offset*WORDSIZE);
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
    }//end if is not global
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

        case EXPR:
        emit_expr(p->left);
        sprintf(s,"lw  $t0, %d($sp)",p->left->symbol->offset*WORDSIZE);
        emit(fp,"",s,"#Insert the value from the LHS EXPR into t0");
        break;
	
	case CALLSTMT:
	emit_callstmt(p->left);
	//v0 has what we need move it into t0
	emit(fp,"","lw  $t0, ($v0)","#Get return for LHS");
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
        emit(fp,"","lw  $t1, ($t2)"," #RHS is an ID load into t1");
        break;

        case EXPR:
        emit_expr(p->right);
        sprintf(s,"lw  $t1, %d($sp)",p->right->symbol->offset*WORDSIZE);
        emit(fp,"",s,"#Insert the value from the RHS EXPR into t1");
        break;
	
	case CALLSTMT:
	emit_callstmt(p->right);
	//v0 has what we need move it into t0
	emit(fp,"","lw  $t1, ($v0)","#Get return for RHS");
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

        case MINUS:
        emit(fp,"","sub $t0, $t0, $t1","#subtract the LHS and RHS");
        break;

        case TIMES:
        emit(fp,"","mult $t0, $t1","#Multiply the LHS and RHS");
        emit(fp,"","mflo $t0","#move contents of lo int $t0");
        break;

        case DIVIDE:
        emit(fp,"","div $t0, $t1","#Divide LHS and RHS");
        emit(fp,"","mflo $t0","#move contents of hi into $t0");
        break;

        case LESSTHANEQUAL:
        emit(fp,"","addu $t1, $t1, 1","#Add one for the lt equal");
        emit(fp,"","slt $t0, $t0, $t1","#Will be 1 if LT equal");
        break;

        case LESSTHAN:
        emit(fp,"","slt $t0, $t0, $t1","#will be 1 if less than");
        break;

        case GREATERTHAN:
        emit(fp,"","slt $t0, $t1, $t0","#will be 1 if greater than");
        break;

        case GREATERTHANEQUAL:
        emit(fp,"","addu $t0, $t0, 1","#add one for GT equal");
        emit(fp,"","slt $t0, $t1, $t0","#will be 1 if GT equal");
        break;

        case NOTEQUAL:
        emit(fp,"","sne $t0, $t0, $t1","#If not equal will be 1");
        break;

        case EQUAL:
        emit(fp,"","seq $t0, $t0, $t1","#If equal will be 1");
        break;

    }
    sprintf(s,"sw  $t0, %d($sp)",p->symbol->offset*WORDSIZE);
    emit(fp,"",s,"#put the value into the stack");
}//end emit_expr




void emit_iteration(ASTnode * p)
{
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
        sprintf(s,"lw  $t0, %d($sp)",p->right->symbol->offset*WORDSIZE);
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
}




void emit_ifstmt(ASTnode * p)
{
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
        sprintf(s,"lw  $t0, %d($sp)",p->right->symbol->offset*WORDSIZE);
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
}


//we were handed p->right, an arg node
//this function isnt called if args are void
//from here p->right is the arg's expression
//p->left is the next arg in the list
//p->right should not be NULL so we will not check
emit_args(ASTnode * p)
{
  switch(p->right->type)
  {
      
  }
  
}



//when this is call we will have the return stmt in p
emit_return_stmt(ASTnode * p)
{
  //there is an expression to do if something is in p->s2
  
      if(p->s2 != NULL){
	    switch (p->s2->type) {
                case NUMBER:
                sprintf(s,"li $v0, %d",p->s2->value);
                emit(fp,"",s,"#Load number into $v0 for return");
                break;

                case EXPR:
                emitAST(p->s2);
                sprintf(s,"lw  $v0, %d($sp)",p->s2->symbol->offset*WORDSIZE);
                emit(fp,"",s,"#load the value from the stack into v0 for return");
                break;

                case IDENT:
                emit_ident(p->s2);
                emit(fp,"","lw  $v0, ($t2)", "#Load the value from the stack into v0 for return");
                break;

                case CALLSTMT:
		  emitAST(p->s2);
                break;

            }
      }//end if expr exists
      else
	  emit(fp,"","li $v0, 0","#Return 0 since there was no expression");

	  
   sprintf(s,"lw  $ra, %d($sp)",1*WORDSIZE);
   emit(fp,"",s,"# Load the right value back into ra");
            //TODO: fix this
            
   emit(fp,"","lw  $sp, ($sp)","#add the right value back into sp");
   emit(fp,"","jr  $ra","");
}



emit_callstmt(ASTnode * p)
{
  //p->right is beginning of arglist
    //each arg expression is in p->right
    //the next arg in the list is p->left
    //if p->left is NULL we are al the end of the list.
    int offsetDownFromSP;
    //this value is the same as maxoffset for the function
    //made this way when creating the AST
    //only used forclarity of what operations are happening
    emit(fp,"","addu $t5, $sp, 0","#Save old sp into t5");
    offsetDownFromSP = p->symbol->mysize*WORDSIZE;
    sprintf(s,"subu $sp, $sp, %d",offsetDownFromSP);
    emit(fp,"",s,"#temoporarily move the sp to eval the args");
    //
    //$t5 is now the old sp we will evaluate all the expressions
    //in the args and put the values in the right memory addressess
     //p->right is beginning of arglist
    //each arg expression is in p->right
    //the next arg in the list is p->left
    //if p->left is NULL we are al the end of the list.
    //no we can emit the args, using $t5 as our "sp"
  if(p->right != NULL)
  {
    
    emit_args(p->right);
  
  }
  //emit 
  emit(fp,"","addu $sp, $t5, 0","#Put sp back where it goes");
  sprintf(s,"jal %s",p->name);
  emit(fp,"",s,"#jump and linkthe function");
  emit(fp,"","nop","");
}


/******************************************************************
*
* start of emitAST
*
*******************************************************************/
/*  Emit the mips code to the file */
void emitAST(ASTnode* p)
{
    if (p == NULL ) return;
    else {
        switch (p->type) {

        case VARDEC :
            if(p->symbol->level == 0)
            {
                emit(fp,"",".data","#Indicates we are in data segment");
                sprintf(s,"%s: .space  %d",p->symbol->name,p->symbol->mysize*WORDSIZE);
                emit(fp,s,"","");
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
            sprintf(s,"subu $t0, $sp, %d",p->value*WORDSIZE);
            emit(fp,"",s,"# put where the new sp should be in t0");
            sprintf(s,"sw  $ra, %d($t0)",1*WORDSIZE);
            emit(fp,"",s,"# Store return adress into the stack");
	    emit(fp,"","sw  $sp, ($t0)","# save the old sp");
	    emit(fp,"","addu $sp, $t0, 0","#move the sp now");

            //TODO: Here is where the params work should go?

            //recursively do the block inside the dec
            emitAST(p->right);
	    emit_return_stmt(p);
	    break;

        case EXPR:
            emit_expr(p);
            break;

        case RETURNSTMT:
	    emit_return_stmt(p);
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
            //Emit the expressionstmt, value will be in t6
            //we use the whole funciton because the node is expresison stmt
            emitAST(p->s1);
	    
            //Emit the ID, address will be in t2 we do this after the expression
            //Because emit_ident does not touch t0
            emit_ident(p->right);
            //Now shove value in t6 into address at t2
            emit(fp,"","sw  $t6, ($t2)","#Store the value in the right place");
            break;

        case NUMBER:
            //want to load the value into t0 so we can use it
            sprintf(s, "li  $t0, %d", p->value);
            emit(fp,"",s," #Load immediate into t1");;
            break;

        case ITERSTMT:
            emit_iteration(p);
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
            emit_ifstmt(p);
            break;//end of IFSTMT

        case CALLSTMT:
	    emit_callstmt(p);
	  break;
	  
/*	  
            printf("Function Call  %s\n" , p->name);
            if (p->right != NULL){
                //recursively print out args
                //ASTprint(level+2, p->right);
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
            //ASTprint(level+1, p->right);
            break;
*/
        case EXPRSTMT:
            //do the right hand pointer in this node
            //can be NUMBER, EXPR, CALL, or VAR, we need the value to be
            //in t6 when we are done.
	  //can switch this to a function later
            switch (p->right->type) {
                case NUMBER:
                sprintf(s,"li  $t6 %d",p->right->value);
                emit(fp,"",s,"#Load number into $t6 for if stmt");
                break;

                case EXPR:
                emitAST(p->right);
                sprintf(s,"lw  $t6, %d($sp)",p->right->symbol->offset*WORDSIZE);
                emit(fp,"",s,"#load the value from the stack into t6");
                break;

                case IDENT:
                emit_ident(p->right);
                emit(fp,"","lw  $t6, ($t2)", "#Load the value from the stack into t0 for ifstmt");
                break;

                case CALLSTMT:
		  emitAST(p->right);
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
