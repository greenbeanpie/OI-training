#include<bits/stdc++.h>
using namespace std;
#define clo 1000.*clock()/CLOCKS_PER_SEC
#ifndef xxzx
#define endl '\n'
#endif
using ll=long long;
using PII=pair<int,int>;
const int N=2e5+10;
bool mem1;
int Case,T;
ll n,m,k,d;
vector<PII> nd[N];
ll f[N],g[N];
const ll INF=0x3f3f3f3f3f3f3f3f;
struct Segt {
    #define ls (id<<1)
    #define rs (id<<1|1)
    ll v[N<<2],lz[N<<2];
    void Build(int id,int l,int r) {
        v[id]=0, lz[id]=0;
        if(l==r) return;
        int mid=(l+r)>>1;
        Build(ls,l,mid), Build(rs,mid+1,r);
    }
    void pushdown(int id) {
        if(!lz[id]) return;
        ll val=lz[id]; lz[id]=0;
        v[ls]+=val, lz[ls]+=val;
        v[rs]+=val, lz[rs]+=val;
    }
    void Modify(int id,int l,int r,int x,int y,ll val) {
        if(x<=l&&y>=r) {
            v[id]+=val, lz[id]+=val;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(id);
        if(x<=mid) Modify(ls,l,mid,x,y,val);
        if(y>mid) Modify(rs,mid+1,r,x,y,val);
        v[id]=max(v[ls],v[rs]);
    }
    void Modify2(int id,int l,int r,int x,ll val) {
        if(l==r) return v[id]=val, void();
        int mid=(l+r)>>1;
        pushdown(id);
        if(x<=mid) Modify2(ls,l,mid,x,val);
        else Modify2(rs,mid+1,r,x,val);
        v[id]=max(v[ls],v[rs]);
    }
    ll Query(int id,int l,int r,int x,int y) {
        if(x<=l&&y>=r) return v[id];
        int mid=(l+r)>>1;
        pushdown(id);
        if(y<=mid) return Query(ls,l,mid,x,y);
        if(x>mid) return Query(rs,mid+1,r,x,y);
        return max(Query(ls,l,mid,x,y),Query(rs,mid+1,r,x,y));
    }
}sg;
struct Option {
    int x,y,v;
}mem[N];
ll X[N],tot;
int read() {
    int f=1,z=0; char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f*=-1; 
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        z=z*10+ch-'0'; ch=getchar();
    }
    return f*z;
}
void solve() {
    n=read(), m=read(), k=read(), d=read();
    tot=0;
    for(int i=1,x,y,v;i<=m;i++) {
        x=read(), y=read(), v=read();
        mem[i]={x-y,x,v};
        X[++tot]=x, X[++tot]=x-y;
    }
    X[++tot]=0;
    sort(X+1,X+tot+1);
    tot=unique(X+1,X+tot+1)-X-1;
    for(int i=1;i<=m;i++) {
        int x=lower_bound(X+1,X+tot+1,mem[i].x)-X;
        int y=lower_bound(X+1,X+tot+1,mem[i].y)-X;
        nd[y].emplace_back(x,mem[i].v);
    }
    memset(f,-0x3f,sizeof(f)), memset(g,0,sizeof(g));
    sg.Build(1,1,tot);
    for(int i=2;i<=tot;i++) {
        for(auto now:nd[i]) 
            sg.Modify(1,1,tot,1,now.first,now.second);
        int p=lower_bound(X+1,X+tot+1,max(0ll,X[i]-k))-X;
        if(p<=i-1) f[i]=sg.Query(1,1,tot,p,i-1)-X[i]*d;
        g[i]=max(g[i-1],f[i-1]);
        sg.Modify2(1,1,tot,i,g[i]+X[i]*d);
        // cerr<<i<<" "<<X[i]<<" "<<f[i]<<" "<<p<<endl;
    }
    // for(int i=1;i<=n;i++) cerr<<f[i]<<" ";
    // cerr<<endl;
    cout<<max(g[tot],f[tot])<<endl;
    for(int i=1;i<=tot;i++) nd[i].clear();
}
bool mem2;
int main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    Case=read(), T=read();
    while(T--) solve();

    #ifdef xxzx
    cerr<<"Time "<<clo<<"MS"<<endl;
    cerr<<"Memory "<<abs(&mem1-&mem2)/1024./1024.<<"MB"<<endl;
    #endif
    return 0;
}
// 2*N memory