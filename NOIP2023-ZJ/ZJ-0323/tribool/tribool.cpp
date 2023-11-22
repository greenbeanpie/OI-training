#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const int inf = 0x3f3f3f3f;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = x*10+ch-48;ch = getchar();}
	return x*f;
}
int a[N];int n,m;
int val[N],fa[N*4];
inline int findx(int x)
{
	if(x==fa[x])return x;
	else return fa[x] = findx(fa[x]);
}
bool vis[N];
struct pos
{
	int v,w;
};
vector<pos>g[N*2];
bool cis[N];
int t[N];
void dfs(int u,int id)
{
	if(cis[u])return;
	cis[u] = 1;
	if(u>n+1)a[u-n-1] = id;
	else val[u] = id;
	for(pos nex:g[u])
	{
		int v = nex.v,w = nex.w;
		if(cis[v]==1)continue;
//		cis[v] = 1;
		dfs(v,id*w);
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int bian,T;scanf("%d%d",&bian,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0;i<=2*n+1;i++)g[i].clear();
		memset(vis,0,sizeof(vis));memset(cis,0,sizeof(cis));
		for(int i = 1;i<=n;i++)a[i] = i+1;
		for(int i = 1;i<=n;i++)val[i] = i+1;
		for(int i = 1;i<=4*n+10;i++)fa[i] = i;
		for(int i = 1;i<=m;i++)
		{
			char op;
			cin>>op;
//			cout<<"op:"<<op<<endl;
			if(op=='T')
			{
				int x;
				scanf("%d",&x);
				a[x] = 1;
			}
			else if(op=='F')
			{
				int x;
				scanf("%d",&x);
				a[x] = -1;
			}
			else if(op=='U')
			{
				int x;
				scanf("%d",&x);
				a[x] = 0;
			}
			else if(op=='+')
			{
				int u,v;
				scanf("%d%d",&u,&v);
				a[u] = a[v];
			}
			else
			{
				int u,v;
				scanf("%d%d",&u,&v);
				a[u] = -a[v];
			}
		}
		int ans = 0;
//		for(int i = 1;i<=n;i++)cout<<a[i]<<' ';
//		cout<<endl;
		int nn = n+1;
		for(int i = 1;i<=n;i++)
		{
			g[i+nn].push_back(pos{i,1});g[i].push_back(pos{i+nn,1});
			if(a[i]==0||a[i]==1||a[i]==-1)continue;
			if(a[i]<0)g[i+nn].push_back(pos{-a[i]-1,-1}),g[-a[i]-1].push_back(pos{i+nn,-1});
			else g[i+nn].push_back(pos{a[i]-1,1}),g[a[i]-1].push_back(pos{i+nn,1});
		}
		for(int i = 1;i<=n;i++)
		{
			if(a[i]==0)dfs(i+nn,0);
			else if(a[i]==1)dfs(i+nn,1);
			else if(a[i]==-1)dfs(i+nn,-1);
		}
//		cout<<endl;
//		for(int i = 1;i<=n;i++)cout<<val[i]<<' ';
//		cout<<endl;
		for(int i = 1;i<=n;i++)if(val[i]==0)ans++;
//		for(int i = 1;i<=n;i++)
//		{
//			if(a[i]==0||a[i]==1||a[i]==-1)continue;
//			if(a[i]>0)
//			{
//				if(val[a[i]])a[i] = val[a[i]];
//			}
//			else
//			{
//				if(val[-a[i]])a[i] = -val[-a[i]];
//			}
//		}
		for(int i = 1;i<=n;i++)
		{
			if(val[i]==0||val[i]==1||val[i]==-1||a[i]==0||a[i]==1||a[i]==-1)continue;
			if(a[i]<0)
			{
				int tmp = -a[i];
				int fx = findx(val[i]),fy = findx(tmp+n);
				fa[fx] = fy;
				fx = findx(val[i]+n),fy = findx(tmp);
				fa[fx] = fy;
//				if(findx(tmp)==findx(tmp+n)&&!vis[tmp])ans++,vis[tmp] = 1;
//				if(findx(val[i])==findx(val[i]+n)&&!vis[val[i]])ans++,vis[val[i]] = 1;
			}
			else
			{
				int fx = findx(val[i]),fy = findx(a[i]);
				fa[fx] = fy;
				fx = findx(val[i]+n),fy = findx(a[i]+n);
				fa[fx] = fy;
//				if(findx(a[i])==findx(a[i]+n)&&!vis[a[i]])ans++,vis[a[i]] = 1;
//				if(findx(val[i])==findx(val[i]+n)&&!vis[val[i]])ans++,vis[val[i]] = 1;
			}
		}
		for(int i = 1;i<=n;i++)
		{
			if(val[i]==0||val[i]==1||val[i]==-1)continue;
			if(findx(val[i])==findx(val[i]+n)&&!vis[val[i]])ans++,vis[val[i]] = 1;
		}
//		cout<<275<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
