#include <bits/stdc++.h>
const int MaxN = 75;
const int MaxK = 155;

int n, V, a[MaxN], dp[MaxN][MaxN][MaxK];
int main()
{
    freopen("qigong.in", "r", stdin);
    freopen("qigong.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	V = *std::max_element(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; ++i)
	for(int k = 0; k <= V; ++k)
	if(k >= a[i] / 2) dp[i][i][k] = std::max(a[i], 2 * k);
	else dp[i][i][k] = INT_MAX / 2;
	
	for(int len = 2; len <= n; ++len)
	for(int l = 1, r = len; r <= n; ++l, ++r)
	for(int k = 0; k <= V; ++k)
	{
		dp[l][r][k] = INT_MAX / 2;
		if(k >= a[r] / 2)
		for(int p = 0; p <= V; ++p)
		dp[l][r][k] = std::min(dp[l][r][k], dp[l][r - 1][p] + std::max({a[r] - p, 2 * k - p, 0}));
		
		for(int m = l; m < r; ++m)
		for(int p = 0; p <= k; ++p)
		dp[l][r][k] = std::min(dp[l][r][k], dp[l][m][p] + dp[m + 1][r][k - p]);
	}
	
	for(int i = 1; i <= n; ++i)
	printf("%d ", *std::min_element(dp[1][i], dp[1][i] + V + 1));
	return 0;
}
