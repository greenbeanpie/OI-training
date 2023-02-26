#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("P2241.in","r",stdin);
    int n,m;
    cin >> n >> m;
    long long a1=n*(n+1)*m*(m+1)/4;
    long long a2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a2+=min(n-i,m-j);
        }
    }
    cout << a2 << " " << abs(a1-a2);
    return 0;
}