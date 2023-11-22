#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
inline ll read() {
	ll s = 0, w = 1; char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') w = -1; c = getchar();}
	while (c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	return s * w;
}
const int N = 500010;
int op, n, m, q;
int a[N], b[N], ta[N], tb[N];
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	op = read(), n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++) ta[i] = read();
	for (int i = 1; i <= m; i++) tb[i] = read();
	if (n <= 1 && m <= 1) {
		if (ta[1] < tb[1] || ta[1] > tb[1]) printf("1");
		else printf("0");
	}
	else if (n <= 2 && m <= 2) {
		if (n == 1) {
			if (ta[1] < tb[1] && ta[1] < tb[2]) printf("1");
			else if (ta[1] > tb[1] && ta[1] > tb[2]) printf("1");
			else printf("0");
		}
		else if (m == 1) {
			if (ta[1] < tb[1] && ta[2] < tb[1]) printf("1");
			else if (ta[1] > tb[1] && ta[2] > tb[1]) printf("1");
			else printf("0");
		}
		else {
			if (ta[1] < tb[1] && ta[2] < tb[2]) printf("1");
			else if (ta[1] > tb[1] && ta[2] > tb[2]) printf("1");
			else printf("0");
		}
	}
	else {
		if (ta[1] == tb[1] || ta[n] == tb[m]) printf("0");
		else if (ta[1] < tb[1] && ta[n] < tb[m]) printf("1");
		else if (ta[1] > tb[1] && ta[n] > tb[m]) printf("1");
		else printf("0");
	}
	for (int I = 1; I <= q; I++) {
		int kx = read(), ky = read();
		for (int i = 1; i <= n; i++) a[i] = ta[i];
		for (int i = 1; i <= m; i++) b[i] = tb[i];
		for (int i = 1; i <= kx; i++) {
			int x = read(), y = read();
			a[x] = y;
		}
		for (int i = 1; i <= ky; i++) {
			int x = read(), y = read();
			b[x] = y;
		}
		if (n <= 1 && m <= 1) {
			if (a[1] < b[1] || a[1] > b[1]) printf("1");
			else printf("0");
			continue;
		}
		else if (n <= 2 && m <= 2) {
			if (n == 1) {
				if (a[1] < b[1] && a[1] < b[2]) printf("1");
				else if (a[1] > b[1] && a[1] > b[2]) printf("1");
				else printf("0");
			}
			else if (m == 1) {
				if (a[1] < b[1] && a[2] < b[1]) printf("1");
				else if (a[1] > b[1] && a[2] > b[1]) printf("1");
				else printf("0");
			}
			else {
				if (a[1] < b[1] && a[2] < b[2]) printf("1");
				else if (a[1] > b[1] && a[2] > b[2]) printf("1");
				else printf("0");
			}
			continue;
		}
		else {
			if (a[1] == b[1] || a[n] == b[m]) printf("0");
			else if (a[1] < b[1] && a[n] < b[m]) printf("1");
			else if (a[1] > b[1] && a[n] > b[m]) printf("1");
			else printf("0");
		}
	}
	return 0;
}
