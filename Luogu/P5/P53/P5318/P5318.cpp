#include <bits/stdc++.h>
using namespace std;
#define int long long


struct edge{
    int u,v;
};
bool cmp(edge u,edge v){
    if(u.u>v.u){
        return false;
    }
    else if(u.v>v.v){
        return false;
    }
    return true;
}
vector<int> e[100005];
int vis[100005],n,m;
vector<edge> temp;
void read(int t){
    int uu,vv;
    for(int i=0;i<t;i++){
        cin >> uu >> vv;
        temp.push_back((edge){uu,vv});
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<t;i++){
        e[temp[i].u].push_back(i);
    }
}


void dfs(int x){
    vis[x]=true;
    cout << x << " ";
    for(int i=0;i<e[x].size();i++){
        int t=temp[e[x][i]].v;
        if(!vis[t]){
        
            dfs(t);
        }
    }
}
void bfs(int x){
    queue<int> q;
    q.push(x);
    cout << x << " ";
    vis[x]=true;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<e[t].size();i++){
            int tt=temp[e[t][i]].v;
            if(!vis[tt]){
                q.push(tt);
                cout << tt << " ";
                vis[tt]=true;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    read(m);

    dfs(1);
    memset(vis,0,sizeof(vis));
    cout << endl;
    bfs(1);
    return 0;
}