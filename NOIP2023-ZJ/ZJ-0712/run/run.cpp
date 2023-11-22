#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e5 + 5;

struct node
{
	long long x, y, v, l;
} a[M];

int n, m, k, d;
long long ans;
long long dp[M];

inline bool cmp(const node &p, const node &q)
{
	return p.y < q.y;
}

inline void solve1()
{
	ans = 0;
	for(int i = 1; i <= m; ++ i)
	{
		if(a[i].y > k) continue;
		if(a[i].y * d < a[i].v)
			ans += a[i].v - a[i].y * d;
	}
	cout << ans << '\n';
}

inline void solve2()
{sort(a + 1, a + m + 1, cmp);
	
	for(int i = 1; i <= n; ++ i)
		dp[i] = -1e18;
	for(int i = 1; i <= m; ++ i)
	{
		if(a[i].y > k) continue;
		if(a[i].y > a[i].x) continue;
		for(int j = 0; j < a[i].x - k; ++ j)
			dp[a[i].x] = max(dp[a[i].x], dp[j]);
		dp[a[i].x] += (a[i].v - a[i].y * d);
		for(int j = i - 1; j; -- j)
		{
			if(a[j].x <= a[i].x - k) break;
			if(a[j].l <= a[i].x - k) continue;
			if(a[j].l >= a[i].l)
				dp[a[i].x] += a[j].v;
			else
				dp[a[i].x] += max(0ll, a[j].v - (a[i].l - a[j].l) * d);
		}
	}
	ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while(T -- )
	{
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; ++ i)
			cin >> a[i].x >> a[i].y >> a[i].v, a[i].l = a[i].x - a[i].y + 1;
		if(c >= 17 && c <= 18) solve1();
		else solve2();
	}
}