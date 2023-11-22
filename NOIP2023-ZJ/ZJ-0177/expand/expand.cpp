#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int N=5e5+5;
const int M=2020;
int c,n,m,q;
int x[N],y[N];
int tx[N],ty[N];
namespace stk1{
    int f[M][M],g[M][M];
    void calc(){
        // for(int i=1;i<=n;i++) cerr<<x[i]<<",";cerr<<"\n";
        // for(int i=1;i<=m;i++) cerr<<y[i]<<",";cerr<<"\n";
        f[0][0]=g[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                f[i][j]=g[i][j]=0;
                if(x[i]<y[j]) f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
                if(x[i]>y[j]) g[i][j]=(g[i-1][j]|g[i][j-1]|g[i-1][j-1]);
            }
        // f[n][m]=g[n][m]=0;
        if(f[n][m]|g[n][m]) putchar('1');
        else putchar('0');
        return;
    }
    void main(){
        calc();
        for(int i=1;i<=q;i++){
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for(int j=1;j<=n;j++) x[j]=tx[j];
            for(int j=1;j<=m;j++) y[j]=ty[j];
            for(int j=1;j<=kx;j++){
                int px,vx;
                scanf("%d%d",&px,&vx);
                x[px]=vx;
            }
            for(int j=1;j<=ky;j++){
                int py,vy;
                scanf("%d%d",&py,&vy);
                y[py]=vy;
            }
            calc();
        }
        puts("");
        return;
    }
}
multiset<int>stx,sty;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]),tx[i]=x[i];
    for(int i=1;i<=m;i++) scanf("%d",&y[i]),ty[i]=y[i];
    if(c<=7) {stk1::main();return 0;}
    else{
        for(int i=1;i<=n;i++) stx.insert(x[i]);
        for(int i=1;i<=m;i++) sty.insert(y[i]);
        if((*stx.rbegin())<(*sty.begin()) || (*stx.begin())>(*sty.rbegin())) putchar('1');
        else putchar('0');
        for(int i=1;i<=q;i++){
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for(int j=1;j<=kx;j++){
                int px,vx;
                scanf("%d%d",&px,&vx);
                stx.erase(stx.find(x[px]));
                x[px]=vx;
                stx.insert(vx);
            }
            for(int j=1;j<=ky;j++){
                int py,vy;
                scanf("%d%d",&py,&vy);
                sty.erase(sty.find(y[py]));
                y[py]=vy;
                sty.insert(vy);
            }
            if((*stx.rbegin())<(*sty.begin()) || (*stx.begin())>(*sty.rbegin())) putchar('1');
            else putchar('0');
        }
    }
    return 0;
}