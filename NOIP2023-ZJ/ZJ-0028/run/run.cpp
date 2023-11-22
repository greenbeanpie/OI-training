#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#ifdef DEBUG
template<typename T>
ostream& operator << (ostream &out,vector<T> a){
	out<<'[';
	for(T x:a)out<<x<<',';
	return out<<']';
}
template<typename T>
vector<T> ary(T *a,int l,int r){
	return vector<T>{a+l,a+1+r};
}
template<typename T>
void debug(T x){
	cerr<<x<<endl;
}
template<typename T,typename...S>
void debug(T x,S...y){
	cerr<<x<<' ',debug(y...);
}
#else
#define debug(...) void()
#endif
const int N=1e5+10,M=2e5+10;
const ll INF=1e18;
int sid,T,lim,n,k,d,m,b[M];
struct opts{
	int l,r,v;
}o[N];
vector<int>R[M];
namespace SGT{
	ll t[M<<2],laz[M<<2];
	void pushup(int rt){
		t[rt]=max(t[rt<<1],t[rt<<1|1])+laz[rt];
	}
	void pushadd(int rt,ll x){
		t[rt]+=x,laz[rt]+=x;
	}
	void build(int l=1,int r=m,int rt=1){
		laz[rt]=0;
		if(l==r){
			t[rt]=1ll*d*b[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		pushup(rt);
	}
	void update(int L,int R,ll x,int l=1,int r=m,int rt=1){
		if(L<=l&&r<=R)return pushadd(rt,x);
		int mid=(l+r)>>1;
		if(L<=mid)update(L,R,x,l,mid,rt<<1);
		if(mid<R)update(L,R,x,mid+1,r,rt<<1|1);
		pushup(rt);
	}
	ll query(int L,int R,int l=1,int r=m,int rt=1){
		if(L<=l&&r<=R)return t[rt];
		int mid=(l+r)>>1;
		ll s=-INF;
		if(L<=mid)s=max(s,query(L,R,l,mid,rt<<1));
		if(mid<R)s=max(s,query(L,R,mid+1,r,rt<<1|1));
		return s+laz[rt];
	}
}
ll f[M];
void print(){
	vector<ll>ans;
	for(int i=1;i<=m;i++){
		ans.push_back(SGT::query(i,i));
	}
	debug(ans);
}
void solve(){
	SGT::build();
	// print();
	for(int i=2,x=1;i<=m;i++){
		for(;x<=i&&b[i]-b[x]>k;x++);
		for(int id:R[i]){
			// debug("update",1,o[id].l,o[id].v);
			SGT::update(1,o[id].l,o[id].v);
		}
		SGT::update(i,i,f[i-1]);
		f[i]=SGT::query(x,i)-1ll*d*b[i];
		// print();
	}
	// debug(ary(f,1,m));
}
void get(){
	scanf("%d%d%d%d",&lim,&n,&k,&d);
	b[m=1]=0;
	for(int i=1,x,y,z;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		o[i]={x-y,x,z};
		b[++m]=o[i].l,b[++m]=o[i].r;
	}
	sort(b+1,b+1+m),m=unique(b+1,b+1+m)-b-1;
	auto trs=[&](int &x){
		x=lower_bound(b+1,b+1+m,x)-b;
	};
	for(int i=1;i<=n;i++){
		trs(o[i].l),trs(o[i].r);
		R[o[i].r].push_back(i);
	}
	// debug("root",ary(root,1,m));
	// for(int i=1;i<=n;i++){
	// 	debug(o[i].l,o[i].r,o[i].v);
	// }
	// debug(ary(b,1,m));
	// for(int i=1;i<=m;i++){
	// 	for(int j=i;j<=m;j++){
	// 		debug("calc",i,j,calc(i,j),SGT::query(root[j],i));
	// 	}
	// }
	solve();
	cout<<f[m]<<endl;
}
void clr(){
	fill(f,f+1+m,0);
	for(int i=1;i<=m;i++)R[i].clear();
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	for(scanf("%d%d",&sid,&T);T--;clr())get();
	debug(1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}