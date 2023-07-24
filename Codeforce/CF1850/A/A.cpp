#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a,b,c;
        cin >> a >> b >> c;
        int ans=max(a+b,max(a+c,b+c));
        if(ans>=10){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}