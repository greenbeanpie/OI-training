#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define cin std::cin
#define cout std::cout
#define int long long
#define Pii std::pair<long long, long long>

tree<Pii, null_type, std::less<Pii>, rb_tree_tag, tree_order_statistics_node_update> bt;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, min;
	cin >> n >> min;
	int add = 0, tot = 1;
	char c;
	int num;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> num;
		num -= add;
		if (c == 'I' && num + add >= min)
		{
			bt.insert({num, tot++});
		}
		else if (c == 'A')
		{
			add += num;
		}
		else if (c == 'S')
		{
			add -= num;
			while (bt.size() && (*bt.begin()).first + add < min)
			{
				bt.erase(bt.begin());
			}
		}
		else
		{
			if (num > bt.size())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << (*bt.find_by_order(num)).first << "\n";
			}
		}
	}
	return 0;
}