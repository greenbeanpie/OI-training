#include<bits/stdc++.h>
#define V vector
#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Int pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
void Yui_Yagi(){
  int n,m;
  cin>>n>>m;
  int tot=0;
  Vi hd(n+5);
  For(i,1,n)hd[i]=++tot;
  auto work=[&](char c){
    if(c=='T')return 2;
    if(c=='F')return 1;
    return 3;
  };
  V<V<Int>> e(n+2*m+5);
  Vi col(n+2*m+5),v(n+2*m+5);
  auto add=[&](int x,int y,int z){
    // cout<<x<<' '<<y<<' '<<z<<endl;
    e[x].pb({y,z}),e[y].pb({x,z});
  };
  auto gg=[&](int x,int z){
    if(!z)return x;
    if(x<=2)return 3-x;
    return x;
  };
  V<Int> A;
  for(int x,y;m--;){
    // cout<<m<<endl;
    char c;
    cin>>c>>x;
    if(c=='+'){
      cin>>y;
      int now=hd[y];
      add(now,hd[x]=++tot,0);
      A.pb({x,y});
    }else if(c=='-'){
      cin>>y;
      int now=hd[y];
      add(now,hd[x]=++tot,1);
    }else{
      A.pb({0,x});
      v[++tot]=work(c);
      int now=tot;
      add(now,++tot,0);
      hd[x]=tot;
    }
  }
  Vi niu(tot+5);
  For(i,1,n)add(i,hd[i],0),niu[hd[i]]=1;
  int ff=1,ss=0;
  Vi vec;
  auto dfs=[&](auto lf,int x,int c)->void {
    col[x]=c;
    vec.pb(x);
    if(c==3&&x<=n)ss++;
    for(auto i:e[x]){
      int y=i.fi,z=i.se;
      int t=gg(c,z);
      // cout<<t<<endl;
      if(!col[y])lf(lf,y,t);
      if(col[y]!=t)ff=0;
    }
  };
  int ans=0;
  For(i,1,tot)if(v[i]&&!col[i]){
    ss=0;
    dfs(dfs,i,v[i]);
    // cout<<ff<<endl;
    ans+=ss;
  }
  // Vi vis(n+5),Ans(tot+5);
  // for(int x:Res)vis[x]=1,cout<<x<<' ';
  // cout<<endl;
  // int t=n;
  // for(auto i:A){
  //   if(!i.fi)vis[i.fi]=1,Ans[++t]=1;
  //   else vis[i.fi]=vis[i.se],t+=2,Ans[t]=vis[i.fi];
  // }
  // For(i,1,tot)if(Ans[i]&&!col[i])cout<<i<<endl;
  // for(int x:Res)vis[x]=0 ;
  // For(i,1,n)if(vis[i]){
  //   cout<<i<<endl;
  //   cout<<"ggg"<<endl;
  // }
  // return;
  // cout<<endl;
  vec.clear();
  // cout<<ans<<endl;
  For(i,1,tot)if(!col[i]){
    int res=1e9;
    For(j,1,3){
      ss=0,ff=1;
      dfs(dfs,i,j);
      if(ff)res=min(res,ss);
      if(j<3)for(int t:vec)col[t]=0;
      vec.clear();
    }
    // if(res)cout<<res<<' '<<111<<endl;
    ans+=res;
  }
  cout<<ans<<'\n';
}
int main(){
  freopen("tribool.in","r",stdin);
  freopen("tribool.out","w",stdout);
  ios::sync_with_stdio(0);
  int _,T;
  for(cin>>_>>T;T--;)Yui_Yagi();
}