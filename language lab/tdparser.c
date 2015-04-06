#include<stdio.h>
int S();
int L();
int L1();
int i,save;
char str[50];
int S()
{
	int save=i;
	if(str[i]=='(')
	{
		i++;
		if(L())
		{
			if(str[i]==')')
				i++;
				return 1;
		}
	}
	i=save;
	if(str[i]=='a')
	{
		i++;
		return 1;	
	}
	return 0;
}
int L()
{
	if(S())
	{
		i++;
		if(L1())
			return 1;
	}
	return 0;
}
int L1()
{
	if(str[i]==',')
	{
		i++;
		if(S())
		{
			if(L1())
				return 1;
		}
	}
	return 1;
}
int main()
{
	i=0;
	printf("enter string\n");
	scanf("%s",str);
	if(S() && str[i]=='\0')
		printf("VALID");
	else
		printf("INVALID");
	return 0;
}
