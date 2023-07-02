#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 3
#define mod 1000000007
struct matrix{
    int m[max_matrix+1][max_matrix+1]={0};
    void init(){
        for(int i=1;i<=max_matrix;i++){
            m[i][i]=1;
        }
    }
};
matrix operator*(matrix a,matrix b){
    matrix ans;
    for(int i=1;i<=max_matrix;i++){
        for(int j=1;j<=max_matrix;j++){
            for(int k=1;k<=max_matrix;k++){
                ans.m[i][j]+=a.m[i][k]*b.m[k][j];
                ans.m[i][j]%=mod;
            }
        }
    }
    return ans;
}
matrix quickpower(matrix base,int t){
    matrix ans=base;
    while(t){
        if(t&1){
            ans=base*ans;
        }
        base=base*base;
        t>>=1;
    }
    return ans;
}
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1||n==2){
        return 1;
    }
    matrix ans;
    ans.m[1][1]=ans.m[1][2]=ans.m[2][1]=1;
    return quickpower(ans,n-2).m[1][1];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("C.in","r",stdin);
    #endif*/
    int n;
    cin >> n;
    cout << fibonacci(n)%mod;
    return 0;
}