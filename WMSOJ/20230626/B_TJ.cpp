#include <bits/stdc++.h>

namespace Main
{
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

	typedef long long i64;
	static constexpr int N = 1e5 + 5;
	static constexpr int inf = 1 << 30;
	static int n, ans, eat[N], eaten[N];
	static std::set<std::pair<int, int>> s;

	static inline void main()
	{
#ifndef CODESPACE
		freopen("lions.in", "r", stdin);
		freopen("lions.out", "w", stdout);
#endif
#ifdef CODESPACE
		freopen("B.in", "r", stdin);
#endif
		read(n);
		ans = n - 1;
		for (int i = 1; i <= n; i++)
		{
			int x;
			read(x);
			s.insert(std::make_pair(x, i));
		}
		for (int i = 1; i < n; i++)
		{
			auto min = *s.begin(), max = *(--s.end());
			s.erase(max), s.erase(min);
			eaten[i] = min.second, eat[max.second] = i;
			s.insert(std::make_pair(max.first - min.first, max.second));
		}
		for (int i = n - 1; i; i = std::min(i - 1, ans))
		{
			if (eat[eaten[i]])
				ans = eat[eaten[i]] - 1;
		} // back
		writeln(ans);
		std::sort(eaten + 1, eaten + ans + 1);
		for (int i = 1; i <= ans; i++)
			writesp(eaten[i]);
		return flush(), void();
	}
}

signed main() { return Main::main(), 0; }