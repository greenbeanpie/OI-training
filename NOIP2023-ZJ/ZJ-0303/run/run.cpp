#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1010;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int c, T;
int n, m, k, d;
LL f[N], g[N];
vector<PII> r[N];

struct Node
{
	int l, r;
	LL v, ad;
}tr[N * 4];

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, f[l], 0};
	else
	{
		int mid = (l + r) >> 1;
		tr[u] = {l, r, 0, 0};
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
	}
}

void pushadd(int u, LL d)
{
	tr[u].v += d * (tr[u].r - tr[u].l + 1);
	tr[u].ad += d;
}

void pushdown(int u)
{
	if (tr[u].ad)
	{
		pushadd(u << 1, tr[u].ad);
		pushadd(u << 1 | 1, tr[u].ad);
		tr[u].ad = 0;
	}
}

void modify(int u, int l, int r, LL d)
{
	if (tr[u].l >= l && tr[u].r <= r) pushadd(u, d);
	else
	{
		pushdown(u);
		int mid = (tr[u].l + tr[u].r) >> 1;
		if (l <= mid) modify(u << 1, l, r, d);
		if (r > mid) modify(u << 1 | 1, l, r, d);
		tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
	}
}

LL query(int u, int x)
{
	if (tr[u].l == tr[u].r) return tr[u].v;
	int mid = (tr[u].l + tr[u].r) >> 1;
	pushdown(u);
	if (x <= mid) return query(u << 1, x);
	else return query(u << 1 | 1, x);
}

int main()
{
	freopen("run.in", "r", stdin); freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T -- )
	{
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i = 1; i <= n; i ++ ) r[i].clear();
		for (int i = 1; i <= m; i ++ )
		{
			int x, y, v; scanf("%d%d%d", &x, &y, &v);
			r[x].push_back({y, v});
		}
		memset(f, -0x3f, sizeof f);
		f[0] = 0;
		for (int i = 1; i <= n; i ++ )
		{
			memcpy(g, f, sizeof g);
			f[0] = -INF;
			for (int j = 0; j <= min(i - 1, k); j ++ ) f[0] = max(f[0], g[j]);
			for (int j = 1; j <= min(i, k); j ++ )
				if (j) f[j] = g[j - 1] - d;
			build(1, 0, min(i, k));
			for (PII w : r[i]) modify(1, w.first, min(i, k), (LL)w.second);
			for (int j = 0; j <= min(i, k); j ++ ) f[j] = query(1, j);
		}
		
		LL res = -INF;
		for (int i = 0; i <= min(n, k); i ++ )
			res = max(res, f[i]);
		printf("%lld\n", res);
	}
	return 0;
}
