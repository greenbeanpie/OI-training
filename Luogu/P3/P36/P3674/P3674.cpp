#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P3674"

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
	inline void writeln(_Tp x) { write(x), pc(' '); }
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
	const int N = 1e5 + 5;
	int num[N];
	bitset<N> plus, sub;
	int cnt[N];
	int ans[N];
	struct prob
	{
		int l, r, lb;
		int x, opt, id;
	} ask[N];
	bool cmp(prob a, prob b)
	{
		return (a.lb == b.lb ? (a.lb & 1 ? a.r < b.r : a.r > b.r) : a.lb < b.lb);
	}
	void add(int x)
	{
		if (N < x)
			return;
		if (!cnt[x]++)
		{
			sub.set(x);
			plus.set(N - x);
		}
	}
	void del(int x)
	{
		if (N < x)
			return;
		if (!--cnt[x])
		{
			sub.set(x, false);
			plus.set(N - x, false);
		}
	}
	bool query_sum(int x)
	{
		return ((plus >> (N - x)) & sub).any();
	}
	bool query_delta(int x)
	{
		return (sub & (sub << x)).any();
	}
	bool query_mul(int x)
	{
		int lim = sqrt(x);
		for (int i = 1; i <= lim; i++)
		{
			if (sub[i] && !(x % i) && sub[x / i])
			{
				return 1;
			}
		}
		return 0;
	}

	int main()
	{
		int n, m;
		FastIO::read(n, m);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(num[i]);
		}
		int unit = n / sqrt(m);
		for (int i = 1; i <= m; i++)
		{
			FastIO::read(ask[i].opt, ask[i].l, ask[i].r, ask[i].x);
			ask[i].lb = ask[i].l / unit + 1, ask[i].id = i;
		}
		sort(ask + 1, ask + 1 + m, cmp);
		int idx = 1, l = 1, r = 0;
		for (int lb = 1; lb <= n / unit + 1; lb++)
		{
			while (ask[idx].lb == lb)
			{
				while (ask[idx].l > l)
				{
					del(num[l++]);
				}
				while (ask[idx].l < l)
				{
					add(num[--l]);
				}
				while (ask[idx].r < r)
				{
					del(num[r--]);
				}
				while (ask[idx].r > r)
				{
					add(num[++r]);
				}
				switch (ask[idx].opt)
				{
				case 1:
					ans[ask[idx].id] = query_delta(ask[idx].x);
					break;
				case 2:
					ans[ask[idx].id] = query_sum(ask[idx].x);
					break;
				case 3:
					ans[ask[idx].id] = query_mul(ask[idx].x);
					break;
				}
				++idx;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cout << (ans[i] ? "hana" : "bi") << endl;
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