#include <bits/stdc++.h>
#define rep(i,l,r) for(auto i(l),i##_end(r);i<=i##_end;++i)
#define per(i,r,l) for(auto i(r),i##_end(l);i>=i##_end;--i)
#define fi first
#define se second

using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;
using vii=vector<pii>;

const int N=1e6+5;
int n,m,tot,T,F,U;
int fa[N],shl[N],w[N],unk[N],sz[N];
int getfa(int x)
{
    if(x==fa[x]) return x;
    getfa(fa[x]);
    w[x]^=w[fa[x]];
    return fa[x]=fa[fa[x]];
}
struct DSU
{
    int fa[N],w[N],uke[N];
    int getfa(int x)
    {
        if(x==fa[x]) return x;
        getfa(fa[x]);
        w[x]^=w[fa[x]];
        return fa[x]=fa[fa[x]];
    }
    void murge(int x,int y,int val)
    {
        getfa(x); 
        getfa(y);
        // printf("murge%d %d %d: fax=%d fay=%d wx=%d wy=%d\n",x,y,val,fa[x],fa[y],w[x],w[y]);
        if(fa[x]!=fa[y])
        {
            w[fa[x]]=w[x]^w[y]^val;
            fa[fa[x]]=fa[y];
        }
        else
        {
            if((w[x]^w[y]^val)) uke[fa[x]]=1;
        }
    }
} D;
void task()
{
    scanf("%d%d",&n,&m);
    tot=n*2;
    T=++tot;
    F=++tot;
    U=++tot;
    rep(i,1,tot) fa[i]=i,w[i]=0;
    rep(i,1,tot) unk[i]=sz[i]=0;
    rep(i,1,n) 
        fa[i]=shl[i]=i+n;
    rep(i,1,m)
    {
        char op; 
        int x,y;
        scanf(" %c",&op);
        if(op=='T'||op=='F'||op=='U')
        {
            scanf("%d",&x);
            shl[x]=++tot;
            if(op=='T') fa[shl[x]]=T;
            if(op=='F') fa[shl[x]]=F;
            if(op=='U') fa[shl[x]]=U;
            w[shl[x]]=0;
            fa[x]=shl[x],w[x]=0;
        }
        else if(op=='+')
        {
            scanf("%d%d",&x,&y);
            int shy=shl[y];
            shl[x]=++tot;
            fa[shl[x]]=shy,w[shl[x]]=0;
            fa[x]=shl[x],w[x]=0;
        }
        else
        {
            scanf("%d%d",&x,&y);
            int shy=shl[y];
            shl[x]=++tot;
            fa[shl[x]]=shy,w[shl[x]]=1;
            fa[x]=shl[x],w[x]=0;
        }
        // printf("i=%d\n",i);
    // rep(i,1,n)
    // {
    //     int f=getfa(i);
    //     printf("%d ",f);
    // }
    // puts("");
    }
    rep(i,1,n) D.fa[i]=i,D.w[i]=0,D.uke[i]=0;
    unk[U]=1;
    // rep(i,1,n)
    // {
    //     int f=getfa(i);
    //     printf("%d ",f);
    // }
    // puts("");
    
    // rep(i,1,n)
    // {
    //     int f=w[i];
    //     printf("%d ",f);
    // }
    // puts("");
    rep(i,1,n)
    {
        int f=getfa(i),w=::w[i];
        if(f==T||f==F||f==U)
        {
            if(f==U) D.uke[i]=1;
        }
        else
        {
            assert(n+1<=f&&f<=n*2);
            // printf("i=%d j=%d\n",i,f-n);
            D.murge(i,f-n,w);
        }
        // if(fa[i]==i+n&&w[i]) unk[fa[i]]=1;
    // rep(i,1,n) printf("%d",D.w[i]); puts("");
    }
    rep(i,1,n) sz[i]=0;
    rep(i,1,n)
    {
        D.uke[D.getfa(i)]|=D.uke[i];
        sz[D.getfa(i)]++;
    }
    int ans=0;
    rep(i,1,n)
        if(D.getfa(i)==i&&D.uke[i]) ans+=sz[i]; 
    // rep(i,1,tot) 
    //     if(getfa(i)==i&&unk[i]) ans+=sz[i];
    printf("%d\n",ans);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;
    scanf("%d%d",&C,&T);
    while(T--) task();
    return 0;
}