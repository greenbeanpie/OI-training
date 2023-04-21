#include <bits/stdc++.h>
using namespace std;
#define int long long

int a_min[100005][21];

int rmq(int l, int r)
{ // op==0==>query mininum op==1==>query mininum
    int t = floor(log2(r - l + 1));
    return min(a_min[l][t], a_min[r - (1 << t) + 1][t]);
}
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
signed main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a_min[i][0] = read();
    }
    for (int j = 1; j <= 21; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            a_min[i][j] = min(a_min[i + (1 << (j - 1))][j - 1], a_min[i][j - 1]);
        }
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        printf("%lld\n", rmq(i, i + m-1));
    }
    return 0;
}