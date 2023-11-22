#include<bits/stdc++.h>
using namespace std;//WY AK IOI!!!
inline long long read()
{
	long long s=0,k=1;
	char r=getchar();
	while(!isdigit(r)) k=(r=='-')?-1:1,r=getchar();
	while(isdigit(r)) s=s*10+r-'0',r=getchar();
	return s*k;
}
#define d read()
#define ll long long
#define Maxn 10010
#define Size 2010
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll dp[Size][Size];
vector<pair<ll,ll> >p[Size];
void solve()
{
	ll n=d,m=d,k=d,cost=d;
	for(int i=0;i<=n;i++)
	{
		p[i].clear();
		for(int j=0;j<=k;j++)
			dp[i][j]=0;
	}
	for(int i=0;i<m;i++)
	{
		ll x=d,y=d,v=d;
		p[x].pb(mp(y,v));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min((ll)i,k);j++)
			dp[i][j]=dp[i-1][j-1]-cost;
		for(int j=0;j<=min((ll)i-1,k);j++)
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
		if(p[i].size())
			for(auto [y,v]:p[i])
				for(int j=y;j<=k;j++)
					dp[i][j]+=v;
	}
	ll maxn=0;
	for(int i=0;i<=k;i++)
		maxn=max(maxn,dp[n][i]);
	printf("%lld\n",maxn);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ll test=d;ll t=d;
	if(test>=17&&test<=18)
	{
		while(t--)
		{
			ll n=d,m=d,k=d,cost=d,ans=0;
			for(int i=0;i<m;i++)
			{
				ll x=d,y=d,v=d;
				ans+=max(0ll,v-cost*y);
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(t--) solve();
}
