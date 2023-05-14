#include <bits/stdc++.h>
using namespace std;    int n,m;
    int num[5005];
bool check(int num[],int mid){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=num[i]/mid;
    }
    if(cnt>=m){
        return 1;
    }
    return 0;
}
int main(){
    #ifdef CODESPACE
        freopen("E1222.in","r",stdin);
    #endif

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    int l=0,r=10000;
    int mid;
    while(l<r){
        int mid = (l + r + 1) / 2;
		if(check(num,mid)) l = mid;
		else r = mid - 1;
    }
    cout << l;
    return 0;
}