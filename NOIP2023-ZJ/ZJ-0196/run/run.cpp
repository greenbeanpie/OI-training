//#include<bits/stdc++.h>
//#define fi first
//#define se second
//#define PII pair<int,int>
//using namespace std;
//const int N=1e3+5;
//long long f[N][N];
//vector<PII> g[N];
//int n,m,k,d,ID,T;
//inline void solve() {
//	scanf("%d%d%d%d",&n,&m,&k,&d);
//	for(int i=1; i<=n; i++) g[i].clear();
//	for(int i=1,x,y,v; i<=m; i++) {
//		scanf("%d%d%d",&x,&y,&v);
//		g[x].push_back({y,v});
//	}
//	for(int i=1; i<=n; i++) {
//		f[i][0]=f[i-1][0];
//		for(int j=1; j<=min(k,i); j++) {
//			f[i][j]=f[i-1][j-1]-d;
//			f[i][0]=max(f[i][0],f[i-1][j]);
//		}
//		for(auto j:g[i]) {
//			for(int t=j.fi; t<=min(k,i); t++) f[i][t]+=j.se;
//		}
//	}
//	long long ans=0;
//	for(int j=0; j<=k; j++) ans=max(ans,f[n][j]);
//	cout<<ans<<'\n';
//}
//int main() {
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
//	scanf("%d%d",&ID,&T);
//	while(T--) solve();
//	return 0;
//}
#include<bits/stdc++.h>
#define fi first
#define se second
#define PII pair<int,int>
using namespace std;
const int N=2e5+5;
vector<PII> g[N];
int n,m,k,d,ID,T;
mt19937 rnd(time(0));
int cnt,siz[N],ls[N],rs[N],id[N];
long long val[N],mx[N],tag[N],pri[N];
inline void push_up(int p) {
//	assert(!siz[0]);
//	if(ls[p]) assert(pri[p]<=pri[ls[p]]);
//	if(rs[p]) assert(pri[p]<=pri[rs[p]]);
	mx[p]=max(val[p],max(mx[ls[p]],mx[rs[p]]));
	siz[p]=siz[ls[p]]+siz[rs[p]]+1;
}
inline void push_down(int p) {
	if(!tag[p]) return ;
	if(ls[p]) {
		val[ls[p]]+=tag[p];
		mx[ls[p]]+=tag[p];
		tag[ls[p]]+=tag[p];
	}
	if(rs[p]) {
		val[rs[p]]+=tag[p];
		mx[rs[p]]+=tag[p];
		tag[rs[p]]+=tag[p];
	}
	tag[p]=0;
}
inline int new_node(long long w,int ii) {
	cnt++,siz[cnt]=1,pri[cnt]=rnd(),id[cnt]=ii;
	ls[cnt]=rs[cnt]=0,val[cnt]=mx[cnt]=w;
	return cnt;
}
void split(int p,int&x,int&y) {
	push_down(p);
	if(siz[p]==1) x=0,y=p;
	else {
		push_down(ls[p]),push_down(rs[p]);
		if(siz[rs[p]]) x=p,split(rs[x],rs[x],y);
		else x=ls[p],y=p,ls[p]=0;
		push_up(x);
	}
}
int merge(int x,int y) {
	if(!x||!y) return x+y;
	push_down(x),push_down(y);
	if(pri[x]<pri[y]) {
		push_down(rs[x]);
		rs[x]=merge(rs[x],y);
		push_up(x);
		return x;
	} else {
		push_down(ls[y]);
		ls[y]=merge(x,ls[y]);
		push_up(y);
		return y;
	}
}
void update(int p,int l,int r,long long w) {
	if(l==1&&r==siz[p]) {
		val[p]+=w,mx[p]+=w,tag[p]+=w;
		return ;
	}
	push_down(p);
	if(l<=siz[ls[p]]) update(ls[p],l,min(r,siz[ls[p]]),w);
	if(l<=siz[ls[p]]+1&&siz[ls[p]]+1<=r) val[p]+=w;
	if(siz[ls[p]]+1<r) update(rs[p],max(1,l-siz[ls[p]]-1),r-siz[ls[p]]-1,w);
	push_up(p);
}
inline void solve() {
	scanf("%d%d%d%d",&n,&m,&k,&d);
//	int rt=new_node(0);
//	for(int i=1; i<=n; i++)
//		rt=merge(new_node(0),rt);
	
	mx[0]=-1e14,cnt=0;
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1,x,y,v; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&v);
		g[x].push_back({y,v});
	}
	int rt=new_node(0,0);
	for(int i=1,x,y; i<=n; i++) {
		long long tmp=mx[rt];
		if(i>k)	{
			split(rt,x,y);
//			cerr<<y<<" ";
		} else x=rt;
		val[x]-=d,mx[x]-=d,tag[x]-=d;
		for(auto j:g[i]) {
			update(x,j.fi,min(k,i),j.se);
		}
		rt=merge(new_node(tmp,i),x);
	}
	cout<<mx[rt]<<'\n';
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&ID,&T);
	while(T--) solve();
	return 0;
}
