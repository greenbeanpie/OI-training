#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3010;
const int INF=0x3f3f3f3f;
int n,m;
char s[N];
int minn[N],maxn[N];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        minn[i]=INF,maxn[i]=-INF;
        for(int j=1;j<=m;j++){
            minn[i]=min(minn[i],(int)s[j]);
            maxn[i]=max(maxn[i],(int)s[j]);
        }
    }
    for(int i=1;i<=n;i++){
        int ans=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(minn[i]>=maxn[j]){
                ans=0;
                break;
            }
        }
        putchar(ans+'0');
    }
    puts("");
    return 0;
}