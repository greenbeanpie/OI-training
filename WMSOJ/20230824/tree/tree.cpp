#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "array"
#define const constexpr

namespace Main
{
	mt19937 random(time(0));
	int n, m;
	int cnt[100005], minans;
	bool mp[20][100005];
	void check()
	{
		int res = 0;
		for (int i = 1; i <= m; i++)
		{
			res += max(cnt[i], n - cnt[i]);
		}
		minans = max(minans, res);
	}
	void dfs(int now)
	{
		if (clock() >= 1.95 * CLOCKS_PER_SEC)
		{
			check();
			return;
		}
		if (now == n + 1)
		{
			check();
			return;
		}
		if (random() % 2)
		{
			dfs(now + 1);
			for (int i = 1; i <= m; i++)
			{
				mp[now][i] = !mp[now][i];
				if (mp[now][i])
				{
					++cnt[i];
				}
				else
				{
					--cnt[i];
				}
			}
			dfs(now + 1);
		}
		else
		{
			dfs(now + 1);
			for (int i = 1; i <= m; i++)
			{
				mp[now][i] = !mp[now][i];
				if (mp[now][i])
				{
					++cnt[i];
				}
				else
				{
					--cnt[i];
				}
			}
			dfs(now + 1);
		}
	}
	int main()
	{
		char c;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> c;
				if (c == '1')
				{

					mp[i][j] = 1;
					++cnt[j];
				}
			}
		}
		dfs(1);
		cout << n * m - minans;
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