#include<stdio.h>
int E();
int E1();
int T();
int T1();
int F();
char str[50];
int i,save;
int E()
{
	if(T())
	{
		if(E1())
			return 1;
	}
	return 0;
}
int E1()
{
	if(str[i]=='+')
	{
		i++;
		if(T())
		{
			if(E1())
				return 1;
		}
	}
		return 1;
}
int T()
{
	if(F())
	{
		if(T1())
			return 1;
	}
	return 0;
}
int T1()
{
	if(str[i]=='*')
	{
		i++;
		if(F())
		{
			if(T1())
				return 1;
		}
	}
	return 1;
}
int F()
{
	save=i;
	if(str[i]=='(')
	{
		i++;
		if(E())
		{
			if(str[i]==')')
			{
				i++;
				return 1;
			}
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
int main()
{
	printf("enter string\n");
	scanf("%s",str);
	i=0;
	if(E() && str[i]=='\0')
		printf("VALID");
	else
		printf("INVALID");
	return 0;
}
