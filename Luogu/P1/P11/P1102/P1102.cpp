#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,c;
    cin >> n >> c;
    ll num[n];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    sort(num,num+n);
    ll sum=0;
    for(int i=-0;i<n;i++){
        sum+=(upper_bound(num,num+n,num[i]+c)-num)-(lower_bound(num,num+n,num[i]+c)-num);
    }
    cout << sum;
}