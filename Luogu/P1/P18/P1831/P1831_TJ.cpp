#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
const int N = 20;
int a[N];										  // 储存每一位的大小
LL dp[N][N][2500], l, r;						  // dp[i][j][k]表示考虑i位数字，支点为j，力矩和为k
LL dfs(int pos, int point, int state, bool limit) // pos是几位数字；ponit是支点；state是力矩；limit表示当前这一位有无大小限制，防止枚举超过上限
{
	if (pos == 0)
		return state == 0; // 判断是否合法
	if (state < 0)
		return 0; // 当前力矩为负
	if (!limit && dp[pos][point][state] != -1)
		return dp[pos][point][state];
	int up = limit ? a[pos] : 9; // 数位上限
	LL tmp = 0;
	for (int i = 0; i <= up; i++)
		tmp += dfs(pos - 1, point, state + i * (pos - point), limit && (i == up));
	if (!limit)
		dp[pos][point][state] = tmp;
	return tmp;
}
LL solve(LL x)
{
	int len = 0;
	while (x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	LL ans = 0;
	for (int i = 1; i <= len; i++)
		ans += dfs(len, i, 0, 1);
	return ans - len + 1; // 每次dfs都会重复搜索到00000……的情况这里减去重复数
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P1831.in", "r", stdin);
	freopen("P1831_TJ.out", "w", stdout);
#endif
	scanf("%lld %lld", &l, &r);
	memset(dp, -1, sizeof(dp));
	printf("%lld", solve(r) - solve(l - 1));
	return 0;
}
