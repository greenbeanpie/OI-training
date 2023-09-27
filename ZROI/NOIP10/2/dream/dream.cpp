// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>

#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "dream"
#define const constexpr

int idx = 0;

struct operation
{
	int op, l, r;
} ops[500005];
set<int> query;

namespace Main
{
	int people[500005];
	int cnt[500005];
	int mark[500005];
	int main()
	{
		fill(people, people + 500001, 5e5);
		fill(mark, mark + 500001, 1e9);
		int n, q;
		cin >> n >> q;

		for (int i = 1; i <= q; i++)
		{
			cin >> ops[i].op >> ops[i].l >> ops[i].r;
			if (ops[i].op == 5)
			{
				query.insert(ops[i].l);
				++cnt[ops[i].l];
			}
		}
		for (int i = 1; i <= q; i++)
		{
			if(query.empty()){
				break;
			}
			auto start = query.lower_bound(ops[i].l), end = query.upper_bound(ops[i].r);
			for (auto j = start; j != end; j++)
			{
				switch (ops[i].op)
				{
					case 1:
						++people[*j];
						break;
					case 2:
						--people[*j];
						if(people[*j]<mark[*j]){
							mark[*j] = 1e9;
							break;
						case 3:
							mark[*j] = min(mark[*j], people[*j]);
							break;
						case 4:
							if (mark[*j] < 1e9)
							{
								people[*j] = mark[*j];
								mark[*j] = 1e9;
							}
							break;
						case 5:
							cout << people[*j] << endl;
							--cnt[*j];
							if (!cnt[*j])
							{
								int val = *j;
								--j;
								query.erase(val);
							}
							break;
						}
				}
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