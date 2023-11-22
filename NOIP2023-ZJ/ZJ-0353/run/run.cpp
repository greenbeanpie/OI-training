#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=1e3+5;
struct node{
	int date,length,w;
}f[N];
long long dp1[N],dp2[N];
int n,m,ans;
int k,d;
int f1[N],f2[N];
int g[N];
bool cmp(node a,node b)
{
	if(a.date==b.date)
		return a.length<b.length;
	return a.date<b.date;
}
void check()
{
	for(int i=0;i<=n;i++)
		g[i]=0;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f1[i]==1)
			g[i]=g[i-1]+1,sum-=d;
		else
			g[i]=0;
		if(g[i]>k)
			return;
	}
	for(int i=1;i<=m;i++)
		if(g[f[i].date]>=f[i].length)
			sum+=f[i].w;
	ans=max(ans,sum);
}
void dfs(int x)
{
	if(x>n)
	{
		check();
		return;
	}
	f1[x]=0;
	dfs(x+1);
	f1[x]=1;
	dfs(x+1);
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
			scanf("%lld%lld%lld",&f[i].date,&f[i].length,&f[i].w);
		sort(f+1,f+m+1,cmp);
		if(c<=2)
		{
//			b=0;
			dfs(1);
			printf("%lld\n",ans);
		}
		else if(c==16 || c==17)
		{
//			for()
		}
	}
}
