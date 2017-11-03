/*************************************************************
    emit.c
    Written by: Brian O'Dell  April, 2017
    This file along with it's header is a collection of functions
    adapted from ASTprinting. It is meant to take a valid Abstract
    Syntax Tree (AST) and generate mips assembly code from it.

    This program will give mips based on the AST. Therefore, if the
    AST was not made properly the code my not work as expected.
    There is not a check to see that the tree is correct.

    It should be noted that mips "pseudo instructions" were used
    when deemed appropriate. Mainly, it the case of determining
    equal/not equal in expressions. This was done for ease
    of programming alone, it should have no effect on runtime.

    The main driver of the program is emitAST, it is located at
    the bottom of the file.

    Preconditions:
        1.) It is assumed that the program is passed a valid AST.
            It only handles the AST format that was developed in
            conjunction with this emitter. If different variable names,
            pointers, etc are used there will be segmentation faults.
        2.) It is assumed that the AST files will be included in
            any file/ program that calls these functions. They are
            not included here to prevent re-declaring structs, etc.
        3.) It is assumed that FILE * fp is handled before calling
            these functions, and that it points to a valid output.
            It has been tested to work on files and stdout.
        4.) It is assumed this will be run on linux systems, other
            operating systems, including other UNIX based systems,
            have not been tested. Therefore, they are not guaranteed
            to work properly.
        5.) There must be a "main" function in the AST, or the output
            may not be runnable on simulators or machines.

    Postconditions:
        1.) Mips code will be emitted to the location FILE * fp
            points to when the program is run.
        2.) Said mips code will be in standard format, i.e.
            LABEL  COMMAND  COMMENT
        3.) The mips code will execute the functions descibed
            by the AST.

*************************************************************/

#include "emit.h"
#include <stdlib.h>
int stackval;
static int LTEMP=0;

/**
  * Helper function to generate labels for jumps
  * After execution the return will be a label such as _L3
  * The label will be unique, in that it can not be one the user
  * could make, and will be the next one in numeric sequence
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
  * Preconditions:
  *     1.) All args are not NULL
  *     2.) char x, is not used anywhere else, to prevent overwrites
  * Postconditions:
        1.) The line with all the data will be output to fp
 */
void emit(FILE * fp, char * label, char * cmd, char * comment)
{
    char x[100];
    sprintf(x,"%s\t%s\t\t%s\n",label,cmd,comment);
    fprintf(fp,"%s",x);
}

/**
  * Helper function to emit identifiers, goal is to have t2 be the
  * correct location in memory for said identifier.
  * Preconditions:
  *     1.) p must be an IDENT node
  *     2.) If p is an array the things allowed inside  brackets are only
  *         Numbers, Expressions, Identifiers, Function calls.
  *         Other things will not work correctly.
  *     3.) The identifier was already declared in the symbol table,
  *         If this is not handled elsewhere correctly, there will
  *         segmentation faults
  * Postconditions:
  *     1.) Recursive calls will be used to emit things other than Numbers
  *         in array brackets
  *     2.) $t2 will be the exact memory location of the desired variable
 */
void emit_ident(ASTnode * p)
{   //check to see if it is a global
    if(p->symbol->level==0)
    {   //if NULL it is scalar
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

                case CALLSTMT:
                emit_callstmt(p->right);
                emit(fp,"","addu $t3, $v0, 0","#Move return value into t3");
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

                case CALLSTMT:
                emit_callstmt(p->right);
                emit(fp,"","addu $t3, $v0, 0","#Move return value into t3");
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
  * Helper function that will emit the code for expressions
  * The goal is to have the value of the evaluated expression in its
  * place in the stack, to use it later
  * Preconditions:
  *     1.) p must be a valid EXPR node
  *     2.) The left hand side(LHS) and right hand side(RHS) can only be
  *         Numbers, Identifiers, other expressions, and function calls.
  *         Other things will not work correctly
  *     3.) The expression has an enrty in the symbol table,
  *         even if temporary
  * Postconditions:
  *     1.) The value of the evaluated expression will be in the correct
  *         location in the stack, found by its offset in the symbol table
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
        emit(fp,"","addu $t0, $v0, 0","#Get return for LHS");
        break;

        default:
        fprintf(stderr,"unhandled type in emit_expr");
        exit(1);
    }
    //need to store t0 bc RHS could mess it up
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
        emit(fp,"","addu $t1, $v0, 0","#Get return for RHS");
        break;

        default:
        fprintf(stderr,"unhandled type in emit_expr");
        exit(1);
    }

    //restore t0 after handling RHS
    sprintf(s,"lw  $t0, %d($sp)",p->symbol->offset*WORDSIZE);
    emit(fp,"",s,"#Get what was in t0 back form the stack");

    //evaluate the expression properly using t0 and t1
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


