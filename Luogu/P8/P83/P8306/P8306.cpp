#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "P8306"
// #define const constexpr

const int N = 3e6 + 5;

char c[N];

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
	struct Trie
	{
		struct node
		{
			cc_hash_table<char, node *> son;
			int cnt;
			node()
			{
				cnt = 0;
			}
		};
		node *root;
		void add(char *s)
		{
			return add(s, 1, root);
		}
		void add(char *s, int now, node *p)
		{
			if (p->son.find(s[now]) == p->son.end())
			{
				p->son[s[now]] = new node;
			}
			++p->son[s[now]]->cnt;
			if (s[now + 1])
			{
				add(s, now + 1, p->son[s[now]]);
			}
		}
		int find(char *s)
		{
			// return find(s, 1, root);
			auto cur = root;
			int now = 1;
			while(s[now]&&cur->son[s[now+1]]){
				
			}
		}
		int find(char *s, int now, node *p)
		{
			if(!s[now+1])
			{
				return p->cnt;
			}
			else if (p->son.find(s[now]) == p->son.end())
			{
				return 0;
			}
			else
			{
				return find(s, now + 1, p->son[s[now]]);
			}
		}
		void init()
		{
			root = new node;
		}
		void clear()
		{
			root = new node;
		}
	} Tree;

	int main()
	{
		int T;
		FastIO::read(T);
		while (T--)
		{
			Tree.clear();
			int n, q;
			FastIO::read(n, q);
			for (int i = 1; i <= n; i++)
			{
				FastIO::read(c + 1);
				Tree.add(c);
			}
			for (int i = 1; i <= q; i++)
			{
				FastIO::read(c + 1);
				cout << Tree.find(c) << endl;
			}
		}
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
