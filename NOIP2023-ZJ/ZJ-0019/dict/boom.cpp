// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int n,m;
std::string s[3005];
signed main()
{
    freopen("dict.in","r",stdin)&&freopen("dict.ans","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>n>>m;
    for(int i=1;i<=n;++i)
        std::cin>>s[i],std::sort(s[i].rbegin(),s[i].rend());
    for(int i=1;i<=n;++i)
    {
        bool flag=true;
        std::reverse(s[i].begin(),s[i].end());
        for(int j=1;j<=n;++j)
            if(j!=i)
                flag&=s[i]<s[j];
        std::reverse(s[i].begin(),s[i].end());
        std::cout<<flag;
    }
    std::cout<<std::endl;
    return 0;
}