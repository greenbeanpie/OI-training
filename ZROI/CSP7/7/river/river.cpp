#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#pragma GCC optimize(2)

struct Segtree
{
	struct node
	{
		int cl, cr, val;
		node *son[2];
		node()
		{
			cl = cr = val = 0;
			son[0] = son[1] = nullptr;
		}
		node(int pos, int v)
		{
			cl = cr = pos;
			val = v;
		}
		node(int l, int r, int v, node *lson, node *rson)
		{
			cl = l, cr = r, val = v, son[0] = lson, son[1] = rson;
		}
	};

	node *root = nullptr;
	int *cnt;

	node *build_tree(int cl, int cr, node *p)
	{
		p->cl = cl, p->cr = cr;
		if (cl == cr)
		{
			// p->val = cnt[cl];
			return p;
		}
		int mid = (cl + cr) >> 1;
		p->son[0] = build_tree(cl, mid, new node);
		p->son[1] = build_tree(mid + 1, cr, new node);
		// p->val = p->son[0]->val + p->son[1]->val;
		return p;
	}
	void build_tree(int n)
	{
		build_tree(1, n, (root = new node));
		return;
	}

	void add(int pos, int val, node *p)
	{
		p->val += val;
		if (p->cl == p->cr)
		{
			return;
		}
		if (p->son[0]->cr >= pos)
		{
			return add(pos, val, p->son[0]);
		}
		else
		{
			return add(pos, val, p->son[1]);
		}
	}
	void add(int pos, int val)
	{
		return add(pos, val, root);
	}

	int query(int l, int r, node *p)
	{
		if (l > r)
		{
			return 0;
		}
		if (l <= p->cl && p->cr <= r)
		{
			return p->val;
		}
		int res = 0;
		if (p->son[0]->cr >= l)
		{
			res += query(l, r, p->son[0]);
		}
		if (p->son[1]->cl <= r)
		{
			res += query(l, r, p->son[1]);
		}
		return res;
	}

	int query(int l, int r)
	{
		return query(l, r, root);
	}
	Segtree()
	{
		return;
	}
	Segtree(int *cnt)
	{
		this->cnt = cnt;
	}
};

namespace Main
{
	constexpr int N = 5e5 + 5, mod = 998244353;
	int temp[N], cnt[N], res, ans;
	list<int> num;
	bool rv = 0;
	Segtree Tree(cnt);

	int quickpower(int a, int b, int p = mod)
	{
		int ans = 1, base = a;
		while (b)
		{
			if (b & 1)
			{
				ans *= base;
				ans %= p;
			}
			b >>= 1;
			base *= base;
			base %= p;
		}
		return ans;
	}

	int main()
	{
		int n, q;
		cin >> n >> q;
		for (int i = 1, tmp; i <= n; i++)
		{
			cin >> tmp;
			num.push_back(tmp);
			temp[i] = tmp;
		}
		sort(temp + 1, temp + 1 + n);
		int siz = unique(temp + 1, temp + 1 + n) - temp - 1;
		for (auto i = num.begin(); i != num.end();i++)
		{
			*i = lower_bound(temp + 1, temp + 1 + siz, *i) - temp;
			++cnt[*i];
		}
		Tree.build_tree(siz);
		for (int i : num)
		{
			res += Tree.query(i + 1, siz);
			Tree.add(i, 1);
		}
		char op;
		for (int i = 1; i <= q; i++)
		{
			cin >> op;
			if (op == '0')
			{
				int tmp;
				if (!rv)
				{
					tmp = num.front();
					num.pop_front();
					num.push_back(tmp);
				}
				else
				{
					tmp = num.back();
					num.pop_back();
					num.push_front(tmp);
				}
				res -= Tree.query(1, tmp - 1);
				res += Tree.query(tmp + 1, siz);
			}
			else
			{
				rv = !rv;
				res = n * (n - 1) / 2 - res;
			}
			ans += res % mod * quickpower(233, q - i) % mod;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
#endif
	Main::main();
	return 0;
}
