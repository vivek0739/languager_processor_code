//top down parsing
#include<stdio.h>

char *ptr;
bool S();
bool LPrime()
{
	char *ip=ptr;
	if(*ptr==",")
	{
		++ptr;
		if(LPrime())
		{
			return true;
		}
	}
	ptr=ip;
}
bool L()
{
	if(S())
	{
		if(LPrime())
		return true;
	}
	return false;
}
bool S()
{
	char *ip=ptr;
	if(*ptr=='(')
	{
		ptr++;
		if(L())
		{
			if(*ptr==')')
			return true;
		}
	}
	ptr=ip;
	if(*ptr == 'a')
	return true;
	return false;
}
int main()
{
	char str[50];
	scanf("%s",str);
	ptr=&str[0];
	if(S())
	printf("string accepted\n");
	else
	printf("error\n");
	return 0;
}