#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "escape"
#define const constexpr

namespace Main
{

	const int N = 1e5 + 5;
	struct node
	{
		int pos, to, topos, val;
		node(int a,int b,int c,int d){
			pos = a, to = b, topos = c, val = d;
		}
	};
	vector<node> line[N];
	int val[N], minans = LLONG_MAX;
	int n, m, k;
	void dfs(int x, int y, int rp)
	{
		if(x==n){
			minans = min(minans, rp + abs(m - y) * val[x]);
			return;
		}
		for(auto i:line[x]){
			dfs(i.to, i.topos, rp+(abs(i.pos - y) * val[x]) - i.val);
		}
	}
	int main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			minans = LLONG_MAX;
			
			cin >> n >> m >> k;
			if (k == 0)
			{
				if (n == 1)
				{
					cout << m - 1 << endl;
				}
				else
				{
					cout << "NO ESCAPE" << endl;
				}
			}
			for (int i = 1; i <= n; i++)
			{
				line[i].clear();
			}
			for (int i = 1; i <= n; i++)
			{
				cin >> val[i];
			}
			int a, b, c, d, h;
			for (int i = 1; i <= k; i++)
			{
				cin >> a >> b >> c >> d >> h;
				line[a].emplace_back(b, c, d, h);
			}
			dfs(1, 1,0);
			if(minans>=INT_MAX){
				cout << "NO ESCAPE" << endl;
				continue;
			}
			cout << minans << endl;
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