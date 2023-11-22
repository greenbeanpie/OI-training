#include <bits/stdc++.h>
using namespace std;
#define push askdfhkad
#define tag asdjkfasdf
typedef long long ll;
const int maxn=100005;
const ll inf=0x3fffffffffffffffll;
int s[maxn],t[maxn],n,k,id[maxn];
ll f[maxn],d,maxx[maxn<<2],tag[maxn<<2];
struct node
{
    int l,r,lid;
    ll v;
    inline bool operator <(const node &p) const
    {
        return r<p.r;
    }
}p[maxn];
inline void pushup(int rt) { maxx[rt]=max(maxx[rt<<1],maxx[(rt<<1)|1]); }
inline void push(int rt,ll a) { maxx[rt]+=a,tag[rt]+=a; }
inline void pushdown(int rt) { if(tag[rt]) push(rt<<1,tag[rt]),push((rt<<1)|1,tag[rt]),tag[rt]=0; }
void build(int rt,int l,int r)
{
    tag[rt]=0,maxx[rt]=-inf;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid),build((rt<<1)|1,mid+1,r);
}
void update(int rt,int l,int r,int x,int y,ll z)
{
    if(x<=l && r<=y) { push(rt,z); return; }
    int mid=(l+r)>>1;
    pushdown(rt);
    if(x<=mid) update(rt<<1,l,mid,x,y,z);
    if(mid<y) update((rt<<1)|1,mid+1,r,x,y,z);
    pushup(rt);
}
ll query(int rt,int l,int r,int x,int y)
{
    if(x>y) return -inf;
    if(x<=l && r<=y) return maxx[rt];
    int mid=(l+r)>>1; ll res=-inf;
    pushdown(rt);
    if(x<=mid) res=max(res,query(rt<<1,l,mid,x,y));
    if(mid<y) res=max(res,query((rt<<1)|1,mid+1,r,x,y));
    return res;
}
int main()
{
    int T,i,j;
    freopen("run.in","r",stdin),freopen("run.out","w",stdout);
    scanf("%*d%d",&T);
    while(T--)
    {
        scanf("%*d%d%d%lld",&n,&k,&d);
        for(i=1;i<=n;i++)
            scanf("%d%d%lld",&p[i].r,&p[i].l,&p[i].v),
            p[i].l=p[i].r-p[i].l+1,id[i]=i;
        sort(p+1,p+1+n);
        sort(id+1,id+1+n,[](int x,int y){return p[x].l<p[y].l;});
        for(i=1;i<=n;i++)
            p[id[i]].lid=i,s[i]=p[id[i]].l,t[i]=p[i].r;
        p[0].r=-1,f[0]=0;
        build(1,1,n);
        for(i=1;i<=n;i++)
        {
            update(1,1,n,1,upper_bound(s+1,s+1+n,p[i].l)-s-1,p[i].v);
            update(1,1,n,p[i].lid,p[i].lid,inf+f[upper_bound(t+1,t+1+n,p[i].l-2)-t-1]+d*(p[i].l-1));
            f[i]=max(f[i-1],query(1,1,n,lower_bound(s+1,s+1+n,p[i].r-k+1)-s,n)-d*p[i].r);
        }
        printf("%lld\n",f[n]);
    }
    fclose(stdin),fclose(stdout);
    return 0;
}