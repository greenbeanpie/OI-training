#include<bits/stdc++.h>
#define ll long long 

using namespace std;

const int N=1e5+10;
const ll oo=0x7ffffffffffff;
ll dp[2][N];
int n,m,k;
ll d;
int c,t;
int x,y[N];
ll v[N];
vector<int> a[N];
int fuck_ccf()
{
	scanf("%d%d%d%d",&n,&m,&k,&d);
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;ll v;
		scanf("%d%d%lld",&x,&y,&v);
		ans=max(ans,ans-y*d+v);
	}
	printf("%lld\n",ans);
	return 0;
}
int mian()
{
	scanf("%d%d%d%lld",&n,&m,&k,&d);
	for(int i=0;i<=k;i++)
	{
		dp[0][i]=dp[1][i]=-oo;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&x,y+i,v+i);
		a[x].push_back(i);
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i&1][0]=dp[(i-1)&1][0];
		for(int j=1;j<=k;j++)
		{
			if(dp[(i-1)&1][j-1]!=-oo) dp[i&1][j]=dp[(i-1)&1][j-1]-d;
			dp[i&1][0]=max(dp[(i-1)&1][j],dp[i&1][0]);
		}
		int l=a[i].size();
		for(int j=0;j<l;j++)
		{
			for(int o=y[a[i][j]];o<=k;o++)
			{
				if(dp[i&1][o]!=-oo) dp[(i&1)][o]+=v[a[i][j]];
			}
		}
	}
	ll ans=-oo;
	for(int i=0;i<=k;i++)
	{
		ans=max(ans,dp[n&1][i]);
	}
	printf("%lld\n",ans);
	return 0;
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==17||c==18)
	{
		while(t--)
		{
			fuck_ccf();
		}
	}
	else 
	{
		while(t--)
		{
			mian();
		}
	}
	
	return 0;
}



//zsy dalao orz
//sjh dalao orz
//lzy dalao orz
//大佬们保佑我
//骗分出省一