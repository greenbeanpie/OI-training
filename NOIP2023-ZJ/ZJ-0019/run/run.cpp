// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int c,T,n,m,k,l[100005],r[100005];
long long v[100005],d,ans,max[1<<19],tag[1<<19];
std::vector<int> app,g[200005];
#define lson (now<<1)
#define rson (lson|1)
#define mid ((l+r)>>1)
void pushdown(int now)
{
    if(long long &v=tag[now])
    {
        max[lson]+=v;
        max[rson]+=v;
        tag[lson]+=v;
        tag[rson]+=v;
        v=0;
    }
}
void pushup(int now){max[now]=std::max(max[lson],max[rson]);}
void build(int now=1,int l=0,int r=app.size())
{
    if(r-l==1)
        return void(max[now]=0);
    pushdown(now);
    build(lson,l,mid);
    build(rson,mid,r);
    pushup(now);
}
void modify(int pos,long long val,int now=1,int l=0,int r=app.size())
{
    if(r-l==1)
        return void(max[now]=val);
    pushdown(now);
    if(pos<mid)
        modify(pos,val,lson,l,mid);
    else
        modify(pos,val,rson,mid,r);
    pushup(now);
}
void add(int L,int R,long long val,int now=1,int l=0,int r=app.size())
{
    if(r<=L||R<=l)
        return;
    if(L<=l&&r<=R)
    {
        max[now]+=val;
        tag[now]+=val;
        return;
    }
    pushdown(now);
    add(L,R,val,lson,l,mid);
    add(L,R,val,rson,mid,r);
    pushup(now);
}
long long query(int L,int R,int now=1,int l=0,int r=app.size())
{
    if(r<=L||R<=l)
        return 0;
    if(L<=l&&r<=R)
        return max[now];
    pushdown(now);
    return std::max(query(L,R,lson,l,mid),query(L,R,rson,mid,r));
}
signed main()
{
    freopen("run.in","r",stdin)&&freopen("run.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>c>>T;
    while(T--)
    {
        std::cin>>n>>m>>k>>d;
        ans=0;
        app.clear();
        for(int i=1;i<=m;++i)
        {
            std::cin>>r[i]>>l[i]>>v[i];
            app.push_back(l[i]=r[i]-l[i]);
            app.push_back(r[i]);
        }
        std::sort(app.begin(),app.end());
        for(int i=1;i<=m;++i)
        {
            l[i]=std::lower_bound(app.begin(),app.end(),l[i])-app.begin();
            r[i]=std::lower_bound(app.begin(),app.end(),r[i])-app.begin();
            g[r[i]].push_back(i);
        }
        build();
        for(std::size_t i=0,j=0;i!=app.size();++i)
        {
            modify(i,ans+app[i]*d);
            while(app[i]-app[j]>k)
                ++j;
            for(auto j:g[i])
                add(0,l[j]+1,v[j]);
            g[i].clear();
            ans=std::max(ans,query(j,i)-app[i]*d);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}