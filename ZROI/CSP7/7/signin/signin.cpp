#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define double long double

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("signin.in", "r", stdin);
	freopen("signin.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	while (n)
	{
		int temp = (double)logf64x(n) / logf64x(60);
		temp = pow(60, temp);
		ans += n / temp;
		n %= temp;
	}
	cout << ans << endl;

	return 0;
}
