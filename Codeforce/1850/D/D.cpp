#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5;
int dp[N];


signed main(){
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        int num[n];
        for(int i=0;i<n;i++){
            cin >> num[i];
        }
        sort(num,num+n);
        int t=1,maxinum=1;;
        for(int i=1;i<n;i++){
            if(num[i]-num[i-1]<=k){
                t++;
            }
            else{
                t=1;
            }
            maxinum=max(maxinum,t);
        }
        cout << n-maxinum << endl;
    }
    return 0;
}