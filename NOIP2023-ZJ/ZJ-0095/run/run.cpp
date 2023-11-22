#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

struct segment_tree {
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	ll t[N*8],tag[N*8];
	void clear(int n) {
		memset(t,0,sizeof(ll)*(n*4+5));
		memset(tag,0,sizeof(ll)*(n*4+5));
	}
	void update(int w,ll x) {
		t[w]+=x;
		tag[w]+=x;
	}
	void push_down(int w) {
		if (tag[w]) {
			update(ls,tag[w]);
			update(rs,tag[w]);
			tag[w]=0;
		}
	}
	void add(int w,int l,int r,int ql,int qr,ll x) {
		if (ql>qr) {
			return;
		}
		if (ql<=l&&r<=qr) {
			update(w,x);
			return;
		}
		push_down(w);
		if (ql<=mid) {
			add(ls,l,mid,ql,qr,x);
		}
		if (qr>mid) {
			add(rs,mid+1,r,ql,qr,x);
		}
		t[w]=max(t[ls],t[rs]);
	}
	ll query(int w,int l,int r,int ql,int qr) {
		if (ql>qr) {
			return 0;
		}
		if (ql<=l&&r<=qr) {
			return t[w];
		}
		push_down(w);
		if (qr<=mid) {
			return query(ls,l,mid,ql,qr);
		}
		if (ql>mid) {
			return query(rs,mid+1,r,ql,qr);
		}
		return max(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
	}
	#undef mid
	#undef rs
	#undef ls
}t;
ll dp[N*2];
int n,m,k,d,b[N*2],l[N],r[N],v[N];
void work() {
	int cnt=0;
	cin>>n>>m>>k>>d;
	for (int i=1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		l[i]=x-y+1,r[i]=x+1,v[i]=z;
		b[++cnt]=l[i];
		b[++cnt]=r[i];
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	vector<vector<pair<int,int>>>a(cnt+1);
	for (int i=1;i<=m;i++) {
		l[i]=lower_bound(b+1,b+1+cnt,l[i])-b;
		r[i]=lower_bound(b+1,b+1+cnt,r[i])-b;
		a[r[i]].emplace_back(l[i],v[i]);
	}
	t.clear(cnt);
	ll mx=0;
	for (int i=1,j=1;i<=cnt;i++) {
		t.add(1,1,cnt,1,i-1,-1LL*(b[i]-b[i-1])*d);
		for (auto [l,v]:a[i]) {
			t.add(1,1,cnt,1,l,v);
		}
		while (b[i]-b[j]>k) {
			j++;
		}
		dp[i]=mx=max(mx,t.query(1,1,cnt,j,i-1));
		t.add(1,1,cnt,i,i,dp[i-1]);
	}
	cout<<mx<<"\n";
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	int C,T;
	cin>>C>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
