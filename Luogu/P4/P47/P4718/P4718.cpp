#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "P4718"

auto abs(auto x)
{
	return x > 0 ? x : -x;
}

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
	random_device rd;
	sfmt19937_64 myrand(rd());
	uniform_int_distribution<> dist(1000, 2000);
	int maxfac = -1;

	int gcd(int x, int y)
	{
		if (x == 0)
		{
			return y;
		}
		return gcd(y % x, x);
	}

	int f(int x, int c, int n)
	{
		return (x * x + c) % n;
	}

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

	bool MillerRabin(int x)
	{
		int time = 8;
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

	int PollardRho(int x)
	{
		int t = 0, c = myrand() % (x - 1) + 1, temp = dist(myrand);
		int val = 1, s = 0;
		// for (int cnt = 1;; s = t, cnt = min(cnt << 1, (int)127))
		// {

		// 	for (int i = 1; i <= cnt; i++)
		// 	{
		// 		t = f(t, c, x);
		// 		val = val * abs(t - s) % x;
		// 		if (!val)
		// 		{
		// 			return x;
		// 		}
		// 	}
		// 	int d = gcd(val, x);
		// 	if (d > 1)
		// 	{
		// 		return d;
		// 	}
		// }
		for (int cnt = 1;;cnt<<=1,s=t,val=1){
			for (int i = 1; i <= cnt;i++){
				t = f(t, c, x);
				val = val * abs(t - s) % x;
				if(!(i%127)){
					int d = gcd(val, x);
					if(d>1){
						return d;
					}
				}
			}
			int d = gcd(val, x);
			if(d>1){
				return d;
			}
		}
	}

	int solve(int x)
	{
		if (maxfac >= x || x < 2)
		{
			return 0;
		}
		if (MillerRabin(x))
		{
			maxfac = max(maxfac, x);
			return x;
		}
		int p = x;
		while (p >= x)
		{
			p = PollardRho(x);
		}
		while (x % p == 0)
		{
			x /= p;
		}
		return max(solve(x), solve(p));
	}

	int main()
	{
		int T;
		FastIO::read(T);
		while (T--)
		{
			int n;
			FastIO::read(n);
			maxfac = -1;
			int ans = solve(n);
			if (ans == n)
			{
				FastIO::write("Prime");
				FastIO::pc('\n');
			}
			else
			{
				FastIO::write(ans);
				FastIO::pc('\n');
			}
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
