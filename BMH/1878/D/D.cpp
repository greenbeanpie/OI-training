#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    /*#ifndef ONLINE_JUDGE
        freopen("D.in","r",stdin);
    #endif*/
    int n;
    cin >> n;
    int t[10005]={0};
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        t[a]++;
        t[b]--;
    }
    int maxinum=0,temp=0;
    for(int i=0;i<10005;i++){
        temp+=t[i];
        maxinum=max(temp,maxinum);
    }
    cout << maxinum;
    return 0;
}