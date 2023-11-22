#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define INFLL 0x3f3f3f3f3f3f3f3f
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
const int N=5e5+5;
struct SGT {
	struct node {
		int l,r,val,tag;
	}; node tree[N<<2];
	#define ls(k) (k<<1)
	#define rs(k) (k<<1|1)
	void push_up(int k) {
		tree[k].val=max(tree[ls(k)].val,tree[rs(k)].val);
	}
	void build(int k,int l,int r) {
		tree[k]={l,r,0ll,0ll};
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(ls(k),l,mid);
		build(rs(k),mid+1,r);
		push_up(k);
	}
	void upd(int k,int val) {
		tree[k].val+=val; tree[k].tag+=val;
	}
	void push_down(int k) {
		int &t=tree[k].tag;
		if(t) {
			upd(ls(k),t); upd(rs(k),t);
			t=0;
		}
	}
	void update(int k,int ql,int qr,int val) {
		if(ql<=tree[k].l&&tree[k].r<=qr) {
			upd(k,val);
			return;
		}
		push_down(k);
		if(ql<=tree[ls(k)].r)
			update(ls(k),ql,qr,val);
		if(qr>=tree[rs(k)].l)
			update(rs(k),ql,qr,val);
		push_up(k);
	}
	int query(int k,int ql,int qr) {
		if(ql<=tree[k].l&&tree[k].r<=qr)
			return tree[k].val;
		push_down(k);
		int res=-INFLL;
		if(ql<=tree[ls(k)].r)
			chkmax(res,query(ls(k),ql,qr));
		if(qr>=tree[rs(k)].l)
			chkmax(res,query(rs(k),ql,qr));
		return res;
	}
}; SGT T;
int f[N],g[N],l[N],r[N],val[N],t[N],len;
vector<PII> vec[N];
int get_id(int x) {
	return lower_bound(t+1,t+len+1,x)-t;
}
void solve() {
	int n,m,k,d;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	cl(f,0); cl(g,0); len=0;
	rep(i,1,m) {
		int x;
		scanf("%lld%lld%lld",&r[i],&x,&val[i]);
		l[i]=r[i]-x;
		t[++len]=l[i];
		t[++len]=r[i];
		t[++len]=l[i]-k;
		t[++len]=r[i]-k;
	}
	sort(t+1,t+len+1);
	len=unique(t+1,t+len+1)-t-1;
	T.build(1,0,len);
	rep(i,1,len)
		vec[i].clear();	
	rep(i,1,m) {
		l[i]=get_id(l[i]); r[i]=get_id(r[i]);
		vec[r[i]].push_back({l[i],val[i]});
	}
	rep(i,1,len) {
		T.update(1,0,i-1,-d*(t[i]-t[i-1]));
		for(auto x:vec[i]) {
			int l=x.first,val=x.second;
			T.update(1,0,l,val);
		}
		f[i]=max(0ll,T.query(1,max(0ll,get_id(t[i]-k)),i-1));
		g[i]=max(g[i-1],f[i]);
		if(i!=len) {
			int p=get_id(t[i]+1);
			T.update(1,p,p,g[i]); 
		}
	}
	printf("%lld\n",g[len]);
}
//pretest at 12:44 , used time = 3.8s
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int testcase,_;
	scanf("%lld%lld",&_,&testcase);
	while(testcase--)
		solve();
	return 0;
}
