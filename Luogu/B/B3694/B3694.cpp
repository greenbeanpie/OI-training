#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace  __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("B3694.in","r",stdin);
        freopen("B3694.out","w",stdout);
    #endif
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> v;
        tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t;
        int a;
        for(int i=1;i<=n;i++){
            cin >> a;
            v.push_back(a);
            t.insert(a);
        }
        for(int i:v){
            cout << t.order_of_key(i)+1 << " ";
        }
        cout << endl;
    }
    return 0;
}