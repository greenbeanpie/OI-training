#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e5 + 5;
int h[N], n, max_dis[N];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1081.in", "r", stdin);
	freopen("P1081.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	
	return 0;
}