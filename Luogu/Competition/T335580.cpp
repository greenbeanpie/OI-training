#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int sum=0;
    int home[n+1];
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        home[t]=i;
        sum+=abs(t-i);
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",abs(i-home[i]));
    }
    cout << "\n" << sum%520;
    return 0;
}