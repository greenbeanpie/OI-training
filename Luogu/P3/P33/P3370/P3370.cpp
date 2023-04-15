#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P3370.in","r",stdin);
    #endif
    int n;
    cin >> n;
    string a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==a[j]&&j!=i){
                break;
            }
            sum++;
        }
    }
    cout << sum;
    return 0;
}