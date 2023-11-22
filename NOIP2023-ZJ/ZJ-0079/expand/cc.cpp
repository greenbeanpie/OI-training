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
    system("g++ -O2 maker.cpp -o maker");
    system("g++ -O2 bf.cpp -o bf");
    system("g++ -O2 expand.cpp -o expand");
    for (int i=1;;i++)
    {
        system("./maker");
        system("./bf");
        system("./expand");
        if (system("diff expand.out bf.out -b")) return;
        cout<<i<<" AC"<<endl;
    }
}
signed main()
{
    // freopen("run.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T=1;
    while (T--)
    {
        BellaKira();
    }
}