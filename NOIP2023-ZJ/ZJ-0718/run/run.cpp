//样例全是大数据......祈祷我的DFS能拿个几分......
//祝愿xjhc的各位都能1= 
//fzx,wyz,zl,lyr,chm,xr,lhy,fsj,rbd,zy,jqz助我1= 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int c,t;
int n,m,k,d;
struct node{
	int l,r,w;
}a[N];
int vis[N];
int ans; 
bool cmp(node p1,node p2)
{
	if(p1.l==p2.l)
	{
		return p1.r<p2.r;
	}
	return p1.l<p2.l;
}
void dfs(int x,int cnt)
{
	if(x==n+1)
	{
		ans=max(ans,cnt);
		return ;
	}
	dfs(x+1,cnt);
	bool flag=true;
	int cn=0;
	for(int i=a[x].l-1;i>=0;i--)
	{
		if(vis[i]==0)
		{
			break;
		}
		cn++;
		if(cn+a[x].r-a[x].l+1>k)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		for(int i=a[x].l;i<=a[x].r;i++)
		{
			vis[i]=1;
		}
		dfs(x+1,cnt+a[x].w);
		for(int i=a[x].l;i<=a[x].r;i++)
		{
			vis[i]=0;
		}
	}else{
		dfs(x+1,cnt);
	}
	return;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			a[i].l=x-y+1;
			a[i].r=x;
			a[i].w=z-y*d;
		}
		sort(a+1,a+1+n,cmp);
		dfs(1,0);
		printf("%lld\n",ans);
	}
 	return 0;
}
