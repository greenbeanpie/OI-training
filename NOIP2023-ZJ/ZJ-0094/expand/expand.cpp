#include<bits/stdc++.h>
#define ll long long
#define Ci const int
#define Cc const char
#define Cl const ll
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define For(i_,l_,r_) for(int i_=l_,p_=r_;i_<=p_;i_++)
#define Rep(i_,l_,r_) for(int i_=l_,p_=r_;i_>=p_;i_--)
using namespace std;
#define _c_ getchar()
#define getchar() (_u==_v&&(_v=(_u=_c)+fread(_c,1,inS,stdin),_u==_v)?EOF:*_u++)
Ci inS=1<<20,ouS=1<<20;
char _c[inS],*_u=_c,*_v=_c,_b[ouS],_d[55];int _p,_l=-1;
template<typename T=int>inline T read(){
    T x=0;bool fl=0;char ch=_c_;while(ch<48||ch>57)fl|=(ch==45),ch=_c_;
    while(ch>47&&ch<58)x=x*10+(ch^48),ch=_c_;return fl?-x:x;
}
inline char Gec(){char ch=_c_;while(ch<33)ch=_c_;return ch;}
inline void flush(){fwrite(_b,1,_l+1,stdout);_l=-1;}
inline void _pc(Cc c){if(c!=-1)_b[++_l]=c;}
inline void _chf(){if(_l>(ouS>>1))flush();}
template<typename T>inline void write(T x,char ch=-1){
    if(x<0)_pc(45),x=-x;do{_d[++_p]=(x%10)|48;}while(x/=10);
    do{_pc(_d[_p]);}while(--_p);_pc(ch);_chf();
}
Ci N_=5e5+5;
int N,M,Q,A[N_],B[N_],aa[N_],bb[N_];
int n,m,a[N_],b[N_],f[N_];
struct SGT{
    struct T{
        int mn,mx;
    }tr[N_<<2];
    #define u (s<<1)
    #define v (s<<1|1)
    inline void push_up(Ci s){
        tr[s].mn=min(tr[u].mn,tr[v].mn);
        tr[s].mx=max(tr[u].mx,tr[v].mx);
    }
    void build(Ci l,Ci r,Ci s){
        if(l==r){tr[s]={b[l],b[l]};return;}
        Ci mid=(l+r)>>1;
        build(l,mid,u);
        build(mid+1,r,v);
        push_up(s);
    }
    int find(Ci x,Ci k,Ci l,Ci r,Ci s){
        // cerr<<x<<" "<<k<<' '<<l<<" "<<r<<" "<<s<<"\n";
        if(l==r)return tr[s].mn>=k?-1:l;
        Ci mid=(l+r)>>1;
        if(mid>=x)return find(x,k,l,mid,u);
        int g=find(x,k,mid+1,r,v);
        if(g!=-1)return g;
        if(tr[u].mn>=k)return -1;
        return find(x,k,l,mid,u);
    }
    int find2(Ci x,Ci k,Ci l,Ci r,Ci s){
        // cerr<<x<<" "<<k<<' '<<l<<" "<<r<<" "<<s<<"\n";
        if(l==r)return tr[s].mn>=k?-1:l;
        Ci mid=(l+r)>>1;
        if(mid<x)return find2(x,k,mid+1,r,v);
        int g=find2(x,k,l,mid,u);
        if(g!=mid)return g;
        // cerr<<"!! "<<mid+1<<' '<<r<<' '<<tr[v].mn<<" "<<k<<"\n";
        if(tr[v].mx<k)return r;
        int h=find2(x,k,mid+1,r,v);
        if(h==-1)return mid;
        return h;
    }
    #undef u
    #undef v
}t;
void work(){
    if(A[1]==B[1]||A[N]==B[M])return write(0);
    if((A[1]>B[1])!=(A[N]>B[M]))return write(0);
    if(A[1]<B[1]){
        n=M,m=N;
        For(i,1,n)a[i]=B[i];
        For(i,1,m)b[i]=A[i];
    }
    else{
        n=N,m=M;
        For(i,1,n)a[i]=A[i];
        For(i,1,m)b[i]=B[i];
    }
    t.build(1,m,1);
    f[1]=t.find2(1,a[1],1,m,1);
    // cerr<<1<<' '<<f[1]<<"\n";
    For(i,2,n){
        int j=t.find(f[i-1],a[i],1,m,1);
        int k=t.find2(j,a[i],1,m,1);
        if(j==-1)return write(0);
        // cerr<<i<<' '<<j<<" "<<k<<"\n";
        f[i]=k;
        //the first b[j] before f[i-1] smaller than a[i]
        //the length of max subarray begin with j and all of b[s](s in [j,k])<a[i]
    }
    return write((int)(f[n]==m));
}
inline void init(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    atexit(flush);read();
    N=read(),M=read(),Q=read();
    For(i,1,N)A[i]=aa[i]=read();
    For(i,1,M)B[i]=bb[i]=read();
    work();
}
inline void ypa(){
    // cerr<<"---------------\n";
    int kx=read(),ky=read();
    For(i,1,N)A[i]=aa[i];
    For(i,1,M)B[i]=bb[i];
    For(i,1,kx){
        int p=read(),x=read();
        A[p]=x;
    }
    For(i,1,ky){
        int p=read(),x=read();
        B[p]=x;
    }
    // For(i,1,n)cerr<<A[i]<<" ";cerr<<"\n";
    // For(i,1,m)cerr<<B[i]<<" ";cerr<<"\n";
    work();
}
signed main(){init();int T=Q;For(i,1,T)ypa();return 0;}