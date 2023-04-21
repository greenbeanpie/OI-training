#include <bits/stdc++.h>
using namespace std;
#define MOD 100003
#define int long long
long long quickpower(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    if (a == 1)
    {
        return 1;
    }
    long long answer = 1;
    while (b)
    {
        if (b & 1)
        {
            answer = answer * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return answer;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P3197_2.in", "r", stdin);
#endif
    int n, m;
    cin >> m >> n;
    m %= MOD;
    n %= MOD;
    cout << (quickpower(m, n) - m * quickpower(m - 1, n - 1) % MOD + MOD) % MOD;
    return 0;
}