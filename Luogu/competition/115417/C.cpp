#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k, t;
    cin >> n >> k >> t;
    int ori[n + 1], op[n + 1], temp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        ori[i] = i;
        cin >> op[i];
    }
    int tem;
    for (int i = 2; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tem;
            temp[j] = op[tem];
        }
        for (int j = 1; j <= n; j++)
        {
            op[j] = temp[j];
        }
    }
    while (k)
    {
        if (k & 1)
        {
            for (int j = 1; j <= n; j++)
            {
                temp[j] = ori[op[j]];
            }
            for (int j = 1; j <= n; j++)
            {
                ori[j] = temp[j];
            }
        }
        k >>= 1;
        for (int j = 1; j <= n; j++)
        {
            temp[j] = op[op[j]];
        }
        for (int j = 1; j <= n; j++)
        {
            op[j] = temp[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ori[i] << " ";
    }
    return 0;
}