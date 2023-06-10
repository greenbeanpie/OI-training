#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("D.in","r",stdin);
    #endif
    int n,m;
    cin >> n >> m;
    int a,b,c;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        sum+=a*b*c;
    }
    int row=ceil(1.0*sum/m);
    if(row*m==sum){
        cout << row << " " << m;
    }
    else{
        cout << row << " " << sum-(row-1)*m;
    }
    return 0;
}