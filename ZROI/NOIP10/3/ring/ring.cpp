#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "ring"
#define const constexpr

namespace Main
{
	const int N = 205;
	struct node
	{
		int to, val;
		int flag = 0;
		node(int a, int b)
		{
			to = a, val = b;
		};
	};
	bool operator>(node a, node b)
	{
		return a.val > b.val;
	}
	unsigned int n, ans = LLONG_MAX;
	bitset<N> vis, vis2;
	vector<node> e[N];
	unsigned int dis[N];
	void dijkstra(int u)
	{
		__gnu_pbds::priority_queue<node, greater<node>> q;
		q.push({u, 0});
		fill(dis, dis + N, LLONG_MAX >> 1);
		vis.reset();
		dis[u] = 0;
		while (q.size())
		{
			auto now = q.top();
			q.pop();
			if (dis[now.to] < now.val || vis[now.to])
			{
				continue;
			}
			vis[now.to] = 1;
			dis[now.to] = now.val;
			for (auto i : e[now.to])
			{
				if (dis[now.to] + i.val < dis[i.to])
				{
					dis[i.to] = dis[now.to] + i.val;
					q.push({i.to, dis[now.to] + i.val});
				}
			}
		}
	}
	void dfs2(int now, int sum)
	{
		if (now == 1)
		{
			ans = min((int)ans, sum);
			return;
		}
		for (auto i = e[now].begin(); i != e[now].end();i++)
		{
			if (i->flag != 2 && !vis2[i->to])
			{
				int temp = i->flag;
				i->flag = 2;
				vis2[i->to] = 1;
				dfs2(i->to, (1 - temp) * i->val + sum);
				i->flag = temp;
				vis2[i->to] = 0;
			}
		}
	}
	void dfs1(int now, int sum)
	{
		if (now == n)
		{
			dfs2(n, sum);
		}
		for (auto i = e[now].begin(); i != e[now].end();i++)
		{
			if (!i->flag && !vis[i->to])
			{
				i->flag = 1;
				vis[i->to] = 1;
				dfs1(i->to, sum + i->val);
				i->flag = 0;
				vis[i->to] = 0;
			}
		}
	}
	int main()
	{
		cin >> n;
		int temp;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> temp;
				if (temp)
				{
					e[i].emplace_back(j, temp);
				}
			}
		}
		if (n <= 10)
		{
			dfs1(1, 0);
			cout << ans;
			return 0;
		}
		else
		{
			int ans = 0;
			dijkstra(1);
			cout << dis[n];
			return 0;
		}
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
