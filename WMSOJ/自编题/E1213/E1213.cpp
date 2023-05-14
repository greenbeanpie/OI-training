#include <bits/stdc++.h>
using namespace std;
#define int long long
#define xhw sb

signed main(){
    #ifdef CODESPACE
        freopen("E1213.in","r",stdin);
    #endif
    int n;
    cin >> n;
    vector<int> s;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(),s.end());
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        auto t2=lower_bound(s.begin(),s.end(),t)-s.begin();
        if(s[t2]!=t){
            cout<< "no" << endl;
        }
        else{
            cout << t2+1 << endl;
        }
    }
    return 0;
}