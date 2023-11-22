#include<bits/stdc++.h>
#define V vector
#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Int pair<int,int>
#define Inf ((int)1e18)
#define fi first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
using namespace std;
#define int long long
struct hzy{int l,r,z;};
void Yui_Yagi(){
  int n,m,K,d;
  cin>>n>>m>>K>>d;
  V<hzy> vec(m+5);
  Vi v;
  V<V<Int>> q(n+5);
  for(int i=1,l,r,x;i<=m;i++){
    cin>>r>>l>>x;
    q[r-l+1].pb({r,x});
  }
  V<Vi> dp(n+5,Vi(n+5,-Inf));
  dp[0][0]=0;
  For(i,1,n){
    dp[i][0]=dp[i-1][0];
    For(j,i,min(i+K-1,n))dp[i][j]=max(dp[i-1][j],dp[i][0]);
    For(j,1,n)dp[i][j]-=d;
    for(auto j:q[i])
      For(t,j.fi,n)dp[i][t]+=j.se;
    // dp[i][0]=max(dp[i][0],dp[i][i]);
    dp[i][0]=max(dp[i][0],dp[i-1][i-1]);
    // For(j,1,n)dp[i][j]-=d*(v[i+1]-v[i]-1);
    // cout<<dp[i][0]<<' ';
    // For(j,0,n)cout<<dp[i][j]<<' ';
    // cout<<endl;
  }
  cout<<max(dp[n][0],dp[n][n])<<'\n';
}
signed main(){
  freopen("run.in","r",stdin);
  freopen("run.ans","w",stdout);
  ios::sync_with_stdio(0);  
  int c,_;
  for(cin>>c>>_;_--;)Yui_Yagi();
}