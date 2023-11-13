#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

static const int N = 5e5 + 5;

struct Segtree
{

	struct node
	{
		int ls, rs, val, cl, cr;
	} tree[N << 5];

	int tot = 0;
	vector<int> root;

	void build_tree(int l, int r, int p)
	{
		tree[p].ls = tree[p].rs = tree[p].val = 0;
		tree[p].cl = l, tree[p].cr = r;
		if (l == r)
		{
			return;
		}
		int mid = (l + r) >> 1;
		// tree[tree[p].cl].cl = l;
		// tree[tree[p].cl].cr = mid;
		build_tree(l, mid, tree[p].ls = ++tot);
		tree[p].rs = ++tot;
		build_tree(mid + 1, r, tot);
		return;
	}
	void build_tree(int n)
	{
		tot = 0;
		root.clear();
		root.emplace_back(1);
		return build_tree(1, n, ++tot);
	}

	void add(int pos, int ori, int p)
	{
		tree[p] = tree[ori];
		++tree[p].val;
		if (tree[p].cl == tree[p].cr)
		{
			return;
		}
		int mid = (tree[p].cl + tree[p].cr) >> 1;
		if (mid >= pos)
		{
			add(pos, tree[ori].ls, tree[p].ls = ++tot);
		}
		else
		{
			add(pos, tree[ori].rs, tree[p].rs = ++tot);
		}
	}
	void add(int pos)
	{
		root.emplace_back(tot + 1);
		add(pos, *++root.rbegin(), ++tot);
		return;
	}
	int query(pair<int, int> range, int o, int p)
	{
		int l = range.first, r = range.second;
		if (l <= tree[p].cl && tree[p].cr <= r)
		{
			return tree[p].val - tree[o].val;
		}
		int mid = (tree[p].cl + tree[p].cr) >> 1, res = 0;
		if (l <= mid)
		{
			res += query(range, tree[o].ls, tree[p].ls);
		}
		if (r > mid)
		{
			res += query(range, tree[o].rs, tree[p].rs);
		}
		return res;
	}
	int query(int v1, int v2, int l, int r)
	{
		if (v1 > v2 || l > r)
		{
			return 0;
		}
		return query({l, r}, root[v1], root[v2]);
	}
} PStree;