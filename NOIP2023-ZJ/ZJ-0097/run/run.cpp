#include <stdio.h>
using namespace std;
long long s[1003][1003], f[1003][1003];
int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    // Glorious Purpose --Loki
    int t, n, m, k, d;
    scanf("%d%d", &t, &t);
    while (t--)
    {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i(1); i <= n; ++i)
            for (int j(1); j <= i; ++j)
                s[i][j] = 0;
        while (m--)
        {
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            s[x][y] += v;
        }
        for (int i(1); i <= n; ++i)
            for (int j(0); j <= k; ++j)
                f[i][j] = -1e18;
        f[0][0] = 0;
        for (int i(1); i <= n; ++i)
        {
            long long t(0);
            for (int j(1); j <= k && j <= i; ++j)
            {
                t += s[i][j];
                if (f[i - 1][j - 1] + t - d > f[i][j])
                    f[i][j] = f[i - 1][j - 1] + t - d;
            }
            for (int j(0); j < i && j <= k; ++j)
                if (f[i - 1][j] > f[i][0])
                    f[i][0] = f[i - 1][j];
        }
        long long w(0);
        for (int i(0); i <= k && i <= n; ++i)
            if (f[n][i] > w)
                w = f[n][i];
        printf("%lld\n", w);
    }
    return 0;
}