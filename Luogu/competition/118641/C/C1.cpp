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
        int l=1,g=1,sum=1;
        int n;
        cin >> n;
        int t;
        cin >> t;
        l=g=sum=t;
        for(int i=2;i<=n;i++){
            cin >> t;
            g=gcd(g,t);
            l=lcm(l,t);
            sum*=t;
        }
        if(g*t!=sum){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}