#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "UVA11922"
#define const constexpr

const int N = 1e6 + 5;

namespace Main
{
	int n;
	struct Splay
	{
		int tot = 0;

		struct node
		{
			int val = 0, cnt = 0, size = 1;
			bool tag = 0;
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
		void pushdown(node *x)
		{
			if (x && x->tag)
			{
				if (x->son[1])
				{
					x->son[1]->tag ^= 1;
				}
				if (x->son[0])
				{
					x->son[0]->tag ^= 1;
				}
				swap(x->son[0], x->son[1]);
				x->tag = 0;
			}
		}
		bool check(node *u)
		{
			return u->father && (u == (u->father->son[1]));
		}

		void rotate(node *x)
		{
			auto f1 = x->father, f2 = f1->father;
			pushdown(x), pushdown(f1);
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
		void splay(node *x, node *to)
		{
			if (!x)
			{
				return;
			}
			for (auto father = x->father; father = x->father, father != to; rotate(x))
			{
				pushdown(x);
				if (father->father != to)
				{
					rotate(check(x) == check(father) ? father : x);
				}
			}
			if (!to)
			{
				root = x;
			}
		}
		node *find(int val)
		{
			if (val < 1 || val > n)
			{
				return nullptr;
			}
			auto cur = root;
			while (val)
			{
				pushdown(cur);
				if (cur->son[0] && val <= cur->son[0]->size)
				{
					cur = cur->son[0];
				}
				else
				{
					val -= (cur->son[0] ? cur->son[0]->size : 0) + cur->cnt;
					if (!val)
					{
						return cur;
					}
					cur = cur->son[1];
				}
			}
			return cur;
		}
		void reverse(int l, int r)
		{
			// ++r;
			auto left = find(l - 1), right = find(r + 1);
			splay(left, nullptr);
			splay(right, left);
			if (l == 1 && r == n)
			{
				root->tag ^= 1;
			}
			else if (r == n )
			{
				root->son[1]->tag ^= 1;
			}
			else
			{
				auto temp = root;
				if (l == 1)
				{
					temp = root->son[0];
					root->son[0] = nullptr;
					maintain(root);
				}
				else
				{
					temp = root->son[1]->son[0];
					root->son[1]->son[0] = nullptr;
					maintain(root->son[1]);
					maintain(root);
				}
				temp->tag ^= 1;
				splay(find(root->size), nullptr);
				root->son[1] = temp;
				temp->father = root;
				maintain(root);
			}
		}
		node *build(int l, int r, node *fa)
		{
			if (l > r)
			{
				return nullptr;
			}
			int mid = (l + r) >> 1;
			auto now = new node;
			now->val = mid;
			now->father = fa;
			++now->cnt;
			now->son[0] = build(l, mid - 1, now);
			now->son[1] = build(mid + 1, r, now);
			maintain(now);
			return now;
		}
		void createroot()
		{
			root = new node;
			root->cnt = 1;
			root->father = nullptr;
			root->size = 1;
			root->tag = 0;
			root->val = 0;
		}
		void dfs(node *now)
		{
			pushdown(now);
			if (now->son[0])
			{
				dfs(now->son[0]);
			}
			if (now->val <= 1e9 && now->val >= -1e9)
			{
				cout << now->val << endl;
			}
			if (now->son[1])
			{
				dfs(now->son[1]);
			}
		}
	} tree;
	int main()
	{
		cin >> n;
		// tree.createroot();

		tree.root = tree.build(1, n, nullptr);
		int m;
		cin >> m;
		int x, y;
		for (int i = 1; i <= m; i++)
		{
			cin >> x >> y;
			tree.reverse(x, y);
			// tree.dfs(tree.root);
			// cout << endl;
		}
		tree.dfs(tree.root);
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