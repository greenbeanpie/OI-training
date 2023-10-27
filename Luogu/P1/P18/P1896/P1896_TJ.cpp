#include <iostream>
#include <cstdio>
using namespace std;
int n, k, num;
long long cnt[2000], ok[2000];
// cnt[i]:第i种状态的二进制中有几个1
// ok[i]:第i个行内不相矛盾(满足条件2:左右国王不相邻)的状态是多少
long long dp[10][100][2000];
// dp[i][j][s]:我们已经放了i行,用了j个国王,第i行的状态为s的方案数
int main()
{
	cin >> n >> k;					   // n*n的棋盘上放k个国王
	for (int s = 0; s < (1 << n); s++) // 枚举所有可能状态
	{
		int tot = 0, s1 = s; // tot:二进制下有多少个1;
		while (s1)			 // 一位一位枚举,直至为0(做法类似于快速幂那样)
		{
			if (s1 & 1)
				tot++; // 如果最后一位是1,tot++
			s1 >>= 1;  // 右移看下一位
		}
		cnt[s] = tot; // 预处理这个二进制数有多少个1
		if ((((s << 1) | (s >> 1)) & s) == 0)
			ok[++num] = s; // 如果这一状态向左向右都没有重复的话,说明左右不相邻,合法
	}
	dp[0][0][0] = 1;			 // 第0行一个也不放的方案数
	for (int i = 1; i <= n; i++) // 枚举我们已经放到了第几行
	{
		for (int l = 1; l <= num; l++) // 枚举第i行的状态,这里我们直接枚举所有满足条件2的状态,算是个优化吧
		{
			int s1 = ok[l];
			for (int r = 1; r <= num; r++) // 枚举上一行的状态
			{
				int s2 = ok[r];
				if (((s2 | (s2 << 1) | (s2 >> 1)) & s1) == 0) // 如果上下,左下右上,左上右下方向都不相邻,合法
				{
					for (int j = 0; j <= k; j++) // 枚举国王个数
						if (j - cnt[s1] >= 0)
							dp[i][j][s1] += dp[i - 1][j - cnt[s1]][s2]; // 状态转移方程
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= num; i++)
		ans += dp[n][k][ok[i]]; // 枚举第n行所有可能的情况,统计答案
	printf("%lld\n", ans);		// 输出
	return 0;
}