/*   Abstract syntax tree code

     This code is used to define an AST node,
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Shaun Cooper February 2015

    Edited by Brian O'Dell March 2017

    The link to the next node is left, except for expression

*/

#include "emit.h"

/**
 * Helper function to emit a line to a file, accepts:
 * a file pointer, a label, a command, and a comment
 * will use stdout for now instead of fp
 */
void emitf( char * label, char * cmd, char * comment)
{
   sprintf(s,"%s\t%s\t\t%s\n",label,cmd,comment);
   fprintf(stdout,s);
}

//function to emit edentifier code so that t2 is the direct
//access into memory for the identifier
void emit_ident (ASTnode * p)
{
 //check for scalar vs array
  if (p->right == NULL)
  {
    //is scalar
    sprintf(s,"li\t$t2\t%d",p->symbol->offset*WORDSIZE);
    emitf("",s,"# Load ID offset into $t2");
    emitf("","add\t$t2\t$t2\t$sp","# Create exact mem location for ID");
  }
  else
  {
    //is an array
  }
}

void emit_expr(ASTnode * p)
{
 //left hand side first
  switch(p->left->type) {
    case NUMBER:
      //li $t0 %d, p->left->value
      break;
    case IDENT:
      emit_ident(p->left);
      printf("lw $t0 ($t2) #LHS is an ID");
      break;
    default:
      printf("unhandled type in emit_expr");
      //exit(1);
   }
   //need to store t0 bc RHS could mess it up
   switch(p->right->type) {
     case NUMBER:
      //li $t1 %d, p->right->value
      break;
    case IDENT:
      emit_ident(p->right);
      printf("lw $t1 ($t2) #RHS is an ID");
      break;
    default:
      printf("unhandled type in emit_expr");
      //exit(1);
   }
   //need to restore t0 after handling RHS
}//end emit_expr

/*  Print out the abstract syntax tree */
void emitAST(ASTnode* p)
{
    if (p == NULL ) return;
    else {
        switch (p->type) {
	
        case VARDEC :
            printf("Variable  "); //one per ast node type
            /*if ((p->op) == INTDEC)
                printf("INT ");

            if (p->op == VOIDDEC)
                printf("VOID ");

            printf("%s", p->name);
            if (p->value > 0) //is an array
                printf("[%d]",p->value);

            printf("\n"); //finish with new line
            */
            break;

        case FUNCTIONDEC:
            if (p->op == INTDEC)
                printf("INT ");

            if (p->op == VOIDDEC)
                printf("VOID ");

            printf("FUNCTION %s \n",p->name);
            //print parameter list
	    /*
            if (p->s1 == NULL) {
                PT(level+2);
                printf( "(VOID)\n" );
            }//end if
            else {
                PT(level+2);
                printf("( \n");
                //recursively print parameters
                ASTprint(level+2,p->s1);
                PT(level+2);
                printf(") \n");
            }//end else
            //recursively print the block statment
            */
            emitAST(p->right);
            break;

        case EXPR: printf("EXPR ");
            if (p->name != NULL)
                printf("  %s = ", p->name);
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
           break;//EXPR break

        case  RETURNSTMT:
 /*           printf("Return statement\n");
            //recursively print return expression
            ASTprint(level+1, p->right);
            break;
*/
        case IDENT:
            emit_ident(p);
            break;

        case BLOCK:
            printf("BLOCK STATEMENT\n");
            //recursively print the contents of the block statement
            emitAST(p->right);
            break;


        case READSTMT:
            emit_ident(p->right);
	    printf(" li $v0 5 #read in an integer\n");
	    printf("syscall #call a READ NUMBER FUNCITON\n");
	    printf("sw $v0 ($t2) #store a READ number in t2\n");
            break;

        case WRITESTMT:
            switch (p->right->type) {
	      case NUMBER:
		sprintf(s,"li\t$a0\t%d",p->right->value);
		emitf("",s,"# Write a Number to the screen");
		break;
	      case EXPR:
		emitAST(p->right);
		printf("lw $a0 %d($sp) #fetch expr value\n",p->right->symbol->offset*4);
		break;
	      case CALLSTMT:
		break;
	      case IDENT:
		emit_ident(p->right);
		printf("lw $a0 ($t2) #put stuff in a0\n");
		break;
	    }
	    printf("syscall\n");
            break;
/*
        case ASSIGN:
            printf("Assignment STATEMENT\n");
            //recursively print var to be assigned and expression on right
            ASTprint(level+1,p->right);
            ASTprint(level+1,p->s1);
            break;

        case NUMBER:
            printf("NUMBER with value %d\n", p->value);
            break;

        case ITERSTMT:
            printf("WHILE STATEMENT\n");

            //recursively pritn out condition and a newline for seperation
            ASTprint(level+1,p->right);
            printf("\n");

            //recursively print out statment(could be block) and newline
            ASTprint(level+1,p->s1);
            printf("\n");
            break;

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

        case IFSTMT:
            printf("IF STATEMENT\n");

            //recursively print out condition and newline for seperation
            ASTprint(level+1,p->right);
            printf("\n");

            //recursively print out Statement(can be block) and newline
            ASTprint(level+1,p->s1);
            printf("\n");

            //handle the else Statement
            if(p->s2 != NULL){
                PT(level);
                printf("ELSE \n");
                ASTprint(level+2,p->s2);
            }
            break;

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

        case EXPRSTMT:
            printf("Expression Statement\n");
            //recursively print out the expression Statement
            ASTprint(level+1, p->right);
            break;
*/
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
