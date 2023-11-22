#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=3e5+5;
struct node{
	int ip;
	int x,y;
}g[N];
int fa[N];
int c,t,n,m;
int f[50],vis[N];
int cc[50];
int ans=inf;
void check()
{
	int k=0;
	for(int i=1;i<=n;i++)
		cc[i]=f[i],k+=(f[i]==0);
	for(int i=1;i<=m;i++)
	{
		if(g[i].ip<2)
			cc[g[i].x]=g[i].ip;
		if(g[i].ip==2)
			cc[g[i].x]=-cc[g[i].y];
		if(g[i].ip==3)
			cc[g[i].x]=cc[g[i].y];
	}
	int b=0;
	for(int i=1;i<=n;i++)
		if(cc[i]!=f[i])
			b=1;
	if(!b)
		ans=min(ans,k);
}
void dfs(int x)
{
	if(x>n)
	{
		check();
		return;
	}
	f[x]=0;
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
	f[x]=-1;
	dfs(x+1);
}
int dfs1(int x,int sum,int p)
{
	if(vis[x]==2)
	{
		if(f[x]==0)
			return sum-1;
		return 0;
	}
	if(vis[x]==1)
	{
		if(p)
			return sum-1;
		return 0;
	}
	if(fa[x]==x)
	{
//		vis[x]=1;
		if(f[x]==0)
			return sum;
		return 0;
	}
	vis[x]=1;
	int s=dfs1(fa[x],sum+1,p|(f[x]==0));
	vis[x]=2;
	f[x]=fa[f[x]];
	return s;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=inf;
		scanf("%d%d",&n,&m);
		if(c<=2)
		{
			for(int i=1;i<=m;i++)
			{
				char c;
				int x,y;
				cin>>c;
				if(c=='-' || c=='+')
				{
					if(c=='-')
						g[i].ip=2;
					if(c=='+')
						g[i].ip=3;
					scanf("%d%d",&x,&y);
					g[i].x=x;
					g[i].y=y;
				}
				else
				{
					if(c=='T')
						g[i].ip=1;
					if(c=='F')
						g[i].ip=-1;
					if(c=='U')
						g[i].ip=0;
					scanf("%d",&x);
					g[i].x=x;
				}
			}
			dfs(1);
			printf("%d\n",ans);
		}
		else if(c<=4)
		{
			for(int i=1;i<=n;i++)
				f[i]=100;
			for(int i=1;i<=m;i++)
			{
				char c;
				cin>>c;
				int x;
				scanf("%d",&x);
				if(c=='T')
					f[x]=1;
				if(c=='F')
					f[x]=-1;
				if(c=='U')
					f[x]=0;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=(f[i]==0);
			printf("%d\n",ans);
		}
		else if(c<=6)
		{
			for(int i=1;i<=n;i++)
				f[i]=100,fa[i]=i,vis[i]=0;
			for(int i=1;i<=m;i++)
			{
				char c;
				cin>>c;
				int x,y;
				scanf("%d",&x);
				if(c=='U')
					f[x]=0;
				if(c=='+')
				{
					scanf("%d",&y);
					fa[x]=y;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])
					continue;
				ans+=dfs1(i,1,(f[i]==0));
			}
			printf("%d\n",ans);
		}
	}
}
