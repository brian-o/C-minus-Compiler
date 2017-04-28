/*
lab5.l
Brian O'Dell
February, 2017
                        ***********
This lex routine will turn the file, expected to be written in "Cminus"
and will output the appropriate tokens for it.
If anything is not recognized it will output an error.
The routine keeps track of line numbers for help with mydebugging
*/
%{
int mydebug=0;
int lineNum=1;
#include "y.tab.h"
/*
when mydebug is 1, the program will ouput each token it sees,
otherwise it will only output the values of constants
*/
%}

%%

int                 {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return INT;}

if                  {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return IF;}

while               {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return WHILE;}

void                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return VOID;}

else                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return ELSE;}

return              {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return RETURN;}

write               {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return WRITE;}

read                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return READ;}

[=\-+*%/&|(){}><\;,\[\]] {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return (*yytext);}

"<="                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return LE;}

">="                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return GE;}

"!="                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return NE;}

"=="                {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    return EQ;}

[0-9]+              {if(mydebug)
                        fprintf(stderr,"%s\n",yytext);
                    yylval.value=atoi((const char *)yytext);
                    return NUM; }

[a-zA-Z][0-9a-zA-Z]* {if (mydebug)
                        fprintf(stderr,"ID: %s\n",yytext);
                      yylval.string=strdup(yytext);
                      return ID; }

[ \t]               {/*Eats whitespace*/}

\n                  {lineNum++;}

.                   {//If anything not defined is found, output an error
                    fprintf(stderr,"Lex Error: no rule found for:%s\n",yytext);
                    fprintf(stderr,"Found on Line Number: %d\n",lineNum);
                    }

%%

int yywrap(void)
{ return 1;}
