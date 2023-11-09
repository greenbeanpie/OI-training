// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 500007
#define reg register
using namespace std;

struct query
{
	int l, r, id;
} q[N];

int a[N], cnt[N], pos[N], be[N];
int stk[N], ans[N];
int n, m, top, unit;

inline void read(int &x);
void print(int x);
inline bool cmp(query x, query y);
inline void add(int t);
inline void del(int t);
inline char gc();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in", "r", stdin);
	freopen("F_TJ.out", "w", stdout);
#endif
	int l, r;
	read(n);
	unit = sqrt(n);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
		be[i] = i / unit + 1;
	}
	read(m);
	for (int i = 1; i <= m; ++i)
	{
		read(q[i].l), read(q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + 1 + m, cmp);
	l = r = 1;
	add(a[1]);
	for (int i = 1; i <= m; ++i)
	{
		while (r < q[i].r)
			add(a[++r]);
		while (r > q[i].r)
			del(a[r--]);
		while (l < q[i].l)
			del(a[l++]);
		while (l > q[i].l)
			add(a[--l]);
		ans[q[i].id] = stk[top];
	}
	for (int i = 1; i <= m; ++i)
	{
		print(ans[i]);
		putchar('\n');
	}
	return 0;
}

inline char gc()
{
	static char buf[100000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline void add(int t)
{
	++cnt[t];
	if (cnt[t] == 1)
	{
		stk[++top] = t; // 放到栈顶
		pos[t] = top;	// 更新栈顶元素所在位置
	}
	else if (cnt[t] == 2)
	{
		stk[pos[t]] = stk[top];	 // 栈顶元素替换t的位置
		pos[stk[top]] = pos[t];	 // 把位置更新一下
		stk[top--] = pos[t] = 0; // 原来的地方要清0
	}
}

inline void del(int t)
{
	--cnt[t];
	if (cnt[t] == 1)
	{
		stk[++top] = t;
		pos[t] = top;
	}
	else if (!cnt[t])
	{
		stk[pos[t]] = stk[top];
		pos[stk[top]] = pos[t];
		stk[top--] = pos[t] = 0;
	}
}

inline bool cmp(query a, query b)
{
	return (be[a.l] ^ be[b.l]) ? a.l < b.l : ((be[a.l] & 1) ? a.r < b.r : a.r > b.r); // 传说中的奇偶排序优化
}

inline void read(int &x)
{
	x = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = gc();
	}
}

void print(int x)
{
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}
