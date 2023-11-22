#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,m;
char c[N][N],mn[N],mx[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	bool flg;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
		mn[i]=mx[i]=c[i][1];
		for(int j=2;j<=m;j++)
		{
			mn[i]=min(mn[i],c[i][j]);
			mx[i]=max(mx[i],c[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		flg=1;
		for(int j=1;j<=n;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(mn[i]>=mx[j])
			{
				flg=0;
				break;
			}
		}
		cout<<flg;
	}
}