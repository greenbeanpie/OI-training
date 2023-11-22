#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INFx = 1000000000;
int caseidx,n,m,q;
int x[2001000],y[2010000];
int nowx[2001000],nowy[2010000];
int f[2010][2010];
int solve()
{
    if (x[1] <= y[1] && x[n] >= y[m])
        return 0;
    if (x[1] >= y[1] && x[n] <= y[m])
        return 0;
    int minnx=INFx,minny=INFx,maxxx=-INFx,maxxy=-INFx;
    for (int i=1;i<=n;++i)
        {
            minnx = min(minnx,x[i]);
            maxxx = max(maxxx,x[i]);
        }
    for (int i=1;i<=n;++i)
        {
            minny = min(minny,y[i]);
            maxxy = max(maxxy,y[i]);
        }
    if (minnx > maxxy || minny > maxxx)
        return 1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            f[i][j] = 0;
    f[0][0] = 1;
    if (x[1] < y[1] && x[n] < y[m])
        {
            for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                    if (x[i] < y[j])
                        {
                            f[i][j] = max(f[i-1][j-1],max(f[i][j-1],f[i-1][j]));
                            if (j == m)
                                f[i][j] = max(f[i][j],f[i-1][j]);
                        }
            return f[n][m];
        }
    else
        {
            for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j)
                    if (x[i] > y[j])
                        {
                            f[i][j] = max(f[i-1][j-1],max(f[i][j-1],f[i-1][j]));
                            if (j == m)
                                f[i][j] = max(f[i][j],f[i-1][j]);
                        }
            return f[n][m];
        }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&caseidx,&n,&m,&q);
    for (int i=1;i<=n;++i)
        scanf("%d",&nowx[i]);
    for (int i=1;i<=m;++i)
        scanf("%d",&nowy[i]);
    for (int i=1;i<=n;++i)
        x[i] = nowx[i];
    for (int i=1;i<=m;++i)
        y[i] = nowy[i];
    printf("%d",solve());
    while (q--)
        {
            for (int i=1;i<=n;++i)
                x[i] = nowx[i];
            for (int i=1;i<=m;++i)
                y[i] = nowy[i];
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            int ax,bx;
            for (int i=1;i<=kx;++i)
                {
                    scanf("%d%d",&ax,&bx);
                    x[ax] = bx;
                }
            for (int i=1;i<=ky;++i)
                {
                    scanf("%d%d",&ax,&bx);
                    y[ax] = bx;
                }
            printf("%d",solve());
        }
    return 0;
}