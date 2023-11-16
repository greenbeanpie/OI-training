#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

// __gnu_pbds::priority_queue<int, greater<int>> pq;

struct PSegtree
{
	struct node
	{
		int val, cl, cr;
		node *son[2];
		node()
		{
			val = 0, cl = cr = -1;
			son[0] = son[1] = nullptr;
		}
		node(int a) { val = a; }
		node(int a, int b)
		{
			cl = a, cr = b;
		}
		node(int a, int b, int c)
		{
			cl = a, cr = b, val = c;
		}
	};
	vector<node *> root;
	void build(int cl, int cr, node *p)
	{
		p->cl = cl, p->cr = cr;
		if (cl == cr)
		{
			return;
		}
		int mid = (cl + cr) >> 1;
		build(cl, mid, p->son[0] = new node);
		build(mid + 1, cr, p->son[1] = new node);
		return;
	}
	void build(int n)
	{
		root.emplace_back(new node);
		return build(1, n, root.at(0));
	}
	void add(node *o, node *p, int pos, int val = 1)
	{ // Do you play Genshin Impact?
		*p = *o;
		p->val += val;
		if (p->cl == p->cr)
		{
			return;
		}
		if (p->son[0]->cr >= pos)
		{
			add(o->son[0], p->son[0] = new node, pos, val);
		}
		else
		{
			add(o->son[1], p->son[1] = new node, pos, val);
		}
	}
	void add(int pos, int val = 1)
	{
		root.emplace_back(new node);
		return add(root.at(root.size() - 2), root.at(root.size() - 1), pos, val);
	}
	void modify(int pos, int val, node *p = nullptr)
	{
		p->val += val;
		if (p->cl == p->cr)
		{
			return;
		}
		if (p->son[0]->cr >= pos)
		{
			return modify(pos, val, p->son[0]);
		}
		else
		{
			return modify(pos, val, p->son[1]);
		}
	}
	void modify(int pos, int val = -1)
	{
		return modify(pos, val, root.at(root.size() - 1));
	}
	int query_max(node *o, node *p)
	{ // No! God! Please! No!
		if (p->val - o->val == 0)
		{
			return 0;
		}
		else if (p->cl == p->cr)
		{
			return p->cl;
		}
		else if (p->son[1]->val - o->son[1]->val > 0)
		{
			return query_max(o->son[1], p->son[1]);
		}
		else
		{
			return query_max(o->son[0], p->son[0]);
		}
	}
	int query_max(int l, int r)
	{
		return query_max(root.at(l), root.at(r));
	}
} PSTree;

const int N = 3e5 + 5;

int pos[N];

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	PSTree.build(n);
	for (int i = 1, temp; i <= n; i++)
	{
		cin >> temp;
		PSTree.add(temp);
		pos[temp] = i;
	}
	for (int i = 1, temp; i <= n; i++)
	{
		cin >> temp;
		cout << PSTree.query_max(0, n) << " ";
		auto res = PSTree.query_max(0, pos[temp]);
		if (!res)
		{
			res = PSTree.query_max(0, n);
		}
		PSTree.modify(res);
	}
	return 0;
}
