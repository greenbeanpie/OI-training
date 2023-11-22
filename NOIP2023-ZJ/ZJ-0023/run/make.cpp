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
mt19937 rgen(random_device{}());
#define uid uniform_int_distribution
int n=5,m=3,k=2,d=2;
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    cout<<"0 1\n";
    cout<<n<<" "<<m<<" "<<k<<" "<<d<<"\n";
    rep(i,1,m){
        int l=uid<>(1,n)(rgen),r=uid<>(1,n)(rgen),w=uid<>(1,10)(rgen);
        if(l>r) swap(l,r);
        cout<<r<<" "<<r-l+1<<" "<<w<<"\n";
    }
return 0;}