#include<bits/stdc++.h>
using namespace std;
char  string1[200];
char table1[12][9];
int table2[12][9];
int i,save;

#define ID 0
#define ADD 1
#define MULT 2
#define OPBR 3
#define CLBR 4
#define DOLLAR 5
#define E 6
#define T 7
#define F 8


void createtable()
{
	table1[0][0]='s';table2[0][0]=1;
	table1[0][3]='s';table2[0][3]=4;
	table1[0][6]='g';table2[0][6]=1;
	table1[0][7]='g';table2[0][7]=2;
	table1[0][8]='g';table2[0][8]=3;

	table1[1][1]='s';table2[1][1]=6;
	table1[1][5]='a';

	table1[2][1]='r';table2[2][1]=2;
	table1[2][2]='s';table2[2][1]=7;
	table1[2][4]='r';table2[2][4]=2;
	table1[2][5]='r';table2[2][5]=1;

	table1[3][1]='r';table2[3][1]=4;
	table1[3][2]='r';table2[3][2]=4;
	table1[3][4]='s';table2[3][4]=4;
	table1[3][5]='s';table2[3][5]=4;

	table1[4][0]='s';table2[4][0]=5;
	table1[4][3]='s';table2[4][3]=4;
	table1[4][6]='g';table2[4][6]=8;
	table1[4][7]='g';table2[4][7]=2;
	table1[4][8]='g';table2[4][8]=4;

	table1[5][1]='r';table2[5][1]=6;
	table1[5][2]='r';table2[5][2]=6;
	table1[5][4]='r';table2[5][4]=6;
	table1[5][5]='r';table2[5][5]=6;

	table1[6][0]='s';table2[6][0]=5;
	table1[6][3]='s';table2[6][3]=4;
	table1[6][7]='g';table2[6][7]=9;
	table1[6][8]='g';table2[6][8]=3;

	table1[7][0]='s';table2[7][0]=5;
	table1[7][3]='s';table2[7][3]=4;
	table1[7][8]='g';table2[7][8]=10;

	table1[8][1]='s';table2[8][1]=6;
	table1[8][4]='s';table2[8][4]=11;

	table1[9][1]='r';table2[9][1]=1;
	table1[9][2]='s';table2[9][2]=7;
	table1[9][4]='r';table2[9][4]=1;
	table1[9][5]='r';table2[9][5]=1;

	table1[10][1]='r';table2[10][1]=3;
	table1[10][2]='r';table2[10][2]=3;
	table1[10][4]='r';table2[10][4]=3;
	table1[10][5]='r';table2[10][5]=3;

	table1[11][1]='r';table2[11][1]=5;
	table1[11][2]='r';table2[11][2]=5;
	table1[11][4]='r';table2[11][4]=5;
	table1[11][5]='r';table2[11][5]=5;

}

void error()
{
	printf(" string1 not valid\n");
	exit(1);
}

short int gettoken() {
  /* ignore blanks */
  while( string1[i]==' ')
    i++;
  /* definition for identifier */
  if(isalpha( string1[i])) {
    save=i;
    i++;
    while( string1[i]!=0 &&  string1[i]!='*' &&  string1[i]!='+' &&  string1[i]!=')' &&  string1[i]!='(') {
      if(!isalnum( string1[i++]))
    error();
    }
    return ID;
  }
  else if( string1[i]=='+') {
    save=i;
    i++;
    return ADD;
  }
  else if( string1[i]=='*') {
    save=i;
    i++;
    return MULT;
  }
  else if( string1[i]=='(') {
    save=i;
    i++;
    return OPBR;
  }
  else if( string1[i]==')') {
    save=i;
    i++;
    return CLBR;
  }
  else if( string1[i]==0) {
    return DOLLAR;
  }
}

void parse()
{
	createtable();
	stack<int> S;
	S.push(0);
	//while(!S.empty())
	//{
		int ch=gettoken();
		char action=table1[S.top()][ch];
		int arg=table2[S.top()][ch];
		cout<<action<<" "<<arg<<" "<<ch<<endl;
		/*if(action=='s')
		{
			S.push(ch);
			S.push(arg);
		}
		else if(action ='r')
		{
			switch(arg)
			{
				case 1:
				{
					while(S.top()!=E)
						S.pop();
					S.push(E);
					S.push(table1[S.top()-1][S.top()]);
					break;
				}
				case 2:
				{
					S.pop();
					S.pop();
					S.push(E);
					S.push(table1[S.top()-1][S.top()]);
					break;
				}
				case 3:
				{
					while(S.top()!=T)
						S.pop();
					S.push(T);
					S.push(table1[S.top()-1][S.top()]);
					break;
				}
				case 4:
				{
					S.pop();
					S.pop();
					S.push(T);
					S.push(table1[S.top()-1][S.top()]);
					break;
				}
				case 5:
				{
					while(S.top()!=OPBR)
						S.pop();
					S.push(F);
					S.push(table1[S.top()-1][S.top()]);
					break;
				}
				case 6:
				{
					S.pop();
					S.pop();
					S.push(F);
					S.push(table1[S.top()-1][S.top()]);
					break;
				}

			}
		}
		else if(action == '\0')
		{

			error();
			exit(0);
		}
		else
		{

			printf("accpted\n");
			exit(1);	
//		}*/


//	}

}
int main()
{
	printf("enter  string1\n");
	scanf("%s", string1);
	strcat(string1,"$");
	parse();
	
	return 0;
}