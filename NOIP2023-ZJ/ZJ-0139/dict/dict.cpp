#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 3000;
const ll N = maxn + 10;
ll n, m;
bool ans;
string s[N], t[N], f[N], g[N];
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
void rd_str(string &s) {
	char ch = getchar();
	s = "";
	while (ch < 'a' || ch > 'z') {
		ch = getchar();
	}
	while (ch >= 'a' && ch <= 'z') {
		s += ch;
		ch = getchar();
	}
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = rd(); m = rd();
	for (ll i = 1; i <= n; ++i) {
		rd_str(s[i]);
		sort(s[i].begin(), s[i].end());
		for (ll j = (ll)(s[i].length()) - 1; j >= 0; --j) {
			t[i] += s[i][j];
		}
	}
	f[1] = t[1];
	for (ll i = 2; i <= n; ++i) {
		if (t[i] > f[i - 1]) {
			f[i] = f[i - 1];
		}
		else {
			f[i] = t[i];
		}
	}
	g[n] = t[n];
	for (ll i = n - 1; i >= 1; --i) {
		if (t[i] > g[i + 1]) {
			g[i] = g[i + 1];
		}
		else {
			g[i] = t[i];
		}
	}
	for (ll i = 1; i <= n; ++i) {
		ans = 1;
		if (i > 1 && s[i] >= f[i - 1]) {
			ans = 0;
		}
		if (ans && i < n && s[i] >= g[i + 1]) {
			ans = 0;
		}
		if (ans) {
			putchar('1');
		}
		else {
			putchar('0');
		}
	}
	return 0;
}
