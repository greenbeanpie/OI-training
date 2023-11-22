// Lesser Lord Kusanali
#include <bits/stdc++.h>
#define reg
#define fi first
#define se second
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,y,x) for(int i=(y);i>=(x);--i)
#define dprintf(x...) fprintf(stderr,x)
#define MP std::make_pair
typedef std::vector<int > poly;
typedef long long ll;
typedef std::pair<int,int > pii;
inline int lowbit(int x){return x&(-x);}
void setIn(std::string s){freopen(s.c_str(),"r",stdin);}
void setOut(std::string s){freopen(s.c_str(),"w",stdout);}
void setIO(std::string s){setIn(s+".in"),setOut(s+".out");}
template<class t> inline int ckmin(t&x,t y){if(x>y)return x=y,1;return 0;}
template<class t> inline int ckmax(t&x,t y){if(x<y)return x=y,1;return 0;}
namespace BF
{
const int MaxN=205;
int n,m,q;
int a[MaxN],b[MaxN];
int dp[MaxN][MaxN];
void add(int u,int v,int x,int y)
{
    ++dp[u][v],--dp[u][y+1],--dp[x+1][v],++dp[x+1][y+1];
}
bool check(int *a,int n,int *b,int m) // A > B
{
/*    dprintf("checking\n");
    rep(i,1,n)
        dprintf("<%d>",a[i]);
    dprintf("\n");
    rep(i,1,m)
        dprintf("<%d>",b[i]);
    dprintf("\n");
    */

    std::mem(dp,0);
    dp[0][0]=1;
    // poly st(std::max(n,m)+5);
    // int tp=0;
    rep(i,0,n-1)
    {
        rep(j,0,m-1)
        {
            // dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            if(dp[i][j])
            {
                rep(k,j+1,m)
                {
                    if(b[k]>=a[i+1])break;
                    dp[i+1][k]=1;
                }
                rep(k,i+1,n)
                {
                    if(a[k]<=b[j+1])break;
                    dp[k][j+1]=1;
                }
            }
        }
    }
    /*
    rep(i,1,n)rep(j,1,m)if(dp[i][j])
        dprintf("dp %d %d\n",i,j);
    */
    return dp[n][m];
}
void solve()
{
    // dprintf("solving\n");
    int ans=0;
    if(a[1]>b[1])ans=check(a,n,b,m);
    else if(a[1]<b[1])ans=check(b,m,a,n);
    std::cout<<ans;
}
void SOLVE()
{
    std::cin>>n>>m>>q;
    rep(i,1,n)std::cin>>a[i];
    rep(i,1,m)std::cin>>b[i];
    solve();
    rep(i,1,q)
    {
        int x,y;
        int N,M;std::cin>>N>>M;
        std::vector<pii > RA,RB;
        while(N--)std::cin>>x>>y,RA.pb(MP(x,a[x])),a[x]=y;
        while(M--)std::cin>>x>>y,RB.pb(MP(x,b[x])),b[x]=y;
        solve();
        while(RA.size())a[RA.back().fi]=RA.back().se,RA.pop_back();
        while(RB.size())b[RB.back().fi]=RB.back().se,RB.pop_back();
    }
    std::cout<<'\n';
}
}
namespace SP
{
    const int MaxN=5e5+50;
    int n,m,q;
    int a[MaxN],b[MaxN];
    void solve()
    {
        int p=1,i=1;
        for(;i<=n;++i)
        {
            while(p<=m&&b[p]>a[i])++p;
            if(p>m)break;
            if(p<i)break;
        }
        // std::cerr<<"pi "<<p<<' '<<i<<'\n';
        if(p>m)
        {
            std::cout<<1;
            return;
        }
        if(i>n)
        {
            if(a[n]<*std::min_element(b+p,b+m+1))
                std::cout<<1;
            else std::cout<<0;
            return ;
        }
        if(*std::min_element(b+p,b+m+1)>*std::max_element(a+i,a+i+1))
            std::cout<<1;
        else std::cout<<0;
    }
    void SOLVE()
    {
        std::cin>>n>>m>>q;
        rep(i,1,n)std::cin>>a[i];
        rep(i,1,m)std::cin>>b[i];
        solve();
        rep(i,1,q)
        {
            int x,y;
            int N,M;std::cin>>N>>M;
            std::vector<pii > RA,RB;
            while(N--)std::cin>>x>>y,RA.pb(MP(x,a[x])),a[x]=y;
            while(M--)std::cin>>x>>y,RB.pb(MP(x,b[x])),b[x]=y;
            solve();
            while(RA.size())a[RA.back().fi]=RA.back().se,RA.pop_back();
            while(RB.size())b[RB.back().fi]=RB.back().se,RB.pop_back();
        }
        std::cout<<'\n';
    }
}
signed main(void)
{
    setIO("expand");

    int Cid;
    std::cin>>Cid;
    if(8<=Cid&&Cid<=14)
    {
        SP::SOLVE();
        return 0;
    }
    BF::SOLVE();
    return 0;
}
