#include <bits/stdc++.h>
const int INF = 1e9+10;
const int N = 3050;
using namespace std;
int n,m;
char s[N][N],sx[N][N],sn[N][N];
int mn[N],mx[N];
int ans[N];
bool cmp1(char a,char b)
{
	return (int)(a)<(int)(b);
}
bool cmp2(char a,char b)
{
	return (int)(a)>(int)(b);
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin>>n>>m;
	memset(mn,0x3f,sizeof mn);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++) cin>>s[i][j];
		sort(s[i]+1,s[i]+m+1,cmp1);
		memcpy(sn[i],s[i],sizeof sn[i]);
		sort(s[i]+1,s[i]+m+1,cmp2);
		memcpy(sx[i],s[i],sizeof sx[i]);
	}
	for(int i = 1;i<=n;i++)
	{
		bool flag=1;
		for(int j = 1;j<=n;j++)
		{
			if(i==j) continue;
			for(int k = 1;k<=m;k++)
			{
				if(sn[i][k]>sx[j][k])
				{
					flag=0;
					break;
				}
				else if(sn[i][k]<sx[j][k]) break;
			}
			if(!flag) break;
		}
		if(flag) ans[i]=1;
		else ans[i]=0;
	}
	for(int i = 1;i<=n;i++) cout<<ans[i];
	return 0;
}