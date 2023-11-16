#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#ifndef ONLINE_JUDGE
#pragma GCC optimize("inline")
#endif
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
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
void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
#define const constexpr

namespace P4124
{
	int dp[15][10][5][2][2][2];

	inline int getlen(int x)
	{
		if (x == 0)
		{
			return x;
		}
		return log10(x) + 1;
	}

	inline int gettrail(int x, int len)
	{
		return x % (int)pow(10, len - 1);
	}

	inline int gethead(int x, int len)
	{
		return x / (int)pow(10, len - 1);
	}

	int dfs(int len, int last, int cnt, bool ok, bool f8, bool f4, int up, bool limit, bool head = 0)
	{
		if (f4 && f8)
		{
			return 0;
		}
		if (cnt >= 3)
		{
			ok = 1;
		}
		if (len <= 0)
		{
			return ok;
		}
		
		if (!limit && dp[len][last][cnt][ok][f8][f4])
		{
			return dp[len][last][cnt][ok][f8][f4];
		}
		assert(gethead(up, len) <= 10);
		int res = 0;
		for (int i = head; i <= (limit ? gethead(up, len) : 9); i++)
		{
			res += dfs(len - 1, i, (last == i ? cnt + 1 : 1), ok, f8 || (i == 8), f4 || (i == 4), -1, 0);
		}
		if (limit)
		{
			int temp = gethead(up, len);
			res += dfs(len - 1, temp, (temp == last ? cnt + 1 : 1), ok, f8 || temp == 8, f4 || temp == 4, gettrail(up, len), 1);
		}
		else
		{
			dp[len][last][cnt][ok][f8][f4] = res;
		}
		return res;
	}

	int main()
	{
		int l, r;
		FastIO::read(l, r);
		// dfs(1000, 1, 1);
		// FastIO::writeln(dfs(r, getlen(r), gethead(r), 1) - dfs(l - 1, getlen(l - 1), gethead(l - 1), 1));
		// FastIO::writeln(dfs(r, getlen(r), gethead(r, getlen(r)), 1) - dfs(l - 1, getlen(l - 1), gethead(l - 1, getlen(l - 1)), 1));
		FastIO::writeln(dfs(11, -1, 0, 0, 0, 0, r, 1, 1) - dfs(getlen(l - 1), -1, 0, 0, 0, 0, l - 1, 1, 1));
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P4124");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P4124::main();
	FastIO::flush();
	return 0;
}
