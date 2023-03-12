#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum[1005][1005]={0},num[1005][1005]={0};

signed main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> num[i][j];
        }
    }
    sum[0][0]=num[0][0];
    for(int i=1;i<n;i++){
        sum[i][0]=sum[i-1][0]+num[i][0];
        for(int j=1;j<=i+1;j++){
            sum[i][j]=max(sum[i-1][j],sum[i-1][j-1])+num[i][j];
        }
    }
    int maxinum=-1;
    for(int i=0;i<n;i++){
        maxinum=max(sum[n-1][i],maxinum);
    }
    cout << maxinum;
    return 0;
}