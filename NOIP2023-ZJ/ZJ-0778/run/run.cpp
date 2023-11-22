#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i <= (k);i++)
#define per(i,j,k) for(int i = (j);i >= (k);i--)
#define ll long long
#define pii pair<int,int>
#define SZ(S) (int)S.size()
#define mkp make_pair
#define uint unsigned int
#define linf 0x3f3f3f3f3f3f3f3f
#define eb emplace_back
using namespace std;

template <class P>
void chkmax(P &x,P y){
	if(x < y) x = y;
}

template <class Q>
void chkmin(Q &x,Q y){
	if(x > y) x = y;
}
int testid,T;
int n,m,K,d;
int _l[100005],_r[100005],val[100005],tmp[200005];

void fix(int &v){
	v = lower_bound(tmp + 1,tmp + 2 * m + 1,v) - tmp;
}
vector <pii> P[200005];

struct node{
	ll val,tag;
}tree[800005];
#define ls (rt * 2)
#define rs (rt * 2 + 1)
void build(int rt,int l,int r){
	tree[rt].val = 0;
	tree[rt].tag = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(ls,l,mid);build(rs,mid+1,r);
}

void pushup(int rt){
	tree[rt].val = max(tree[ls].val,tree[rs].val) + tree[rt].tag;
}

void upload(int rt,int l,int r,int L,int R,ll C){
	if(l == L && r == R){
		tree[rt].tag += C;
		tree[rt].val += C;
		return;
	}
	int mid = (l + r) >> 1;
	if(R <= mid){
		upload(ls,l,mid,L,R,C);
	}else if(L > mid){
		upload(rs,mid+1,r,L,R,C);
	}else{
		upload(ls,l,mid,L,mid,C);
		upload(rs,mid+1,r,mid+1,R,C);
	}
	pushup(rt);
}

ll query(int rt,int l,int r,int L,int R,ll tot){
	if(l == L && r == R) return tree[rt].val + tot;
	int mid = (l + r) >> 1;
	tot += tree[rt].tag;
	if(R <= mid) return query(ls,l,mid,L,R,tot);
	else if(L > mid) return query(rs,mid+1,r,L,R,tot);
	else return max(query(ls,l,mid,L,mid,tot),query(rs,mid+1,r,mid+1,R,tot));
}

ll dp[200005];
void solve(){
	memset(_l,0,sizeof(_l));
	memset(_r,0,sizeof(_r));
	memset(val,0,sizeof(val));
	memset(tmp,0,sizeof(tmp));
	memset(dp,0,sizeof(dp));
	scanf("%d%d%d%d",&n,&m,&K,&d);
	rep(i,1,2 * m) P[i].clear();
	rep(i,1,m){
		scanf("%d%d%d",&_r[i],&_l[i],&val[i]);
		_l[i] = _r[i] - _l[i] + 1;
		tmp[2 * i - 1] = _l[i];
		tmp[2 * i] = _r[i];
	}
	sort(tmp + 1,tmp + 2 * m + 1);
	rep(i,1,m){
		fix(_l[i]);
		fix(_r[i]);
		P[_r[i]].eb(mkp(_l[i],val[i]));
	}
	build(1,1,2 * m);
	int j = 0,k = 1;
	ll Mx = 0,ans = 0;
	rep(i,1,2 * m){
		while(j < 2 * m && tmp[j + 1] + 1 < tmp[i]){
			j++;
			chkmax(Mx,dp[j]);
		}
		while(tmp[i] - tmp[k] + 1 > K) k++;
		upload(1,1,2 * m,i,i,Mx + 1ll * d * (tmp[i] - 1));
		for(pii I:P[i]) upload(1,1,2 * m,1,I.first,I.second);
		dp[i] = query(1,1,2 * m,k,i,0) - 1ll * d * tmp[i];
		chkmax(ans,dp[i]);
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&testid,&T);
	while(T--) solve();
	return 0;
}
//g++ D.cpp -o D -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result -fsanitize=address,undefined
//memset ALL!