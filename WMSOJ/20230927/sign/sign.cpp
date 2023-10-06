#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// #define int long long
// #define double long double
#define endl "\n"
#define problemname "sign"
#define const constexpr

namespace Main
{
	const int N = 2e6 + 5;
	int fa[N], siz[N];
	int n, t;
	struct node
	{
		vector<int> v;
		int k, id;
	} stu[N];
	bool operator<(node a, node b)
	{
		return a.k < b.k;
	}
	int find(int x)
	{
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	void merge(int u, int v)
	{
		siz[v] += siz[u];
		fa[u] = v;
	}
	bitset<N> vis;
	void solve()
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> stu[i].k;
			stu[i].id = i;
			stu[i].v.clear();
			for (int j = 1, temp; j <= stu[i].k; j++)
			{
				cin >> temp;
				stu[i].v.push_back(temp + 1e6);
			}
		}
		sort(stu + 1, stu + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			fa[i] = i;
			siz[i] = 0;
		}
		for (int i = 1e6 + 1; i <= 1e6 + n; i++)
		{
			fa[i] = i;
			siz[i] = 1;
		}
		int ansa = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j : stu[i].v)
			{
				int faj = find(j), fai = find(i);
				if (faj != fai)
				{
					merge(fai, faj);
				}
			}
			int fai = find(i);
			if (siz[fai] > stu[i].k)
			{
				ansa = i;
				break;
			}
		}
		cout << (ansa ? "YES" : "NO") << endl;
		return;
	}
	int main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			solve();
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
