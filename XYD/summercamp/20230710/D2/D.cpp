#include <cstdio>

const int N = 1e5 + 5;

int n, m;
int tot, pos[N], ed[N], dep[N], va[N];

struct Bit {
	long long tr[N];
	int lim;
	void Add(int x, long long v) {
		for (; x; x -= x & (-x)) {
			tr[x] += v;
		}
	}
	long long Query(int x, long long res = 0) {
		for (; x <= lim; x += x & (-x)) {
			res += tr[x];
		}
		return res;
	}
} Tw;

int yun, las[N], to[N << 1 | 3], pre[N << 1 | 3];
void Add(int a, int b) {
	to[++yun] = b;
	pre[yun] = las[a];
	las[a] = yun;
}

void dfs(int x, int fa) {
	pos[x] = ++tot;
	dep[x] = dep[fa] + 1;
	for (int i = las[x]; i; i = pre[i]) {
		if (to[i] != fa) {
			dfs(to[i], x);
		}
	}
	ed[x] = tot;
}

int main() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	scanf("%d%d", &n, &m);
	Tw.lim = n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &va[i]);
	}
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		Add(x, y);
		Add(y, x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		Tw.Add(ed[i], va[i]);
		Tw.Add(pos[i] - 1, -va[i]);
	}
	for (int ty, x, a; m; --m) {
		scanf("%d%d", &ty, &x);
		if (ty == 1) {
			scanf("%d", &a);
			Tw.Add(ed[x], a);
			Tw.Add(pos[x] - 1, -a);
		}
		if (ty == 2) {
			printf("%lld\n", Tw.Query(pos[x]));
		}
	}
	return 0;
}