%{
	#include<stdio.h>	
%}
%token A B X
%%
S: A S B
|X;
%%
yyerror()
{
	printf("the string does not match\n");
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
	else if(ch=='x')
		return X;
	else if(ch=='\n')
		return 0;
	else
		return ch;
}
int main()
{
	printf("enter the string\n");
	yyparse();
	printf("string is accepted\n");
	return 0;
}