#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P4387.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    for(int T=0;T<t;T++){
        int n;
        cin >> n;
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> res;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            res.push(a);
        }
        stack<int> ans;
        for(int i=0;i<n;i++){
            ans.push(q.front());
            q.pop();
            while(ans.size()&&ans.top()==res.front()){
                ans.pop();
                res.pop();
            }
        }
        if(ans.size()){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}