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
const int N=200005,inf=1000;
int n,m,q;
poly g;
poly G[N];
int L[N],R[N],V[N];
int dp[N];
mt19937_64 rnd(chrono::system_clock().now().time_since_epoch().count());
void BellaKira()
{
    cout<<0<<" ";
    n=rnd()%1000+1000,
    m=rnd()%1000+1000,q=rnd()%61;
    // n=2000,m=2000,q=60;
    // q=2;
    // q=0;
    cout<<n<<" "<<m<<" "<<q<<'\n';
    for (int i=1;i<=n;i++) cout<<rnd()%inf<<" ";
    cout<<endl;
    for (int i=1;i<=m;i++) cout<<rnd()%inf<<" ";
    cout<<endl;
    while (q--)
    {
        int x=n,y=m;
        cout<<x<<" "<<y<<'\n';
        for (int i=1;i<=x;i++) cout<<i<<" "<<rnd()%inf<<'\n';
        for (int i=1;i<=y;i++) cout<<i<<" "<<rnd()%inf<<'\n';
    }
}
signed main()
{
    freopen("expand.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T=1;
    while (T--)
    {
        BellaKira();
    }
}