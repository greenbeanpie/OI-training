// Lesser Lord Kusanali
#include <bits/stdc++.h>
#define reg
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,y,x) for(int i=(y);i>=(x);--i)
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
const int MaxN=1e5+50;
int n,m,K,D;
struct node
{
    int l,t,v;
}a[MaxN];
int f[MaxN];
void solve()
{
    std::cin>>n>>m>>K>>D;
    rep(i,1,m)std::cin>>a[i].l>>a[i].t>>a[i].v;
    ll ans=0;
    rep(mask,0,(1<<n)-1)
    {
        bool ok=1;
        {
            int cnt=0;
            rep(i,0,n-1)
            {
                if(mask>>i&1)
                {
                    ++cnt;
                    if(cnt>K)
                        ok=0;
                }
                else cnt=0;
            }
        }
        if(!ok)break;
        rep(i,1,n)f[i]=0;
        rep(i,0,n-1)if(mask>>i&1)f[i+1]=1;
        rep(i,1,n)f[i]+=f[i-1];
        ll res=0;
        rep(i,0,n-1)if(mask>>i&1)res-=D;
        rep(i,1,m)if(f[a[i].l+a[i].t-1]-f[a[i].l-1]==a[i].t)
            res+=a[i].v;
        ckmax(ans,res);
    }
    std::cout<<ans<<'\n';
}
signed main(void)
{
    setIO("run");

    int Cid,T;
    std::cin>>Cid>>T;
    while(T--)
        solve();
    return 0;
}
