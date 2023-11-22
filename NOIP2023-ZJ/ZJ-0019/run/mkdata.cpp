// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
std::mt19937_64 Rand(std::chrono::system_clock::now().time_since_epoch().count());
int c=10,t=10,n=3000,m=10,k,d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout<<c<<' '<<t<<std::endl;
    while(t--)
    {
        n=Rand()%3000+1;
        m=Rand()%50000+1;
        k=Rand()%n+1;
        d=Rand()%1000000000+1;
        std::cout<<n<<' '<<m<<' '<<k<<' '<<d<<std::endl;
        for(int i=1;i<=m;++i)
        {
            int l=Rand()%n+1,r=Rand()%n+1,v=Rand()%1000000000+1;
            if(l>r)
                std::swap(l,r);
            std::cout<<r<<' '<<r-l+1<<' '<<v<<std::endl;
        }
    }
    return 0;
}