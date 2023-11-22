#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int x[maxn],n,he[maxn],ne[maxn];
void dfs(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(x[i]>=2)
            x[i]=(x[i]&1)?((x[u]>=0)?x[u]^1:-1):x[u],
            dfs(i);
}
inline int solve()
{
    int i,j,k,cnt;
    for(i=1;i<=n;i++)
        if(x[i]<=1)
            dfs(i);
    for(i=1;i<=n;i++)
        if(x[i]>=2)
        {
            for(j=x[i]>>1,k=x[j]>>1;j!=k;j=x[j]>>1,k=x[x[k]>>1]>>1);
            for(cnt=x[j]&1,j=x[j]>>1;j!=k;j=x[j]>>1)
                cnt^=x[j]&1;
            x[j]=cnt?-1:0;
            dfs(j);
            assert(x[i]<2);
        }
    for(i=1,cnt=0;i<=n;i++)
        if(x[i]==-1)
            cnt++;
    return cnt;
}
int main()
{
    int T,m,i,j;
    char op[3];
    freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
    scanf("%*d%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) x[i]=i<<1;
        while(m--)
        {
            scanf("%s%d",op,&i);
            if(op[0]=='T') x[i]=1;
            else if(op[0]=='F') x[i]=0;
            else if(op[0]=='U') x[i]=-1;
            else if(scanf("%d",&j),op[0]=='+')
                x[i]=x[j];
            else if(x[j]>=2) x[i]=x[j]^1;
            else if(x[j]==-1) x[i]=-1;
            else x[i]=x[j]^1;
        }
        for(i=1;i<=n;i++) he[i]=-1;
        for(i=1;i<=n;i++)
            if(x[i]>=2)
                ne[i]=he[x[i]>>1],he[x[i]>>1]=i;
        printf("%d\n",solve());
    }
    fclose(stdin),fclose(stdout);
    return 0;
}