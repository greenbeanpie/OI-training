#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

struct node
{
	int val, cnt;
};
int num[1005][1005];
int tot[1005];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P2216.in", "r", stdin);
	freopen("P2216.out", "w", stdout);
#endif
	deque<node> qmax[1005], qmin[1005];
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b, n;
	cin >> a >> b >> n;
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			cin >> num[i][j];
		}
	}
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			while (qmax[i].size() && qmax[i].front().val < num[i][j])
			{
				qmax[i].pop_front();
			}
			qmax[i].push_front({num[i][j], ++tot[i]});
			while (qmin[i].size() && qmin[i].front().val > num[i][j])
			{
				qmin[i].pop_front();
			}
			qmin[i].push_front({num[i][j], tot[i]});
		}
	}
	int ans = INT_MAX;
	deque<node> max1, min1;
	for (int j = 1; j <= a; j++)
	{
		while (max1.size() && max1.front().val < qmax[j].back().val)
		{
			max1.pop_front();
		}
		max1.push_front({qmax[j].back().val, j});
		if (max1.back().cnt <= j - n)
		{
			max1.pop_back();
		}
		while (min1.size() && min1.front().val > qmin[j].back().val)
		{
			min1.pop_front();
		}
		min1.push_front({qmin[j].back().val, j});
		if (min1.back().cnt <= j - n)
		{
			min1.pop_back();
		}
		if (j >= n)
		{
			ans = min(ans, max1.back().val - min1.back().val);
		}
	}
	for (int i = n + 1; i <= b; i++)
	{ // row

		for (int j = 1; j <= a; j++)
		{ // line
			if (qmax[j].back().cnt <= i - n)
			{
				qmax[j].pop_back();
			}
			if (qmin[j].back().cnt <= i - n)
			{
				qmin[j].pop_back();
			}
			while (qmax[j].size() && qmax[j].front().val < num[j][i])
			{
				qmax[j].pop_front();
			}
			qmax[j].push_front({num[j][i], ++tot[j]});
			while (qmin[j].size() && qmin[j].front().val > num[j][i])
			{
				qmin[j].pop_front();
			}
			qmin[j].push_front({num[j][i], tot[j]});
		}
		deque<node> max1, min1;
		for (int j = 1; j <= a; j++)
		{
			while (max1.size() && max1.front().val < qmax[j].back().val)
			{
				max1.pop_front();
			}
			max1.push_front({qmax[j].back().val, j});
			if (max1.back().cnt <= j - n)
			{
				max1.pop_back();
			}
			while (min1.size() && min1.front().val > qmin[j].back().val)
			{
				min1.pop_front();
			}
			min1.push_front({qmin[j].back().val, j});
			if (min1.back().cnt <= j - n)
			{
				min1.pop_back();
			}
			if (j >= n)
			{
				ans = min(ans, max1.back().val - min1.back().val);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}