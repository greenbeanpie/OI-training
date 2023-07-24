#include <cstdio>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <algorithm>

using std::sort;
using std::unique;
using std::lower_bound;

const int maxn=2e5+100;

int a[maxn],b[maxn];
int L[maxn],R[maxn],blo[maxn];

struct Qry
{
    int l,r,id;
    bool operator< (const Qry& q){return blo[l]==blo[q.l]?r<q.r:l<q.l;}
}Q[maxn];

template<class T>inline T max(T a,T b){return a<b?b:a;}
template<class T>inline T min(T a,T b){return a<b?a:b;}

int cnt[maxn];
int64_t tmp;

inline void add(int x,int val=1)
{
    cnt[a[x]]+=val;
    tmp=max(tmp,(int64_t)cnt[a[x]]*b[a[x]]);
}

inline int64_t brute_force(int l,int r)
{
    static int c[maxn];
    int64_t ans=0;
    for (int i=l;i<=r;++i) ++c[a[i]];
    for (int i=l;i<=r;++i) ans=max(ans,(int64_t)c[a[i]]*b[a[i]]);
    for (int i=l;i<=r;++i) --c[a[i]];
    return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("AT_joisc2014_c.in", "r", stdin);
	freopen("AT_joisc2014_c_TJ.out", "w", stdout);
#endif
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),b[i]=a[i];
    for (int i=1;i<=q;++i)
        scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
    sort(b+1,b+n+1);
    int tot=unique(b+1,b+n+1)-b-1;
    // for (int i=1;i<=tot;++i) printf("%d ",b[i]);
    // putchar('\n');
    // printf("%d\n",tot);
    for (int i=1;i<=n;++i)
        a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    int T=sqrt(n),bl=n/T;
    for (int i=1;i<=bl;++i)
        L[i]=R[i-1]+1,R[i]=L[i]+T-1;
    if (R[bl]<n) ++bl,L[bl]=R[bl-1]+1,R[bl]=n;
    for (int i=1;i<=n;++i)
        blo[i]=(i-1)/T+1;
    sort(Q+1,Q+q+1);
    static int64_t ans[maxn];
    for (int i=1,lp=1,r=0,l=0;i<=bl;++i)
    {
        memset(cnt,0,sizeof(cnt));
        r=R[i];
        tmp=0;
        // for (l=L[i];l<=R[i];++l) add(l,-1);
        while (blo[Q[lp].l]==i)
        {
            l=R[i]+1;
            if (Q[lp].r-Q[lp].l<=T)
            {
                ans[Q[lp].id]=brute_force(Q[lp].l,Q[lp].r);
                ++lp;
                continue;
            }
            while (Q[lp].r>r) add(++r);
            int64_t now=tmp;
            while (l>Q[lp].l) add(--l);
            ans[Q[lp].id]=tmp;
            tmp=now;
            while (l<=R[i]) --cnt[a[l++]];
            ++lp;
        }
    }
    for (int i=1;i<=q;++i) printf("%lld\n",ans[i]);
}
