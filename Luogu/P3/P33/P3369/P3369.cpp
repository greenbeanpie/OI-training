#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> bt;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3369.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int T;
	std::cin >> T;
	int tot = 0;
	while (T--)
	{
		int op, num;
		std::cin >> op >> num;
		switch (op)
		{
		case 1:
			bt.insert({num, tot++});
			break;
		case 2:
			bt.erase(bt.lower_bound({num, -1}));
			break;
		case 3:
			std::cout << bt.order_of_key({num, -1})+1 << "\n";
			break;
		case 4:
			std::cout << (*bt.find_by_order(num-1)).first << "\n";
			break;
		case 5:
			std::cout << (*(--bt.lower_bound({num, -1}))).first << "\n";
			break;
		case 6:
			std::cout << (*bt.upper_bound({num, INT_MAX})).first << "\n";
			break;
		}
	}
	return 0;
}