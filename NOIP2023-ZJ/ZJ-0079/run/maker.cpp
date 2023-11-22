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
mt19937_64 rnd(chrono::system_clock().now().time_since_epoch().count());
void BellaKira()
{
    n=rnd()%2000+1,m=rnd()%2000+1;
    K=rnd()%n+1,d=rnd()%1000000000+1;
    cout<<n<<" "<<m<<" "<<K<<" "<<d<<'\n';
    for (int i=1;i<=m;i++)
    {
        int l=rnd()%n+1;
        int r=rnd()%n+1;
        if (l>r) swap(l,r);
        int v=rnd()%1000000000+1;
        cout<<r<<" "<<r-l+1<<" "<<v<<'\n';
    }
}
signed main()
{
    freopen("run.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T=1;
    c=1,T=10;
    cout<<c<<" "<<T<<'\n';
    while (T--)
    {
        BellaKira();
    }
}