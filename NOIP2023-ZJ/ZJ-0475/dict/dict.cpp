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
const int N = 3010;
int n, m;
char c[N][N];
char s[N << 1][N];
string st[N << 1];
int calc(int x) {
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		if (!(st[x] < st[i + n])) return 0;
	}
	return 1;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) s[i][j] = c[i][j];
		sort(s[i] + 1, s[i] + 1 + m);
		for (int j = 1; j <= m; j++) st[i] += s[i][j];
		for (int j = 1; j <= m; j++) s[i + n][j] = s[i][j];
		reverse(s[i + n] + 1, s[i + n] + 1 + m);
		for (int j = 1; j <= m; j++) st[i + n] += s[i + n][j];
	}
	for (int i = 1; i <= n; i++) printf("%d", calc(i));
	return 0;
}
