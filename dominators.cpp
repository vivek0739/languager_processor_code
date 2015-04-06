#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,g[30][30];
printf("enter number of nodes\n");
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
int n0;
printf("enter start node:\n");
scanf("%d",&n0);
int D[n][n],l,k;

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(i==n0)
		{
			if(j==n0)
			D[i][j]=1;
			else
			D[i][j]=0;
		}
		else
		{
		
				D[i][j]=1;
		}
     }
}

bool change=true;
while(change)
{
	change=false;
	
	for(i=0;(i<n);i++)
	{
		//cout<<"check";
		if(i!=n0)
		{
			int temp[10];
			//memset(temp,1,sizeof(temp));
			for(l=0;l<n;l++)
			{
				temp[l]=1;
			}
			for(j=0;j<n;j++)
			{
				if(g[j][i]==1)
				{

					for(k=0;k<n;k++)
					{
						if(D[j][k]==0)
						temp[k]=0;
					}
				}
			}

			temp[i]=1;
			for(l=0;l<n;l++)
				{
				if(D[i][l]!=temp[l])
				{
					change=true;
				}
				D[i][l]=temp[l];
			}
			/*for(l=0;l<n;l++)
			{
				cout<<temp[l]<<endl;
			}*/
		}
		
	}
}
for(i=0;i<n;i++)
{
	cout<<"parent for"<<i<<":"<<endl;
	for(j=0;j<n;j++)
	{
		if(D[i][j]==1)
		{
			cout<<j<<" ";
		}
	}
}

return 0;
}



