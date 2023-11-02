#include <bits/stdc++.h>
#define For(i, l, r) for (int i = l, i##_e = r; i <= i##_e; ++i)
#define rFor(i, r, l) for (int i = r, i##_e = l; i >= i##_e; --i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned u32;
typedef unsigned long long u64;
typedef pair<int, int> pii;
const int N = 1e4 + 10;
namespace Flow
{
	int hd[N], cur[N], to[N], nxt[N], tot = 1;
	ll f[N];
	void add_(int u, int v, ll w)
	{
		++tot;
		nxt[tot] = hd[u];
		hd[u] = tot;
		to[tot] = v;
		f[tot] = w;
	}
	void add(int u, int v, ll w)
	{
		add_(u, v, w);
		add_(v, u, 0);
	}
	int dis[N];
	int s, e;
	bool bfs()
	{
		memset(dis, 0xFF, sizeof(dis));
		memcpy(cur, hd, sizeof(hd));
		queue<int> q;
		auto ins = [&](int x, int w)
		{
			if (!~dis[x])
				dis[x] = w, q.push(x);
		};
		ins(s, 0);
		while (q.size())
		{
			int u = q.front();
			q.pop();
			for (int i = cur[u]; i; i = nxt[i])
				if (f[i])
					ins(to[i], dis[u] + 1);
		}
		return dis[e] >= 0;
	}
	ll dfs(int u, ll in)
	{
		if (u == e)
			return in;
		ll out = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (f[i] && dis[to[i]] == dis[u] + 1)
			{
				int v = to[i];
				ll x = dfs(v, min(in, f[i]));
				f[i] -= x;
				in -= x;
				f[i ^ 1] += x;
				out += x;
				if (!x)
					dis[v] = -1;
				if (!in)
					break;
			}
		return out;
	}
	ll dinic(int _s, int _e)
	{
		s = _s;
		e = _e;
		ll ans = 0;
		while (bfs())
			ans += dfs(s, 1e18);
		return ans;
	}
}
const ll INF1 = 2e12, INF2 = 1e18;
int n;
int s, t, tot;
ll a[N], b[N], c[N];
int id[N];
int main()
{
	freopen("currency20.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	For(i, 1, n - 1) cin >> a[i];
	For(i, 1, n) cin >> b[i];
	For(i, 1, n - 1) cin >> c[i];
	if (n == 1)
		return cout << b[1], 0;
	c[1] += b[1];
	a[n - 1] += b[n];
	s = ++tot;
	t = ++tot;
	For(i, 1, n - 1)
	{
		id[i] = ++tot;
		tot += 3;
		int x = id[i];
		Flow::add(s, x, INF2);
		Flow::add(x, x + 1, a[i] + INF1);
		Flow::add(x + 1, x + 2, INF2);
		Flow::add(x + 2, x + 3, c[i] + INF1);
		Flow::add(x + 3, t, INF2);
	}
	auto ins = [](int i, int j, ll w)
	{
		if (i == j)
			return;
		Flow::add(id[i] + 1, id[j] + 2, w);
	};
	For(i, 2, n - 1)
	{
		ins(i - 1, i, b[i]);
		ins(i, i - 1, b[i]);
	}
	For(i, 1, m)
	{
		int x, y, w;
		cin >> x >> y >> w;
		ins(y, x, w);
	}
	ll res = Flow::dinic(s, t);
	ll ans = res - INF1 * (n - 1);
	cout << ans;
}