#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],vis[N],dis[N];
int v[N<<1],nxt[N<<1],first[N],w[N<<1];
int tot;
inline void add_edge(register int from,register int to,int flow)
{
	v[++tot]=to;nxt[tot]=first[from];first[from]=tot;w[tot]=flow;
	v[++tot]=from;nxt[tot]=first[to];first[to]=tot;w[tot]=flow;
}
int f[N],size[N],ans;
inline int gf(register int x){return f[x]==x?x:f[x]=gf(f[x]);}
inline void merge(register int x,register int y)
{
	if(size[gf(x)]>size[gf(y)]) swap(x,y);
	size[gf(y)]+=size[gf(x)];
	f[gf(x)]=gf(y);
}
inline int dfs(register int x,register int d,register int fa)
{
	if(vis[x])
	{
		if((d-dis[x])&1)
		{
			ans+=size[gf(x)];
		}
		vis[x]=1;
		return 1;
	}
	dis[x]=d;
	vis[x]=1;
	for(register int go=first[x];go;go=nxt[go])
	{
		if(v[go]==fa) continue;
		if(dfs(v[go],d+w[go],x)) return 1;
	}
	return 0;
}
signed main(void)
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	register int testpoint,T;
	scanf("%d%d",&testpoint,&T);
	while(T--)
	{
		tot=0;
		register int n,m;
		scanf("%d%d",&n,&m);
		for(register int i=1;i<=n;i++) first[i]=0,vis[i]=0,dis[i]=0,a[i]=i,f[i]=i,size[i]=1;
		for(register int i=1;i<=m;i++)
		{
			char opt;
			cin>>opt;
			if(opt=='-')
			{
				register int u,v;
				scanf("%d%d",&u,&v);
				a[u]=-a[v];
			}
			else if(opt=='+')
			{
				register int u,v;
				scanf("%d%d",&u,&v);
				a[u]=a[v];
			}
			else if(opt=='T')
			{
				register int v;
				scanf("%d",&v);
				a[v]=1e5+1;
			}
			else if(opt=='F')
			{
				register int v;
				scanf("%d",&v);
				a[v]=1e5+2;
			}
			else
			{
				register int v;
				scanf("%d",&v);
				a[v]=1e5+3;
			}
		}
		ans=0;
		for(register int i=1;i<=n;i++)
		{
			if(a[i]==i) continue;
			if(a[i]==-i or abs(a[i])==1e5+3)
			{
				add_edge(i,i,1);
			}
			else if(abs(a[i])<=1e5)
			{
				add_edge(i,abs(a[i]),a[i]>0?0:1);
				if(gf(i)^gf(abs(a[i])))
				{
					merge(i,abs(a[i]));
				}
			}
		}
		for(register int i=1;i<=n;i++)
		{
			if(vis[gf(i)]) continue;
			register int root=gf(i);
			dis[root]=0;
			dfs(root,0,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}