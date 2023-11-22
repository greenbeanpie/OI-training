#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
// #define int long long
inline int read()
{
    int x=0,f=1,c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)x=x*10+c-48,c=getchar();
    return x*f;
}
int a[1234567],b[1234567],c[1234567],d[1234657];


int id,n,m,q;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int prex[1234567],sufx[1234567];
int pren[1234567],sufn[1234567];
std::vector<int>get(int *a,int n)
{
    prex[0]=sufx[n+1]=-1e9;
    pren[0]=sufn[n+1]=1e9;
    for(int i=1;i<=n;i++)prex[i]=max(prex[i-1],a[i]);
    for(int i=1;i<=n;i++)pren[i]=min(pren[i-1],a[i]);
    for(int i=n;i>=1;i--)sufx[i]=max(sufx[i+1],a[i]);
    for(int i=n;i>=1;i--)sufn[i]=min(sufn[i+1],a[i]);
    std::vector<int>g;
    // printf("%d\n")
    int H=1e9,L=-1e9;
    for(int i=1;i<=n;i++)
    {
        // if(prex[i-1]>a[i]&&a[i]>=sufn[i+1])continue;
        // if(pren[i-1]<a[i]&&a[i]<=sufx[i+1])continue;
        // if(H<=a[i]&&a[i]<=sufx[i+1])continue;
        // if(L>=a[i]&&a[i]>=sufn[i+1])continue;
        if(prex[i]==a[i]||pren[i]==a[i]||sufx[i]==a[i]||sufn[i]==a[i])
        {
            while(g.size()>1)
            {
                int t=g.size()-1;
                if(a[i]>=g[t]&&g[t]>=g[t-1])g.pop_back();
                else if(a[i]<=g[t]&&g[t]<=g[t-1])g.pop_back();
                else break;
            }
            while(g.size()&&g.back()==a[i])g.pop_back();
            g.push_back(a[i]);
        }
            // H=min(H,a[i]);
            // L=max(L,a[i]);
    }
    for(int i=0;i<g.size();i++)
    {
        if(g[i]==prex[n]||g[i]==pren[n])
        {
            for(int j=g.size()-1;j>=0;j--)
                if((g[j]==prex[n]||g[j]==pren[n])&&g[j]!=g[i])
                {
                    // g.erase(g.begin()+i+1,g.begin()+j);
                    std::vector<int>p;
                    for(int k=0;k<g.size();k++)
                        if(k>i&&k<j)continue;
                        else p.push_back(g[k]);
                    return p;
                }
        }
    }
    qwq:
    // printf("mx=%d\n",sufx[1]);
    return g;
}
int f[2][2005];
void query()
{
    if(a[1]==b[1])return printf("0"),void();
    if(a[1]<b[1])
    {
        for(int i=1;i<=n;i++)a[i]=-a[i];
        for(int i=1;i<=m;i++)b[i]=-b[i];
    }
    if(id<=5)
    {
        // puts("aha");
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            int c=i&1,d=c^1;
            memset(f[c],0,sizeof(f[c]));
            for(int j=0;j<=n;j++)
                if(f[d][j])
                {
                    if(j&&a[j]>b[i])f[c][j]=1;
                    if(j<n&&a[j+1]>b[i])f[c][j+1]=1;
                }
            for(int j=1;j<=n;j++)
                if(f[c][j-1]&&a[j]>b[i])f[c][j]=1;
        // for(int j=0;j<=n;j++)printf("%d",f[c][j]);puts("");
        }
        printf("%d",f[m&1][n]);
        return;
    }
    std::vector<int>p,x=get(a,n),y=get(b,m);
    // puts("");
    // printf("%d %d\n",x.size(),y.size());
    // for(int t:x)printf("%d ",t);puts("");
    // for(int t:y)printf("%d ",t);puts("");
    
    if(id>=8&&id<=14)
    {

        int nw=1;
        int tp=1;
        int MN=1e9,MX=-1e9;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]<=y[nw-1]){return printf("0"),void();}
            if(i&&x[i]>x[i-1])tp=1;
            if(i&&x[i]<x[i-1])tp=0;
            // if(tp==0)
            // {
            //     // printf("%d\n",x[i]);
            //     if(MN<x[i])puts("??????");
            //     MN=x[i];
            // }
            // if(tp==1)
            // {
            //     if(MX>x[i])puts("?!!!EQW");
            //     MX=x[i];
            // }
            // if(tp==1)
                while(nw!=y.size()&&x[i]>y[nw])nw++;
            if(nw==y.size()&&i+1!=x.size())
                if(nw>1&&y[nw-1]>y[nw-2])nw--;
            // printf("%d %d\n",i,nw);
            
        }
        return printf("1"),void();
    }
    int XM=0,XX=0,YM=0,YX=0;
    if((XX=*std::max_element(a+1,a+1+n))<=(YX=*std::max_element(b+1,b+1+m)))
        return printf("0"),void();
    if((XM=*std::min_element(a+1,a+1+n))<=(YM=*std::min_element(b+1,b+1+m)))
        return printf("0"),void();
    {
        int nw=1;
        int tp=1;
        int SX=x.size(),SY=y.size();
        while(x[SX-1]!=XX&&x[SX-1]!=XM)SX--;
        while(y[SY-1]!=YX&&y[SY-1]!=YM)SY--;
        for(int i=0;i<SX;i++)
        {
            if(x[i]<=y[nw-1]){return printf("0"),void();}
            if(i&&x[i]>x[i-1])tp=1;
            if(i&&x[i]<x[i-1])tp=0;
            while(nw!=SY&&x[i]>y[nw])nw++;
            if(nw==SY&&i+1!=SX)
                if(nw>1&&y[nw-1]>y[nw-2])nw--;
            
        }
    }
    std::reverse(x.begin(),x.end());
    std::reverse(y.begin(),y.end());
    {
        int nw=1;
        int tp=1;
        int SX=x.size(),SY=y.size();
        while(x[SX-1]!=XX&&x[SX-1]!=XM)SX--;
        while(y[SY-1]!=YX&&y[SY-1]!=YM)SY--;
        for(int i=0;i<SX;i++)
        {
            if(x[i]<=y[nw-1]){return printf("0"),void();}
            if(i&&x[i]>x[i-1])tp=1;
            if(i&&x[i]<x[i-1])tp=0;
            while(nw!=SY&&x[i]>y[nw])nw++;
            if(nw==SY&&i+1!=SX)
                if(nw>1&&y[nw-1]>y[nw-2])nw--;
            
        }
    }
    printf("1");
    // int u=-1e18;
    // int nw=0;
    // for(int i=0;i<x.size();i++)
    // {
    //     int tp=0;
    //     if(i==0||x[i]>x[i-1])tp=1;
    //     //tp = 1: max
    // }
}
signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    id=read(),n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)a[i]=c[i]=read();
    for(int i=1;i<=m;i++)b[i]=d[i]=read();
    query();
    for(int s=1;s<=q;s++)
    {
        int A=read(),B=read();
        // printf("\n%d %d\n",A,B);
        for(int i=1;i<=n;i++)a[i]=c[i];
        for(int i=1;i<=m;i++)b[i]=d[i];
        for(int i=1;i<=A;i++)
        {
            int x=read(),y=read();
            a[x]=y;
        }
        for(int i=1;i<=B;i++)
        {
            int x=read(),y=read();
            b[x]=y;
        }
        if(s==39)
        {
            // puts("");
            // for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
            // for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
        }
        // printf("case %d\n",s);
        query();
    }
    puts("");
}