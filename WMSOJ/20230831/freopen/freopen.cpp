#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "freopen"
#define const constexpr

namespace Main
{
	const int N = 2e5;
	struct node
	{
		int l, r, c;
	} q[N];
	int num[N];
	int ans = INT_MAX;
	bitset<N> vis;
	int n, m;
	void dfs(int last, int sum)
	{
		bool flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			ans = min(ans, sum);
			return;
		}
		for (int i = last + 1; i <= m; i++)
		{
			vector<int> temp;
			for (int j = q[i].l; j != q[i].r; j++)
			{
				if (!vis[j])
				{
					vis[j] = 1;
					temp.push_back(j);
				}
			}
			if (temp.empty())
			{
				continue;
			}
			dfs(i, sum + q[i].c);
			for (int j : temp)
			{
				vis[j] = 0;
			}
		}
	}
	int main()
	{

		cin >> n >> m;
		if (m < n)
		{
			cout << "Genshin Impact, Qi Dong!" << endl;
			return 0;
		}
		// for (int i = 1; i <= n; i++)
		// {
		// 	cin >> num[i];
		// }
		bool flag = 1;
		for (int i = 1; i <= m; i++)
		{
			cin >> q[i].l >> q[i].r >> q[i].c;
			flag = flag && (q[i].l == q[i].r);
		}
		if (flag)
		{
			unordered_map<int, int> mp;
			for (int i = 1; i <= m; i++)
			{
				if (mp.find(q[i].l) == mp.end())
				{
					mp[q[i].l] = q[i].c;
				}
				else
				{
					mp[q[i].l] = min(mp[q[i].l], q[i].c);
				}
			}
			if (mp.size() < n)
			{
				cout << "Genshin Impact, Qi Dong!" << endl;
				return 0;
			}
			int sum = 0;
			for (int i = 1; i <= n; i++)
			{
				sum += mp[i];
			}
			cout << sum << endl;
			return 0;
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