#include <bits/stdc++.h>
using namespace std;
#define int long long
bool flags[500005];
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("T326619.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    
    int tot=0;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        int temp=__gcd(a,n);
        if(tot==n){
            cout << 0 << " ";
            continue;
        }
        if(a==n){
            if(flags[a]){
                cout << 0 << " ";
                continue;
            }
            cout << 1 << " ";
            flags[a]=true;
            tot++;
        }
        else if(temp!=1){
            int cnt=0;
            if(flags[a]){
                cout << 0 << " ";
                continue;
            }
            for(int i=1;i<=n/temp;i++){
                if(flags[i*temp]==0){
                    flags[i*temp]=true;
                    cnt++;
                }
            }
            cout << cnt << " ";
            tot+=cnt;
        }
        else{
            cout << n-tot << " ";
            tot=n;
        }
    }
    return 0;
}