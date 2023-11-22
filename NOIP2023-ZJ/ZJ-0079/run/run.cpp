#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define sz(x) ((int)(x.size()))
#define int ll
using namespace std;
const int N=200005,inf=1e18;
int n,m,K,d;
int dp[N];
poly g;
poly G[N];
int tr[N<<2],tag[N<<2];
int L[N],R[N],V[N];
inline void ptag(int k,int x)
{
    tr[k]+=x;
    tag[k]+=x;
}
inline void pushdown(int k)
{
    ptag(k<<1,tag[k]);
    ptag(k<<1|1,tag[k]);
    tag[k]=0;
}
void build(int k,int l,int r)
{
    tag[k]=0;
    if (l==r)
    {
        tr[k]=g[l-1]*d;
        return;
    }
    int mid=l+(r-l)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int L,int R,int x)
{
    if (L>R)return;
    if (L<=l&&r<=R)
    {
        ptag(k,x);
        return;
    }
    pushdown(k);
    int mid=l+(r-l)/2;
    if (L<=mid) update(k<<1,l,mid,L,R,x);
    if (R>mid) update(k<<1|1,mid+1,r,L,R,x);
    tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
int query(int k,int l,int r,int L,int R)
{
    if (L>R) return -inf;
    if (L<=l&&r<=R) return tr[k];
    pushdown(k);
    int mid=l+(r-l)/2;
    int res=-inf;
    if (L<=mid) res=max(res,query(k<<1,l,mid,L,R));
    if (R>mid) res=max(res,query(k<<1|1,mid+1,r,L,R));
    return res;
}
void BellaKira()
{
    cin>>n>>m>>K>>d;
    for (int i=1;i<=m;i++)
    {
        int x,y,v;
        cin>>x>>y>>v;
        L[i]=x-y+1,R[i]=x;
        V[i]=v;
        g.push_back(L[i]-1);
        g.push_back(R[i]);
    }
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
    for (int i=1;i<=m;i++)
    {
        L[i]=lower_bound(g.begin(),g.end(),L[i]-1)-g.begin()+1;
        R[i]=lower_bound(g.begin(),g.end(),R[i])-g.begin()+1;
        G[R[i]].push_back(i);
    }
    build(1,1,g.size());
    int ans=0;
    for (int i=1,j=1;i<=g.size();i++)
    {
        while (j<=g.size()&&g[i-1]-g[j-1]>K) j++;
        dp[i]=max(dp[i],dp[i-1]);
        ans=max(ans,dp[i]);
        for (auto u:G[i])
        {
            update(1,1,sz(g),1,L[u],V[u]);
        }
        dp[i+1]=max(dp[i+1],query(1,1,sz(g),j,i-1)-g[i-1]*d);
        update(1,1,sz(g),i,i,dp[i]);
    }
    ans=max(ans,dp[sz(g)+1]);
    cout<<ans<<'\n';
    for (int i=1;i<=sz(g)+1;i++) 
    {
        dp[i]=0;
        poly().swap(G[i]);
    }
    poly().swap(g);
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T=1;
    cin>>c>>T;
    while (T--)
    {
        BellaKira();
    }
}