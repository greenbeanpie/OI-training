#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define vector std::vector
#define cin std::cin
#define cout std::cout
vector<int> num;
int n, tot = 0;

template <typename T>


SegTree<int> st(&num);

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3834.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cc_hash_table<int, int> ht;
	int n, m;
	cin >> n >> m;
	tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.insert(t);
		num.push_back(t);
	}
	for (int i : s)
	{
		ht[i] = ++tot;
	}
	for (auto i = num.begin(); i != num.end(); i++)
	{
		(*i) = ht[*i];
	}

	st.build();
	int l, r, k;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r >> k;
		cout << *s.find_by_order(st.query(l, r, k) - 1) << std::endl;
	}
	return 0;
}