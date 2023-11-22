#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=100005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,K,d;
ll f[2][N];
struct node {
    int l,r,v;
    bool operator <(const node &o) const {return r<o.r;}
} a[N];
void solve() {
    cin>>n>>m>>K>>d;
    for(int i=1;i<=m;i++) {
        int x,y,v;
        cin>>x>>y>>v;
        a[i].l=x-y+1; a[i].r=x; a[i].v=v;
    }
    int cur=1,pre=0;
    sort(a+1,a+m+1);
    for(int i=0;i<=K;i++) f[1][i]=-INF;
    for(int i=0;i<=a[1].r;i++) {
        f[1][i]=1ll*i*(-d);
        if(i>=a[1].r-a[1].l+1) f[1][i]+=a[1].v;
    }
    for(int i=2;i<=m;i++) {
        swap(cur,pre);
        for(int j=0;j<=K;j++) f[cur][j]=-INF;
        int dt=a[i].r-a[i-1].r;
        for(int j=0;j+dt<=K;j++) {
            f[cur][j+dt]=max(f[cur][j+dt],f[pre][j]-1ll*dt*d);
        }
        ll mx=-INF;
        for(int j=0;j<=K;j++) mx=max(mx,f[pre][j]);
        for(int j=0;j<dt&&j<=K;j++) f[cur][j]=max(f[cur][j],mx-1ll*j*d);
        for(int j=a[i].r-a[i].l+1;j<=K;j++) f[cur][j]+=a[i].v;
    }
    ll ans=0;
    for(int i=0;i<=K;i++) ans=max(ans,f[cur][i]);
    cout<<ans<<"\n";
}
namespace SOL2 {
    int n,m,K,d,Q[N];
    ll sum[N],f[N],g[N],ans;
    struct node {
        int l,r,v;
        bool operator <(const node &o) const {return r<o.r;}
    } a[N];
    void main() {
        cin>>n>>m>>K>>d;
        for(int i=1;i<=m;i++) {
            int x,y,v;
            cin>>x>>y>>v;
            a[i].l=x-y+1; a[i].r=x; a[i].v=v;
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++) sum[i]=sum[i-1]+a[i].v;
        ans=0;
        ll mxf=0;
        int pt=0;
        int L=1,R=0;
        for(int i=1;i<=m;i++) {
            f[i]=-INF;
            while(a[pt+1].r<a[i].l) {
                pt++;
                mxf=max(mxf,f[pt]);
            }
            g[i]=mxf-sum[i-1]+1ll*a[i].l*d-d;
            while(L<=R&&g[i]>=g[Q[R]]) R--;
            Q[++R]=i;
            while(L<=R&&a[i].r-a[Q[L]].l+1>K) L++;
            if(L<=R) f[i]=max(f[i],g[Q[L]]+sum[i]-1ll*a[i].r*d);
            ans=max(ans,f[i]);
        }
        cout<<ans<<"\n";
    }
}
int main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c<=11) {
        while(T--) solve();
    }
    else {
        while(T--) SOL2::main();
    }
    return 0;
}