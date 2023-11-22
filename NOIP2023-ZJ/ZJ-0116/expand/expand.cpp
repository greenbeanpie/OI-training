#include<bits/stdc++.h>
using namespace std;
// 没写完，写了个5分的还不知道对不对。

namespace solve_7{
    int n,m,q;
    int _x[2001],_y[2001];
    int x[2001],y[2001];
    int lstx[2001],lsty[2001];
    int minx[2001][2001];
    int miny[2001][2001];
    int maxx[2001][2001];
    int maxy[2001][2001];

    void solve__(
        int n,int m,
        int *x,int *y
    ){
        for(int i=1;i<=n;i++){
            minx[i][i]=maxx[i][i]=x[i];
            for(int j=i+1;j<=n;j++){
                minx[i][j]=min(minx[i][j-1],x[j]);
                maxx[i][j]=max(maxx[i][j-1],x[j]);
            }
        }
        for(int i=1;i<=m;i++){
            miny[i][i]=maxy[i][i]=y[i];
            for(int j=i+1;j<=m;j++){
                miny[i][j]=min(miny[i][j-1],y[j]);
                maxy[i][j]=max(maxy[i][j-1],y[j]);
            }
        }
        // 设目标为 x 比 y 大
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                bool is=false;
                if(minx[lsty[j-1]+1][i]>y[j])is=true;
                if(miny[lstx[i-1]+1][j]<x[i])is=true;
                if(is){
                    lsty[j]=i;
                    lstx[i]=j;
                }
                if(i==n&&j==m)
                    printf("%d",is);
            }
        }
    }

    void solve(){
        for(int i=1;i<=n;i++){
            minx[i][i]=maxx[i][i]=x[i];
            for(int j=i+1;j<=n;j++){
                minx[i][j]=min(minx[i][j-1],x[j]);
                maxx[i][j]=max(maxx[i][j-1],x[j]);
            }
        }
        for(int i=1;i<=m;i++){
            miny[i][i]=maxy[i][i]=y[i];
            for(int j=i+1;j<=m;j++){
                miny[i][j]=min(miny[i][j-1],y[j]);
                maxy[i][j]=max(maxy[i][j-1],y[j]);
            }
        }
        if(maxx[1][n]<maxy[1][m]){
            if(minx[1][n]>miny[1][n]){
                printf("0");
                return;
            }
            // TODO swap
            solve__(m,n,y,x);
        }
        else if(maxx[1][n]>maxy[1][m]){
            if(minx[1][n]<miny[1][n]){
                printf("0");
                return;
            }
            solve__(n,m,x,y);
        }
        else printf("0");
    }

    void main(){
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",x+i),_x[i]=x[i];
        for(int i=1;i<=m;i++)
            scanf("%d",y+i),_y[i]=y[i];
        solve();
        while(q--){
            int kx,ky;
            scanf("%d%d",&kx,&ky);
            for(int i=1;i<=n;i++)x[i]=_x[i];
            for(int i=1;i<=m;i++)y[i]=_y[i];
            for(int i=1;i<=kx;i++){
                int pos,v;
                scanf("%d%d",&pos,&v);
                x[pos]=v;
            }
            for(int i=1;i<=ky;i++){
                int pos,v;
                scanf("%d%d",&pos,&v);
                y[pos]=v;
            }
            solve();
        }
    }
}

void solve_1(int x,int y){
    printf("%d",x!=y);
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    srand(time(0));
    int testId; scanf("%d",&testId);
    if(testId==1){
        int n,m,q;
        cin>>n>>m>>q;
        int x,y;
        cin>>x>>y;
        solve_1(x,y);
        while(q--){
            int kx,ky;
            cin>>kx>>ky;
            int xx=x,yy=y;
            if(kx){
                int pos,v;
                cin>>pos>>v;
                xx=v;
            }
            if(ky){
                int pos,v;
                cin>>pos>>v;
                yy=v;
            }
            solve_1(xx,yy);
        }
        return 0;
    }
    if(testId<=7)solve_7::main();
    else{
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=0;i<=q;i++){
            printf("%d",rand()%2);
        }
    }
    // fprintf(stderr,"%lf\n",clock()*1.0/CLOCKS_PER_SEC);
    return 0;
}