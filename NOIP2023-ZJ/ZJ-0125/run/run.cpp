#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct TREE{ll l,r,ma,tag;}tr[400005];
void build(ll p,ll l,ll r){
	tr[p].l=l,tr[p].r=r,tr[p].ma=tr[p].tag=0;
	if(l==r) return;
	ll mid=(l+r)>>1;
	build(p*2,l,mid),build(p*2+1,mid+1,r);
}
void pushup(ll p){tr[p].ma=max(tr[p*2].ma,tr[p*2+1].ma);}
void pushdown(ll p){
	tr[p*2].tag+=tr[p].tag,tr[p*2+1].tag+=tr[p].tag;
	tr[p*2].ma+=tr[p].tag,tr[p*2+1].ma+=tr[p].tag;
	tr[p].tag=0;
}
void change(ll p,ll L,ll R,ll k){
	if(tr[p].l>R||tr[p].r<L) return;
	if(L<=tr[p].l&&tr[p].r<=R){
		tr[p].tag+=k,tr[p].ma+=k;
		return;
	}
	pushdown(p);
	change(p*2,L,R,k),change(p*2+1,L,R,k);
	pushup(p);
}
ll query(ll p,ll L,ll R){
	if(tr[p].l>R||tr[p].r<L) return -1e18;
	if(L<=tr[p].l&&tr[p].r<=R) return tr[p].ma;
	pushdown(p);
	return max(query(p*2,L,R),query(p*2+1,L,R));
}
ll n,m,k,d,x[100005],y[100005],v[100005];
vector<pair<ll,ll> >tmp[100005];
void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for(ll i=1;i<=n;i++) tmp[i].clear();
	for(ll i=1;i<=m;i++) scanf("%lld%lld%lld",&x[i],&y[i],&v[i]),tmp[x[i]].push_back(make_pair(y[i],v[i]));
	build(1,1,n+1);
	for(ll i=1;i<=n;i++){
		ll L=n-i+1,R=min(L+k,n+1);
		ll tmpp=query(1,L+1,min(R+1,n+1));
		change(1,L,L,tmpp);
		change(1,L+1,R,-d);
		for(ll j=0;j<tmp[i].size();j++){
			ll y=tmp[i][j].first,v=tmp[i][j].second;
			if(L+y>R) continue;
			change(1,L+y,R,v);
		}
		if(i==n) printf("%lld\n",query(1,L,R));
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ll ID,Ca;
	scanf("%lld%lld",&ID,&Ca);
	while(Ca--) solve();
	return 0;
}
