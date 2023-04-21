#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    multiset<int> b;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        b.insert(a[i+1]-a[i]);
        sum+=(a[i+1]-a[i]);
    }
    auto c=b.end();
    c--;
    for(int i=0;i<m-1;i++){
        sum-=*c;
        sum++;
        c--;
    }
    cout << sum+1;
    return 0;
}