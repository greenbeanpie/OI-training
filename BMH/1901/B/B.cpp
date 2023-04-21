#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[10000005];
bool ip[10000005];
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in","r",stdin);
    #endif
    for(int i=2;i<sqrt(10000000);i++){
        if(cnt[i]==0){
            ip[i]=true;
            cnt[i]=1;
            for(int j=2;j<=10000000/i;j++){
                cnt[i*j]++;
            }
        }
    }
    int l,r;
    cin >> l >> r;
    int sum=0;
    for(int i=l;i<=r;i++){
        if(cnt[i]==0){
            cnt[i]=2;
        }
        sum+=(1>>(cnt[i]-1))+1;
    }
    cout << sum;
    return 0;
}
