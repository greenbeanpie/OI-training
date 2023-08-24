#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "array"
#define const constexpr
#ifndef CODESPACE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#endif

namespace Main
{
	int n, m;
	int cnt[100005], minans, maxans;
	bool mp[21][100005], vis[21];
	random_device rd;
	sfmt19937 random(rd());
	void check()
	{
		int res = 0;
		for (int i = 1; i <= m; i++)
		{
			res += min(cnt[i], n - cnt[i]);
		}
		maxans = max(maxans, n * m - res);
		minans = min(minans, res);
	}
	void dfs(int now)
	{
		// if (clock() >= 5.95 * CLOCKS_PER_SEC)
		// {
		// 	check();
		// 	return;
		// }
		check();
		if (now >= (n + 1) / 2)
		{
			check();
			return;
		}
		int i = 1;
		while (vis[i])
			i = random() % n+1;
		vis[i] = 1;
		dfs(now+1);
		for (int j = 1; j <= m; j++)
		{
			mp[i][j] = !mp[i][j];
			if (mp[i][j])
			{
				++cnt[j];
			}
			else
			{
				--cnt[j];
			}
		}

		dfs(now + 1);
	}
	int main()
	{
		char c;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> c;
				if (c == '1')
				{

					mp[i][j] = 1;
					++cnt[j];
				}
			}
		}
		random_device rd;
		mt19937 random(rd());
		shuffle(&mp[1], &mp[n], random);
		minans = n * m;
		dfs(1);
		cout << min(minans, n * m - maxans);
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "1.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}