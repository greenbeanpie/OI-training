#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define OPFI(x) freopen(#x".in", "r", stdin);\
                freopen(#x".out", "w", stdout)
#define REP(i, a, b) for(int i=(a); i<=(b); ++i)
#define REPd(i, a, b) for(int i=(a); i>=(b); --i)
inline ll rd(){
    ll r=0, k=1; char c=0; while(!isdigit(c=getchar())) if(c=='-') k=-k;
    while(isdigit(c)) r=r*10+c-'0', c=getchar(); return r*k;
}
const int N=1e5+10;
ll tid, T, n, m;
namespace subtask1{
    /**
     * bf case n,m<=10, tid<=2
     * O((m+n)*3^n)
    */
    int a[N], tmp[N], ans; // {-1, 0, 1} <--- {F, U, T}
    struct opt{
        char v;
        int i, j;
    }o[N];
    bool check(){
        REP(i, 1, n) tmp[i]=a[i];
        REP(i, 1, m){
            if(o[i].v=='+') tmp[o[i].i]=tmp[o[i].j];   
            else if(o[i].v=='-') tmp[o[i].i]=-tmp[o[i].j];
            else if(o[i].v=='T') tmp[o[i].i]=1;
            else if(o[i].v=='F') tmp[o[i].i]=-1;
            else tmp[o[i].i]=0;
        }
        REP(i, 1, n) if(a[i]!=tmp[i]) return false;
        return true;
    }
    void dfs(int k){
        if(k>n){
            if(check()){
                int cnt=0;
                REP(i, 1, n) cnt+=(a[i]==0);
                ans=min(ans, cnt);
            }
            return;
        }
        a[k]=1, dfs(k+1);
        a[k]=-1, dfs(k+1);
        a[k]=0, dfs(k+1);
    }
    void solve(){
        char tmpstr[20];
        while(T--){
            n=rd(), m=rd();
            REP(i, 1, m){
                scanf("%s", tmpstr);
                o[i].v=tmpstr[0];
                if(o[i].v=='+'||o[i].v=='-')
                    o[i].i=rd(), o[i].j=rd();
                else o[i].i=rd();
            }
            ans=n+1;
            dfs(1);
            printf("%d\n", ans);
        }
    }
}
namespace subtask2{
    /**
     * bingchaji 
     * O(q(n+m))
    */
    int a[N]; // 1=(1) 2n+3=-(1) ... n=(n) n+4=-(n) n+1=F n+2=U n+3=T
    int f[2*N+10], ans, vis[2*N+10];
    vector<int> g[2*N+10];
    int find(int x){
        if(f[x]==x) return x;
        return f[x]=find(f[x]);
    }
    void bfs(){
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(n+2);
        vis[n+2]=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            if(u<=n) ++ans;
            for(vector<int>::iterator i=g[u].begin(); i!=g[u].end(); ++i){
                if(vis[*i]) continue;
                vis[*i]=1;
                q.push(*i);
            }
        }
    }
    void solve(){
        char tmpstr[20];
        while(T--){
            n=rd(), m=rd();
            REP(i, 1, n) a[i]=i;
            memset(f, 0, sizeof(f));
            REP(i, 1, 2*n+3) f[i]=i, g[i].clear();
            REP(i, 1, m){
                scanf("%s", tmpstr);
                char v=tmpstr[0]; int ti=rd(), tj=0;
                if(v=='+') tj=rd(), a[ti]=a[tj];
                else if(v=='-') tj=rd(), a[ti]=2*n+4-a[tj];
                else if(v=='T') a[ti]=n+3;
                else if(v=='F') a[ti]=n+1;
                else a[ti]=n+2;
            }
//            REP(i, 1, n) cerr<<a[i]<<" ";
//            cerr<<endl;
            REP(i, 1, n){
                int u=find(i), v=find(a[i]);
                f[u]=v;
                g[i].push_back(a[i]), g[a[i]].push_back(i);
            }
            REP(i, 1, n){
                int u=find(i), v=find(2*n+4-find(2*n+4-i));
                f[u]=v;
                u=find(2*n+4-i), v=find(2*n+4-find(i));
                f[u]=v;
                g[i].push_back(2*n+4-i), g[2*n+4-i].push_back(i);
            }
            REP(i, 1, n){
                int u=find(i), v=find(2*n+4-i);
                if(u==v&&u!=n+2) f[u]=n+2, 
                    g[i].push_back(n+2), g[n+2].push_back(i); 
            }
            ans=0;
            bfs();
//            cerr<<sz[n+1]<<" "<<sz[n+3]<<" "<<sz[n+2]<<endl;
            printf("%d\n", ans);
        }
    }
}
int main(){
    OPFI(tribool);
    tid=rd(), T=rd();
    if(tid<=2){
        subtask1::solve();
    }else{
        subtask2::solve();
    }
    return 0;
}