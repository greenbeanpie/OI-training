#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "A"
#define const constexpr
int T;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO
{
	static constexpr int S = 1 << 21;
	char ibuf[S], obuf[S], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
	inline void pc(char c)
	{
		if (p3 - obuf == S)
			fwrite(obuf, 1, S, stdout), p3 = obuf;
		*p3++ = c;
	}
	inline void write(char c) { pc(c); }
	template <typename _Tp>
	inline void read(_Tp &x)
	{
		x = 0;
		char c = gc();
		int f = 0;
		for (; !std::isdigit(c); c = gc())
			f |= c == '-';
		for (; std::isdigit(c); c = gc())
			x = x * 10 + (c ^ 48);
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
	inline void writesp(_Tp x) { write(x), pc(' '); }
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
using namespace FastIO;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	read(T);
	while (T--)
	{
		int n, p;
		read(n, p);
		if (p == 1 || n < p / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				write(i);
				pc(' ');
			}
			pc('\n');
			continue;
		}
		for (int i = 1; i < 1.0 * p / 2; i++)
		{
			for (int j = 0; j + i <= n; j += p)
			{
				write(j + i);
				pc(' ');
				if (j + p - i != j + i && j + p - i <= n)
				{
					write(j + p - i);
					pc(' ');
				}
			}
		}
		for (int i = p; i <= n; i += p)
		{
			write(i);
			pc(' ');
		}
		if (p % 2 == 0)
		{
			for (int i = p / 2; i <= n; i += p)
			{
				write(i);
				pc(' ');
			}
		}
		pc('\n');
	}
	flush();
	return 0;
}