#include<bits/stdc++.h>
using namespace std;
long long Id,T,a,b,c,d,u[1000001],dp[1000001],cn,sm[1000001];
struct p{long long q,w,e;}l[1000001];
struct pp{long long q,w;};
vector<pp> qu[1000001];
struct seg{long long mx,ta;}g[3000001];
void pushup(long long qq){g[qq].mx=max(g[qq<<1].mx,g[qq<<1|1].mx);}
void pushdown(long long qq)
{
    if(g[qq].ta)
    {
        g[qq<<1].ta+=g[qq].ta,g[qq<<1|1].ta+=g[qq].ta;
        g[qq<<1].mx+=g[qq].ta,g[qq<<1|1].mx+=g[qq].ta;
        g[qq].ta=0;
    }
}
void build(long long x,long long ll,long long rr)
{
    g[x].ta=0;
    if(ll==rr)
    {
        g[x].mx=0;
        return;
    }long long mid=((ll+rr)>>1);
    build(x<<1,ll,mid),build(x<<1|1,mid+1,rr);pushup(x);
}
void change(long long x,long long ll,long long rr,long long qq,long long ww,long long ee)
{
    if(ll>=qq&&rr<=ww)
    {
        g[x].mx+=ee,g[x].ta+=ee;
        return;
    }long long mid=((ll+rr)>>1);pushdown(x);
    if(mid>=ww) change(x<<1,ll,mid,qq,ww,ee);
    else if(mid<qq) change(x<<1|1,mid+1,rr,qq,ww,ee);
    else change(x<<1,ll,mid,qq,ww,ee),change(x<<1|1,mid+1,rr,qq,ww,ee);pushup(x);
}
void change1(long long x,long long ll,long long rr,long long qq,long long ee)
{
    if(ll==rr)
    {
        g[x].mx=ee;
        return;
    }long long mid=((ll+rr)>>1);
    if(mid>=qq) change1(x<<1,ll,mid,qq,ee);
    else change1(x<<1|1,mid+1,rr,qq,ee);pushup(x);
}
long long query(long long x,long long ll,long long rr,long long qq,long long ww)
{
    if(ll>=qq&&rr<=ww) return g[x].mx;
    long long mid=((ll+rr)>>1);pushdown(x);
    if(mid>=ww) return query(x<<1,ll,mid,qq,ww);
    if(mid<qq) return query(x<<1|1,mid+1,rr,qq,ww);
    return max(query(x<<1,ll,mid,qq,ww),query(x<<1|1,mid+1,rr,qq,ww));
}
inline int read(){char c;int x=0,fl=1;while(c=getchar()){if(c>='0'&&c<='9') break;if(c=='-') fl=-1;}x=c-'0';while(c=getchar()){if(c<'0'||c>'9') break;x=(x<<1)+(x<<3)+c-'0';}return x*fl;}
void solve()
{
//    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    a=read(),b=read(),c=read(),d=read();
    cn=0;u[++cn]=0;
    for(int i=1;i<=b;i++)
    {
        l[i].q=read(),l[i].w=read(),l[i].e=read();
        l[i].w=l[i].q-l[i].w+1;
        if(l[i].w>=1) u[++cn]=l[i].q,u[++cn]=l[i].w,u[++cn]=l[i].w-1;
    }
    sort(u+1,u+cn+1);
    cn=unique(u+1,u+cn+1)-u-1;
    for(int i=1;i<=b;i++)
    {
        if(l[i].w<1) continue;
        l[i].q=lower_bound(u+1,u+cn+1,l[i].q)-u;
        l[i].w=lower_bound(u+1,u+cn+1,l[i].w)-u;
        qu[l[i].q].push_back(pp{l[i].w,l[i].e});
    }
    for(int i=0;i<=cn;i++) sm[i]=0;
    dp[1]=dp[0]=0;u[0]=-1e9;
    build(1,0,cn);
    change1(1,0,cn,1,dp[1]+u[3]*d);
    change1(1,0,cn,0,dp[0]+u[2]*d);
    for(int i=2;i<=cn;i++)
    {
        dp[i]=dp[i-1];
        long long hh=lower_bound(u+1,u+cn+1,u[i]-c+1)-u;
        for(int j=0;j<qu[i].size();j++)
        {
            if(qu[i][j].q>=1) sm[1]+=qu[i][j].w;
            if(qu[i][j].q>=2)
            {
                change(1,0,cn,0,qu[i][j].q-2,qu[i][j].w);
            }
        }
        if(u[i]<=c) dp[i]=max(dp[i],sm[1]-u[i]*d);
        hh=max(hh,(long long)(2));
        dp[i]=max(dp[i],query(1,0,cn,hh-2,i-2)-(u[i]+1)*d);
        change1(1,0,cn,i,dp[i]+u[i+2]*d);
    }
    printf("%lld\n",dp[cn]);
    for(int i=1;i<=cn;i++) qu[i].clear();
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    // freopen("run.out","w",stdout);
    Id=read(),T=read();
    for(int ii=1;ii<=T;ii++) solve();
    return 0;
}