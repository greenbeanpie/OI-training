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
const int N = 100010, U = 100001, T = 100002, F = 100003;
int op, t, n, m;
int a[N], b[N];
//a[i] = x
// if 1<=x<=n : b[i]=a[x]
// if -n<=x<=-1, b[i]=-a[-x]
int last[N], cnt;
struct edge {
	int to, next, op;
} e[N];
void addedge(int x, int y, int op) {
	e[++cnt].to = y;
	e[cnt].next = last[x];
	e[cnt].op = op;
	last[x] = cnt;
}
bool used[N];
int s[N], ed;
int deg[N];
void dfs(int x, int fa, int pcnt) {
//	cout << "!! " << x << ' ' << fa << ' ' << pcnt << '\n';
	if (used[x]) {
//		cout << "@@@@ " << x << '\n';
		if (pcnt & 1) {
			int r = ed - 1;
			while (r && s[r] != x) {
				a[s[r]] = U;
				r--;
			}
			a[x] = U;
		}
		return ;
	}
	used[x] = 1;
	for (int i = last[x]; i; i = e[i].next) {
		int v = e[i].to;
		s[++ed] = v;
		dfs(v, x, pcnt + e[i].op);
		ed--;
	}
	if (a[x])
		for (int i = last[x]; i; i = e[i].next) {
			int v = e[i].to;
			a[v] = a[x];
		}
}
void dfs2(int x) {
	for (int i = last[x]; i; i = e[i].next) {
		int v = e[i].to;
		if (b[v]) continue;
		b[v] = b[x];
		dfs2(v);
	}
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	op = read(), t = read();
	for (int I = 1; I <= t; I++) {
		n = read(), m = read();
		for (int i = 1; i <= n; i++) a[i] = i, b[i] = 0, deg[i] = 0;
		for (int i = 1; i <= m; i++) {
			char c = getchar(); while (c != 'T' && c != 'F' && c != 'U' && c != '+' && c != '-') c = getchar();
			if (c == '+') {
				int x = read(), y = read();
				a[x] = a[y];
			}
			if (c == '-') {
				int x = read(), y = read();
				if (a[y] == U) a[x] = U;
				else if (a[y] == T) a[x] = F;
				else if (a[y] == F) a[x] = T;
				else a[x] = -a[y];
			}
			if (c == 'T') {
				int x = read();
				a[x] = T;
			}
			if (c == 'U') {
				int x = read();
				a[x] = U;
			}
			if (c == 'F') {
				int x = read();
				a[x] = F;
			}
		}
		for (int i = 1; i <= n; i++) last[i] = 0, used[i] = 0; cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x = a[i];
			if (x < 0) addedge(-x, i, 1), deg[-x]++;
			else addedge(x, i, 0), deg[x]++;
		}
		for (int i = 1; i <= n; i++)
			if (deg[i] && !used[i]) {
				ed = 0, s[++ed] = i;
				dfs(i, i, 0);
			}
//		for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
//		for (int i = 1; i <= n; i++) cout << b[i] << ' '; cout << '\n';
		for (int i = 1; i <= n; i++) {
			if (b[i]) continue;
			if (a[i] == T) b[i] = T, dfs2(i);
			if (a[i] == U) b[i] = U, dfs2(i);
			if (a[i] == F) b[i] = F, dfs2(i);
			if (a[i] == -i) b[i] = U, dfs2(i);
		}
		for (int i = 1; i <= n; i++) {
			if (b[i]) continue;
			if (a[i] < 0) {
				int x = -a[i];
				if (b[x] == U) b[i] = U;
				if (b[x] == T) b[i] = F;
				if (b[x] == F) b[i] = T;
			}
			if (a[i] > 0) {
				int x = a[i];
				b[i] = b[x];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (b[i] == U) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
