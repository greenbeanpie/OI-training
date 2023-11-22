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
const string name="run";
const int len=3;
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    system(("g++ "+name+".cpp -O2 -Dsuper -Wall -Wextra -Wshadow -o b.out").c_str());
    rep(i,1,len){
        string qwq=name+to_string(i);
        system(("/usr/bin/time -f \"%Us\" ./b.out < "+qwq+".in > "+qwq+".out").c_str());
        system(("diff "+qwq+".out "+qwq+".ans -b").c_str());
    }
return 0;}