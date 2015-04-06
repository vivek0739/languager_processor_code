%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token A B
%%
S: A S B
 | A B
 ;
%%
yyerror()
{
	printf("error\n");
	exit(1);
}
int yylex()
{
	char ch= getchar();
	if(ch == 'a')
	 return A;
	else if(ch == 'b')
	 return B;
	else if(ch == '\n')
	 return 0;
	else 
		return ch;
}
int main()
{
	printf("enter the expression\n");
	yyparse();
	printf("string is accepted\n");
	return 0;
}