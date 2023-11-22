#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
const int maxm=1005;
int n,m,k,l[maxm],r[maxm];
ll v[maxm],d,f[maxn];
int main()
{
    int T,i,j,t;
    ll cur;
    freopen("run.in","r",stdin),freopen("run.ans","w",stdout);
    scanf("%*d%d",&T);
    while(T--)
    {
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        for(i=0;i<m;i++)
            scanf("%d%d%lld",&r[i],&l[i],&v[i]),l[i]=r[i]-l[i]+1;
        f[0]=0;
        for(i=1;i<=n;i++)
            for(f[i]=f[i-1],j=i;j>=1 && i-j+1<=k;j--)
            {
                cur=((j>=2)?f[j-2]:0)-(i-j+1)*d;
                for(t=0;t<m;t++)
                    if(j<=l[t] && r[t]<=i)
                        cur+=v[t];
                f[i]=max(f[i],cur);
            }
        printf("%lld\n",f[n]);
    }
    fclose(stdin),fclose(stdout);
    return 0;
}