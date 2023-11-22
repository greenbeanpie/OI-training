#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
struct node{
    char opt;
    int x,y;
}a[N];
int c,test,n,m,b[N],blg[N],dcc,ans;
bool vis[N],ok[N];
char clo[N],now[N],tmp[N];
vector<pii> e[N];
vector<int> G[N];
char calc(char x)
{
    if(x=='U') return 'U';
    else return (x=='T'?'F':'T');
}
void pre(int u)
{
    for(pii i:e[u])
    {
        int v=i.first;
        if(!blg[v])
        {
            blg[v]=dcc;
            G[dcc].push_back(v);
            pre(v);
        }
    }
}
bool dfs(int u)
{
    for(pii i:e[u])
    {
        int v=i.first,type=i.second;
        if(clo[v]!='a')
        {
            if(clo[v]!=clo[u]&&type==0) return false;
            if(clo[v]!=calc(clo[u])&&type==1) return false;
        }
        else
        {
            if(!type) clo[v]=clo[u];
            else clo[v]=calc(clo[u]);
        }
        if(!vis[v])
        {
            vis[v]=1;
            if(!dfs(v)) return false;
        }
    }
    return true;
}
void dfs1(int u)
{
    if(u==n+1)
    {
        int cnt=0;
        for(int i=1;i<=n;i++) tmp[i]=now[i],cnt+=(tmp[i]=='U');
        for(int i=1;i<=m;i++)
        {
            if(a[i].opt=='-') tmp[a[i].x]=calc(tmp[a[i].y]);
            else if(a[i].opt=='+') tmp[a[i].x]=tmp[a[i].y];
            else tmp[a[i].x]=a[i].opt;
        }
        for(int i=1;i<=n;i++)
            if(tmp[i]!=now[i])
                return;
        ans=min(ans,cnt);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(i==1) now[u]='T';
        else if(i==2) now[u]='F';
        else now[u]='U';
        dfs1(u+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>test;
    while(test--)
    {
        cin>>n>>m;
        dcc=ans=0;
        for(int i=1;i<=n;i++)
        {
            clo[i]='a';
            e[i].clear();
            G[i].clear();
            blg[i]=vis[i]=ok[i]=b[i]=0;
        }
        for(int i=1;i<=m;i++) 
        {
            cin>>a[i].opt;
            if(a[i].opt!='-'&&a[i].opt!='+') 
            {
                cin>>a[i].x;
            }
            else 
            {
                cin>>a[i].x>>a[i].y;
            }
        }
        if(c>=1&&c<=2)
        {
            ans=n;
            dfs1(1);
            cout<<ans<<'\n';
        }
        if(c>=3&&c<=4)
        {
            for(int i=1;i<=m;i++)
            {
                if(a[i].opt!='-'&&a[i].opt!='+') clo[a[i].x]=a[i].opt;
            }
            for(int i=1;i<=ans;i++)
                ans+=(clo[i]=='U');
            cout<<ans<<'\n';
        }
        if(c>=5&&c<=6)
        {
            for(int i=1;i<=m;i++)
            {
                if(a[i].opt=='+')
                {
                    clo[a[i].x]=clo[a[i].y];
                }
                else
                    clo[a[i].x]='U';
            }
            for(int i=1;i<=m;i++)
                if(clo[a[i].x]=='a')
                    b[a[i].x]=i;
            for(int i=1;i<=n;i++)
            {
                if(b[i])
                {
                    if(a[b[i]].opt=='+') e[i].push_back({a[b[i]].y,0}),e[a[b[i]].y].push_back({i,0});
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!blg[i])
                {
                    dcc++;
                    blg[i]=dcc;
                    G[dcc].push_back(i);
                    pre(i);
                    for(int j:G[dcc])
                        if(clo[j]=='U')
                        {
                            ok[dcc]=1;
                            ans+=G[dcc].size();
                            break;
                        }
                }
            }
            for(int i=1;i<=dcc;i++)
            {
                if(ok[i]) continue;
                int u=G[i][0];
                clo[u]='T';
                vis[u]=1;
                if(!dfs(u))
                {
                    ans+=G[i].size();
                }
            }
            cout<<ans<<'\n';
        }
        if(c>=7&&c<=8)
        {
            for(int i=1;i<=m;i++)
                b[a[i].x]=i;
            for(int i=1;i<=n;i++)
            {
                if(b[i])
                {
                    if(a[b[i]].opt=='+') e[i].push_back({a[b[i]].y,0}),e[a[b[i]].y].push_back({i,0});
                    if(a[b[i]].opt=='-') e[i].push_back({a[b[i]].y,1}),e[a[b[i]].y].push_back({i,1});
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!blg[i])
                {
                    dcc++;
                    blg[i]=dcc;
                    G[dcc].push_back(i);
                    pre(i);
                }
            }
            for(int i=1;i<=dcc;i++)
            {
                int u=G[i][0];
                clo[u]='T',vis[u]=1;
                if(!dfs(u))
                {
                    ans+=G[i].size();
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}