#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in","r",stdin);
    #endif
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int tot=0;
        int a;
        int now=-1;
        for(int i=1;i<=n;i++){
            cin >> a;
            if(now==-1){
                now=a;
            }
            else{
                now&=a;
            }
            if(now==0){
                tot++;
                now=-1;
            }
        }
        cout << max(1,tot) << endl;
    }
    return 0;
}