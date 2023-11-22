#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb emplace_back
#define fi first
#define se second
typedef pair<ll,ll> P;
ll c,t;
ll read(){
	ll x=0, f=1; char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1; ch=getchar();
	}
	while(ch>='0' && ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*f;
}
ll maxx(ll a,ll b){return a>b?a:b;}
ll minn(ll a,ll b){return a<b?a:b;}

ll n,m,k,d;
ll mx[400005], tag[400005];
vector<P>vec[400005];
void php(ll pos){
	mx[pos] = maxx(mx[pos<<1], mx[pos<<1|1]);
}
void phd(ll pos){
	if(tag[pos]){
		tag[pos<<1] += tag[pos], tag[pos<<1|1] += tag[pos];
		mx[pos<<1] += tag[pos], mx[pos<<1|1] += tag[pos];
		tag[pos] = 0;
	}
}
void upd(ll l,ll r,ll L,ll R,ll v,ll pos){
	if(l<=L && R<=r) {
		mx[pos] += v; tag[pos] += v;
		return;
	}
	ll mid=L+R>>1;
	phd(pos);
	if(l<=mid) upd(l,r,L,mid,v,pos<<1);
	if(mid<r)  upd(l,r,mid+1,R,v,pos<<1|1);
	php(pos);
}
void upd2(ll L,ll R,ll wei,ll v,ll pos){
	if(L==R){
		mx[pos] = v;
		return;
	}
	ll mid=L+R>>1;
	phd(pos);
	if(wei<=mid) upd2(L,mid,wei,v,pos<<1);
	else upd2(mid+1,R,wei,v,pos<<1|1);
	php(pos);
}
ll query(ll l,ll r,ll L,ll R,ll pos){
	if(l<=L && R<=r) return mx[pos];
	ll mid=L+R>>1, ans=-1e18;
	phd(pos);
	if(l<=mid) ans=maxx(ans, query(l,r,L,mid,pos<<1));
	if(mid<r)  ans=maxx(ans, query(l,r,mid+1,R,pos<<1|1));
	return ans;
}
void solve(){
	n=read(), m=read(), k=read(), d=read();
	memset(mx, 0, sizeof(mx));
	memset(tag, 0, sizeof(tag));
	
	for(ll i=1;i<=m;i++){
		ll x=read(), y=read(), v=read();
		vec[x].pb(y,v);
	}
	for(ll i=1;i<=n;i++){
		upd2(0, n, i, query(0, i-1, 0, n, 1) , 1);
		upd(0, i-1, 0, n, -d, 1);
		if(i>k){
			upd2(0, n, i-k-1, -1e18, 1);
		}
		for(auto p: vec[i]){
			ll len = p.fi;
			upd(0, i-len, 0, n, p.se, 1);
		}
	}
	printf("%lld\n", query(0, n, 0, n, 1));
	for(ll i=1;i<=n;i++){
		vec[i].clear();
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	c=read(), t=read();
	while(t--){
		solve();
	}
	return 0;
}
