#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
bool use[N];

struct Q{
    char opt;
    int i,j;
}q[N];
inline int g(int x){
    if(x==1)return 2;
    if(x==2)return 1;
    if(x==3)return 3;
    return 3;
}
inline void solve(){
    cin>>n>>m;
    int ans=INT_MAX;
    for(int t=1;t<=3;t++)
    {
        for(int i=1;i<=n;i++)a[i]=t;
        for(int i=1;i<=m;i++)
        {
            cin>>q[i].opt;
            if(q[i].opt=='+')
                cin>>q[i].i>>q[i].j,a[q[i].i]=a[q[i].j];
            else if(q[i].opt=='-')cin>>q[i].i>>q[i].j,a[q[i].i]=g(a[q[i].j]);
            else if(q[i].opt=='T')cin>>q[i].i,a[q[i].i]=1;
            else if(q[i].opt=='F')cin>>q[i].i,a[q[i].i]=2;
            else if(q[i].opt=='U')cin>>q[i].i,a[q[i].i]=3;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
            if(a[i]==3)sum++;
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
    
}

inline void clear(){
    memset(use,0,sizeof(use));
}
int ans_bf,b[N];
inline void calc(){
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=m;i++)
    {
        if(q[i].opt=='+')b[q[i].i]=b[q[i].j];
        else if(q[i].opt=='-')b[q[i].i]=g(b[q[i].j]);
        else if(q[i].opt=='T')b[q[i].i]=1;
        else if(q[i].opt=='F')b[q[i].i]=2;
        else if(q[i].opt=='U')b[q[i].i]=3;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])return;
        else if(a[i]==3)sum++;
    ans_bf=min(ans_bf,sum);
}
inline void dfs(int dep){
    if(dep==n+1)return calc(),void();
    a[dep]=1,dfs(dep+1);
    a[dep]=2,dfs(dep+1);
    a[dep]=3,dfs(dep+1);
}
inline void solve_bf(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].opt;
        if(q[i].opt=='+'||q[i].opt=='-')
            cin>>q[i].i>>q[i].j;
        else cin>>q[i].i;
    }
    ans_bf=INT_MAX;
    dfs(1);
    cout<<ans_bf<<'\n';
}

inline void solve_TFU(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        char opt;int p;
        cin>>opt>>p;
        if(opt=='T')a[p]=1;
        if(opt=='F')a[p]=2;
        if(opt=='U')a[p]=3;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(a[i]==3)sum++;
    cout<<sum<<'\n';
}
vector<int>e[N];
int sz[N],in[N];bool vis[N];
inline void Dfs(int u,int x){
    if(vis[u])return;
    vis[u]=1;
    a[u]=x;
    for(int v:e[u])
        Dfs(v,x);
}
inline void solve_U(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=1;
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].opt;
        if(q[i].opt=='+')
            cin>>q[i].i>>q[i].j,a[q[i].i]=a[q[i].j];
        else cin>>q[i].i,a[q[i].i]=3;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(a[i]==3)sum++;
    cout<<sum<<'\n';
}

signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int C,T;cin>>C>>T;
    if(C<=2)while(T--)solve_bf();
    else if(C<=4)while(T--)solve_TFU();
    else if(C<=6)while(T--)solve_U(),clear();
    else while(T--)solve(),clear();
    return 0;
}