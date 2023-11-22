#include <bits/stdc++.h>
#define MAXN 100009
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define dep(i,s,t) for(int i=(s);i>=(t);i--)
using namespace std;
int n,m,c;
struct EV {
	int fa;
	int opt;
} val[MAXN];
int size[MAXN],vis[MAXN];
int head[MAXN<<2],nxt[MAXN<<2],to[MAXN<<2],wt[MAXN<<2],egcnt;
inline void match(int u,int v,int w) {
	++egcnt;
	nxt[egcnt]=head[u];
	to[egcnt]=v;
	wt[egcnt]=w;
}
void dfs(int u) {
	size[u]=1;
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		dfs(v);
		size[u]+=size[v];
	}
}
struct DSU {
	int fa[MAXN],sz[MAXN];
	void init() {
		rep(i,1,n) fa[i]=i,sz[i]=1;
	}
	int sfn(int u) { return fa[u]==u?u:fa[u]=sfn(fa[u]); }
	inline void merge(int u,int v) {
		u=sfn(u),v=sfn(v);
		if(u==v) return;
		if(sz[u]>sz[v]) swap(u,v);
		fa[u]=v;
		sz[v]+=sz[u];
	}
	inline bool same(int u,int v) {
		u=sfn(u),v=sfn(v);
		return u==v;
	}
	inline int getsize(int u) { return sz[sfn(u)]; }
} dsu;
void init() {
	dsu.init();
	egcnt=0;
	memset(vis,0,sizeof(vis));
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
	memset(wt,0,sizeof(wt));
	memset(val,0,sizeof(val));
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C,T;
	cin>>C>>T;
	rep(t,1,T) {
		
		cin>>n>>m;
		init();
		vector<int> qs,as;
		rep(i,1,n) val[i].fa=i,val[i].opt=1;
		rep(i,1,m) {
			char v;
			cin>>v;
			if(v=='+'||v=='-') {
				int a,b;
				cin>>a>>b;
				if(v=='+') val[a].fa=val[b].fa,val[a].opt=val[b].opt;
				else val[a].fa=val[b].fa,val[a].opt=-val[b].opt;
			}
			else {
				int a;
				cin>>a;
				val[a].fa=0;
				if(v=='T') val[a].opt=1;
				if(v=='U') val[a].opt=0;
				if(v=='F') val[a].opt=-1;
			}
		}
		rep(i,1,n) if(val[i].fa!=0) {
			if(!dsu.same(val[i].fa,i))
				dsu.merge(val[i].fa,i);
			else as.push_back(i);
		}
//		cerr<<"as: ";
//		for(auto x:as) cerr<<x<<" ";
//		cerr<<endl;
//		rep(i,1,n) {
//			cerr<<i<<": "<<val[i].fa<<" "<<val[i].opt<<endl;
//		}
//		cerr<<endl;
		int ans=0;
//		if(C==5) {
//			rep(i,1,n) if(val[i].opt==0&&val[i].fa==0&&!vis[dsu.sfn(i)]) ans+=dsu.getsize(i);
//			cout<<ans<<endl;
//			continue;
//		}
		rep(i,1,n) if(val[i].fa==0&&val[i].opt==0) ans+=dsu.getsize(i);
		for(auto x:as) {
//			cerr<<"DO: "<<x<<endl;
			int y=x,d=0;
			do {
				if(val[y].opt==-1)
					d^=1;
				y=val[y].fa;
			} while(y!=x);
			if(d!=0) ans+=dsu.getsize(x);
		} 
		cout<<ans<<endl;
	}
	return  0;
}
