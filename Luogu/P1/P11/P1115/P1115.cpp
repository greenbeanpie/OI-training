#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P1115.in","r",stdin);
    #endif
    int n;
    cin >> n;
    int num;
    int dp=0,maxinum=INT_MIN;
    for(int i=0;i<n;i++){
        cin >> num;
        dp+=num;
        maxinum=max(maxinum,dp);
        if(dp<0){
            dp=0;
        }
        
    }
    cout << maxinum;
    return 0;
}