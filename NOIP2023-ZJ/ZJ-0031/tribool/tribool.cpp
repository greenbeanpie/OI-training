#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
namespace __Clonoth__
{
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=2e5+10;
int a[Max],b[Max];//T : 1; F : 0; U : -1
char opt[Max];
int c[Max],d[Max];
int n,m;
vector<int>e[Max];
int pos[Max];
int depth[Max];
int bel[Max];
int find(int i)
{
	return i==bel[i]?i:bel[i]=find(bel[i]);
}
inline void unite(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
		bel[x]=y;
}
inline int rev(const int &x)
{
	return ~x?!x:x;
}
bool tag[Max];
int val[Max];
int siz[Max];
bool flag;
void dfs(int u,int from)
{
	depth[u]=depth[from]+1;
	for(auto v:e[u])
		if(!depth[v])
			dfs(v,u);
		else
			if(depth[v]>=depth[u]&&(depth[v]-depth[u]+1)&1)
				flag=true;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		a[i]=i,b[i]=0,pos[i]=i;
	for(int i=1;i<=m;++i)
	{
		cin>>opt[i]>>c[i];
		int u=i+n;
		if(opt[i]=='T')
			a[u]=0,b[u]=1;
		if(opt[i]=='F')
			a[u]=0,b[u]=0;
		if(opt[i]=='U')
			a[u]=0,b[u]=-1;
		if(opt[i]=='+')
		{
			cin>>d[i];
			int v=pos[d[i]];
			a[u]=a[v],b[u]=b[v];
		}
		if(opt[i]=='-')
		{
			cin>>d[i];
			int v=pos[d[i]];
			a[u]=a[v],b[u]=rev(b[v]);
		}
		pos[c[i]]=u;
	}
	for(int i=1;i<=n;++i)
		bel[i]=i,siz[i]=0;
	for(int i=1;i<=n;++i)
	{
		int u=pos[i];
		if(a[u])
		{
			if(!b[u])
				unite(i,a[u]);
		}
		else
			tag[i]=true,val[i]=b[u];
	}
	for(int i=1;i<=n;++i)
	{
		int u=pos[i];
		if(a[u]&&b[u])
		{
			int x=find(i),y=find(a[u]);
			e[x].push_back(y);
			e[y].push_back(x);
		}
	}
	for(int i=1;i<=n;++i)
	{
		int u=pos[i];
		if(a[u]&&b[u])
			unite(i,a[u]);
	}
	for(int i=1;i<=n;++i)
	{
		if(tag[i])
			tag[find(i)]=true,val[find(i)]=val[i];
		++siz[find(i)];
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(i!=find(i))
			continue;
		if(tag[i])
		{
			if(val[i]==-1)
				ans+=siz[i];
		}
		else
		{
			flag=false;
			dfs(i,0);
			if(flag)
				ans+=siz[i];
		}
	}
	cout<<ans<<"\n";
}
void clear()
{
	for(int i=1;i<=n+m;++i)
		e[i].clear(),depth[i]=0,val[i]=0,tag[i]=false;
}
signed main()
{
	int o,t;
	cin>>o>>t;
	while(t--)
		solve(),clear();
	return 0;
}
}
signed main()
{
	freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	__Clonoth__::main();
	return 0;
}
