#include <bits/stdc++.h>
using namespace std;
int c,t,k,n,m,d;
struct cha{
	int x;
	int y;
	int v;
}challenge[114514];
int dp[1005][1005];
bool cmp(cha a,cha b)
{
	return a.x<b.x;
}
int maxi=0;
int len;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>challenge[i].x>>challenge[i].y>>challenge[i].v;
		}
		sort(challenge+1,challenge+1+m,cmp);
		int len=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(j>k) break;
				dp[i][j]=dp[i-1][j-1]-d;
				dp[i][0]=max(dp[i][0],dp[i][j]);
			}
			if(challenge[len].x==i)
			{
				for(int j=challenge[len].y;j<=i;j++)
				{
					dp[i][j]+=challenge[len].v;
					maxi=max(maxi,dp[i][j]);
				}
				len++;
			}
		}
	}
	cout<<maxi;
	return 0;
}
