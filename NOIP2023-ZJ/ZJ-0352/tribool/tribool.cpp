#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1e3;

int c,T;
int fa[N],vis[N];

int n,m,ans;

vector<pair<int,int> > e[N];
#define pb push_back
#define fi first
#define se second

int dis[N];
bool flag[N],fl;
int sz;

void dfs(int u){
	flag[u]=1;sz++;
	if(fa[u]==n+3) fl=true;
	for(auto x:e[u]){
		int v=x.fi,w=x.se;
		if(!flag[v]) dis[v]=dis[u]^w,dfs(v);
		else if(dis[u]^w!=dis[v]) fl=true;
	}
}

void solve(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++) fa[i]=i,vis[i]=0,flag[i]=0,dis[i]=0,e[i].clear();
	for(int i=1,x,y;i<=m;i++){
		char op;
		cin>>op;
		if(op=='T') cin>>x,fa[x]=n+1;
		if(op=='F') cin>>x,fa[x]=n+2;
		if(op=='U') cin>>x,fa[x]=n+3;
		if(op=='+') cin>>x>>y,fa[x]=fa[y],vis[x]=vis[y];
		if(op=='-') cin>>x>>y,fa[x]=fa[y],vis[x]=vis[y]^1;
	}
	//for(int i=1;i<=n;i++) printf("i:%d fa:%d vis:%d\n",i,fa[i],vis[i]);
	for(int i=1;i<=n;i++){
		if(fa[i]<=n){
			e[i].pb({fa[i],vis[i]});
			e[fa[i]].pb({i,vis[i]});
		}
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			fl=false,sz=0;
			dfs(i);if(fl) ans+=sz;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;while(T--) solve();
	return 0;
}
/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/
