#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[2][3001][3001];
bool cmp(int x,int y)
{
	for(int i=0;i<m;i++)
	{
		if(s[1][y][i]>s[0][x][i])
			return 0;
		if(s[1][y][i]<s[0][x][i])
			return 1;
	}
	return 1;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>s[0][i][j];
		sort(s[0][i],s[0][i]+m);
		for(int j=0;j<m;j++)
			s[1][i][m-j-1]=s[0][i][j];
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool f=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(cmp(i,j))
			{
				f=0;
				break;
			}
		}
		if(f)cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}