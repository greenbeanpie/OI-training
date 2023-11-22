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

const int N=1e5+5;

struct node
{
    int flag;// F 0 T 1 U 2
    int p,v;
    int ini,f2;
}a[N];

vector<pair<int,int> > e[N];
int sz,flag;
int vis[N];

void dfs(int u,int val)
{
    if(vis[u]!=-1)
    {
        if(vis[u]!=val) flag=0;
        return;
    }
    vis[u]=val;
    sz++;
    for(auto res:e[u])
    {
        int v=res.first;
        int c=res.second;
        dfs(v,val^c);
    }
}

void dfs2(int u)
{
    if(vis[u]!=-1) return;
    vis[u]=2;
    sz++;
    for(auto res:e[u])
    {
        int v=res.first;
        int c=res.second;
        dfs2(v);
    }
}
char s[10];

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int task=read(),T=read();
    while(T--)
    {
        int n=read(),m=read();
        for(int i=1;i<=n;i++) a[i].flag=-1,a[i].p=i,a[i].v=0,a[i].ini=1,a[i].f2=1,e[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%s",s+1);
            if(s[1]=='+')
            {
                int x=read(),y=read();
                if(a[y].flag==-1)
                {
                    a[x].flag=-1;
                    a[x].p=a[y].p;
                    a[x].v=a[y].v;
                    a[x].ini=0;
                    a[x].f2=(a[a[x].p].ini);
                    if(a[x].p==x)
                    {
                        a[x].ini=1;
                        a[x].f2=0;
                    }
                }
                else
                {
                    a[x].flag=a[y].flag;
                }
            }
            if(s[1]=='-')
            {
                int x=read(),y=read();
                if(a[y].flag==-1)
                {
                    a[x].flag=-1;
                    a[x].p=a[y].p;
                    a[x].v=a[y].v^1;
                    a[x].ini=0;
                    a[x].f2=(a[a[x].p].ini);
                    if(a[x].p==x)
                    {
                        a[x].ini=1;
                        a[x].f2=0;
                    }
                }
                else
                {
                    if(a[y].flag!=2) a[x].flag=a[y].flag^1;
                    else a[x].flag=a[y].flag;
                }
            }
            if(s[1]=='F')
            {
                int x=read();
                a[x].flag=0;
            }
            if(s[1]=='T')
            {
                int x=read();
                a[x].flag=1;
            }
            if(s[1]=='U')
            {
                int x=read();
                a[x].flag=2;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) vis[i]=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i].flag!=-1) continue;
            int p=a[i].p;
            if(a[i].f2==0) continue;
            e[i].push_back(make_pair(p,a[i].v));
            e[p].push_back(make_pair(i,a[i].v));
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]!=-1) continue;
            if(a[i].flag==-1) continue;
            sz=0,flag=1;
            if(a[i].flag==2)
            {
                dfs2(i);
                ans+=sz;
                //cout<<sz<<endl;
            }
            else
            {
                dfs(i,a[i].flag);
                if(!flag) ans+=sz;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].flag!=-1) continue;
            int p=a[i].p;
            if(a[i].f2!=0) continue;
            e[i].push_back(make_pair(p,a[i].v));
            e[p].push_back(make_pair(i,a[i].v));
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].flag!=-1) continue;
            if(vis[i]!=-1) continue;
            sz=0,flag=1;
            dfs(i,0);
            //cout<<i<<" "<<flag<<" "<<sz<<endl;
            if(!flag) ans+=sz;
        }
        printf("%d\n",ans);
    }
    return 0;
}
