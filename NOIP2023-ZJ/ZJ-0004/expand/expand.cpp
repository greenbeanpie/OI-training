#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,x_[maxn],y_[maxn],x[maxn],y[maxn];
char ans[maxn];
inline bool check()
{
    int i,l,r,l_,r_/*,pre*/,k;
    if(x[1]==y[1]) return false;
    if(x[1]<y[1])
    {
        for(i=1;i<=n;i++) x[i]=-x[i];
        for(i=1;i<=m;i++) y[i]=-y[i];
    }
    if(x[n]<=y[m]) return false;
    for(k=1,i=2;i<=n;i++)
        if(x[i]>=x[k])
            k=i;
    for(/*x[pre=0]=x[1]-1,*/l=r=1,i=1;i<=k;i++)
    {
        // if(x[i]>=x[pre])
        // {
            while(r<m && x[i]>y[r+1]) r++;
        //     pre=i;
        // }
        while(l<=r && x[i]<=y[l]) l++;
        if(l>r) return false;
    }
    for(/*x[pre=n+1]=x[n]-1,*/l_=r_=m,i=n;i>=k;i--)
    {
        // if(x[i]>x[pre])
        // {
            while(l_>1 && x[i]>y[l_-1]) l_--;
        //     pre=i;
        // }
        while(l_<=r_ && x[i]<=y[r_]) r_--;
        if(l_>r_) return false;
    }
    return l<=r_ && l_<=r;
}
int main()
{
    int T,q,i,kx,ky,j;
    freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
    scanf("%*d%d%d%d",&n,&m,&q);
    for(i=0;i<n;i++) scanf("%d",&x_[i]);
    for(i=0;i<m;i++) scanf("%d",&y_[i]);
    ans[q+1]='\0';
    memcpy(x+1,x_,sizeof(int)*n);
    memcpy(y+1,y_,sizeof(int)*m);
    for(ans[0]=check()?'1':'0',i=1;i<=q;i++)
    {
        memcpy(x+1,x_,sizeof(int)*n);
        memcpy(y+1,y_,sizeof(int)*m);
        scanf("%d%d",&kx,&ky);
        while(kx--)
            scanf("%d",&j),scanf("%d",&x[j]);
        while(ky--)
            scanf("%d",&j),scanf("%d",&y[j]);
        ans[i]=check()?'1':'0';
    }
    printf("%s\n",ans);
    fclose(stdin),fclose(stdout);
    return 0;
}