#include<bits/stdc++.h>
using namespace std;
bool E();
bool T();
char *ptr;
bool F()
{
	char *item=ptr;
	if(*ptr=='(')
	{
		ptr++;
		if(E())
		{
		  if(*ptr==')')
		  {
		  	ptr++;
		  	return true;
		  }	
		}
	}
	ptr=item;
	if(isalnum(*ptr))//isalpha for identifier
	{
		ptr++;
		while(isalnum(*ptr))
		ptr++;
		
		return true;
	}
	return false;
}
bool Tprime()
{
	char *item=ptr;
	if(*ptr=='*')
	{
		ptr++;
		if(F())
		{
			if(Tprime())
			{
				return true;
			}
		}
	}
	ptr=item;
}
bool Eprime()
{
	char *item=ptr;
	if(*ptr=='+')
	{
		ptr++;
		if(T())
		{
			if(Eprime())
			{
				return true;
			}
		}
	}
	ptr=item;
}
bool T()
{
	if(F())
	{
		if(Tprime())
		{
			//if(*ptr=='$')
			return true;
		}	
	}
	return false;
}
bool E()
{

		if(T())
		{
			if(Eprime())
			{
				if(*ptr=='$')
				return true;
			}
		}
	return false;
}
int main()
{
	char str[200];
	scanf("%s",str);
	strcat(str,"$");
	cout<<str<<endl;
	ptr=&str[0];
	if(E())
	{
		printf("accpted\n");
	}
	else
	{
		printf("not");
	}
}
