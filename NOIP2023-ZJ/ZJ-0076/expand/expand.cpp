#include <bits/stdc++.h>
using namespace std;

inline int rd() {
	char c; int x = 0;
	do c = getchar(); while (!isdigit(c));
	do x = (x << 1) + (x << 3) + (c ^ 48), c = getchar(); while (isdigit(c));
	return x;
}

const int N = 5e5 + 5;
char ans[65];
int n, m, q, a[N], b[N];

namespace S1{
	const int N = 205;
	int v1[N], v2[N], f[N][N];
	void solve(int T) {
		if (v1[1] == v2[1]) return ans[T] = '0', void();
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j)
				f[i][j] = 0;
		f[0][0] = 1;
		if (v1[1] < v2[1]) {
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					if (v1[i] < v2[j])
						f[i][j] = f[i - 1][j - 1] | f[i - 1][j] | f[i][j - 1];
		} else {
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					if (v1[i] > v2[j])
						f[i][j] = f[i - 1][j - 1] | f[i - 1][j] | f[i][j - 1];
		}
		ans[T] = (f[n][m] ? '1' : '0');
	}
	
	void main() {
		for (int i = 1; i <= n; ++i)
			v1[i] = a[i];
		for (int i = 1; i <= m; ++i)
			v2[i] = b[i];
		solve(0);
		int kx, ky, x, y;
		for (int T = 1; T <= q; ++T) {
			for (int i = 1; i <= n; ++i)
				v1[i] = a[i];
			for (int i = 1; i <= m; ++i)
				v2[i] = b[i];
			kx = rd(), ky = rd();
			for (int i = 1; i <= kx; ++i)
				x = rd(), y = rd(), v1[x] = y;
			for (int i = 1; i <= ky; ++i)
				x = rd(), y = rd(), v2[x] = y;
			solve(T);
		}
		puts(ans);
	}
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c;
	c = rd(), n = rd(), m = rd(), q = rd();
	for (int i = 1; i <= n; ++i) a[i] = rd();
	for (int i = 1; i <= m; ++i) b[i] = rd();
	S1::main();
	return 0;
}