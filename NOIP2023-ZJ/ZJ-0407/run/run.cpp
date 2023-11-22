#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int f,t,n,m,k,d,a[N],sum[N],ans;
struct hhh
{
	int x,y,v;
}g[N];
void dfs(int x)
{
	if(x==n+1)
	{
		int anss=0,flag=0;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=m;i++) if(sum[g[i].x]-sum[g[i].x-g[i].y]==g[i].y) anss+=g[i].v;
		anss-=sum[n]*d;
		for(int i=k;i<=n;i++) 
			if(sum[i]-sum[i-k]==k) 
			{
				flag=1;
				break ;
			}
		if(flag==0) ans=max(anss,ans);
		return ;
	}
	a[x]=0;
	dfs(x+1);
	a[x]=1;
	dfs(x+1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>f>>t;
	if(f<=2)
	{
		for(int j=1;j<=t;j++)
		{
			ans=-1e9;
			cin>>n>>m>>k>>d; k++;
			for(int i=1;i<=m;i++) cin>>g[i].x>>g[i].y>>g[i].v;
			dfs(1);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
