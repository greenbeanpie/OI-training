#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in","r",stdin);
    #endif
    int n;
    cin >> n;
    int a,b,c;
    cin >> a >> b >> c;
    if(n>5){
        cout << "art";
    }
    else if(n>3){
        if(b<c){
            cout << "comprehensive";
        }
        else{
            cout << "art";
        }
    }
    else{
        if(a<c&&a<b){
            cout << "library";
        }
        else if(b<c&&b<a){
            cout << "comprehensive";
        }
        else{
            cout << "art";
        }
    }
    return 0;
}