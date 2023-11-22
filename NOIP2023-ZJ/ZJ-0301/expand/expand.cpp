#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read() {
    int x=0;char c=getchar();bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x; return x;
}
const int maxn=500050;
int C,n,m,q,x[maxn],y[maxn];
bool ans[maxn];
namespace s1{
    bool f[2023][2023];
    bool calc()
    {
        if(x[1]==y[1]) return false;
        bool type=(x[1]<y[1]);
        For(i,0,n) For(j,0,m) f[i][j]=0;
        f[0][0]=1;
        if(type)
        {
            For(i,1,n)
                For(j,1,m)
                {
                    if(x[i]>=y[j]) continue;
                    if(i==1&&j==1||x[i-1]<y[j-1]) f[i][j]=f[i-1][j-1];
                    if(j>1&&x[i]<y[j-1]) f[i][j]|=f[i][j-1];
                    if(i>1&&x[i-1]<y[j]) f[i][j]|=f[i-1][j];
                }
        }
        else
        {
            For(i,1,n)
                For(j,1,m)
                {
                    if(x[i]<=y[j]) continue;
                    if(i==1&&j==1||x[i-1]>y[j-1]) f[i][j]=f[i-1][j-1];
                    if(j>1&&x[i]>y[j-1]) f[i][j]|=f[i][j-1];
                    if(i>1&&x[i-1]>y[j]) f[i][j]|=f[i-1][j];
                }
        }
        return f[n][m];
    }
    int ox[maxn],oy[maxn];
    void solve()
    {
        ans[0]=calc();
        For(i,1,n) ox[i]=x[i];
        For(i,1,m) oy[i]=y[i];
        For(tt,1,q)
        {
            int kx=read(),ky=read();
            For(i,1,kx)
            {
                int p=read(),v=read();
                x[p]=v;
            }
            For(i,1,ky)
            {
                int p=read(),v=read();
                y[p]=v;
            }
            // For(i,1,n) cout<<x[i]<<' '; cout<<endl;
            // For(i,1,n) cout<<y[i]<<' '; cout<<endl;
            ans[tt]=calc();
            For(i,1,n) x[i]=ox[i];
            For(i,1,m) y[i]=oy[i];
        }
        For(i,0,q) putchar(ans[i]?'1':'0');
        puts("");
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    C=read(); n=read(); m=read(); q=read();
    For(i,1,n) x[i]=read();
    For(i,1,m) y[i]=read();
    s1::solve();
    return 0;
}
/*
g++ expand/expand.cpp -O2 -Wall -o expand.exe
./expand.exe
*/