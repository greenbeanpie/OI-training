// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int c,T,n,m,k;
long long sum[3005][3005],d,ans,dp[3005];
signed main()
{
    freopen("run.in","r",stdin)&&freopen("run.ans","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>c>>T;
    while(T--)
    {
        std::cin>>n>>m>>k>>d;
        std::memset(sum,0,sizeof(sum));
        for(int i=1,l,r,v;i<=m;++i)
        {
            std::cin>>r>>l>>v;
            sum[r-l][r]+=v;
        }
        for(int i=0;i<=n;++i)
            for(int j=1;j<=n;++j)
                sum[i][j]+=sum[i][j-1];
        for(int i=n;i--;)
            for(int j=0;j<=n;++j)
                sum[i][j]+=sum[i+1][j];
        ans=0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=ans;
            for(int j=std::max(0,i-k);j<i;++j)
                ans=std::max(ans,dp[j]+sum[j][i]-(i-j)*d);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}