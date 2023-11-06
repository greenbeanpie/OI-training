#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "P3835"
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

namespace Main
{
	const int N = 5e5 + 5;

	int tot = 0, ans[N];

	struct ask
	{
		int v, op, x;
	};

	struct node
	{
		int v;
		ask op;
		vector<int> son;
	} e[N];

	struct Splay
	{
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
						return now+1;
					}
				}
				else if (cur->son[1])
				{
					now += (cur->son[0] ? cur->son[0]->size : 0);

					if (k == cur->val)
					{
						splay(cur);
						return now + 1;
					}
					now += cur->cnt;
					cur = cur->son[1];
				}
				else
				{
					now += (cur->son[0] ? cur->son[0]->size : 0);
					splay(cur);
					if (k > cur->val)
					{
						now += cur->cnt;
					}
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
		node *pre(int x)
		{
			insert(x);
			auto res = pre(root);
			del(x);
			return res;
			// rk(x);
			// if (root->val == x)
			// {
			// 	return pre(root);
			// }
			// return root;
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
		node *nxt(int x)
		{
			insert(x);
			auto res = nxt(root);
			del(x);
			return res;
			// rk(x);
			// return nxt(root);
		}
		bool del(int x)
		{
			rk(x);
			auto cur = root;
			if (cur->val != x)
			{
				return 1;
			}
			if (cur->cnt > 1)
			{
				--cur->cnt;
				maintain(cur);
				return 0;
			}
			if (!cur->son[0] && !cur->son[1])
			{
				root = nullptr;
				return 0;
			}
			if (!cur->son[0])
			{
				root = cur->son[1];
				root->father = nullptr;
				return 0;
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
			return 0;
		}
	} tree;

	void insert(int ver, ask op)
	{
		e[op.v].op = op;
		e[ver].son.emplace_back(op.v);
	}

	void dfs(int pos)
	{
		bool flag = 0;
		if (pos != 0)
		{
			int temp = e[pos].op.x;
			switch (e[pos].op.op)
			{
			case 1:
				tree.insert(temp);
				break;
			case 2:
				flag = tree.del(temp);
				break;
			case 3:
				ans[pos] = tree.rk(temp) - 1;
				break;
			case 4:
				ans[pos] = tree.kth(temp + 1);
				break;
			case 5:
				ans[pos] = tree.pre(temp)->val;
				break;
			case 6:
				ans[pos] = tree.nxt(temp)->val;
				break;
			}
		}
		for (auto i : e[pos].son)
		{
			dfs(i);
		}
		if (pos != 0)
		{
			if (e[pos].op.op == 1)
			{
				tree.del(e[pos].op.x);
			}
			else if (e[pos].op.op == 2 && !flag)
			{
				tree.insert(e[pos].op.x);
			}
		}
	}

	int main()
	{
		tree.insert(-(1ll << 31) + 1);
		tree.insert((1ll << 31) - 1);
		int n;
		FastIO::read(n);
		for (int i = 1, v, op, x; i <= n; i++)
		{
			FastIO::read(v, op, x);
			insert(v, {i, op, x});
		}
		dfs(0);
		for (int i = 1; i <= n; i++)
		{
			if (ans[i])
			{
				FastIO::writeln(ans[i]);
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
	FastIO::flush();
	return 0;
}
