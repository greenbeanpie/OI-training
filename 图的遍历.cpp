#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge{
    int to,nxt;
}e[100005];
int n,m,idx,h[100005],a[100005];
void addedge(int u,int v){
    e[idx].to=v;
    e[idx].nxt=h[u];
    h[u]=idx++;
}
void read(){
    int a,b;
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        cin >> a >> b;
        addedge(b,a);
    }
}
void dfs(int u,int v){
    if(!a[v]){
        a[v]=u;
        for(int p=h[v];p!=-1;p=e[p].nxt){
            int tt=e[p].to;
            dfs(u,tt);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    read();
    for(int i=n;i>=1;i--){
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    return 0;
}