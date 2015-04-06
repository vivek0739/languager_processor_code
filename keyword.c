#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	char a[20];
	scanf("%s",a);
	if(strcmp(a,"if")==0||strcmp(a,"else")==0)
		printf("it is a keyword \n");
		else printf("it is not a keyword\n");
		return 0;

}