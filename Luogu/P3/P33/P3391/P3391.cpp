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
#define const constexpr

const int N = 1e5 + 5;

namespace Main
{
	struct FHQ
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
				swap(x->son[0], x->son[1]);
				x->tag = 0;
				if (x->son[0])
				{
					x->son[0]->tag ^= 1;
				}
				if (x->son[1])
				{
					x->son[1]->tag ^= 1;
				}
			}
		}
		bool check(node *u)
		{
			return u->father && (u == (u->father->son[1]));
		}

		void not_rotate(node *x)
		{ // Of course FHQ doesn't need rotate(
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
		void fhq(node *x, node *to)
		{ // emmm,function fhq.
			for (auto father = x->father; father = x->father, father != to; not_rotate(x))
			{
				if (father->father != to)
				{
					not_rotate(check(x) == check(father) ? father : x);
				}
			}
			if (to->val == 0)
			{
				root = x;
			}
		}
		node *find(int val)
		{
			auto cur = root;
			while (cur->val != val)
			{
				cur = cur->son[cur->val < val];
			}
			return cur;
		}
		void reverse(int l, int r)
		{
			auto left = find(l), right = find(r);
			fhq(left, root);
			fhq(right, left);
			root->son[1]->son[0]->tag ^= 1;
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
			cout << now->val << " ";
			if (now->son[1])
			{
				dfs(now->son[1]);
			}
		}
	} tree;

	int main()
	{
		int n;
		cin >> n;
		tree.createroot();
		tree.build(1, n, tree.root);
		int m;
		cin >> m;
		int x, y;
		for (int i = 1; i <= m; i++)
		{
			cin >> x >> y;
			tree.reverse(x, y);
		}
		dfs(tree.root->son[1]);
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