#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "naughty"
#define const constexpr

const int N = 1e6 + 10,mod=1e9+7;
int num[N], n, pre[N], dp[N], sum[N];

signed main()
{
#ifndef ONLINE_JUDGE
	// freopen(problemname ".in", "r", stdin);
	// freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	deque<int> q;
	int l = n + 1;
	for (int r = n; r >= 1; r--)
	{
		while (q.size() && q.front() > r)
		{
			q.pop_front();
		}
		while (l - 1)
		{
			if (min(num[l - 1], (!q.size() ? n : num[q.front()])) >= r - (l - 1) + 1)
			{
				l--;
				while (q.size() && num[q.back()] > num[l])
				{
					q.pop_back();
				}
				q.push_back(l);
			}
			else{
				break;
			}
		}
		pre[r] = l;
	}
	dp[0]=sum[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=(sum[i-1]-(pre[i]==1?0:sum[pre[i]-2])+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	cout << dp[n];
	return 0;
}