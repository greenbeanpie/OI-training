#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5+5;
int c,T,n,m,a[MAXN],cnt,tot,fa[MAXN],siz[MAXN],vis[MAXN];
int xx[MAXN],yy[MAXN],now[MAXN],opt[MAXN];
bool used[MAXN];
char ch[MAXN];
vector<int> G[MAXN];
void solve(char c,int pos)
{
	if(c=='T') a[pos]=n+1;
	if(c=='F') a[pos]=n+2;
	if(c=='U') a[pos]=n+3;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	fa[fx]=fy,siz[fy]+=siz[fx];
}
void solve1(char c,int pos)
{
	if(c=='U') a[pos]=n+3;
	else 
	{
		int y;
		scanf("%d",&y);
		a[pos]=a[y];
	}
}
void add(int x,int y)
{
	if(x==y) return;
	G[x].push_back(y),G[y].push_back(x);
}
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)now[i]=a[i];
		for(int i=1;i<=m;i++)
		{
			if(opt[i]>=1&&opt[i]<=3) now[xx[i]]=opt[i];
			if(opt[i]==4) now[xx[i]]=now[yy[i]];
			if(opt[i]==5) now[xx[i]]=(now[yy[i]]<3?3-now[yy[i]]:now[yy[i]]);
		}
		for(int i=1;i<=n;i++) if(now[i]!=a[i]) return;
		int res=0;
		for(int i=1;i<=n;i++) if(now[i]==3) res++;
		cnt=min(cnt,res);
		return;
	}
	for(int i=1;i<=3;i++) a[x]=i,dfs(x+1);
}
void dfs1(int uuu,int ccc)
{
	vis[uuu]=ccc;
	for(int i=0;i<G[uuu].size();i++)
	{
		int vvv=G[uuu][i];
		if(!vis[vvv]) dfs1(vvv,ccc);	
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		if(c==1||c==2)
		{
			for(int i=1;i<=m;i++)opt[i]=xx[i]=yy[i]=0;
			for(int i=1;i<=m;i++)
			{
				scanf("%s",ch);
				scanf("%d",&xx[i]);
				if(ch[0]=='T') opt[i]=1;
				if(ch[0]=='F') opt[i]=2;
				if(ch[0]=='U') opt[i]=3;
				if(ch[0]=='+')
				{
					opt[i]=4;
					scanf("%d",&yy[i]);
				}
				if(ch[0]=='-') 
				{
					opt[i]=5;
					scanf("%d",&yy[i]);
				}
			}
			for(int i=1;i<=n;i++)a[i]=0;
			cnt=n+1;
			dfs(1);
			printf("%d\n",cnt);
		}
		if(c==3||c==4)// U T F
		{
			int x;
			for(int i=1;i<=n;i++) a[i]=0;
			cnt=0;
			for(int i=1;i<=m;i++)
			{
				scanf("%s",ch);
				scanf("%d",&x);
				solve(ch[0],x);
			}
			for(int i=1;i<=n;i++)if(a[i]==n+3)cnt++;
			printf("%d\n",cnt);
		}
		if(c==5||c==6)// U +
		{
			int x;
			for(int i=1;i<=n;i++) a[i]=i,fa[i]=i,siz[i]=1,used[i]=0;
			cnt=tot=0;
			for(int i=1;i<=m;i++)
			{
				scanf("%s",ch);
				scanf("%d",&x);
				solve1(ch[0],x);
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=1&&a[i]<=n) merge(a[i],i);
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==n+3)
				{
					int u=find(i);
					if(!used[u]) cnt+=siz[u],used[u]=1;	
				}
			}
			printf("%d\n",cnt);
		}
		if(c==7||c==8)// + -
		{
			for(int i=1;i<=n;i++)a[i]=i;
			for(int i=1;i<=2*n;i++)fa[i]=i,G[i].clear(),vis[i]=0;
			cnt=tot=0;
			for(int i=1;i<=m;i++)
			{
				scanf("%s",ch);
				int u,v;
				scanf("%d %d",&u,&v);
				if(ch[0]=='+') a[u]=a[v];
				else a[u]=-a[v];
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=i) 
				{
					if(a[i]>0) add(i,a[i]),add(i+n,a[i]+n);
					else add(i,n-a[i]),add(i+n,-a[i]);
				}
			}
			for(int i=1;i<=2*n;i++)
			{
				if(!vis[i]) dfs1(i,++tot);
			}
			for(int i=1;i<=n;i++) if(vis[i]==vis[i+n]) cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}
