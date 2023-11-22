//再见，NOIP
#include <bits/stdc++.h>
using namespace std;
int c, t;
int oc = 0;
int a[100005]; // 0=U,1=T|F
int link[3005][3005], tail[10005];
bool loop(int o)
{
    for (int i = 0; i < tail[o]; i++)
    {
        if (oc == link[o][i])
        {
            a[o] = 0;
            return 0;
        }
    }
    for (int i = 0; i < tail[o]; i++)
    {
        if (loop(abs(link[o][i])) == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            a[i] = 1;
            tail[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            char c;
            scanf("\n%c", &c);
            if (c == 'T' || c == 'F')
            {
                int ou;
                scanf("%d", &ou);
                a[ou] = 1;
            }
            if (c == 'U')
            {
                int ou;
                scanf("%d", &ou);
                a[ou] = 0;
            }
            if (c == '-')
            {
                int x, y;
                scanf("%d%d", &y, &x);
                link[x][tail[x]] = -y;
                tail[x]++;
            }
            if (c == '+')
            {
                int x, y;
                scanf("%d%d", &y, &x);
                link[x][tail[x]] = y;
                tail[x]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
            {
                oc = i;
                loop(i);
                oc = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
}