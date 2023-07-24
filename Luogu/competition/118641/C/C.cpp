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
        int n;
        cin >> n;
        bool flag=true;
        int t,l;
        cin >> l;
        for(int i=2;i<=n;i++){
            cin >> t;
            if(flag&&gcd(l,t)==1){
                l*=t;
            }
            else{
                flag=false;
            }
        }
        if(flag||n<=2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}