#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
const ll inf = 1e18;
void rd(int &x) {
	x = 0; int tp = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') tp = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	if(tp) x = -x;
}
const int N = 1e3 + 10;
int n, m, k, d;
ll pre[N][N], f[N][N];
void init() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++)
			pre[i][j] = 0, f[i][j] = -inf;
	}
	f[0][0] = 0;
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int csd, T;
	rd(csd); rd(T);//multiple cases！
	if(csd <= 9) {
		while(T--) {
			rd(n); rd(m); rd(k); rd(d);
			init();
			for(int i = 1, x, y, v; i <= m; i++) {
				rd(x); rd(y); rd(v);
				pre[x][y] += v;
			}
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= k; j++)
					pre[i][j] += pre[i][j - 1];
			ll mxlst = 0;
			for(int i = 1; i <= n; i++) {
				f[i][0] = mxlst;
				for(int j = 1; j <= k; j++) {
					f[i][j] = f[i - 1][j - 1] - d + pre[i][j]; 
					mxlst = max(mxlst, f[i][j]);
				}
			}
			ll ans = 0;
			for(int j = 0; j <= k; j++)
				ans = max(ans, f[n][j]);
			printf("%lld\n", ans);
		}
	} else {
		while(T--) {
			rd(n); rd(m); rd(k); rd(d);
			ll ans = 0;
			for(int i = 1, x, y, v; i <= m; i++) {
				rd(x); rd(y); rd(v);
				if(y <= k) ans += max(0ll, v - 1ll * y * d);
				//cout<<max(0ll, v - 1ll * y * d)<<endl;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
/*
10 1
1000000 2 0 1
5 2 3
9 3 2
*/
