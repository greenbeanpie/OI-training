// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
std::mt19937_64 Rand(std::chrono::system_clock::now().time_since_epoch().count());
int c=10,n=Rand()%10+1,m=Rand()%10+1,q=60;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout<<c<<' '<<n<<' '<<m<<' '<<q<<std::endl;
    for(int i=1;i<=n;++i)
        std::cout<<Rand()%1000000000<<" \n"[i==n];
    for(int i=1;i<=m;++i)
        std::cout<<Rand()%1000000000<<" \n"[i==m];
    for(int i=1;i<=q;++i)
    {
        std::cout<<n<<' '<<m<<std::endl;
        for(int j=1;j<=n;++j)
            std::cout<<j<<' '<<Rand()%1000000000<<std::endl;
        for(int j=1;j<=m;++j)
            std::cout<<j<<' '<<Rand()%1000000000<<std::endl;
    }
    return 0;
}