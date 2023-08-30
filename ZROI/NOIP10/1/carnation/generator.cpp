#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "carnation"
#define const constexpr

namespace Main
{

	random_device rd;
	sfmt216091_64 myrand(rd());
	struct node
	{
		int from, to, vala, valb;
	} e[650005];
	int main()
	{
		// int point = myrand() % 1000, idx = 0;
		int point = myrand() % 200 + 3, idx = 0;
		for (int i = 1; i < point; i++)
		{
			e[++idx] = {i, i + 1, abs((int)myrand()) % 1000, abs((int)myrand() % 1000)};
		}
		e[++idx] = {1, point, abs((int)myrand()) % 1000, abs((int)myrand()) % 1000};
		// int n = myrand() % 200000;
		int n = myrand() % 300000;
		cout << n << " ";
		while (point < n)
		{
			// int end = myrand() % (n - point + 2) + point + 2;
			// for (int i = point + 1; i < end; i++)
			// {
			// 	e[++idx] = {i, i + 1, abs((int)myrand()) % 1000, abs((int)myrand()) % 1000};
			// }
			// e[++idx] = {point,
			// 			abs((int)myrand())%(end-point)+1+point,
			// 			abs((int)myrand()) % 1000,
			// 			abs((int)myrand()) % 1000};
			// if (myrand() % 2)
			// {
			// 	e[++idx] = {point + 1,
			// 				end,
			// 				abs((int)myrand()) % 1000,
			// 				abs((int)myrand()) % 1000};
			// }
			// point = end;
			int start = myrand() % point + 1, circle_size = myrand() % 200 + 3, len_size = myrand() % 200 + 1;
			e[++idx] = {start,
						++point,
						abs((int)myrand()) % 1000,
						abs((int)myrand()) % 1000};
			for (int i = 2; i <= len_size; i++)
			{
				e[++idx] = {point,
							++point,
							abs((int)myrand()) % 1000,
							abs((int)myrand()) % 1000};
			}
			start=point;
			e[++idx] = { start,
						 ++point,
						 abs((int)myrand()) % 1000,
						 abs((int)myrand()) % 1000};
			for (int i = 2; i <= circle_size;i++){
				e[++idx] = {point,
							++point,
							abs((int)myrand()) % 1000,
							abs((int)myrand()) % 1000};
			}
			e[++idx] = {point,
						start,
						abs((int)myrand()) % 1000,
						abs((int)myrand()) % 1000};
		}
		cout << idx << endl;
		shuffle(e + 1, e + 1 + idx, myrand);
		for (int i = 1; i <= idx; i++)
		{
			if (myrand() % 2)
			{
				swap(e[i].from, e[i].to);
			}
			cout << e[i].from << " " << e[i].to << " " << e[i].vala << " " << e[i].valb << endl;
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