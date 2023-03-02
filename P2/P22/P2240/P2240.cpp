#include <bits/stdc++.h>
using namespace std;

struct coin{
    double m,v;
};

bool cmp(coin a,coin b){
    if(a.v/a.m>b.v/b.m){
        return true;
    }
    return false;
}

int main(){
    freopen("P2240.in","r",stdin);
    int n,t;
    cin >> n >> t;
    coin bag[n];
    for(int i=0;i<n;i++){
        cin >> bag[i].m >> bag[i].v;
    }
    sort(bag,bag+n,cmp);
    double summ=0;
    double sumv=0;
    for(int i=0;i<n;i++){
        if(bag[i].m+summ<=t){
            summ+=bag[i].m;
            sumv+=bag[i].v;
        }
        else{
            sumv+=(t-summ)/bag[i].m*bag[i].v;
            break;
        }
    }
    cout << fixed << setprecision(2) << sumv;
    return 0;
}