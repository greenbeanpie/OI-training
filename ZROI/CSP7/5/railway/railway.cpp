#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
// #pragma GCC optimize("Ofast")
const int N = 3e3 + 5;

unordered_map<int, bool> q[N];

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO
{
	static constexpr int SIZE = 1 << 22;
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

signed main()
{
	freopen("railway.in", "r", stdin);
	freopen("railway.out", "w", stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0), cout.tie(0);
	int n;
	// cin >> n;
	FastIO::read(n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j > i; j--)
		{
			q[i][j] = 1;
		}
	}
	for (int i = 1; i <= n;)
	{
		while (q[i].empty() && i <= n)
		{
			++i;
		}
		if (i > n)
		{
			break;
		}
		FastIO::writesp(i, q[i].begin()->first);
		// cout << i << " " << q[i].begin()->first << " ";
		int to = q[i].begin()->first;
		q[i].erase(q[i].begin()->first);
		if (q[to].size())
		{
			FastIO::writesp(q[to].begin()->first);
			// cout << q[to].begin()->first << " ";
			int a = to;
			to = q[to].begin()->first;
			q[a].erase(to);
			if (q[to].size())
			{
				FastIO::write(q[to].begin()->first);
				FastIO::pc('\n');
				// cout << q[to].begin()->first << endl;
				q[to].erase(q[to].begin()->first);
			}
			else
			{
				FastIO::write(n);
				FastIO::pc('\n');
				// cout << n << endl;
			}
		}
		else
		{
			int now = to;
			while (q[now].empty() && now <= n)
			{
				++now;
			}
			if (now > n)
			{
				FastIO::writesp(n, n);
				FastIO::pc('\n');
				// cout << n << " " << n << endl;
				continue;
			}
			FastIO::writesp(now, q[now].begin()->first);
			FastIO::pc('\n');
			// cout << now << " " << q[now].begin()->first << endl;
			q[now].erase(q[now].begin()->first);
		}
	}
	FastIO::flush();
	return 0;
}
