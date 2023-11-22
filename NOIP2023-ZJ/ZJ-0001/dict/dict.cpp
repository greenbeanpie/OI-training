// Lesser Lord Kusanali
#include <bits/stdc++.h>
#define reg
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,y,x) for(int i=(y);i>=(x);--i)
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int,int > pii;
typedef std::vector<int > poly;
inline int lowbit(int x){return x&(-x);}
void setIn(std::string s){freopen(s.c_str(),"r",stdin);}
void setOut(std::string s){freopen(s.c_str(),"w",stdout);}
void setIO(std::string s){setIn(s+".in"),setOut(s+".out");}
const int MaxN=3050;
struct node
{
    poly c;
}a[MaxN];
int n,m;
int check(int X,int Y)
{
    poly x=a[X].c,y=a[Y].c;
    int p=25;
    rep(i,0,25)
    {
        while(x[i])
        {
            while(!y[p])--p;
            if(p<i)return 0;
            if(p>i)return 1;
            int t=std::min(x[i],y[p]);
            x[i]-=t,y[p]-=t;
        }
    }
    return 0;
}
signed main(void)
{
    setIO("dict");
    
    std::ios::sync_with_stdio(0),std::cin.tie(0);

    std::cin>>n>>m;
    rep(i,1,n)
    {
        std::string s;
        a[i].c.resize(26);
        std::cin>>s;
        rep(j,0,m-1)
            ++a[i].c[int(s[j]-'a')];
    }
    rep(i,1,n)
    {
        int ok=1;
        rep(j,1,n)if(i!=j)
            if(!check(i,j))
            {
                ok=0;
                break;
            }
        std::cout<<ok;
    }
    return 0;
}
