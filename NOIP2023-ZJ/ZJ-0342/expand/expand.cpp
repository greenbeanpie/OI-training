#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N=5e5+86,INF=0x7f7f7f7f;

template<typename T>
inline void read(T &x)
{
    T k=1;char ch=getchar();x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')k=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
    x*=k;
}

int c,n,m,q,a[N],b[N],rta,rtb;
stack<pii> st1,st2;
struct Tree{int mn,mx,ls,rs;}t[N<<3];
int cnt;
void push_up(int o){t[o].mn=min(t[t[o].ls].mn,t[t[o].rs].mn),t[o].mx=max(t[t[o].ls].mx,t[t[o].rs].mx);}
int builda(int o,int l,int r)
{
    o=++cnt;
    if(l==r)
    {
        t[o].mn=t[o].mx=a[l];
        return o;
    }
    int mid=l+r>>1;
    t[o].ls=builda(t[o].ls,l,mid);
    t[o].rs=builda(t[o].rs,mid+1,r);
    push_up(o);
    return o;
}
int buildb(int o,int l,int r)
{
    o=++cnt;
    if(l==r)
    {
        t[o].mn=t[o].mx=b[l];
        return o;
    }
    int mid=l+r>>1;
    t[o].ls=buildb(t[o].ls,l,mid);
    t[o].rs=buildb(t[o].rs,mid+1,r);
    push_up(o);
    return o;
}
void update(int o,int l,int r,int x,int v)
{
    if(l==r)
    {
        t[o].mn=t[o].mx=v;
        return;
    }
    int mid=l+r>>1;
    if(mid>=x) update(t[o].ls,l,mid,x,v);
    else update(t[o].rs,mid+1,r,x,v);
    push_up(o);
}
int querymax(int o,int l,int r,int L,int R)
{
    if(l>=L&&r<=R) return t[o].mx;
    int mid=l+r>>1,res=0;
    if(mid>=L) res=max(res,querymax(t[o].ls,l,mid,L,R));
    if(R>mid) res=max(res,querymax(t[o].rs,mid+1,r,L,R));
    return res;
}
int querymin(int o,int l,int r,int L,int R)
{
    if(l>=L&&r<=R) return t[o].mn;
    int mid=l+r>>1,res=INF;
    if(mid>=L) res=min(res,querymin(t[o].ls,l,mid,L,R));
    if(R>mid) res=min(res,querymin(t[o].rs,mid+1,r,L,R));
    return res;
}

int findl(int rt,int x,int v,int beg,int ed)
{
    int r=x,l=1,res=0;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(querymin(rt,beg,ed,mid,x)<v) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
int findr(int rt,int x,int v,int beg,int ed)
{
    int r=ed,l=x,res=ed+1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(querymax(rt,beg,ed,x,mid)>=v) res=mid,r=mid-1;
        else l=mid+1;
    }
    return res-1;
}

bool calc()
{
    if(b[1]>a[1])
    {
        int p=1;
        bool f=true;
        for(int i=1;i<=m;i++)
        {
            if(a[p]>=b[i]) p=findl(rta,p,b[i],1,n);//while(p&&a[p]>=b[i]) p--;
            else p=findr(rta,p,b[i],1,n);//while(p+1<=n&&a[p+1]<b[i]) p++;
            if(!p) 
            {
                f=false;
                break;
            }
        }
        if(f&&p==n) return true;
    }
    if(a[1]>b[1])
    {
        int p=1;
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            if(b[p]>=a[i]) p=findl(rtb,p,a[i],1,m);//while(p&&b[p]>=a[i]) p--;
            else p=findr(rtb,p,a[i],1,m);//while(p+1<=m&&b[p+1]<a[i]) p++;
            if(!p)
            {
                f=false;
                break;
            }
        }
        if(f&&p==m) return true;
    }
    return false;
}

void solve()
{
    read(c),read(n),read(m),read(q);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=m;i++) read(b[i]);
    rta=builda(rta,1,n);
    rtb=buildb(rtb,1,m);
    if(calc()) putchar('1');
    else putchar('0');
    for(int i=1;i<=q;i++)
    {//printf("%d\n",i);
        int k1,k2;//puts("dss");
        read(k1),read(k2);
        for(int j=1,x,y;j<=k1;j++)
            read(x),read(y),st1.push({x,a[x]}),update(rta,1,n,x,y),a[x]=y;
        for(int j=1,x,y;j<=k2;j++)
            read(x),read(y),st2.push({x,b[x]}),update(rtb,1,m,x,y),b[x]=y;
        if(calc()) putchar('1');
        else putchar('0');
        while(!st1.empty()) update(rta,1,n,st1.top().first,st1.top().second),a[st1.top().first]=st1.top().second,st1.pop();
        while(!st2.empty()) update(rtb,1,m,st2.top().first,st2.top().second),b[st2.top().first]=st2.top().second,st2.pop();
    }
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    solve();
    return 0;
}