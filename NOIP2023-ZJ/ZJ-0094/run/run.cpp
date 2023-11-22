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
Ci N_=2e5+5;
int Q,CCC;
inline void init(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    atexit(flush);CCC=read(),Q=read();
}
int n,m,k,d;
struct N{
    int l,r,w;
    inline bool operator<(const N&U)const{
        return r<U.r;
    }
}a[N_];
int B[N_],L;
ll f[N_],S[N_],ss[N_];
map<int,bool>mp;
inline void ypa(){
    L=0;mp.clear();
    n=read(),m=read(),k=read(),d=read();
    For(i,1,m){
        int x=read(),y=read(),w=read();
        a[i]={x-y+1,x,w};B[++L]=x;B[++L]=x-y+1;
        mp[x]=1;
    }
    sort(B+1,B+1+L);L=unique(B+1,B+1+L)-B-1;
    sort(a+1,a+1+m);
    int P=1;
    For(i,1,L){
        if(!mp[B[i]]){f[i]=f[i-1];continue;}
        f[i]=0;
        while(P<=m&&a[P].r==B[i])ss[lower_bound(B+1,B+1+L,a[P].l)-B]+=a[P].w,++P;
        ll pres=0;
        Rep(j,i,0){
            pres+=ss[j];ss[j]=0;S[j]+=pres;
            if(B[i]-B[j]>k+1)break;
            if(B[i]-B[j]>=2){
                ll uss=0;
                For(I,1,m)
                    if(B[j]+2<=a[I].l&&a[I].r<=B[i])uss+=a[I].w;
                f[i]=max(f[i],f[j]+uss-1ll*(B[i]-B[j]-1)*d);
                // int u=B[j]+2;
                // if(u==B[j+1])u=j+1;
                // else if(u==B[j+2])u=j+2;
                // else u=j+1;
                // f[i]=max(f[i],f[j]+S[u]-1ll*(B[i]-B[j]-1)*d);
            }
        }
        f[i]=max(f[i],f[i-1]);
        // cerr<<i<<" "<<B[i]<<" "<<f[i]<<"\n";
    }
    write(f[L],'\n');
    For(i,1,L)ss[i]=S[i]=f[i]=0;
}
signed main(){init();int T=Q;For(i,1,T)ypa();return 0;}