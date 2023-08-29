#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int __int128
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long T;
    cin >> T;
    while(T--){
        long long n,c;
        cin >> n >> c;
        int num[n];
        long long t;
        for(int i=0;i<n;i++){
            cin >> t;
            num[i]=t;
        }
        int l=0,r=sqrt(c),mid;
        while(l!=r){
            mid=(l+r)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(num[i]+2*mid)*(num[i]+2*mid);
            }
            if(sum>c){
                r=mid;
            }
            else if(sum<c){
                l=mid+1;
            }
            else{
                break;
            }
        }
        cout << (long long)mid << endl;
    }
    return 0;
}