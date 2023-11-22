#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int a[2][N], dp[2010][2010], _, n, m, q, id, b[2][N];
int num[2];

int init()
{
	if (a[1][1] > a[0][1])
	{
		_ = 1;
	}
	else _ = 0;
	int _1, _2;
	if (_ == 1)
	{
		_1 = m;
		_2 = n;
	}
	else _1 = n, _2 = m;
	for (int i = 0;i <= max(n, m);i++)
	{
		for (int j = 0;j <= max(n, m);j++)
		{
			dp[i][j] = 0;
			
		}
	}
	dp[0][0] = 1;
	for (int i = 1;i <= _1;i++)
	{
		for (int j = 1;j <= _2;j++)
		{
			if (a[_][i] > a[_ ^ 1][j])
			{
				dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j] | dp[i][j - 1];
			}
		}
	}
	
	return dp[_1][_2];
}

signed main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> id >> n >> m >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[0][i];
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> a[1][i];
	}
	for (int i = 0;i <= 1;i++)
	for (int j = 1;j <= n;j++)
	b[i][j] = a[i][j];
	if (id <= 7)
	{
		cout << init();
		while (q--)
		{
			cin >> num[0] >> num[1];
			while (num[0]--)
			{
				int pos, v;
				cin >> pos >> v;
				a[0][pos] = v;
			}
			while (num[1]--)
			{
				int pos, v;
				cin >> pos >> v;
				a[1][pos] = v;
			}
//			for (int i = 0;i <= 1;i++)
//			for (int j = 1;j <= n;j++)
//			cout << a[i][j] << " \n"[j == n];
			cout << init();
			for (int i = 0;i <= 1;i++)
			{
				for (int j = 1;j <= n;j++)
				a[i][j] = b[i][j];
			}
		}
	}
}
