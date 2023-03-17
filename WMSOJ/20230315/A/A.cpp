#include <bits/stdc++.h>
using namespace std;

struct food{
    int a,b;
}a[205];
bool cmp(food a,food b){
    return a.a>b.a;
}
int type_max[205];
int main(){
    int m,n,k;
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        cin >> type_max[i+1];
    }
    for(int i=0;i<n;i++){
        cin >> a[i].a >> a[i].b;
    }
    sort(a,a+m,cmp);
    int sumfat=0,eaten[205]={0};
    for(int i=0;i<n;i++){
        if(eaten[a[i].b]<type_max[a[i].b]){
            sumfat+=a[i].a;
            eaten[a[i].b]++;
        }
    }
    cout << sumfat;
    return 0;
}