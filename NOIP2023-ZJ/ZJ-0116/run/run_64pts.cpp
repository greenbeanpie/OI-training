#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,k,d;
struct Job{
    int x,y,v;
    bool operator<(Job &t)const{
        return x<t.x;
    }
}a[100001];

struct SegmentTree{
    struct Node{
        int l,r;
        ll maxn;
        ll tag_add,tag_mul;
        inline void add(ll v){
            tag_add+=v,maxn+=v;
        }
        inline void mul(ll v){
            tag_add*=v,tag_mul*=v,maxn*=v;
        }
    }node[500000];
    
    inline void pushup(int id){
        node[id].maxn=max(node[id<<1].maxn,node[id<<1|1].maxn);
    }
    inline void pushdown(int id){
        node[id<<1].mul(node[id].tag_mul);
        node[id<<1].add(node[id].tag_add);
        node[id<<1|1].mul(node[id].tag_mul);
        node[id<<1|1].add(node[id].tag_add);
        node[id].tag_mul=1;
        node[id].tag_add=0;
    }

    void build(int id,int l,int r){
        node[id].l=l,node[id].r=r;
        node[id].maxn=node[id].tag_add=0;
        node[id].tag_mul=1;
        if(l==r)return;
        int mid=l+r>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
    }

    void updateAddMulti(int id,int l,int r,ll v){
        if(l<=node[id].l&&node[id].r<=r){
            node[id].add(v);
            return;
        }
        pushdown(id);
        int mid=node[id].l+node[id].r>>1;
        if(l<=mid)updateAddMulti(id<<1,l,r,v);
        if(mid<r)updateAddMulti(id<<1|1,l,r,v);
        pushup(id);
    }
    void updateAddSingle(int id,int pos,ll v){
        updateAddMulti(id,pos,pos,v);
    }
    void updateMulMulti(int id,int l,int r,ll v){
        if(l<=node[id].l&&node[id].r<=r){
            node[id].mul(v);
            return;
        }
        pushdown(id);
        int mid=node[id].l+node[id].r>>1;
        if(l<=mid)updateMulMulti(id<<1,l,r,v);
        if(mid<r)updateMulMulti(id<<1|1,l,r,v);
        pushup(id);
    }

    ll queryMax(int id,int l,int r){
        if(l<=node[id].l&&node[id].r<=r)
            return node[id].maxn;
        pushdown(id);
        long long ret=-1e18;
        int mid=node[id].l+node[id].r>>1;
        if(l<=mid)ret=max(ret,queryMax(id<<1,l,r));
        if(mid<r)ret=max(ret,queryMax(id<<1|1,l,r));
        return ret;
    }
}_;

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int testId,T; scanf("%d%d",&testId,&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        sort(a+1,a+1+m);
        if(testId==17||testId==18){
            ll ans=0;
            for(int i=1;i<=m;i++){
                if(a[i].y>k)continue;
                if(a[i].v>1ll*d*a[i].y)
                    ans+=a[i].v-d*a[i].y;
            }
            printf("%lld\n",ans);
            continue;
        }
        _.build(1,0,n+1);
        int now=0;
        for(int i=1;i<=n;i++){
            _.updateAddSingle(1,i+1,_.queryMax(1,0,i));
            _.updateAddMulti(1,0,i,-d);
            if(i-k>=0)_.updateMulMulti(1,0,i-k,0);
            while(a[now+1].x==i){
                now++;
                // printf("work %d\n",now);
                if(a[now].y>k)continue;
                // printf("work %d\n",now);
                if(max(i-k+1,0)<=i-a[now].y+1)
                    _.updateAddMulti(1,max(i-k+1,0),i-a[now].y+1,a[now].v);
            }
            // for(int j=0;j<=i+1;j++)
            //     printf("dp[%d][%d] = %lld\n",i,j,_.queryMax(1,j,j));
        }
        printf("%lld\n",_.queryMax(1,max(n-k+1,0),n+1));
    }
    // fprintf(stderr,"%lf\n",clock()*1.0/CLOCKS_PER_SEC);
    return 0;
}