#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1127.in", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	sfmt11213 random(time(0));
	int n = random()%10+1;
	cout << n << endl;
	char last = random() % 10 + 'a';
	for (int i = 1; i <= n; i++)
	{
		cout << last;
		last = random() % 10 + 'a';
		cout << last << endl;
	}
	return 0;
}