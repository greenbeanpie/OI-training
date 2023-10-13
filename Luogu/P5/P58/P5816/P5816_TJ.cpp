#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	register int x = 0;
	register bool f = 0;
	register char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return f ? -x : x;
}
const int maxn = 100005;
const int inf = 1000000007;
int t[maxn << 4], n, m, lsh[maxn], sj[maxn], xj[maxn], nl, nr, res;
// lsh为离散数组，sj上界，xj下界，t线段树，nl为当前行最左点的x坐标
struct _node
{
	int x, y;
	friend bool operator<(_node aa, _node bb)
	{
		if (aa.y == bb.y)
			return aa.x < bb.x;
		return aa.y > bb.y;
	} // 在这边我排序的时候顺便以x为第二变量排了一下，方便下面的处理
} node[maxn];
void change(int o, int l, int r, int q, int v)
{
	t[o] += v;
	if (l == r)
		return;
	int mid = l + r >> 1;
	if (q <= mid)
		change(o << 1, l, mid, q, v);
	else
		change(o << 1 | 1, mid + 1, r, q, v);
} // 标准线段树修改操作
int query(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
		return t[o];
	int ans = 0, mid = l + r >> 1;
	if (ql <= mid)
		ans += query(o << 1, l, mid, ql, qr);
	if (qr > mid)
		ans += query(o << 1 | 1, mid + 1, r, ql, qr);
	return ans;
} // 标准线段树查询操作
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		node[i].x = read();
		node[i].y = read();
		lsh[i] = node[i].x;
		sj[i] = -inf;
		xj[i] = inf;
	}
	sort(node + 1, node + n + 1);
	sort(lsh + 1, lsh + n + 1);
	m = unique(lsh + 1, lsh + n + 1) - 1 - lsh;
	for (int i = 1; i <= n; i++)
	{
		node[i].x = lower_bound(lsh + 1, lsh + m + 1, node[i].x) - lsh;
		sj[node[i].x] = max(node[i].y, sj[node[i].x]);
		xj[node[i].x] = min(node[i].y, xj[node[i].x]);
	}
	nl = node[1].x;
	node[n + 1].y = inf;
	// 防止node[n].y=0的情况的影响
	for (int i = 1; i <= n; i++)
	{
		if (node[i].y == sj[node[i].x])
			change(1, 1, m, node[i].x, 1);
		if (node[i].y == xj[node[i].x])
		{
			res += 1;
			change(1, 1, m, node[i].x, -1);
		} // 我在删除的时候先把点加上，防止该点漏记
		if (node[i].y != node[i + 1].y)
		{
			res += query(1, 1, m, nl, node[i].x);
			nl = node[i + 1].x;
		} // 这一行结束，统计答案
	}
	printf("%d", res);
	return 0;
}