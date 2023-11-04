#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname "geometry"
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
	int l = 0, r = INT_MAX;
	random_device rd;
	sfmt19937_64 myrand(rd());
	uniform_int_distribution<long long> distlen(2, 10), distcnt(1, 200);
	uniform_int_distribution<char> cdist('a', 'd');
	// uniform_int_distribution<int> distcnt(1, 1000);
	int main()
	{
		int T = 10;
		int maxs = 980, sigmas = 4.98e5;
		FastIO::writeln(T);

		for (int i = 1; i <= T; i++)
		{
			string a, b;
			int lena = distlen(myrand), lenb = distlen(myrand);
			for (int i = 1; i <= lena; i++)
			{
				a += cdist(myrand);
			}
			for (int i = 1; i <= lenb; i++)
			{
				b += cdist(myrand);
			}
			bool ans = myrand() % 2;
			if (ans)
			{
				int cnta, cntb;
				cnta = cntb = min(maxs, sigmas / T) / (lena + lenb);
				int ap = 0, bp = 0;
				for (;;)
				{
					if (cnta && cntb)
					{
						if (myrand() % 2)
						{
							FastIO::write(a[ap++]);
							if (ap == a.size())
							{
								--cnta;
								ap = 0;
							}
						}
						else
						{
							FastIO::write(b[bp++]);
							if (bp == b.size())
							{
								--cntb;
								bp = 0;
							}
						}
					}
					else
					{
						if (cnta)
						{
							FastIO::write(a[ap++]);
							if (ap == a.size())
							{
								--cnta;
								ap = 0;
							}
						}
						else if (cntb)
						{
							FastIO::write(b[bp++]);
							if (bp == b.size())
							{
								--cntb;
								bp = 0;
							}
						}
						else
						{
							break;
						}
					}
				}
				FastIO::pc('\n');
			}
			else
			{
				int cnt = 0;
				for (int i = 1; i <= min(maxs, sigmas / T); i++)
				{
					FastIO::write(cdist(myrand));
					++cnt;
				}
				while (cnt % (lena + lenb))
				{
					FastIO::write(cdist(myrand));
					++cnt;
				}
				FastIO::pc('\n');
			}
			FastIO::writeln(a, b);
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "7.in", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	FastIO::flush();
	return 0;
}
