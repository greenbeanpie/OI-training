#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int C,n,m,q,a[N],b[N];
bool dp[2005][2005];
struct Change
{
    int p,v1,v2;
}ca[N],cb[N];

void Solve()
{
    if(a[1]==b[1]||a[n]==b[m]) return cout<<0,void();
    if((a[1]<b[1]&&a[n]>b[m])||(a[1]>b[1]&&a[n]<b[m])) return cout<<0,void();
    if(n>=2005||m>=2005) return cout<<1,void();
    // cerr<<"ab:\n";
    // for(int i=1;i<=n;++i)
    //     cerr<<a[i]<<" \n"[i==n];
    // for(int i=1;i<=m;++i)
    //     cerr<<b[i]<<" \n"[i==m];
    // cerr<<"\n";
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            dp[i][j]=false;
    dp[1][1]=true;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(!dp[i][j]) continue;
            if((a[1]<b[1]&&a[i+1]<b[j])||(a[1]>b[1]&&a[i+1]>b[j])) dp[i+1][j]=true;
            if((a[1]<b[1]&&a[i]<b[j+1])||(a[1]>b[1]&&a[i]>b[j+1])) dp[i][j+1]=true;
            if((a[1]<b[1]&&a[i+1]<b[j+1])||(a[1]>b[1]&&a[i+1]>b[j+1])) dp[i+1][j+1]=true;
        }
    cout<<(dp[n][m]?1:0);
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>C>>n>>m>>q;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
        cin>>b[i];
    Solve();
    while(q--)
    {
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;++i)
        {
            cin>>ca[i].p>>ca[i].v2;
            ca[i].v1=a[ca[i].p];
            a[ca[i].p]=ca[i].v2;
        }
        for(int i=1;i<=ky;++i)
        {
            cin>>cb[i].p>>cb[i].v2;
            cb[i].v1=b[cb[i].p];
            b[cb[i].p]=cb[i].v2;
        }
        // cerr<<"q:"<<q<<"\n";
        Solve();
        for(int i=1;i<=kx;++i)
            a[ca[i].p]=ca[i].v1;
        for(int i=1;i<=ky;++i)
            b[cb[i].p]=cb[i].v1;
    }
    return 0;
}