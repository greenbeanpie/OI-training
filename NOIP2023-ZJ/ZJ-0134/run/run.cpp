#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e3+5;
int C,T,n,m,k,d;
vector<pair<int,int>>a[N];
vector<int>b[N];
vector<LL>c[N];
LL dp[N][N];

void Solve()
{
    cin>>n>>m>>k>>d;
    for(int i=1,x,y,v;i<=m;++i)
    {
        cin>>x>>y>>v;
        a[x].emplace_back(y,v);
    }
    for(int i=1;i<=n;++i)
    {
        sort(a[i].begin(),a[i].end());
        b[i].resize(a[i].size()),c[i].resize(a[i].size());
        for(int j=0;j<(int)b[i].size();++j)
        {
            b[i][j]=a[i][j].first;
            c[i][j]=a[i][j].second;
            if(j!=0) c[i][j]+=c[i][j-1];
        }
    }
    memset(dp,0xcf,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k&&j<=i;++j)
        {
            LL tot=0;
            auto it=upper_bound(b[i].begin(),b[i].end(),j);
            if(it!=b[i].begin()) tot=c[i][prev(it)-b[i].begin()];
            dp[i][j]=max(dp[i-1][j-1]+tot-d,dp[i-1][j]+tot);
        }
    LL ans=0;
    for(int j=0;j<=k;++j)
        ans=max(ans,dp[n][j]);
    cout<<ans<<"\n";
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>C>>T;
    while(T--) Solve();
    return 0;
}