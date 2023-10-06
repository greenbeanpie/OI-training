#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#ifndef CODESPACE
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#endif
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
#define int long long
#define double long double
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
		{
			f |= c == '-';
		}
		for (; std::isdigit(c); c = gc())
		{
			x = (x << 1) + (x << 3) + (c ^ 48);
		}
		return f ? x = ~x + 1 : 1, void();
	}
	template <typename _Tp>
	inline void write(_Tp x)
	{
		static int stk[40];
		int tp = 0;
		if (!x)
		{
			return pc('0'), void();
		}
		if (x < 0)
		{
			pc('-'), x = ~x + 1;
		}
		while (x)
		{
			stk[++tp] = x % 10, x /= 10;
		}
		while (tp)
		{
			pc(stk[tp--] + '0');
		}
	}
	template <typename _Tp>
	inline void writesp(_Tp x)
	{
		write(x);
		pc(' ');
	}
	template <typename _Tp>
	inline void writeln(_Tp x)
	{
		write(x), pc(' ');
	}
	template <typename _Tp, typename... Args>
	inline void read(_Tp &x, Args &...args)
	{
		read(x), read(args...);
	}
	template <typename _Tp, typename... Args>
	inline void write(_Tp x, Args... args)
	{
		write(x), write(args...);
	}
	template <typename _Tp, typename... Args>
	inline void writesp(_Tp x, Args... args)
	{
		writesp(x), writesp(args...);
	}
	template <typename _Tp, typename... Args>
	inline void writeln(_Tp x, Args... args)
	{
		writeln(x), writeln(args...);
	}
	inline void flush()
	{
		fwrite(obuf, p3 - obuf, 1, stdout);
	}
	int read()
	{
		int f = 1, x = 0;
		char c;
		c = getchar();
		while (!isdigit(c))
		{
			c = getchar();
			if (c == '-')
			{
				f = -1;
			}
		}

		while (isdigit(c))
		{
			x = x * 10 + c - '0';
			c = getchar();
		}
		return x * f;
	}
	void write(int x)
	{
		stack<int> s;
		while (x)
		{
			s.push(x % 10);
			x /= 10;
		}
		while (s.size())
		{
			putchar(s.top() + '0');
			s.pop();
		}
	}
}
#define endl "\n"
#define problemname "pair"
#define const constexpr

namespace Main
{
	struct ta
	{
		int lowbit(int x)
		{
			return x & (-x);
		}
		int n = 55;
		int d[105];
		void add(int p, int k)
		{
			while (p <= n)
			{
				d[p] += k;
				p += lowbit(p);
			}
		}

		int query(int x)
		{
			int ans = 0;
			while (x > 0)
			{
				ans += d[x];
				x -= lowbit(x);
			}
			return ans;
		}
	} cnt;
	const int N = 1e6 + 5;
	struct prob
	{
		int l, r, id, lb;
	} ask[N];
	int num[N];
	// int cnt[55];
	int ans[N];
	bool cmp(prob a, prob b)
	{
		if (a.lb == b.lb)
		{
			if (a.lb & 1)
			{
				return a.r < b.r;
			}
			return a.r > b.r;
		}
		return a.lb < b.lb;
	}
	int res = 0;
	void addl(int u)
	{
		// for (int i = 1; i < u; i++)
		// {
		// 	res += cnt[i];
		// }
		res += cnt.query(u - 1);
		cnt.add(u, 1);
	}
	void addr(int u)
	{
		// for (int i = u + 1; i <= 50; i++)
		// {
		// 	res += cnt[i];
		// }
		res += cnt.query(50) - cnt.query(u);
		// ++cnt[u];
		cnt.add(u, 1);
	}
	void dell(int u)
	{
		// for (int i = 1; i < u; i++)
		// {
		// 	res -= cnt[i];
		// }
		res -= cnt.query(u - 1);
		// --cnt[u];
		cnt.add(u, -1);
	}
	void delr(int u)
	{
		// for (int i = u + 1; i <= 50; i++)
		// {
		// 	res -= cnt[i];
		// }
		res -= cnt.query(50) - cnt.query(u);
		// --cnt[u];
		cnt.add(u, -1);
	}
	int main()
	{
		auto st = clock();
		int n, m;
		n = FastIO::read(), m = FastIO::read();
		for (int i = 1; i <= n; i++)
		{
			num[i] = FastIO::read();
		}
		int unit = sqrt(n);
		for (int i = 1; i <= m; i++)
		{
			// FastIO::read(ask[i].l, ask[i].r);
			ask[i].l = FastIO::read(), ask[i].r = FastIO::read();
			ask[i].lb = ask[i].l / unit + 1;
			ask[i].id = i;
		}
		sort(ask + 1, ask + m + 1, cmp);
		int l = 1, r = 0, idx = 1;
		for (int lb = 1; lb <= n / unit + 1; lb++)
		{
			while (ask[idx].lb == lb)
			{
				while (l < ask[idx].l)
				{
					dell(num[l++]);
				}
				while (l > ask[idx].l)
				{
					addl(num[--l]);
				}
				while (r < ask[idx].r)
				{
					addr(num[++r]);
				}
				while (r > ask[idx].r)
				{
					delr(num[r--]);
				}
				ans[ask[idx].id] = res;
				++idx;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i] << endl;
		}
		cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC;
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname "3.in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}