// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int id,T,n,m,v[100005],fa[200005],val[200005],siz[200005];
int find(int now)
{
    if(now==fa[now])
        return now;
    int res=find(fa[now]);
    val[now]*=val[fa[now]];
    return fa[now]=res;
}
void connect(int A,int B,int v)
{
    if(find(A)!=find(B))
    {
        v*=val[A]*val[B];
        val[find(B)]*=v;
        fa[find(B)]=find(A);
    }
    else if(val[A]*val[B]!=v)
        val[find(A)]=0;
}
signed main()
{
    freopen("tribool.in","r",stdin)&&freopen("tribool.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>id>>T;
    while(T--)
    {
        std::cin>>n>>m;
        ++n;
        std::iota(v+1,v+1+n,1);
        for(int i=1;i<=m;++i)
        {
            static char opt;
            static int x,y;
            std::cin>>opt;
            switch(opt)
            {
            case 'T':
                std::cin>>x;
                v[x]=+n;
                break;
            case 'F':
                std::cin>>x;
                v[x]=-n;
                break;
            case 'U':
                std::cin>>x;
                v[x]=0;
                break;
            case '+':
                std::cin>>x>>y;
                v[x]=+v[y];
                break;
            case '-':
                std::cin>>x>>y;
                v[x]=-v[y];
                break;
            }
        }
        std::iota(fa+1,fa+1+n+n,1);
        std::fill(val+1,val+1+n+n,+1);
        std::fill(siz+1,siz+1+n+n,0);
        for(int i=1;i<=n;++i)
            if(v[i])
                connect(std::abs(v[i]),i+n,v[i]>0?+1:-1);
            else
                val[find(i)]=0;
        for(int i=1;i<=n;++i)
            connect(i,i+n,+1);
        for(int i=1;i<=n+n;++i)
            if(val[i])
                ++siz[find(i)];
            else
                val[find(i)]=0;
        int ans=0;
        for(int i=1;i<=n+n;++i)
            if(find(i)==i&&val[i])
                ans+=siz[i];
        std::cout<<(n+n-ans)/2<<std::endl;
    }
    return 0;
}