#include <stdio.h>
int n, m, a[500005], b[500005], kx[500005][3], ky[500005][3];
bool askbig()
{
    int i(2), j(2), t(0);
    if (a[1] <= b[1] || a[n] <= b[m])
        return false;
    while (i <= n || j <= m)
    {
        if (++t > n + m + 1)
            return false;
        if (i > n)
        {
            while (j <= m)
                if (a[n] <= b[j])
                    return false;
                else
                    ++j;
            return true;
        }
        if (j > m)
        {
            while (i <= n)
                if (a[i] <= b[m])
                    return false;
                else
                    ++i;
            return true;
        }
        while (a[i] > b[j - 1] && i <= n)
            ++i;
        while (b[j] < a[i - 1] && j <= m)
            ++j;
        while (i <= n && j <= m && a[i] > b[j])
            ++i, ++j;
    }
    return i > n && j > m;
}
bool asksmall()
{
    int i(2), j(2), t(0);
    if (a[1] >= b[1] || a[n] >= b[m])
        return false;
    while (i <= n || j <= m)
    {
        if (++t > n + m + 1)
            return false;
        if (i > n)
        {
            while (j <= m)
                if (a[n] >= b[j])
                    return false;
                else
                    ++j;
            return true;
        }
        if (j > m)
        {
            while (i <= n)
                if (a[i] >= b[m])
                    return false;
                else
                    ++i;
            return true;
        }
        while (a[i] < b[j - 1] && i <= n)
            ++i;
        while (b[j] > a[i - 1] && j <= m)
            ++j;
        while (i <= n && j <= m && a[i] < b[j])
            ++i, ++j;
    }
    return i > n && j > m;
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    // Glorious Purpose
    int q;
    scanf("%d%d%d%d", &n, &n, &m, &q);
    for (int i(1); i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i(1); i <= m; ++i)
        scanf("%d", &b[i]);
    putchar(askbig() | asksmall() ? '1' : '0');
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        for (int i(1); i <= x; ++i)
            scanf("%d%d", &kx[i][0], &kx[i][1]), kx[i][2] = a[kx[i][0]], a[kx[i][0]] = kx[i][1];
        for (int i(1); i <= y; ++i)
            scanf("%d%d", &ky[i][0], &ky[i][1]), ky[i][2] = b[ky[i][0]], b[ky[i][0]] = ky[i][1];
        putchar(askbig() | asksmall() ? '1' : '0');
        for (int i(1); i <= x; ++i)
            a[kx[i][0]] = kx[i][2];
        for (int i(1); i <= y; ++i)
            b[ky[i][0]] = ky[i][2];
    }
    return 0;
}