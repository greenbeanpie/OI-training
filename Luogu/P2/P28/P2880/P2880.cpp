#include <bits/stdc++.h>
using namespace std;
#define int long long

int a_max[50005][17], a_min[50005][17];

int rmq(bool op, int l, int r)
{ // op==0==>query maxinum op==1==>query mininum
    int t = floor(log2(r - l + 1));
    if (op == 0)
    {
        return max(a_max[l][t], a_max[r - (1 << t) + 1][t]);
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
            a_max[i][j] = max(a_max[i + (1 << (j - 1))][j - 1], a_max[i][j - 1]);
            a_min[i][j] = min(a_min[i + (1 << (j - 1))][j - 1], a_min[i][j - 1]);
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