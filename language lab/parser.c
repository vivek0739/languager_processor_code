#include<stdio.h>
char str[50];
int i,save;
int S();
int L();
int S()
{
	save=i;
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
	save=i;
	if(L())
	{
		if(str[i]==',')
		{
			i++;
			if(S())
			{
				return 1;
			}
		}
	}
	i=save;
	if(S())
		return 1;
	return 0;
}
int main()
{
	printf("enter string\n");
	scanf("%s",str);
	if(S() && str[i]=='\0')
		printf("valid");
	else
		printf("INVALID");
	return 0;
}
