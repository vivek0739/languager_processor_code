#include<stdio.h>
#include<string.h>
#include<stdbool.h>
inline bool check(char a){
	if((a>='a' && a<='z')||(a>='A' && a<='Z')||(a>='0'&& a<='9')||a=='_')
	return true;
	else return false;
}
int main()
{
	char a[20];
	scanf("%s",a);
	int i=0,flag=0;
	if((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z'))
	flag=1;
		
		int k=strlen(a);
		for(i=1;i<k;i++)
		if(!check(a[i]))
		{
			flag=0;
			break;
		}
		if(flag == 0) printf("it is not an identifier \n");
		else printf("it is an identifier \n");
		return 0;

}