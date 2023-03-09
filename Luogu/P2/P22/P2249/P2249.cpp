#include <bits/stdc++.h>
using namespace std;

int n,m,num[1000000];

int lookfor(int q){
    int mid;
    int l=0,r=n-1;
    while(l<r){
        mid=(l+r)/2;
        if(num[mid]<q){
            l=mid+1;
        }
        else if(num[mid]>q){
            r=mid;
        }
        if(num[mid]==q){
            while(num[mid]==q){
                mid--;
            }
            return mid+2;
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        //cin >> num[i];
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    int q;
    for(int i=0;i<m;i++){
        //cin >> q;
        scanf("%d",&q);
        //cout << lookfor(q) << " ";
        printf("%d ",lookfor(q));
    }
    return 0;
}