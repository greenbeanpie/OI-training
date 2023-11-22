#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1010;
int c,n,m,k,d;
namespace stk1{
    LL s[N][N],f[N][N];
    void main(){
        memset(s,0,sizeof(s));
        for(int i=1;i<=m;i++){
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            s[x][y]+=v;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=min(n,k);j++)
                s[i][j]+=s[i][j-1];
        memset(f,-0x3f,sizeof(f));
        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,k);j++) f[i][0]=max(f[i][0],f[i-1][j]);
            for(int j=1;j<=min(i,k);j++)
                f[i][j]=f[i-1][j-1]-d+s[i][j];
        }
        LL ans=0;
        for(int j=0;j<=k;j++) ans=max(ans,f[n][j]);
        printf("%lld\n",ans);
        return;
    }
}
void calc(){
    scanf("%d%d%d%d",&n,&m,&k,&d);
    if(c<=9) stk1::main();
    else{
        for(int i=1;i<=m;i++){
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
        }
        puts("0");
    }
    return;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int T;
    scanf("%d%d",&c,&T);
    while(T--) calc();
    return 0;
}