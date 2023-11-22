// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int c,n,m,q,a[500005],b[500005],x[500005],y[500005];
bool dp[3005][3005];
bool check()
{
    std::memset(dp,0,sizeof(dp));
    dp[1][1]=true;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(dp[i][j]&&1ll*(x[1]-y[1])*(x[i+1]-y[j])>0)
                dp[i+1][j]=true;
            if(dp[i][j]&&1ll*(x[1]-y[1])*(x[i]-y[j+1])>0)
                dp[i][j+1]=true;
            if(dp[i][j]&&1ll*(x[1]-y[1])*(x[i+1]-y[j+1])>0)
                dp[i+1][j+1]=true;
        }
    return dp[n][m];
}
signed main()
{
    freopen("expand.in","r",stdin)&&freopen("expand.ans","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i)
        std::cin>>a[i];
    for(int i=1;i<=m;++i)
        std::cin>>b[i];
    std::copy(a+1,a+1+n,x+1);
    std::copy(b+1,b+1+m,y+1);
    std::cout<<check();
    for(int i=1,kx,ky;i<=q;++i)
    {
        std::cin>>kx>>ky;
        std::copy(a+1,a+1+n,x+1);
        std::copy(b+1,b+1+m,y+1);
        for(int j=1,px,vx;j<=kx;++j)
        {
            std::cin>>px>>vx;
            x[px]=vx;
        }
        for(int j=1,py,vy;j<=ky;++j)
        {
            std::cin>>py>>vy;
            y[py]=vy;
        }
        std::cout<<check();
    }
    std::cout<<std::endl;
    return 0;
}