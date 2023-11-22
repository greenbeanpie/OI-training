#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100010;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = x*10+ch-48;ch = getchar();}
	return x*f;
}
struct pos
{
	int l,r,v;
};
vector<pos>g[N];
int cost[1010][1010];
int dp[1010];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int bian = read(),T = read();
	while(T--)
	{
		int n,m,k,d;n = read();m = read();k = read();d = read();
		if(n<=1000)
		{
			memset(cost,0,sizeof(cost));
			memset(dp,0,sizeof(dp));
			for(int i = 0;i<=n;i++)g[i].clear();
			for(int i = 1;i<=m;i++)
			{
				int x,y,v;x = read();y = read();v = read();
				if(y>k)continue;
				if(x-y+1<1)continue;
				g[x].push_back(pos{x-y+1,x,v});
//				cout<<x-y+1<<' '<<x<<endl;
			}
			for(int i = 1;i<=n;i++)
			{
				int sum = 0;
				for(int j = i;j<=min(n,i+k-1);j++)
				{
					for(pos cur:g[j])
					{
						if(cur.l>=i)sum+=cur.v;
					}
					cost[i][j] = max(0ll,sum-(j-i+1)*d);
//					cout<<i<<' '<<j<<' '<<cost[i][j]<<endl;
				}
			}
			int ans = 0;
			for(int i = 1;i<=n+1;i++)
			{
				for(int j = 0;j<=k&&i-j>=1;j++)
				{
//					cout<<i<<' '<<j<<endl;
					dp[i] = max(dp[i],dp[i-j-1]+cost[i-j][i-1]);
				}
				ans = max(ans,dp[i]);
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i = 1;i<=m;i++)
			{
				int x,y,v;x = read();y = read();v = read();
				if(y>k)continue;
				if(x-y+1<1)continue;
			}
			cout<<0<<endl;
		}
	}
	return 0;
}
