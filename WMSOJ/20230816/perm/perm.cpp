#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "perm"
#define const constexpr
const int N = 1e6 + 10;
// #define dp [(i)][(j)] dp[myhash((i), (j))]
int nxt[N], g[N << 1], end1[N << 1], start[N << 1];
int num1[N], num2[N], pos[N], q[N], f[N];
int n, m;

// int myhash(int a, int b)
// {
// 	return hash<int>()(a.first * N + a.second);
// }

// cc_hash_table<int, int> dp;

int check(int l, int r, int x)
{
	int mid,t=0;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (q[mid] <= x)
		{
			t=mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return q[t];
}

int dp(int x, int y)
{
	if (x == 0 || y == 0)
	{
		return x + y;
	}
	if (num1[x] == num2[y])
	{
		if (f[x])
		{
			return f[x];
		}
		return f[x] = min(dp(x - 1, y), dp(x, y - 1))+1;
	}
	int seg = check(start[x - y + n], end1[x - y + n], x);
	return seg ? dp(seg, y - x + seg) + x - seg : max(x,y);
}
void ins(int x, int y)
{
	nxt[y] = g[x];
	g[x] = y;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num1[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> num2[i];
		pos[num2[i]] = i;
	}
	for (int i = n; i >= 1; i--)
	{
		ins(i - pos[num1[i]] + n, i);
	}
	for (int i = 1; i < (n << 1); end1[i++] = m)
	{
		start[i] = m + 1;
		for (int j = g[i]; j; j = nxt[j])
		{
			q[++m] = j;
		}
	}
	cout << dp(n, n);
	return 0;
}