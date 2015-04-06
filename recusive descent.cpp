#include<bits/stdc++.h>
using namespace std;
void E();
void T();
char *ptr;
void Error()
{
	printf("not acc");
	exit(0);
}
void F()
{
   if(isalnum(*ptr))//isalpha for identifier
	{
		ptr++;
		while(isalnum(*ptr))
		ptr++;
	}
	else if(*ptr=='(')
	{
		ptr++;
		E();
		  if(*ptr==')')
		  {
		  	ptr++;
		  }	
             else
		  {
		  	Error();
		  }
	}
	else
		  {
		  	Error();
		  }
	
}
void Tprime()
{
	if(*ptr=='*')
	{
		ptr++;
		F();
		Tprime();
	}
}
void Eprime()
{
	if(*ptr=='+')
	{
		ptr++;
		T();
		Eprime();
	}
}
void T()
{
	F();
	Tprime();
}
void E()
{
		T();
		Eprime();
}
int main()
{
	char str[200];
	scanf("%s",str);
	cout<<str<<endl;
	ptr=&str[0];
	E();
	printf("accpted\n");
	return 0;
}
