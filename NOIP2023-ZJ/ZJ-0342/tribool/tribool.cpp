#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+86;

template<typename T>
inline void read(T &x)
{
    T k=1;char ch=getchar();x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')k=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
    x*=k;
}

int beg[N],ed[N],n,m;//0 F 1 T 2 U
struct node{int op,x,y;}p[N];//0 F 1 T 2 U 3 + 4 -
int ops(int x){if(x==2) return x;return !x;}
bool check()
{
    for(int i=1;i<=n;i++) ed[i]=beg[i];
    for(int i=1;i<=m;i++)
    {
        if(p[i].op==0) ed[p[i].x]=0;
        else if(p[i].op==1) ed[p[i].x]=1;
        else if(p[i].op==2) ed[p[i].x]=2;
        else if(p[i].op==3) ed[p[i].x]=ed[p[i].y];
        else if(p[i].op==4) ed[p[i].x]=ops(ed[p[i].y]);
    }
    for(int i=1;i<=n;i++)
        if(ed[i]!=beg[i]) return false;
    return true;
}
void solve1()
{
    read(n),read(m);
    int ans=99;
    for(int i=1;i<=n+1;i++) beg[i]=0;
    for(int i=1;i<=m;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='F') p[i].op=0,read(p[i].x);
        else if(c=='T') p[i].op=1,read(p[i].x);
        else if(c=='U') p[i].op=2,read(p[i].x);
        else if(c=='+') p[i].op=3,read(p[i].x),read(p[i].y);
        else if(c=='-') p[i].op=4,read(p[i].x),read(p[i].y);
        // printf("%d %d %d\n",p[i].op,p[i].x,p[i].y);
    }
    while(!beg[n+1])
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=beg[i]==2;
            if(beg[i]==3) beg[i]=0,beg[i+1]++;
        }
        if(beg[n+1]) break;
        if(check()) ans=min(ans,cnt);
        beg[1]++;
    }
    printf("%d\n",ans);
}

void solve3()
{
    read(n),read(m);
    for(int i=1;i<=n+1;i++) ed[i]=0;
    for(int i=1;i<=m;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='F') p[i].op=0,read(p[i].x);
        else if(c=='T') p[i].op=1,read(p[i].x);
        else if(c=='U') p[i].op=2,read(p[i].x);
        else if(c=='+') p[i].op=3,read(p[i].x),read(p[i].y);
        else if(c=='-') p[i].op=4,read(p[i].x),read(p[i].y);
        // printf("%d %d %d\n",p[i].op,p[i].x,p[i].y);
    }
    for(int i=1;i<=m;i++)
    {
        if(p[i].op==0) ed[p[i].x]=0;
        else if(p[i].op==1) ed[p[i].x]=1;
        else if(p[i].op==2) ed[p[i].x]=2;
        else if(p[i].op==3) ed[p[i].x]=ed[p[i].y];
        else if(p[i].op==4) ed[p[i].x]=ops(ed[p[i].y]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=ed[i]==2;
    printf("%d\n",ans);
}
void solve5()
{
    read(n),read(m);
    for(int i=1;i<=n;i++) ed[i]=0;
    for(int i=1;i<=m;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='F') p[i].op=0,read(p[i].x);
        else if(c=='T') p[i].op=1,read(p[i].x);
        else if(c=='U') p[i].op=2,read(p[i].x);
        else if(c=='+') p[i].op=3,read(p[i].x),read(p[i].y);
        else if(c=='-') p[i].op=4,read(p[i].x),read(p[i].y);
        // printf("%d %d %d\n",p[i].op,p[i].x,p[i].y);
    }
    bool f=true;
    int cnt=0;
    while(f)
    {
        for(int i=1;i<=n;i++) beg[i]=ed[i];
        for(int i=1;i<=m;i++)
        {
            if(p[i].op==2) beg[p[i].x]=2;
            else if(p[i].op==3) beg[p[i].x]=beg[p[i].y];
        }
        int t=0;
        for(int i=1;i<=n;i++) t+=beg[i]==2;
        if(t==cnt) f=false;
        cnt=t;
        for(int i=1;i<=n;i++) ed[i]=beg[i];
    }
    printf("%d\n",cnt);
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;
    read(C),read(T);
    while(T--)
    {
        if(C==1||C==2) solve1();
        else if(C==3||C==4) solve3();
        else solve5();
    }
    return 0;
}