/**
  * Helper function to emit iterative stmts, specifially while statements
  * Preconditions:
  *     1.) p is a valid ITERSTMT node, it has a p->right, and a p->s1
  *     2.) p->right can only be a Number, Identifier, Expression,
  *         or function call. Others will not work
  *     3.) s1 should be some kind of statment or block statement
  * Postconditions:
  *     1.) temporary labels will be emitted, based on the form
  *         provided by the genLabel function
  *     2.) The expression in p->right will emitted recursively
  *         and be evaluated in mips
  *     3.) If the expression is false, the loop will stop by jumping out
  *     4.) If the expression is true, the statments that were emitted
  *         recursively by the program will execute. After each iteration
  *         the expression will be re-evaluated.
  *     5.) Everything needed to emit the loops will be done after execution
  *         of this helper function.
 */
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
        break;

        case IDENT:
        emit_ident(p->right);
        emit(fp,"","lw  $t0, ($t2)", "#Load value from stack in t0 for while");
        break;

        case CALLSTMT:
        emit_callstmt(p->right);
        emit(fp,"","lw  $t0, ($v0)","#Load value from return for whilestmt");
        break;
    }
    //condition no satisfied jump out
    sprintf(s,"beq $t0 $0 %s",L4);
    emit(fp,"",s,"#WHILE expression false jump out");

    //recursively emit Statement(can be block)
    emitAST(p->s1);
    sprintf(s,"j   %s", L3);
    emit(fp,"",s,"#jump back to beginning of WHILE");

    //make target to jump out
    sprintf(s,"%s:  ",L4);
    emit(fp,s,"  ","#target to stop executing loop");
}//end emit_iteration


/**
  * Helper function to emit if statements
  * Preconditions:
  *     1.) p must be a valid IFSTMT node, it has a p->right,
  *         a p->s1, and an optional p->s2 for ELSE
  *     2.) p->right can only be a Number, Identifier, expression
  *         or function call. Others will not work correctly
  *     3.) p->s1 and p->s2(if it exists) should be some
  *         kind of statement or block statment
  * Postconditions:
  *     1.) temporary labels will be emitted based on the form from genLabel
  *     2.) The expression in p->right will be emitted recursively,
  *         it will be evaluated in mips to check the branch
  *     3.) If the expression was true, the statment/s in s1 will be executed
  *     4.) If the expression was false, the statment/s in s2 will
  *         be executed, if no else was declared only the label is made.
  *     5.) s1 and s2 statment/s will be emitted recursively
  *         and be in the proper place
  *     6.) All things needed for the IFSTMT will be complete
  *         after this function executes
 */
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
        emitAST(p->right);
        sprintf(s,"lw  $t0, %d($sp)",p->right->symbol->offset*WORDSIZE);
        break;

        case IDENT:
        emit_ident(p->right);
        emit(fp,"","lw  $t0, ($t2)", "#Load value from stack in t0 for ifstmt");
        break;

        case CALLSTMT:
        emit_callstmt(p->right);
        emit(fp,"","addu $t0, $v0, 0","#get value from return into t0");
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
    if(p->s2 != NULL)
        emitAST(p->s2);

    //label to jump over else stmts
    sprintf(s,"%s:    ",L2);
    emit(fp,s,"","# End of IF");
}//end emit_ifstmt

