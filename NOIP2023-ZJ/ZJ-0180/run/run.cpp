#include<bits/stdc++.h>
#define ll long long
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
ll dp[1009][1009];
vector<pair<int,ll> > ve[1009];
void Solve()
{
	int n,m,k; ll d;
	cin>>n>>m>>k>>d;
	if(n>100000)
	{
		ll ans=0;
		F(i,1,m)
		{
			int x,y;ll v;
			cin>>x>>y>>v;
			if(k>=y && v-d*y>=0) ans+=v-d*y;
			
		}
		cout<<ans<<endl;
		return ;
	}
	F(i,1,m)
	{
		int x,y;ll v;
		cin>>x>>y>>v;
		ve[x].emplace_back(y,v);
	}
	F(i,1,n) sort(ve[i].begin(),ve[i].end());
	F(i,1,n)
	{
		int tot=0,ans=0;
		F(j,1,min(i,k))
		{
			while(tot<ve[i].size() && j>=ve[i][tot].first) ans+=ve[i][tot++].second;
			dp[i][j]=dp[i-1][j-1]-d+ans;
		}
		dp[i][0]=-1e18;
		F(j,0,min(i-1,k))
		{
			dp[i][0]=max(dp[i-1][j],dp[i][0]);
		}
	}
	ll ans=-1e9;
	F(i,0,k) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	F(i,1,n)ve[i].clear();
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)Solve();
}