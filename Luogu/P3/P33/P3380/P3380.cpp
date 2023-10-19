#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// #pragma GCC optimize(2)
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3380"

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO
{
	static constexpr int SIZE = 1 << 21;
	char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
	inline void read(char &c)
	{
		for (c = gc(); !std::isgraph(c); c = gc())
			;
	}
	inline void read(char *s)
	{
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			*s++ = c;
		*s = 0;
	}
	inline void read(std::string &s)
	{
		s.clear();
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			s.push_back(c);
	}
	inline void pc(char c)
	{
		if (p3 - obuf == SIZE)
			fwrite(obuf, 1, SIZE, stdout), p3 = obuf;
		*p3++ = c;
	}
	inline void write(char c) { pc(c); }
	inline void write(const char *s)
	{
		while (*s)
			pc(*s), ++s;
	}
	inline void write(std::string s)
	{
		for (const char c : s)
			pc(c);
	}
	template <typename _Tp>
	inline void read(_Tp &x)
	{
		x = 0;
		char c = gc();
		int f = 0;
		for (; !std::isdigit(c); c = gc())
			f |= c == '-';
		for (; std::isdigit(c); c = gc())
			x = (x << 1) + (x << 3) + (c ^ 48);
		return f ? x = ~x + 1 : 1, void();
	}
	template <typename _Tp>
	inline void write(_Tp x)
	{
		static int stk[40];
		int tp = 0;
		if (!x)
			return pc('0'), void();
		if (x < 0)
			pc('-'), x = ~x + 1;
		while (x)
			stk[++tp] = x % 10, x /= 10;
		while (tp)
			pc(stk[tp--] + '0');
	}
	template <typename _Tp>
	inline void writesp(_Tp x)
	{
		write(x);
		pc(' ');
	}
	template <typename _Tp>
	inline void writeln(_Tp x) { write(x), pc('\n'); }
	template <typename _Tp, typename... Args>
	inline void read(_Tp &x, Args &...args) { read(x), read(args...); }
	template <typename _Tp, typename... Args>
	inline void write(_Tp x, Args... args) { write(x), write(args...); }
	template <typename _Tp, typename... Args>
	inline void writesp(_Tp x, Args... args) { writesp(x), writesp(args...); }
	template <typename _Tp, typename... Args>
	inline void writeln(_Tp x, Args... args) { writeln(x), writeln(args...); }
	inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); }
}

#define const constexpr

const int N = 1e5 + 5;

namespace Main
{

	vector<int> num = vector<int>(1);

	struct Splay
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

		node *root = nullptr;

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

