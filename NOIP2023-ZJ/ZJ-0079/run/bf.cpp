#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define sz(x) ((int)(x.size()))
#define int ll
using namespace std;
const int N=200005,inf=1e18;
int n,m,K,d;
poly g;
poly G[N];
int L[N],R[N],V[N];
int dp[N];
void BellaKira()
{
    cin>>n>>m>>K>>d;
    for (int i=1;i<=m;i++)
    {
        int x,y,v;
        cin>>x>>y>>v;
        L[i]=x-y+1,R[i]=x;
        V[i]=v;
        G[R[i]].push_back(i);
    }
    for (int i=0;i<=n+1;i++) dp[i]=0;
    int mx=0;
    for (int i=1;i<=n+1;i++)
    {
        for (auto u:G[i])
        {
            for (int j=0;j<L[u];j++)
                dp[j]+=V[u];
        }
        dp[i]=mx;
        if (i<=n)
        {
            for (int j=0;j<i;j++)
            {
                if ((i-j)<=K) dp[i+1]=max(dp[i+1],
                dp[j]-(i-j)*d);
            }
            mx=max(mx,dp[i+1]);
        }
        poly().swap(G[i]);
    }
    cout<<dp[n+1]<<'\n';
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("bf.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T=1;
    cin>>c>>T;
    while (T--)
    {
        BellaKira();
    }
}