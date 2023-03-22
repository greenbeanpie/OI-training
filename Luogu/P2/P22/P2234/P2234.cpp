#include <bits/stdc++.h>
using namespace std;
#define int long long
int temp;

signed main(){
    ios::sync_with_stdio(false);
    set<int> s;
    int n;
    cin >> n;
    int sum=0;
    s.insert(INT_MIN);
    s.insert(INT_MAX);
    for(int i=0;i<n;i++){
        cin >> temp;
        if(s.size()==2){
            sum+=temp;
            s.insert(temp);
        }
        else{
            auto t=s.lower_bound(temp);
            
            if(*t==temp){
                continue;
            }

            auto t1=t;
            t1--;
            sum+=min(abs(*t-temp),abs(*t1-temp));
            s.insert(temp);
        }
    }
    cout << sum;
    return 0;
}
