#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=1e5+5;
int tt,n,m,val[N],f[N],sz,dep[N],siz[N];
bool uk[N],bp,vis[N];
vector<int> adj[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int u)
{
	vis[u]=true;
	bp=bp&&!uk[u];
	sz+=siz[u];
	for(int v:adj[u])
	{
		if(vis[v])bp=bp&&((dep[u]^dep[v])&1);
		else
		{
			dep[v]=dep[u]^1;
			dfs(v);
		}
	}
}
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
#endif
#endif
	scanf("%*d%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		F(i,0,n)val[i]=i;
		F(i,0,m)
		{
			char op;scanf(" %c",&op);
			if(op=='+'||op=='-')
			{
				int u,v;scanf("%d%d",&u,&v);--u,--v;
				if(op=='+')val[u]=val[v];
				if(op=='-')val[u]=~val[v];
			}
			else
			{
				int u;scanf("%d",&u);--u;
				if(op=='U')val[u]=n;
				if(op=='T')val[u]=n+1;
				if(op=='F')val[u]=n+2;
			}
		}
		F(i,0,n)if(val[i]<-n)
		{
			val[i]=~val[i];
			if(val[i]>n)
			{
				if(val[i]==n+1)val[i]=n+2;
				else val[i]=n+1;
			}
		}
		F(i,0,n)f[i]=i,uk[i]=false,vis[i]=false,siz[i]=0;
		F(i,0,n)if(val[i]<n&&val[i]>=0)f[find(i)]=find(val[i]);
		F(i,0,n)if(val[i]<0)
		{
			adj[find(i)].emplace_back(find(~val[i]));
			adj[find(~val[i])].emplace_back(find(i));
		}
		F(i,0,n)if(val[i]==n)uk[find(i)]=true;
		F(i,0,n)++siz[find(i)];
		int ans=0;
		F(i,0,n)if(!vis[i])
		{
			bp=true;sz=0;
			dfs(i);
			ans+=sz*!bp;
		}
		F(i,0,n)adj[i].clear();
		printf("%d\n",ans);
	}
	return 0;
}
