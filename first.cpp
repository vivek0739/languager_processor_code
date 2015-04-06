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
				if(gram[j][k]>='A' && gram[j][k]<='Z')
				while(gram[j][k]>='A' && gram[j][k]<='Z')
				{
					first(gram[j][k],gs,ep);
					if(ep==false)
					break;
					k++;
				}
				if(gram[j][k]=='e')
				{
					ep=true;
					return;
				}
				else
				{
					gs.push_back(gram[j][k]);
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
	list<char> fs[n];
	for(int i=0;i<n;i++)
	{
		bool epsil=false;
		first(i,fs[i],epsil);
		list<char>:: iterator it;
		cout<<gram[i][0]<<"=";
		for(it=fs[i].begin();it!=fs[i].end();it++)
			printf("%c ",*it);
			cout<<endl;
	}
	return 0;
}
