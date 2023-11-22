#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mpr make_pair
const ll SIZE = 200005;
const ll mod = 998244353;
ll ID, T;
ll n, m, K, d;

inline ll rd(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}
	return x*f;
}

struct A{
	ll x, y, val;
}a[SIZE];

namespace solve{
	bool cmp(A x, A y){
		return (x.x == y.x) ? (x.y < y.y) : (x.x < y.x);
	}
	ll dp[1005][1005];
	void Main(){
		n = rd(), m = rd(), K = rd(), d = rd();
		for(ll i = 1; i <= m; i++){
			a[i].x = rd(), a[i].y = rd(), a[i].val = rd();
		}
		sort(a+1, a+m+1, cmp);
		for(ll i = 0; i <= n; i++) dp[0][i] = -(1ll<<60);
		dp[0][0] = 0; ll now = 1; ll ans = 0;
		for(ll i = 1; i <= n; i++){
			while(now <= m && a[now].x < i) now++; 
			ll jl = 0; dp[i][0] = 0;
			for(ll j = 1; j <= K; j++){
				dp[i][0] = max(dp[i][0], dp[i-1][j-1]);
				while(now <= m && a[now].x == i && a[now].y <= j){
					jl += a[now].val;
					now++;
				}
				dp[i][j] = -(1ll<<60);
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + jl - d);
				ans = max(ans, dp[i][j]);
			}
			for(ll j = K+1; j <= n; j++) dp[i][j] = -(1ll<<60);
			dp[i][0] = max(dp[i][0], dp[i-1][K]);
			ans = max(ans, dp[i][0]);
		}
		printf("%lld\n", ans);
	}
}

int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ID = rd(), T = rd();
	while(T--){
		solve::Main();
	}
	return 0;
}

