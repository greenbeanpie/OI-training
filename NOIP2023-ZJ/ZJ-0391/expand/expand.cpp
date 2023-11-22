#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN = 500005;

int C, n, m, Q;
int ta[MAXN], tb[MAXN];
int a[MAXN], b[MAXN];
inline void Gv() {
	for (int i = 1; i <= n; ++ i)
		a[i] = ta[i];
	for (int i = 1; i <= m; ++ i)
		b[i] = tb[i];
}

namespace Sub1 {
	inline void Solve() {
		if (a[1] == b[1]) printf("0");
		else printf("1");
		while (Q --) {
			int kx, ky;
			int p, v;
			scanf ("%lld%lld", &kx, &ky);
			for (int i = 1; i <= kx; ++ i) {
				scanf ("%lld%lld", &p, &v);
				a[p] = v;
			}
			for (int i = 1; i <= ky; ++ i) {
				scanf ("%lld%lld", &p, &v);
				b[p] = v;
			}
			if (a[1] == b[1]) printf("0");
			else printf("1");
			Gv();
		}
	}
}
namespace Sub2 {
	inline void Solve() {
		if ((a[1] - b[1]) * (a[n] - b[m]) > 0) printf("1");
		else printf("0");
		while (Q --) {
			int kx, ky;
			int p, v;
			scanf ("%lld%lld", &kx, &ky);
			for (int i = 1; i <= kx; ++ i) {
				scanf ("%lld%lld", &p, &v);
				a[p] = v;
			}
			for (int i = 1; i <= ky; ++ i) {
				scanf ("%lld%lld", &p, &v);
				b[p] = v;
			}
			if ((a[1] - b[1]) * (a[n] - b[m]) > 0) printf("1");
			else printf("0");
			Gv();
		} 
	}
}
namespace Sub3 {
	int t[MAXN], fg;
	inline void dfs(int step) {
		if (step == n) {
			if (a[1] == b[1]) return;
			int tmp = a[1] - b[1];
			for (int i = 1; i <= n; ++ i) {
				int st = t[i - 1];
				if (t[i] > st) ++ st;
				for (int j = st; j <= t[i]; ++ j) {
					if (a[i] == b[j])
					return;
					if (tmp * (a[i] - b[j]) < 0) return;
					tmp = (a[i] - b[j]);
				}
			}
			fg = 1;
//			for (int i = 1; i <= n; ++ i)
//				printf ("%d ", t[i]);
//			puts("");
			return;
		}
		for (int i = t[step - 1]; i <= m; ++ i)
			t[step] = i, dfs(step + 1);
	}
	inline void Solve() {
		t[0] = 1; t[n] = m;
		fg = 0; 
		dfs(1);
		if (fg) printf("1");
		else printf("0");
		while (Q --) {
			int kx, ky;
			int p, v;
			scanf ("%lld%lld", &kx, &ky);
			for (int i = 1; i <= kx; ++ i) {
				scanf ("%lld%lld", &p, &v);
				a[p] = v;
			}
			for (int i = 1; i <= ky; ++ i) {
				scanf ("%lld%lld", &p, &v);
				b[p] = v;
			}
			fg = 0; dfs(1);
			if (fg) printf("1");
			else printf("0");
			Gv();
		}
	}
}
namespace Sub4 {
	inline void Solve() {
		printf("1");
		while (Q --) {
			int kx, ky;
			int p, v;
			scanf ("%lld%lld", &kx, &ky);
			for (int i = 1; i <= kx; ++ i) {
				scanf ("%lld%lld", &p, &v);
				a[p] = v;
			}
			for (int i = 1; i <= ky; ++ i) {
				scanf ("%lld%lld", &p, &v);
				b[p] = v;
			}
			printf("1");
			Gv();
		}
	}
}

signed main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	scanf ("%lld%lld%lld%lld", &C, &n, &m, &Q);
	for (int i = 1; i <= n; ++ i) scanf ("%lld", ta + i);
	for (int i = 1; i <= m; ++ i) scanf ("%lld", tb + i);
	Gv();
	if (n == 1 && m == 1) {
		Sub1::Solve();
		puts("");
		return 0;
	}
	if (n <= 2 && m <= 2) {
		Sub2::Solve();
		puts("");
		return 0;
	}
	if (n <= 8 && m <= 8) {
		Sub3::Solve();
		puts("");
		return 0;
	}
	Sub4::Solve();
	return puts(""), 0;
}