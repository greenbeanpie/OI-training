#include <bits/stdc++.h>

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

const int N = 1e5, M = 1e6;
int n, m, s, t, tot = 1;
int head[N], dep[N], depcnt[N], left[N];
std::bitset<N> inque;
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
std::queue<int> q;
#ifndef ONLINE_JUDGE
std::priority_queue<int, std::vector<int>, cmp> pq;
#else
#include <bits/extc++.h>
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
	std::swap(u, v);
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
	while (q.size())
	{
		auto now = q.front();
		q.pop();
		inque[now] = 0;
		for (auto i = head[now]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (e[i ^ 1].val && dep[v] > dep[now] + 1)
			{
				dep[v] = dep[now] + 1;
				if (!inque[v])
				{
					q.push(v);
					inque[v] = 1;
				}
			}
		}
	}
	return dep[s] == INT_MAX;
}
void push(int u)
{
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (e[i].val && dep[v] + 1 == dep[u])
		{
			int temp = std::min(e[i].val, left[u]);
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
			{
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
}
int HLPP()
{
	if (bfs())
	{
		return 0;
	}
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
			{
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

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("P2756.in","r",stdin);
// 	freopen("P2756.out","w",stdout);
// #endif
	int m;
	FastIO::read(n, m);
	s = 0, t = n + 1;
	for (int i = 1; i <= m; i++)
	{
		add_edge(0, i, 1);
	}
	for (int u, v; n != -1; m++)
	{
		FastIO::read(u, v);
		add_edge(u, v, INT_MAX);
	}
	for (int i = n - m + 1; i <= n; i++)
	{
		add_edge(i, t, 1);
	}
	HLPP();
	if(left[n]==0){
		FastIO::writeln("No Solution!");
		return 0;
	}
	// FastIO::writeln();
	// for (int i = 2; i <= (n << 1);i++){
	// 	if(e[i].val){
	// 		++cnt;
	// 	}
	// }
	// FastIO::writeln(cnt);
	return 0;
}