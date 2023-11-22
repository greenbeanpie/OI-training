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
inline int read(char*s){
    char c,*t=s;
    while((c=gc())<33);
    do *t++=c;while((c=gc())>32);
    return *t=0,t-s;
}
const int N=3e3+5;
int n,m,mx,se;
char s[N],a[N],b[N];
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=read(),m=read();
    b[0]=127;
    for(int i=1;i<=n;++i){
        read(s+1);
        a[i]=*min_element(s+1,s+m+1);
        b[i]=*max_element(s+1,s+m+1);
        if(b[i]<b[mx])se=mx,mx=i;
        else if(b[i]<b[se])se=i;
    }
    for(int i=1;i<=n;++i)
        putchar((mx==i?a[i]<b[se]:a[i]<b[mx])?49:48);
    return 0;
}
/*

*/