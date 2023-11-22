#include <bits/stdc++.h>
typedef unsigned uint;
typedef long long llt;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return a<b?(a=b,true):false;}
template<typename T>bol _min(T&a,T b){return b<a?(a=b,true):false;}
namespace Seg
{
    const uint Lim=262144;
    llt Max[Lim<<1|1],Tag[Lim<<1|1];
    voi clear(){for(uint i=0;i<Lim*2;i++)Max[i]=Tag[i]=0;}
    voi add(uint l,uint r,llt w,uint u=1,uint n=Lim)
    {
        if(l>=r)return;
        if(!l&&r==n){Max[u]+=w,Tag[u]+=w;return;}
        if(l<(n>>1))
            if(r<=(n>>1))add(l,r,w,u<<1,n>>1);
            else add(l,n>>1,w,u<<1,n>>1),add(0,r-(n>>1),w,u<<1|1,n>>1);
        else add(l-(n>>1),r-(n>>1),w,u<<1|1,n>>1);
        Max[u]=Tag[u]+std::max(Max[u<<1],Max[u<<1|1]);
    }
    llt find(uint l,uint r,uint u=1,uint n=Lim)
    {
        if(l>=r)return 0;
        if(!l&&r==n)return Max[u];
        if(l<(n>>1))
            if(r<=(n>>1))return find(l,r,u<<1,n>>1)+Tag[u];
            else return std::max(find(l,n>>1,u<<1,n>>1),find(0,r-(n>>1),u<<1|1,n>>1))+Tag[u];
        else return find(l-(n>>1),r-(n>>1),u<<1|1,n>>1)+Tag[u];
    }
}
uint L[100005],R[100005],P[200005];llt W[100005];
std::vector<uint>V[200005];
voi solve()
{
    uint n,m,k;llt d;scanf("%u%u%u%lld",&n,&m,&k,&d);
    for(uint i=0;i<m;i++)scanf("%u%u%lld",R+i,L+i,W+i),L[i]=R[i]-L[i],P[i<<1]=L[i],P[i<<1|1]=R[i];
    std::sort(P,P+m*2);
    uint c=std::unique(P,P+m*2)-P;
    for(uint i=0;i<c;i++)V[i].clear();
    for(uint i=0;i<m;i++)if(R[i]-L[i]<=k)V[std::lower_bound(P,P+c,R[i])-P].push_back(i);
    Seg::clear();
    llt ans=0;
    for(uint i=0,j=0;i<c;i++)
    {
        while(P[i]-P[j]>k)j++;
        for(auto s:V[i])Seg::add(0,std::upper_bound(P,P+c,L[s])-P,W[s]);
        Seg::add(i,i+1,ans+d*(llt)P[i]),_max(ans,Seg::find(j,i)-d*(llt)P[i]);
    }
    printf("%lld\n",ans);
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
#endif
    uint t;scanf("%*u%u",&t);
    while(t--)solve();
    return 0;
}

/*

g++ run.cpp -o run -std=c++11 -Wall -fsanitize=undefined,address -DMYEE

*/
