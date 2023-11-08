#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
#define double long double
#define endl "\n"
#define problemname ""
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

namespace very
{

	const int N = 55;
	pair<int, int> w[N];

	vector<pair<int, int>> e[N];

	string s[N];

	bool vis[N];

	void bfs(int u)
	{
		bool flag0, flag1, flag2, flag3;
		queue<pair<int, int>> q;
		q.emplace(u, 0);
		while (q.size() && ((int)flag0 + flag1 + flag2 + flag3 < 2))
		{
			auto now = q.front();
			q.pop();
			for (auto i : e[now.first])
			{
				if (!vis[i.first])
				{
					vis[i.first] = 1;
					q.emplace(i.first, now.second + i.second);
					switch (now.second + i.second)
					{
					case -2:
						flag0 = 1;
						break;
					case -1:
						flag1 = 1;
						break;
					case 1:
						flag2 = 1;
						break;
					case 2:
						flag3 = 1;
					}
				}
			}
		}
		queue<pair<int, int>> q1;
		swap(q1, q);
		q.emplace(u, 0);
		int k;
		if (flag0)
		{
			k = 3;
		}
		else if (flag3)
		{
			k = 1;
		}
		else if (flag1 && flag2)
		{
			k = 2;
		}
		else if (!flag1 && !flag2 && !flag3 && !flag0)
		{
			while (q.size())
			{
				auto now = q.front();
				q.pop();
				for (auto i : e[now.first])
				{
					if (w[i.first] == pair<int, int>{0, 0})
					{
						w[i.first] = {1,3};
						q.emplace(i.first, i.second + now.second);
					}
				}
			}
			return;
		}
		else
		{
			if (flag1)
			{
				k = 1;
			}
			else
			{
				k = 2;
			}
			while (q.size())
			{
				auto now = q.front();
				q.pop();
				for (auto i : e[now.first])
				{
					if (w[i.first] == pair<int, int>{0, 0})
					{
						w[i.first] = {now.second + i.second + k, now.second + i.second + k + 1};
						q.emplace(i.first, i.second + now.second);
					}
				}
			}
			return;
		}
		while (q.size())
		{
			auto now = q.front();
			q.pop();
			for (auto i : e[now.first])
			{
				if (!vis[i.first])
				{
					vis[i.first] = 1;
					q.emplace(i.first, now.second + i.second);
					w[i.first] = {now.second + i.second + k, now.second + i.second + k};
				}
			}
		}
	}

	int main()
	{
		int n;
		FastIO::read(n);
		for (int i = 1; i <= n; i++)
		{
			FastIO::read(s[i]);
		}
		int a, b;
		FastIO::read(a, b);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < s[i].size(); j++)
			{
				if (s[i][j] == '=')
				{
					e[i].emplace_back(j, 0);
					e[j].emplace_back(i, 0);
				}
				else if (s[i][j] == '+')
				{
					e[i].emplace_back(j, 1);
					e[j].emplace_back(i, -1);
				}
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
	very::main();
	FastIO::flush();
	return 0;
}