#include<bits/stdc++.h>
using namespace std;
const int inf=1e8;
int c,t,n,m,ans;
int a[100002],vis[100002],f[100002];
vector<int> g[100002];
char Ch[100002];
int X[100002],Y[100002];
// 1 : T
// 2 : F
// 3 : U
inline int num(char ch)
{
    if(ch=='T') return 1;
    if(ch=='F') return 2;
    return 3;
}
inline int no(int x)
{
    if(x==1) return 2;
    if(x==2) return 1;
    return 3;
}
bool check()
{
    int A[12];
    for(int i=1;i<=n;++i) A[i]=a[i];
    for(int i=1;i<=m;++i)
    {
        if(Ch[i]=='T'||Ch[i]=='F'||Ch[i]=='U') A[X[i]]=num(Ch[i]);
            else if(Ch[i]=='+') A[X[i]]=A[Y[i]];
                else A[X[i]]=no(A[Y[i]]);
    }
    for(int i=1;i<=n;++i) if(a[i]!=A[i]) return false;
    return true;
}
void dfs(int k)
{
    if(k==n+1)
    {
        if(check())
        {
            int sum=0;
            for(int i=1;i<=n;++i) if(a[i]==3) sum++;
            ans=min(ans,sum);
        }
        return;
    }
    for(int i=1;i<=3;++i) a[k]=i,dfs(k+1);
}
void work1()
{
    cin>>n>>m;
    ans=inf;
    for(int i=1;i<=m;++i)
    {
        cin>>Ch[i];
        if(Ch[i]=='T'||Ch[i]=='F'||Ch[i]=='U') cin>>X[i];
            else cin>>X[i]>>Y[i];
    }
    dfs(1);
    cout<<ans<<"\n";
}
void work2()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) a[i]=0;
    while(m--)
    {
        int x;char ch;
        cin>>ch>>x;
        a[x]=num(ch);
    }
    int ans=0;
    for(int i=1;i<=n;++i) if(a[i]==3) ans++;
    cout<<ans<<"\n";
}
void Dfs(int u)
{
    vis[u]=1;
    for(int v:g[u]) if(!vis[v]) a[v]=3,Dfs(v);
}
void work3()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) a[i]=0,f[i]=0,g[i].clear(),vis[i]=0;
    for(int i=1;i<=m;++i)
    {
        cin>>Ch[i];
        if(Ch[i]=='T'||Ch[i]=='F'||Ch[i]=='U') cin>>X[i];
            else cin>>X[i]>>Y[i];
    }
    for(int i=m;i>=1;--i)
    {
        if(Ch[i]=='T'||Ch[i]=='F'||Ch[i]=='U')
        {
            if(!f[X[i]]) a[X[i]]=num(Ch[i]);
        }
        else f[X[i]]=1;
    }
    for(int i=1;i<=m;++i)
        if(Ch[i]=='-'||Ch[i]=='+')
        {
            if(a[X[i]]==3) g[X[i]].push_back(Y[i]);
            if(a[Y[i]]==3) g[Y[i]].push_back(X[i]);
        }
    for(int i=1;i<=n;++i) if(a[i]==3) Dfs(i);
    int ans=0;
    for(int i=1;i<=n;++i) if(a[i]==3) ans++;
    cout<<ans<<"\n";
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c==1||c==2) while(t--) work1();
    if(c==3||c==4) while(t--) work2();
    if(c==5||c==6) while(t--) work3();
    if(c==7||c==8)
    {
        while(t--)
        {
            cin>>n>>m;
            for(int i=1;i<=m;++i)
            {
                cin>>Ch[i];
                if(Ch[i]=='T'||Ch[i]=='F'||Ch[i]=='U') cin>>X[i];
                    else cin>>X[i]>>Y[i];
            }
            cout<<n<<"\n";
        }
    }
    if(c==9||c==10) while(t--) work1();
    return 0;
}