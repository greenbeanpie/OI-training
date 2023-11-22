#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
#define ld(x) printf("%lld\n",x)
inline int read()
{
    int x=0,f=1,c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)x=x*10+c-48,c=getchar();
    return x*f;
}
struct run{
    int l,r,v;
    bool operator<(const run&b)const{
        return r<b.r;
    }
}a[1234567];
int dp[1234567];
int tag[1234567],mx[1234567];
#define lc o*2
#define rc o*2+1
void pt(int o,int t)
{
    tag[o]+=t;
    mx[o]+=t;
}
void pd(int o)
{
    pt(lc,tag[o]);
    pt(rc,tag[o]);
    tag[o]=0;
}
void pu(int o)
{
    mx[o]=std::max(mx[lc],mx[rc]);
}
void add(int o,int l,int r,int L,int R,int v)
{
    if(L>R)return;
    if(L<=l&&r<=R)
    {
        pt(o,v);
        return;
    }
    int m=l+r>>1;
    pd(o);
    if(L<=m)add(lc,l,m,L,R,v);
    if(m<R)add(rc,m+1,r,L,R,v);
    pu(o);
}
int qr(int o,int l,int r,int L,int R)
{
    if(L>R)return -1e18;
    if(L<=l&&r<=R)return mx[o];
    pd(o);
    int m=l+r>>1,res=-1e18;
    if(L<=m)res=std::max(res,qr(lc,l,m,L,R));
    if(m<R)res=std::max(res,qr(rc,m+1,r,L,R));
    return res;
}
void build(int o,int l,int r)
{
    tag[o]=mx[o]=0;
    if(l!=r)
    {
        int m=l+r>>1;
        build(lc,l,m),build(rc,m+1,r);
    }
}
int cc=0,c[1234657];
void jo(int x){c[++cc]=x;}
std::vector<run>g[1234657];
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int id=read(),t=read();
    while(t--)
    {
        int n=read(),m=read(),k=read(),d=read();
        cc=0;
        for(int i=1;i<=m;i++)
        {
            int x=read(),y=read();
            a[i].l=x-y+1,a[i].r=x,a[i].v=read(),jo(a[i].r),jo(a[i].l);//,jo(a[i].l-2);
        }
        std::sort(c+1,c+1+cc);
        cc=std::unique(c+1,c+1+cc)-c-1;
        build(1,1,cc);
        for(int i=1;i<=cc;i++)g[i].clear();
        for(int i=1;i<=m;i++)
            a[i].l=std::lower_bound(c+1,c+1+cc,a[i].l)-c,
            a[i].r=std::lower_bound(c+1,c+1+cc,a[i].r)-c,
            g[a[i].r].push_back(a[i]);

        // std::sort(a+1,a+1+m);
        int ans=0;
        for(int i=1;i<=cc;i++)
        {
            dp[i]=dp[i-1];
            add(1,1,cc,1,i-1,-d*(c[i]-c[i-1]));
            for(run x:g[i])
            {
                int l=x.l,r=x.r,v=x.v;
                add(1,1,cc,1,l,v);
            }
            int sw=std::upper_bound(c+1,c+1+cc,c[i]-k)-c;
            dp[i]=std::max(dp[i],qr(1,1,cc,sw,i)-d);
            ans=std::max(ans,dp[i]);
            int D=dp[i]-dp[i-1];
            // printf("dp[%lld]=%lld\n",c[i],dp[i]);
            for(int j=i+1;j<=cc;j++)
                if(c[j]>=c[i]+2)
                {
                    add(1,1,cc,j,cc,D);
                    break;
                }
        }
        ld(ans);
    }
}