#include <iostream>
#include <cstdio>

int n, m;

inline int read()
{
	register int x = 0, v = 1;
	register char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			v = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * v;
}

namespace Splay
{
	struct Tree
	{
		struct Splay
		{
			int val, size;
			bool rev;
			Splay *ch[2], *father;
			Splay() {}
			Splay(int _val, Splay *parent) : val(_val), rev(0), size(1), father(parent) { ch[0] = ch[1] = NULL; }
		} *root;
		inline int size(Splay *o) { return o == NULL ? 0 : o->size; }
		inline void pushup(Splay *o) { o->size = size(o->ch[0]) + size(o->ch[1]) + 1; }
		inline void pushdown(Splay *o)
		{
			if (o->rev)
			{
				if (o->ch[0])
					o->ch[0]->rev ^= 1;
				if (o->ch[1])
					o->ch[1]->rev ^= 1;
				std::swap(o->ch[0], o->ch[1]);
				o->rev = 0;
			}
		}
		inline int relation(Splay *o) { return o->father ? o->father->ch[1] == o : 0; }
		inline void connect(Splay *x, Splay *y, int relation)
		{
			if (x)
				x->father = y;
			if (y)
				y->ch[relation] = x;
		}
		inline void rotate(Splay *o)
		{
			Splay *p = o->father, *q = p->father;
			int wson = relation(o);
			connect(o, q, relation(p));
			connect(o->ch[wson ^ 1], p, wson);
			connect(p, o, wson ^ 1);
			pushup(p);
			pushup(o);
		}
		inline void splay(Splay *o, Splay *goal)
		{
			if (o == NULL)
				return;
			while (o->father != goal)
			{
				Splay *p = o->father, *q = p->father;
				if (q != goal)
					relation(o) ^ relation(p) ? rotate(o) : rotate(p);
				rotate(o);
			}
			if (goal == NULL)
				root = o;
		}
		inline Splay *kth(int k)
		{
			if (k < 1 || k > n)
				return NULL;
			Splay *o = root;
			while (1)
			{
				pushdown(o);
				if (size(o->ch[0]) + 1 == k)
					return o;
				else if (size(o->ch[0]) >= k)
					o = o->ch[0];
				else
				{
					k -= size(o->ch[0]) + 1;
					o = o->ch[1];
				}
			}
			return NULL;
		}
		void build(Splay *&o, Splay *fa = NULL, int l = 1, int r = n)
		{
			// printf("l=%d r=%d\n", l, r);
			if (l > r)
				return;
			int mid = (l + r) >> 1;
			o = new Splay(mid, fa);
			build(o->ch[0], o, l, mid - 1);
			build(o->ch[1], o, mid + 1, r);
			pushup(o);
		}
		void out(Splay *o)
		{
			if (!o)
				return;
			pushdown(o);
			out(o->ch[0]);
			printf("%d\n", o->val);
			out(o->ch[1]);
		}
		inline void reverseS(int l, int r)
		{
			Splay *o1 = kth(l - 1), *o2 = kth(r + 1);
			splay(o1, NULL);
			splay(o2, o1);
			if (l == 1 && r == n)
			{
				root->rev ^= 1;
			}
			else if (l == 1)
			{
				Splay *nowP = root->ch[0];
				nowP->rev ^= 1;
				root->ch[0] = NULL;
				pushup(root);
				splay(kth(size(root)), NULL);
				// root -> ch[1] = nowP;
				connect(nowP, root, 1);
				pushup(root);
			}
			else if (r == n)
			{
				root->ch[1]->rev ^= 1;
			}
			else
			{
				Splay *nowP = root->ch[1]->ch[0];
				// printf("val=%d %d\n", root -> val, root -> ch[1] -> val);
				nowP->rev ^= 1;
				root->ch[1]->ch[0] = NULL;
				pushup(root->ch[1]);
				pushup(root);
				splay(kth(size(root)), NULL);
				// root -> ch[1] = nowP;
				connect(nowP, root, 1);
				pushup(root);
			}
		}
	} tree;
}

using namespace Splay;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("UVA11922.in", "r", stdin);
	freopen("UVA11922_TJ.out", "w", stdout);
#endif
	n = read();
	m = read();
	tree.build(tree.root);
	while (m--)
	{
		int l = read(), r = read();
		tree.reverseS(l, r);
	}
	tree.out(tree.root);
	return 0;
}