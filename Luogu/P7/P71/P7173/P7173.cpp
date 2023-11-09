#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
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

namespace P7173
{
	const int N = 5e3, M = 5e4;
	struct node
	{
		int to, val, weight;
		int nxt;
	} e[M << 1];
	int head[N], dis[N], n, m, s, t, maxflow, mincost, curflow[N], last[N], supers, supert /* 字面意思(确信) */, prework[N];
	bitset<N> vis;
	void addedge(int u, int v, int val, int w)
	{
		static int tot = 1;
		e[++tot].nxt = head[u];
		e[tot].to = v;
		e[tot].weight = w;
		e[tot].val = val;
		head[u] = tot;
		e[++tot].nxt = head[v];
		e[tot].to = u;
		e[tot].weight = -w;
		e[tot].val = 0;
		head[v] = tot;
	}

	bool spfa(int s, int t)
	{
		queue<int> q;
		fill(dis, dis + N - 5, INT_MAX);
		vis.reset();
		q.push(s);
		dis[s] = 0;
		vis[s] = 1;
		curflow[s] = INT_MAX;
		while (q.size())
		{
			int u = q.front();
			vis[u] = 0;
			q.pop();
			for (auto i = head[u]; i; i = e[i].nxt)
			{
				if (!e[i].val)
				{
					continue;
				}
				int v = e[i].to;
				if (dis[v] > dis[u] + e[i].weight)
				{
					dis[v] = dis[u] + e[i].weight;
					curflow[v] = min(curflow[u], e[i].val);
					last[v] = i;
					if (!vis[v])
					{
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
		return dis[t] == INT_MAX;
	}
	void MCMF(int s, int t)
	{ // Mininum Cost Maxinum Flow
		while (!spfa(s, t))
		{
			int cur = t;
			maxflow += curflow[t];
			mincost += dis[t] * curflow[t];
			int temp;
			while (cur != s)
			{
				temp = last[cur];
				e[temp].val -= curflow[t];
				e[temp ^ 1].val += curflow[t];
				cur = e[temp ^ 1].to;
			}
		}
	}
	auto main()
	{
		FastIO::read(n, m, s, t);
		for (int i = 1, u, v, val, w; i <= m; i++)
		{
			FastIO::read(u, v, val, w);
			if (w >= 0)
			{
				addedge(u, v, val, w);
			} // 正权边正常加边
			else
			{
				addedge(v, u, val, -w);
				prework[u] -= val, prework[v] += val;
				mincost += val * w;
			} // 负权边预先满流
		}
		supers = n + 1, supert = n + 2;

		for (int i = 1; i <= n; i++)
		{
			if (prework[i] > 0)
			{
				addedge(supers, i, prework[i], 0);
			}
			else if (prework[i] < 0)
			{
				addedge(i, supert, -prework[i], 0);
			}
		} // 使用虚拟源点/汇点维护流守恒性
		addedge(t, s, INT_MAX, 0);
		MCMF(supers, supert);
		maxflow = 0;
		MCMF(s, t);
		FastIO::writesp(maxflow, mincost);
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P7173");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P7173::main();
	FastIO::flush();
	return 0;
}