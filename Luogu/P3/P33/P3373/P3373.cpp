#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int P;

template <typename T>
struct Segtree
{
	struct node
	{
		int l, r;
		T val, lazy_add, lazy_mul;
		node *son[2];
		node()
		{
			l = r = val = lazy_add = 0;
			lazy_mul = 1;
			son[0] = son[1] = nullptr;
		}
	};

	node *root;

	vector<T> *arr;

	Segtree(vector<T> &a)
	{
		arr = &a;
	}

	void build(int l, int r, node *p)
	{
		p->l = l, p->r = r;
		if (l == r)
		{
			p->val = arr->at(l);
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, p->son[0] = new node);
		build(mid + 1, r, p->son[1] = new node);
		p->val = p->son[0]->val + p->son[1]->val;
		p->val %= P;
	}
	void build()
	{
		return build(1, arr->size() - 1, root = new node);
	}
	void maintain(node *p)
	{
		// if (p->son[0])
		// {
		if (p->lazy_mul)
		{
			p->son[0]->lazy_mul *= p->lazy_mul;
			p->son[0]->lazy_mul %= P;
			p->son[0]->lazy_add *= p->lazy_mul;
			p->son[0]->lazy_add %= P;
			p->son[0]->val *= p->lazy_mul;
			p->son[0]->val %= P;
			p->son[1]->lazy_mul *= p->lazy_mul;
			p->son[1]->lazy_mul %= P;
			p->son[1]->lazy_add *= p->lazy_mul;
			p->son[1]->lazy_add %= P;
			p->son[1]->val *= p->lazy_mul;
			p->son[1]->val %= P;
			// p->lazy_add *= p->lazy_mul;
			p->lazy_mul = 1;
		}
		if (p->lazy_add)
		{
			p->son[0]->lazy_add += p->lazy_add;
			p->son[0]->lazy_add %= P;
			p->son[1]->lazy_add += p->lazy_add;
			p->son[1]->lazy_add %= P;
			p->son[0]->val += (p->son[0]->r - p->son[0]->l + 1) * p->lazy_add;
			p->son[0]->val %= P;
			p->son[1]->val += (p->son[1]->r - p->son[1]->l + 1) * p->lazy_add;
			p->son[1]->val %= P;
			p->lazy_add = 0;
		}
		// p->son[0]->lazy_mul *= p->lazy_mul;
		// p->son[0]->lazy_mul %= P;
		// p->son[1]->lazy_mul *= p->lazy_mul;
		// p->son[1]->lazy_mul %= P;
		// p->son[0]->lazy_add *= p->lazy_mul;
		// p->son[0]->lazy_add += p->lazy_add;
		// p->son[0]->lazy_add %= P;

		// }
	}
	void update(node *p)
	{
		p->val = p->son[0]->val + p->son[1]->val;
		p->val %= P;
	}
	void add(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_add += val;
			p->val += (p->r - p->l + 1) * val;
			p->lazy_add %= P;
			p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			add(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			add(l, r, val, p->son[1]);
		}
		update(p);
	}
	void add(int l, int r, int val)
	{
		return add(l, r, val, root);
	}
	void mul(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_mul *= val;
			p->lazy_add *= val;
			p->val *= val;
			p->lazy_mul %= P;
			p->lazy_add %= P;
			p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			mul(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			mul(l, r, val, p->son[1]);
		}
		update(p);
	}
	// inline void mul(int l, int r, T val, node *p)
	// {
	// 	int cl = p->l, cr = p->r;
	// 	if (l <= cl && cr <= r)
	// 	{
	// 		p->val *= val;
	// 		p->lazy_add *= val;
	// 		p->lazy_mul *= val;
	// 		return;
	// 	}
	// 	int mid = (cl + cr) / 2;
	// 	// maintain(cl, cr, p);
	// 	maintain(p);
	// 	if (l <= mid)
	// 	{
	// 		mul(l, r, val, p->son[0]);
	// 	}
	// 	if (r > mid)
	// 	{
	// 		mul(l, r, val, p->son[1]);
	// 	}
	// 	update(p);
	// }
	void mul(int l, int r, T val)
	{
		return mul(l, r, val, root);
	}
	int query(int l, int r, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			return p->val;
		}
		maintain(p);
		int res = 0;
		if (p->son[0]->r >= l)
		{
			res += query(l, r, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			res += query(l, r, p->son[1]);
		}
		return res % P;
	}
	int query(int l, int r)
	{
		return query(l, r, root);
	}
};

vector<int> num = vector<int>(1);

Segtree<int> Tree(num);

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P3373.in", "r", stdin);
	freopen("P3373.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m >> P;
	for (int i = 1, tmp; i <= n; i++)
	{
		cin >> tmp;
		num.emplace_back(tmp);
	}
	Tree.build();
	for (int i = 1, op, x, y, z; i <= m; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> z;
			Tree.mul(x, y, z);
		}
		else if (op == 2)
		{
			cin >> x >> y >> z;
			Tree.add(x, y, z);
		}
		else
		{
			cin >> x >> y;
			cout << Tree.query(x, y) << endl;
		}
	}
	return 0;
}