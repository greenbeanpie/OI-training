#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("E.in","r",stdin);
    #endif
    multiset<int> s;
    int n,q;
    cin >> n >> q;
    int sal[n+1];
    for(int i=1;i<=n;i++){
        cin >> sal[i];
        s.insert(sal[i]);
    }
    while(q--){
        char c;
        int b,a;
        cin >> c >> a >> b;
        if(c=='!'){
            s.erase(s.find(sal[a]));
            sal[a]=b;
            s.insert(b);   
        }
        else{
            set<int>::iterator tb=s.upper_bound(b),ta=s.lower_bound(a);

            int cnt=0;
            while(tb!=ta){
                tb--;
                cnt++;
            }
            cout << cnt << " ";
        }
    }
    return 0;
}