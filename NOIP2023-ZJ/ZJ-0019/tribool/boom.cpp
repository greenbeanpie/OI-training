// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int c,t,n,m,ans,x[100005],y[100005],a[100005],b[100005];
char opt[100005];
void dfs(int now)
{
    if(!now)
    {
        std::copy(a+1,a+1+n,b+1);
        for(int i=1;i<=m;++i)
            switch(opt[i])
            {
            case 'T':
                b[x[i]]=+1;
                break;
            case 'F':
                b[x[i]]=-1;
                break;
            case 'U':
                b[x[i]]=0;
                break;
            case '+':
                b[x[i]]=+b[y[i]];
                break;
            case '-':
                b[x[i]]=-b[y[i]];
                break;
            }
        for(int i=1;i<=n;++i)
            if(a[i]!=b[i])
                return;
        ans=std::min(ans,int(std::count(a+1,a+1+n,0)));
        return;
    }
    for(int &i=a[now]=-1;i<=+1;++i)
        dfs(now-1);
}
signed main()
{
    freopen("tribool.in","r",stdin)&&freopen("tribool.ans","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>c>>t;
    while(t--)
    {
        std::cin>>n>>m;
        ans=n;
        for(int i=1;i<=m;++i)
        {
            std::cin>>opt[i];
            switch(opt[i])
            {
            case 'T':
            case 'F':
            case 'U':
                std::cin>>x[i];
                break;
            case '+':
            case '-':
                std::cin>>x[i]>>y[i];
                break;
            }
        }
        dfs(n);
        std::cout<<ans<<std::endl;
    }
    return 0;
}