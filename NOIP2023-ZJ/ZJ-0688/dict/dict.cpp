#include <bits/stdc++.h>
#define L(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define R(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
using namespace std;
signed main(){
  freopen("dict.in","r",stdin);
  freopen("dict.out","w",stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin>>n>>m;
  vector<string>s(n);
  vector<vector<int>>a(n,vector<int>(26));
  L(i,0,n-1){
    cin>>s[i];
  }
  auto id=[&](auto x){
    return x-'a';
  };
  L(i,0,n-1){
    L(j,0,m-1){
      a[i][id(s[i][j])]++;
    }
  }
  vector<pair<int,int>>mi(n);
  vector<pair<int,int>>ma(n);

  L(i,0,n-1){
    L(j,0,25){
      if(a[i][j]){
        mi[i]={j,a[i][j]};
        break;
      }
    }
    R(j,25,0){
      if(a[i][j]){
        ma[i]={j,a[i][j]};
        break;
      }
    }
  }

  auto check=[&](int a,int b)->bool{
    return (mi[a].first<ma[b].first);
  };
  vector<bool>ans;
  L(i,0,n-1){
    bool flag=1;
    L(j,0,n-1){
      if(i==j){
        continue;
      }
      flag&=check(i,j);
    }
    ans.push_back(flag);
  }
  for(auto i:ans){
    cout<<i;
  }
  cout<<'\n';
	return 0;
}