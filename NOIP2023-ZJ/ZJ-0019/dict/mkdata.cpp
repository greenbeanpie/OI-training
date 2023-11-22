// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
std::mt19937_64 Rand(std::chrono::system_clock::now().time_since_epoch().count());
int n=4,m=4;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout<<n<<' '<<m<<std::endl;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j!=m;++j)
            std::cout<<char(Rand()%4+'a');
        std::cout<<std::endl;
    }
    return 0;
}