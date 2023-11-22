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
int main(){
  freopen("expand.in","r",stdin);
  freopen("expand.ans","w",stdout);
  ios::sync_with_stdio(0);
  int c,n,m,Q;
  cin>>c>>n>>m>>Q;
  Vi a(n+5),b(m+5);
  auto solve=[&](){
    if(a[1]==b[1]){
      cout<<0;
      return;
    }
    V<Vi> f(n+5,Vi(m+5));
    f[1][1]=1;
    For(i,1,n)For(j,1,m)if(f[i][j]){
      if((a[i+1]>b[j])==(a[1]>b[1]))f[i+1][j]=1;
      if((a[i]>b[j+1])==(a[1]>b[1]))f[i][j+1]=1;
      if((a[i+1]>b[j+1])==(a[1]>b[1]))f[i+1][j+1]=1;
    }
    cout<<f[n][m];
  };
  For(i,1,n)cin>>a[i];
  For(i,1,m)cin>>b[i];
  solve();
  for(int Ta,Tb,x,z;Q--;){
    cin>>Ta>>Tb;
    auto ta=a,tb=b;
    for(;Ta--;)cin>>x>>z,a[x]=z;
    for(;Tb--;)cin>>x>>z,b[x]=z;
    solve();
    a=ta,b=tb;
  }
}