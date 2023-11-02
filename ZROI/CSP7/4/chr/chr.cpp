#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long

const int N = 5e5 + 5;

unsigned maxinum[N][20], mininum[N][20];

int T,n;

int querymax(int l, int r)
{
	if (r < l)
	{
		return -1145141919810;
	}
	int len = log2f64x(r - l + 1);
	return max(maxinum[l][len], maxinum[r - (1 << len) + 1][len]);
}

int querymin(int l, int r)
{
	if (r < l)
	{
		return 1145141919810;
	}
	int len = log2f64x(r - l + 1);
	return min(mininum[l][len], mininum[r - (1 << len) + 1][len]);
}

int getans(int l,int r){
	return max(querymax(l, r) - querymin(l, r), max(querymax(1, l - 1), querymax(r + 1, n)) - min(querymin(1, l - 1), querymin(r + 1, n)));
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("chr.in", "r", stdin);
	freopen("chr.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		int minl = 1919810, minr = 0, minval = 1145141919;
		for (int i = 1; i <= n; i++)
		{
			cin >> maxinum[i][0];
			mininum[i][0] = maxinum[i][0];
			if (mininum[i][0] < minval)
			{
				minval = mininum[i][0];
				minl = minr = i;
			}
			else if (mininum[i][0] == minval)
			{
				minr = i;
			}
		}

		for (int i = 1; (1 << i) <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				mininum[j][i] = min(mininum[j][i - 1], mininum[j + (1 << (i - 1))][i - 1]);
				maxinum[j][i] = max(maxinum[j][i - 1], maxinum[j + (1 << (i - 1))][i - 1]);
			}
		}
		int maxans = querymax(minl, minr);
		int l = minl, r = minr;
		while (l>1&&mininum[l - 1][0] <= maxans)
		{
			--l;
		}
		while (r<n&&mininum[r + 1][0] <= maxans)
		{
			++r;
		}
		int ans = max(querymax(minl, minr) - querymin(minl, minr), max(querymax(1, minl - 1),querymax(minr + 1, n)) -min(querymin(1, minl - 1), querymin(minr + 1, n)));
		while (querymax(l, r) != querymax(1, n))
		{
			if ((l>1&&r<n&&mininum[l - 1][0] <= mininum[r + 1][0])||(l>1&&r>=n))
			{
				maxans = mininum[l - 1][0];
			}
			else if(r<n)
			{
				maxans = mininum[r + 1][0];
			}
			else{
				break;
			}
			while (l>1&&mininum[l - 1][0] <= maxans)
			{
				--l;
			}
			while (r<n&&mininum[r + 1][0] <= maxans)
			{
				++r;
			}
			ans = min(ans, max(querymax(l, r) - querymin(l, r), max(querymax(1, l - 1), querymax(r + 1, n)) - min(querymin(1, l - 1), querymin(r + 1, n))));
		}
		ans = min(ans, max(querymax(l, r) - querymin(l, r), max(querymax(1, l - 1), querymax(r + 1, n)) - min(querymin(1, l - 1), querymin(r + 1, n))));
		cout << ans << endl;
	}
	return 0;
}
