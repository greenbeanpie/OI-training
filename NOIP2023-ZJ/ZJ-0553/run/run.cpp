#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in","r",stdin);freopen(prob".out","w",stdout);

using namespace std;

const int N = 1010;

int n, m, k, d, c, T;

namespace C12
{
bool f[20]; int sum[20]; i64 res = 0;
struct Task { int x, y, v; } t[110];
inline bool chk()
{
	int cnt = 0;
	rep (i, 1, n)
	{
		if (f[i]) ++cnt;
		else cnt = 0;
		if (cnt > k) return false;
	}
	return true;
}
inline i64 calc()
{
	sum[0] = 0; i64 tot = 0;
	rep (i, 1, n) sum[i] = sum[i - 1] + f[i];
	rep (i, 1, m) if (sum[t[i].x] - sum[t[i].x - t[i].y] == t[i].y) tot += t[i].v;
	return tot - sum[n] * d;
}
inline void dfs(int i)
{
	if (i > n) { if (chk()) res = max(res, calc()); return; }
	f[i] = 0; dfs(i + 1);
	f[i] = 1; dfs(i + 1);
}
inline void solve()
{
	cin >> n >> m >> k >> d; res = 0;
	rep (i, 1, m) cin >> t[i].x >> t[i].y >> t[i].v;
	dfs(1);
	cout << res << endl;
}
}

namespace C1718
{
struct Task { int x, y, v; } t[100010];
inline void solve()
{
	cin >> n >> m >> k >> d; i64 res = 0;
	rep (i, 1, m) cin >> t[i].x >> t[i].y >> t[i].v;
	rep (i, 1, m)
	{
		if (t[i].y <= k and t[i].x - t[i].y >= 0)
		{
			if (1ll * t[i].y * d < t[i].v)
				res += t[i].v - 1ll * t[i].y * d;
		}
	}
	cout << res << endl;
}
}

int main()
{
	file("run");
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> T;
	if (c <= 2) { while (T--) C12::solve(); return 0; }
	// if (c <= 9) { while (T--) C19::solve(); return 0; }
	while (T--) C1718::solve();
	return 0;
}