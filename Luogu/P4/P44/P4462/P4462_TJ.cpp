#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, c;
int a[N];
struct Query
{
	int l, r, id;
} q[N];
int block;
int bel[N];
ll sum;
int tot[M];
ll ans[N];
#define problemname "P4462"

bool cmp(Query a, Query b)
{
	return (bel[a.l] ^ bel[b.l]) ? bel[a.l] < bel[b.l] : ((bel[a.l] & 1) ? a.r < b.r : a.r > b.r);
}

void Build()
{
	block = pow(n, 2.0 / 3.0);
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / block + 1;
}

void Add(int x)
{
	sum += tot[a[x] ^ c];
	tot[a[x]]++;
}

void Del(int x)
{
	tot[a[x]]--;
	sum -= tot[a[x] ^ c];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname "_TJ.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &c);
	Build();
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		a[i] ^= a[i - 1];
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + 1 + m, cmp);
	tot[0] = 1;
	int l = 0, r = 0;
	for (int i = 1; i <= m; i++)
	{
		int ql = q[i].l - 1, qr = q[i].r, id = q[i].id;
		while (l < ql)
			Del(l++);
		while (l > ql)
			Add(--l);
		while (r < qr)
			Add(++r);
		while (r > qr)
			Del(r--);
		ans[id] = sum;
	}
	for (int i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}