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
  freopen("run.in","w",stdout);
  int n=100,m=100,K=10,d=10;
  cout<<1<<' '<<1<<endl;
  cout<<n<<' '<<m<<' '<<K<<' '<<d<<endl;
  For(i,1,m){
    int x=rnd()%n+1,y=rnd()%n+1;
    if(x>y)swap(x,y);
    cout<<y<<' '<<y-x+1<<' '<<rnd()%100<<endl;
  }
}