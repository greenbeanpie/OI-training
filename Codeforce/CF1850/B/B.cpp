#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a,b,n,t,maxinum=INT_MIN;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a >> b;
            if(a<=10&&b>maxinum){
                maxinum=b;
                t=i;
            }
        }
        cout << t << endl;
    }
    return 0;
}