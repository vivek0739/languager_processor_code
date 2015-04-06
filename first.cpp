#include<bits/stdc++.h>
using namespace std;
char gram[10][50];
	int n;
void first(char nonter,list<char>& gs,bool& ep)
{
	
	for(int j=0;j<n ;j++)
	{
		ep=false;
		if(gram[j][0]==nonter)
		{
				int k=2;
				int p=strlen(gram[j]);
				//printf("%d ",p);
				for(;k<p;k++)
				{
					if(gram[j][k]>='A' && gram[j][k]<='Z')
					first(gram[j][k],gs,ep);
					else if(gram[j][k]=='e')
					{
					ep=true;
					gs.push_back(gram[j][k]);
					break;
					}
					else
					{
					gs.push_back(gram[j][k]);
					break;
					}

					if(ep==false)
					break;
					k++;
				}
				
				
		}
	}
}
void follow(char nonter,list<char> gs,bool& ep)
{
	
	for(int j=0;j<n ;j++)
	{
		ep=false;
		if(gram[j][0]==nonter)
		{
				int k=2;
				int p=strlen(gram[j]);
				//printf("%d ",p);
				for(;k<p;k++)
				{
					if(gram[j][k]>='A' && gram[j][k]<='Z')
					first(gram[j][k],gs,ep);
					else if(gram[j][k]=='e')
					{
					ep=true;
					gs.push_back(gram[j][k]);
					break;
					}
					else
					{
					gs.push_back(gram[j][k]);
					break;
					}

					if(ep==false)
					break;
					k++;
				}
				
				
		}
	}
}
int main()
{
	printf("enter the no of production rule:");

	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%s",gram[i]);
	list<char> fs;
	char i;
	printf("enter the terminal symbol:\n");
	getchar();
	scanf("%c",&i);
	cout<<i<<"=";
		bool epsil=false;
		first(i,fs,epsil);
		
		list<char>:: iterator it;
		printf("{ ");
		for(it=fs.begin();it!=fs.end();it++)
			printf("%c, ",*it);
			printf(" }");
			cout<<endl;

	return 0;
}
