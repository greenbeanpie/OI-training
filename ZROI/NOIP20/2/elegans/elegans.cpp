#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

#ifdef CODESPACE
// #pragma GCC optimize(2)
#endif

constexpr int N = 3e5 + 5;

struct node
{
	int to, val, i;
	node(int a, int b, int c)
	{
		to = a, val = b, i = c;
	}
	node(int a, int b)
	{
		to = a, val = b, i = 0;
	}
	node()
	{
		to = 1, val = i = 0;
	}
};

bool operator>(const node &a, const node &b)
{
	return a.val > b.val;
}

vector<node> e[N];

priority_queue<node, vector<node>, greater<node>> q;

int mindis[N];

int dijkstra(int val, int n)
{
	q.emplace(1, 0, 0);
	while (q.size())
	{
		auto now = q.top();
		q.pop();
		if (now.to == n)
		{
			return now.val;
		}
		for (auto i : e[now.to])
		{
			int temp = (now.i + 1) * i.val;
			if (max(now.val, temp) < val)
			{
				mindis[i.to] = max(now.val, temp);
				q.emplace(i.to, max(now.val, temp), now.i + 1);
			}
		}
	}
	return 0;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("elegans.in", "r", stdin);
	freopen("elegans.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1, u, v, val; i <= m; i++)
	{
		cin >> u >> v >> val;
		e[u].emplace_back(v, val);
		// e[v].emplace_back(u, val);
	}
	fill(mindis, mindis + 300001, ULLONG_MAX);
	// cout << dijkstra(n) << endl;
	int l = 0, r = 3e14;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		int res = dijkstra(mid, n);
		if (res)
		{
			r = res;
		}
		else
		{
			l = mid+1;
		}
	}
	cout << l - 1 << endl;
	return 0;
}
