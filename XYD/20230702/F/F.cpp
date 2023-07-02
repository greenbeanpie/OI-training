#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int from,to,val;
};
vector<node> e[2505];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("F.in","r",stdin);
    #endif
    int n,m;
    cin >> n >> m;
    int u,v,val;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        e[u].push_back({u,v,val});
    }
    for(int i=1;i<=n;i++){
        e[0].push_back({0,i,0});
    }
    queue<int> q;
    q.push(0);
    int cnt[n+1],dis[n+1];
    memset(cnt,0,sizeof(cnt));
    memset(dis,0x3f3f3f,sizeof(dis));
    dis[0]=0;
    while(q.size()){
        auto now=q.front();
        q.pop();
        for(auto i:e[now]){
            if(dis[i.to]>dis[i.from]+i.val){
                
            }
        }
    }
    return 0;
}