#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3369"
#define const constexpr

namespace Main
{
	int l = -1e7, r = 1e7;
	random_device rd;
	sfmt216091_64 myrand(rd());
	uniform_int_distribution<> dist(l, r);

	int main()
	{
		int op = myrand() % 100000 + 1;
		cout << op << endl;
		cout << "1 -10000005\n1 10000005\n";
		int cnt = 0;
		multiset<int> ms;
		ms.insert(-10000005);
		ms.insert(10000005);
		for (int i = 3; i <= op; i++)
		{
		flag1:
			int now = myrand() % 60 + 1;
			if (now <= 12)
			{
				if (now == 12 && ms.size() > 2)
				{
					auto num = ms.lower_bound(dist(myrand));
					if (*num <= -1e7)
					{
						++num;
					}
					if (*num >= 1e7)
					{
						--num;
					}
					cout << 1 << " " << *num << endl;
					ms.insert(*num);
					continue;
				}
				int num = dist(myrand);
				ms.insert(num);
				cout << 1 << " " << num << endl;
				++cnt;
			}
			else if (now <= 15)
			{
				if (ms.size() == 2)
				{
					goto flag1;
				}
				auto num = ms.lower_bound(dist(myrand));
				if (*num >= 10000005)
				{
					--num;
				}
				if (*num <= -10000005)
				{
					++num;
				}
				cout << 2 << " " << *num << endl;
				ms.erase(num);
				--cnt;
			}
			else if (now <= 25)
			{
				if (ms.size() == 2)
				{
					goto flag1;
				}
				auto num = ms.lower_bound(dist(myrand));
				if (*num > 1e7)
				{
					--num;
				}
				if (*num < -1e7)
				{
					++num;
				}
				cout << 3 << " " << *num << endl;
			}
			else if (now <= 35)
			{
				if (ms.size() == 2)
				{
					goto flag1;
				}
				cout << 4 << " " << myrand() % cnt + 1 << endl;
			}
			else if (op <= 48)
			{
				cout << 5 << " " << dist(myrand) << endl;
			}
			else
			{
				cout << 6 << " " << dist(myrand) << endl;
			}
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}
