#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

char c[100005][55];
vector<int> vis;
signed main()
{
	freopen("P2580.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	mt19937 a(time(0));
	int n = 10000, m = a() % 100000;
	cout << n << endl;
	for (int i = 1; i <= n; i++)
	{
		int len = a() % 50 + 1;
		for (int j = 0; j < len; j++)
		{
			c[i][j] = 'a' + rand() % 26;
			cout << c[i][j];
		}
		cout << endl;
	}
	cout << m << endl;
	for (int i = 1; i <= m; i++)
	{
		if (a() % 2)
		{
			int len = a() % 50 + 1;
			for (int j = 1; j <= len; j++)
			{
				cout << (char)('a' + rand() % 26);
			}
		}
		else
		{
			int now = a() % n + 1;
			cout << c[now];
		}
		cout << endl;
	}
	return 0;
}