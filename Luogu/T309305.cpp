#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("T309305.in", "r", stdin);
#endif
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l, r, x, y, m;
    for (int k = 0; k < q; k++)
    {
        cin >> l >> r >> x >> y >> m;
        int cnt = 0;
        x %= m;
        y %= m;
        if (x < y)
        {
            for (int i = l - 1; i < r; i++)
            {
                int temp = a[i] % m;
                if (temp + x >= m || temp + y < m)
                {
                    cnt++;
                }
            }
        }
        else if (x > y)
        {
            for (int i = l - 1; i < r; i++)
            {
                int temp = a[i] % m;
                if (temp + x >= m && temp + y < m)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}