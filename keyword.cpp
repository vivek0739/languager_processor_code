#include<bits/stdc++.h>
using namespace std;
int mov[8][2]={
		{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
long long int key[11][11];

vector<string> v;
int  solve(int x1,int y1,int x2,int y2)
{	
	if(x1 == x2 && y1 == y2)
		return 0;
	int cost=9999999;
	for(int k=0;k<8;k++)
	{
		int i=x1+mov[k][0];
		int j=y1+mov[k][1];
		if(i>=0 && i<10 && j>=0 && j<10)
		{
			if(key[i][j]==-1)
				key[i][j]=solve(i,j,x2,y2);
			cost=min(cost,key[i][j]+3);
		}
		key[x1][y1]=cost;
	}	
	return cost;
}
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		memset(key,-1,sizeof(key));
		cout<<solve(x1,y1,x2,y2)<<endl;
	}
	
}
