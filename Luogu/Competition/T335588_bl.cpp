#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        int cr=0;
        cnt++;
        for(int j=i;j<n;j++){
            cr+=num[i];
            if(cr<0){
                cnt--;
                break;
            }
        }
        if(cr<0){
            continue;
        }
        for(int j=0;j<i;j++){
            cnt+=num[i];
            if(cr<0){
                cnt--;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}