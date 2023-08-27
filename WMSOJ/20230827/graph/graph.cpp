#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "graph"
#define const constexpr

namespace Main
{
	const int N = 2e5 + 5;
	vector<int> e[N], block = vector<int>(1);
	int point[N], idx;
	int n, m, k;
	cc_hash_table<int, bool> con[N];
	vector<int> now;
	void dfs(int u, int idx)
	{
		now.clear();
		bitset<N> vis;
		vis[u] = 1;
		now.push_back(u);
		queue<int> q;
		q.push(u);
		while (q.size() && now.size() <= (k + 1) / 2)
		{
			int cur = q.front();
			q.pop();
			for (int i : e[cur])
			{
				if (vis[i])
				{
					continue;
				}
				vis[i] = 1;
				for (int j : e[i])
				{
					if (vis[j])
					{
						continue;
					}
					vis[j] = 1;
					now.push_back(j);
					q.push(j);
					if (con[u][j])
					{
						q.pop();
						now.pop_back();
						continue;
					}
					for (int k : now)
					{
						if (con[j][k])
						{
							q.pop();
							now.pop_back();
							break;
						}
					}
				}
			}
		}
		for (int i : now)
		{
			point[i] = idx;
		}
		block.push_back(now.size());
	}
	// int dfn[N], low[N], nowdfn;
	bitset<N> vis;
	void spfa(int u)
	{
		vis[u] = 1;
		for(int iter:e[u])
		{
			if (!vis[iter])
			{
				now.push_back(iter);
				spfa(iter);
				now.pop_back();
			}
			else if(*++now.rbegin()!=iter)
			{
				int dep = 0;
				for (auto i = --now.end(); i != --now.begin() && dep < k; i--)
				{
					++dep;
					if (*i == iter)
					{
						cout << 2 << endl
							 << dep << endl;
						for (auto j = i; j != now.end(); j++)
						{
							cout << *j << " ";
						}
						exit(0);
					}
				}
			}
		}
		vis[u] = 0;
	}

	int main()
	{

		cin >> n >> m >> k;
		int u, v;
		for (int i = 1; i <= m; i++) // create graph
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			con[u][v] = con[v][u] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!point[i])
			{
				dfs(i, ++idx);
				if (block[idx] >= (k + 1) / 2)
				{
					break;
				}
			}
		}
		if (block[idx] >= (k + 1) / 2)
		{
			cout << 1 << endl;
			for (int i = 1, cnt = 0; i <= n && cnt < (k + 1) / 2; i++)
			{
				if (point[i] == idx)
				{
					++cnt;
					cout << i << " ";
				}
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				now.clear();
				now.push_back(i);
				spfa(i);
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