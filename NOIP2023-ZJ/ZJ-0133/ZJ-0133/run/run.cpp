#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read()
{
    int x=0,f=1;char s=getchar();
    while(s<'0'||s>'9')
    {
        if(s=='-') f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9')
    {
        x=x*10+s-'0';
        s=getchar();
    }
    return x*f;
}

const int N=2005;
ll f[N];
struct node
{
    int l,r,v;
}a[100005];

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c=read(),T=read();
    while(T--)
    {
        int n=read(),m=read(),k=read(),d=read();
        for(int i=1;i<=m;i++)
        {
            int x=read(),y=read(),v=read();
            a[i].l=y-x+1;
            a[i].r=x;
            a[i].v=v;
        }
        for(int i=0;i<=n;i++) f[i]=0;
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1];
            for(int j=i;j>=1;j--)
            {
                if(i-j+1>k) break;
                ll tmp=0;
                for(int x=1;x<=m;x++)
                    if(a[x].l>=j&&a[x].r<=i) tmp+=a[x].v;
                f[i]=max(f[i],(j==1?tmp:f[j-2]+tmp)-1ll*d*(i-j+1));
            }
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
