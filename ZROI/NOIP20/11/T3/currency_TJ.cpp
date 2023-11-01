#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

template <typename T>
bool chkmin(T &x, T y) { return x > y ? x = y, 1 : 0; }
template <typename T>
bool chkmax(T &x, T y) { return x < y ? x = y, 1 : 0; }

int readint()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const ll inf = 2000000000000ll;
int n, m, k, src, sink, tot;
int v[6005], nxt[6005], rev[6005], h[505], q[505], lev[505];
ll c[6005], A[505], B[505];

void addedge(int x, int y, ll z)
{
	v[++tot] = y;
	c[tot] = z;
	nxt[tot] = h[x];
	rev[tot] = tot + 1;
	h[x] = tot;
	v[++tot] = x;
	c[tot] = 0;
	nxt[tot] = h[y];
	rev[tot] = tot - 1;
	h[y] = tot;
}

bool bfs()
{
	for (int i = src; i <= sink; i++)
		lev[i] = -1;
	int front = 0, rear = 0;
	q[rear++] = src;
	lev[src] = 0;
	while (front < rear)
	{
		int t = q[front++];
		for (int p = h[t]; p; p = nxt[p])
		{
			if (c[p] && lev[v[p]] < 0)
			{
				lev[v[p]] = lev[t] + 1;
				q[rear++] = v[p];
			}
		}
		if (lev[sink] >= 0)
			return true;
	}
	return false;
}

ll dfs(int u, ll low)
{
	if (u == sink)
		return low;
	ll res = 0;
	for (int p = h[u]; p; p = nxt[p])
	{
		if (c[p] && lev[v[p]] == lev[u] + 1)
		{
			ll flow = dfs(v[p], min(c[p], low));
			res += flow, low -= flow, c[p] -= flow, c[rev[p]] += flow;
			if (low <= 0)
				break;
		}
	}
	if (!res)
		lev[u] = -1;
	return res;
}

ll dinic()
{
	ll ret = 0;
	while (bfs())
		ret += dfs(src, 1ll << 60);
	return ret;
}

// void IO()
// {
// 	freopen("currency1.out", "w", stdout);
// 	freopen("currency1.in", "r", stdin);
// }

int main()
{
	// IO();
	freopen("currency20.in", "r", stdin);
	n = readint();
	m = readint();
	src = 0, sink = n;
	int x, y, z;
	for (int i = 1; i < n; i++)
		A[i] = B[i] = inf;
	for (int i = 1; i < n; i++)
	{
		x = readint();
		A[i] += x;
	}
	for (int i = 1; i <= n; i++)
	{
		x = readint();
		if (i == 1)
			B[i] += x;
		else if (i == n)
			A[i - 1] += x;
		else
			addedge(i - 1, i, x), addedge(i, i - 1, x);
	}
	for (int i = 1; i < n; i++)
	{
		x = readint();
		B[i] += x;
	}
	for (int i = 1; i <= m; i++)
	{
		x = readint();
		y = readint();
		z = readint();
		addedge(y, x, z);
	}
	for (int i = 1; i < n; i++)
	{
		addedge(src, i, A[i]);
		addedge(i, sink, B[i]);
	}
	printf("%lld\n", dinic() - (n - 1) * inf);
	return 0;
}