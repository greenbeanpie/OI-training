#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m,k,d;
long long f[1000010],pre[1000010],temp[1000010];
long long ans,dp[1010][1010];
long long addval[1010][1010];
int x[1000010];
struct node
{
    int x,y,val;
}a[1000010];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&d),ans=0;
        if(c==17||c==18)
        {
            for(int i=1;i<=m;i++)
            {
                int x,y,val;
                scanf("%d%d%d",&x,&y,&val);
                if(val>(long long)y*d) ans+=val-(long long)y*d;
            }
            printf("%lld\n",ans);
            continue;
        }
        if(c>9)
        {
            int now=1;
            memset(f,-0x3f,sizeof(f)),f[0]=0;
            for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val),x[i]=a[i].x;
            sort(x+1,x+m+1),sort(a+1,a+m+1,cmp);
            n=unique(x+1,x+m+1)-x-1;
            for(int i=1;i<=n;i++)
            {
                while(now<=m&&a[now].x==x[i])
                {
                    if(a[now].y<=k) pre[a[now].y]+=a[now].val;
                    now++;
                }
                for(int i=1;i<=k;i++) pre[i]+=pre[i-1];
                long long maxx=0;
                for(int j=0;j<=k;j++) maxx=max(maxx,f[j]),temp[j]=f[j],f[j]=-1145141919810975123;
                for(int j=0;j<=min(k,x[i]-x[i-1]-1);j++) f[j]=maxx-(long long)j*d;
                for(int j=0;j+x[i]-x[i-1]<=k;j++)
                    f[j+x[i]-x[i-1]]=max(f[j+x[i]-x[i-1]],temp[j]-(long long)(x[i]-x[i-1])*d);
                // for(int j=0;j<=k;j++) printf("%d ",f[j]);
                // printf("\n");
                for(int j=0;j<=k;j++) f[j]+=pre[j],pre[j]=0;
                // for(int j=0;j<=k;j++) printf("%d ",f[j]);
                // printf("\n");
            }
            for(int i=0;i<=k;i++) ans=max(ans,f[i]);
            printf("%lld\n",ans);
            continue;
        }
        memset(dp,-0x3f,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,val;
            scanf("%d%d%d",&x,&y,&val);
            if(y<=k) addval[x][y]+=val;
        }
        for(int i=1;i<=n;i++)
        {
            long long maxx=dp[i-1][0];
            for(int j=1;j<=min(i,k);j++) dp[i][j]=dp[i-1][j-1]-d,maxx=max(maxx,dp[i-1][j]);
            dp[i][0]=maxx;
            for(int j=1;j<=min(i,k);j++) addval[i][j]+=addval[i][j-1];
            for(int j=1;j<=min(i,k);j++) dp[i][j]+=addval[i][j],addval[i][j]=0;
        }
        for(int i=0;i<=k;i++) ans=max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
*/
