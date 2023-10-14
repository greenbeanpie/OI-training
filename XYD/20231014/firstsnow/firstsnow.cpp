#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "firstsnow"
#define const constexpr
#define Pii pair<int, int>

namespace Main
{
	const int N = 505;
	// bitset<N> snow[N];
	bool snow[N][N];
	int main()
	{
		int n, o;
		cin >> n >> o;

		if (o == 5)
		{
			cout << 0 << endl;
		}
		else if (o == 1)
		{
			char c;
			for (int i = 1; i <= n; i++)
			{
				// snow[i].reset();
				for (int j = 1; j <= n; j++)
				{
					cin >> c;
					if (c == '1')
					{
						// snow[i].set(j,true);
						snow[i][j] = 1;
					}
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i += 2)
			{
				for (int j = 1; j <= n; j += 2)
				{
					for (int k = i; k <= n; k += 2)
					{
						if (j + i - k > n)
						{
							break;
						}
						if (i + j <= k)
						{
							break;
						}
						for (int f = j + 2; f <= n; f += 2)
						{
							if (f + k <= j || i + f <= k || i + f <= j)
							{
								f = max(j - k, max(k - i, j - i)) + 1;
								if (f % 2 == 0)
								{
									++f;
								}
							}
							if (k + f - j > n || f + i - k > n || i + f - j > n)
							{
								break;
							}
							Pii p1 = {i, j}, p2 = {k, f};
							Pii p3 = {p2.first - (p1.second - p2.second), p2.second - (p2.first - p1.first)}, p4 = {p1.first - (p1.second - p2.second), p1.second - (p2.first - p1.first)};
							if (snow[p1.first][p1.second] && snow[p2.first][p2.second] && snow[p3.first][p3.second] && snow[p4.first][p4.second])
							{
								++cnt;
							}
						}
					}
				}
			}
			cout << cnt << endl;
		}
		else if (o == 2)
		{
			char c;
			for (int i = 1; i <= n; i++)
			{
				// snow[i].reset();
				for (int j = 1; j <= n; j++)
				{
					cin >> c;
					if (c == '1')
					{
						// snow[i].set(j,true);
						snow[i][j] = 1;
					}
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i += 2)
			{
				for (int j = 1; j <= n; j++)
				{
					for (int k = i; k <= n; k += 2)
					{
						if (j + i - k > n)
						{
							break;
						}
						if (i + j <= k)
						{
							break;
						}
						for (int f = j + 1; f <= n; f++)
						{
							if (f + k <= j || i + f <= k || i + f <= j)
							{
								f = max(j - k, max(k - i, j - i)) + 1;
							}
							if (k + f - j > n || f + i - k > n || i + f - j > n)
							{
								break;
							}
							Pii p1 = {i, j}, p2 = {k, f};
							Pii p3 = {p2.first - (p1.second - p2.second), p2.second - (p2.first - p1.first)}, p4 = {p1.first - (p1.second - p2.second), p1.second - (p2.first - p1.first)};
							if (snow[p1.first][p1.second] && snow[p2.first][p2.second] && snow[p3.first][p3.second] && snow[p4.first][p4.second])
							{
								++cnt;
							}
						}
					}
				}
			}
			cout << cnt << endl;
		}
		// else if (o == 3)
		// {
		// }
		else if (o == 4)
		{
			cout << (n - 1) * (n + 1) * (n / 2) * (n / 2) / 3 << endl;
		}
		else
		{
			char c;
			for (int i = 1; i <= n; i++)
			{
				// snow[i].reset();
				for (int j = 1; j <= n; j++)
				{
					cin >> c;
					if (c == '1')
					{
						// snow[i].set(j,true);
						snow[i][j] = 1;
					}
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					for (int k = i; k <= n; k++)
					{
						if (j + i - k > n)
						{
							break;
						}
						if (i + j <= k)
						{
							break;
						}
						for (int f = j + 1; f <= n; f++)
						{
							if (f + k <= j || i + f <= k || i + f <= j)
							{
								f = max(j - k, max(k - i, j - i)) + 1;
							}
							if (k + f - j > n || f + i - k > n || i + f - j > n)
							{
								break;
							}
							Pii p1 = {i, j}, p2 = {k, f};
							Pii p3 = {p2.first - (p1.second - p2.second), p2.second - (p2.first - p1.first)}, p4 = {p1.first - (p1.second - p2.second), p1.second - (p2.first - p1.first)};
							if (snow[p1.first][p1.second] && snow[p2.first][p2.second] && snow[p3.first][p3.second] && snow[p4.first][p4.second])
							{
								++cnt;
							}
						}
					}
				}
			}
			cout << cnt << endl;
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