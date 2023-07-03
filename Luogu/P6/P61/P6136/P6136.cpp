#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> bt;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P6136.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int n,T;
	int tot = 0, last = 0,ans=0;
	std::cin >> n >> T;
	while(n--){
		int t;
		std::cin >> t;
		bt.insert({t,tot++});
	}
	
	while (T--)
	{
		int op, num;
		std::cin >> op >> num;
		num ^= last;
		switch (op)
		{
		case 1:
			bt.insert({num, tot++});
			break;
		case 2:
			bt.erase(bt.lower_bound({num, -1}));
			break;
		case 3:
			last=bt.order_of_key({num, -1}) + 1;
			ans^=last;
			break;
		case 4:
			last = (*bt.find_by_order(std::min((int)bt.size() - 1, num - 1))).first;
			ans^=last;
			break;
		case 5:
			last = (*(--bt.lower_bound({num, -1}))).first;
			ans^=last;
			break;
		case 6:
			last=(*bt.upper_bound({num, INT_MAX})).first;
			ans^=last;
			break;
		}
	}
	std::cout << ans;
	return 0;
}