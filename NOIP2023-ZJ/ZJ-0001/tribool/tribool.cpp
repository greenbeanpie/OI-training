// Lesser Lord Kusanali
#include <bits/stdc++.h>
#define reg
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,y,x) for(int i=(y);i>=(x);--i)
#define MP std::make_pair
#define dprintf(x...) fprintf(stderr,x)
typedef std::vector<int > poly;
typedef long long ll;
typedef std::pair<int,int > pii;
inline int lowbit(int x){return x&(-x);}
void setIn(std::string s){freopen(s.c_str(),"r",stdin);}
void setOut(std::string s){freopen(s.c_str(),"w",stdout);}
void setIO(std::string s){setIn(s+".in"),setOut(s+".out");}
#define fi first
#define se second
const int MaxN=4e5+50;
int lst[MaxN];
int hid[100050],tid[100050];
int n,m,ndn;
std::vector<pii > E[MaxN];
poly G[MaxN];
int deg[MaxN],val[MaxN],Q[MaxN],h,t;
pii rev[MaxN];
int newnode(int x,int y)
{
    ++ndn;
    if(y==0)hid[x]=ndn;
    if(y==m+1)tid[x]=ndn;
    rev[ndn]=MP(x,y);
    return ndn;
}
void adde(int x,int y,int z)
{
    ++deg[y];
    E[x].pb(MP(y,z));
    G[x].pb(y),G[y].pb(x);
}
inline int calc(int x,int y)
{
    if(x==2)return 2;
    return x^y;
}
void SOLVE()
{
    
    std::cin>>n>>m;
    std::mem(lst,0);
    std::mem(hid,0);
    std::mem(tid,0);
    rep(i,1,ndn)
    {
        E[i].clear();
        G[i].clear();
    }
    ndn=0;
    std::mem(deg,0);
    std::mem(val,-1);

    rep(i,1,n)
    {
        int st=newnode(i,0);
        int ed=newnode(i,m+1);
        lst[i]=st;
        adde(ed,st,0);
    }

    rep(i,1,m)
    {
        char opt;
        std::cin>>opt;
        int x;std::cin>>x;
        int cur=newnode(x,i);
        if(opt=='T')
            val[cur]=1; 
        else if(opt=='F')
            val[cur]=0;
        else if(opt=='U')
            val[cur]=2;
        else if(opt=='+')
        {
            int y;std::cin>>y;
            adde(lst[y],cur,0);
        }
        else if(opt=='-')
        {
            int y;std::cin>>y;
            adde(lst[y],cur,1);
        }
        else assert(false);
        lst[x]=cur;
    }
    rep(i,1,n)
        adde(lst[i],tid[i],0);
    
    h=1,t=0;
    rep(i,1,ndn)if(!deg[i])Q[++t]=i;
    
    while(h<=t)
    {
        int u=Q[h++];
        // dprintf("u %d\n",u);
        for(auto v:E[u])
        {
            val[v.fi]=calc(val[u],v.se);
            --deg[v.fi];
            if(!deg[v.fi])Q[++t]=v.fi;
        }
    }

/*
    rep(i,1,n)
        std::cerr<<val[id[i][m+1]]<<' ';
    std::cerr<<'\n';
*/

    // dprintf("ndn %d\n",ndn);

    poly vis(ndn+5);

    int sum=0;

    rep(X,1,ndn)if(deg[X])
    {
        poly dr;

        {
            h=1,t=0;
            Q[++t]=X,vis[X]=1,dr.pb(X);
            while(h<=t)
            {
                int u=Q[h++];
                for(auto v:G[u])if(!vis[v])
                {
                    vis[v]=1;
                    Q[++t]=v;
                    dr.pb(v);
                }
            }
            for(auto i:dr)vis[i]=0;
        }

        // sum+=(int)dr.size();

        int ckpt=-1;
        for(auto S:dr)if(rev[S].se==0)
        {
            poly Dr;
            h=1,t=0;
            Q[++t]=S,Dr.pb(S),vis[S]=1;
            while(h<=t)
            {
                int u=Q[h++];
                for(auto v:E[u])if(!vis[v.fi])
                {
                    vis[v.fi]=1;
                    Q[++t]=v.fi;
                    Dr.pb(v.fi);
                    if(rev[v.fi].se==m+1&&rev[S].fi==rev[v.fi].fi)
                    {
                        ckpt=rev[S].fi;
                        break;
                    }
                }
                if(~ckpt)break;
            }
            sum+=(int)Dr.size();
            // for(auto i:Dr)vis[i]=0;
            if(~ckpt)break;
        }
        assert(ckpt!=-1);
        for(auto i:dr)vis[i]=0;
        // dprintf("ckpt %d\n",ckpt);

        {
            h=1,t=0;
            int S=hid[ckpt];
            val[S]=0,vis[S]=1,Q[++t]=S;
            while(h<=t)
            {
                int u=Q[h++];
                for(auto v:E[u])if(!vis[v.fi])
                {
                    val[v.fi]=calc(val[u],v.se);
                    vis[v.fi]=1,Q[++t]=v.fi;
                }
            }
            for(auto i:dr)vis[i]=0;
        }
        if(val[hid[ckpt]]!=val[tid[ckpt]])
        {
            /*
            h=1,t=0;
            int S=id[ckpt][0];
            val[S]=2,vis[S]=1,Q[++t]=S;
            while(h<=t)
            {
                int u=Q[h++];
                for(auto v:E[u])if(!vis[v.fi])
                {
                    val[v.fi]=calc(val[u],v.se);
                    vis[v.fi]=1,Q[++t]=v.fi;
                }
            }
            for(auto i:dr)vis[i]=0;
            */
            for(auto i:dr)val[i]=2;
        }

        for(auto i:dr)deg[i]=0;
    }
    // dprintf("sum %d\n",sum);
/*
    rep(i,1,n)
        std::cerr<<val[id[i][m+1]]<<' ';
    std::cerr<<'\n';
*/
    int ans=0;
    rep(i,1,n)
        ans+=(val[tid[i]]==2);
    std::cout<<ans<<'\n';
}
signed main(void)
{
    setIO("tribool");

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int Cid,T;
    std::cin>>Cid>>T;
    rep(i,1,T)
    {
        // dprintf("T %d\n",i);
        SOLVE();   
    }
    return 0;
}
