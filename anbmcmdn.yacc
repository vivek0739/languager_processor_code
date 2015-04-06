%{
#include<stdio.h>
%}
%token A B C D
%%
S: A S D | A D | X
X: B X C | B C
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
else if(ch=='d')
return D;
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
