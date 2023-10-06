#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "arrange"
#define const constexpr
#define a % b((a) % (b) + (b)) % (b)

namespace Main
{
	double st = clock();
	const int N = 5e5 + 5;
	int ans = 0xffffff, n, m;
	int pos[N];
	
	void dfs(int l, int r, int now, int res)
	{
		if(clock()-st>=CLOCKS_PER_SEC*1.9){
			cout << ans;
			exit(0);
		}
		if (now == n + 1)
		{
			ans = min(res, ans);
			return;
		}
		while (l > n && r > n)
		{
			l -= n, r -= n;
		}
		while (l <= 0 && r <= 0)
		{
			l += n, r += n;
		}
		int cost = 0;
		int nowpos = pos[now];
		if (l <= nowpos && nowpos <= r)
		{
			dfs(l, r, now + 1, res);
			return;
		}
		if (nowpos > r)
		{
			cost = l + n - nowpos;
			l -= cost;
			r -= cost;
			dfs(l, r, now + 1, res + cost);
			l += cost;
			r += cost;
			cost = nowpos - r;
			l += cost;
			r += cost;
			dfs(l, r, now + 1, res + cost);
			l -= cost;
			r -= cost;
		}
		else if (nowpos < l)
		{
			cost = nowpos + n - r;
			l += cost;
			r += cost;
			dfs(l, r, now + 1, res + cost);
			l -= cost;
			r -= cost;
			cost = l - nowpos;
			l -= cost;
			r -= cost;
			dfs(l, r, now + 1, res + cost);
			l += cost;
			r += cost;
		}
	}

	int main()
	{
		cin >> n >> m;
		for (int i = 1, temp; i <= n; i++)
		{
			cin >> temp;
			pos[temp] = i;
		}
		if(n>=0){
			ans = 0;
			for (int i = 1; i <= n; i++)
			{
				ans+=max(abs(pos[i]-i)-m+1,0ll);
			}
		}
		dfs(1, m, 1, 0);
		cout << ans << endl;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}