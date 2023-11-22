#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int __int128

long long P;

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

template <typename T>
struct Segtree
{
	struct node
	{
		int l, r;
		T val, lazy_add, lazy_mul;
		node *son[2];
		node()
		{
			l = r = val = lazy_add = 0;
			lazy_mul = 1;
			son[0] = son[1] = nullptr;
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
		// p->val %= P;
	}
	void build()
	{
		return build(1, arr->size() - 1, root = new node);
	}
	void maintain(node *p)
	{
		p->son[0]->lazy_mul = (p->son[0]->lazy_mul * p->lazy_mul) % P;
		p->son[1]->lazy_mul = (p->son[1]->lazy_mul * p->lazy_mul) % P;
		p->son[0]->lazy_add = (p->son[0]->lazy_add * p->lazy_mul + p->lazy_add) % P;
		p->son[1]->lazy_add = (p->son[1]->lazy_add * p->lazy_mul + p->lazy_add) % P;
		p->son[0]->val = (p->son[0]->val * p->lazy_mul + p->lazy_add * (p->son[0]->r - p->son[0]->l + 1)) % P;
		p->son[1]->val = (p->son[1]->val * p->lazy_mul + p->lazy_add * (p->son[1]->r - p->son[1]->l + 1)) % P;
		p->lazy_mul = 1;
		p->lazy_add = 0;
	}
	void update(node *p)
	{
		p->val = p->son[0]->val + p->son[1]->val;
		// p->val %= P;
	}
	void add(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_add += val;
			p->val += (p->r - p->l + 1) * val;
			// p->lazy_add %= P;
			// p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			add(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			add(l, r, val, p->son[1]);
		}
		update(p);
	}
	void add(int l, int r, int val)
	{
		return add(l, r, val, root);
	}
	void mul(int l, int r, int val, node *p)
	{
		if (l <= p->l && p->r <= r)
		{
			p->lazy_mul *= val;
			p->lazy_add *= val;
			p->val *= val;
			// p->lazy_mul %= P;
			// p->lazy_add %= P;
			// p->val %= P;
			return;
		}
		maintain(p);
		if (p->son[0]->r >= l)
		{
			mul(l, r, val, p->son[0]);
		}
		if (p->son[1]->l <= r)
		{
			mul(l, r, val, p->son[1]);
		}
		update(p);
	}
	void mul(int l, int r, T val)
	{
		return mul(l, r, val, root);
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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	FastIO::read(n, m, P);
	// cin >> n >> m >> P;
	for (int i = 1, tmp; i <= n; i++)
	{
		// cin >> tmp;
		FastIO::read(tmp);
		num.emplace_back(tmp);
	}
	Tree.build();
	int tot = 0;
	for (int i = 1, op, x, y, z; i <= m; i++)
	{
		// cin >> op;
		FastIO::read(op);
		if (op == 1)
		{
			// cin >> x >> y >> z;
			FastIO::read(x, y, z);
			Tree.mul(x, y, z);
		}
		else if (op == 2)
		{
			// cin >> x >> y >> z;
			FastIO::read(x, y, z);
			Tree.add(x, y, z);
		}
		else
		{
			++tot;
			// cin >> x >> y;
			FastIO::read(x, y);
			// cout << Tree.query(x, y) % P << endl;
			FastIO::writeln(Tree.query(x, y) % P);
		}
	}
	FastIO::flush();
	return 0;
}