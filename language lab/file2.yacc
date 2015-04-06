%{
	#include<stdio.h>	
%}
%token I
%left '+' '-'
%left '*' '/'
%%
T: T '=' S {printf("valid expression\n");}
|I
S: E '+' E 
|E '-' E 
|E '*' E 
|E '/' E
E: I;
%%
yyerror()
{
	printf("Invalid expression\n");
	exit(1);
}
int yylex()
{
	char ch;
	ch=getchar();
	if(isalnum(ch))
		return I;
	else if(ch=='\n')
		return 0;
	else
		return ch;
}
int main()
{
	printf("enter the string\n");
	yyparse();
	return 0;
}