/**
  * Helper function to emit a list of function call args
  * Unfortunately, there must be repeated code for the cases in the switch
  * statement. This is because function calls must work differently
  * in order to work correctly alongside other things like recursion.
  * Preconditions:
  *     1.) p is a valid ARG node, it has a p->right, it may have p->left
  *     2.) p->right is the expression in the arg,
  *         p->left is the next arg in the list if it exists
  *     3.) p->right can never be NULL, and must be a Number, Identifier,
  *         expression or function call. Others will not work
  *     4.) argNum must be passed correctly so it is saved in the stack
  *     5.) offsetDownFromSP is the maxoffset of the function being called
  *     6.) this function isn't called if args are void
  * Postconditions:
  *     1.) After one exectution the value of the arg will be in the
  *         slot of the stack they belong when the funciton is called.
  *         In other words it will be:
  *         SP - offsetDownFromSP + (argNum+1)*WORDSIZE
  *     2.) It is recursive, so if there is another arg in the list
  *         the function will run again until all args are done
  *     3.) After this function finishes completely, all the args for a
  *         function call will be emitted and stored in their future locations
 */
void emit_args(ASTnode * p, int argNum, int offsetDownFromSP)
{
    switch(p->right->type)
    {
        case NUMBER:
        sprintf(s,"li  $t0, %d",p->right->value);
        emit(fp,"",s," #Load imeddiate into t0 for arg");
        //move the sp temporarily
        sprintf(s,"subu $t6, $sp, %d",offsetDownFromSP);
        emit(fp,"",s,"# put where the new sp should be in t0");
        emit(fp,"","sw  $sp, ($t6)","# save the old sp");
        emit(fp,"","addu $sp, $t6, 0","#move the sp now");

        //store the value and move sp back
        sprintf(s,"sw  $t0 %d($sp)",(argNum+1)*WORDSIZE);
        emit(fp,"",s,"#store the value of arg into the stack");
        emit(fp,"","lw  $sp, ($sp)","#Put sp back where it goes");
        break;

        case IDENT:
        emit_ident(p->right);
        emit(fp,"","lw  $t0, ($t2)"," #arg is an ID load into t0");
        //move the sp temporarily
        sprintf(s,"subu $t6, $sp, %d",offsetDownFromSP);
        emit(fp,"",s,"# put where the new sp should be in t0");
        emit(fp,"","sw  $sp, ($t6)","# save the old sp");
        emit(fp,"","addu $sp, $t6, 0","#move the sp now");

        //store the value and move sp back
        sprintf(s,"sw  $t0 %d($sp)",(argNum+1)*WORDSIZE);
        emit(fp,"",s,"#store the value of arg into the stack");
        emit(fp,"","lw  $sp, ($sp)","#Put sp back where it goes");
        break;

        case EXPR:
        emit_expr(p->right);
        sprintf(s,"lw  $t0, %d($sp)",p->right->symbol->offset*WORDSIZE);
        emit(fp,"",s,"#Insert the value from the arg expr into t0");
        //move the sp temporarily
        sprintf(s,"subu $t6, $sp, %d",offsetDownFromSP);
        emit(fp,"",s,"# put where the new sp should be in t0");
        emit(fp,"","sw  $sp, ($t6)","# save the old sp");
        emit(fp,"","addu $sp, $t6, 0","#move the sp now");

        //store the value and move sp back
        sprintf(s,"sw  $t0 %d($sp)",(argNum+1)*WORDSIZE);
        emit(fp,"",s,"#store the value of arg into the stack");
        emit(fp,"","lw  $sp, ($sp)","#Put sp back where it goes");
        break;

        case CALLSTMT:
        //move the sp temporarily
        sprintf(s,"subu $t6, $sp, %d",offsetDownFromSP);
        emit(fp,"",s,"# put where the new sp should be in t0");
        emit(fp,"","sw  $sp, ($t6)","# save the old sp");
        emit(fp,"","addu $sp, $t6, 0","#move the sp now");

        emit_callstmt(p->right);

        //store the value and move sp back
        sprintf(s,"sw  $v0 %d($sp)",(argNum+1)*WORDSIZE);
        emit(fp,"",s,"#store the value of arg into the stack");
        emit(fp,"","lw  $sp, ($sp)","#Put sp back where it goes");
        break;

        default:
        fprintf(stderr,"unhandled type in emit_expr");
        exit(1);
    }//end switch for arg type

    //if we have more to do, recursively do the next arg
    if(p->left != NULL)
        emit_args(p->left,argNum +1,offsetDownFromSP);
}//end emit_args


