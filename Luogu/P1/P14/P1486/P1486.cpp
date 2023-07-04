#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define cin std::cin
#define cout std::cout
#define int long long
#define Pii std::pair<long long, long long>

tree<Pii, null_type, std::greater<Pii>, rb_tree_tag, tree_order_statistics_node_update> bt,btt;
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("P1486.in","r",stdin);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, min;
	cin >> n >> min;
	int add = 0, tot = 1;
	char c;
	int num;
	int leave=0;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> num;
		
		if (c == 'I'&& num>=min)
		{
			num -= add;
			bt.insert({num, tot++});
		}
		else if (c == 'A')
		{
			add += num;
		}
		else if (c == 'S')
		{
			add -= num;
			bt.split({min-add,-1},btt);
			leave+=btt.size();
		}
		else if(c=='F')
		{
			if (num > bt.size())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << (*bt.find_by_order(num-1)).first+add << "\n";
			}
		}
	}
	cout << leave;
	return 0;
}