		void rotate(node *x)
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
		void splay(node *x)
		{
			for (auto father = x->father; father = x->father, father; rotate(x))
			{
				if (father->father)
				{
					rotate(check(x) == check(father) ? father : x);
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
						splay(cur);
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
						splay(cur->son[cur->val < val]);
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
				if (k < cur->val)
				{
					if (cur->son[0])
					{
						cur = cur->son[0];
					}
					else
					{
						splay(cur);
						return now + 1;
					}
				}
				else if (k > cur->val)
				{
					now += (cur->son[0] ? cur->son[0]->size : 0);
					now += cur->cnt;
					if (cur->son[1])
					{
						cur = cur->son[1];
					}
					else
					{
						splay(cur);
						return now + 1;
					}
				}
				else
				{
					now += (cur->son[0] ? cur->son[0]->size : 0);
					splay(cur);
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
					k -= cur->cnt + (cur->son[0] ? cur->son[0]->size : 0);
					if (k <= 0)
					{
						splay(cur);
						return cur->val;
					}
					cur = cur->son[1];
				}
				else
				{
					splay(cur);
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
			splay(cur);
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
			splay(cur);
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
	};

	struct Segtree
	{
		struct node
		{
			int cl, cr;
			node *son[2] = {nullptr, nullptr}, *father = nullptr;
			Splay *tree;
			node()
			{
				tree = new Splay;
			}
		};
		vector<int> *arr;
		node *root;
		Segtree()
		{
			arr = nullptr;
			root = nullptr;
		}
		Segtree(vector<int> &a)
		{
			arr = &a;
			root = build_tree(1, arr->size() - 1, nullptr);
		}
		node *build_tree(int cl, int cr, node *fa)
		{
			node *p = new node;
			p->father = fa;
			p->cl = cl, p->cr = cr;
			for (auto i = arr->begin() + cl; i <= arr->begin() + cr; i++)
			{
				p->tree->insert(*i);
			}
			if (cl == cr)
			{
				return p;
			}
			int mid = (cl + cr) >> 1;
			p->son[0] = build_tree(cl, mid, p);
			p->son[1] = build_tree(mid + 1, cr, p);
			return p;
		}
		void modify(int k, int val, node *p)
		{
			p->tree->del(arr->at(k));
			p->tree->insert(val);
			if (p->cl == p->cr)
			{
				return;
			}
			else
			{
				return modify(k, val, p->son[(p->son[0]->cr < k)]);
			}
		}
		void modify(int k, int val)
		{
			modify(k, val, root);
			(*arr)[k] = val;
		}
		int rnk(int l, int r, int k, node *p)
		{
			if (l <= p->cl && p->cr <= r)
			{
				// p->tree->insert(k);
				int res = p->tree->rk(k) - 1;
				// p->tree->del(k);
				return res;
			}
			int res = 0;
			if (l <= p->son[0]->cr)
			{
				res += rnk(l, r, k, p->son[0]);
			}
			if (r >= p->son[1]->cl)
			{
				res += rnk(l, r, k, p->son[1]);
			}
			return res;
		}
		int rnk(int l, int r, int k)
		{
			return rnk(l, r, k, root) + 1;
		}
		int pre(int l, int r, int val, node *p)
		{
			if (l <= p->cl && p->cr <= r)
			{
				p->tree->insert(val);
				int ans = p->tree->pre(p->tree->root)->val;
				p->tree->del(val);
				if (ans >= val)
				{
					return -2147483647;
				}
				return ans;
			}
			int ans = INT_MIN;
			if (l <= p->son[0]->cr)
			{
				ans = max(ans, pre(l, r, val, p->son[0]));
			}
			if (r >= p->son[1]->cl)
			{
				ans = max(ans, pre(l, r, val, p->son[1]));
			}
			return ans;
		}
		int pre(int l, int r, int val)
		{
			return pre(l, r, val, root);
		}
		int nxt(int l, int r, int val, node *p)
		{
			if (l <= p->cl && p->cr <= r)
			{
				p->tree->insert(val);
				int ans = p->tree->nxt(p->tree->root)->val;
				p->tree->del(val);
				if (ans <= val)
				{
					return 2147483647;
				}
				return ans;
			}
			int ans = 2147483647;
			if (l <= p->son[0]->cr)
			{
				ans = min(ans, nxt(l, r, val, p->son[0]));
			}
			if (r >= p->son[1]->cl)
			{
				ans = min(ans, nxt(l, r, val, p->son[1]));
			}
			return ans;
		}
		int nxt(int l, int r, int val)
		{
			return nxt(l, r, val, root);
		}
		int kth(int l, int r, int val)
		{
			int cl = -1, cr = 1e8 + 1, mid;
			while (cl < cr)
			{
				mid = (cl + cr+1) >> 1;
				if (rnk(l, r, mid) <= val)
				{
					cl = mid;
				}
				else
				{
					cr = mid - 1;
				}
			}
			return cl;
		}
	} Tree;

	int main()
	{
		int n, m;
		FastIO::read(n, m);
		for (int i = 1, temp; i <= n; i++)
		{
			FastIO::read(temp);
			num.push_back(temp);
		}
		Tree = Segtree(num);
		int opt, l, r, pos, x;
		while (m--)
		{
			FastIO::read(opt);
			switch (opt)
			{
			case 1:
				FastIO::read(l, r, x);
				FastIO::writeln(Tree.rnk(l, r, x));
				break;
			case 2:
				FastIO::read(l, r, x);
				FastIO::writeln(Tree.kth(l, r, x));
				break;
			case 3:
				FastIO::read(pos, x);
				Tree.modify(pos, x);
				break;
			case 4:
				FastIO::read(l, r, x);
				FastIO::writeln(Tree.pre(l, r, x));
				break;
			case 5:
				FastIO::read(l, r, x);
				FastIO::writeln(Tree.nxt(l, r, x));
				break;
			}
		}
		FastIO::flush();
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