/**
  * Helper function to emit return statements, it is also called
  * at the end of every funciton declaration to ensure default returns
  * Preconditions:
  *     1.) p is a valid RETURNSTMT node
  *     2.) if there is an expression/value to return it must be in p->s2
  *     3.) p->s2 can only be a number, expression, Identifier
  *         or function call, others will not work
  * Postconditions:
  *     1.) return expression will be executed if it exits,
  *         and the value will be in v0
  *     2.) the return address and correct stack pointer will be
  *         set and then we will jump to the value in the return address
  *     3.) If this was called without an expression p->s2 will be null,
  *         this is true when a function declaration called
  *         this method. In these two cases 0 is returned in v0
 */
//when this is call we will have the return stmt in p
void emit_return_stmt(ASTnode * p)
{
    //there is an expression to do if something is in p->s2
    if(p->s2 != NULL)
    {
        switch (p->s2->type)
        {
            case NUMBER:
            sprintf(s,"li $v0, %d",p->s2->value);
            emit(fp,"",s,"#Load number into $v0 for return");
            break;

            case EXPR:
            emitAST(p->s2);
            sprintf(s,"lw  $v0, %d($sp)",p->s2->symbol->offset*WORDSIZE);
            emit(fp,"",s,"#load value from stack into v0 for return");
            break;

            case IDENT:
            emit_ident(p->s2);
            emit(fp,"","lw  $v0, ($t2)","#Load value from stack in v0 for return");
            break;

            case CALLSTMT:
            emitAST(p->s2);
            //v0 already has our value nothing left to do
            break;

        }//end switch for expr type
    }//end if expr exists
    //the else means there was just "return;"
    else
        emit(fp,"","li $v0, 0","#Return 0 as default");

    sprintf(s,"lw  $ra, %d($sp)",1*WORDSIZE);
    emit(fp,"",s,"# Load the right value back into ra");
    emit(fp,"","lw  $sp, ($sp)","#add the right value back into sp");
    emit(fp,"","jr  $ra","");
}//end emit_return_stmt


/**
  * Helper function to emit call statements
  * Preconditions:
  *     1.) p must be a valid CALLSTMT node
  *     2.) p->name must be the name that of the function
  *         that is trying to be called in this node
  *     3.) p->symbol->mysize should be set to the function's
  *         maxoffset when the AST is being made, this is so
  *         we can properly temporarily move the sp the evaluate the args.
  *         If it is a void function this is ignored
  *     4.) If args exist they must be in p->right. They must be valid ARG
  *         nodes and linked where ARG->right is the expression in the arg,
  *         and ARG->left is the next arg if it exists
  * Postconditions:
  *     1.) Args will be handled by another function if they exist,
  *         this will happen before the call.
  *     2.) offsetDownFromSP will be the same as the function's maxoffset
  *     3.) The jump will be emitted, and a nop will be after.
  *         The program counter will be at the address of the
  *         nop after returning from the jump
 */
void emit_callstmt(ASTnode * p)
{
    if(p->right != NULL)
    {
        //offsetDownFromSP is the same as the function's maxoffset
        int offsetDownFromSP;
        offsetDownFromSP = p->symbol->mysize*WORDSIZE;
        emit_args(p->right,1,offsetDownFromSP);
    }//end if there are args

    //do the jump, the nop is just in case weird things happen
    //this is because PC will be here when we return
    //if an instruction was in this slot potential problems could happen
    sprintf(s,"jal %s",p->name);
    emit(fp,"",s,"#jump and linkthe function");
    emit(fp,"","nop","#Program counter will be here when we return");
}//end emit_callstmt


