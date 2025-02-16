#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
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
void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
#define const constexpr

namespace P3690
{
	struct LCT
	{
		int tot = 0;

		struct node
		{
			int val = 0, cnt = 1, size = 1, dat;
			bool tag;
			node *son[2] = {nullptr, nullptr}, *father = nullptr;
			node()
			{
				cnt = 1;
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
			return u != nullptr && u->father && (u == (u->father->son[1]));
		}
		static constexpr int N = 3e5 + 5;

		node *ptr = new node[N << 1];

		void pushup(node *u)
		{
			u->size = u->cnt, u->dat = u->val;
			if (u->son[0])
			{
				u->size += u->son[0]->size, u->dat ^= u->son[0]->dat;
			}
			if (u->son[1])
			{
				u->size += u->son[1]->size, u->dat ^= u->son[1]->dat;
			}
		}

		void reverse(node *u)
		{
			swap(u->son[0], u->son[1]);
			u->tag ^= 1;
		}
		void pushdown(node *x)
		{
			if (x->tag)
			{
				if (x->son[0])
				{
					reverse(x->son[0]);
				}
				if (x->son[1])
				{
					reverse(x->son[1]);
				}
				x->tag = 0;
			}
		}
		bool isroot(node *x)
		{
			return (x != nullptr && x->father == nullptr) || (x->father != nullptr && x->father->son[0] != x && x->father->son[1] != x);
		}
		void rotate(node *x)
		{
			auto f1 = x->father, f2 = f1->father;
			// pushdown(x), pushdown(f1);
			auto r1 = check(x), r2 = check(f1);
			// if (f2)
			// {
			// 	f2->son[f1 == f2->son[1]] = x;
			// }
			// x->father = f2;
			// f1->son[r1] = x->son[r1 ^ 1];
			// if (x->son[r1 ^ 1])
			// {
			// 	x->son[r1 ^ 1]->father = f1;
			// }
			if (!isroot(f1))
			{
				f2->son[r2] = x;
			}
			x->father = f2;
			f1->son[r1] = x->son[r1 ^ 1];
			if (x->son[r1 ^ 1])
			{
				x->son[r1 ^ 1]->father = f1;
			}
			// x->son[r1 ^ 1] = f1;
			x->son[r1 ^ 1] = f1;
			f1->father = x;
			// maintain(f1), maintain(x);

			pushup(f1), pushup(x);
		}
		void update(node *x)
		{
			if (!isroot(x))
			{
				update(x->father);
			}
			pushdown(x);
		}
		void splay(node *x)
		{
			update(x);
			for (auto father = x->father; !isroot(x); rotate(x))
			{
				father = x->father;
				if (!isroot(father))
				{
					rotate(check(x) == check(father) ? father : x);
				}
			}
			root = x;
		}
		node *findroot(node *x)
		{
			access(x);
			splay(x);
			while (x->son[0])
			{
				pushdown(x);
				x = x->son[0];
			}
			splay(x);
			return x;
		}
		node *access(node *x)
		{
			node *last;
			for (last = nullptr; x; x = x->father)
			{
				splay(x);
				x->son[1] = last;
				last = x;
				pushup(x);
			}
			return last;
		}
		void makeroot(node *p)
		{
			access(p);
			splay(p);
			reverse(p);
		}
		void split(node *x, node *y)
		{
			makeroot(x);
			access(y);
			splay(y);
		}
		void split(int x, int y)
		{
			return split(ptr + x, ptr + y);
		}
		node *find(node *p)
		{
			access(p);
			splay(p);
			while (p->son[0])
			{
				pushdown(p);
				p = p->son[0];
			}
			splay(p);
			return p;
		}
		void link(node *x, node *y)
		{
			makeroot(x);
			// splay(x);
			// if (findroot(y) != x)
			// {
			// 	x->father = y;
			// }
			if (findroot(y) == x)
			{
				return;
			}
			else
			{
				x->father = y;
			}
		}
		void link(int x, int y)
		{
			return link(ptr + x, ptr + y);
		}
		void cut(node *x, node *p)
		{
			split(x, p);
			if (p->son[0] == x && !p->son[1])
			{
				x->father = p->son[0] = nullptr;
			}
		}
		void cut(int x, int y)
		{
			return cut(ptr + x, ptr + y);
		}
	} Tree;

	int main()
	{
		int n, m;
		FastIO::read(n, m);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(Tree.ptr[i].val);
			Tree.ptr[i].dat = Tree.ptr[i].val;
		}
		for (int i = 1; i <= m; i++)
		{
			int op, x, y;
			FastIO::read(op, x, y);
			switch (op)
			{
			case 0:
				Tree.split(x, y);
				FastIO::writeln(Tree.ptr[y].dat);
				break;
			case 1:
				Tree.link(x, y);
				break;
			case 2:
				Tree.cut(x, y);
				break;
			case 3:
				Tree.splay(Tree.ptr + x);
				Tree.ptr[x].val = y;
			}
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P3690");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P3690::main();
	FastIO::flush();
	return 0;
}
