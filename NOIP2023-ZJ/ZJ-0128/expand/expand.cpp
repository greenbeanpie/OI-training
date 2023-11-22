/*
9：31
第一个和最后一个是最重要的。我们先把两个序列的最大值分别求出，然后比较就知道哪个序列
是恒大于另外一个的了。
对于小的要尽可能拓展最小的
想到一个dp转移。
转移成功！-9:56
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int cid,n,m,q;
int a[N],b[N];
namespace subtask1{
    bool f[2003][2003];
    int x[2003],y[2003];
    bool DP(){
        // memset(f,0,sizeof(f));
        f[0][0]=f[1][0]=f[0][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=((f[i-1][j]&(x[i]<y[j]))|(f[i][j-1]&(x[i]<y[j])));
            }
        }
        if(f[n][m])return 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=((f[i-1][j]&(x[i]>y[j]))|(f[i][j-1]&(x[i]>y[j])));
            }
        }
        return f[n][m];
    }
    bool work(){
        for(int i=1;i<=n;i++)x[i]=a[i];
        for(int i=1;i<=m;i++)y[i]=b[i];
        putchar(DP()?'1':'0');
        while(q--){
            for(int i=1;i<=n;i++)x[i]=a[i];
            for(int i=1;i<=m;i++)y[i]=b[i];
            int chx=read(),chy=read();
            for(int i=1;i<=chx;i++){
                int loc=read(),v=read();
                x[loc]=v;
            }
            for(int i=1;i<=chy;i++){
                int loc=read(),v=read();
                y[loc]=v;
            }
            putchar(DP()?'1':'0');
        }
        return 0;
    }
}
int x[N],y[N];
bool check(){
    int maxx=0,minx=1e9,maxy=0,miny=1e9;
    for(int i=1;i<=n;i++)maxx=max(maxx,x[i]),minx=min(minx,x[i]);
    for(int i=1;i<=m;i++)maxy=max(maxy,y[i]),miny=min(miny,y[i]);
    if(minx>miny&&maxx>maxy&&x[1]>y[1]&&x[n]>y[m])return 1;
    if(minx<miny&&maxx<maxy&&x[1]<y[1]&&x[n]<y[m])return 1;
    return 0;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cid=read(),n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }   
    for(int i=1;i<=m;i++){
        b[i]=read();
    }
    if(cid<=7)return subtask1::work(),0;
    while(q--){
        for(int i=1;i<=n;i++)x[i]=a[i];
        for(int i=1;i<=m;i++)y[i]=b[i];
        putchar(check()?'1':'0');
        for(int ww=1;ww<=q;ww++){
            for(int i=1;i<=n;i++)x[i]=a[i];
            for(int i=1;i<=m;i++)y[i]=b[i];
            int chx=read(),chy=read();
            for(int i=1;i<=chx;i++){
                int loc=read(),v=read();
                x[loc]=v;
            }
            for(int i=1;i<=chy;i++){
                int loc=read(),v=read();
                y[loc]=v;
            }
            putchar(check()?'1':'0');
        }
    }
    return 0;
}