/**
  * Helper function to emit assignmet statements
  * Preconditions:
  *     1.) p must be a valid ASSIGN node, and must have a symbol table entry
  *         This should be created when the AST is made
  *     2.) p must have a p->s1, and p->right
  *     3.) p->s1 should be type EXPRSTMT, p->right should be type IDENT
  *     4.) The function that handles EXPRSTMT must put the value in $t6
  *     5.) The function that handles IDENT must put the address
  *         of the ident in $t2
  * Postconditions:
  *     1.) All the mips code needed will be emitted to
  *         execute Postcondition 2.
  *     2.) The value of the expression will be inserted into the stack
  *         at the location where the variable is
 */
void emit_assignment_stmt(ASTnode * p)
{
    //right = var, s1 = expression
    //Emit the expressionstmt, value will be in t6
    //but we want to save it so it wont get overwritten
    emitAST(p->s1);
    sprintf(s,"sw $t6, %d($sp)",p->symbol->offset*WORDSIZE);
    emit(fp,"",s,"#put the value in the right place for later");

    //Emit the ID, address will be in t2 we do this after the expression
    //Because emit_ident does not touch t0
    emit_ident(p->right);
    //First get value off the stack into t6
    //Now shove value in t6 into address at t2
    sprintf(s,"lw $t6, %d($sp)",p->symbol->offset*WORDSIZE);
    emit(fp,"",s,"#sget the value back formt he stack");
    emit(fp,"","sw  $t6, ($t2)","#Store the value in the right place");
}//emit_assignment_stmt


/**
  * Helper function to emit write statements, whatever is denoted will
  * appear on the console when the code is run
  * Preconditions:
  *     1.) p must be a valid WRITESTMT node
  *     2.) p->right must not be NULL, and can only be a Number, expression
  *         Identifier, function call, or a string literal
  *     3.) All Previously necessary actions must be properly done in
  *         the lex, yacc, and AST for this to work properly
  * Postconditions:
  *     1.) The appropriate actions will be emitted for p->right
  *     2.) a syscall will be emitted
  *     3.) when run the code will display the right thing in the console
  *
 */
void emit_write_stmt(ASTnode * p)
{
    switch (p->right->type) {
        case NUMBER:
        sprintf(s,"li  $a0, %d",p->right->value);
        emit(fp, "",s,"# Write a Number to the screen");
        emit(fp,"","li  $v0, 1"," #put 1 in v0 to print an integer");
        break;

        case EXPR:
        emitAST(p->right);
        sprintf(s, "lw  $a0, %d($sp)",p->right->symbol->offset*WORDSIZE);
        emit(fp, "",s," #fetch expr value");
        emit(fp,"","li  $v0, 1"," #put 1 in v0 to print an integer");
        break;

        case CALLSTMT:
        emit_callstmt(p->right);
        emit(fp,"","addu $a0, $v0, 0","#put the return in a0 to write");
        emit(fp,"","li  $v0, 1"," #put 1 in v0 to print an integer");
        break;

        case IDENT:
        emit_ident(p->right);
        emit(fp, "","lw  $a0, ($t2)"," #put id value in a0");
        emit(fp,"","li  $v0, 1"," #put 1 in v0 to print an integer");
        break;

        case STRINGNODE:
        emit(fp,"",".data","");
        sprintf(s,"%s: .asciiz  %s",p->right->name, p->right->str);
        emit(fp,s,"","");
        emit(fp,"",".text","");
        sprintf(s,"la  $a0, %s",p->right->name);
        emit(fp,"",s,"#Load address of the string");
        emit(fp,"","li  $v0, 4","#Load 4 to print a string");
        break;
    }
    emit(fp,"","syscall","");
}


