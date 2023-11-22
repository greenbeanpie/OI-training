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
  // freopen("run.in","w",stdout);
  system("g++ run.cpp -o run -O2");
  system("g++ mkdt.cpp -o mkdt -O2");
  system("g++ bl.cpp -o bl -O2");
  while(1){
    system("./mkdt");
    system("./bl");
    system("./run");
    if(system("diff run.out run.ans -b")){
      cout<<"WA\n";
      return 0;
    }
    cout<<"AC"<<endl;
  }
}