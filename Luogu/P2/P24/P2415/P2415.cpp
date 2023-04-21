#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P2415.in", "r", stdin);
#endif
    int cnt = 0, sum = 0;
    int t;
    while (cin >> t)
    {
        sum += t;
        cnt++;
    }
    cout << sum * pow(2, cnt - 1);
    return 0;
}