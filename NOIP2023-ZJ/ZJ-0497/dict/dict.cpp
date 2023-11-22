#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,p[27],s[3001][27];char a[3001][3001];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)p[a[i][j]-'a']++;
		for(int j=25,cnt=0;j>=0;j--)
			while(p[j])a[i][++cnt]=j,p[j]--;
	}
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			s[j][a[i][j]]++;
	for(int j=1;j<=m;j++)
		for(int i=1;i<26;i++)
			s[j][i]+=s[j][i-1];
	for(int i=1;i<=n;i++)
	{
		int is=0;
		for(int j=1;j<=m;j++)
		{
			int x=a[i][m-j+1];
			if(x==a[i][j])
			{
				if(s[j][x]==1)
				{
					is=1;
					break;
				}
				else if(s[j][x-1]==0)continue;
				else 
				{
					is=-1;
					break;
				}
			}
			else
			{
				if(!s[j][x])
				{
					is=1;
					break;
				}
				else if(!x||(x>0&&s[j][x-1]==0))continue;
				else
				{
					is=-1;
					break;
				}
			}
		}
		if(is==1)cout<<1;
		else cout<<0;
	}
	cout<<'\n';
	return 0;
}
