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
const int N=4e5+5;
const int T=200001,U=200002,F=400003;
int typ,n,m,ext;
int fd[N],id[N];
inline int neg(const int&x){
    if(x==U)return x;
    if(x<200002)return x+200002;
    else return x-200002;
}
inline int find(const int&x){
    return fd[x]==x?x:fd[x]=find(fd[x]);
}
inline void merge(const int&u,const int&v){
    fd[find(u)]=find(v),fd[find(neg(u))]=find(neg(v));
}
inline void MAIN(){
    n=ext=read(),m=read();
    iota(id+1,id+n+1,1);
    iota(fd+1,fd+N,1);
    for(int i=1;i<=m;++i){
        char c=read<char>();
        int x=read();
        if(c=='T')merge(T,++ext),id[x]=ext;
        else if(c=='F')merge(F,++ext),id[x]=ext;
        else if(c=='U')merge(U,++ext),id[x]=ext;
        else if(c=='+')merge(id[read()],++ext),id[x]=ext;
        else merge(neg(id[read()]),++ext),id[x]=ext;
    }
    for(int i=1;i<=n;++i)merge(id[i],i);
    int ans=0;
    for(int i=1;i<=n;++i)if(find(i)==find(neg(i)))++ans;
    printf("%d\n",ans);
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    typ=read();
    for(int T=read();T--;MAIN());
    return 0;
}
/*

*/