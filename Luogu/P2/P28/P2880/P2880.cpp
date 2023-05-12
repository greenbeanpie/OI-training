#include <bits/stdc++.h>
using namespace std;
#define int long long

int a_max[50005][17], a_min[50005][17];

int rmq(bool op, int l, int r)// ST表使用了倍增思想，目的是使用两个长度为2^n(n∈N)的区间覆盖整个查询区间，预处理时间复杂度O(nlog2n)，查询时间复杂度O(1)
{ // op==0==>query maxinum op==1==>query mininum
    int t = floor(log2(r - l + 1));// 计算n为多少时可以正好覆盖区间
    if (op == 0)
    {
        return max(a_max[l][t], a_max[r - (1 << t) + 1][t]);// 对于区间使右边的长度为2^n的部分和左边的2^n部分正好可以覆盖整个区间，此时查询既不会有遗漏也不会有溢出
    }
    else
    {
        return min(a_min[l][t], a_min[r - (1 << t) + 1][t]);
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P2880.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a_max[i][0];
        a_min[i][0] = a_max[i][0];
    }
    for (int j = 1; j <17; j++)
    {
        for (int i = 1; i+(1<<j)-1<=n; i++)
        {
            a_max[i][j] = max(a_max[i + (1 << (j - 1))][j - 1], a_max[i][j - 1]);// 对于i + (1 << (j - 1))~i+(1<<j)和i~i + (1 << (j - 1))两个区间的最大值取较大值
            a_min[i][j] = min(a_min[i + (1 << (j - 1))][j - 1], a_min[i][j - 1]);// 同理
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << rmq(0, l, r) - rmq(1, l, r) << endl;
    }
    return 0;
}