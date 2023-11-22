#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define per(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define ckmn(i,j) (i=min(i,j))
#define ckmx(i,j) (i=max(i,j))
#define fir first
#define sec second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double db;
#define siz(i) ((int)(i).size())
#define all(i) (i).begin(),(i).end()
// #define int ll
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N=1010;
const ll inf=1e18;
int n,m,K;
ll d;
vector<pair<int,ll>> gua[N];
ll f[N][N];
void work(){
    cin>>n>>m>>K>>d;
    rep(i,1,n) gua[i].clear();
    rep(i,1,m){
        int x,y;
        ll z;
        cin>>x>>y>>z;
        gua[x].eb(y,z);
    }
    f[0][0]=0;
    rep(i,1,n){
        rep(j,0,i){
            f[i][j]=-inf;
            if(j>K) continue;
            if(j) ckmx(f[i][j],f[i-1][j-1]-d);
            else{
                rep(jj,0,i-1) ckmx(f[i][j],f[i-1][jj]);
            }
            for(auto k:gua[i]){
                if(j>=k.fir) f[i][j]+=k.sec;
            }
        }
    }
    ll ans=-inf;
    rep(i,0,n) ckmx(ans,f[n][i]);
    cout<<ans<<"\n";
}
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    // freopen("run.in","r",stdin);
    // freopen("run.out","w",stdout);
    int orz,T;cin>>orz>>T;
    while(T--)work();
return 0;}