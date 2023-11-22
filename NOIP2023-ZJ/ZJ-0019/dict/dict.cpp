// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int n,m;
std::string s[3005];
signed main()
{
    freopen("dict.in","r",stdin)&&freopen("dict.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>n>>m;
    for(int i=1;i<=n;++i)
        std::cin>>s[i],std::sort(s[i].begin(),s[i].end());
    for(int i=1;i<=n;++i)
    {
        bool flag=true;
        for(int j=1;j<=n;++j)
            if(i!=j)
                flag&=s[i].front()<s[j].back();
        std::cout<<flag;
    }
    std::cout<<std::endl;
    return 0;
}