#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define endl "\n"
#define problemname "P5064"
#define const constexpr

namespace Main
{

	const int N = 1e5 + 5;

	int unit, unitcnt, val[N], temp[N], maxdep[N], fa[N], cnt[N], ans[N], posb[N];

	unsigned short block[N][28];

	struct edge
	{
		int v, nxt;
		int op, x, y;
	} op[N];
	int head[N], tot = 0;

	void insert(int fa, int pos, int opt, int x, int y = 0)
	{
		op[++tot].v = pos;
		op[tot].nxt = head[fa];
		head[fa] = tot;
		op[pos].op = opt, op[pos].x = x, op[pos].y = y;
	}

	int find(int x)
	{
		return x == fa[x] ? x : find(fa[x]);
	}

	void dfs(int pos)
	{
		int x = op[pos].x, y = op[pos].y, fatherx = find(x), fathery = find(y);
		int deptmp = maxdep[fatherx];
		if (op[pos].op == 1)
		{
			if (fatherx != fathery)
			{
				if (maxdep[fatherx] < maxdep[fathery]) // dep 用于按秩合并
				{
					swap(fatherx, fathery);
				}
				deptmp = maxdep[fatherx];
				fa[fathery] = fatherx;
				maxdep[fatherx] = max(maxdep[fatherx], maxdep[fathery] + 1);
				for (int i = 1; i <= unitcnt; i++)
				{
					block[fatherx][i] += block[fathery][i];
				}
			}
		}
		else if (op[pos].op == 3)
		{
			int rnk = op[pos].y;
			for (int i = 1; i <= unitcnt; i++)
			{
				if (block[fatherx][i] < rnk)
				{
					rnk -= block[fatherx][i];
				}
				else
				{
					int j;
					// while (rnk && pos1 <= unit * i)
					// {
					// 	++pos1;
					// 	if (find(posb[pos1]) == fatherx)
					// 	{
					// 		--rnk;
					// 	}
					// }
					for (j = unit * (i - 1) + 1; j <= unit * i; j++)
					{
						if (find(posb[j]) == fatherx)
						{
							--rnk;
						}
						if (!rnk)
						{
							ans[pos] = temp[j];
							break;
						}
					}
					break;
				}
			}
			if (rnk)
			{
				ans[pos] = -1;
			}
		}
		for (int i = head[pos]; i; i = op[i].nxt)
		{
			dfs(op[i].v);
		}
		if (op[pos].op == 1 && fatherx != fathery)
		{
			maxdep[fatherx] = deptmp;
			fa[fathery] = fathery;
			for (int i = 1; i <= unitcnt; i++)
			{
				block[fatherx][i] -= block[fathery][i];
			}
		}
	}

	int main()
	{
		int n, m;

		cin >> n >> m;

		unit = n / 26 + 1;
		unitcnt = n / unit + 1;
		assert(unitcnt < 31);
		// fill(ans, ans + 100001, -1);

		for (int i = 1; i <= n; i++)
		{
			cin >> val[i];
			temp[i] = val[i];
			fa[i] = i;
			maxdep[i] = 1;
		}

		sort(temp + 1, temp + 1 + n);

		for (int i = 1; i <= n; i++)
		{
			val[i] = lower_bound(temp + 1, temp + 1 + n, val[i]) - temp;
			val[i] += cnt[val[i]]++;
			posb[val[i]] = i;
			// ++cnt[i];
			block[i][(val[i] - 1) / unit + 1] = 1;
		}

		for (int i = 1, opt, x, y; i <= m; i++)
		{
			cin >> opt;
			if (opt == 2)
			{
				cin >> x;
				insert(x, i, opt, x);
			}
			else
			{
				cin >> x >> y;
				insert(i - 1, i, opt, x, y);
			}
		}
		dfs(0);
		for (int i = 1; i <= m; i++)
		{
			if (op[i].op == 3)
			{
				cout << ans[i] << endl;
			}
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