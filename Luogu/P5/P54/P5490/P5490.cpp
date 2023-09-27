#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P5490"
#define const constexpr

const int N = 2e6 + 5;
struct scanline
{
	int l, r, h;
	short val;
} line[N >> 1];
int temp[N];
bool operator<(scanline a, scanline b)
{
	return a.h < b.h;
}

struct IntervalTree
{
public:
	vector<int> sum = vector<int>(N << 1), len = vector<int>(N << 1);
	vector<int> *arr;
	int size;
	void range_add(int l, int r, int val)
	{
		range_add(1, 1, size, l, r, val);
	}

protected:
	void update(int u, int cl, int cr)
	{
		if (sum[u])
		{
			len[u] = temp[cr + 1] - temp[cl];
		}
		else
		{
			len[u] = len[u << 1] + len[(u << 1) | 1];
		}
	}
	void range_add(int u, int cl, int cr, int l, int r, int val)
	{
		if (l <= cl && cr <= r)
		{
			sum[u] += val;
			update(u, cl, cr);
			return;
		}
		int cmid = (cl + cr) >> 1;
		if (l <= cmid)
		{
			range_add(u << 1, cl, cmid, l, r, val);
		}
		if (r > cmid)
		{
			range_add(u << 1 | 1, cmid + 1, cr, l, r, val);
		}
		update(u, cl, cr);
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "_3.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int x1, x2, y1, y2;
	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		line[(i << 1) - 1] = {x1, x2, y1, 1};
		line[i << 1] = {x1, x2, y2, -1};
		temp[(i << 1) - 1] = x1;
		temp[i << 1] = x2;
	}
	sort(temp + 1, temp + 1 + 2 * n);
	sort(line + 1, line + 2 * n + 1);
	int tot = unique(temp + 1, temp + 1 + 2 * n) - temp - 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		line[i].l = lower_bound(temp + 1, temp + 1 + tot, line[i].l) - temp;
		line[i].r = lower_bound(temp + 1, temp + 1 + /*2 * n*/ tot, line[i].r) - temp - 1;
	}
	IntervalTree SegTree;
	SegTree.size = tot;
	int ans = 0;
	for (int i = 1; i < n * 2; i++)
	{
		SegTree.range_add(line[i].l, line[i].r, line[i].val);
		ans += SegTree.len[1] * (line[i + 1].h - line[i].h);
	}
	cout << ans;
	return 0;
}