#include <bits/stdc++.h>
using namespace std;
#define int long long

struct edge
{
    int to, w;
};
bool operator<(edge a,edge b){
    if(a.to==b.to){
        return a.w<b.w;
    }
    return a.to<b.to;
}
vector<edge> e[1505];
int maxroad[1505];
signed main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int u, v, m;
        cin >> u >> v >> m;
        e[u].push_back((edge){v, m});
    }
    queue<int> q;
    
    memset(maxroad, -1, sizeof(maxroad));
    q.push((long long)1);
    maxroad[1] = 0;
    while (!q.empty())
    {
        for (auto i = e[q.front()].begin(); i != e[q.front()].end(); i++)
        {
            maxroad[(*i).to] = max(maxroad[(*i).to], maxroad[q.front()] + (*i).w);
        }
        q.pop();
    }
    cout << maxroad[n];
    return 0;
}