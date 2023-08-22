#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "B"
#define const constexpr

vector<pair<int, int>> first, second;
int max1, max2;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname "_TJ.out", "w", stdout);
#endif
	double start = clock();
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T, n, nowans;
	cin >> T;
	while (T--)
	{
		cin >> n;
		max1 = max2 = 0;
		first.clear();
		second.clear();
		string str;
		cin >> str;
		int maxlen = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'T')
			{
				int start = i;
				while (i <= n && str[++i] == 'T')
					;
				--i;
				if (i - start + 1 > max1)
				{
					max2 = max1;
					swap(second, first);
					first.clear();
					first.push_back({start, i});
					max1 = i - start + 1;
				}
				else if (i - start + 1 == max1)
				{
					first.push_back({start, i});
				}
				else if (i - start + 1 > max2)
				{
					second.clear();
					max2 = i - start + 1;
					second.push_back({start, i});
				}
				else if (i - start + 1 == max2)
				{
					second.push_back({start, i});
				}
			}
		}
		int temp = 0;
		for (auto i : first)
		{
			if (clock() - start >= 0.5 * CLOCKS_PER_SEC)
			{
				break;
			}
			temp = 0;
			int a = i.first - 1, b = i.second + 1;
			if (a > 1 && str[a - 1] == 'T' && str[a] == 'B')
			{
				while (a > 1 && str[a - 1] == 'T' && str[a] == 'B')
				{
					a -= 2;
				}
				if (str[a - 1] == 'B' && str[a] == 'T')
				{
					++temp;
				}
			}
			if (str[b] == 'B' && str[b + 1] == 'T')
			{
				while (b < n - 2 && str[b] == 'B' && str[b + 1] == 'T')
				{
					b += 2;
				}
				if (b < n && str[b] == 'T' && str[b + 1] == 'B')
				{
					++temp;
				}
			}
			maxlen = max(maxlen, i.second - i.first + 1 + temp);
		}

		if ((maxlen - max1 == 0) || (maxlen - max1 == 1 && max1 - max2 == 1))
		{
			for (auto i : second)
			{
				if (clock() - start >= 0.9 * CLOCKS_PER_SEC)
				{
					break;
				}
				temp = 0;
				int a = i.first - 1, b = i.second + 1;
				if (a > 1 && str[a - 1] == 'T' && str[a] == 'B')
				{
					while (a > 1 && str[a - 1] == 'T' && str[a] == 'B')
					{
						a -= 2;
					}
					if (str[a - 1] == 'B' && str[a] == 'T')
					{
						++temp;
					}
				}
				if (b < n - 2 && str[b] == 'B' && str[b + 1] == 'T')
				{
					while (b < n - 2 && str[b] == 'B' && str[b + 1] == 'T')
					{
						b += 2;
					}
					if (str[b] == 'T' && str[b + 1] == 'B')
					{
						++temp;
					}
				}
				maxlen = max(maxlen, i.second - i.first + 1 + temp);
			}
		}
		cout << maxlen << endl;
	}
	return 0;
}