#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF=2e5+15;
struct Segment{
    #define ll tl[id]
    #define rr tr[id]
    #define ls(x) x<<1
    #define rs(x) x<<1|1
    int tl[INF<<2],tr[INF<<2],sum[INF<<2],lazy[INF<<2];
    void push_up(int id) {
        sum[id]=max(sum[ls(id)],sum[rs(id)]);
    }
    void push_down(int id) {
        if (lazy[id]==0) return ;
        int rt=ls(id);
        sum[rt]+=lazy[id];
        lazy[rt]+=lazy[id];

        rt=rs(id);
        sum[rt]+=lazy[id];
        lazy[rt]+=lazy[id];

        lazy[id]=0;
    }
    void build(int l,int r,int id) {
        ll=l;rr=r;sum[id]=lazy[id]=0;
        if (ll==rr) {
            sum[id]=0;
            return ;
        }
        int Mid=(ll+rr)>>1;
        build(l,Mid,ls(id));
        build(Mid+1,r,rs(id));
        push_up(id);
    }
    void add(int l,int r,int x,int id) {
        if (l<=ll && rr<=r) {
            sum[id]+=x;
            lazy[id]+=x;
            return ;
        }
        push_down(id);
        int Mid=(ll+rr)>>1;
        if (l<=Mid) add(l,r,x,ls(id));
        if (Mid<r) add(l,r,x,rs(id));
        push_up(id);
    }
    int query(int l,int r,int id) {
        if (l<=ll && rr<=r) return sum[id];
        push_down(id);int Mid=(ll+rr)>>1;
        if (r<=Mid) return query(l,r,ls(id));
        else if (l>Mid) return query(l,r,rs(id));
        else return max(query(l,r,ls(id)),query(l,r,rs(id)));
    }
    #undef ll
    #undef rr
    #undef ls
    #undef rs
}T1;
int c,t,n,m,k,d,x[INF],y[INF],v[INF],f[INF],f1[INF];
vector <int> cnt;
vector < pii > e[INF];
int Get(int x) {return lower_bound(cnt.begin(),cnt.end(),x)-cnt.begin()+1;}
void solve() {
    memset(f,0,sizeof f);
    memset(f1,0,sizeof f1);
    cnt.clear();
    cin>>n>>m>>k>>d;
    for (int i=1;i<=m;i++) {
        cin>>x[i]>>y[i]>>v[i];
        cnt.pb(x[i]);cnt.pb(x[i]-y[i]+1);
    }
    sort(cnt.begin(),cnt.end());
    cnt.erase(unique(cnt.begin(),cnt.end()),cnt.end());
    for (int i=1;i<=m;i++) 
        e[Get(x[i])].pb({x[i]-y[i]+1,v[i]});
    int len=cnt.size();
    T1.build(1,len,1);
    for (int i=1;i<=len;i++) {
        if (i==1) T1.add(i,i,d*cnt[i-1],1);
        else if (i==2) {
            if (cnt[i-1]-cnt[i-2]>1) T1.add(i,i,f[i-1]+d*cnt[i-1],1);
            else T1.add(i,i,d*cnt[i-1],1);
        }
        else {
            if (cnt[i-1]-cnt[i-2]>1) T1.add(i,i,f[i-1]+d*cnt[i-1],1);
            else T1.add(i,i,d*cnt[i-1]+f[i-2],1);
        }
        for (pii j:e[i]) {
            int v=j.first,d=j.second;
            v=Get(v);
            T1.add(1,v,d,1);
            // for (int j=1;j<=v;j++) f1[j]+=d;  
        }
        f[i]=max(f[i],f[i-1]);
        int l=1,r=i,ans=-1;
        while (l<=r) {
            int Mid=(l+r)>>1;
            if (cnt[i-1]-cnt[Mid-1]+1<=k) r=(ans=Mid)-1;
            else l=Mid+1;
        }
        if (ans!=-1) 
            f[i]=max(f[i],T1.query(ans,i,1)-d*cnt[i-1]-d);
    }
    cout<<f[len]<<"\n";
    for (int i=1;i<=len;i++) vector <pii> ().swap(e[i]);
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while (t--) solve();
    return 0;
}