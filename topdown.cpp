#include<bits/stdc++.h>
using namespace std;
bool S();
char *ptr;
bool Lprime()
{
	char *item=ptr;
	if(*ptr==',')
	{
		ptr++;
		if(S())
		{
			if(Lprime())
			{
				return true;
			}
		}
	}
	ptr=item;
}
bool L()
{
	if(S())
	{
		if(Lprime())
		{
			return true;
		}	
	}
	return false;
}
bool S()
{
	char *item=ptr;
	if(*ptr=='(')
	{
		ptr++;
		if(L())
		{
			if(*ptr==')')
			{
				ptr++;
				return true;
			}
		}
	}
	ptr=item;
	if(*ptr=='a')
	{
		ptr++;
		return true;
	}
	return false;
}
int main()
{
	char str[200];
	scanf("%s",str);
	ptr=&str[0];
	if(S())
	{
		printf("accpted\n");
	}
	else
	{
		printf("not");
	}
}
