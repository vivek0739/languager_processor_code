#include<bits/stdc++.h>
using namespace std;
int m,d;
stack<int> S;
bool visited[10];
int g[10][10];
int main()
{
	int n;
	printf("enter size of matrix\n");
	scanf("%d",&n);
	printf("enter adjacency matrix\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		scanf("%d",&g[i][j]);
		}
	}
	printf("enter the back edge");
	scanf("%d%d",&m,&d);
	visited[d]=true;
	visited[m]=true;
	S.push(m);
	while(!S.empty())
	{
		int tp=S.top();
		S.pop();
		for(i =0 ;i<n;i++)
		{
			if(g[i][tp]==1)
			{
				if(!visited[i])
				{
					visited[i]=true;
					S.push(i);
				}
			}
		}
	}
	for(i=0;i<n;i++)
	if(visited[i])
	cout<<i<<" ";
}