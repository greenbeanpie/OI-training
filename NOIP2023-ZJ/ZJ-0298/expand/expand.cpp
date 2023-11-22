#include <iostream>
#include <cstring>
#include <cstdio>
#define N 500005

using namespace std;

int ans[N];
int opX[N];
int opY[N];
int X[N];
int Y[N];

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, n, m, q;
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &opX[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &opY[i]);
    for (int i = 0; i <= q; i++)
    {
        for (int i = 1; i <= n; i++) X[i] = opX[i];
        for (int i = 1; i <= m; i++) Y[i] = opY[i];
        if (i == 0) goto start;
        int kx, ky;
        scanf("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; i++)
        {
            int p, v;
            scanf("%d%d", &p, &v);
            X[p] = v;
        }
        for (int i = 1; i <= ky; i++)
        {
            int p, v;
            scanf("%d%d", &p, &v);
            Y[p] = v;
        }
        start:
        if (c == 1 || (n == 1 && m == 1)) ans[i] = 1;
        else if (c == 2)
        {
            if (n == 2 && m == 2)
            {
                if ((X[1] - Y[1]) > 0 && (X[1] - Y[2]) > 0 && (X[2] - Y[1]) > 0 && (X[2] - Y[2]) > 0) ans[i] = 2;
                else if ((X[1] - Y[1]) < 0 && (X[1] - Y[2]) < 0 && (X[2] - Y[1]) < 0 && (X[2] - Y[2]) < 0) ans[i] = 2;
                else ans[i] = 0;
            }
            if (n == 2 && m == 2)
            {
                if ((X[1] - Y[1]) > 0 && (X[1] - Y[2]) > 0) ans[i] = 2;
                else if ((X[1] - Y[1]) < 0 && (X[1] - Y[2]) < 0) ans[i] = 2;
                else ans[i] = 0;
            }
            if (n == 2 && m == 2)
            {
                if ((X[1] - Y[1]) > 0 && (X[2] - Y[1]) > 0) ans[i] = 2;
                else if ((X[1] - Y[1]) < 0 && (X[2] - Y[1]) < 0) ans[i] = 2;
                else ans[i] = 0;
            }
        }
        else
        {
            int maxX = 0, maxY = 0;
            for (int i = 1; i <= n; i++) maxX = max(maxX, X[i]);
            for (int i = 1; i <= m; i++) maxY = max(maxY, Y[i]);
            if (maxX > maxY && X[1] > Y[1] && X[n] > Y[n])
            {
                ans[i] = 1;
            }
            else if (maxX < maxY && X[1] < Y[1] && X[n] < Y[n])
            {
                ans[i] = 1;
            }
            else ans[i] = 0;
        }
    }
    for (int i = 0; i <= q; i++) printf("%d", ans[i]);
    return 0;
}