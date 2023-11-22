#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[1000010];
int b[1000010];
int nowa[1000010];
int nowb[1000010];
int vis[2010][2010];
int ca[1000010],ya[1000010];
int cb[1000010],yb[1000010];
struct node
{
    int x,y;
};
int head,tail;
node que[4000010];
bool calc(int now)
{
    bool flag=(nowa[1]<nowb[1]);
    if(nowa[1]==nowb[1]) return 0;
    if(nowa[n]==nowb[m]) return 0;
    if(flag!=(nowa[n]<nowb[m])) return 0;
    // dp[1][1]=1;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         if(i==1&&j==1) continue;
    //         dp[i][j]=0;
    //         if(flag)
    //         {
    //             if(nowa[i]<nowb[j]) dp[i][j]=dp[i-1][j]|dp[i][j-1]|dp[i-1][j-1];
    //         }
    //         else
    //         {
    //             if(nowa[i]>nowb[j]) dp[i][j]=dp[i-1][j]|dp[i][j-1]|dp[i-1][j-1];
    //         }
    //     }
    // }
    if(!flag)
    {
        for(int i=1;i<=n;i++) nowa[i]=-nowa[i];
        for(int i=1;i<=m;i++) nowb[i]=-nowb[i];
    }
    if(c>7)
    {
        int posa=1,posb=1;
        int tota=1,totb=1;
        ca[1]=nowa[1],cb[1]=nowb[1];
        int maxx=nowa[1],minn=nowb[1];
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,nowa[i]);
            if(nowa[i]<ca[tota]) ca[++tota]=nowa[i],ya[tota]=maxx,maxx=-1145141919;
        }
        for(int i=1;i<=m;i++)
        {
            minn=min(minn,nowb[i]);
            if(nowb[i]>cb[totb]) cb[++totb]=nowb[i],yb[totb]=minn,minn=1145141919;
        }
        // for(int i=1;i<=tota;i++) printf("%d ",ya[i]);
        // printf("\n");
        // for(int i=1;i<=totb;i++) printf("%d ",yb[i]);
        // printf("\n");
        int lsta=0,lstb=0;
        while(lsta!=posa||lstb!=posb)
        {
            lsta=posa,lstb=posb;
            if(posa<tota&&cb[posb]>ya[posa+1]) posa++;
            if(posb<totb&&ca[posa]<yb[posb+1]) posb++;
        }
        if(posa==tota&&posb==totb) return 1;
        return 0;
    }
    head=tail=1,que[1]=(node){1,1};
    while(head<=tail)
    {
        node u=que[head++];
        if(u.x<n&&nowa[u.x+1]<nowb[u.y]&&vis[u.x+1][u.y]!=now) vis[u.x+1][u.y]=now,que[++tail]=(node){u.x+1,u.y};
        if(u.y<m&&nowa[u.x]<nowb[u.y+1]&&vis[u.x][u.y+1]!=now) vis[u.x][u.y+1]=now,que[++tail]=(node){u.x,u.y+1};
        if(u.x<n&&u.y<m&&nowa[u.x+1]<nowb[u.y+1]&&vis[u.x+1][u.y+1]!=now) vis[u.x+1][u.y+1]=now,que[++tail]=(node){u.x+1,u.y+1};
        if(vis[n][m]==now) return 1;
    }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),nowa[i]=a[i];
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),nowb[i]=b[i];
    printf("%d",calc(1));
    for(int i=1;i<=q;i++)
    {
        int numa,numb;
        int pos,val;
        scanf("%d%d",&numa,&numb);
        for(int i=1;i<=n;i++) nowa[i]=a[i];
        for(int i=1;i<=m;i++) nowb[i]=b[i];
        for(int i=1;i<=numa;i++) scanf("%d%d",&pos,&val),nowa[pos]=val;
        for(int i=1;i<=numb;i++) scanf("%d%d",&pos,&val),nowb[pos]=val;
        // for(int i=1;i<=n;i++) printf("%d ",nowa[i]);
        // printf("\n");
        // for(int i=1;i<=n;i++) printf("%d ",nowb[i]);
        // printf("\n");
        printf("%d",calc(i+1));
    }
    printf("\n");
    return 0;
}
/*
*/
