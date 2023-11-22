//At best it's 35pts

/*  
    the mighty god blesses me!

    when I was young
    I listen to the radio
    waiting for my favorite code....
                             -- EDGW_

    I may be Away Of OI after this.

    I love OI, who didn't love me.

    A bunch of rose.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
int c,n,m,q;
int X[MAXN],Y[MAXN];
int A[MAXN],B[MAXN];
typedef function<bool(const int&a,const int&b)> pred;
bool greater_func(const int&a,const int&b){
    return a>b;
}
bool less_func(const int&a,const int&b){
    return a<b;
}
bool dp[MAXN][MAXN];
bool solve(){
    /*printf("A:");
    for(int i = 1;i<=n;i++){
        printf("%d ",A[i]);
    }
    printf("\nB:");
    for(int i = 1;i<=m;i++){
        printf("%d ",B[i]);
    }
    printf("\n");*/
    if(A[1]==B[1])return false;
    pred p;
    if(A[1]>B[1])p=greater_func;
    else p = less_func;
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    for(int j = 1;j<=m;j++)
    {
        dp[1][j]=dp[1][j-1]&p(A[1],B[j]);
        //printf("dp[%d][%d] is %d\n",1,j,dp[1][j]);
    }
    for(int i = 2;i<=n;i++){
        dp[i][1]=p(A[i],B[1])&&(dp[i-1][1]);
        //printf("dp[%d][%d] is %d\n",i,1,dp[i][1]);
        for(int j = 2;j<=m;j++){
            if(p(A[i],B[j])){
                dp[i][j]=dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
            }
            //printf("dp[%d][%d] is %d\n",i,j,dp[i][j]);
        }
    }
    return dp[n][m];
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i = 1;i<=n;i++)scanf("%d",&X[i]);
    for(int i = 1;i<=m;i++)scanf("%d",&Y[i]);
    memcpy(A,X,sizeof(X));
    memcpy(B,Y,sizeof(X));
    printf("%d",solve());
    while(q--){
        memcpy(A,X,sizeof(X));
        memcpy(B,Y,sizeof(X));
        int kx,ky;scanf("%d%d",&kx,&ky);
        for(int i = 1;i<=kx;i++){
            int p,v;scanf("%d%d",&p,&v);
            A[p]=v;
        }
        for(int i = 1;i<=ky;i++){
            int p,v;scanf("%d%d",&p,&v);
            B[p]=v;
        }
        printf("%d",solve());
    }
    printf("\n");
}