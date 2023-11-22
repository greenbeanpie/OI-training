#include<bits/stdc++.h>
using namespace std;
int c,n,m,s,x1,x2,T,i,ans[100005],father[100005],diff[100005];
struct STU{int x,d;}f[100005];
char opt;
inline void read(int &x)
{
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
}
STU find(int x)
{
    if(f[x].x==x)return f[x];
    STU xx=find(f[x].x);
    f[x].x=xx.x,f[x].d^=xx.d;
    return f[x];
}
int get(int x,int d)
{
    if(x<3&&d)return 3-x;
    return x;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        memset(diff,0,sizeof(diff));
        memset(ans,0,sizeof(ans));
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&m),getchar();
        for(i=1;i<=n+3;i++)father[i]=i,f[i].x=i;
        for(i=1;i<=m;i++)
        {
            opt=getchar();
            if(opt=='+')
            {
                read(x1),read(x2);
                father[x1]=father[x2],diff[x1]=0^diff[x2];
            }
            if(opt=='-')
            {
                read(x1),read(x2);
                father[x1]=father[x2],diff[x1]=1^diff[x2];
            }
            if(opt=='T')
            {
                read(x1),x2=n+1;
                father[x1]=x2,diff[x1]=0;
            }
            if(opt=='F')
            {
                read(x1),x2=n+2;
                father[x1]=x2,diff[x1]=0;
            }
            if(opt=='U')
            {
                read(x1),x2=n+3;
                father[x1]=x2,diff[x1]=0;
            }
        }
        for(i=1;i<=n;i++)
        {
            STU fx=find(i),fy=find(father[i]);
            f[fx.x].x=fy.x,f[fx.x].d^=fy.d^diff[i];
        }
        for(i=1;i<=n;i++)f[i]=find(f[i].x);
        for(i=1;i<=n;i++)
            if((f[i].x==i&&f[i].d==1)||f[i].x==n+3)ans[i]=-1;
        for(i=1;i<=n;i++)
            if(f[i].x!=i&&f[i].x<=n)ans[i]=ans[f[i].x];
        s=0;
        for(i=1;i<=n;i++)s+=(ans[i]==-1);
        printf("%d\n",s);
    }
}
