#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define cin std::cin
#define cout std::cout
tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> bt;

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("E.in", "r", stdin);
#endif
	int n, q, tot = 1;
	cin >> n >> q;
	int sal[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> sal[i];
		bt.insert({sal[i], tot++});
	}
	int a, b;
	char c;
	while (q--)
	{
		cin >> c >> a >> b;
		if (c == '!')
		{
			bt.erase(bt.lower_bound({sal[a], -1}));
			sal[a] = b;
			bt.insert({b, tot++});
		}
		else
		{
			cout << bt.order_of_key({b+1, -1}) -  bt.order_of_key({a, -1}) << " ";
		}
	}
	return 0;
}