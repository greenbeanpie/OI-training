#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define i64 long long
#define pii pair<int,int>
inline int read(void) {
    int sgn=1,x=0; char c=getchar();
    while(c< '0'||'9'< c) { c=='-' && (sgn=0); c=getchar(); }
    while('0'<=c&&c<='9') { x=x*10+c-'0'; c=getchar(); }
    return sgn ? x : -x;
}
void write(i64 x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar('0'+x%10);
}
const i64 iii=3e18;
int n,m,k,d; i64 Ans;
struct task {
    int l,r,v;
} q[100005];
int nxt[100005];
pii cr[100005];
inline void solvenxt(void) {
    int cur=m+1;
    for(int i=m; i>=1; --i) {
        while(q[cur-1].l>cr[i].first+1) --cur;
        nxt[cr[i].second]=cur;
    }
    // for(int i=1; i<=m; ++i) cerr<<nxt[i]<<' ';
    // cerr<<endl;
}
#define lch (x<<1)
#define rch (x<<1|1)
#define lowbit(x) (x&(-x))
i64 seg[400005],tag[400005],sss[400005];
i64 f[100005]; // BIT
inline void updf(int p,i64 v) { for(; p<=m+1; p+=lowbit(p)) f[p]=max(f[p],v); }
inline i64 qryf(int p) {
    i64 res=0;
    for(; p; p-=lowbit(p)) res=max(res,f[p]);
    return res;
}
inline void pushup(int x) { 
    seg[x]=max(seg[lch],seg[rch])+tag[x]; 
    sss[x]=sss[lch]+sss[rch];
}
inline void pushdown(int x) {
    tag[lch]+=tag[x]; seg[lch]+=tag[x];
    tag[rch]+=tag[x]; seg[rch]+=tag[x];
    tag[x]=0;
}
void build(int x,int l,int r) {
    tag[x]=0;
    if(l==r) return seg[x]=-iii,sss[x]=0,void();
    int mid=(l+r)>>1;
    build(lch,l,mid);
    build(rch,mid+1,r);
    pushup(x);
}
void ins(int x,int l,int r,int p,i64 v) {  
    if(l==r) return seg[x]=v+tag[x],sss[x]=0,void();
    pushdown(x);
    int mid=(l+r)>>1;
    if(p<=mid) ins(lch,l,mid,p,v);
    else ins(rch,mid+1,r,p,v);
    pushup(x);
}
void upd(int x,int l,int r,int ql,int qr,i64 v) {
    if(ql<=l&&r<=qr) return tag[x]+=v,seg[x]+=v,void();
    int mid=(l+r)>>1;
    if(ql<=mid) upd(lch,l,mid,ql,qr,v);
    if(qr> mid) upd(rch,mid+1,r,ql,qr,v);
    pushup(x);
}
i64 qry(int x,int l,int r,int ql,int qr) {
    if(ql<=l&&r<=qr) return seg[x];
    int mid=(l+r)>>1; i64 res=-iii;
    if(ql<=mid) res=max(res,qry(lch,l,mid,ql,qr));
    if(qr> mid) res=max(res,qry(rch,mid+1,r,ql,qr));
    return res+tag[x];
}
i64 qrysum(int x,int l,int r,int ql,int qr) {
    if(ql<=l&&r<=qr) return sss[x];
    int mid=(l+r)>>1; i64 res=0;
    if(ql<=mid) res=res+qrysum(lch,l,mid,ql,qr);
    if(qr> mid) res=res+qrysum(rch,mid+1,r,ql,qr);
    return res;
}
inline void work(void) {
    n=read(); m=read(); k=read(); d=read();
    for(int i=1; i<=m; ++i) {
        q[i].r=read();
        q[i].l=q[i].r-read()+1;
        q[i].v=read();
        // cerr<<q[i].l<<' '<<q[i].r<<' '<<q[i].v<<endl;
    }
    // cerr<<"--------";
    sort(q+1,q+m+1,[&](task A,task B){ return A.l<B.l; });
    for(int i=1; i<=m; ++i) cr[i]=make_pair(q[i].r,i);
    sort(cr+1,cr+m+1);
    solvenxt();
    build(1,1,m);
    int cur=1;
    int L=1;
    for(int i=1; i<=m; ++i) {
        int x=cr[i].second;
        while(q[L].l<=q[x].r-k) ++L;
        if(L>x) continue;
        // cerr<<"------"<<endl;
        // cerr<<"work "<<x<<' '<<q[x].l<<' '<<q[x].r<<" with L = "<<L<<endl;
        ins(1,1,m,x,1ll*d*(q[x].l-1)+qryf(x));
        // cerr<<"ins "<<x<<' '<<1ll*d*(q[x].l-1)<<" + "<<qryf(x)<<endl;
        // cerr<<"qry "<<x<<" = "<<qrysum(1,1,m,x+1,m)<<" + "<<qry(1,1,m,L,x)
        // <<" - "<<1ll*d*q[i].r<<endl;
        // upda(1,1,m,x,q[x].v);
        upd(1,1,m,1,x,q[x].v);
        i64 r=max(qryf(x),qry(1,1,m,L,x)-1ll*d*q[x].r);
        updf(nxt[x],r);
    }
    write(qryf(m+1)); puts("");
    for(int i=0; i<=m+2; ++i) f[i]=0;
}
signed main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    read(); int T=read();
    while(T--) work();
    // fprintf(stderr,"%.3lf\n",1.0*clock()/CLOCKS_PER_SEC);
    return 0;
}