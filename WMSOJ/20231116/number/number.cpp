#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#pragma GCC target("tune=native")
#define int long long
#define Pii pair<__float128, int>

tree<Pii, null_type, less<Pii>, rb_tree_tag, tree_order_statistics_node_update> posi, nega;
int cnt1;

random_device rd;
sfmt19937_64 myrand(rd());

const int N = 1e6 + 5;
int num[N];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	int res = 0, cntn = 0, cnt0 = 0, cnt1 = 0, cntp = 0;
	for (int i = n; i >= 1; i--)
	{
		if (num[i] < 0)
		{
			
			res += cnt1 + cntp;
			++cntn;
		}
		else if (num[i] == 0)
		{
			
			res += cnt1 + cntp;
			++cnt0;
		}
		else if (num[i] == 1)
		{
			res += cnt1 + cnt0 + cntp + cntn;
			++cnt1;
		}
		else
		{
			
			res += cnt1 + cnt0 + cntn;
			++cntp;
		}
	}
	cout << res << endl;
	return 0;
}