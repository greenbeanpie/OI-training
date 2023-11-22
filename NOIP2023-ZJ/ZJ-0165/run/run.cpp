#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,k,d,mx;
int dp[1010][1010];
vector<pair<int,int> >vc[1010];
int search(int x,int v)
{
	int l=0,r=vc[x].size()-1,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(v>=vc[x][mid].first)
		{
			l=mid+1;
			ans=vc[x][mid].second;
		}
		else
			r=mid-1;
	}
	return ans;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=n;++i)
			vc[i].clear();
		for(int i=1;i<=m;++i)
		{
			int x,y,v;
			scanf("%lld%lld%lld",&x,&y,&v);
			vc[x].push_back({y,v});
		}
		for(int i=1;i<=n;++i)
		{
			sort(vc[i].begin(),vc[i].end());
			for(int j=1;j<(int)vc[i].size();++j)
				vc[i][j].second+=vc[i][j-1].second;
		}
		mx=dp[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			dp[i][0]=mx;
			for(int j=1;j<=k&&j<=i;++j)
			{
				dp[i][j]=dp[i-1][j-1]-d+search(i,j);
				mx=max(mx,dp[i][j]);
			}
		}
		printf("%lld\n",mx);
	}
	return 0;
}
