#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
signed main()
{
	cin >> a >> b;
	c = a;
	if (a == 1e9 && b != 1)
	{
		cout << -1;
		return 0;
	}
	for (int i = 2; i <= b; i++)
	{
		a *= c;
		if (a > 1e9)
		{
			cout << -1;
			return 0;
		}
	}
	cout << a;
	return 0;
}