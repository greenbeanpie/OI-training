#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans = 1ll << 62, a[5];
// ans用来比较，a是运算数字
char c[4];	   // 这是符号
int dfs(int k) // 深度优先搜索
{
	if (k > 3)
		return 0;
	for (int i = 1; i <= 4; i++)
		for (int j = i + 1; j <= 4; j++)
		{
			if (i != j && a[i] != -1 && a[j] != -1)
			{
				// 即是否被选或运算两数是否是一个数
				ll s = a[i], t = a[j]; // 保存，后面回溯。
				a[i] = -1;
				if (c[k] == '+')
					a[j] = s + t;
				if (c[k] == '*')
					a[j] = s * t; // 按提议模拟
				if (k == 3 && a[j] < ans)
					ans = a[j]; // 比较答案
				dfs(k + 1);
				a[i] = s, a[j] = t; // 这是回溯
			}
		}
}
int main()
{
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	cin >> c[1] >> c[2] >> c[3];
	dfs(1);
	cout << ans; // 输入，solve，输出
	return 0;
}