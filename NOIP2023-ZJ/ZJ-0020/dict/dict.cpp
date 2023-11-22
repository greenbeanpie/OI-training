#include<bits/stdc++.h>
#define V vector
#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define For(i,l,r) for(int i=l;i<=r;i++)
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=3005;
int Ans[N];
int main(){
  freopen("dict.in","r",stdin);
  freopen("dict.out","w",stdout);
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  V<pair<string,int>> vec;
  For(i,1,n){
    string st;
    cin>>st;
    sort(all(st));  
    vec.pb({st,-i});
    reverse(all(st));
    vec.pb({st,i});
  }
  sort(all(vec));
  reverse(all(vec));
  int s=0;
  for(auto i:vec){
    if(i.se>0)s++;
    else if(s==n)Ans[-i.se]=1;
  }
  For(i,1,n)cout<<Ans[i];
  cout<<'\n';
}