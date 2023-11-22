#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[3005][3005]; // 排序列
int a[3005][3005]; // 原始
int minn;
bool choose(int a, int b)
{
    for (int i = 0; i < m; i++)
    {
        if (s[a][i] > s[b][m - 1 - i])
        {
            return 0;
        }
        if (s[a][i] < s[b][m - 1 - i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        minn = 100;
        for (int j = 0; j < m; j++)
        {
            char c;
            scanf("\n%c", &c);
            s[i][j] = int(c) - 'a';
            a[i][j] = int(c) - 'a';
            minn = min(minn, a[i][j]);
        }
        sort(s[i], s[i] + m);
    }
    // if (m == 1)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (a[i][0] == minn)
    //         {
    //             printf("1");
    //         }
    //         else
    //         {
    //             printf("0");
    //         }
    //     }
    // }
    if (n == 1)
    {
        printf("1");
    }
    else
    {
        // printf("1");
        for (int i = 0; i < n; i++)
        {
            bool flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (choose(i, j) == 0)
                {
                    flag = 0;
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
    }
    // printf("\n___________\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf("%d ", s[i][j]);
    //     }
    //     printf("\n");
    // }
}