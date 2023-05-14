#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define map unordered_map
#define xhw sb
int n, num[30005];
int l1, l2, r1, lyhsb[30005], lyh2b[30005];

bool zhengque(int cha)
{
    int pre = lyh2b[l2];
    for (int i = l2 - 1;i >= 1;)
    {
        if (pre - lyh2b[i] == cha)
            pre = lyh2b[i], i--;
        else if (pre - lyhsb[r1] == cha)
            pre = lyhsb[r1], r1--;
        else
            return false;
    }
    return true;
}

bool solve(int st, int cha)
{
    l1 = l2 = 0;
    for (int i = 1;i < st;i++)
        lyh2b[++l2] = num[i];
    int now = num[st];
    for (int i = st;i <= n;i++)
        if (num[i] == now)
            lyhsb[++l1] = num[i], now += cha;
        else
            lyh2b[++l2] = num[i];
    if (l2 == 0)
    {
        return 1;
    }
    if (l2 == 1)
    {
        return true;
    }
    r1 = l1;
    if (zhengque(lyh2b[l2] - lyh2b[l2 - 1]))
    {
        return true;
    }
    r1 = l1;
    if (zhengque(lyh2b[l2] - lyhsb[l1]))
    {
        return true;
    }

    return false;
}

signed main()
{
    int t;
    cin >> t;
    for (int T = 0;T < t;T++) {
        cin >> n;
        for (int i = 1;i <= n;scanf("%lld", &num[i++]));
        if (solve(1, num[2] - num[1]) || solve(1, num[3] - num[1]) || solve(2, num[3] - num[2])) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    return 0;
}