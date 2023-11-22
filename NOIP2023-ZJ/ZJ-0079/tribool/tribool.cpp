#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
using namespace std;
const int N=100005;
int n,m,vis[N],a[N];
vector<pa>G[N];
poly all;
int bl;
void dfs(int k)
{
    all.push_back(k);
    vis[k]=1;
    for (auto [u,w]:G[k])
    {
        if (vis[u]) continue;
        dfs(u);
    }
}
void dfs1(int k)
{
    vis[k]=2;
    for (auto [u,w]:G[k])
    {
        if (a[u]!=0)
        {
            if (w==0&&a[u]!=a[k]) bl=0;
            if (w==1&&a[u]==a[k]) bl=0;
        } else
        {
            if (w==0) a[u]=a[k];
            else if (w==1)
            {
                if (a[k]==-1) a[u]=-2;
                else a[u]=-1;
            }
        }
        if (vis[u]==2) continue;
        dfs1(u);
    }
}
void BellaKira()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        a[i]=i;
    while (m--)
    {
        char c;
        cin>>c;
        if (c=='+')
        {
            int x,y;
            cin>>y>>x;
            a[y]=a[x];
        } else
        if (c=='-')
        {
            int x,y;
            cin>>y>>x;
            if (a[x]<0)
            {
                if (a[x]==-3) a[y]=-3;
                else
                if (a[x]==-1) a[y]=-2;
                else a[y]=-1;
            } else
            {
                if (a[x]>n) a[y]=a[x]-n;
                else a[y]=a[x]+n;
            }
        } else
        {
            int x;
            cin>>x;
            if (c=='T') a[x]=-1;
            else if (c=='F') a[x]=-2;
            else a[x]=-3;
        }
    }
    for (int i=1;i<=n;i++)
        if (a[i]>0)
        {
            if (a[i]==i) continue;
            if (a[i]>n) 
            {
                G[i].push_back(mp(a[i]-n,1));
                G[a[i]-n].push_back(mp(i,1));
            }
            else 
            {
                G[i].push_back(mp(a[i],0));
                G[a[i]].push_back(mp(i,0));
            }
        }
    for (int i=1;i<=n;i++) 
        if (a[i]>0) a[i]=0;
    int ans=0;
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            poly().swap(all);
            dfs(i);
            int rt=0;
            bl=1;
            for (auto u:all)
                if (a[u]<0) 
                {
                    if (a[u]==-3) bl=0;
                    rt=u;
                }
            if (rt==0)
            {
                a[i]=-1;
                dfs1(i);
            } else
                dfs1(rt);
            if (!bl) ans+=all.size();
        }
    cout<<ans<<'\n';
    for (int i=1;i<=n;i++) 
    {
        vis[i]=0;
        vector<pa>().swap(G[i]);
    }
}
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T=1;
    cin>>c>>T;
    while (T--)
    {
        BellaKira();
    }
}