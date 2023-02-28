#include <bits/stdc++.h>
using namespace std;

struct coin{
    int m,v;
};

bool cmp(coin a,coin b){
    if(a.v/a.m>b.v/b.m){
        return true;
    }
    return false;
}

int main(){
    int n,t;
    cin >> n >> t;
    coin bag[n];
    for(int i=0;i<n;i++){
        cin >> bag[i].m >> bag[i].v;
    }
    sort(bag,bag+n,cmp);
    
    return 0;
}