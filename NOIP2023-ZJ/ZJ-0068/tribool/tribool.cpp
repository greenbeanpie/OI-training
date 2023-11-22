#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
int c,t,n,m,nw[N],vis[N],gf,cnt,flu,tt=12939282,uu=12939283,ff=123939284;
vector<int>a[N];
void dfs(int x,int y){
	vis[x]=y,flu|=(y==uu),++cnt;
	for (int v:a[x]){
		if (v<0){
			int ng=y;
			if (ng==uu){
				if (vis[-v] && vis[-v]!=uu){gf=1;}
				if (!vis[-v]) dfs(-v,uu);
			}
			if (ng==tt){
				if (vis[-v] && vis[-v]!=ff){gf=1;}
				if (!vis[-v]) dfs(-v,ff);
			}
			if (ng==ff){
				if (vis[-v] && vis[-v]!=tt){gf=1;}
				if (!vis[-v]) dfs(-v,tt);
			}
		}else{
			if (vis[v] && vis[v]!=y){gf=1;}
			if (!vis[v]) dfs(v,y);
		}
	}
}
void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;++i) nw[i]=i,vis[i]=0,a[i].clear();
	while (m--){
		char c;cin>>c;
		if (c=='T'){
			int x;cin>>x;
			nw[x]=tt;
		}
		if (c=='U'){
			int x;cin>>x;
			nw[x]=uu;
		}
		if (c=='F'){
			int x;cin>>x;
			nw[x]=ff;
		}
		if (c=='-'){
			int x,y;cin>>x>>y;
			if (nw[y]<=n) nw[x]=-nw[y];
			else{
				if (nw[y]==uu) nw[x]=uu;
				if (nw[y]==tt) nw[x]=ff;
				if (nw[y]==ff) nw[x]=tt;
			}
		}
		if (c=='+'){
			int x,y;cin>>x>>y;
			nw[x]=nw[y];
		}
	}
	for (int i=1;i<=n;++i)
		if (nw[i]!=uu && nw[i]!=tt && nw[i]!=ff){
			a[i].push_back(nw[i]);
			int g=abs(nw[i]);
			if (nw[i]<0) a[g].push_back(-i);
			else a[g].push_back(i);
		}
	int ans=0;
	for (int i=1;i<=n;++i){
		if (vis[i]) continue;
		if ((nw[i]==uu) || (nw[i]==tt) || (nw[i]==ff)){
			cnt=flu=0,dfs(i,nw[i]);
			if (flu) ans+=cnt;
		}
	}
	for (int i=1;i<=n;++i){
		if (vis[i]) continue;
		cnt=gf=0,dfs(i,tt);
		if (gf) ans+=cnt;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--) solve();
	return 0;
}