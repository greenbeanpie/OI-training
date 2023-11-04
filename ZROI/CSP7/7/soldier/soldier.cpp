#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
// #pragma GCC optimize(2)
// #define int long long

constexpr int N = 7505, M = 55;
int sum[N][M], temp[M];
vector<int> e[N];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("soldier.in", "r", stdin);
	freopen("soldier.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int s;
		cin >> s;
		for (int j = 1, tmp; j <= s; j++)
		{
			cin >> tmp;
			e[i].emplace_back(tmp);
			sum[i][tmp] = 1;
			// ++temp[j];
		}
		sort(e[i].begin(), e[i].end());
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] += sum[i][j - 1];
			// sum[i][j] = sum[i][j - 1] + temp[j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int last = 0, res = 0;
			for (int f : e[j])
			{
				res += min(1, sum[i][f] - sum[i][last]);
				last = f;
			}
			ans += res % 2;
		}
	}
	cout << ans << endl;
	return 0;
}
