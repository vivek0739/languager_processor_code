%{
#include<stdio.h>
%}
%token A B C
%%
S: A S C | X | A C
X: B X | B
%% 
yyerror()
{
printf("Not Accepted\n");
exit(1);
}
int yylex()
{
char ch;
ch=getchar();
if(ch=='a')
return A;
else if(ch=='b')
return B;
else if(ch=='c')
return C;
if(ch=='\n')
return 0;
else
return ch;
}
int main()
{
printf("Enter the expression\n");
yyparse();
printf("Accepted\n");
return 0;
}
