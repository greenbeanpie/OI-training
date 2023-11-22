//remember to clear!!!!!!!!!
//remember to clear!!!!!!!!!
//remember to clear!!!!!!!!!
#include <bits/stdc++.h>
#define L(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define R(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
#define F first
#define S second
using namespace std;
map<char,int>mp;
int f(int x){
  if(x==2){
    return 2;
  }
  else{
    return (1-x);
  }
}
void bl1(){
  int n,m;
  cin>>n>>m;
  int sum=pow(3,n)-1;
  vector<int>a(n);
  vector<int>id(m);
  vector<pair<int,int>>q(m);
  L(i,0,m-1){
    char o;
    cin>>o;
    if(o=='+'){
      id[i]=2;
      cin>>q[i].F>>q[i].S;
      q[i].F--;q[i].S--;
    }
    else if(o=='-'){
      id[i]=1;
      cin>>q[i].F>>q[i].S;
      q[i].F--;q[i].S--;
    }
    else{
      id[i]=3;
      cin>>q[i].F;
      q[i].F--;
      q[i].S=mp[o];
    }
  }
  int ans=n;
  L(i,0,sum){
    int k=i,g=0;
    L(j,0,n-1){
      a[j]=k%3;
      g+=(a[j]==2);
      k/=3;
    }
    auto b=a;
    L(j,0,m-1){
      if(id[j]==3){
        b[q[j].F]=q[j].S;
      }
      if(id[j]==2){
        b[q[j].F]=b[q[j].S];
      }
      if(id[j]==1){
        b[q[j].F]=f(b[q[j].S]);
      }
    }
    if(b==a){
      ans=min(ans,g);
    }
  }
  cout<<ans<<'\n';
}
void bl2(){
  int n,m;
  cin>>n>>m;
  int ans=0;
  vector<int>a(n,-1);
  L(i,0,m-1){
    char o;
    cin>>o;
    int x;
    cin>>x;
    x--;
    a[x]=mp[o];
  }
  L(i,0,n-1){
    ans+=(a[i]==2);
  }
  cout<<ans<<'\n';
}
void bl3(){
  int n,m;
  cin>>n>>m;
  vector<int>id(m);
  vector<pair<int,int>>q(m);
  vector<int>lst(n,-1);
  vector<vector<int>>g(n,vector<int>());
  L(i,0,m-1){
    char o;
    cin>>o;
    if(o=='+'){
      id[i]=2;
      cin>>q[i].F>>q[i].S;
      q[i].F--;q[i].S--;
    }
    else if(o=='-'){
      id[i]=1;
      cin>>q[i].F>>q[i].S;
      q[i].F--;q[i].S--;
    }
    else{
      id[i]=3;
      cin>>q[i].F;
      q[i].F--;
      q[i].S=mp[o];
    }
  }
  int ans=0;
  vector<int>a(n,-1);
  L(i,0,m-1){
    if(id[i]==3){
      a[q[i].F]=2;
    }
    else{
      lst[q[i].F]=q[i].S;
      a[q[i].F]=a[q[i].S];
    }
  }
  L(i,0,n-1){
    if(lst[i]!=-1){
      g[lst[i]].push_back(i);
    }
  }
  auto b=a;
  auto dfs=[&](auto dfs,int x)->void{
    for(int v:g[x]){
      if(b[v]==2){
        continue;
      }
      else{
        b[v]=2;
        dfs(dfs,v);
      }
    }
  };
  
  L(i,0,n-1){
    if(a[i]==2){
      b[i]=2;
      dfs(dfs,i);
    }
  }
  L(i,0,n-1){
    ans+=(b[i]==2);
  }
  cout<<ans<<'\n';
}
signed main(){
  freopen("tribool.in","r",stdin);
  freopen("tribool.out","w",stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mp['T']=0;mp['F']=1;mp['U']=2;

  int c,t;
  cin>>c>>t;

  if(c<=2){
    L(i,1,t){
      bl1();
    }
    return 0;
  }
  if(c<=4){
    L(i,1,t){
      bl2();
    }
    return 0;
  }
  if(c<=6){
    L(i,1,t){
      bl3();
    }
    return 0;
  }
  return 0;
}