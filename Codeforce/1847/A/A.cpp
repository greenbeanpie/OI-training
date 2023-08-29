#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in","r",stdin);
    #endif
    int T;
    cin >> T;
    while(T--){
        multiset<int> s;
        vector<int> v;
        int n,k;
        cin >> n >> k;
        int a,b,sum=0;
        cin >> a;
        for(int i=1;i<n;i++){
            cin >> b;
            s.insert(abs(a-b));
            sum+=abs(a-b);
            a=b;
        }
        k--;
        while(k--){
            sum-=*(--s.end());
            s.erase(--s.end());
        }
        cout << sum << endl;
    }
    return 0;
}