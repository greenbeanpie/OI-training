#include <bits/stdc++.h>
using namespace std;
#define int long long
#define map unordered_map

signed main(){
#ifndef ONLINE_JUDGE
    freopen("P1638_4.in","r",stdin);
#endif
    int n,m;
    cin >> n >> m;
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%lld",nums+i);
    }
    int l=0,r=l+m-1;
    int a=INT_MIN,b=INT_MAX;
    while(l<n&&r<n){
        set<int> vis1;
        int vis[m+1]={0};
        for(int i=l;i<=r;i++){
            vis[nums[i]]++;
            vis1.insert(nums[i]);
        }
        while(vis1.size()<m&&r<n-1){
            r++;
            vis[nums[r]]++;
            vis1.insert(nums[r]);
        }
        if(vis1.size()<m){
            break;
        }
        while(true){
            if(vis[nums[l]]-1>0){
                vis[nums[l]]--;
                l++;
            }
            else if(vis[nums[l]]-1==0){
                break;
            }
        }
        if(r-l<b-a){
            a=l;
            b=r;
        }
        l++;
        r=l+m-1;
    }
    printf("%lld %lld",++a,++b);
    return 0;
}