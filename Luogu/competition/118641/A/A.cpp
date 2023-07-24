#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"



signed main(){
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int big=0,small=0,num=0;
    char c;
    while(cin>>c){
        if(c>='a'&&c<='z'){
            small++;
        }
        else if(c>='A'&&c<='Z'){
            big++;
        }
        else if(c>='0'&&c<='9'){
            num++;
        }
    }
    cout << num <<" "<< small <<" "<<big;
    return 0;
}