#include <bits/stdc++.h>
#pragma GCC target("abm,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO
{
	static constexpr int S = 1 << 21;
	char ibuf[S], obuf[S], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
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
		if (p3 - obuf == S)
			fwrite(obuf, 1, S, stdout), p3 = obuf;
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
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2)
#endif
using namespace std;
#define endl "\n"

int num[95], add[30], n;
char a[30], b[30], c[30];
bool used[30];

int check(int now)
{
	int tot=0;
	for (int i = 0; i < n; i = -~i)
	{

		if (num[a[i]] != -1 && num[b[i]] != -1 && num[c[i]] != -1)
		{
			if ((num[a[i]] + num[b[i]] + add[i]) % n != num[c[i]] && (num[a[i]] + num[b[i]] + 1) % n != num[c[i]])
			{
				return -1;
			}
			else if (i == now)
			{
				tot=3;
			}
		}
	}
	if(tot)return 3;
	if (num[a[now]] != -1)
	{
		tot = -~tot;
	}
	if (num[b[now]] != -1)
	{
		tot = -~tot;
	}
	if (num[c[now]] != -1)
	{
		tot = -~tot;
	}
	return tot;
}
void dfs(int now)
{
	if (now == n)
	{
		for (int i = 0; i < n; i = -~i)
		{
			printf("%d ", num['A' + i]);
		}
		exit(0);
	}
	int res = check(now);
	if (res == -1)
	{
		return;
	}
	else if (res == 3)
	{
		if (now == n - 1)
		{
			for (int i = 0; i < n; i = -~i)
			{
				printf("%d ", num['A' + i]);
			}
			exit(0);
		}
		else
		{
			add[now + 1] = (num[a[now]] + num[b[now]] + add[now]) / n;
			dfs(now + 1);
			add[now + 1] = 0;
		}
	}
	else if (res == 2)
	{
		if (num[a[now]] == -1)
		{
			num[a[now]] = ((num[c[now]] - num[b[now]] - add[now]) + n) % n;
			if (used[num[a[now]]])
			{
				num[a[now]] = -1;
			}
			else
			{
				used[num[a[now]]] = 1;
				add[now + 1] = (num[a[now]] + num[b[now]] + add[now]) / n;
				dfs(now + 1);
				add[now + 1] = used[num[a[now]]] = 0;
				num[a[now]] = -1;
			}
		}
		else if (num[b[now]] == -1)
		{
			num[b[now]] = ((num[c[now]] - num[a[now]] - add[now]) + n) % n;
			if (used[num[b[now]]])
			{
				num[b[now]] = -1;
			}
			else
			{
				used[num[b[now]]] = 1;
				add[now + 1] = (num[a[now]] + num[b[now]] + add[now]) / n;
				dfs(now + 1);
				add[now + 1] = used[num[b[now]]] = 0;
				num[b[now]] = -1;
			}
		}
		else
		{
			num[c[now]] = (num[a[now]] + num[b[now]] + add[now]) % n;
			if (used[num[c[now]]])
			{
				num[c[now]] = -1;
			}
			else
			{
				used[num[c[now]]] = 1;
				add[now + 1] = (num[a[now]] + num[b[now]] + add[now]) / n;
				dfs(now + 1);
				add[now + 1] = used[num[c[now]]] = 0;
				num[c[now]] = -1;
			}
		}
	}
	else
	{
		if (num[a[now]] == -1)
		{
			for (int i = 0; i <n; i = -~i)
			{
				if (!used[i])
				{
					used[i] = true;
					num[a[now]] = i;
					dfs(now);
					num[a[now]] = -1;
					used[i] = false;
				}
			}
		}
		else
		{
			for (int i = 0; i <n; i = -~i)
			{
				if (!used[i])
				{
					used[i] = true;
					num[b[now]] = i;
					dfs(now);
					num[b[now]] = -1;
					used[i] = false;
				}
			}
		}
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1092_3.in", "r", stdin);
	freopen("P1092.out", "w", stdout);
#endif
	read(n);
	// memset(num, -1, sizeof(num));
	fill(num, num + 95, -1);
	string A, B, C;
	read(A), read(B), read(C);
	for (int i = A.size() - 1; i >= 0; i = ~-i)
	{
		a[A.size() - i - 1] = A[i];
		b[A.size() - i - 1] = B[i];
		c[A.size() - i - 1] = C[i];
	}
	dfs(0);
	return 0;
}