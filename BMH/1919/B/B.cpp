#include <bits/stdc++.h>
typedef long long ll;
constexpr int maxn = 1000005;	
using namespace std;
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2")
#pragma GCC optimize(3,"Ofast","inline")
ll n, m, l ,r, cnt, k;
ll u[maxn], v[maxn];
bool vis[maxn];

void add(ll x, ll y){
	if(vis[x] || vis[y]){ vis[x] = vis[y] = 1; return ;}
	else vis[x] = vis[y] = 1, cnt++;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= m; ++i)
		scanf("%lld%lld", &u[i], &v[i]);
	
	cin >> k;
	while(k--){
		cnt = 0;
		scanf("%lld%lld", &l, &r);
		memset(vis, 0, sizeof vis);
		
		for(int i = 1;i < l; ++i)	add(u[i], v[i]);
		for(int i = r + 1;i <= m; ++i)	add(u[i], v[i]);
		for(int i = 1;i <= n; ++i) cnt += (1 - vis[i]);
		
		printf("%lld\n", cnt);
	}
		
	return 0;
}