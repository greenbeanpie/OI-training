#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "tree"
#define const constexpr

namespace Main
{

	vector<int> e[3005];
	int b[3005], w[3005];
	int n, m;
	int bsum[3005], wsum[3005];
	int fa[3005];
	void init()
	{
		for (int i = 1; i <= n; i++)
		{
			e[i].clear();
		}
		fill(b, b + n + 1, 0);
		fill(w, w + n + 1, 0);
	}
	void dfs(int u, int fa)
	{
		bsum[u] = b[u], wsum[u] = w[u];
		for (int i : e[u])
		{
			if (i != fa)
			{
				dfs(i, u);
				bsum[u] += bsum[i], wsum[u] += wsum[i];
			}
		}
	}
	int main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			cin >> n >> m;

			if (m == 1)
			{
				int b, w, bsum, wsum;
				for (int i = 1; i <= n; i++)
				{
					cin >> b;
					bsum += b;
				}
				for (int i = 1; i <= n; i++)
				{
					cin >> w;
					wsum += w;
				}
				for (int i = 1; i < n; i++)
				{
					cin >> b >> b;
				}
				if (wsum > bsum)
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else
			{
				init();
				for (int i = 1; i <= n; i++)
				{
					cin >> b[i];
				}
				for (int i = 1; i <= n; i++)
				{
					cin >> w[i];
				}
				int u, v;
				for (int i = 1; i < n; i++)
				{
					cin >> u >> v;
					e[u].push_back(v);
					e[v].push_back(u);
				}
				if (m != 2)
				{
					int left = n - m, cnt = 0;
					for (int i = 2; i <= n; i++)
					{
						if (b[i] < w[i])
						{
							++cnt;
						}
					}
					cout << max(cnt, m);
					continue;
				}
				dfs(1, 0);

				int cnt = 0;
				for (int i = 2; i <= n; i++)
				{
					if (bsum[i] < wsum[i] || bsum[1] - bsum[i] < wsum[1] - wsum[i])
					{
						cnt = 1;
						if (bsum[i] < wsum[i] && bsum[1] - bsum[i] < wsum[1] - wsum[i])
						{
							cnt = 2;
							break;
						}
					}
				}
				cout << cnt << endl;
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