#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P9566"
#define const constexpr

namespace Main
{

	const int N = 1e6 + 5;
	int n, m;
	char a[N];
	char b[N];
	bitset<N> tag;

	void setchar(char *a, char *b)
	{
		for (int i = 1; i <= n; i++)
		{
			a[i] = b[i];
		}
	}

	bool solve(char k, char b)
	{
		tag[1] = tag[n] = false;
		a[1] = k, a[n] = b;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (tag[i])
			{
				a[i] = '0';
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (a[i] != a[i + 1])
			{
				++sum;
			}
		}
		int tmp = (sum & 1) ^ (m & 1);
		if (tmp)
		{
			return 0;
		}
		if (sum > m)
		{
			bool f = 1;
			int l, r;
			for (int i = n - 1; i >= 1; i--)
			{
				if (sum == m)
				{
					break;
				}
				if (f && tag[i])
				{
					f = false;
					r = i;
				}
				if (!tag[i] && !f)
				{
					f = 1;
					l = i + 1;
					if (a[r + 1] == '1' && a[l - 1] == '1')
					{
						sum -= 2;
						for (int i = l; i <= r; i++)
						{
							a[i] = '1';
						}
					}
				}
			}
		}
		else
		{
			for (int i = n - 1; i > 1; i--)
			{
				if (sum == m)
				{
					break;
				}
				if (tag[i])
				{
					if (a[i + 1] == a[i] && a[i - 1] == a[i])
					{
						a[i] = '1';
						sum += 2;
					}
				}
			}
		}
		if (sum != m)
		{
			return 0;
		}
		return 1;
	}

	int main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			tag.reset();
			cin >> n >> m;
			cin >> (a + 1);
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == '?')
				{
					tag[i] = 1;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				b[i] = a[i];
			}
			if (a[1] == '?' && a[n] == '?')
			{
				if (solve('0', '0'))
				{
					cout << a + 1 << endl;
					continue;
				}
				setchar(a, b);
				if (solve('0', '1'))
				{
					cout << a + 1 << endl;
					continue;
				}
				setchar(a, b);
				if (solve('1', '0'))
				{
					cout << a + 1 << endl;
					continue;
				}
				setchar(a, b);
				if (solve('1', '1'))
				{
					cout << a + 1 << endl;
					continue;
				}
			}

			else if (a[1] == '?')
			{
				if (solve('0', a[n]))
				{
					cout << a + 1 << endl;
					continue;
				}
				setchar(a, b);

				if (solve('1', a[n]))
				{
					cout << a + 1 << endl;
					continue;
				}
			}
			else if (a[n] == '?')
			{

				if (solve(a[1], '0'))
				{
					cout << a + 1 << endl;
					continue;
				}
				setchar(a, b);
				if (solve(a[1], '1'))
				{
					cout << a + 1 << endl;
					continue;
				}
			}
			else
			{
				if (solve(a[1], a[n]))
				{
					cout << a + 1 << endl;
					continue;
				}
			}
			cout << "Impossible" << endl;
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