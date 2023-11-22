#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c ^ 48);
	return x;
}

const int MAXN = 1e5 + 5;
int C, T;
int n, m, k, d;
struct node {
	int y, v;
	node() : y(), v() {}
	node(int y, int v) : y(y), v(v) {}
};
long long ans, sum;
vector<node> x[MAXN];

void dfs(int t, int rt, long long e) {
	if (e + sum <= ans) return;
	if (t > n) {
		ans = max(ans, e);
		return;
	}
	dfs(t + 1, 0, e);
	if (rt >= k) return;
	for (int i = 0; i < x[t].size(); ++i)
		if (rt + 1 >= x[t][i].y) e += x[t][i].v;
	dfs(t + 1, rt + 1, e - d);
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	C = read();
	T = read();
	for (; T; --T) {
		n = read();
		m = read();
		k = read();
		d = read();
		sum = 0ll;
		ans = -9e18;
		for (int i = 1; i <= m; ++i) {
			int xx = read(), yy = read(), vv = read();
			x[xx].push_back(node(yy, vv));
			sum += vv;
		}
		dfs(1, 0, 0);
		printf("%lld\n", ans);
		for (int i = 1; i <= n; ++i) {
			x[i].clear();
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}