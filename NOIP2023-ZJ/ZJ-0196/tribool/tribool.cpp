#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ID,T;
int flg[N],p[N],vis[N];
int fa[N],tot[N],siz[N];
inline int find(int x) {
	if(!fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) flg[i]=0,p[i]=i;
	for(int i=1; i<=(n<<1); i++) tot[i]=fa[i]=0,siz[i]=1;
	for(int i=1; i<=m; i++) {
		char op; 
		int x,y;
		cin>>op;
		if(op=='T') {
			cin>>x;
			flg[x]=1;
			p[x]=0;
		}
		if(op=='F') {
			cin>>x;
			flg[x]=2;
			p[x]=0;
		}
		if(op=='U') {
			cin>>x;
			flg[x]=3;
			p[x]=0;
		}
		if(op=='+') {
			cin>>x>>y;
			if(flg[y]) {
				flg[x]=flg[y];
				p[x]=0;
			} else {
				flg[x]=0;
				p[x]=p[y];
			}
		}
		if(op=='-') {
			cin>>x>>y;
			if(flg[y]) {
				if(flg[y]==1) flg[x]=2;
				else if(flg[y]==2) flg[x]=1;
				else flg[x]=3;
				p[x]=0;
			} else {
				flg[x]=0;
				if(p[y]>n) p[x]=p[y]-n;
				else p[x]=p[y]+n;
			}
		}
	}
	for(int i=1,u,v; i<=n; i++) {
		if(p[i]) {
			if(p[i]>n) {
				u=find(i),v=find(p[i]);
				if(u!=v) {
					fa[u]=v;
					siz[v]+=siz[u];
					tot[v]+=tot[u];
				}
				u=find(i+n),v=find(p[i]-n);
				if(u!=v) {
					fa[u]=v;
					siz[v]+=siz[u];
					tot[v]+=tot[u];
				}
			} else {
				u=find(i),v=find(p[i]);
				if(u!=v) {
					fa[u]=v;
					siz[v]+=siz[u];
					tot[v]+=tot[u];
				}
				u=find(i+n),v=find(p[i]+n);
				if(u!=v) {
					fa[u]=v;
					siz[v]+=siz[u];
					tot[v]+=tot[u];
				}
			}
		} else if(flg[i]==3) {
			tot[find(i)]++;
			tot[find(i+n)]++;
		}
	}
	for(int i=1; i<=(n<<1); i++) vis[i]=0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(vis[find(i)]) continue;
		if(vis[find(i+n)]) continue;
		int u=find(i),v=find(i+n);
		if(u==v) ans+=siz[u]/2;
		else if(tot[u]) ans+=siz[u];
		vis[u]=vis[v]=1;
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cin>>ID>>T;
	while(T--) solve();
}
