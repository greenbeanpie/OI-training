#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int __int128
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
// #define const constexpr

namespace P4722
{

	const int N = 1e5, M = 1e6;
	int n /* 点数 */, m /* 边数 */, s /* 源点 */, t /* 汇点 */, tot = 1 /* 总边数/当前已建边数 */;
	int head[N] /* 前向星 */, dep[N] /* 对应点深度 */, depcnt[N] /* 对应深度点数 */, left[N] /* 节点余流 */;
	bitset<N> inque; /* 是否在队列中 */
	struct node
	{
		int to, val, nxt;
	} e[M];
	struct cmp
	{
		bool operator()(const int &a, const int b)
		{
			return dep[a] < dep[b];
		}
	};
	queue<int> q;
#ifdef CODESPACE
	std::priority_queue<int, vector<int>, cmp> pq;
#else
	__gnu_pbds::priority_queue<int, cmp> pq;
#endif
	void add_edge(int u, int v, int w)
	{
		++tot;
		e[tot].nxt = head[u];
		head[u] = tot;
		e[tot].to = v;
		e[tot].val = w;
		++tot;
		swap(u, v);
		e[tot].nxt = head[u];
		head[u] = tot;
		e[tot].val = 0;
		e[tot].to = v;
	}
	bool bfs()
	{
		memset(dep, 0x3f3f3f, sizeof(dep));
		dep[t] = 0;
		q.push(t);
		inque[t] = 1;
		while (q.size()) // 标高度
		{
			auto now = q.front();
			q.pop();
			inque[now] = 0;
			for (auto i = head[now]; i; i = e[i].nxt)
			{
				int v = e[i].to;
				if (e[i ^ 1].val && dep[v] > dep[now] + 1)
				{ // 跑反向边
					dep[v] = dep[now] + 1;
					if (!inque[v])
					{
						q.push(v);
						inque[v] = 1;
					}
				}
			}
		}
		return dep[s] == INT_MAX; // 判断能否到达
	}
	void push(int u)
	{
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (e[i].val && dep[v] + 1 == dep[u])
			{
				int temp = min(e[i].val, left[u]);
				e[i].val -= temp;
				e[i ^ 1].val += temp;
				left[u] -= temp;
				left[v] += temp;
				if (!inque[v] && v != t && v != s)
				{
					pq.push(v);
					inque[v] = 1;
				}
				if (!left[u])
				{ // 已经没有多余的流量可以推了
					break;
				}
			}
		}
	}
	void relabel(int u)
	{
		dep[u] = 0x3f3f3f;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (e[i].val && dep[v] + 1 < dep[u])
			{
				dep[u] = dep[v] + 1;
			}
		}
	} // 将u的节点高度改为和u最近的最低点+1
	int HLPP()
	{
		if (bfs())
		{
			return 0;
		}
		// inque.reset();
		dep[s] = n;
		for (int i = 1; i <= n; i++)
		{
			if (dep[i] <= N)
			{
				++depcnt[dep[i]];
			}
		}
		for (int i = head[s]; i; i = e[i].nxt)
		{
			int v = e[i].to, val = e[i].val;
			if (val)
			{
				left[s] -= val;
				left[v] += val;
				e[i].val -= val;
				e[i ^ 1].val += val;
				// cerr << inque[v] << " ";
				if (!inque[v] && v != s && v != t)
				{
					pq.push(v);
					inque[v] = 1;
				}
			}
		}
		while (pq.size())
		{
			auto u = pq.top();
			pq.pop();
			inque[u] = 0;
			push(u);
			if (left[u] && dep[u] <= N)
			{
				--depcnt[dep[u]];
				if (depcnt[dep[u]] == 0)
				{ // 重标高度
					for (int i = 1; i <= n; i++)
					{
						if (i != s && i != t && dep[i] > dep[u] && dep[i] <= n)
						{
							dep[i] = n + 1;
						}
					}
				}
				relabel(u);
				++depcnt[dep[u]];
				pq.push(u);
				inque[u] = 1;
			}
		}
		return left[t];
	}
	int main()
	{
		FastIO::read(n, m, s, t);
		for (int i = 1, u, v, val; i <= m; i++)
		{
			FastIO::read(u, v, val);
			add_edge(u, v, val);
		}
		FastIO::writeln(HLPP());
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P4722");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P4722::main();
	FastIO::flush();
	return 0;
}
