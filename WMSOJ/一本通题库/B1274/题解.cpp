#include <bits/stdc++.h>
using namespace std;
#define N 305
int f[N][N], a[N], s[N][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("B1274.in", "r", stdin);
#endif
    memset(f, 0x3f, sizeof(f)); // 求最小值，所以初始化无穷大
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        f[i][i] = 0;                  // 自己到自己代价肯定是0啊
        s[1][i] = s[1][i - 1] + a[i]; // 用前缀和快速算质量和，区间[j,i]的和为区间[1,i]的和减去区间[1,j-1]的和
        for (int j = 2; j <= i; j++)
        {
            s[j][i] = s[1][i] - s[1][j - 1];
        }
    }
    for (int i = 2; i <= n; i++) // 枚举当前区间长度
    {
        for (int j = 1; j + i - 1 <= n; j++) // j为左端点，则右端点为j+i-1，注意要减1，因为第j个也是算在区间内的
        {
            int e = j + i - 1;          // 存一下右端点
            for (int k = j; k < e; k++) // 枚举区间的分界点，把区间[j,k]和区间[k+1,e]合并，k是到e-1，因为分界点两边的区间长度都必须要>=1，不然会出现区间[e,e]长度为0的情况，和空气合并就没意义了
            {
                f[j][e] = min(f[j][e], f[j][k] + s[j][k] + f[k + 1][e] + s[k + 1][e]);
                // 状态转移方程，f[j][k]表示合并成为左区间的最小代价
                // f[k+1][e]表示合并成为右区间的最小代价，
                // s[j][k]表示左区间的质量和，s[k+1][e]表示右区间质量和；
                // 即，f[j][k]+f[k+1][e]为得到左右两个区间所需要花费的最小代价，
                // s[j][k]+s[k+1][e]为合并左右两个区间所需要花费的代价，
                // 两者加起来就是得到区间[j,e]花费的代价，然后和原方案取min
            }
        }
    }
    printf("%d\n", f[1][n]); // 最后输出得到区间[1,n]的最小花费代价
    return 0;
}