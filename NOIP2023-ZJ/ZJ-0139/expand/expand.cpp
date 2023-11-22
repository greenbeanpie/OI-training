#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e3, maxm = 5e5;
const ll N = maxn + 10, M = maxm + 10;
const ll INF = 4e18;
ll o, n, m, q, qq, a[M], b[M];
bool ans;
ll rd() {
	char ch = getchar();
	ll s = 0, w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (s * w);
}
//namespace Sub1{ // o <= 7
//	ll A[N], B[N];
//	bool dp[N][N];
//	void solve1() {
//		for (ll i = 0; i <= m; ++i) {
//			dp[0][i] = 0;
//		}
//		dp[0][0] = 1;
//		ll k = 0, p = 0;
//		for (ll i = 1; i <= n; ++i) {
//			k = -1; p = (i == 1 ? 0 : -INF);
//			dp[i][0] = 0;
//			for (ll j = 1; j <= m; ++j) {
//				if (b[j] <= a[i]) {
//					k = j;
//				}
//				if (dp[i - 1][j]) {
//					p = j;
//				}
//				if (p > k) {
//					dp[i][j] = 1;
//				}
//				else {
//					dp[i][j] = 0;
//				}
//			}
//		}
//		if (dp[n][m]) {
//			ans = 1;
//	//		if (qq == 2) cout << "A\n";
//		}
//	}
//	void solve2() {
//		for (ll i = 0; i <= m; ++i) {
//			dp[0][i] = 0;
//		}
//		dp[0][0] = 1;
//		ll k = 0, p = 0;
//		for (ll i = 1; i <= n; ++i) {
//			k = -1; p = (i == 1 ? 0 : -INF);
//			dp[i][0] = 0;
//			for (ll j = 1; j <= m; ++j) {
//				if (b[j] >= a[i]) {
//					k = j;
//				}
//				if (dp[i - 1][j]) {
//					p = j;
//				}
//	//			if (i == 1 && j == 1) {
//	//				cout << "C " << k << ' ' << p << endl;
//	//			}
//				if (p > k) {
//					dp[i][j] = 1;
//	//				cout << "D " << i << ' ' << j << endl;
//				}
//				else {
//					dp[i][j] = 0;
//				}
//			}
//		}
//		if (dp[n][m]) {
//			ans = 1;
//	//		if (qq == 2)cout << "B\n";
//		}
//	}
//	void initSub1() {
//		for (ll i = 1; i <= n; ++i) {
//			A[i] = rd();
//			a[i] = A[i];
//		}
//		for (ll i = 1; i <= m; ++i) {
//			B[i] = rd();
//			b[i] = B[i];
//		}
//		ans = 0;
//		solve1();
//		if (!ans) {
//			solve2();
//		}
//		if (ans) {
//			putchar('1');
//		}
//		else {
//			putchar('0');
//		}
//	//	cout << endl; // ...
//		{ll u, v, x, y;
//		for (qq = 1; qq <= q; ++qq) {
//			u = rd(); v = rd();
//			for (ll i = 1; i <= n; ++i) {
//				a[i] = A[i];
//			}
//			for (ll i = 1; i <= m; ++i) {
//				b[i] = B[i];
//			}
//			for (ll i = 1; i <= u; ++i) {
//				x = rd(); y = rd();
//				a[x] = y;
//			}
//			for (ll i = 1; i <= v; ++i) {
//				x = rd(); y = rd();
//				b[x] = y;
//			}
//	//		if (qq == 2) {
//	//			for (ll i = 1; i <= n; ++i) {
//	//				cout << a[i] << ' ';
//	//			}
//	//			cout << endl;
//	//			for (ll i = 1; i <= m; ++i) {
//	//				cout << b[i] << ' ';
//	//			}
//	//			cout << endl;
//	//		}
//			ans = 0;
//			solve1();
//			if (!ans) {
//				solve2();
//			}
//			if (ans) {
//				putchar('1');
//			}
//			else {
//				putchar('0');
//			}
//	//		cout << endl; // ...
//		}}
//	}
//}
namespace Sub2{
	ll A[M], B[M], X[M], Y[M];
	void solve1() { // x < y
		ll x = m;
		for (ll i = n; i >= 1; --i) {
			if (a[i] >= b[x]) {
				while (x <= m && a[i] >= b[x]) {
					++x;
				}
				if (x > m) {
					return;
				}
			}
			else {
				while (x > 0 && a[i] < b[x]) {
					--x;
				}
				++x;
			}
		}
		if (x == 1) {
			ans = 1;
		}
	}
	void solve2() { // x > y
		ll x = m;
		for (ll i = n; i >= 1; --i) {
			if (a[i] <= b[x]) {
				while (x <= m && a[i] <= b[x]) {
					++x;
				}
				if (x > m) {
					return;
				}
			}
			else {
				while (x > 0 && a[i] > b[x]) {
					--x;
				}
				++x;
			}
		}
		if (x == 1) {
			ans = 1;
		}
	}
	void initSub2() {
		for (ll i = 1; i <= n; ++i) {
			a[i] = rd();
			A[i] = a[i];
		}
		for (ll i = 1; i <= m; ++i) {
			b[i] = rd();
			B[i] = b[i];
		}
		ans = 0;
		solve1();
		if (!ans && (o <= 7 || o >= 15)) {
			solve2();
		}
		if (ans) {
			putchar('1');
		}
		else {
			putchar('0');
		}
		{ll u, v, k;
		for (qq = 1; qq <= q; ++qq) {
			u = rd(); v = rd();
			for (ll i = 1; i <= u; ++i) {
				X[i] = rd(); k = rd();
				a[X[i]] = k;
			}
			for (ll i = 1; i <= v; ++i) {
				Y[i] = rd(); k = rd();
				b[Y[i]] = k;
			}
	//		if (qq == 2) {
	//			for (ll i = 1; i <= n; ++i) {
	//				cout << a[i] << ' ';
	//			}
	//			cout << endl;
	//			for (ll i = 1; i <= m; ++i) {
	//				cout << b[i] << ' ';
	//			}
	//			cout << endl;
	//		}
			ans = 0;
			solve1();
			if (!ans && (o <= 7 || o >= 15)) {
				solve2();
			}
			if (ans) {
				putchar('1');
			}
			else {
				putchar('0');
			}
			for (ll i = 1; i <= u; ++i) {
				a[X[i]] = A[X[i]];
			}
			for (ll i = 1; i <= v; ++i) {
				b[Y[i]] = B[Y[i]];
			}
	//		cout << endl; // ...
		}}
	}
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	o = rd(); n = rd(); m = rd(); q = rd();
//	if (o <= 7) {
//		Sub1::initSub1();
//	}
//	else {
		Sub2::initSub2();
//	}
	return 0;
}
