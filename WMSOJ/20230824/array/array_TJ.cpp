#include <bits/stdc++.h>
#define ll long long
#define re register
#define rep(i, l, r) for (int i = l; i <= r; i++)
using namespace std;
#define N 25
#define M 100005
string st;
int n, m;
int zt[M];
int dp[N][(1 << 20) + 9];
int ans;
void fre()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
}

int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ans = n * m;
	for (int i = 1; i <= n; i++)
	{
		cin >> st;
		for (int j = 0; j < st.length(); j++)
			zt[j + 1] = (zt[j + 1] << 1) + (st[j] - '0');
	}
	for (int i = 1; i <= m; i++)
		dp[0][zt[i]]++;
	for (int i = 0; i < n; i++)
		for (int j = n; j >= 1; j--)
			for (int k = 0; k < (1 << n); k++)
				dp[j][k] += dp[j - 1][k ^ (1 << i)];

	for (int i = 0; i < (1 << n); i++)
	{
		int res = 0;
		for (int j = 0; j <= n; j++)
			res += dp[j][i] * min(j, n - j);
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}