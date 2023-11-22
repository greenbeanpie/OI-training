#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3010,MAXM=3010;
char strs[MAXN][MAXM];
char mxchr[MAXN],mnchr[MAXN];
int n,m;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==1){
        printf("1\n");
        return 0;    
    }
    for(int i = 1;i<=n;i++){
        scanf("%s",strs[i]);
        mxchr[i]='a';
        mnchr[i]='z';
        for(int j = 0;j<m;j++){
            mxchr[i]=max(mxchr[i],strs[i][j]);
            mnchr[i]=min(mnchr[i],strs[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        bool a = 1;
        for(int j = 1;j<=n;j++)if(i!=j){
            if(mnchr[i]>=mxchr[j])a=false;
        }
        printf("%d",a);
    }
    printf("\n");
    
}