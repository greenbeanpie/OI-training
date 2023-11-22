#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 57;
int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -f; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * f;
}

bool _u;

int c, t, n, m, k, d, ans;

int b[N], sum[N];

struct line{
	int l, r, v;
	bool operator < (const line &A) const{return l < A.l;}
}a[N];

void dfs(int x, int ll){
	if(ll > k) return ;
	if(x > n){
		int res = 0;
		for(int i = 1; i <= n; ++i) if(b[i]) res -= d;
		for(int i = 1; i <= n; ++i) sum[i] = 0;
		for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + b[i];
		for(int i = 1; i <= m; ++i){
			int l = a[i].l, r = a[i].r, len = r - l + 1;
			if(sum[r] - sum[l - 1] == len) res += a[i].v; 
		}
		ans = max(ans, res); return ;
	}
	b[x] = 1, dfs(x + 1, ll + 1);
	b[x] = 0, dfs(x + 1, 0);
}

void solve(){
	n = read(), m = read(), k = read(), d = read();
	for(int i = 1; i <= m; ++i){
		a[i].r = read(), a[i].l = read(), a[i].v = read();
		a[i].l = a[i].r - a[i].l + 1;
	}
	sort(a + 1, a + 1 + m);
	if(c >= 17 && c <= 18){
		int res = 0;
		for(int i = 1; i <= m; ++i){
			int len = a[i].r - a[i].l + 1;
			if(len <= k) res = max(res, res - len * d + a[i].v);
		}
		printf("%lld\n", res); return ;
	}else if(c >= 1 && c <= 2){
		ans = 0;
		dfs(1, 0);
		printf("%lld\n", ans); return ;
	}
}

bool _v;

signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	cerr << abs(&_u - &_v) / 1048576.0 << " MB\n";
	c = read(), t = read();
	while(t--) solve();
	return 0;
}
