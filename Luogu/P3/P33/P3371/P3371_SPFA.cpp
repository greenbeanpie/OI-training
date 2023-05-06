#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int v,w;
};
int dis[10005];

vector<node> e[10005];
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P3371.in","r",stdin);
        #endif
    int n,m,s;
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back(node{v,w});
    }
    for(int i=0;i<10005;i++){
        dis[i]=INT_MAX;
    }
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int now=q.front();
        q.pop();
        for(auto i=e[now].begin();i!=e[now].end();i++){
            if(dis[(*i).v]>dis[now]+(*i).w){
                dis[(*i).v]=dis[now]+(*i).w;
                q.push((*i).v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << dis[i] << " ";
    }
    return 0;
}