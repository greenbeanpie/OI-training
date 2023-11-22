#include<bits/stdc++.h>
using namespace std;
int c,_,n,m,k,d,up=1000000000;
long long f[1010][1010],ans,inf=1e16;
struct opt{
    int l,r,v;
    bool operator<(const opt &x)const{
        return r==x.r?l<x.l:r<x.r;
    }
}a[100010];
namespace FHQ{
vector<int>g[100010];
struct point{
    long long tag,val,mx;
    int l,r,sz,pri;
}t[200010];
void fill(int k,long long val){
    t[k].val=t[k].mx=val,t[k].tag=t[k].l=t[k].r=0,t[k].sz=1,t[k].pri=rand();
}
int init(int l,int r){
    if(l>r)return 0;
    int p=l+r>>1;
    t[p].tag=0,t[p].val=-1ll*d*(p-1);
    t[p].pri=rand(),t[p].sz=r-l+1;
    t[p].l=init(l,p-1),t[p].r=init(p+1,r);
    t[p].mx=t[l].val;
    return p;
}
void add_tag(int p,long long x){
    t[p].val+=x,t[p].tag+=x,t[p].mx+=x;
}
void psd(int p){
    t[t[p].l].tag+=t[p].tag,t[t[p].l].val+=t[p].tag,t[t[p].l].mx+=t[p].tag;
    t[t[p].r].tag+=t[p].tag,t[t[p].r].val+=t[p].tag,t[t[p].r].mx+=t[p].tag;
    t[p].tag=0;
}
void psu(int p){
    t[p].sz=t[t[p].l].sz+t[t[p].r].sz+1;
    t[p].mx=max(max(t[t[p].l].mx,t[t[p].r].mx),t[p].val);
}
void split(int p,int k,int &x,int &y){
    if(!p)return x=y=0,void();
    psd(p);
    if(t[t[p].l].sz>=k)y=p,split(t[p].l,k,x,t[p].l);
    else x=p,split(t[p].r,k-t[t[p].l].sz-1,t[p].r,y);
    psu(p);
}
int merge(int x,int y){
    if(!x||!y)return x|y;
    if(t[x].pri>t[y].pri){
        psd(x),t[x].r=merge(t[x].r,y),psu(x);
        return x;
    }
    psd(y),t[y].l=merge(x,t[y].l),psu(y);
    return y;
}
}
int main(){
    srand(time(NULL));
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&_),FHQ::t[0].val=FHQ::t[0].mx=-inf;
    while(_--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d%d",&x,&y,&a[i].v);
            a[i].l=x-y+1,a[i].r=x;
        }
        sort(a+1,a+1+m);
        if(c<=9){
            memset(f,0,sizeof(f)),ans=0;
            for(int i=1;i<=m;i++)
                if(a[i].r-a[i].l+1<=k)f[a[i].r][a[i].r-a[i].l+1]+=a[i].v;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=k&&j<=i;j++)f[i][j]+=f[i][j-1];
            for(int i=1;i<=n;i++){
                for(int j=0;j<=k&&j<=i-1;j++)f[i][0]=max(f[i][0],f[i-1][j]);
                for(int j=1;j<=k&&j<=i;j++)f[i][j]+=f[i-1][j-1]-d;
            }
            for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
            printf("%lld\n",ans);
        }else if(c<=14){
            int rt=FHQ::init(1,k+1),tot=k+1,tmpx;
            for(int i=1;i<=n;i++)FHQ::g[i].clear();
            for(int i=1;i<=m;i++)
                if(a[i].r-a[i].l<k)FHQ::g[a[i].r].push_back(i);
            for(int i=1;i<=n;i++){
                FHQ::fill(++tot,FHQ::t[rt].mx);
                FHQ::split(rt,k,rt,tmpx);
                FHQ::add_tag(rt,-d);
                rt=FHQ::merge(tot,rt);
                for(auto j:FHQ::g[i]){
                    FHQ::split(rt,a[j].r-a[j].l+1,rt,tmpx);
                    FHQ::add_tag(tmpx,a[j].v);
                    rt=FHQ::merge(rt,tmpx);
                }
            }
            printf("%lld\n",FHQ::t[rt].mx);
        }
    }
    return 0;
}