#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long

const int N = 1e5 + 5;

int ori[N], num[N];

// struct Segtree
// {
// 	int tot = 0;
// 	int val[N << 2];
// 	int query(int cl, int cr, int l, int r, int p)
// 	{
// 		if (l <= cl && cr <= r)
// 		{
// 			return val[p];
// 		}
// 		int mid = (cl + cr) >> 1;
// 		int res = 0;
// 		if (l <= mid)
// 		{
// 			res += query(cl, mid, l, r, p << 1);
// 		}
// 		if (r > mid)
// 		{
// 			res += query(mid + 1, cr, l, r, (p << 1) | 1);
// 		}
// 		return res;
// 	}
// 	int query(int l, int r)
// 	{
// 		return query(1, tot, l, r, 1);
// 	}
// 	void build(int cl, int cr, int p)
// 	{
// 		if (cl == cr)
// 		{
// 			val[p] = num[cl];
// 			return;
// 		}
// 		int mid = (cl + cr) >> 1;
// 		build(cl, mid, p << 1);
// 		build(mid + 1, cr, (mid << 1) | 1);
// 		val[p] = val[p << 1] + val[(p << 1) | 1];
// 		return;
// 	}
// 	void build(int n)
// 	{
// 		tot = n;
// 		return build(1, n, 1);
// 	}
// };

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> Tree;

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	int tot;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ori[i];
	}
	for (int i = 1, temp; i <= m; i++)
	{
		tot = 0;
		Tree.clear();
		cin >> temp;
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res += Tree.size()-Tree.order_of_key({ori[i] ^ temp, -1});
			Tree.insert({ori[i] ^ temp, ++tot});
		}
		cout << res << endl;
	}
	return 0;
}