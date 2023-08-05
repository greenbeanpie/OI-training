#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[15][10];
int count(int n, int nowlen,bool flag=false)
{
	if (n == 0)
	{
		if (nowlen != 0)
		{
			count(n, nowlen - 1);
		}
		else
		{
			dp[nowlen][0] = 1;
			return 1;
		}
		for (int i = 2; i <= 9; i++)
		{
			dp[nowlen][0] += dp[nowlen - 1][i];
		}
		return dp[nowlen][0];
	}
	int now = n, len = log10(n), ans = 0, last = n / pow(10, len);
	if (len < nowlen)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				dp[i][j] = 0;
			}
		}
		count(now, nowlen - 1);
		for (int i = 2; i <= 9; i++)
		{
			dp[nowlen][0] += dp[nowlen - 1][i];
		}
		return dp[nowlen][0];
	}
	for (int i = 0; i <= min(9ll, n); i++)
	{
		dp[0][i] = 1;
		ans += dp[0][i];
	}
	if (n == 10)
	{
		return 10;
	}
	else if (n < 10)
	{
		return n + 1;
	}
	for (int i = 1; i < len; i++)
	{
		int temp = 0;
		for (int j = 0; j <= 9; j++)
		{
			temp += dp[i - 1][j];
		}
		dp[i][0] = temp - dp[i - 1][0] - dp[i - 1][1];
		// ans += dp[i][0];
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = temp - dp[i - 1][j - 1] - dp[i - 1][j] - dp[i - 1][j + 1];
			ans += dp[i][j];
		}
		dp[i][9] = temp - dp[i - 1][9] - dp[i - 1][8];
		ans += dp[i][9];
	}
	int temp = 0;
	for (int j = 0; j <= 9; j++)
	{
		temp += dp[len - 1][j];
	}
	for (int i = flag?1:0; i < last; i++)
	{
		if (i == 9)
		{
			dp[len][9] = temp - dp[len - 1][9] - dp[len - 1][8];
			ans += dp[len][i];
		}
		else if(i==0){
			dp[len][0]=temp-dp[len-1][0]-dp[len-1][1];
		}
		else
		{
			dp[len][i] = temp - dp[len - 1][i - 1] - dp[len - 1][i] - dp[len - 1][i + 1];
			ans += dp[len][i];
		}
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			dp[i][j] = 0;
		}
	}
	now %= (int)pow(10, len);
	count(now, nowlen - 1);
	for (int i = 0; i <= 9; i++)
	{
		if (abs(last - i) >= 2)
		{
			dp[len][last] += dp[len - 1][i];
			ans += dp[len - 1][i];
		}
	}
	return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P2657.in", "r", stdin);
	freopen("P2657.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l, r;
	cin >> l >> r;
	int a = count(r, log10(r));
	memset(dp, 0, sizeof(dp));
	int b = 0;
	if (l > 1)
	{
		b = count(l - 1, log10(l - 1),1);
	}
	else
	{
		b = count(l - 1, 0,1);
	}
	cout << a - b;
	return 0;
}