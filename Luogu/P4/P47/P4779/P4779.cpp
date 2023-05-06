#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #pragma GCC optimize(2)
#endif
using namespace std;
#define int long long
struct node{
    int v,w;
    bool operator()(node a,node b){
    if(a.w==b.w){
        return a.v<b.v;
    }
    return a.w>b.w;
}
};
int dis[100005];

bool vis[100005];
priority_queue<node,vector<node>,node > s;
vector<node> e[100005];
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P4779_1.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,start;
    cin >> n >> m >> start;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back(node{v,w});
    }
    for(int i=0;i<=100005;i++){
        dis[i]=INT_MAX;
    }
    dis[start]=0;
    s.push(node{start,0});
    while(!s.empty()){
        auto now=s.top();
        s.pop();
        if(now.w>dis[now.v]){
            continue;
        }
        vis[now.v]=1;
        dis[now.v]=now.w;
        if(e[now.v].empty()){
            continue;
        }
        for(auto i=e[now.v].begin();i!=e[now.v].end();i++){
            if(!vis[(*i).v]&&(*i).w+dis[now.v]<dis[(*i).v]){
                dis[(*i).v]=(*i).w+dis[now.v];
                s.push(node{(*i).v,dis[(*i).v]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dis[i] << " ";
    }
    return 0;
}