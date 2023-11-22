#include<bits/stdc++.h>
#define LL long long
#define uint unsigned
#define LLL __int128_t
#define ldb long double
using namespace std;
char rdc[1<<14],*rS,*rT;
#define gc() (rS==rT?rT=(rS=rdc)+fread(rdc,1,1<<14,stdin),rS==rT?EOF:*rS++:*rS++)
template<class T=int>inline T read(){
    T x(0);char c;bool f(1);
    while(!isdigit(c=gc()))if(c==45)f=!f;
    if(f)do x=x*10+(c&15);while(isdigit(c=gc()));
    else do x=x*10-(c&15);while(isdigit(c=gc()));
    return x;
}
template<>inline char read(){char c;while((c=gc())<33);return c;}
inline int read(char*s){
    char c,*t=s;
    while((c=gc())<33);
    do *t++=c;while((c=gc())>32);
    return *t=0,t-s;
}
const int N=5e5+5;
int typ,n,m,q;
int T[N<<2],S[N<<2];
int a[N],b[N],ca[N],cb[N];
inline void build(int p,int l,int r,int*a){
    if(l==r)return T[p]=S[p]=a[l],void();
    int mid=(l+r)>>1;
    build(p<<1,l,mid,a);
    build(p<<1|1,mid+1,r,a);
    T[p]=min(T[p<<1],T[p<<1|1]);
    S[p]=max(S[p<<1],S[p<<1|1]);
}
inline int qryR(int p,int l,int r,int x,int y){
    if(T[p]>y)return r;
    if(l==r)return l-1;
    int mid=(l+r)>>1,res=mid;
    if(x<=mid)res=qryR(p<<1,l,mid,x,y);
    if(res==mid)res=qryR(p<<1|1,mid+1,r,x,y);
    return res;
}
inline int qryL(int p,int l,int r,int x,int y){
    if(S[p]<=y)return l-1;
    if(l==r)return l;
    int mid=(l+r)>>1,res=mid;
    if(x>mid)res=qryL(p<<1|1,mid+1,r,x,y);
    if(res==mid)res=qryL(p<<1,l,mid,x,y);
    return res;
}
inline bool solve(int*a,int n,int*b,int m){
    build(1,1,m,b);
    for(int i=1,j=0;i<=n;++i){
        if(j<m&&a[i]<b[j+1])j=qryR(1,1,m,j+1,a[i]);
        else j=j?qryL(1,1,m,j,a[i]):0;
        if(!j||(i==n&&j!=m))return 0;
    }
    return 1;
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    typ=read(),n=read(),m=read(),q=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i]=read();
    putchar((solve(a,n,b,m)||solve(b,m,a,n))?49:48);
    for(int i=1;i<=q;++i){
        int ka=read(),kb=read();
        copy(a+1,a+n+1,ca+1);
        copy(b+1,b+m+1,cb+1);
        for(int j=1;j<=ka;++j){
            int x=read(),y=read();
            ca[x]=y;
        }
        for(int j=1;j<=kb;++j){
            int x=read(),y=read();
            cb[x]=y;
        }
        putchar((solve(ca,n,cb,m)||solve(cb,m,ca,n))?49:48);
    }
    return 0;
}
/*

*/