#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("P5542.in", "r", stdin);
	freopen("P5542.out", "w", stdout);
#endif
	int n, k;
	int delta[1010][1010];
	int sum[1010][1010];
	memset(delta, 0, sizeof(delta));
	memset(sum, 0, sizeof(sum));
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		delta[x1+1][y1+1]++;
		delta[x2+1][y2+1]++;
		delta[x1+1][y2+1]--;
		delta[x2+1][y1+1]--;
	}
	int tot = 0;
	for (int i = 1; i <= 1005; i++)
	{
		for (int j = 1; j <= 1005; j++)
		{
			sum[i][j] = delta[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
			if (sum[i][j] == k)
			{
				tot++;
			}
		}
	}
	cout << tot;
	return 0;
}