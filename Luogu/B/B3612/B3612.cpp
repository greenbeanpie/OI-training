#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("B3612.in","r",stdin);
        freopen("B3612.out","w",stdout);
    #endif
    int n;
    cin >> n;
    int a[n + 1], sum[n + 1];
    a[0] = sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}