#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int __int128

long long P;
int n, d, q;

template <typename T>
struct Segtree
{
	struct node
	{
		int l, r, size;
		T val, lazy_mod;
		node *son[2];
		node()
		{
			size = 1;
			lazy_mod = 0 son[0] = son[1] = nullptr;
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
		p->size = p->son[0]->size + p->son[1]->size;
	}
	void build()
	{
		return build(1, arr->size() - 1, root = new node);
	}
	void maintain(node *p)
	{
		if (p->son[0])
		{
			p->son[0]->lazy_mod = p->lazy_mod;
			if (p->son[0]->l == p->son[0]->r)
			{
				p->son[0]->val = max(p->son[0]->val, lazy_mod);
			}
		}
		if (p->son[1])
		{
			p->son[1]->lazy_mod  
		}
		p->son[1]->lazy_mod = p->lazy_mod;

		p->lazy_mod = -1;
	}
	void update(node *p)
	{
		p->val = p->son[0]->val + p->son[1]->val;
		// p->val %= P;
	}
	void mod(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_mod = val;
			p->val = (p->r - p->l + 1) * val;
			// p->lazy_add %= P;
			// p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			mod(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			mod(l, r, val, p->son[1]);
		}
		update(p);
	}
	void mod(int l, int r, int val)
	{
		return mod(l, r, val, root);
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
		return res;
	}
	int query(int l, int r)
	{
		return query(l, r, root);
	}
};

vector<int> num = vector<int>(1);

Segtree<int> Tree(num);

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

namespace A
{
	void main()
	{
#ifdef CODESPACE
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
#endif
		FastIO::read(n, d, q);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(num[i]);
		}
		Tree.build();
		for (int i = 1; i <= q; i++)
		{
			int l, x;
			FastIO::read(l, x);
		}
	}
}

signed main()
{

	A::main();
	FastIO::flush();
	return 0;
}