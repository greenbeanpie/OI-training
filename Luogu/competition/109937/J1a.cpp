#include <iostream>
#include <cmath>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("J1.in","r",stdin);
        freopen("J1a.out","w",stdout);
    #endif
    long double a,b,c;
    cin >> a >> b >> c;
    cout << (int)ceill(a/(b-c));
    return 0;
}