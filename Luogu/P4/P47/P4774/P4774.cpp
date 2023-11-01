#include <bits/stdc++.h>
#include <bits/extc++.h>
// #include <python3.12/Python.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "P4774"
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
	const int N = 1e5 + 5;
	int a[N], b[N], p[N], atk[N], maxinum;
	multiset<int> sword;

	int gcd(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}
		return gcd(b, a % b);
	}

	int lcm(int x, int y)
	{
		return x * y / gcd(x, y);
	}

	int exgcd(int a, int b, int &x, int &y)
	{ // ax+by=gcd(a,b)
		if (!b)
		{
			x = 1, y = 0;
			return a;
		}
		auto ans = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return ans;
	}

	int excrt(int n)
	{
		int m1 = 1, a1 = 0;
		for (int i = 1; i <= n; i++)
		{
			int m2 = p[i];
			int x, y;
			int gcd = exgcd(b[i] * m1 % p[i], m2, x, y);
			int c = (a[i] - b[i] * a1 % m2 + m2) % m2 /* , mod = m2 / gcd */;
			if (c % gcd)
			{
				return -1;
			}
			x = (x % m2 + m2) % m2;
			// x = x * c / gcd % mod;
			// a1 += m1 * x;
			// m1 = lcm(m2, m1);
			// a1 = (a1 % m1 + m1) % m1;
			a1 += (c / gcd) * x % (m2 / gcd) * m1 % (m1 * m2 / gcd);
			m1 *= m2 / gcd;
			a1 %= m1;
		}

		if (a1 < maxinum)
		{
			a1 += ((maxinum - a1 - 1) / m1 + 1) * m1;
		}
		return a1;
	}

	void solve()
	{
		sword.clear();
		int n, m;
		FastIO::read(n, m);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(p[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(atk[i]);
		}
		for (int i = 1, temp; i <= m; i++)
		{
			FastIO::read(temp);
			sword.insert(temp);
		}
		maxinum = 0;
		for (int i = 1; i <= n; i++)
		{
			auto now = sword.upper_bound(a[i]);
			if (now != sword.begin())
			{
				--now;
			}
			b[i] = *now;
			sword.erase(now), sword.insert(atk[i]);
			maxinum = max(maxinum, (a[i] - 1) / b[i] + 1);
		}
		FastIO::writeln(excrt(n));
	}

	int main()
	{
		int T;
		FastIO::read(T);
		while (T--)
		{
			solve();
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "_1.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	FastIO::flush();
	return 0;
}
