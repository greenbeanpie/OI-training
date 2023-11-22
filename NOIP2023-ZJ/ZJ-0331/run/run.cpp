#include<bits/stdc++.h>
#define ZJL using
#define AK namespace
#define IOI std
#define Name "run"
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
const ll N = 1e5 + 10;
ZJL AK IOI;

int Y, _;

ll n, m, k, d, T, C;
ll a[N], b[N], c[N];

namespace sol1{
	
	struct Node{
		int x, w;
		Node(int x = 0, int w = 0): x(x), w(w){}
	};
	
	vector<Node> A[N];
	
	inline bool cmp(Node x, Node y){
		return x.x < y.x;
	}
	
	ll f[1010][1010];
	inline void sol(){
		for(int i = 1;i <= n;i++) A[i].clear();
		for(int i = 1;i <= m;i++){
			A[a[i]].push_back(Node(b[i], c[i]));
		}
		for(int i = 1;i <= n;i++) sort(A[i].begin(), A[i].end(), cmp);
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= k;j++){
				f[i][j] = -INF;
			}
		}
		f[0][0] = 0;
		for(int i = 1;i <= n;i++){
			for(ll j = 1, p = 0, sum = 0;j <= k;j++){
				while(p < (ll)A[i].size() && A[i][p].x <= j) sum += A[i][p].w, p++;
				f[i][j] = f[i - 1][j - 1] + sum - d;
			}
			for(ll j = 0;j <= k;j++){
				f[i][0] = max(f[i][0], f[i - 1][j]);
			}
		}
		ll ans = -INF;
		for(ll j = 0;j <= k;j++){
			ans = max(ans, f[n][j]);
		}
		printf("%lld\n", ans);
	}
}

namespace sol2{
	inline void sol(){
		ll ans = 0;
		for(int i = 1;i <= m;i++){
			ll w = c[i] - b[i] * d;
			if(w > 0) ans += w;	
		}
		printf("%lld\n", ans);
	}
}

//namespace sol3{
//	ll mx;
//	ll f[4010][4010];
//	ll lf[N], L[N];
//	vector<ll> A;
//	
//	struct Node{
//		ll l, w;
//		Node(ll l = 0, ll w = 0): l(l), w(w){}
//	};
//	
//	vector<Node> B[4010];
//	
//	inline void sol(){
//		A.clear(), A.push_back(0);
//		for(int i = 1;i <= m;i++){
//			lf[i] = a[i] - b[i] + 1;
//			L[i] = max(a[i] - k + 1, 1ll);
//			A.push_back(lf[i]), A.push_back(L[i]), A.push_back(a[i]);
//		}
//		sort(A.begin(), A.end());
//		mx = 0;
//		for(int i = 1;i <= m;i++){
//			lf[i] = lower_bound(A.begin(), A.end(), lf[i]) - A.begin();
//			L[i] =  lower_bound(A.begin(), A.end(), L[i]) - A.begin();
//			a[i] =  lower_bound(A.begin(), A.end(), a[i]) - A.begin();
//			B[a[i]].push_back(Node(lf[i], c[i]));
//			mx = max(mx, a[i]);
//		}
//		for(int i = 0;i <= mx;i++){
//			for(int j = 0;j <= mx;j++){
//				f[i][j] = -INF;
//			}
//		}
//		f[0][1] = 0;
//		ll S = 0;
//	}
//}

inline ll read(){
	ll x = 0, y = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') y = -y;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * y;
}

int main(){
	freopen(Name ".in", "r", stdin);
	freopen(Name ".out", "w", stdout);
	C = read(), T = read();
	while(T--){
		n = read(), m = read(), k = read(), d = read();
		for(int i = 1;i <= m;i++){
			a[i] = read(), b[i] = read(), c[i] = read();
		}
		if(C <= 9) sol1::sol();
		else if(C >= 17 && C <= 18) sol2::sol();
	}
	return ~~(Y^_^Y);
}