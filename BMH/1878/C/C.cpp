#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#define int long long
using namespace std;
signed main()
{

    int k, n, s;
    cin >> k >> n >> s;
    int sum = 1;
    n %= s;
    if (n == s - 1)
    {
        cout << 1;
    }
    for (int i = 2; i <= n; i++)
    {
        sum *= k;
        sum %= s;
        if (sum == 0)
        {
            break;
        }
    }
    cout << sum;
    return 0;
}