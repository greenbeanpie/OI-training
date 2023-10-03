#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "number"
#define const constexpr

namespace Main
{

	set<int> s;
	bool check(int num)
	{
		if (num < 100)
		{
			return 1;
		}
		int first = num % 10;
		num /= 10;
		int second = num % 10;
		int delta = first - second, last = second;
		num /= 10;
		while (num)
		{
			if (last - num % 10 != delta)
			{
				return 0;
			}
			last = num % 10;
			num /= 10;
		}
		return 1;
	}
	void dfs2(int num)
	{
		int first = num / 10, second = num % 10;
		int delta = second - first;
		int next = second + delta;
		while (next>=0&&next < 10&&num<=1e10)
		{
			num *= 10;
			num += next;
			next += delta;
			s.insert(num);
		}
	}
	void dfs1()
	{
		for (int i = 10; i <= 99; i++)
		{
			dfs2(i);
		}
	}

	int main()
	{
		int n;
		cin >> n;
		if (n >= 9876543210)
		{
			int maxinum = 0, len = log10(n) + 1;
			while (n >= 10)
			{
				maxinum = max(maxinum, n % 10);
				n /= 10;
			}
			if (maxinum > n)
			{
				for (int i = 1; i <= len; i++)
				{
					cout << n + 1;
				}
			}
			else
			{
				for (int i = 1; i <= len; i++)
				{
					cout << n;
				}
			}
			return 0;
		}
		else if (n < 100)
		{
			cout << n;
			return 0;
		}
		else if (n <= 10000)
		{
			for (int i = n;; i++)
			{
				if (check(i))
				{
					cout << i;
					return 0;
				}
			}
		}
		dfs1();
		s.insert(11111111111);
		cout << *s.lower_bound(n);
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