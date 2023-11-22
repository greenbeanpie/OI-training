#include<bits/stdc++.h>
using namespace std;
long long Id,T,a,b,q,w;
long long nw[300001],nx[300001],fl[300001],cnt,v[300001],ls[300001],g[300001],cn,st[1000001],fa[300001],an;
char s[101];
long long find(long long qq){return qq==fa[qq]?qq:fa[qq]=find(fa[qq]);}
void merge(long long qq,long long ww)
{
    long long f1=find(qq),f2=find(ww);
    if(f1==f2) return;
    if(f1<f2) swap(f1,f2);fa[f2]=f1;
}
void solve()
{
    scanf("%lld%lld",&a,&b);
    for(int i=1;i<=a;i++) nw[i]=i;cnt=a;
    for(int i=1;i<=b;i++)
    {
        scanf("%s",s+1);
        scanf("%lld",&q);
        if(s[1]=='T') nw[q]=++cnt,nx[nw[q]]=a+b+1;
        else if(s[1]=='F') nw[q]=++cnt,nx[nw[q]]=a+b+2;
        else if(s[1]=='U') nw[q]=++cnt,nx[nw[q]]=a+b+3;
        else
        {
            scanf("%lld",&w);
            long long lss=nw[w];nw[q]=++cnt;
            if(s[1]=='+') nx[nw[q]]=lss,fl[nw[q]]=0;
            else nx[nw[q]]=lss,fl[nw[q]]=1;
        }
    }cnt+=3;
    for(int i=1;i<=a*2+3;i++) fa[i]=i;
    for(int i=1;i<=cnt;i++) v[nx[i]]=1;
    for(int i=1;i<=cnt;i++) if(!nx[i]) ls[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        if(!v[i])
        {
            long long tt=i,hh=0;cn=0;
            while(!ls[tt])
            {
                st[++cn]=tt;
                hh^=fl[tt];
                tt=nx[tt];
            }
            for(int j=1;j<=cn;j++)
            {
                g[st[j]]=g[tt]^hh;
                ls[st[j]]=ls[tt];
                hh^=fl[st[j]];
            }
        }
    }an=0;
    for(int i=1;i<=a;i++)
    {
        long long t1=ls[nw[i]],t2=g[nw[i]];
//        cout<<i<<" "<<t1<<" "<<t2<<"\n";
        if(t1>a+b)
        {
            if(t1==a+b+3) merge(a+a+3,i),merge(a+a+3,i+a);
            else if(t1==a+b+2) merge(a+a+2,i),merge(a+a+1,i+a);
            else merge(a+a+1,i),merge(a+a+2,i+a);
        }
        else if(t2==0) merge(i,t1),merge(i+a,t1+a);
        else merge(i,t1+a),merge(i+a,t1);
    }
    for(int i=1;i<=a;i++)
    {
        if(find(i)==find(i+a)) ++an;
    }
    printf("%lld\n",an);
    for(int i=1;i<=a+b+5;i++) v[i]=nx[i]=nw[i]=fl[i]=ls[i]=g[i]=0;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&Id,&T);
    for(int ii=1;ii<=T;ii++) solve();
    return 0;
}