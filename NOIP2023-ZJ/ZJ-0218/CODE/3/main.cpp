#include<bits/stdc++.h>
using namespace std;
int p,q,c,xx,n,m,i,j,x[500005],y[500005],a[500005],b[500005];
inline void read(int &x)
{
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
}
void sub()
{
    printf("%d",(a[1]!=b[1]));
    for(i=1;i<=q;i++)
    {
        int kx,ky;
        read(kx),read(ky);
        for(j=1;j<=kx;j++)
        {
            read(p),read(xx);
            a[p]=xx;
        }
        for(j=1;j<=ky;j++)
        {
            read(p),read(xx);
            b[p]=xx;
        }
        printf("%d",(a[1]!=b[1]));
    }
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(i=1;i<=n;i++)read(x[i]);
    for(i=1;i<=m;i++)read(y[i]);
    if(n==m&&n==1){sub();return 0;}
    if(a[1]>a[2])
    for(i=1;i<=q;i++)
    {
        int kx,ky;
        for(j=1;j<=n;j++)a[j]=x[j];
        for(j=1;j<=n;j++)b[j]=y[j];
        read(kx),read(ky);
        for(j=1;j<=kx;j++)
        {
            read(p),read(xx);
            a[p]=xx;
        }
        for(j=1;j<=ky;j++)
        {
            read(p),read(xx);
            b[p]=xx;
        }
        if(a[1]==b[1]){printf("0");continue;}
        if(a[1]<b[1])
        {
            printf("%d",a[2]<b[2]);
            continue;
        }
        if(a[1]>b[1])
        {
            printf("%d",a[2]>b[2]);
            continue;
        }
    }
}
