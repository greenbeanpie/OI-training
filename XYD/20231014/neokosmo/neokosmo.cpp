#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "neokosmo"
#define const constexpr

namespace Main
{

	const int N = 1e5;
	struct node
	{
		int to, val;
		node(int a, int b)
		{
			to = a, val = b;
		}
	};
	bool operator>(node a, node b)
	{
		return a.val > b.val;
	}
	vector<node> e[N];
	int a[N], b[N];
	int dis[N];
	int n, m, c;
	int solve(int u)
	{
		fill(dis, dis + n + 1, LLONG_MAX >> 1);
		int minans = a[u] + b[u];
		__gnu_pbds::priority_queue<node, greater<node>> q;
		q.push({u, 0});
		dis[u] = 0;
		while (q.size())
		{
			auto now = q.top();
			q.pop();
			if (now.val > dis[now.to])
			{
				continue;
			}
			if (dis[now.to] > minans)
			{
				break;
			}
			for (auto i : e[now.to])
			{
				if (dis[i.to] > dis[now.to] + i.val && i.to >= c)
				{
					q.push({i.to, dis[i.to] = dis[now.to] + 2 * i.val});
					minans = min(minans, dis[i.to] + a[i.to] + b[u]);
				}
			}
		}
		return minans;
	}
	int main()
	{

		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < c; i++)
		{
			cin >> b[i];
		}
		for (int i = 1, u, v, w; i <= m; i++)
		{
			cin >> u >> v >> w;
			e[u].emplace_back(v, w + b[v]);
			e[v].emplace_back(u, w + b[u]);
		}
		int minans = LLONG_MAX;
		for (int i = 0; i < c; i++)
		{
			minans = min(minans, solve(i));
		}
		cout << minans << endl;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}