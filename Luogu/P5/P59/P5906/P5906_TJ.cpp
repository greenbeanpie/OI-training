#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x)
{
	char c = getchar();
	bool f = 0;
	x = 0;
	while (!isdigit(c))
	{
		f |= c == '-', c = getchar();
	}
	while (isdigit(c))
	{
		x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	}
	if (f)
	{
		x = -x;
	}
	return x;
}
template <class t>
inline void write(t x)
{
	if (x < 0)
		putchar('-'), write(-x);
	else
	{
		if (x > 9)
		{
			write(x / 10);
		}
		putchar('0' + x % 10);
	}
}

const int N =1005;
int un, n, m, a[N], ANS[N], ma[N], b[N], bn, num[N], st[N], cn, clear[N];
// 变量的解释下面的代码中都有哦！！！
struct que
{
	int l, r, i;
	inline bool operator<(const que &nt) const
	{
		return (b[l] ^ b[nt.l]) ? b[l] < b[nt.l] : r < nt.r; // 先按左边界所在块排，相同时再按右边界排
	}
} q[N];

inline int max(const int &x, const int &y)
{
	return x > y ? x : y;
}

int calc(int l, int r)
{ // 暴力扫一遍
	int last[N], res = 0;
	for (int i = l; i <= r; i++)
	{
		last[a[i]] = 0;
	} // 记录每个数最早出现的位置
	for (int i = l; i <= r; i++)
		if (!last[a[i]])
		{
			last[a[i]] = i;
		}
		else
		{
			res = max(res, i - last[a[i]]);
		}
	return res;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P5906.in", "r", stdin);
	freopen("P5906.out", "w", stdout);
#endif
	read(n);
	int len = sqrt(n); // 块长
	for (int i = 1; i <= n; i++)
	{
		num[i] = read(a[i]), b[i] = (i - 1) / len + 1;
	}		   // b记录每个下标是在哪个块中的
	bn = b[n]; // 块数
	sort(num + 1, num + 1 + n);
	un = unique(num + 1, num + 1 + n) - num - 1;
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(num + 1, num + 1 + un, a[i]) - num;
	} // 正常的离散操作
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(q[i].l);
		read(q[i].r);
		q[i].i = i;
	}
	sort(q + 1, q + 1 + m); // 询问排序
	for (int i = 1, j = 1; j <= bn; j++)
	{															  // i枚举询问,j枚举询问的左边界所在块
		int br = min(n, j * len), l = br + 1, r = l - 1, ans = 0; // br是当前块的右边界
		cn = 0;													  // 清空记录数组的指针
		for (; b[q[i].l] == j; i++)
		{ // 枚举当前块内的询问
			if (b[q[i].r] == j)
			{ // 如果左右边界都在同一块内内就暴力做
				ANS[q[i].i] = calc(q[i].l, q[i].r);
				continue;
			}
			while (r < q[i].r)
			{
				r++;
				ma[a[r]] = r; // 最后出现的位置
				if (!st[a[r]])
				{
					st[a[r]] = r, clear[++cn] = a[r];
				}							  // st是最早出现的位置，clear是出现过的数字，用来清空数字最后出现的位置
				ans = max(ans, r - st[a[r]]); // 情况2
			}
			int tp = ans; // 先保存一下，因为右区间的贡献不会被刷新，但左区间的会
			while (l > q[i].l)
			{
				l--;
				if (ma[a[l]])
				{
					ans = max(ans, ma[a[l]] - l);
				}
				else
				{
					ma[a[l]] = l;
				} // 最后出现的位置可能在左区间中
			}
			ANS[q[i].i] = ans;
			while (l <= br)
			{
				if (ma[a[l]] == l)
				{
					ma[a[l]] = 0;
				} // 去掉左区间的贡献
				l++;
			}
			ans = tp; // 去掉当前左区间的贡献
		}
		for (int i = 1; i <= cn; i++)
		{
			ma[clear[i]] = st[clear[i]] = 0;
		} // 根据记录数组清空每个数出现位置的各种信息
	}
	for (int i = 1; i <= m; i++)
	{
		write(ANS[i]), puts("");
	}
}
