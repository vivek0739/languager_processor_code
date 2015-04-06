//code for episilon closure
#include<bits/stdc++.h>
using namespace std;
#define MAX_STATE 6
#define MAX_TRANS 2
int trans[MAX_STATE][MAX_TRANS];
bool visited[MAX_STATE];
/*void episilonClosure(int s)
{
	stack<int> S;
	S.push(s);
	visited[s]=true;
	while(!S.empty())
	{
		int t=S.top();
		S.pop();
		for(int i=0;i<11;i++)
			if( trans[t][0] && visited[i]==false)
			{
				visited[i]=true;
				S.push(i);
			}
	}
}*/

int main()
{
	
	memset(trans,-1,sizeof(trans));
	trans[0][0]=1;
	trans[0][1]=3;
	trans[1][0]=2;
	trans[1][1]=4;
	trans[2][0]=2;
	trans[2][1]=3;
	trans[3][1]=3;
	trans[4][1]=5;
	trans[5][1]=3;
	
	memset(visited,false,sizeof(visited));
	visited[1]=true;
	visited[3]=true;
	visited[4]=true;
	visited[5]=true;
	char str[500];
	scanf("%s",str);
      int len=strlen(str);
      int state=0;
      /*for(int i=0;i<MAX_STATE;i++)
      {
      	cout<<endl;
      	for(int j=0;j<MAX_TRANS;j++)
      	{
      		cout<<trans[i][j]<<" ";
      	}
      }*/
      for(int i=0;i<len;i++)
      {
      	cout<<str[i]<<endl;
      	if(state == -1)
      	break;
      	state=trans[state][str[i]-'a'];
      	
      }
      if(state != -1 && visited[state] ) printf("accepted\n");
      else printf("not accepted\n");
		return 0;
}
