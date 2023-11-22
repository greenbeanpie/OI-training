#include <bits/stdc++.h>
#define rep(i,l,r) for(auto i(l),i##_end(r);i<=i##_end;++i)
#define per(i,r,l) for(auto i(r),i##_end(l);i>=i##_end;--i)
#define fi first
#define se second
#define pb push_back

using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;
using vii=vector<pii>;

const int N=2e5+5;
int n,m,K,D;
int va[N*2],tot;
struct ran
{
    int l,r,v;
} a[N];
ll f[N*2],tag[N];
vi op[N];
void task()
{
    scanf("%d%d%d%d",&n,&m,&K,&D);
    tot=0;
    rep(i,1,m)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        a[i]={x-y+1,x,v};
        va[++tot]=a[i].l-1;
        va[++tot]=a[i].r;
    }
    sort(va+1,va+tot+1);
    tot=unique(va+1,va+tot+1)-va-1;
    rep(i,1,tot) op[i].clear();
    rep(i,1,m)
    {
        a[i].l=lower_bound(va+1,va+tot+1,a[i].l)-va;
        a[i].r=lower_bound(va+1,va+tot+1,a[i].r)-va;
        op[a[i].r].pb(i);
    }
    // rep(i,1,tot) printf("%d ",va[i]); puts("");
    // rep(i,1,m) printf("[%d %d]\n",a[i].l,a[i].r);
    rep(j,0,tot) f[j]=0;
    ll ans=0;
    rep(i,1,tot)
    {
        ll t0=f[0];
        per(j,i-1,1)
        {
            if(va[i-1]-va[j-1]>K) break;
            f[0]=max(f[0],f[j]);
        }
        ans=max(ans,f[0]);
        
        per(j,i,1)
        {
            if(va[i]-va[j-1]>K) break;
            tag[j]=0;
        }
        tag[i]+=ll(va[i]-va[i-1])*-D;
        f[i]+=t0;
        for(int id:op[i]) tag[a[id].l]+=a[id].v;
        ll cur=0;
        per(j,i,1)
        {
            if(va[i]-va[j-1]>K) break;
            cur+=tag[j];
            f[j]+=cur;
            ans=max(ans,f[j]);
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C,T;
    scanf("%d%d",&C,&T);
    while(T--) task();
    return 0;
}