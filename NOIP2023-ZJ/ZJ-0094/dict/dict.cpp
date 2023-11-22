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
Ci N_=3e3+5;
inline void init(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    atexit(flush);
}
int n,m;
string ans,ans1,a[N_];
inline void ypa(){
    n=read(),m=read();
    ans=ans1=" ";
    For(i,1,m)ans+='~',ans1+='~';
    For(i,1,n){
        string s=" ";
        For(j,1,m)s+=Gec();
        sort(s.begin()+1,s.begin()+1+m);
        a[i]=s;
        reverse(s.begin()+1,s.begin()+1+m);
        if(s<ans)ans1=ans,ans=s;
        else if(s<ans1)ans1=s;
    }
    For(i,1,n){
        string s=a[i];
        reverse(s.begin()+1,s.begin()+1+m);
        // cerr<<s<<' '<<a[i]<<" "<<ans<<"\n";
        if(ans==s){
            if(a[i]<ans1)_pc('1');
            else _pc('0');
        }
        else if(a[i]<ans)_pc('1');
        else _pc('0');
    }
}
signed main(){init();int T=1;For(i,1,T)ypa();return 0;}