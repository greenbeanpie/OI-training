#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define per(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define ckmn(i,j) (i=min(i,j))
#define ckmx(i,j) (i=max(i,j))
#define fir first
#define sec second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double db;
#define siz(i) ((int)(i).size())
#define all(i) (i).begin(),(i).end()
// #define int ll
typedef vector<int> vi;
typedef pair<int,int> pi;
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    system(("g++ run.cpp -O2 -Dsuper -Wall -Wextra -Wshadow -o run"));
    system(("g++ run_bf.cpp -O2 -Dsuper -Wall -Wextra -Wshadow -o run_bf"));
    system(("g++ make.cpp -O2 -Dsuper -Wall -Wextra -Wshadow -o make"));
    while(1){
        system(("./make > qwq.in"));
        system(("./run < qwq.in > 1.out"));
        system(("./run_bf < qwq.in > 2.out"));
        if(system(("diff 1.out 2.out -b"))) break;
    }
return 0;}