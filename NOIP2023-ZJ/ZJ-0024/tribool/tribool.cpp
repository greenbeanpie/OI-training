#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ssz(x) (int((x).size()))

auto chmin = [](auto& x, auto y) { if (x > y) x = y; };
auto chmax = [](auto& x, auto y) { if (x < y) x = y; };

using ll = long long;
const int max_n = 1e5;

int cv[max_n]; // U = 0 T = n + 1, inv
int dsu[max_n], val[max_n], ty[max_n];
bool ok[max_n];

pair<int, int> fnd(int x)
{
	if (x == dsu[x])
		return { x, 0 };
	auto [t, v] = fnd(dsu[x]);
	dsu[x] = t, val[x] ^= v;
	return { t, val[x] };
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);  
	
	int cid, cas, n, m;
	
	cin >> cid >> cas;
	while (cas--)
	{
		cin >> n >> m;
		iota(cv, cv + n, 1);
		iota(dsu, dsu + n, 0);
		fill(ok, ok + n, 1);
		fill(val, val + n, 0);
		fill(ty, ty + n, -1);
		
		char opt;
		for (int i = 0, x, y; i < m; i++)
		{
			cin >> opt;
			if (opt == '+' || opt == '-')
			{
				cin >> x >> y, x--, y--;
				cv[x] = cv[y] * (opt == '+' ? 1 : -1);
			}
			else
			{
				cin >> x, x--;
				cv[x] = (opt == 'U' ? 0 : (n + 1) * (opt == 'T' ? 1 : -1));
			}
		}
		for (int i = 0; i < n; i++) // x connects with cv[x]
		{
			// cerr << i << " " << cv[i] << endl;
			if (cv[i] == 0)
				ok[i] = 0;
			else if (cv[i] == n + 1 || cv[i] == -n - 1)
				ty[i] = (cv[i] == n + 1);
			else
			{
				auto [xt, xv] = fnd(abs(cv[i]) - 1);
				bool epv = xv ^ (cv[i] < 0);
				// cerr << xt << " " << i << " " << xv << " " << (cv[i] < 0) << endl;
				if (xt != i)
					dsu[i] = xt, val[i] = epv;
				else if (epv)
				{
					ok[xt] = 0;
					// cerr << "gank " << xt << endl;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += !ok[fnd(i).first];
		cout << ans << endl;
	}
	
	return 0;
}