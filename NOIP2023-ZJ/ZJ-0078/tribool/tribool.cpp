#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
const ll T = 200001;
const ll F = 200002;
const ll U = 200003;
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
ll c, t, n, m;
ll fa[400050], col[400050], a[400050], vis[400050];
ll find(ll x){
	if(x!=fa[x]) fa[x]=find(fa[x]); return fa[x];
}
void Merge(ll x,ll y){
	ll fx=find(x), fy=find(y);
//	cerr<<"???\n";
	if(fx==fy) return;
	fa[fx] = fy;
}
ll _not(ll x){
	if(x==T) return F;
	else if(x==F) return T;
	else if(x==U) return U;
	else if(1<=x && x<=n) return x+n;
	else return x-n;
}
//vector<ll>vec[200050];
//void dfs(ll x){
//	vis[x] = 1;
//	for(auto num: vec[x]){
//		if(x != find(_not(num))){
//			if(!vis[find(_not(num))]) dfs(find(_not(num)));
//		}
//	}
//}
void solve(){
	n=read(), m=read();
//	cerr<<"hi\n";
	for(ll i=1;i<=200003;i++) fa[i]=i;
	memset(col,0,sizeof(col)); memset(vis,0,sizeof(vis));
//	for(ll i=1;i<=200003;i++) vec[i].clear();
	for(ll i=1;i<=n;i++) a[i]=i;
	for(ll i=1;i<=m;i++){
		char str[5]; scanf("%s",str);
		if(str[0] == '+') {
			ll i=read(), j=read();
			a[i] = a[j];
		}else if(str[0] == '-'){
			ll i=read(), j=read();
			a[i] = _not(a[j]);
		}else {
			ll i=read();
			if(str[0] == 'T') a[i] = T;
			else if(str[0] == 'F') a[i] = F;
			else a[i] = U;
		}
	}
//	cerr<<"hi\n";
	for(ll i=1;i<=n;i++){
		Merge(i, a[i]);
		Merge(_not(i), _not(a[i]));
	}
//	cerr<<"hi\n";
	for(ll i=1;i<=n;i++){
		if(find(i) == find(i+n)) Merge(U, i);
	}
//	for(ll i=1;i<=2*n;i++){
//		vec[find(i)].pb(i);
//	}
//	vec[find(T)].pb(T); vec[find(F)].pb(F); vec[find(U)].pb(U);
//	dfs(find(U));
//	for(ll i=1;i<=n;i++)
//		if(vis[find(i)]) Merge(U, i);
	ll ans = 0;
	for(ll i=1;i<=n;i++){
		ans += (find(i) == find(U));
	}
	printf("%lld\n", ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	c=read(), t=read();
	while(t--){
		solve();
	}
	return 0;
}

/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1


*/