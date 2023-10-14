#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "paradise"
// #define const constexpr

const int mod = (int)ULONG_LONG_MAX + 1;

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

namespace Main
{

	const int N = 1e5 + 5;
	map<int, int> cost;
	int a[N], b[N];
	int dp[N];
	int main()
	{
		int T, o;
		// cin >> T >> o;
		FastIO::read(T, o);
		while (T--)
		{
			int m, q;
			FastIO::read(m, q);
			int minval = ULLONG_MAX;
			for (int i = 1; i <= m; i++)
			{
				// cin >> a[i] >> b[i];
				FastIO::read(a[i], b[i]);
				minval = min(minval, b[i]);
			}
			if (m <= 20 && q <= 10)
			{
				fill(dp, dp + 105, ULONG_LONG_MAX);
				dp[0] = 0;
				for (int i = 1; i <= m; i++)
				{
					// if (a[i] > 100)
					// {
					// 	minval100 = min(minval100, b[i]);
					// 	continue;
					// }
					for (int j = 1; j <= min((__int128)105, a[i]); j++)
					{
						dp[j] = min(dp[j], b[i]);
						dp[j] %= mod;
					}
					for (int j = a[i]; j <= 105; j++)
					{
						dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
						dp[j] %= mod;
					}
				}
			}
			for (int i = 1, n; i <= q; i++)
			{
				// cin >> n;
				FastIO::read(n);
				if (n <= 1)
				{
					// cout << 0 << endl;
					FastIO::write(0);
					FastIO::pc('\n');
				}
				else
				{
					// cout << dp[n - 1] << endl;
					int sum = 0;
					for (int i = 1; i < n; i++)
					{
						sum += dp[i];
					}
					FastIO::write(sum%mod);
					FastIO::pc('\n');
				}
			}
		}
		FastIO::flush();
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "2.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}