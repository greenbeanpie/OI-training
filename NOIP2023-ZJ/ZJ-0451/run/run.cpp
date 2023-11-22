#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct challen
{
    ll l,r,v;
    bool operator < (const challen &o) const
    {
        return v/1.0/(r-l+1) > o.v/1.0/(o.r-o.l+1);
    }
};
challen p[200100];
ll caseidx,T,n,m,k,d,ans;
ll tempsov1[20],sumsov1[20];
ll day[200100];
bool check12()
{
    ll cnt = 0;
    for (int i=1;i<=n;++i)
        if (tempsov1[i] == 0)
            {
                if (cnt > k)
                    return false;
                cnt = 0;
            }
        else
            ++cnt;
    return true;
}
ll calc12()
{
    ll ener = 0;
    for (int i=1;i<=n;++i)
        sumsov1[i] = 0;
    for (int i=1;i<=n;++i)
        sumsov1[i] = sumsov1[i-1]+tempsov1[i];
    ener -= sumsov1[n]*d;
    for (int i=1;i<=m;++i)
        if (sumsov1[p[i].r]-sumsov1[p[i].l-1] == p[i].r-p[i].l+1)
            ener += p[i].v; 
    return ener;
}
void dfs12(int now)
{
    if (now == n+1)
        {
            if (!check12())
                return;
            ans = max(ans,calc12());
            return;
        }
    for (int i=0;i<=1;++i)
        {
            tempsov1[now] = i;
            dfs12(now+1);
        }
}
void solve12()
{
    ans = 0;
    for (int i=1;i<=m;++i)
        p[i].r += p[i].l-1;
    dfs12(1);
    printf("%lld\n",ans);
}
bool check()
{
    ll cnt = 0;
    for (int i=1;i<=n;++i)
        if (day[i] == 0)
            {
                if (cnt > k)
                    return false;
                cnt = 0;
            }
        else
            ++cnt;
    return true;
}
void solve()
{
    ll ans = 0;
    for (int i=1;i<=m;++i)
        p[i].r += p[i].l-1;
    sort(p+1,p+m+1);
    for (int i=1;i<=n;++i)
        day[i] = 0;
    for (int i=1;i<=m;++i)
        {
            if (p[i].r > n)
                continue;
            ll tempcnt = 0;
            for (int j=p[i].l;j<=p[i].r;++j)
                {
                    if (day[j] == 0)
                        ++tempcnt;
                    ++day[j];
                }
            if (!check())
                {
                    for (int j=p[i].l;j<=p[i].r;++j)
                        --day[j];
                    continue;
                }
            if (p[i].v <= tempcnt*d)
                {
                    for (int j=p[i].l;j<=p[i].r;++j)
                        --day[j];
                    continue;
                }
            ans += p[i].v-tempcnt*d;
        }
    printf("%lld\n",ans);
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&caseidx,&T);
    while (T--)
        {
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            for (int i=1;i<=m;++i)
                scanf("%lld%lld%lld",&p[i].l,&p[i].r,&p[i].v);
            if (caseidx <= 2)
                solve12();
            else
                solve();
        }
    return 0;
}