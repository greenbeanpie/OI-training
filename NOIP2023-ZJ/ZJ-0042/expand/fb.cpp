#include <bits/stdc++.h>
#define rep(i,l,r) for(auto i(l),i##_end(r);i<=i##_end;++i)
#define per(i,r,l) for(auto i(r),i##_end(l);i>=i##_end;--i)
#define fi first
#define se second

using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;
using vii=vector<pii>;

const int N=5e5+5;
int C,n,m,q;
int a[N],b[N],_a[N],_b[N];
int p1[N],p2[N];
int va[N*2],tot;
struct ST
{
    int f1[20][N],f2[20][N];
    void build(int a[N],int n)
    {
        rep(i,1,n) f1[0][i]=f2[0][i]=a[i];
        rep(i,1,__lg(n))
            rep(j,1,n-(1<<i)+1) 
            {
                f1[i][j]=min(f1[i-1][j],f1[i-1][j+(1<<i-1)]);
                f2[i][j]=max(f2[i-1][j],f2[i-1][j+(1<<i-1)]);
            }
    }
    int qmin(int l,int r)
    {
        int lg=__lg(r-l+1);
        return min(f1[lg][l],f1[lg][r-(1<<lg)+1]);
    }
    int qmax(int l,int r)
    {
        int lg=__lg(r-l+1);
        return max(f2[lg][l],f2[lg][r-(1<<lg)+1]);
    }
} A,B;
bool calc(int a[N],int n,int b[N],int m) // ai>bi
{
    puts("Calc:");
    tot=0;
    rep(i,1,n) va[++tot]=a[i];
    rep(i,1,m) va[++tot]=b[i];
    sort(va+1,va+tot+1);
    tot=unique(va+1,va+tot+1)-va-1;
    rep(i,1,n) a[i]=lower_bound(va+1,va+tot+1,a[i])-va;
    rep(i,1,m) b[i]=lower_bound(va+1,va+tot+1,b[i])-va;
    rep(i,1,n) printf("%d ",a[i]); puts("");
    rep(i,1,m) printf("%d ",b[i]); puts("");
    if(a[1]<=b[1]||a[n]<=b[m]) return 0;
    A.build(a,n);
    B.build(b,m);
    int i=1,j=1,r1=1,r2=1;
    p1[n+1]=n;
    p1[n]=n;
    per(i,n-1,1)
    {
        p1[i]=p1[i+1];
        if(a[i]>=a[p1[i]]) p1[i]=i;
    }
    p2[m+1]=m;
    p2[m]=m;
    per(i,m-1,1)
    {
        p2[i]=p2[i+1];
        if(b[i]<=b[p2[i]]) p2[i]=i;
    }
    while(1)
    {
        bool fl=0;
        while(r1<n&&a[r1+1]>b[j]) 
        {
            fl=1;
            r1++;
            if(a[r1]>=a[i]) i=r1;
        }
        while(r2<m&&b[r2+1]<a[i]) 
        {
            fl=1;
            r2++;
            if(b[r2]<=b[j]) j=r2;
        }
        if(!fl) break;
    }
    printf("A:%d r1:%d B:%d r2:%d\n",i,r1,j,r2);
    if(r1<n||r2<m) return 0;
    int ti=i,tj=j; bool fl=1;
    while(i<n||j<m)
    {
        printf("{%d %d}\n",i,j);
        if(j<m&&a[p1[i+1]]>B.qmax(j,p2[j+1])) i=p1[i+1],j=p2[j+1];
        else if(i<n&&b[p2[j+1]]<A.qmin(i,p1[i+1])) i=p1[i+1],j=p2[j+1];
        else return 0;
        // if(i<n)
        // {
        //     int mn=a[i];
        //     rep(k,i,p1[i+1]) mn=min(mn,a[k]);
        //     if(mn<=b[j]) ;
        //     else i=p1[i+1],stp=1;
        // }
        // if(j<m)
        // {
        //     int mx=b[j];
        //     rep(k,j,p2[j+1]) mx=max(mx,b[k]);
        //     if(mx>=a[i]);
        //     else j=p2[j+1],stp=1;
        // }
        // if(!stp) break;
    }
    printf("ij(%d %d)\n",i,j);
    return i==n&&j==m;
    // if(i==n&&j==m) return 1;
    // i=ti,j=tj;
    // while(i<n||j<m)
    // {
    //     printf("[%d %d]\n",i,j);
        
    //     int stp=0;
    //     if(j<m)
    //     {
    //         int mx=b[j];
    //         rep(k,j,p2[j+1]) mx=max(mx,b[k]);
    //         if(mx>=a[i]);
    //         else j=p2[j+1],stp=1;
    //     }
    //     if(i<n)
    //     {
    //         int mn=a[i];
    //         rep(k,i,p1[i+1]) mn=min(mn,a[k]);
    //         if(mn<=b[j]) ;
    //         else i=p1[i+1],stp=1;
    //     }
    //     if(!stp) break;
    // }
    // return i==n&&j==m;
}
int ANS[N];
int main()
{
    scanf("%d%d%d%d",&C,&n,&m,&q);
    rep(i,1,n) scanf("%d",&a[i]),_a[i]=a[i];
    rep(i,1,m) scanf("%d",&b[i]),_b[i]=b[i];

    
    int ans=0;
    if(a[1]>b[1]) ans=calc(a,n,b,m);
    else ans=calc(b,m,a,n);
    ANS[0]=ans;
    rep(T,1,q)
    {
        int k1,k2;
        scanf("%d%d",&k1,&k2);
        rep(i,1,n) a[i]=_a[i];
        rep(i,1,m) b[i]=_b[i];
        while(k1--)
        {
            int x,v;
            scanf("%d%d",&x,&v);
            a[x]=v;
        }
        while(k2--)
        {
            int x,v;
            scanf("%d%d",&x,&v);
            b[x]=v;
        }
        int ans=0;
        if(a[1]>b[1]) ans=calc(a,n,b,m);
        else ans=calc(b,m,a,n);
        ANS[T]=ans;
        if(!ans) printf("bad T=%d\n",T);
    }
    rep(i,0,q) printf("%d",ANS[i]);
}