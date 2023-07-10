#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long l, r;
		cin >> l >> r;
		auto mid = r / 2;
		if (l == 1)
		{
			cout << 0 << endl;
			continue;
		}
		auto a = 1ll << 40, ans = 0ll;
		while (a)
		{
			a >>= 1;
			if (l >= a)
			{
				ans += a * mid * (r - mid);
				ans %= mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
