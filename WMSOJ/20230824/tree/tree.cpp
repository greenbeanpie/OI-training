#include <bits/stdc++.h>
#define int long long
namespace Main{
	constexpr int N = 2.5e5 + 5;

	struct Edge
	{
		int to, nxt;
		int a, b;
	} e[N << 1];
	int head[N], tot;

	inline void addEdge(int u, int v, int a, int b)
	{
		e[++tot] = Edge{v, head[u], a, b}, head[u] = tot;
	}

	int n, lim;
	int d1[N], d2[N], d;

	inline void dfs(int u, int fa, int delta)
	{
		d1[u] = d2[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (v == fa)
				continue;
			dfs(v, u, delta);
			int w = e[i].a + e[i].b * delta;
			int dis = d1[v] + w;
			if (dis > d1[u])
				d2[u] = d1[u], d1[u] = dis;
			else if (dis > d2[u])
				d2[u] = dis;
		}
		d = std::max(d1[u] + d2[u], d);
	}

	inline int calc(int x)
	{
		d = 0;
		dfs(1, 0, x);
		return d;
	}

	inline void main()
	{
		std::cin >> n >> lim;
		for (int i = 1; i < n; i++)
		{
			int u, v, a, b;
			std::cin >> u >> v >> a >> b;
			addEdge(u, v, a, b);
			addEdge(v, u, a, b);
		}
		int l = 0, r = lim;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (calc(mid) > calc(mid + 1))
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		std::cout << l << '\n'
				  << calc(l) << '\n';
		return;
	}
}

signed main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	Main::main();
	return 0;
}