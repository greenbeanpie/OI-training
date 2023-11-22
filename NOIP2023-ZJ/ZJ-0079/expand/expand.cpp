#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define sz(x) ((int)(x).size())
using namespace std;
const int N=500005,inf=1e9;
int a[N],b[N],c[N],d[N];
int pre[N],suf[N],pe[N],sf[N];
int n,m,q;
int p[N],pp[N];
int mn[N<<2],mx[N<<2];
vector<pa>alla[65],allb[65];
poly g;
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
    
    for (int i=1;i<=g.size();i++) mn[i]=inf;
    for (int i=1;i<=g.size();i++) mx[i]=-inf;
    for (int i=1;i<=n;i++)
        mn[a[i]]=min(mn[a[i]],pre[i]);
    for (int i=1;i<=m;i++)
        mx[pe[i]]=max(mx[pe[i]],b[i]);
    for (int i=sz(g);i>=1;i--)
    {
        if (i+1<sz(g)) mx[i]=max(mx[i],mx[i+1]);
        if (mx[i]>=mn[i]) return 0;
    }

    for (int i=1;i<=g.size();i++) mn[i]=inf;
    for (int i=1;i<=g.size();i++) mx[i]=-inf;
    for (int i=1;i<=n;i++)
        mn[a[i]]=min(mn[a[i]],suf[i]);
    for (int i=1;i<=m;i++)
        mx[sf[i]]=max(mx[sf[i]],b[i]);
    for (int i=sz(g);i>=1;i--)
    {
        if (i+1<sz(g)) mx[i]=max(mx[i],mx[i+1]);
        if (mx[i]>=mn[i]) return 0;
    }
    return 1;
}
int cc;
bool dp[2005][2005];
void bf()
{
    if (a[1]>b[1])
    {
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i]>b[j]) 
                {
                    dp[i][j]|=dp[i-1][j-1];
                    dp[i][j]|=dp[i][j-1];
                    dp[i][j]|=dp[i-1][j];
                }
            }
        cout<<dp[n][m];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) dp[i][j]=0;
    } else
    if (a[1]<b[1])
    {
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i]<b[j]) 
                {
                    dp[i][j]|=dp[i-1][j-1];
                    dp[i][j]|=dp[i][j-1];
                    dp[i][j]|=dp[i-1][j];
                }
            }
        cout<<dp[n][m];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) dp[i][j]=0;
    } else cout<<0;
}
inline void calc()
{
    if (1<=cc&&cc<=7)
    {
        bf();
        return;
    }
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
    cin>>cc;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i],g.push_back(a[i]);
    for (int i=1;i<=m;i++)
        cin>>b[i],g.push_back(b[i]);
    for (int i=1;i<=n;i++) c[i]=-1;
    for (int i=1;i<=m;i++) d[i]=-1;
    for (int tms=1;tms<=q;tms++)
    {
        int tx,ty;
        cin>>tx>>ty;
        while (tx--)
        {
            int x,y;
            cin>>x>>y;
            g.push_back(y);
            alla[tms].push_back(mp(x,y));
        }
        while (ty--)
        {
            int x,y;
            cin>>x>>y;
            g.push_back(y);
            allb[tms].push_back(mp(x,y));
        }
    }


    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
    for (int i=1;i<=n;i++) 
    {
        a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+1;
    }
    for (int i=1;i<=m;i++)
    {
        b[i]=lower_bound(g.begin(),g.end(),b[i])-g.begin()+1;
    }

    calc();
    for (int tms=1;tms<=q;tms++)
    {
        for (auto [x,y]:alla[tms])
        {
            y=lower_bound(g.begin(),g.end(),y)-g.begin()+1;
            c[x]=y;
            swap(a[x],c[x]);
        }
        for (auto [x,y]:allb[tms])
        {
            y=lower_bound(g.begin(),g.end(),y)-g.begin()+1;
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