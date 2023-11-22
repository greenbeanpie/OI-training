#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long int LL;
const int N = 5e3+5;
int c,t;
int n,m;
char a[N][5];
int minn=INT_MAX;
void read()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cout<<i;
		cin>>a[i][1];
		if(a[i][1]=='+'||a[i][1]=='-') 
		{
			cin>>a[i][2]>>a[i][3];
		}
		else cin>>a[i][2];
	}
}
int check(string strin)
{
	string str=strin;
	for(int i=1;i<=m;i++)
	{
		char x=a[i][1];
		int y=a[i][2]-'0',z=a[i][3]-'0';
		switch(x)
		{
			case '-':
				{
					if(str[z]=='T')
						str[y]='F';
					else if(str[z]=='F')
						str[y]='T';
					else 
						str[y]='U';
					break;		
				}
			case '+':
				{
					str[y]=str[z];
					break;		
				}
			case 'T':
				{
					str[y]='T';
					break;		
				}
			case 'F':
				{
					str[y]='F';
					break;		
				}
			case 'U':
				{
					str[y]='U';
					break;		
				}
		}
	}
	if(str==strin)
	{
		int sum=0;
		for(int i=1;i<=str.length();i++)
		{
			if(str[i]=='U')
				sum++;
		}
		return sum;
	}
	return INT_MAX;
}
void dfs(string str)
{
	if(str.length()==n)
	{
		minn=min(check(str),minn);
		return;
	}
	dfs(str+"T");
	dfs(str+"F");
	dfs(str+"U");
}
int main()
{	
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		read();
		minn=n;
		dfs("");
		cout<<minn<<'\n';
	}
	return 0;
}
