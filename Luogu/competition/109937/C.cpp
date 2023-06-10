#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("C.in","r",stdin);
    #endif
    int n,x;
    cin >> n >> x;
    int sum=n*x;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        sum+=t;
    }
    cout << sum;
    return 0;
}