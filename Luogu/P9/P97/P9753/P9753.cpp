#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P9753"

random_device rd;
sfmt19937_64 myrand(rd());
int k = myrand(), k1 = myrand(), k2 = myrand();

namespace std
{
	template <>
	struct hash<pair<int, int>>
	{
		size_t operator()(const pair<int, int> &x) const
		{
			return hash<int>()(x.first) * k + hash<int>()(x.second);
		}
	};
};

#define const constexpr

namespace Main
{

	const int N = 3e5 + 5;
	char str[N];
	cc_hash_table<pair<int, int>, int, hash<pair<int, int>>> cnt;
	int a[N];
	int main()
	{
		int T = 1;
		for (int i = 1; i <= 3e5; i++)
		{
			a[i] = myrand();
		}
		while (T--)
		{
			cnt.clear();
			int n, sum = 0;
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				cin >> str[i];
			}
			stack<char> s;
			unsigned int val = 0, val2 = 0;
			++cnt[{val, val2}];
			for (int i = 1; i <= n; i++)
			{
				if (s.empty() || s.top() != str[i])
				{
					s.push(str[i]);
					val ^= s.top() * a[s.size()];
					val2 += s.top() * a[s.size()];
				}
				else
				{
					val ^= s.top() * a[s.size()];
					val2 -= s.top() * a[s.size()];
					s.pop();
				}
				sum += cnt[{val, val2}];
				++cnt[{val, val2}];
			}
			cout << sum << endl;
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