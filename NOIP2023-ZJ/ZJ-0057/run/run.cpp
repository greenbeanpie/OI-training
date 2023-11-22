#include<bits/stdc++.h>
#define For(i,l,r) for(int i=l,i##end=r;i<=i##end;++i)
#define rFor(i,r,l) for(int i=r,i##end=l;i>=i##end;--i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int BS=1e8;
char buf[BS];
int read() {
	static char *p;
	if(!p) fread(buf,BS,1,stdin),p=buf;
	int x=0;
	while(!isdigit(*p)) ++p;
	while(isdigit(*p)) x=x*10+(*(p++)&15);
	return x;
}
const int N=2e5+10; const ll INF=1e18;
int n,m,k; ll d;
int a[N],l[N],r[N],v[N];
vector<pii>t[N];
ll f[N][2];
namespace DS {
	const int S=N<<2;
	ll tr[S],lz[S];
#define ls (k<<1)
#define rs (ls|1)
	void pushup(int k){tr[k]=max(tr[ls],tr[rs]);}
	void pushlz(int k,ll x){tr[k]+=x; lz[k]+=x;}
	void pushdown(int k) {
		if(lz[k]) {
			pushlz(ls,lz[k]); pushlz(rs,lz[k]); lz[k]=0;
		}
	}
	void build(int k=1,int l=0,int r=n) {
		tr[k]=lz[k]=0;
		if(l==r) return ;
		int m=l+r>>1; build(ls,l,m); build(rs,m+1,r);
	}
	void upd(int L,int R,ll x,int k=1,int l=0,int r=n) {
		if(L<=l && r<=R) return pushlz(k,x);
		int m=l+r>>1; pushdown(k);
		if(L<=m) upd(L,R,x,ls,l,m);
		if(m<R) upd(L,R,x,rs,m+1,r);
		pushup(k);
	}
	ll que(int L,int R,int k=1,int l=0,int r=n) {
		if(L<=l && r<=R) return tr[k];
		int m=l+r>>1; ll ans=-INF; pushdown(k);
		if(L<=m) ans=max(ans,que(L,R,ls,l,m));
		if(m<R) ans=max(ans,que(L,R,rs,m+1,r));
		return ans;
	}
#undef ls
#undef rs
}
void work() {
	a[1]=read(); m=read(); k=read(); d=read();
	n=1;
	For(i,1,m) {
		int x=read(),y=read(); v[i]=read();
		l[i]=x-y+1; r[i]=x;
		if(l[i]>1) a[++n]=l[i]-1;
		a[++n]=r[i];
	}
	sort(a+1,a+n+1); n=unique(a+1,a+n+1)-a-1;
	For(i,1,n) t[i].clear();
	For(i,1,m) {
		t[lower_bound(a+1,a+n+1,r[i])-a].push_back({lower_bound(a+1,a+n+1,l[i])-a,v[i]});
	}
	DS::build();
	f[0][0]=f[0][1]=0;
	int j=0;
	For(i,1,n) {
		while(a[i]-a[j]>k) ++j;
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		DS::upd(i,i,f[i][0]+d*a[i]);
		f[i][1]=f[i][0];
		for(auto [l,x]:t[i]) DS::upd(0,l-1,x);
		if(j<i) f[i][1]=max(f[i][1],DS::que(j,i-1)-d*a[i]);
	}
	cout<<f[n][1]<<"\n";
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int tmp=read(),T=read();
	while(T--) work();
}