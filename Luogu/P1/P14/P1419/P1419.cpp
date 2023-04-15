#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define map unordered_map
#define multimap unordered_multimap

signed main(){
#ifndef ONLINE_JUDGE
    freopen("P1419.in","r",stdin);
#endif
    int n;
    scanf("%lld",&n);
    int s,t;
    scanf("%lld %lld",&s,&t);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%lld",nums+i);
    }
    int sum[n]={0};
    sum[0]=nums[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+nums[i];
    }
    int max_ave=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            max_ave=max(max_ave,(sum[j]-sum[i])/(i-j));
        }
    }
    cout << max_ave;
    return 0;
}