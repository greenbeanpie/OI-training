#include<bits/stdc++.h>
using namespace std;
bool vist[200005];
inline int read() {
	int f = 1, x = 0;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') {
		ch = getchar();
	}
	if (ch == '-') {
		f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + int(ch) - 48;
		ch = getchar();
	}
	return x * f;
}
struct Node {
	int now, al, v;
} a[100005];
long long f[1005][1005];
inline bool cmp(Node a, Node b) {
	return a.now < b.now;
}
int n, m, k, d;
long long ans = 0;
void dfs(int Now, int Al, long long En, int Ai) {
	if (Now == n) {
		ans = max(ans, En);
		return;
	}
	long long delta = 0;
	int p = Ai;
	for (int i = Ai; i <= m && a[i].now <= Now + 1; ++ i) {
		if (a[i].now == Now + 1 && Al + 1 >= a[i].al) {
			delta += a[i].v;
			p = i;
		}
	}
	if (Al + 1 == k)
		dfs(Now + 1, 0, En - d + delta, p);
	else {
		dfs(Now + 1, Al + 1, En - d + delta, p);
	}
	dfs(Now + 1, 0, En, p);
}
int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int C = read(), T = read();
	while (T --) {
		n = read(), m = read(), k = read(), d = read();
		for (int i = 1; i <= m; ++ i) {
			a[i] = (Node) {read(), read(), read()};
		}
		memset(f, 0, sizeof(f));
		sort(a + 1, a + 1 + m, cmp);
		ans = 0;
		dfs(0, 0, 0, 1);
		printf("%lld\n", ans);
	}
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
