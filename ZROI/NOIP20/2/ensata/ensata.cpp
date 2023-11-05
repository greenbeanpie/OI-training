#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef CODESPACE
#pragma GCC optimize(2)
#endif

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("ensata.in", "r", stdin);
	freopen("ensata.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int a, b;
	cin >> a >> b;
	if (a - b - 2 == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if (b == 0)
	{
		cout << a << endl;
		for (int i = 1; i <= a; i++)
		{
			cout << 1 << " " << i + 1 << endl;
		}
		return 0;
	}

	cout << a + b << endl;
	for (int i = 1; i <= b + 1; i++)
	{
		cout << i << " " << i + 1 << endl;
	}
	int last = b + 2;
	for (int i = 1; i <= b; i++)
	{
		cout << (1 + i) << " " << (2 + b + i) << endl;
	}
	for (int i = last + b + 1; i <= last + a - 1; i++)
	{
		cout << last << " " << i << endl;
	}
	return 0;
}
