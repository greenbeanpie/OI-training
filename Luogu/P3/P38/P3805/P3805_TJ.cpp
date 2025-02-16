#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 11000002;
char dat[maxn << 1];
int p[maxn << 1], cnt, ans;
inline void qr()
{
	char c = getchar();
	dat[0] = '~', dat[cnt = 1] = '|';
	while (c < 'a' || c > 'z')
		c = getchar();
	while (c >= 'a' && c <= 'z')
		dat[++cnt] = c, dat[++cnt] = '|', c = getchar();
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P3805.in", "r", stdin);
	freopen("P3805_TJ.out", "w", stdout);
#endif
	qr();
	for (int t = 1, r = 0, mid = 0; t <= cnt; ++t)
	{
		if (t <= r)
			p[t] = min(p[(mid << 1) - t], r - t + 1);
		while (dat[t - p[t]] == dat[t + p[t]])
			++p[t];
		// 暴力拓展左右两侧,当t-p[t]==0时，由于data[0]是'~'，自动停止。故不会下标溢出。
		// 假若我这里成功暴力扩展了，就意味着到时候r会单调递增，所以manacher是线性的。
		if (p[t] + t > r)
			r = p[t] + t - 1, mid = t;
		// 更新mid和r,保持r是最右的才能保证我们提前确定的部分回文半径尽量多。
		if (p[t] > ans)
			ans = p[t];
	}
	printf("%d\n", ans - 1);
	return 0;
}
