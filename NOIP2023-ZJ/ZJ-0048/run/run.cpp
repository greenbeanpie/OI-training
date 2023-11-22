#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
constexpr int N=1010;
typedef long long ll;
constexpr ll inf=0x3f3f3f3f3f3f3f3f;

int n,m,k,d,C,T;
vector <pair<int,int> > v[N];
ll dp[N][N];

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&C,&T);
	if (C<=9)
	{
		while (T--)
		{
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for (int i=1;i<=n;i++) v[i].clear();
			for (int i=1,x,y,z;i<=m;i++)
			{
				scanf("%d%d%d",&x,&y,&z);
				v[x].push_back({y,z});
			}
			dp[0][0]=0;
			for (int i=1;i<=k;i++)
			{
				dp[0][i]=-inf;
			}
			for (int i=1;i<=n;i++)
			{
				sort(v[i].begin(),v[i].end());
			}
			for (int i=1;i<=n;i++)
			{
				int l=v[i].size(),p=0;
				dp[i][0]=0;
				for (int j=0;j<=k;j++)
				{
					dp[i][0]=max(dp[i][0],dp[i-1][j]);
				}
				ll sum=0;
				for (int j=1;j<=k;j++)
				{
					while (p<l&&v[i][p].fi<=j)
					{
						sum+=v[i][p].se;
						p++;
					}
					dp[i][j]=dp[i-1][j-1]-d+sum;
				}
			}
			ll mx=0;
			for (int i=0;i<=k;i++)
			{
				mx=max(mx,dp[n][i]);
			}
			printf("%lld\n",mx);
		}
	}
	return 0;
}