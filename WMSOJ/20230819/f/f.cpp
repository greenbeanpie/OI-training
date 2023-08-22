#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
const int N = 1e5 + 5, INF = 2e9 + 1;
cc_hash_table<int, bool> mp;
long long num[60], siz;

int n, a[N];
int dp[N];
int main()
{
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
	long long last = 1, now = 2;
	num[++siz] = 0, num[++siz] = 1;
	while (now <= INF)
	{
		num[++siz] = now;
		long long tmp = now;
		now = now + last;
		last = tmp;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 1;
	mp[a[1]] = 1;
	for (int i = 2; i <= n; i++)
	{
		bool ok = 1;
		for (int j = 1; j <= siz; j++)
		{
			if (mp.find(num[j] - a[i])!=mp.end())
			{
				ok = 0;
				break;
			}
		}
		if (!ok)
			mp.clear(), ans++;
		mp[a[i]] = 1;
	}
	cout << ans;
	return 0;
}