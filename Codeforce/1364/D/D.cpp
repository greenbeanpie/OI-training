#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "D"
#define const constexpr

namespace Main
{

	const int N = 1e5 + 5;
	vector<int> e[N];
	bool colors[N];
	int dfn[N];
	vector<int> s;
	bitset<N> vis;
	int n, m, k;
	int cnt[N];
	int maxinum = -1, ms, mt, cnt1, cnt2;
	// void check(int u)
	// {
	// 	queue<int> q;
	// 	while (s.top() != u)
	// 	{
	// 		q.push(s.top());
	// 		s.pop();
	// 	}
	// 	q.push(u);
	// 	if (q.size() > k)
	// 	{
	// 		cout << 1 << endl;
	// 		for (int i = 1; i <= (k + 1) / 2; i++)
	// 		{
	// 			cout << q.front() << " ";
	// 			q.pop();
	// 			q.pop();
	// 		}
	// 		exit(0);
	// 	}
	// 	else
	// 	{
	// 		cout << 2 << endl
	// 			 << q.size() << endl;
	// 		while (q.size())
	// 		{
	// 			cout << q.front() << " ";
	// 			q.pop();
	// 		}
	// 		exit(0);
	// 	}
	// }
	void dfs(int u, int fa)
	{
		s.push_back(u);
		dfn[u] = s.size();
		for (int i : e[u])
		{
			if (!dfn[i])
			{
				dfs(i, u);
			}
			else if (dfn[i] == dfn[u] - 1)
			{
				++cnt[u];
			}
			if (dfn[i] < dfn[u] - 1 || cnt[u] == 2)
			{
				int len = dfn[u] - dfn[i] + 1;
				if (len <= k)
				{
					cout << 2 << endl
						 << len << endl;
					for (int j = dfn[i] - 1; j <= dfn[u] - 1; j++)
					{
						cout << s[j] << " ";
					}
					exit(0);
				}
				else if (len <= maxinum)
				{
					maxinum = len, ms = u, mt = i;
				}
			}
			// {
			// 	// check(i);
			// }
		}
		s.pop_back();
	}
	void dfs1(int u)
	{
		s.push_back(u);
		dfn[u] = s.size();
		if (u == mt)
		{
			cout << 1 << endl;
			for (int i = 0; i < k; i += 2)
			{
				cout << s[i] << " ";
			}
			exit(0);
		}
		for (int i : e[u])
		{
			if (u == ms && i == mt)
			{
				continue;
			}
			if (!dfn[i])
			{
				dfs1(i);
			}
		}
		s.pop_back();
	}
	void dfs2(int u, int fa)
	{
		dfn[u] = dfn[fa] + 1;
		for (int i : e[u])
		{
			if (i != fa)
			{
				dfs2(i, u);
			}
		}
	}
	int main()
	{
		cin >> n >> m >> k;
		maxinum = n;
		int u, v;
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0);
		if (ms)
		{
			fill(dfn, dfn + n + 1, 0);
			dfs1(ms);
		}
		dfs2(1,0);
		for (int i = 1; i <= n; i++)
		{
			if (dfn[i] & 1)
			{
				++cnt1;
			}
			else
			{
				++cnt2;
			}
		}
		cout << 1 << endl;
		if (cnt1 >= cnt2)
		{
			for (int i = 1, cnt = 0; i <= n && cnt < (k + 1) / 2; i++)
			{
				if (dfn[i] & 1)
				{
					++cnt;
					cout << i << " ";
				}
			}
		}
		else
		{
			for (int i = 1, cnt = 0; i <= n && cnt < (k + 1) / 2; i++)
			{
				if (!(dfn[i] & 1))
				{
					++cnt;
					cout << i << " ";
				}
			}
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