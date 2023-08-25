#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

struct node
{
	int to, val;
	node(int a, int b)
	{
		to = a, val = b;
	}
};
const int N = 1e5 + 5;
vector<node> e[N];
int nowdfn, scccnt, top;
int dfn[N], low[N], val[N], in[N], maxval[N];
bool vis[N];
stack<int> s;
void tarjan(int u)
{
	dfn[u] = low[u] = ++nowdfn;
	s.push(u);
	vis[u] = true;
	for (auto i : e[u])
	{
		int to = i.to;
		if (!dfn[to])
		{
			tarjan(to);
			low[u] = min(low[to], low[u]);
		}
		else if (vis[to])
		{
			low[u] = min(dfn[to], low[u]);
		}
	}
	if (dfn[u] == low[u])
	{

		scccnt++;
		while (s.top() != u)
		{
			val[u] += val[s.top()];
			vis[s.top()] = false;
			s.pop();
		}
		vis[s.top()] = false;
		s.pop();
	}
}
vector<node> en[N];
int op, u, v;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3275.in", "r", stdin);
	freopen("P3275.out", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> op >> u >> v;
		if (op == 1)
		{
			e[u].emplace_back(v, 0);
			e[v].emplace_back(u, 0);
		}
		else if (op == 2)
		{
			e[u].emplace_back(v, 1);
		}
		else if (op == 3)
		{
			e[v].emplace_back(u, 0);
		}
		else if (op == 4)
		{
			e[v].emplace_back(u, 1);
		}
		else
		{
			e[u].emplace_back(v, 0);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	cc_hash_table<int, int> ht;
	for (int i = 1; i <= n; i++)
	{
		if (dfn[i] == low[i])
		{
			ht[low[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!ht[low[i]])
			continue;
		for (auto j : e[i])
		{
			int to = j.to;
			if (low[i] == low[to] || !ht[low[to]])
				continue;
			en[ht[low[i]]].push_back(ht[low[to]]);
			in[ht[low[to]]]++;
		}
	}
	swap(e, en);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0 && dfn[i] == low[i])
		{
			maxval[i] = val[i];
			q.push(i);
		}
	}
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i : e[now])
		{
			maxval[i] = max(maxval[i], maxval[now] + val[i]);
			if (!--in[i])
			{
				q.push(i);
			}
		}
	}
	int maxinum = -1;
	for (int i = 1; i <= n; i++)
	{
		maxinum = max(maxinum, maxval[i]);
	}
	cout << maxinum;
	return 0;
}