#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("del.in", "r", stdin);
	freopen("del.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	// char c;
	int cnt = 0, res = 0;
	string str;
	cin >> str;
	res = str[0] - '0';
	str.erase(str.begin());
	for (char c : str)
	{
		c -= '0';
		res += c;
		while (res >= 10)
		{
			res = res / 10 + res % 10;
			++cnt;
		}
		++cnt;
	}
	cout << cnt;
	return 0;
}
