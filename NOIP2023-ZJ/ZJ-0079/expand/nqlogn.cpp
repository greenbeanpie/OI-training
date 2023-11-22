#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
using namespace std;
const int N=500005,inf=1e9;
int a[N],b[N],c[N],d[N];
int pre[N],suf[N],pe[N],sf[N];
int n,m,q;
int p[N],pp[N];
inline int solve()
{
    if (a[n]<=b[m]) return 0;
    
    pre[1]=a[1],suf[n]=a[n];
    for (int i=2;i<=n;i++)
        pre[i]=max(pre[i-1],a[i]);
    for (int i=n-1;i>=1;i--)
        suf[i]=max(suf[i+1],a[i]);
    pe[1]=b[1],sf[m]=b[m];
    for (int i=2;i<=m;i++)
        pe[i]=min(pe[i-1],b[i]);
    for (int i=m-1;i>=1;i--)
        sf[i]=min(sf[i+1],b[i]);
    for (int i=1;i<=n;i++)
        if (a[i]<=pe[m]) return 0;
    for (int i=1;i<=m;i++)
        if (b[i]>=pre[n]) return 0;


    for (int i=1;i<=n;i++)
        p[i]=i;
    for (int i=1;i<=m;i++)
        pp[i]=i;
    sort(p+1,p+n+1,[&](int x,int y)
    {
        return a[x]>a[y];
    });

    {
        sort(pp+1,pp+m+1,[&](int x,int y)
        {
            return pe[x]>pe[y];
        });
        int mx=-inf;
        for (int i=1,j=1;i<=n;i++)
        {
            while (j<=m&&pe[pp[j]]>=a[p[i]]) 
            {
                mx=max(mx,b[pp[j]]);
                j++;
            }
            if (mx>=pre[p[i]]) return 0;
        }
    }
    {
        sort(pp+1,pp+m+1,[&](int x,int y)
        {
            return sf[x]>sf[y];
        });
        int mx=-inf;
        for (int i=1,j=1;i<=n;i++)
        {
            while (j<=m&&sf[pp[j]]>=a[p[i]]) 
            {
                mx=max(mx,b[pp[j]]);
                j++;
            }
            if (mx>=suf[p[i]]) return 0;
        }
    }
    return 1;
}
inline void calc()
{
    if (a[1]>b[1])
    {
        cout<<solve();
    } else
    if (a[1]<b[1])
    {
        for (int i=1;i<=max(n,m);i++) swap(a[i],b[i]);
        swap(n,m);
        cout<<solve();
        for (int i=1;i<=max(n,m);i++) swap(a[i],b[i]);
        swap(n,m);
    } else cout<<0;
}
void BellaKira()
{
    int cc;
    cin>>cc;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];
    for (int i=1;i<=n;i++) c[i]=-1;
    for (int i=1;i<=m;i++) d[i]=-1;
    calc();
    while (q--)
    {
        int tx,ty;
        cin>>tx>>ty;
        while (tx--)
        {
            int x,y;
            cin>>x>>y;
            c[x]=y;
            swap(a[x],c[x]);
        }
        while (ty--)
        {
            int x,y;
            cin>>x>>y;
            d[x]=y;
            swap(b[x],d[x]);
        }
        calc();
        for (int i=1;i<=n;i++)
            if (c[i]!=-1)
            {
                swap(a[i],c[i]),c[i]=-1;
            }
        for (int i=1;i<=m;i++)
            if (d[i]!=-1)
            {
                swap(b[i],d[i]),d[i]=-1;
            }
    }
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}