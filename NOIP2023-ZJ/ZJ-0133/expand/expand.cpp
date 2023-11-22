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

const int N=5e5+5;

struct node
{
    int l,r;
    int mx,mn;
}t[N<<2];
int a[N],b[N],f[N];
int n,m,q;

inline void pushup(int x)
{
    t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx);
    t[x].mn=min(t[x<<1].mn,t[x<<1|1].mn);
}

void build(int x,int l,int r)
{
    t[x].l=l,t[x].r=r;
    if(t[x].l==t[x].r)
    {
        t[x].mx=t[x].mn=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void updata(int x,int id,int v)
{
    if(t[x].l>id||t[x].r<id) return;
    if(t[x].l==t[x].r)
    {
        t[x].mx=t[x].mn=v;
        return;
    }
    updata(x<<1,id,v);
    updata(x<<1|1,id,v);
    pushup(x);
}

int asklmx(int x,int l,int r,int v)
{

    if(t[x].mx<v) return l-1;
    if(t[x].l==t[x].r)
        return t[x].mx>v?l:t[x].l-1;
    int mid=(t[x].l+t[x].r)>>1;
    if(r>mid)
    {
        int res=asklmx(x<<1|1,mid+1,r,v);
        if(res==mid) return asklmx(x<<1,l,mid,v);
        else return res;
    }
    else
        return asklmx(x<<1,l,r,v);
}

int asklmn(int x,int l,int r,int v)
{
    //cout<<l<<" "<<r<<" "<<t[x].l<<" "<<t[x].r<<" "<<v<<endl;
    if(t[x].mn>v) return l-1;
    if(t[x].l==t[x].r)
        return t[x].mn<v?l:t[x].l-1;
    int mid=(t[x].l+t[x].r)>>1;
    if(r>mid)
    {
        int res=asklmn(x<<1|1,mid+1,r,v);
        if(res==mid) return asklmn(x<<1,l,mid,v);
        else return res;
    }
    else
        return asklmn(x<<1,l,r,v);
}

int askrmx(int x,int l,int r,int v)
{
    if(t[x].mx<v) return r+1;
    if(t[x].l==t[x].r)
        return t[x].mx>=v?r:t[x].r+1;
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
    {
        int res=askrmx(x<<1,l,mid,v);
        if(res==mid+1) return askrmx(x<<1|1,mid+1,r,v);
        else return res;
    }
    else return askrmx(x<<1|1,l,r,v);
}

int askrmn(int x,int l,int r,int v)
{
    if(t[x].mn>v) return r+1;
    if(t[x].l==t[x].r)
        return t[x].mn<=v?r:t[x].r+1;
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
    {
        int res=askrmn(x<<1,l,mid,v);
        if(res==mid+1) return askrmn(x<<1|1,mid+1,r,v);
        else return res;
    }
    else return askrmn(x<<1|1,l,r,v);
}

int solve1()
{
    for(int i=1;i<=n;i++) f[i]=0;
    f[1]=askrmx(1,1,n,a[1])-1;
    for(int i=2;i<=n;i++)
    {
        int lst=f[i-1];
        //cout<<lst<<"##########"<<endl;
        if(lst==0) return 0;
        int res=(lst<m)?(askrmx(1,lst+1,m,a[i])-1):lst;
        if(res==lst&&a[i]<=b[lst])
        {
            if(lst>1) f[i]=asklmn(1,1,lst-1,a[i]);
            else return 0;
        }
        else f[i]=res;
    }
    return f[n]>=m;
}

int solve2()
{
    for(int i=1;i<=n;i++) f[i]=0;
    f[1]=askrmn(1,1,n,a[1])-1;
    for(int i=2;i<=n;i++)
    {
        int lst=f[i-1];
        if(lst==0) return 0;
        int res=(lst<m)?(askrmn(1,lst+1,m,a[i])-1):lst;
        if(res==lst&&a[i]>=b[lst])
        {
            if(lst>1) f[i]=asklmx(1,1,lst-1,a[i]);
            else return 0;
        }
        else f[i]=res;
    }
    return f[n]>=m;
}

void calc()
{
    if(a[1]==b[1]) putchar('0');
    else if(a[1]>b[1]) putchar(solve1()?'1':'0');
            else putchar(solve2()?'1':'0');

}

vector<pair<int,int> > v1,v2;
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int task=read();
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    build(1,1,m);
    calc();
    while(q--)
    {
        v1.clear(),v2.clear();
        int kn=read(),km=read();
        for(int i=1;i<=kn;i++)
        {
            int p=read(),v=read();
            v1.push_back(make_pair(p,a[p]));
            a[p]=v;
        }
        for(int i=1;i<=km;i++)
        {
            int p=read(),v=read();
            v2.push_back(make_pair(p,b[p]));
            b[p]=v;
            updata(1,p,v);
        }
        calc();
        for(auto res:v1)
        {
            int p=res.first,v=res.second;
            a[p]=v;
        }
        for(auto res:v2)
        {
            int p=res.first,v=res.second;
            b[p]=v;
            updata(1,p,v);
        }
    }
    return 0;
}
