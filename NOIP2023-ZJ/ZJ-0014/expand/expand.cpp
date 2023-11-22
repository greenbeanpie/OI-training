#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pii pair<int,int>
inline int read(void) {
    int sgn=1,x=0; char c=getchar();
    while(c< '0'||'9'< c) { c=='-' && (sgn=0); c=getchar(); }
    while('0'<=c&&c<='9') { x=x*10+c-'0'; c=getchar(); }
    return sgn ? x : -x;
}
void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar('0'+x%10);
}
int n,m,q;
int x[500005],y[500005];  // a=mx b=mi
int rx[500005],ry[500005];
int pmx[500005],pmi[500005],cnt;
int smx[500005],smi[500005],ccc;
inline void update() {
    int kx=read(); 
    int ky=read();
    for(int i=1; i<=n; ++i) rx[i]=x[i];
    for(int i=1; i<=m; ++i) ry[i]=y[i];
    for(int i=1,p,v; i<=kx; ++i) {
        p=read(); v=read();
        rx[p]=v;
    }
    for(int i=1,p,v; i<=ky; ++i) {
        p=read(); v=read();
        ry[p]=v;
    }
}
inline bool solve(int n,int a[],int m,int b[],bool ck=0) {
    if(b[1]>=a[1]||b[m]>=a[n]) return 0; 
    if(ck) {
        for(int i=1; i<=n; ++i) cerr<<a[i]<<" \n"[i==n];
        for(int i=1; i<=m; ++i) cerr<<b[i]<<" \n"[i==m];
    }
    pmx[0]=-1; cnt=0;
    for(int i=1; i<=n; ++i) {
        if(a[i]>=pmx[cnt]) {
            pmx[++cnt]=a[i];
            pmi[cnt]=a[i];
        } else {
            pmi[cnt]=min(pmi[cnt],a[i]);
        }
    }
    smx[0]=-1; ccc=0;
    for(int i=n; i>=1; --i) {
        if(a[i]>smx[ccc]) {
            smx[++ccc]=a[i];
            smi[ccc]=a[i];
        } else {
            smi[ccc]=min(smi[ccc],a[i]);
        }
    }
    int cur=1,L=m+1,R=-1;
    for(int i=1; i<=m; ++i) {
        while(b[i]<pmi[cur]&&cur<cnt) ++cur; 
        if(b[i]>=pmx[cur]) return 0;
        if(cur==cnt) L=min(L,i);
    }
    cur=1;
    for(int i=m; i>=1; --i) {
        while(b[i]<smi[cur]&&cur<ccc) ++cur; 
        if(b[i]>=smx[cur]) return 0;
        if(cur==ccc) R=max(R,i);
    }
    return L<=R;
    // if(cur==cnt) {
    //     for(int i=1; i<=n; ++i) cerr<<a[i]<<" \n"[i==n];
    //     for(int i=1; i<=m; ++i) cerr<<b[i]<<" \n"[i==m];
    // }
}
inline void work(bool ck=0) {
    write(solve(n,rx,m,ry,ck)|solve(m,ry,n,rx,ck));
    // if(ck) cerr<<"--------"<<endl;
}
signed main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read(); n=read(); m=read(); q=read();
    for(int i=1; i<=n; ++i) x[i]=read();
    for(int i=1; i<=m; ++i) y[i]=read();
    for(int i=1; i<=n; ++i) rx[i]=x[i];
    for(int i=1; i<=m; ++i) ry[i]=y[i];
    work();
    for(int i=1; i<=q; ++i) {
        update(),work();
    }
    puts("");
    return 0;
}