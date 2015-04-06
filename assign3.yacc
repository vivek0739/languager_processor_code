%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token I
%right '^'
%left '+' '-' 
%left '*' '/'
%%
T: T '=' S { printf("string accepted");}
 | I
S: E '+' E
 | E '-' E
 | E '*' E
 | E '/' E
E: I
;


%%
yyerror()
{
	printf("bad string\n");
	exit(1);
}
int yylex()
{
	char ch=getchar();
	if(isalnum(ch))
	 return I;
	else if(ch == '\n')
	 return 0;
	else 
		return ch;
}
int main()
{
	yyparse();

	return 0;
}