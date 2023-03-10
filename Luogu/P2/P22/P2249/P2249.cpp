#include <bits/stdc++.h>
using namespace std;
int n,m,num[1000000];

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        //cin >> num[i];
        scanf("%d",&num[i]);
    }
    int q;
    for(int i=0;i<m;i++){
        //cin >> q;
        scanf("%d",&q);
        //cout << lookfor(q) << " ";
        int ans=*lower_bound(num,num+n,q);
        if(ans!=q){
            printf("%d ",-1);
            continue;
        }
        else printf("%ld ",(lower_bound(num,num+n,q)-num + 1));
    }
    return 0;
}