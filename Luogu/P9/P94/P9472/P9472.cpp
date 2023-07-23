#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

struct node{
	int first,second,t;
};
bool operator<(node a,node b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

set<node> s;

signed main(){
#ifndef ONLINE_JUDGE
    freopen("P9472.in","r",stdin);
    freopen("P9472.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    int t;
    for(int i=1;i<=n;i++){
        cin >> t;
        s.insert({t,t*i,i});
    }
    for(auto i:s){
        cout << i.t << " ";
    }
    return 0;
}