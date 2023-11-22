#include <bits/stdc++.h>
using namespace std;
#define ll long long
int caseidx,T,n,m;
int val[200100];
char optstr[20];
int opt[100100],optx[100100],opty[101000];
int temp[100100],tempxsov1[10010],ans;
bool check()
{
    for (int i=1;i<=n;++i)
        tempxsov1[i] = temp[i];
    for (int i=1;i<=m;++i)
        {
            if (opt[i] == 1)
                tempxsov1[optx[i]] = 1;
            else if (opt[i] == 2)
                tempxsov1[optx[i]] = 0;
            else if (opt[i] == 3)
                tempxsov1[optx[i]] = 2;
            else if (opt[i] == 4)
                tempxsov1[optx[i]] = tempxsov1[opty[i]];   
            else if (opt[i] == 5)
                {
                    if (tempxsov1[opty[i]] == 2)
                        tempxsov1[optx[i]] = 2;
                    else if (tempxsov1[opty[i]] == 1)
                        tempxsov1[optx[i]] = 0;
                    else if (tempxsov1[opty[i]] == 0)
                        tempxsov1[optx[i]] = 1;
                }
        }
    for (int i=1;i<=n;++i)
        if (temp[i] != tempxsov1[i])
            return false;
    return true;
}
void dfs(int now)
{
    if (now == n+1)
        {
            if (check())
                {
                    int cntx = 0;
                    for (int i=1;i<=n;++i)
                        if (temp[i] == 2)
                            ++cntx;
                    ans = min(ans,cntx);
                }
            return;
        }
    for (int i=0;i<=2;++i)
        {
            temp[now] = i;
            dfs(now+1);
        }
}
void solve12()
{
    for (int i=1;i<=m;++i)
        {
            scanf("%s",optstr+1);
            scanf("%d",&optx[i]);
            if (optstr[1] == 'T')
                opt[i] = 1;
            else if (optstr[1] == 'F')
                opt[i] = 2;
            else if (optstr[1] == 'U')
                opt[i] = 3;
            else if (optstr[1] == '+')
                {
                    opt[i] = 4;
                    scanf("%d",&opty[i]);
                }
            else if (optstr[1] == '-')
                {
                    opt[i] = 5;
                    scanf("%d",&opty[i]);
                }
        }
    ans = n;
    dfs(1);
    printf("%d\n",ans);
}
void solve34()
{
    for (int i=1;i<=n;++i)
        val[i] = 0;
    for (int i=1;i<=m;++i)
        {
            scanf("%s",optstr+1);
            int x;
            scanf("%d",&x);
            if (optstr[1] == 'T')
                val[x] = 1;
            else if (optstr[1] == 'F')
                val[x] = 0;
            else if (optstr[1] == 'U')
                val[x] = 2;
        }
    ans = 0;
    for (int i=1;i<=n;++i)
        if (val[i] == 2)
            ++ans;
    printf("%d\n",ans);
}
void get56()
{
    for (int i=1;i<=n;++i)
        temp[i] = val[i];
    for (int i=1;i<=m;++i)
        {
            if (opt[i] == 1)
                temp[optx[i]] = temp[opty[i]];
            else
                temp[optx[i]] = 2;
        }
}
bool check56()
{
    for (int i=1;i<=n;++i)
        if (temp[i] != val[i])
            return false;
    return true;
}
void solve56()
{
    for (int i=1;i<=n;++i)
        val[i] = 0;
    for (int i=1;i<=m;++i)
        {
            scanf("%s",optstr+1);
            scanf("%d",&optx[i]);
            if (optstr[1] == '+')
                {
                    opt[i] = 1;
                    scanf("%d",&opty[i]);
                }
            else
                opt[i] = 2;
        }
    get56();
    while (!check56())
        {
            for (int i=1;i<=n;++i)
                val[i] = temp[i];
            get56();
        }
    for (int i=1;i<=n;++i)
        val[i] = temp[i];
    ans = 0;
    for (int i=1;i<=n;++i)
        if (val[i] == 2)
            ++ans;
    printf("%d\n",ans);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&caseidx,&T);
    while (T--)
        {
            scanf("%d%d",&n,&m);
            if (caseidx <= 2)
                solve12();
            else if (caseidx <= 4)
                solve34();
            else if (caseidx <= 6)
                solve56();
            else
                solve12();
        }
    return 0;
}