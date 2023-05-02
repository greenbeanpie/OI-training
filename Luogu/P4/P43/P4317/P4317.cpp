/*#include <bits/stdc++.h>
using namespace std;
#define int long long

int work(int n);
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P4317.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << work(n);

    return 0;
}
int work(int n)
{
    int ans;
    int t = floor(log2(n+1));
    int dp[64];
    dp[0] = 1;
    for (int i = 1; i < t; i++)
    {
        dp[i] = dp[i - 1] * t + (1 << t);
    }
    return ans;
}*/