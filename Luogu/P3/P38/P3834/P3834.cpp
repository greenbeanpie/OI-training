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
struct SegTree
{
	struct node
	{
		T lr = 0, rr = 0, ls = -1, rs = -1, val = 0;
	};
	vector<node> tree;
	vector<T> *arr;
	vector<int> his;
	int n;

	SegTree(vector<T> *a)
	{
		arr = a;
	}
	inline int point_add(T val, T pos, int p)
	{
		if (tree[p].lr == tree[p].rr)
		{
			node now = tree[p];
			now.val++;
			tree.push_back(now);
			return tree.size() - 1;
		}
		node now = tree[p];
		if (tree[tree[p].ls].rr >= pos)
		{
			now.ls = point_add(val, pos, tree[p].ls);
		}
		else
		{
			now.rs = point_add(val, pos, tree[p].rs);
		}
		now.val++;
		tree.push_back(now);
		return tree.size() - 1;
	}
	inline int build(int l, int r)
	{
		int mid = (l + r) / 2;
		node now;
		now.lr = l;
		now.rr = r;
		now.val = 0;
		if (l != r)
		{
			now.ls = build(l, mid);
			now.rs = build(mid + 1, r);
		}
		tree.push_back(now);
		return tree.size() - 1;
	}
	inline int query(int cl, int cr, int rank, int lp, int rp)
	{
		if (tree[lp].lr == tree[lp].rr)
		{
			return tree[lp].lr;
		}
		int lval = tree[tree[rp].ls].val - tree[tree[lp].ls].val, rval = tree[tree[rp].rs].val - tree[tree[lp].rs].val;
		if (cl + lval-1 >= rank)
		{
			return query(cl, cl + lval-1, rank, tree[lp].ls, tree[rp].ls);
		}
		else
		{
			return query(cl + lval, cr, rank, tree[lp].rs, tree[rp].rs);
		}
	}
};

template <typename T>
inline void build(SegTree<T> *st)
{
	st->his.push_back(st->build(1, tot));
	for (auto i = st->arr->begin(); i != st->arr->end(); i++)
	{
		st->his.push_back(st->point_add(1, *i, *(st->his.rbegin())));
	}
}
template <typename T>
inline int query(SegTree<T> *st, int l, int r, int pos)
{
	return st->query(1, st->tree[st->his[r]].val - st->tree[st->his[l - 1]].val, pos, st->his[l-1], st->his[r]);
}
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
	tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> s;
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
	SegTree<int> st(&num);
	build(&st);
	int l, r, k;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r >> k;
		cout << *s.find_by_order(query(&st,l,r,k)-1) << std::endl;
	}
	return 0;
}