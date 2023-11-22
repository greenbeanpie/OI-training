#include<bits/stdc++.h>
using namespace std;
typedef long long lr;
constexpr int N=1010,M=100100;
int c,t,n,m,k,d;
vector<pair<int,int> > v[N];
struct targ
{
	int x,y,val;
	inline bool operator <(const targ &b)const
	{
		return (x!=b.x)? x<b.x:y<b.y;
	}
}tar[M];
namespace Solve1
{
	lr dp[N][N],sum[N][N];
	void main()
	{
		for(int i=0; i<=n; ++i)
			for(int j=0; j<=n; ++j)
				dp[i][j]=0xcfcfcfcfcfcfcfcf,sum[i][j]=0;
		dp[0][0]=0;
		for(int i=1; i<=n; ++i)
			v[i].clear();
		for(int i=1; i<=m; ++i)
			v[tar[i].x].emplace_back(make_pair(tar[i].y,tar[i].val));
		for(int i=1; i<=n; ++i)
		{
			int now=0,sz=v[i].size();
			for(int j=1; j<=i; ++j)
			{
				sum[i][j]=sum[i][j-1];
				while(now<sz&&v[i][now].first==j)
					sum[i][j]+=v[i][now].second,++now;
			}
		}
		for(int i=0; i<n; ++i)
			for(int j=0; j<=i; ++j)
			{
				if(j<k)
					dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-d+sum[i+1][j+1]);
				dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
			}
		lr mx=0;
		for(int i=0; i<=n; ++i)
			mx=max(mx,dp[n][i]);
		cout<<mx<<'\n';
	}
}
namespace Solve2
{
	lr dp[M][2],lst[M];
	void main()
	{
		for(int i=1; i<=m; ++i)
			for(int l=0; l<=1; ++l)
				dp[i][l]=0xcfcfcfcfcfcfcfcf;
		dp[1][0]=0;
		if(tar[1].y<=k)
			dp[1][1]=tar[1].val;
		lst[1]=tar[1].y;
		for(int i=2; i<=m; ++i)
		{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			if(tar[i].y<=k)
			{
				dp[i][1]=dp[i-1][0]+tar[i].val-1ll*d*tar[i].y;
				if(lst[i-1]+tar[i].y<=k)
					dp[i][1]=max(dp[i][1],dp[i-1][1]+tar[i].val-1ll*d*tar[i].y);
			}
			lst[i]=tar[i].y;
			if(tar[i].x-tar[i].y==tar[i-1].x)
				lst[i]+=lst[i-1];
		}
		cout<<max(dp[m][0],dp[m][1])<<'\n';
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		for(int i=1; i<=m; ++i)
			cin>>tar[i].x>>tar[i].y>>tar[i].val;
		sort(tar+1,tar+1+m);
		if(c<=9)
			Solve1::main();
		else
			Solve2::main();
	}
	return 0;
}
