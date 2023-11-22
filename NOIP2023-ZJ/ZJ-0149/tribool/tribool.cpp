#include <bits/stdc++.h>
#define _T_ 100001
#define _F_ 100002
#define _U_ 100003
using namespace std;
typedef pair<int,int> pi;
inline int gin() {
    int s=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        s=(s<<3)+(s<<1)+(c^48);
        c=getchar();
    }
    return s*f;
}

const int N=1e5+5;
int C,T;
int n,m,sz[N],vis[N],ooo[N],siv[N];
pi a[N];
vector<int> g[N],G[N];

void init() {
    for(int i=1;i<=n;i++)
        a[i]=pi(i,1),G[i].clear(),g[i].clear(),siv[i]=0,ooo[i]=0,vis[i]=0,sz[i]=1;
}

void dfs(int u) {
    sz[u]=1,vis[u]=1;
    for(int v:G[u]) {
        if(vis[v]) continue;
        dfs(v);
        sz[u]+=sz[v];
    }
}

int youhuan(int u,int fa) {
    siv[u]=1;
    for(int v:G[u]) {
        if(v==fa) continue;
        if(siv[v]) return v;
        int k=youhuan(v,u);
        if(k!=0) return k;
    }
    return 0;
}

bool chk(int u,int k) {
    ooo[u]=k;
    for(int v:g[u]) {
        if(ooo[v]==0) {
            if(chk(v,a[v].second*k)) return 1;
        }
        else {
            // if(T==2) {////////////////////
            //     printf("# %d/%d <- %d/%d\n",v,ooo[v],u,ooo[u]);
            // }
            if(a[v].second*ooo[v]!=k) return 1;
        }
    }
    return 0;
}

signed main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    C=gin(),T=gin();
    while(T--) {
        n=gin(),m=gin();
        init();//!!!!!!!!!!!!!!!!!!!!!!!
        for(int i=1;i<=m;i++) {
            char op[3];
            scanf("%s",op);
            if(op[0]=='+') {
                int x=gin(),y=gin();
                a[x]=a[y];
            }
            else if(op[0]=='-') {
                int x=gin(),y=gin();
                a[x]=a[y];
                a[x].second=-a[x].second;
            }
            else {
                int x=gin();
                if(op[0]=='T') a[x]=pi(_T_,1);
                else if(op[0]=='F') a[x]=pi(_F_,1);
                else if(op[0]=='U') a[x]=pi(_U_,1);
            }
        }
        // if(T==2) for(int i=1;i<=n;i++) {
        //     printf("%d %d %d\n",i,a[i].first,a[i].second);
        // }//////////////////////////////
        queue<int> q;
        for(int i=1;i<=n;i++) {
            if(a[i].first==i || a[i].first==_U_
            || a[i].first==_T_ || a[i].first==_F_) {
                q.push(i);
            }
            else {
                g[a[i].first].push_back(i);
                G[a[i].first].push_back(i);
                G[i].push_back(a[i].first);
            }
        }
        int ans=0;
        while(!q.empty()) {
            int x=q.front(); q.pop();
            if((x==a[x].first && a[x].second==-1)
            || a[x].first==_U_) {
                dfs(x);
                ans+=sz[x];
                // if(T==4) {/////////////////////
                //     printf("# %d %d\n",x,sz[x]);
                //     if(x==10) {
                //         printf("$ %d %d %d\n",sz[10],sz[9],sz[2]);
                //     }
                // }
            }
            else {
                dfs(x);
            }
        }
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                int x=youhuan(i,0);
                //printf("$ %d %d\n",i,x);
                if(!x) continue;
                if(chk(x,1)) {
                    // if(T==2) {///////////////
                    //     printf("## %d\n",x);
                    // }
                    dfs(x);
                    ans+=sz[x];
                }
                else {
                    dfs(x);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}