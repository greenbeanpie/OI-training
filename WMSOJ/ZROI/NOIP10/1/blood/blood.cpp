#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "blood"
#define const constexpr
#ifdef CODESPACE
#define cc_hash_table unordered_map
#endif

namespace Main
{
	int n;
	string str;
	extern void dfs(int now, int x, int y);
	set<pair<int, int>> res;
	int myhash(int x, int y)
	{
		return x * 10000 + y;
	}
	cc_hash_table<int, int> mp;
	cc_hash_table<char, pair<int, int>> wk;

	int main()
	{
		cin >> n;
		cin >> str;
		wk['L'] = {-1, 0};
		wk['R'] = {1, 0};
		wk['U'] = {0, 1};
		wk['D'] = {0, -1};
		dfs(0, 0, 0);
		cout << res.size() << endl;
		for (auto i : res)
		{
			cout << i.first << " " << i.second << endl;
		}
		return 0;
	}

	void dfs(int now, int x, int y)
	{
		if (now >= n)
		{
			res.emplace(x, y);
			return;
		}
		bool flag = 0;
		if (mp.find(myhash(x, y)) == mp.end())
		{
			mp[myhash(x, y)] = -1;
		}
		else
		{
			flag = 1;
		}
		int tx = x + wk[str[now]].first, ty = y + wk[str[now]].second;
		if (mp.find(myhash(tx, ty)) == mp.end() || mp[myhash(tx, ty)] != 1)
		{
			dfs(now + 1, tx, ty);
			if (mp[myhash(tx, ty)] != -1)
			{
				mp[myhash(tx, ty)] = 1;
				dfs(now + 1, x, y);
				mp.erase(myhash(tx, ty));
			}
		}
		else
		{
			dfs(now + 1, x, y);
		}
		if (!flag)
		{
			mp.erase(myhash(x, y));
		}
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