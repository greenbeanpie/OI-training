#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int N=2e5+100;
int to[N],val[N],vis[N],vis1[N];
int col[N];
int n,m,pd,res=0;
vector<pii>g[N];
void dfs(int x,int fa)
{
	if(!fa)col[x]=0;
	if(x==n+3)return pd=0,void();
	vis[x]=1;
	for(auto t:g[x])
	{
		int y=t.fi,z=t.se;
		if(!vis[y])col[y]=col[x]^z,dfs(y,x);
		if(col[x]!=col[y]^z)return pd=0,void();
	}
}
void dfs1(int x)
{
	vis1[x]=1;col[x]=2;res++;for(auto t:g[x])if(!vis1[t.fi])dfs1(t.fi);
}
void solve()
{
	cin>>n>>m;res=0;
	to[n+1]=n+2;to[n+2]=n+1;to[n+3]=n+3;
	val[n+1]=val[n+2]=0;val[n+3]=1;
	for(int i=1;i<=n;i++)to[i]=i,val[i]=0;
	for(int i=1;i<=n+3;i++)col[i]=vis[i]=vis1[i]=0,g[i].clear();
	for(int i=1;i<=m;i++)
	{
		char c;int x,y;cin>>c;
		if(c=='T'||c=='F'||c=='U')
		{
			cin>>x;to[x]=c=='T'?n+1:c=='F'?n+2:n+3;val[x]=0;
		}
		else 
		{
			cin>>x>>y;
			if(c=='+')to[x]=to[y],val[x]=val[y];
			else to[x]=to[y],val[x]=val[y]^1;
		}
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<' '<<to[i]<<' '<<val[i]<<endl;
		g[i].push_back(mk(to[i],val[i])),g[to[i]].push_back(mk(i,val[i]));
	}
	for(int i=n+3;i>=1;i--)if(!vis[i]&&!vis1[i])
	{
		pd=1;dfs(i,0);
		if(pd)continue;
		dfs1(i);
	}
	for(int i=n+1;i<=n+3;i++)if(col[i]==2)res--;
	cout<<res<<endl;
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	for(int id=1;id<=T;id++)solve();
	return 0;
}
/*
1 3
2 2
T 2
U 2
*/