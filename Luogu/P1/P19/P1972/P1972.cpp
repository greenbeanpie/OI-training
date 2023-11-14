#include <bits/stdc++.h>
// #include <bits/extc++.h>
//  using namespace __gnu_pbds;
//  using namespace __gnu_cxx;
using namespace std;
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

namespace P1972
{

	const int N = 1e6 + 5;
	struct treearray
	{
		int tre[N << 1], n = N;
		int lwbt(int x) { return x & (-x); }
		int ask(int i)
		{
			int ans = 0;
			for (; i; i -= lwbt(i))
				ans += tre[i];
			return ans;
		}
		void add(int i, int k)
		{
			for (; i <= n; i += lwbt(i))
				tre[i] += k;
		}
	} t;

	int val[N];

	int last[N], ans[N];

	struct ask
	{
		int l, r, id;
	} prob[N];

	bool cmp(ask a, ask b)
	{
		return a.r < b.r;
	}

	int main()
	{
		int n;
		FastIO::read(n);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(val[i]);
		}
		int m;
		FastIO::read(m);
		for (int i = 1; i <= m; i++)
		{
			FastIO::read(prob[i].l, prob[i].r);
			prob[i].id = i;
		}
		sort(prob + 1, prob + 1 + m, cmp);
		int cur = 1;
		for (int i = 1; i <= m; i++)
		{
			for (; cur <= prob[i].r; ++cur)
			{
				if (last[val[cur]])
				{
					t.add(last[val[cur]], -1);
				}

				t.add(last[val[cur]] = cur, 1);
			}
			ans[prob[i].id] = t.ask(prob[i].r) - t.ask(prob[i].l - 1);
		}
		for (int i = 1; i <= m; i++)
		{
			FastIO::writeln(ans[i]);
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P1972");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P1972::main();
	FastIO::flush();
	return 0;
}
