#include <bits/stdc++.h>
using namespace std;
long long n, m, sum = 0;
long long a[100050];
bool check(int x)
{
    int ans = 0, q = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x < a[i])
            return 0;
        else if (ans <= x - a[i])
            ans += a[i];
        else
        {
            if (a[i] <= x)
                ans = a[i];
            else
                ans = 0;
            q++;
        }
    }
    q++;
    return q <= m;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("P1182.in", "r", stdin);
#endif
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int l = 1, r = sum;

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r;
    return 0;
}
