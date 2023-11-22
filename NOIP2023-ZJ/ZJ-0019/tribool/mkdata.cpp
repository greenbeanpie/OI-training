// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
std::mt19937_64 Rand(std::chrono::system_clock::now().time_since_epoch().count());
int c=10,t=10000,n=5,m=10;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout<<c<<' '<<t<<std::endl;
    while(t--)
    {
        n=Rand()%5+1;
        m=Rand()%10+1;
        std::cout<<n<<' '<<m<<std::endl;
        for(int i=1;i<=m;++i)
        {
            switch(Rand()%5)
            {
            case 0:
                std::cout<<'T'<<' '<<Rand()%n+1<<std::endl;
                break;
            case 1:
                std::cout<<'F'<<' '<<Rand()%n+1<<std::endl;
                break;
            case 2:
                std::cout<<'U'<<' '<<Rand()%n+1<<std::endl;
                break;
            case 3:
                std::cout<<'+'<<' '<<Rand()%n+1<<' '<<Rand()%n+1<<std::endl;
                break;
            case 4:
                std::cout<<'-'<<' '<<Rand()%n+1<<' '<<Rand()%n+1<<std::endl;
                break;
            }
        }
    }
    return 0;
}