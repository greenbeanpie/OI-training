#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        char c;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                cin >> c;
                if(c!='.'){
                    cout << c;
                }
            }
        }
        cout << endl;
    }
    return 0;
}