/**
  * Helper function to emit expression statements, these are not the same
  * as an expression. In the grammar they are denoted by -> expression ';'
  * They usually occur in assignment statements, and function calls that
  * are alone on a line i.e. foo();
  * Preconditions:
  *     1.) p must be a valid EXPRSTMT node, and have a p->right
  *     2.) p->right can not be NULL, and must be only a Number, expression
  *         Identifier, or a function call.
  * Postconditions:
  *     1.) The value of the expression will be put into $t6 to use later
 */
void emit_expression_stmt(ASTnode * p)
{
    //do the right hand pointer in this node
    //can be NUMBER, EXPR, CALL, or VAR, we need the value to be
    //in t6 when we are done.
    switch (p->right->type) {
        case NUMBER:
        sprintf(s,"li  $t6, %d",p->right->value);
        emit(fp,"",s,"#Load number into $t6 for expr stmt");
        break;

        case EXPR:
        emitAST(p->right);
        sprintf(s,"lw  $t6, %d($sp)",p->right->symbol->offset*WORDSIZE);
        emit(fp,"",s,"#load the value from the stack into t6");
        break;

        case IDENT:
        emit_ident(p->right);
        emit(fp,"","lw  $t6, ($t2)", "#Load value from stack in t6 for exprstmt");
        break;

        case CALLSTMT:
        emit_callstmt(p->right);
        emit(fp,"","addu $t6, $v0, 0","#put the return in t6 to use later");
        break;

    }
}//end emit_expression_stmt


/**
  * Helper function to emit funciton declarations. The function will have
  * everything needed to run when we are done.
  * Preconditions:
  *     1.) p must be a valid FUNCTIONDEC node, it must have p->right
  *     2.) p->right must be the block statement, which are the
  *         statments the function should do when called
  *     3.) p->name must be the name of the function and not repeated anywhere
  *     4.) p->value must be the maxoffset required for the function
  * Postconditions:
  *     1.) The function name will be emitted in the .text segment
  *     2.) The old SP, and RA will be saved in 0(newSP) and 4(newSP) respectively
  *     3.) The sp will then be moved to the new place
  *     4.) All statments inside the block statment will be handled by the
  *         main driver of this program recursively
  *     5.) A generic return of 0 will be made by calling emit_return_stmt
  *         If another return is used explicitly this will never be reached
 */
void emit_fundec(ASTnode * p)
{
    //declare function as global
    emit(fp,".text","     \t\t","# Directive that says we are in code segment");
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

    //recursively do the block inside the dec
    emitAST(p->right);
    //we do the return stmt no matter what, if there is
    //a declared return this block doesn't get executed in asm
    emit_return_stmt(p);
}//end emit_fundec


/******************************************************************
*
* start of emitAST
*
* Main driver for emission of and Abstract Syntax Tree.
* Preconditions:
*   1.) p must be a valid node type in ENUM type of the AST
*   2.) only the types that are need by this driver ever reach this function.
*       Any unhandled types should never get here, and there is an error in
*       the AST if that error occurs
*   3.) p must have a type in p->type
*   4.) Overall program Preconditions must be true, and all preconditions
*       of helper function must be true for this to work as intended
* Postconditions:
*   1.) if p is NULL the function will simply return
*   2.) After this is called from a "program" node AST node all the mips code
*       for the program will be emitted.
*   3.) The driver will handle emission of the current node, and will be
*       recursively called to hanlde everything below it on the tree. The next
*       node in the tree is at p->left in every case, but expressions
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

        case FUNCTIONDEC:
            emit_fundec(p);
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
            emit_write_stmt(p);
            break;

        case ASSIGN:
            emit_assignment_stmt(p);
            break;

        case NUMBER:
            //want to load the value into t0 so we can use it
            sprintf(s, "li  $t0, %d", p->value);
            emit(fp,"",s," #Load immediate into t1");;
            break;

        case ITERSTMT:
            emit_iteration(p);
            break;

        case IFSTMT:
            emit_ifstmt(p);
            break;//end of IFSTMT

        case CALLSTMT:
            emit_callstmt(p);
            break;

        case EXPRSTMT:
            emit_expression_stmt(p);
            break;

        default:
            fprintf(stderr,"Unknown type in emitAST\n");
            exit(1);
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
