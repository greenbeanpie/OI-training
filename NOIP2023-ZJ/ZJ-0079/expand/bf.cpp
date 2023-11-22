#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
using namespace std;
const int N=500005;
bool dp[2005][2005];
int a[N],b[N],c[N],d[N];
int n,m,q;
void calc()
{
    // for (int i=1;i<=n;i++) cout<<a[i]<<",";
    // cout<<endl;
    // for (int i=1;i<=m;i++) cout<<b[i]<<",";
    // cout<<endl;
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
    freopen("bf.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}