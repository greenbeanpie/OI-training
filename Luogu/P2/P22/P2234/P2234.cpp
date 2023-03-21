#include <bits/stdc++.h>
using namespace std;
#define int long long
int temp;
struct a{
    int day,num;
};
bool operator<(a x,a y){
    return x.num<y.num;
}

set<int> s;
signed main(){
    int n;
    cin >> n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(s.empty()){
            sum+=temp;
            s.insert(temp);
        }
        else{
            auto t=s.lower_bound(temp);
            if(*t==temp){
                continue;
            }
            sum+=min(abs(*t-temp),abs(*(--t)-temp));
            s.insert(temp);
        }
    }
    cout << sum-1;
    return 0;
}