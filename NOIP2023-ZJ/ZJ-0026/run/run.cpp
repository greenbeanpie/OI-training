#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=(j);i<=(k);i++)
#define per(i,j,k) for (int i=(j);i>=(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define ll long long
#define pb push_back
template<class T>void chkmin(T&x,T y){x=min(x,y);}
template<class T>void chkmax(T&x,T y){x=max(x,y);}
const ll inf=1e18;

const int N=2e5+5;
int n,m,k;
bool vis[N];
ll f[N],g[N],c[N],d,s[N];
int a[N][3];
int b[N],cnt;
vector<pii>t[N];

namespace SGT
{
    const int M=N*4;
    ll add[M],mx[M];
    inline void push_up(int u)
    {
        mx[u]=max(mx[u*2],mx[u*2+1]);
    }
    inline void spread(int u,ll v)
    {
        add[u]+=v,mx[u]+=v;
    }
    inline void push_down(int u)
    {
        if (add[u]==0) return;
        spread(u*2,add[u]),spread(u*2+1,add[u]);
        add[u]=0;
    }
    void build(int u,int l,int r)
    {
        add[u]=0;
        if (l==r)
        {
            mx[u]=c[l];
            return;
        }
        int mid=(l+r)>>1;
        build(u*2,l,mid),build(u*2+1,mid+1,r);
        push_up(u);
    }
    void update(int u,int L,int R,int l,int r,ll v)
    {
        if (l<=L&&R<=r)
        {
            spread(u,v);
            return;
        }
        push_down(u);
        int mid=(L+R)>>1;
        if (l<=mid) update(u*2,L,mid,l,r,v);
        if (mid<r) update(u*2+1,mid+1,R,l,r,v);
        push_up(u);
    }
    ll query(int u,int L,int R,int l,int r)
    {
        if (l<=L&&R<=r) return mx[u];
        int mid=(L+R)>>1;
        ll res=-inf;
        push_down(u);
        if (l<=mid) chkmax(res,query(u*2,L,mid,l,r));
        if (mid<r) chkmax(res,query(u*2+1,mid+1,R,l,r));
        return res;
    }
}
void work()
{
    cin >> n >> m >> k >> d;
    cnt=0;
    rep(i,1,m)
    {
        int x,y,z;
        cin >> x >> y >> z;
        int l=x-y+1,r=x;
        a[i][0]=l,a[i][1]=r,a[i][2]=z;
        b[++cnt]=a[i][0],b[++cnt]=a[i][1];
    }
    sort(b+1,b+cnt+1);
    cnt=unique(b+1,b+cnt+1)-b-1;
    rep(i,1,m) a[i][0]=lower_bound(b+1,b+cnt+1,a[i][0])-b;
    rep(i,1,m) a[i][1]=lower_bound(b+1,b+cnt+1,a[i][1])-b;
    rep(i,1,cnt) t[i].clear();
    rep(i,1,m)
    {
        int l=a[i][0],r=a[i][1],v=a[i][2];
        t[r].pb(mkp(l,v));
    }

    rep(i,1,cnt) c[i]=d*(b[i]-1);
    SGT::build(1,1,cnt);
    rep(i,0,cnt) f[i]=-inf,g[i]=-inf;
    g[0]=0;
    rep(i,1,cnt)
    {
        SGT::update(1,1,cnt,i,i,g[i-1]);
        for (pii j:t[i])
        {
            SGT::update(1,1,cnt,1,j.fi,j.se);
        }
        g[i]=max(g[i-1],f[i-1]);
        // rep(j,0,cnt+1) s[j]=0;
        // for (pii j:t[i]) s[j.fi]+=j.se;
        // per(j,cnt,1) s[j]+=s[j+1],c[j]+=s[j];
        int u=lower_bound(b+1,b+cnt+1,b[i]+1-k)-b;
        f[i]=SGT::query(1,1,cnt,u,i)-b[i]*d;
        // rep(j,u,i) chkmax(f[i],g[j-1]-b[i]*d+c[j]);
        if (i!=cnt&&b[i]+1!=b[i+1]) chkmax(g[i],f[i]);
    }
    cout << max(f[cnt],g[cnt]) << "\n";
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int id,T;
    cin >> id >> T;
    while (T--) work();
    return 0;
}