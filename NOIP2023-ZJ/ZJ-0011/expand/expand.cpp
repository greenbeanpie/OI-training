#include<bits/stdc++.h>
using namespace std;
int Id,a,b,d[1000001],f[1000001],an,q1,q2,q,w,cn,st[1000001],cn1,st1[1000001],mn[1000001],ls[1000001];
int lsd[1000001],lsf[1000001];
int work()
{
    // for(int i=1;i<=a;i++) cout<<d[i]<<" ";cout<<"\n";
    // for(int i=1;i<=b;i++) cout<<f[i]<<" ";cout<<"\n";cout<<"\n";
    int mx1=0,mx2=0,fll=0;
    for(int i=1;i<=a;i++) mx1=max(mx1,d[i]);
    for(int i=1;i<=b;i++) mx2=max(mx2,f[i]);
    if(mx1==mx2) return 0;
    if(mx1<mx2)
    {
        fll=1;swap(a,b);
        for(int i=1;i<=max(a,b);i++) swap(d[i],f[i]);
    }
    cn=0;
    for(int i=1;i<=a;i++)
    {
        if(cn==0||d[i]>d[st[cn]]) st[++cn]=i;
    }cn1=0;
    int mxx=cn;
    for(int i=a;i>=1;i--)
    {
        if(cn1==0||d[i]>d[st1[cn1]]) st1[++cn1]=i;
    }
    ls[b+1]=0;
    for(int i=b;i>=1;i--) ls[i]=max(ls[i+1],f[i]);
    for(int i=cn1-1;i>=1;i--) st[++cn]=st1[i];
    for(int i=1;i<cn;i++)
    {
        mn[i]=1e9+5;
        for(int j=st[i]+1;j<=st[i+1];j++)
        {
            mn[i]=min(mn[i],d[j]);
        }
    }
    int fl=1,nw=1;
    for(int i=1;i<mxx;i++)
    {
        while(nw<=b&&mn[i]<=f[nw])
        {
            if(f[nw]>=d[st[i]]) fl=0;
            ++nw;
            if(f[nw]>=d[st[i]]) fl=0;
        }
        if(nw>b)
        {
            fl=0;
        }
    }
    for(int i=mxx;i<cn;i++)
    {
        while(nw<=b&&(mn[i]<=f[nw]||d[st[i+1]]<=ls[nw])) ++nw;
        if(nw>b)
        {
            fl=0;
        }
    }
    if(d[a]<=f[b]) fl=0;
    if(d[1]<=f[1]) fl=0;
    if(fll)
    {
        swap(a,b);
        for(int i=1;i<=max(a,b);i++) swap(d[i],f[i]);
    }
    return fl;
}
inline int read(){char c;int x=0,fl=1;while(c=getchar()){if(c>='0'&&c<='9') break;if(c=='-') fl=-1;}x=c-'0';while(c=getchar()){if(c<'0'||c>'9') break;x=(x<<1)+(x<<3)+c-'0';}return x*fl;}
int main()
{
//    freopen("expand5.in","r",stdin);
//    freopen("1.out","w",stdout);
     freopen("expand.in","r",stdin);
     freopen("expand.out","w",stdout);
//    scanf("%d%d%d%d",&Id,&a,&b,&c);
    int c;
    Id=read(),a=read(),b=read(),c=read();
    for(int i=1;i<=a;i++)
    {
        d[i]=read();
        lsd[i]=d[i];
    }
    for(int i=1;i<=b;i++)
    {
        f[i]=read();
        lsf[i]=f[i];
    }
    an=work();
    putchar(an+'0');
    for(int i=1;i<=c;i++)
    {
        q1=read(),q2=read();
        for(int j=1;j<=q1;j++)
        {
            q=read(),w=read();
            d[q]=w;
        }
        for(int j=1;j<=q2;j++)
        {
            q=read(),w=read();
            f[q]=w;
        }
        an=work();
        putchar(an+'0');
        for(int j=1;j<=a;j++) d[j]=lsd[j];
        for(int j=1;j<=b;j++) f[j]=lsf[j];
    }printf("\n");
    return 0;
}