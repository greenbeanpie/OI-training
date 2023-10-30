#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "C"
// #pragma GCC optimize(2)
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)

namespace FastIO
{
	static constexpr int SIZE = 1 << 25;
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
	random_device rd;
	sfmt19937_64 myrand(rd());
	int quickpower(int a, int b, int mod)
	{
		int ans = 1, base = a;
		while (b)
		{
			if (b & 1)
			{
				ans = ans * base % mod;
			}
			base = base * base % mod;
			b >>= 1;
		}
		return ans % mod;
	}
	bool isprime(int x)
	{
		int time = 4;
		if (x < 3 || !(x % 2))
		{
			return x == 2;
		}
		int u = x - 1, t = 0;
		while (!(u & 1))
		{
			u >>= 1;
			++t;
		}
		for (int i = 1; i <= time; i++)
		{
			int a = myrand() % (x - 2) + 2, v = quickpower(a, u, x);
			if (v == 1)
			{
				continue;
			}
			bool pass = 0;
			for (int s = 1; s <= t; s++)
			{
				if (v == x - 1)
				{
					pass = 1;
					break;
				}
				v = v * v % x;
			}
			if (!pass)
			{
				return 0;
			}
		}
		return 1;
	}
	int main()
	{
		int T;
		FastIO::read(T);
		while (T--)
		{
			int left, k;
			// cin >> left >> k;
			FastIO::read(left, k);
			int ans = 0;
			while (left > 1)
			{
				int now = left;
				while (!isprime(now))
				{
					--now;
				}
				if ((now - k) * (now - k) + (k - 1) * (k - 1) * (left - now) <= (k - 1) * (k - 1) * left)
				{
					break;
				}
				ans += (now - k) * (now - k);
				left -= now;
			}
			ans += (k - 1) * (k - 1) * left;
			// cout << ans << endl;
			FastIO::writeln(ans);
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