#include <bits/stdc++.h>

constexpr int N = 50'0005;

int C, n, m, q, a[N], b[N], c[N], d[N];
bool f[2005][2005];

bool check1() {
	if (a[1] == b[1]) return 0;
	bool rev = 0;
	if (a[1] < b[1]) std::swap(n, m), std::swap(a, b), rev = 1;
//	std::cerr << n << ' ' << m << '\n';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = 0;
	f[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ((i != 1 || j != 1) && a[i] > b[j])
				f[i][j] |= f[i - 1][j - 1] || f[i][j - 1] || f[i - 1][j];
//	std::cerr << f[n][m] << "#\n";
	int n_ = n, m_ = m;
	if (rev) std::swap(n, m), std::swap(a, b);
	return f[n_][m_];
}

bool check2() { 
	if (a[1] == b[1]) return 0;
	bool rev = 0;
	if (a[1] < b[1]) std::swap(n, m), std::swap(a, b), rev = 1;
	for (int i = 1; i <= m; i++)
		if (a[n] <= b[i]) {
			if (rev) std::swap(n, m), std::swap(a, b);
			return 0;
		}
	int i = 1, j = 1;
	while (i <= n || j <= m) {
		int k = i, mx = i;
		while (k <= n && a[k] > b[j]) {
			if (a[k] >= a[mx]) mx = k;
			k++;
		}
		i = mx;
		while (j <= m && b[j] >= a[k]) {
			if (b[j] >= a[i]) {
				if (rev) std::swap(n, m), std::swap(a, b);
				return 0;
			}
			j++;
		}
		i = k + 1;
	}
	if (rev) std::swap(n, m), std::swap(a, b);
	return 1;
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	std::cin >> C >> n >> m >> q;
	for (int i = 1; i <= n; i++) std::cin >> a[i], c[i] = a[i];
	for (int i = 1; i <= m; i++) std::cin >> b[i], d[i] = b[i];
	if (C <= 7) std::cout << check1(); else std::cout << check2();
	while (q--) {
		int kx, ky;
		std::cin >> kx >> ky;
		for (int i = 1; i <= n; i++) a[i] = c[i];
		for (int i = 1; i <= m; i++) b[i] = d[i];
		for (int i = 1, x, y; i <= kx; i++) 
			std::cin >> x >> y, a[x] = y;
		for (int i = 1, x, y; i <= ky; i++)
			std::cin >> x >> y, b[x] = y;
		if (C <= 7) std::cout << check1(); else std::cout << check2();
	}
}