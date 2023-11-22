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
const int N=1e5+5,M=N<<2;
const LL INF=4e18;
int typ,n,m,k,d,cnt,top;
vector<int>vec[N];
int L[N],R[N],TR[N],stk[N];
LL c[N],f[N],mn[M],se[M],mx[M],tg[M],ad[M];
struct node{int l,r;LL v;}A[N];
inline void build(int p,int l,int r){
    mn[p]=mx[p]=ad[p]=0,tg[p]=-INF,se[p]=INF;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(p<<1,l,mid),build(p<<1|1,mid+1,r);
}
inline void Add(int p,LL v){
    mn[p]+=v,mx[p]+=v,ad[p]+=v;if(se[p]<INF)se[p]+=v;
}
inline void Max(int p,LL v){
    mn[p]=v,tg[p]=v-ad[p],mx[p]=max(mx[p],v);
}
inline void pushup(int p){
    int l=p<<1,r=l|1;
    mn[p]=min(mn[l],mn[r]),mx[p]=max(mx[l],mx[r]);
    se[p]=min(mn[l]==mn[p]?se[l]:mn[l],mn[r]==mn[p]?se[r]:mn[r]);
}
inline void pushdown(int p){
    int l=p<<1,r=l|1;
    if(mn[l]<tg[p])Max(l,tg[p]);
    if(mn[r]<tg[p])Max(r,tg[p]);
    Add(l,ad[p]),Add(r,ad[p]);
    tg[p]=-INF,ad[p]=0;
}
inline void add(int p,int l,int r,int x,int y,LL z){
    if(x<=l&&r<=y)return Add(p,z);
    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid)add(p<<1,l,mid,x,y,z);
    if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
    pushup(p);
}
inline void ins(int p,int l,int r,int x,LL y){
    if(mn[p]>=y)return;
    if(x<=l&&se[p]>y)return Max(p,y);
    int mid=(l+r)>>1;
    pushdown(p);
    if(x<=mid)ins(p<<1,l,mid,x,y);
    ins(p<<1|1,mid+1,r,x,y);
    pushup(p);
}
inline LL qry(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y)return mx[p];
    int mid=(l+r)>>1;
    pushdown(p);
    LL res=-INF;
    if(x<=mid)res=max(res,qry(p<<1,l,mid,x,y));
    if(y>mid)res=max(res,qry(p<<1|1,mid+1,r,x,y));
    return res;
}
inline void add(int x,LL y){
    x=lower_bound(TR+1,TR+cnt+1,x)-TR;
    for(;x<=cnt;x+=x&-x)c[x]+=y;
}
inline LL sum(int x){
    LL res=0;
    x=lower_bound(TR+1,TR+cnt+1,x)-TR;
    for(;x;x-=x&-x)res+=c[x];
    return res;
}
inline void MAIN(){
    n=read(),m=read(),k=read(),d=read(),cnt=0;
    for(int i=1;i<=m;++i){
        int x=read(),y=read(),v=read();
        if(y<=x&&y<=k)A[++cnt]={x-y+1,x,v};
    }
    sort(A+1,A+(m=cnt)+1,[&](const node&i,const node&j){
        return i.l!=j.l?i.l<j.l:i.r<j.r;
    });
    for(int i=1;i<=m;++i)L[i]=A[i].l,R[i]=TR[i]=A[i].r,vec[i].clear();
    sort(TR+1,TR+m+1),cnt=unique(TR+1,TR+m+1)-(TR+1);
    fill(c+1,c+cnt+1,0);
    for(int i=m;i>=1;--i)add(A[i].r,A[i].v),A[i].v=sum(A[i].r);
    for(int i=1;i<=m;++i)
        vec[lower_bound(L+1,L+m+1,R[i]+2)-L].emplace_back(i);
    build(1,1,m);
    for(int i=1,top=0;i<=m;++i){
        for(auto j:vec[i])ins(1,1,m,i,f[j]);
        for(;top&&R[stk[top]]<=R[i];--top)
            add(1,1,m,stk[top-1]+1,stk[top],-(R[i]-R[stk[top]])*1ll*d);
        stk[++top]=i,add(1,1,m,i,i,-(R[i]-L[i]+1ll)*d),add(1,1,m,1,i,A[i].v);
        f[i]=max(0ll,qry(1,1,m,max((int)(lower_bound(L+1,L+m+1,R[i]-k+1)-L),stk[top-1]+1),i));
    }
    printf("%lld\n",*max_element(f+1,f+m+1));
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    typ=read();
    for(int T=read();T--;MAIN());
    return 0;
}
/*

*/