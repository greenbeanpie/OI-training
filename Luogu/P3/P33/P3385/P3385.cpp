#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int to, val;
};
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3385.in", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int T = 0; T < t; T++)
	{
		int n, m, u, v, w;
		bool flag = 0;
		cin >> n >> m;
		vector<node> e[2005];
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			e[u].push_back(node{v, w});
			if (w >= 0)
			{
				e[v].push_back(node{u, w});
			}
		}
		for (int i = 1; i <= n; i++)
		{
			e[i].push_back({0, 0});
			e[0].push_back({i, 0});
		}

		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}