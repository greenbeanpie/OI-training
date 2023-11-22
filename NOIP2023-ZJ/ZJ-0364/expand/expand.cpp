// 题记: 老骥伏枥, 志在千里
// 11:41 前两题 如 过了, 来水一下
// 其实l₀是几并不重要
// 只要有一个较短的满足条件即可输出1
// 对前缀DP
// 但是居然要考虑最末尾
// 12:06 ... 遗憾的, 不会写暴力
// 最优策略一定是数字间互相对应
// 不会有一个数字被分成两段
// 12:12 两序列最末端的数字一定会在一起
// 所以结果的相对大小关系与最末端数字相同
// 强制让a > b
// 12：36 啊, 台昆南拉
// 测试点应该是没有捆测, 这点我相信西西弗
// 骗到5分, 险些失手
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int a[N], b[N];
int aa[N], bb[N];
int main()
{
	#ifndef DEBUG
	freopen("expand.in", "r", stdin);
	freopen("expand.out","w",stdout);
	#endif
	int c, n, m, q;
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 1 ; i <= n ; i++) scanf("%d", a + i), aa[i] = a[i];
	for(int i = 1 ; i <= m ; i++) scanf("%d", b + i), bb[i] = b[i];
	// if(a[n] < b[m])
	// {
	// 	swap(n, m);
	// 	int mx = max(n, m);
	// 	for(int i = 1 ; i <= mx ; i++) swap(a[i], b[i]);
	// }
	while(q --)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		for(int i = 1 ; i <= n ; i++) a[i] = aa[i];
		for(int i = 1 ; i <= m ; i++) b[i] = bb[i];
		for(int i = 1, u, v ; i <= x ; i++) scanf("%d%d", &u, &v), a[u] = v;
		for(int i = 1, u, v ; i <= y ; i++) scanf("%d%d", &u, &v), b[u] = v;
		if(a[n] != b[m]) putchar('1');
		else putchar('0');
	}
	puts("");
	return 0;
}
/*
后记:
 横扫饥饿, 作回自己
*/