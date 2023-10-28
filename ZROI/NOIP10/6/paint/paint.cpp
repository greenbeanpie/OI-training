#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "paint"
#define const constexpr

namespace Main
{
	random_device rd;
	sfmt19937_64 myrand(rd());
	const int N = 10000;
	int num[N];
	int main()
	{
		int n, k, A, B, sum = 0;
		cin >> n >> k >> A >> B;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			sum += num[i];
		}
		sort(num + 1, num + 1 + n, greater<int>());
		for (int i = 1; i <= n; i += k)
		{
			int sum1 = 0, sum2 = A;
			for (int j = i; j <= i + k - 1; j++)
			{
				sum1 += num[j];
			}
			if (sum1 < sum2)
			{
				break;
			}
			else
			{
				sum = sum - sum1 + sum2;
			}
		}
		cout << sum << endl;
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
