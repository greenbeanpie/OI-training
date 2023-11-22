// Lesser Lord Kusanali
#include <bits/stdc++.h>
#define reg
#define int long long
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
std::mt19937 rnd(time(0));
int getrand(int l,int r)
{
    assert(l<=r);
    return l+rnd()%(r-l+1);
}
signed main(void)
{
    setOut("tribool.in");

    int Cid=0,T=6;
    std::cout<<Cid<<' '<<T<<'\n';
    while(T--)
    {
        int n=1e5,m=1e5;
        std::cout<<n<<' '<<m<<'\n';
        while(m--)
        {
            int opt=getrand(0,4);
            if(opt==0)
            {
                std::cout<<'T'<<' '<<getrand(1,n)<<'\n';
            }
            else if(opt==1)
            {
                std::cout<<'F'<<' '<<getrand(1,n)<<'\n';
            }
            else if(opt==2)
            {
                std::cout<<'U'<<' '<<getrand(1,n)<<'\n';
            }
            else if(opt==3)
            {
                int x,y;
                do
                {
                    x=getrand(1,n);
                    y=getrand(1,n);
                }while(x==y);
                std::cout<<'+'<<' '<<x<<' '<<y<<'\n';
            }
            else
            {
                int x,y;
                do
                {
                    x=getrand(1,n);
                    y=getrand(1,n);
                }while(x==y);
                std::cout<<'-'<<' '<<x<<' '<<y<<'\n';
            }
        }
    }
    return 0;
}
