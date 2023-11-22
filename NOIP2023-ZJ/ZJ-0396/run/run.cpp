#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e3+100;
ll ad[MAXN][MAXN];
ll dp[MAXN][MAXN];
int n,m,k;
ll d;
void solve(){
    scanf("%d%d%d%lld",&n,&m,&k,&d);
    memset(ad,0,sizeof(ad));
    for(int i = 1;i<=m;i++){
        int x,y;ll v;scanf("%d%d%lld",&x,&y,&v);
        ad[x][y]+=v;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            ad[i][j]+=ad[i][j-1];
        }
    }
    memset(dp,0,sizeof(dp));
    dp[1][0]=0;
    dp[1][1]=-d+ad[1][1];
    //printf("dp[%d,%d]=%d\n",1,0,dp[1][0]);
    //printf("dp[%d,%d]=%d\n",1,1,dp[1][1]);

    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=min(i-1,k);j++){
            dp[i][0]=max(dp[i-1][j],dp[i][0]);
            //printf("dp[%d,%d]=%d\n",i,0,dp[i][0]);
        }
        for(int j = 1;j<=min(i,k);j++){
            dp[i][j]=dp[i-1][j-1]-d;
            dp[i][j]+=ad[i][j];
            //printf("dp[%d,%d]=%d\n",i,j,dp[i][j]);
        }
    }
    ll ans = 0;
    for(int i = 0;i<=n;i++){
        ans=max(ans,dp[n][i]);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }
}