#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("E.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,x,y,a,b;
    cin >> n >> x >> y >> a >> b;
    int maxinum=INT_MIN,cnt1=0,cnt2=0,val=0;
    for(int i=0;i<n;i++){
        int S,s,m;
        cin >> S >> s >> m;
        int m0=x*S+y*s;
        int m1=m-m0;
        if(!m1){
            cnt2++;
            cnt1=0;
            if(cnt2>=b){
                val/=2;
            }
        }
        else{
            cnt2=0;
            cnt1++;
            val+=m1;
            if(m1>m0){
                val+=ceil(1.0*0.5*m1);
            }
            if(cnt1>=a){
                val*=2;
            }
        }
        maxinum=max(maxinum,val);

    }
    cout << maxinum << " " << val;
    return 0;
}