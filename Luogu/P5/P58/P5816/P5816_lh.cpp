#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

int n, x, y, cnt, X[N], mx[N], mn[N], tot;
struct point
{
	int x, y;
	bool operator==(const point &other) const
	{
		return x == other.x && y == other.y;
	}
} ps[N];

#define lowbit(x) ((x) & -(x))
int d[N];

void add(int x, int k)
{
	while (x <= n)
	{
		d[x] += k;
		x += lowbit(x);
	}
}

int query(int x)
{
	int res = 0;
	while (x)
	{
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{
	// FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ps[i].x >> ps[i].y;
		X[i] = ps[i].x;
	}
	sort(X + 1, X + n + 1);
	cnt = unique(X + 1, X + n + 1) - X - 1;
	for (int i = 1; i <= cnt; i++)
		mx[i] = -INF, mn[i] = INF;
	for (int i = 1; i <= n; i++)
	{
		ps[i].x = lower_bound(X + 1, X + cnt + 1, ps[i].x) - X;
		mx[ps[i].x] = max(ps[i].y, mx[ps[i].x]),
		mn[ps[i].x] = min(ps[i].y, mn[ps[i].x]);
	}
	sort(ps + 1, ps + n + 1, [](point a, point b)
		 { return a.y == b.y ? a.x < b.x : a.y > b.y; });
	int h = INF, l, r;
	for (int i = 1; i <= n; i++)
	{
		if (ps[i].y < h)
		{
			tot += query(r) - query(l - 1),
				h = ps[i].y;
			l = INF, r = -INF;
		}
		l = min(ps[i].x, l);
		r = max(ps[i].x, r);
		if (ps[i].y == mx[ps[i].x])
			add(ps[i].x, 1);
		if (ps[i].y == mn[ps[i].x])
		{
			tot++;
			add(ps[i].x, -1);
		}
	}
	cout << tot;

	return 0;
}
