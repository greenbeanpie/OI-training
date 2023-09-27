#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P4462"
#define const constexpr

namespace Main
{
	int n, m, k;
	const int N = 1e5 + 5;
	int prefix[N], cnt[N * 2], ans[N], nowans;

	struct node
	{
		int l, r, id, lb;
	} q[N];
	bool cmp(node a, node b)
	{
		return a.lb ^ b.lb ? a.lb < b.lb : (a.lb & 1 ? a.r < b.r : a.r > b.r);
	}
	void add(int u)
	{
		nowans += cnt[u ^ k];
		++cnt[u];
	}
	void del(int u)
	{
		--cnt[u];
		nowans -= cnt[u ^ k];
	}
	int main()
	{

		cin >> n >> m >> k;
		int temp, unit = sqrt(n);
		for (int i = 1; i <= n; i++)
		{
			cin >> temp;
			prefix[i] = prefix[i - 1] ^ temp;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> q[i].l >> q[i].r;
			--q[i].l;
			q[i].id = i;
			q[i].lb = (q[i].l - 1) / unit + 1;
		}
		cnt[0] = 1;
		int l = 0, r = 0;
		sort(q + 1, q + 1 + m, cmp);
		for (int i = 1; i <= m; i++)
		{
			while (l > q[i].l)
			{
				add(prefix[--l]);
			}
			while (l < q[i].l)
			{
				del(prefix[l++]);
			}
			while (r < q[i].r)
			{
				add(prefix[++r]);
			}
			while (r > q[i].r)
			{
				del(prefix[r--]);
			}
			ans[q[i].id] = nowans;
		}
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i] << endl;
		}
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