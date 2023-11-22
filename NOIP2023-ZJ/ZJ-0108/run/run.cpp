#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<utility>
#include<algorithm>
/*
struct tree
{
	void build(int k,int l,int r)
	{
		if (l==r)
	}
};
*/
int subt,t,n,m,k,d;
long long dp[100005],tag[100005],now,ans;
std::vector< std::pair<int,long long> > p[100005];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&subt,&t);
	while (t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int i=1;i<=m;i++)
		{
			int x,y;long long v;
			scanf("%d%d%lld",&x,&y,&v);
			p[x].push_back(std::make_pair(y,v));
		}
		for (int i=0;i<=n+1;i++) dp[i]=-2000000000000000000;
		now=0;
		for (int i=1;i<=n;i++)
		{
			dp[i]=now;
			for (int x=std::max(1,i-k);x<=i-1;x++) now=std::max(now,dp[x]);
			for (int x=1;x<=i;x++) dp[x]=dp[x]-d;
			for (int x=1;x<=n;x++) tag[x]=0;
			for (int x=0;x<(int)p[i].size();x++)
			{
				int l=p[i][x].first;long long val=p[i][x].second;
				if (i-l+1>=1) tag[i-l+1]=tag[i-l+1]+val;
			}
			for (int x=i;x>=1;x--) tag[x]=tag[x]+tag[x+1],dp[x]=dp[x]+tag[x];
//			printf("Day %d\n",i);
//			for (int i=1;i<=n;i++) printf("%lld ",dp[i]);puts("");
		}
//		printf("%lld\n",now);
		ans=-2000000000000000000;
		for (int i=std::max(1,n-k+1);i<=n;i++) ans=std::max(ans,dp[i]);
		ans=std::max(ans,now);
		printf("%lld\n",ans);
		for (int i=1;i<=n;i++) p[i].clear();
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<utility>
#include<algorithm>
struct tree
{
	void build(int k,int l,int r)
	{
		if (l==r)
	}
};
int subt,t,n,m,k,d;
long long dp[100005],now,ans;
std::vector< std::pair<int,long long> > p[100005];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&subt,&t);
	while (t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int i=1;i<=m;i++)
		{
			int x,y;long long v;
			scanf("%d%d%lld",&x,&y,&v);
			p[x].push_back(std::make_pair(y,v));
		}
		for (int i=0;i<=n+1;i++) dp[i]=-2000000000000000000;
		now=0;
		for (int i=1;i<=n;i++)
		{
			dp[i]=now;
			for (int x=std::max(1,i-k);x<=i-1;x++) now=std::max(now,dp[x]);
			for (int x=1;x<=i;x++) dp[x]=dp[x]-d;
			for (int x=0;x<(int)p[i].size();x++)
			{
				int l=p[i][x].first;long long val=p[i][x].second;
				for (int t=1;t<=i-l+1;t++) dp[t]=dp[t]+val;
			}
//			printf("Day %d\n",i);
//			for (int i=1;i<=n;i++) printf("%lld ",dp[i]);puts("");
		}
//		printf("%lld\n",now);
		ans=-2000000000000000000;
		for (int i=std::max(1,n-k+1);i<=n;i++) ans=std::max(ans,dp[i]);
		ans=std::max(ans,now);
		printf("%lld\n",ans);
		for (int i=1;i<=n;i++) p[i].clear();
	}
	return 0;
}
*/