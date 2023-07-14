#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e4 + 5;
vector<int> e[N];
int nowdfn, scccnt, top;
int dfn[N], low[N], val[N], in[N], maxval[N];
bool vis[N];
stack<int> s;
void tarjan(int u)
{
	dfn[u] = low[u] = ++nowdfn;
	s.push(u);
	vis[u] = true;
	for (int i : e[u])
	{
		if (!dfn[i])
		{
			tarjan(i);
			low[u] = min(low[i], low[u]);
		}
		else if (vis[i])
		{
			low[u] = min(dfn[i], low[u]);
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
vector<int> en[N];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3387_3.in", "r", stdin);
	freopen("P3387.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
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
		if(!ht[low[i]]) continue;
		for (int j : e[i])
		{
			if(low[i]==low[j]||!ht[low[j]]) continue;
			en[ht[low[i]]].push_back(ht[low[j]]);
			in[ht[low[j]]]++;
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