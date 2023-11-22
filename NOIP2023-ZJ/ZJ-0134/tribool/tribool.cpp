#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int C,T,n,m,head[N],numEdge;
struct State
{
    /// val: 0:U; 1:T; -1:F; +-5:none;
    /// id: +:the same as init s[id]; -:the opposite to init s[id]; 0:none;
    int val,id;
}s[N];
struct Edge
{
    int endv,next;
}e[N*2];
vector<int>vertex;
bool vis[N];
struct DSU
{
    int fth[N*2];
    void clear(){for(int i=1;i<=n*2;++i) fth[i]=i;}
    int find(int x){return fth[x]==x?x:fth[x]=find(fth[x]);}
    void merge(int x,int y){fth[find(x)]=find(y);}
    bool difset(int x,int y){return find(x)!=find(y);}
}dsu;

void Init()
{
    numEdge=0;
    for(int i=1;i<=n;++i)
    {
        head[i]=0;
        s[i]={5,i};
        vis[i]=false;
    }
    dsu.clear();
}
char readc()
{
    char c=getchar();
    while(c!='-'&&c!='+'&&c!='T'&&c!='F'&&c!='U') c=getchar();
    return c;
}
int read()
{
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
inline void AddEdge(const int &u,const int &v)
{
    e[++numEdge]={v,head[u]};
    head[u]=numEdge;
}
void DFS(int u,int &cnt,bool &flag1,bool &flag2)
{
    vertex.push_back(u);
    vis[u]=true;
    ++cnt;
    if(s[u].val==1||s[u].val==-1) flag1=true;
    if(s[u].val==0) flag2=true;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].endv;
        if(vis[v]) continue;
        DFS(v,cnt,flag1,flag2);
    }
}
void Solve()
{
    // auto Ts=clock();
    // cin>>n>>m;
    n=read(),m=read();
    Init();
    // auto T0=clock();
    // cerr<<"Time0: "<<T0-Ts<<" ms.\n";
    for(int i=1,u,v;i<=m;++i)
    {
        char opt=readc();
        // cin>>opt;
        switch(opt)
        {
        case 'T':
            // cin>>u;
            u=read();
            s[u]={1,0};
            break;
        case 'F':
            // cin>>u;
            u=read();
            s[u]={-1,0};
            break;
        case 'U':
            // cin>>u;
            u=read();
            s[u]={0,0};
            break;
        case '+':
            // cin>>u>>v;
            u=read(),v=read();
            s[u]=s[v];
            break;
        case '-':
            // cin>>u>>v;
            u=read(),v=read();
            s[u]={-s[v].val,-s[v].id};
            break;
        default:
            break;
        }
    }
    // for(int i=1;i<=n;++i)
    //     cerr<<s[i].val<<" "<<s[i].id<<"\n";
    // cerr<<"\n";
    // auto T1=clock();
    // cerr<<"Time1: "<<T1-T0<<" ms.\n";
    for(int i=1;i<=n;++i)
    {
        if(s[i].id>0)
            AddEdge(i,s[i].id),AddEdge(s[i].id,i);
        else if(s[i].id<0)
            AddEdge(i,-s[i].id),AddEdge(-s[i].id,i);
    }
    // auto T2=clock();
    // cerr<<"Time2: "<<T2-T1<<" ms.\n";
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        vertex.clear();
        int cnt=0;
        bool flag1=false,flag2=false;
        // auto T1=clock();
        DFS(i,cnt,flag1,flag2);
        // if(debug) cerr<<"dfs time:"<<clock()-T1<<"\n";
        // cerr<<"i:"<<i<<"\n";
        // cerr<<"dfs:"<<cnt<<","<<flag1<<","<<flag2<<"\n";
        // for(auto u:vertex)
        //     cerr<<u<<" ";
        // cerr<<"\n";
        if(flag1) continue;
        if(flag2)
        {
            ans+=cnt;
            continue;
        }
        for(auto u:vertex)
        {
            if(s[u].id>0) dsu.merge(u,s[u].id),dsu.merge(u+n,s[u].id+n);
            else dsu.merge(u+n,-s[u].id),dsu.merge(u,-s[u].id+n);
        }
        for(auto u:vertex)
            if(!dsu.difset(u,u+n))
                ++ans;
    }
    printf("%d\n",ans);
    // cout<<ans<<"\n";
    // cerr<<"\n";
    // auto T3=clock();
    // cerr<<"Time3: "<<T3-T2<<" ms.\n\n";
}
signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    // ios::sync_with_stdio(false),cin.tie(nullptr);
    // cin>>C>>T;
    C=read(),T=read();
    while(T--) Solve();
    cerr<<"Time: "<<clock()<<" ms.\n";
    return 0;
}