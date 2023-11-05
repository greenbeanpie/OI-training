#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "C"
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
// #define const constexpr

namespace Main
{
	const int N = 1e5 + 5;

	int n, m, seed, vmax, x, y;

	int quickpower(int a, int b, int p = y)
	{
		int ans = 1, base = a;
		while (b)
		{
			if (b & 1)
			{
				ans *= base;
				ans %= p;
			}
			base *= base;
			base %= p;
			b >>= 1;
		}
		return ans;
	}

	struct ODT
	{
		struct node
		{
			int l, r;
			mutable int val;

			node()
			{
				l = 0, r = 0, val = 0;
			}
			node(int val)
			{
				l = val;
			}
			node(int a, int b, int c)
			{
				l = a, r = b, val = c;
			}
			friend bool operator<(const node &a, const node &b)
			{
				return a.l < b.l;
			}
		};

		set<node> s;
		auto split(int pos)
		{
			auto temp = s.lower_bound(node(pos));
			if (temp != s.end() && pos == temp->l)
			{
				return temp;
			}
			--temp;
			if (temp->r < pos)
			{
				return s.end();
			}
			int l = temp->l, r = temp->r, val = temp->val;
			s.erase(temp);
			s.emplace(l, pos - 1, val);
			assert(l <= pos - 1);
			auto res = s.emplace(pos, r, val);
			assert(pos <= r);
			return res.first;
		}
		void add(int l, int r, int x)
		{
			auto pr = split(r + 1), pl = split(l);
			for (auto i = pl; i != pr; i++)
			{
				i->val += x;
			}
			assert(l <= r);
		}
		void assign(int l, int r, int x)
		{
			auto pr = split(r + 1), pl = split(l);
			s.erase(pl, pr);
			s.emplace(l, r, x);
			assert(l <= r);
		}
		struct __rnk
		{
			int num, cnt;
			bool operator<(__rnk b)
			{
				return num < b.num;
			}
			__rnk(int a, int b)
			{
				num = a, cnt = b;
			}
		};
		int rnk(int l, int r, int x)
		{
			auto pr = split(r + 1), pl = split(l);
			vector<__rnk> v;
			for (auto i = pl; i != pr; i++)
			{
				v.emplace_back(i->val, i->r - i->l + 1);
			}
			sort(v.begin(), v.end());
			for (auto i : v)
			{
				if (i.cnt < x)
				{
					x -= i.cnt;
				}
				else
				{
					return i.num;
				}
			}
			assert(0);
		}
		int calc(int l, int r, int x, int y)
		{
			int ans = 0;
			auto pr = split(r + 1), pl = split(l);
			for (auto i = pl; i != pr; i++)
			{
				ans += quickpower(i->val, x) * (i->r - i->l + 1) % y;
				ans %= y;
			}
			return ans;
		}
	} Tree;

	int num[N];

	struct ask
	{
		int op, l, r;
	} prb[N];

	int rnd()
	{
		int ret = seed;
		seed = (seed * 7 + 13) % 1000000007;
		return ret;
	}

	int main()
	{
		FastIO::read(n, m, seed, vmax);
		for (int i = 1; i <= n; i++)
		{
			num[i] = rnd() % vmax + 1;
			Tree.s.emplace(i, i, num[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			int op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;

			if (l > r)
			{
				swap(l, r);
			}
			if (op == 3)
			{
				x = rnd() % (r - l + 1) + 1;
			}
			else
			{
				x = rnd() % vmax + 1;
			}
			if (op == 4)
			{
				y = rnd() % vmax + 1;
			}
			switch (op)
			{
			case 1:
				Tree.add(l, r, x);
				break;
			case 2:
				Tree.assign(l, r, x);
				break;
			case 3:
				FastIO::writeln(Tree.rnk(l, r, x));
				break;
			case 4:
				FastIO::writeln(Tree.calc(l, r, x, y));
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
