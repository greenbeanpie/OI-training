#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;
const int mN=5e5+9;
int n, m, q, a[mN], b[mN];

namespace Sub7 {
	const int mN=2e3+9;
	bool dp[mN][mN];
	int opt[mN*2][2];
	bool solve(int *a, int n, int *b, int m) {
		if(!(a[1]<b[1])) {
			return 0;
		}
		memset(dp, 0, sizeof dp);
		dp[1][1]=1;
		rep(i, 1, n) rep(j, 1, m) if(dp[i][j]) {
			if(i<n && a[i+1]<b[j]) dp[i+1][j]=1;
			if(j<m && a[i]<b[j+1]) dp[i][j+1]=1;
			if(i<n && j<m && a[i+1]<b[j+1]) dp[i+1][j+1]=1;
		}
		return dp[n][m];
	}

	int main() {
		bool suc=solve(a, n, b, m) || solve(b, m, a, n);
		putchar(48|suc);
		// puts("\n----------------");
		rep(i, 1, q) {
			int ka, kb;
			scanf("%d%d", &ka, &kb);
			rep(i, 1, ka) {
				scanf("%d%d", opt[i], opt[i]+1);
				swap(a[opt[i][0]], opt[i][1]);
			}
			rep(i, ka+1, ka+kb) {
				scanf("%d%d", opt[i], opt[i]+1);
				swap(b[opt[i][0]], opt[i][1]);
			}
			// printf("a=");
			// rep(i, 1, n) printf(" %d", a[i]);
			// printf("\nb=");
			// rep(i, 1, m) printf(" %d", b[i]);
			// puts("");
			suc=solve(a, n, b, m) || solve(b, m, a, n);
			putchar(48|suc);
			// puts("\n----------------");
			rep(i, 1, ka) {
				swap(a[opt[i][0]], opt[i][1]);
			}
			rep(i, ka+1, ka+kb) {
				swap(b[opt[i][0]], opt[i][1]);
			}
		}
		return 0;
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);

	int Cas;
	scanf("%d%d%d%d", &Cas, &n, &m, &q);
	rep(i, 1, n) {
		scanf("%d", a+i);
	}
	rep(i, 1, m) {
		scanf("%d", b+i);
	}
	if(Cas<=7) return Sub7::main();
	return 0;
}

/*
10:16 ~ 11:00
n,m<=5e5
q<=60 sum k<=5e5
f>g / f<g。考虑 f<g
1:n / n:1。不存在 n:m。

O(nmq) 容易。
特殊性质相当于：开始时所有 dp[j]=1
不如打暴力！

为了避免你“不可以，总司令”
*/