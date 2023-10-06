#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3369"
// #define const constexpr

const int N = 1e5 + 5;

namespace Main
{
	struct FHQ
	{
		int tot = 0;

		struct node
		{
			int val = 0, cnt = 0, size = 1;
			node *son[2] = {nullptr, nullptr}, *father = nullptr;
			node()
			{
				return;
			}
			node(int a, int b, int c)
			{
				val = a, cnt = b, size = c;
			}
			node(int a, int b, int c, node &d, node &e)
			{
				val = a, cnt = b, size = c;
				son[0] = &d, son[1] = &e;
			}
		};

		node *root;

		void maintain(node *u)
		{
			if (!u)
			{
				return;
			}
			u->size = (u->son[0] ? u->son[0]->size : 0) + (u->son[1] ? u->son[1]->size : 0) + u->cnt;
		}
		bool check(node *u)
		{
			return u->father && (u == (u->father->son[1]));
		}

		void not_rotate(node *x)
		{
			auto f1 = x->father, f2 = f1->father;
			auto r1 = check(x);
			if (x->son[r1 ^ 1])
			{
				x->son[r1 ^ 1]->father = f1;
				f1->son[r1] = x->son[r1 ^ 1];
			}
			f1->son[r1] = x->son[r1 ^ 1];
			x->son[r1 ^ 1] = f1;
			x->father = f2;
			f1->father = x;
			if (f2)
			{
				f2->son[f1 == f2->son[1]] = x;
			}
			maintain(f1), maintain(x);
		}
		void fhq(node *x)
		{ // emmm,function fhq.
			for (auto father = x->father; father = x->father, father; not_rotate(x))
			{
				if (father->father)
				{
					not_rotate(check(x) == check(father) ? father : x);
				}
			}
			root = x;
		}
		void insert(int val)
		{
			if (root)
			{
				auto cur = root;
				while (1)
				{
					if (cur->val == val)
					{
						++cur->cnt;
						maintain(cur);
						maintain(cur->father);
						fhq(cur);
						break;
					}
					// auto father = cur->father;
					if (cur->son[cur->val < val])
					{
						cur = cur->son[cur->val < val];
					}
					else
					{
						cur->son[cur->val < val] = new node;
						cur->son[cur->val < val]->val = val;
						++cur->son[cur->val < val]->cnt;
						cur->son[cur->val < val]->father = cur;
						maintain(cur);
						maintain(cur->son[cur->val < val]);
						fhq(cur->son[cur->val < val]);
						break;
					}
				}
			}
			else
			{
				root = new node;
				root->cnt = 1;
				root->size = 1;
				root->val = val;
				maintain(root);
			}
		}
		int rk(int k)
		{
			auto cur = root;
			int now = 0;
			while (1)
			{
				if (cur->son[0] && k < cur->val)
				{
					cur = cur->son[0];
				}
				else if (cur->son[1])
				{
					now += (cur->son[0] ? cur->son[0]->size : 0);
					if (k == cur->val)
					{
						fhq(cur);
						return now + 1;
					}
					now += cur->cnt;
					cur = cur->son[1];
				}
				else
				{
					now += (cur->son[0] ? cur->son[0]->size : 0);
					fhq(cur);
					return now + 1;
				}
			}
		}
		int kth(int k)
		{
			auto cur = root;
			while (1)
			{
				if (cur->son[0] && k <= cur->son[0]->size)
				{
					cur = cur->son[0];
				}
				else if (cur->son[1])
				{
					k -= cur->cnt + (cur->son[0]?cur->son[0]->size:0);
					if (k <= 0)
					{
						fhq(cur);
						return cur->val;
					}
					cur = cur->son[1];
				}
				else
				{
					fhq(cur);
					return cur->val;
				}
			}
		}
		node *pre(node *x)
		{
			auto cur = x->son[0];
			if (!cur)
			{
				return x;
			}
			while (cur->son[1])
			{
				cur = cur->son[1];
			}
			fhq(cur);
			return cur;
		}
		node *nxt(node *x)
		{
			auto cur = x->son[1];
			if (!cur)
			{
				return x;
			}
			while (cur->son[0])
			{
				cur = cur->son[0];
			}
			fhq(cur);
			return cur;
		}
		void del(int x)
		{
			rk(x);
			auto cur = root;
			if (cur->cnt > 1)
			{
				--cur->cnt;
				maintain(cur);
				return;
			}
			if (!cur->son[0] && !cur->son[1])
			{
				root = nullptr;
				return;
			}
			if (!cur->son[0])
			{
				root = cur->son[1];
				root->father = nullptr;
				return;
			}
			auto oldroot = root;
			node *x1 = pre(root);
			if (cur->son[1])
			{
				cur->son[1]->father = x1;
			}
			x1->son[1] = cur->son[1];
			delete oldroot;
			maintain(root);
		}
	} tree;

	int main()
	{
		int n;
		cin >> n;
		int opt, x;
		while (n--)
		{
			cin >> opt >> x;
			switch (opt)
			{
			case 1:
				tree.insert(x);
				break;
			case 2:
				tree.del(x);
				break;
			case 3:
				cout << tree.rk(x) << endl;
				break;
			case 4:
				cout << tree.kth(x) << endl;
				break;
			case 5:
				tree.insert(x);
				cout << tree.pre(tree.root)->val << endl;
				tree.del(x);
				break;
			case 6:
				tree.insert(x);
				cout << tree.nxt(tree.root)->val << endl;
				tree.del(x);
				break;
			}
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}