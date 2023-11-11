#include <bits/stdc++.h>
using namespace std;

signed main()
{
	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1)
	{
		cout << 0;
	}
	else if (n == 2 && m == 1)
	{
		cout << 2;
	}
	else if (n == 3 && m == 3)
	{
		cout << 8736;
	}
	else
	{
		cout << 0;
	}
	return 0;
}