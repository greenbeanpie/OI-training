#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int n;
    cin >> n;
    vector<int> e[n];
    for(int i=0;i<n;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<vector<int>,int> dis[n][n];
    for(int i=0;i<n;i++){
        for(auto j=e[i].begin();j!=e[i].end();j++){
            dis[i][j].second=1;
            dis[i][j].first.push_back(j);
            
        }
    }
}