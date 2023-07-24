#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        gp_hash_table<int,int> line,row,ht1,ht2;
        int n,x,y;
        cin >> n;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin >> x >> y;
            cnt+=line[x]++;
            cnt+=row[y]++;
            cnt+=ht1[x-y]++;
            cnt+=ht2[x+y]++;
        }
        cout << cnt*2 << endl;
    }
    return 0;
}