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
mt19937 rnd(time(0));
int main(){
  freopen("expand.in","w",stdout);
  int n=5e5;
  cout<<1<<' '<<n<<' '<<n<<' '<<60<<endl;
  For(i,1,n)cout<<rnd()%1000000000<<' ';
  cout<<endl;
  For(i,1,n)cout<<rnd()%1000000000<<' ';
  For(i,1,60){
    cout<<"0 0\n";
  }
}