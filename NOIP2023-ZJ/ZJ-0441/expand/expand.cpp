#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 2e3 + 5;
const int MOD = 1e9 + 7;
inline int read ();
int ty,n,m,q,ans,a[MAX],b[MAX],c[MAX],d[MAX],dp[MAX][MAX];
bool check1 ();
bool check2 ();
int main ()
{
	freopen ("expand.in","r",stdin);
	freopen ("expand.out","w",stdout);
	ty = read ();n = read ();m = read ();q = read ();
	for (int i = 1;i <= n;++i) a[i] = read ();
	for (int i = 1;i <= m;++i) b[i] = read ();
	ans = check1 ();
	if (!ans) ans |= check2 ();
	printf ("%d",ans);
	while (q--)
	{
		int dx = read (),dy = read ();
		for (int i = 1;i <= n;++i) c[i] = a[i];
		for (int i = 1;i <= m;++i) d[i] = b[i];
		while (dx--)
		{
			int x = read (),y = read ();
			a[x] = y;
		}
		while (dy--)
		{
			int x = read (),y = read ();
			b[x] = y;
		}
		ans = check1 ();
		if (!ans) ans |= check2 ();
		printf ("%d",ans);
		for (int i = 1;i <= n;++i) a[i] = c[i];
		for (int i = 1;i <= m;++i) b[i] = d[i];
	}
	puts ("");
	return 0;
}
inline int read ()
{
	int s = 0,f = 1;
	char ch = getchar ();
	while (('0' > ch || ch > '9') && ch != EOF)
	{
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while ('0' <= ch && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar ();
	}
	return s * f;
}
bool check1 ()
{
	for (int i = 1;i <= n;++i)	
		for (int j = 1;j <= m;++j) dp[i][j] = 0;
	dp[1][1] = (a[1] > b[1]);
	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= m;++j)
		{
			if (i == 1 && j == 1) continue;
			if (a[i] <= b[j]) continue;
			dp[i][j] |= dp[i][j - 1];
			dp[i][j] |= dp[i - 1][j - 1];
			dp[i][j] |= dp[i - 1][j];
		}
	}
	return dp[n][m];
}
bool check2 ()
{
	for (int i = 1;i <= n;++i)	
		for (int j = 1;j <= m;++j) dp[i][j] = 0;
	dp[1][1] = (a[1] < b[1]);
	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= m;++j)
		{
			if (i == 1 && j == 1) continue;
			if (a[i] >= b[j]) continue;
			dp[i][j] |= dp[i][j - 1];
			dp[i][j] |= dp[i - 1][j - 1];
			dp[i][j] |= dp[i - 1][j];
		}
	}
	return dp[n][m];
}
