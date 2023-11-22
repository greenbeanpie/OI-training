#include<bits/stdc++.h>
#define V vector
#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Rep(i,r,l) for(int i=r;i>=l;i--)
#define Int pair<int,int>
#define Inf ((int)1e18)
#define fi first
#define se second
#define pb push_back
#define sz(a) ((int)a.size())
using namespace std;
int main(){
  freopen("expand.in","r",stdin);
  freopen("expand.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int c,n,m,Q;
  cin>>c>>n>>m>>Q;
  Vi a(n+5),b(m+5);
  auto work=[&](){
    // return 0;
    Vi mxa(n+5),mxb(m+5),mna(n+5),mnb(m+5);
    mxa[1]=a[1],mxb[1]=b[1],mna[1]=a[1],mnb[1]=b[1];
    For(i,2,n)mxa[i]=max(mxa[i-1],a[i]),mna[i]=min(mna[i-1],a[i]);
    For(i,2,m)mxb[i]=max(mxb[i-1],b[i]),mnb[i]=min(mnb[i-1],b[i]);
    int X=0,Y=0;
    if(mxa[n]<mxb[m]||mna[n]<mnb[m])return 0;
    Rep(i,n,1)if(mxa[i]==mxa[n])X=i;
    Rep(i,m,1)if(mxb[i]==mxb[m])Y=i;
    For(z,0,1){
      int t=z,x=X,y=Y,ff=1;
      while(x>1||y>1){
        if(t==1){
          if(y>1){
            if(mnb[y-1]>=mna[x]){ff=0;break;}
            while(y>1&&mnb[y-1]<mna[x])y--;
          }
        }
        else{
          if(x>1){
            if(mxa[x-1]<=mxb[y]){ff=0;break;}
            while(x>1&&mxa[x-1]>mxb[y])x--;
          }
        }
        t^=1;
      }
      if(ff)return 1;
    }
    return 0;
  };
  auto bl=[&](){
    // cout<<11<<endl;
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
  auto solve=[&](){
    if(c<=5){
      bl();
      return;
    }
    if(a[1]==b[1]){
      cout<<0;
      return;
    }
    if(a[1]<b[1]){
      For(i,1,n)a[i]*=-1;
      For(i,1,m)b[i]*=-1;
    }
    // For(i,1,n)cout<<a[i]<<' ';
    // For(i,1,m)cout<<b[i]<<' ';
    // cout<<endl;
    int ff=work();
    if(ff){
      reverse(&a[1],&a[n+1]);
      reverse(&b[1],&b[m+1]);
      ff=work();
    }
    cout<<ff;
  };  
  For(i,1,n)cin>>a[i];
  For(i,1,m)cin>>b[i];
  auto ta=a,tb=b;
  solve();
  // return 0;
  a=ta,b=tb;
  for(int Ta,Tb,x,z;Q--;){
    cin>>Ta>>Tb;
    ta=a,tb=b;
    for(;Ta--;)cin>>x>>z,a[x]=z;
    for(;Tb--;)cin>>x>>z,b[x]=z;
    solve();
    swap(a,ta),swap(b,tb);
  }
}