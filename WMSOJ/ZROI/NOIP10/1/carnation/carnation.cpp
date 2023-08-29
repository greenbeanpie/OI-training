#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#pragma GCC optimize("Ofast")
#define int long long
#define double long double
#define endl "\n"
#define problemname "carnation"
#define const constexpr
double st = clock();

namespace Main
{
	const int N = 1e6 + 5;
	struct node
	{
		int to, a, b;
		node(int x, int y, int z)
		{
			to = x, a = y, b = z;
		}
	};
	bool operator==(node a, node b)
	{
		return a.a == b.a && a.b == b.b;
	}
	bool operator!=(node a, node b)
	{
		return !(a == b);
	}
	bool operator<(node a, node b)
	{
		return a.a + a.b < b.a + b.b;
	}

	vector<node> e[N];
	int dfn[N] /*, low[N]*/;
	vector<node> circle[N];
	int end[N];
	int vis[N];
	int ccnt = 0;
	int n, m;
	int suma = 0, sumb = 0;
	vector<node> s;
	random_device rd;
	mt19937 random(rd());
	inline void tarjan(int u, int fa = 0)
	{
		vis[u] = 1;
		dfn[u] = dfn[fa] + 1;
		for (auto i : e[u])
		{

			if (i.to == fa)
			{
				continue;
			}
			s.push_back(i);
			if (!dfn[i.to])
			{
				tarjan(i.to, u);
				if (*s.rbegin() != i && s.rbegin()->to != i.to)
				{
					return;
				}
			}
			else if (vis[i.to])
			{
				++ccnt;
				int idx = 0;
				auto start = --s.end();
				--start;
				circle[ccnt].push_back(i);
				for (auto j = start; j != --s.begin(); j--)
				{
					if (j->to == i.to)
					{
						break;
					}
					circle[ccnt].push_back(*j);
				}
			}
			s.pop_back();
		}
		vis[u] = 0;
	}
	int minans = INT_MAX;
	int suma1, suma2, suma3, sumb1, sumb2, sumb3;
	inline void dfs(int now)
	{
		// if (now > ccnt)
		// {
		// 	minans = min(minans, suma * sumb);
		// 	return;
		// }
		// for (int i = 0; i < end[now] && (clock() - st) / CLOCKS_PER_SEC <= 0.995; i++)
		// {
		// 	suma -= circle[now][i].a;
		// 	sumb -= circle[now][i].b;
		// 	dfs(now + 1);
		// 	suma += circle[now][i].a;
		// 	sumb += circle[now][i].b;
		// }
		for (int i = 1; i <= ccnt; i++)
		{
			int tsuma1 = 0, tsuma2 = 0, tsuma3 = 0, tsumb1 = 0, tsumb2 = 0, tsumb3 = 0;
			for (auto j : circle[i])
			{
				if (j.a > tsuma1)
				{
					tsuma1 = j.a;
					tsumb1 = j.b;
				}
				if (j.b > tsumb2)
				{
					tsuma2 = j.a;
					tsumb2 = j.b;
				}
				if (j.a + j.b > tsuma3 + tsumb3)
				{
					tsuma3 = j.a;
					tsumb3 = j.b;
				}
			}
			suma1 += tsuma1;
			suma2 += tsuma2;
			suma3 += tsuma3;
			sumb1 += tsumb1;
			sumb2 += tsumb2;
			sumb3 += tsumb3;
		}
		minans = min(min((suma - suma1) * (sumb - sumb1), (suma - suma2) * (sumb - sumb2)), (suma - suma3) * (sumb - sumb3));
	}

	int main()
	{
		cin >> n >> m;
		int u, v, a, b;
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v >> a >> b;
			e[u].emplace_back(v, a, b);
			e[v].emplace_back(u, a, b);
			suma += a;
			sumb += b;
		}
		tarjan(1);
		int tsuma = suma, tsumb = sumb;
		for (int i = 1; i <= ccnt; i++)
		{
			int amax = 1, bmax = 1, minsuma = 0, minsumb = 0;
			for (auto j : circle[i])
			{
				if (j.a > amax)
				{
					amax = j.a;
					minsuma = j.a + j.b;
				}
				if (j.b > bmax)
				{
					bmax = j.b;
					minsumb = j.a + j.b;
				}
			}
			int minsum = min(minsuma, minsumb);
			for (auto j = circle[i].begin(); j != circle[i].end(); j++)
			{
				int sum = j->a + j->b;
				if (sum < minsum)
				{
					auto old = j--;
					circle[i].erase(old);
				}
			}
			// sort(circle[i].begin(), circle[i].end());
			// end[i] = unique(circle[i].begin(), circle[i].end()) - circle[i].begin();
			end[i] = circle[i].size();
			// tsuma -= circle[i].begin()->a, tsumb -= circle[i].begin()->b;
		}
		// shuffle(circle + 1, circle + 1 + ccnt, random);
		dfs(1);
		cout << minans;
		cerr << "This program run " << (clock() - st) / CLOCKS_PER_SEC << "s.";
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