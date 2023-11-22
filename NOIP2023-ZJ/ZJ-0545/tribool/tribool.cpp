#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int ID,T,n,m,ans;

struct Ele{
	int id,r,w;
} a[N];

struct Dsu{
	int f,sz,w;
	bool vis;
} fa[N<<2];

inline void init()
{
	ans=0;
	for(int i=1;i<=n;++i) a[i]={0,0,2};
	for(int i=1;i<=n;++i) fa[i]={i,1,2,0};
	for(int i=n+1;i<=n<<1;++i) fa[i]={i,0,2,0};
}

inline int findfa(int x)
{
	return fa[x].f==x?x:fa[x].f=findfa(fa[x].f);
}

inline void unionfa(int u,int v)
{
	int p=findfa(u),q=findfa(v),t;
		if(u<=n) t=findfa(u+n);
		else t=findfa(u-n);
	if(p!=q)
	{
		fa[p].f=q,fa[q].sz+=fa[p].sz;
		if(q==t) fa[q].w=0;
		else if(fa[p].w!=2) fa[q].w=fa[p].w;
	}
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>ID>>T;
	while(T--)
	{
		cin>>n>>m;
		init();
		
		char op;
		for(int i=1;i<=m;++i)
		{
			cin>>op;
			if(op=='+'||op=='-')
			{
				int u,v;
				cin>>u>>v;
				a[u]={v,44-op,a[v].w};
			}
			else
			{
				int u;
				cin>>u;
				a[u]={0,0,2};
				if(op=='T') a[u].w=1;
				else if(op=='F') a[u].w=-1;
				else a[u].w=0;
			}
		}
		
		for(int u=1;u<=n;++u)
		{
			if(a[u].id)
			{
				int v=a[u].id;
				if(a[u].r==1) unionfa(u,a[u].id),
					unionfa(u+n,a[u].id+n);      
				else unionfa(u,a[u].id+n),
					unionfa(u+n,a[u].id);
			}
			else
			{
				int v=findfa(u),o=findfa(u+n);
				fa[v].w=a[u].w,fa[o].w=-a[u].w;
			}
		}
		
		for(int i=1;i<=n;++i)
		{
			int f=fa[i].f;
			if(!fa[f].vis)
			{
				fa[f].vis=1;
				if(!fa[f].w) ans+=fa[f].sz;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}