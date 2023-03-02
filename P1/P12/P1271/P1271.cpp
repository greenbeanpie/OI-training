#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("P1271.in","r",stdin);
    int n,m;
    cin >> n >> m;
    int list1[m];
    for(int i=0;i<m;i++){
        cin >> list1[i];
    }
    sort(list1,list1+m,cmp);
    for(int i=0;i<m;i++){
        cout << list1[i] << " ";
    }
    return 0;
}