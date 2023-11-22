#include <bits/stdc++.h>
#define int long long
#define F(a,b,c) for(int a=b ; a<=c ; a++)
#define pii pair<int,int>
#define open(A) { freopen(#A".in" , "r" , stdin); freopen(#A".out" , "w" , stdout); }
using namespace std;


const int LXB=1e5+8;
const int lxb=3e3+5;
const int mod=998244353;
const int INF=mod+114514;







int n,m;
int fa[LXB];
//
//int find(int x) {
//	return (fa[x]==x?x:fa[x]=find(fa[x])) ;
//}

vector<pii> e[LXB]; 
int fb[LXB];

void change(int x)
{
	for(int p=0 ; p<e[x].size() ; p++){
		pii y=e[x][p];
		e[fa[x]].push_back({y.first,y.second*fb[x]});
		fb[y.first] = y.second*fb[x];
		fa[y.first] = fa[x];
	}
	while(e[x].size()) e[x].pop_back();
}


int dis[LXB] , vis[LXB] , ans;
int size[LXB];
vector<int> ans2;
int dfs(int u , int t)
{
	int f=0;
	for(int p=0 ; p<e[u].size() ; p++){
		pii y=e[u][p];
		if(fa[y.first]!=u or vis[y.first]) continue;
		if(dis[y.first]!=INF){
			if(t*y.second==-1) ans2.push_back(y.first);
			continue;
		}
		dfs(y.first , y.second*t);
		size[u] += size[y.first];
	}
	vis[u]=1;
	size[u]++;
	return size[u];
}

void solve()
{
	cin>>n>>m;
	ans=0;
	F(i,1,n+3) {
		fa[i]=i , fb[i]=1 , dis[i]=INF , vis[i]=size[i]=0;
		while(e[i].size()) e[i].pop_back();
		while(ans2.size()) ans2.pop_back();
	}
	fa[n+1]=n+1 , fa[n+2]=n+2;
	char v;  int x,y;
	F(i,1,m){
		cin>>v;
		if(v=='T'){
			cin>>x;
			if(fa[x]!=x) {
				change(x);
			}
			fa[x]=n+1;
			e[n+1].push_back({x,1});
			fb[x]=1;
		}
		if(v=='F'){
			cin>>x;
			if(fa[x]!=x) {
				change(x);
			}
			fa[x]=n+1;
			e[n+1].push_back({x,-1});
			fb[x]=-1;
		}
		if(v=='U'){
			cin>>x;
			if(fa[x]!=x) {
				change(x);
			}
			fa[x]=n+2;
			e[n+2].push_back({x,0});
			fb[x]=0;
			
		}
		if(v=='+'){
			cin>>x>>y;
			if(x==y) continue;
			if(fa[x]!=x) {
				change(x);
			}
			fa[x]=y;
			e[y].push_back({x,1});
			fb[x]=1;
		}
		if(v=='-'){
			cin>>x>>y;
			if(fa[x]!=x) {
				change(x);
			}
			fa[x]=y;
			e[y].push_back({x,-1});
			fb[x]=-1;
		}
	}
	F(i,1,n) dis[i]=INF;
	dfs(n+1,1); ans+=dfs(n+2,0)-1;
	F(i,1,n){
		if(!vis[i]) 
			dis[i]=0 , dfs(i,1);
	}
	for(int i=0 ; i<ans2.size() ; i++){
		ans += size[ans2[i]];
	}
	cout<<ans<<endl;
	
}

int col[LXB];
void solve2()
{
	cin>>n>>m;
	char v ; int x;
	F(i,1,n) col[x]=0;
	F(i,1,m){
		cin>>v>>x;
		col[x]=v;
	}
	int ans = 0;
	F(i,1,m) if(col[i]=='U') ans++;
	cout<<ans<<endl;
}

signed main()
{
	int c,T=1;
	open(tribool);
	cin>>c>>T;
	while(T--)
	{
		if (c!=3 and c!=4)
			solve();
		if (c==3 or c==4)
			solve2();
	}
}
