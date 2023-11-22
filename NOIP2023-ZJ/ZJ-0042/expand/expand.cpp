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
bool f[2005][2005];
bool calc(int a[N],int n,int b[N],int m) // ai>bi
{
    if(a[1]<=b[1]||a[n]<=b[m]) return 0;
    
    f[1][1]=1;
    rep(i,1,n)
        rep(j,1,m) if(a[i]>b[j])
        {
            f[i][j]=(i==1&&j==1);
            if(i>1&&a[i-1]>b[j]) f[i][j]|=f[i-1][j];
            if(j>1&&a[i]>b[j-1]) f[i][j]|=f[i][j-1];
        }
    return f[n][m];
}
int ANS[N];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
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
        // if(!ans) printf("bad T=%d\n",T);
    }
    rep(i,0,q) printf("%d",ANS[i]);
    return 0;
}