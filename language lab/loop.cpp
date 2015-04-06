#incluse<iostream>
#include<stack>
using namespace std;
int loop[100];
stack<int>s;
void insert(int a)
{
	if(loop[a]==0)
	{
		loop[a]=1;
		s.push(a);
	}
}
int main()
{
	int n;
	cin>>n;
	int graph[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>graph[i][j];
		}
	}
	int back_a,int back_b;
	cin>>back_a>>back_b;
	loop[back_b]=1;
	insert(back_a);
	while(!s.empty())
	{
		int m = s.top();
		s.pop();
		for(int i=0;i<n;i++)
		{
			if(graph[i][m]==1)
			{
				insert(i);
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		if(loop[i])
				   cout<<i<<endl;
	}
	return 0;
}
