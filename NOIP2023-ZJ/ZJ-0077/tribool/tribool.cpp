#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF=2e5+5;
int n,m,b[INF],c[INF],cnt,d[INF],fl,v[INF],vis[INF];
vector < pii > e[INF];
void DFS(int x,int y) {
    if (vis[x]) {
        if (v[x]!=y) fl=1;
        return ;
    }
    vis[x]=1;
    cnt+=(x<=n);
    if (b[x]==3) fl=1;
    if (b[x]) v[x]=b[x];
    else v[x]=y;
    for (auto it:e[x]) {
        int v=it.first,d=it.second;
        DFS(v,y^d);
    }
}
void solve() {
    cin>>n>>m;
    for (int i=1;i<=n*2;i++) b[i]=c[i]=vis[i]=0,d[i]=i;
    for (int i=1;i<=n*2;i++) vector < pii > ().swap(e[i]);
    for (int i=1;i<=m;i++) {
        char cc;cin>>cc;
        if (cc=='T') {
            int x=0;cin>>x;
            b[x]=1;c[x]=d[x]=0;
        }
        else if (cc=='F') {
            int x=0;cin>>x;
            b[x]=2;c[x]=d[x]=0;
        }
        else if (cc=='U') {
            int x=0;cin>>x;
            b[x]=3;c[x]=d[x]=0;
        }
        else if (cc=='+') {
            int x=0,y=0;cin>>x>>y;
            if (b[y]) b[x]=b[y],c[x]=d[x]=0;
            else b[x]=0,c[x]=c[y],d[x]=d[y];
        }
        else if (cc=='-') {
            int x=0,y=0;cin>>x>>y;
            if (b[y]) {
                int xx=b[y];
                if (xx==1) xx=2;
                else if (xx==2) xx=1;
                b[x]=xx,c[x]=d[x]=0;
            }
            else b[x]=0,c[x]=c[y]^1,d[x]=d[y];
        }
    }
    
    for (int i=1;i<=n;i++) {
        e[i].pb({i+n,0});
        e[i+n].pb({i,0});
    }
    for (int i=1;i<=n;i++)
        if (b[i]) ;
        else {
            // cerr<<i<<" "<<d[i]
            e[i].pb({d[i]+n,c[i]});
            e[d[i]+n].pb({i,c[i]});
        } 
    int ans=0;
    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;
        if (b[i]) {
            fl=cnt=0;
            DFS(i,b[i]);
            if (fl) ans+=cnt;
        }
    }
    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;
        fl=cnt=0;
        DFS(i,b[i]);
        if (fl) ans+=cnt;
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c=0,t=0;cin>>c>>t;
    while (t--) solve();
    return 0;
}