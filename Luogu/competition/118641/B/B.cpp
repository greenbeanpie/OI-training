#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

set<pair<int,int> > s;

signed main(){
#ifndef ONLINE_JUDGE
    freopen("B4.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    int t;
    for(int i=1;i<=n;i++){
        cin >> t;
        s.insert({t,i});
    }
    for(auto i:s){
        cout << i.second << " ";
    }
    return 0;
}