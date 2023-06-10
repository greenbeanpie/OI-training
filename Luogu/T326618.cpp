#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("T326618.in","r",stdin);
    #endif
    int y,z;
    cin >> y >> z;
    int first6=(z-z%1000000)/1000000;
    if(first6==0){
        cout << abs(100000000000+y-z);
    }
    else{
        cout << min(min(abs((first6-1)*1000000+y-z),abs(first6*1000000+y-z)),abs((first6+1)*1000000+y-z));
    }
    return 0;
}