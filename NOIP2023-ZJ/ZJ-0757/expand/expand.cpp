#include <bits/stdc++.h>
using namespace std;
int c, n, m, q;
int x[1000005], y[1000005];
int xs[1000005], ys[1000005];
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &xs[i]);
        x[i] = xs[i];
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &ys[i]);
        y[i] = ys[i];
    }
    for (int i = 0; i <= q; i++)
    {
        bool flag = 1;
        if (x[0] == y[0])
        {
            printf("0");
        }
        else if (x[0] < y[0])
        {
            int xt = 0, yt = 0;
            while (xt < n)
            {
                if (x[xt] >= y[yt] && yt == m - 1)
                {
                    flag = 0;
                    break;
                }
                while (x[xt] >= y[yt] && xt >= 0)
                {
                    xt--;
                }
                if (xt < 0)
                {
                    flag = 0;
                    break;
                }
                xt++;
                if (yt < m-1)
                {
                    yt++;
                }
            }
            if (flag)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        else if (x[0] > y[0])
        {
            int xt = 0, yt = 0;
            while (xt < n)
            {
                if (x[xt] <= y[yt] && yt == m - 1)
                {
                    flag = 0;
                    break;
                }
                while (x[xt] <= y[yt] && xt >= 0)
                {
                    xt--;
                }
                if (xt < 0)
                {
                    flag = 0;
                    break;
                }
                xt++;
                if (yt < m-1)
                {
                    yt++;    
                }
            }
            if (flag)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        // printf("\n__________\n");
        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d ", x[j]);
        // }
        // printf("\n");
        // for (int j = 0; j < m; j++)
        // {
        //     printf("%d ", y[j]);
        // }
        // printf("\n__________\n");
        if (i == q)
        {
            break;
        }
        for (int j = 0; j < n; j++)
        {
            x[j] = xs[j];
        }
        for (int j = 0; j < m; j++)
        {
            y[j] = ys[j];
        }
        int qqx, qqy;
        scanf("%d%d", &qqx, &qqy);
        for (int j = 0; j < qqx; j++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            x[a - 1] = b;
        }
        for (int j = 0; j < qqy; j++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            y[a - 1] = b;
        }
    }
}