#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5;
int delta[N];
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P2367.in","r",stdin);
        freopen("P2367.out","w",stdout);
    #endif
    int n,p;
    cin >> n >> p;
    int t,last=0;
    for(int i=1;i<=n;i++){
        cin >> t;
        delta[i]=t-last;
        last=t;
    }
    delta[n+1]=-last;
    int x,y,z;
    for(int i=1;i<=p;i++){
        cin >> x >> y >> z;
        delta[x]+=z;
        delta[y+1]-=z;
    }
    int now=0;
    int mininum=INT_MAX;
    for(int i=1;i<=n;i++){
        now+=delta[i];
        mininum=min(mininum,now);
    }
    cout << mininum;
    return 0;
}