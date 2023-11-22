#include <stdio.h>
#include <algorithm>
char c[3003];
int a[3003], b[3003];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    // Glorious Purpose -- Loki
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i(1); i <= n; ++i)
    {
        scanf("%s", c + 1);
        for (int j(1); j <= m; ++j)
        {
            if (!a[i] || c[j] - 96 < a[i])
                a[i] = c[j] - 96;
            if (!b[i] || c[j] - 96 > b[i])
                b[i] = c[j] - 96;
        }
    }
    for (int i(1); i <= n; ++i)
    {
        bool f(true);
        for (int j(1); j <= n; ++j)
            if (i ^ j)
                if (a[i] >= b[j])
                    f = false;
        putchar(f ? '1' : '0');
    }
    putchar('\n');
    return 0;
}