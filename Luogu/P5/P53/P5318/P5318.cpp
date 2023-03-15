#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v;
};
vector<edge> s;
vector<int> e[100010];
long long tempu, tempv, n, m;
bool vis1[100010] = {false};
bool cmp(edge a, edge b)
{
    if (a.u != b.u)
        return a.u < b.u;
    else
        return a.v < b.v;
}
void read()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tempu >> tempv;
        s.push_back((edge){tempu, tempv});
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        e[s[i].u].push_back(i);
    }
}
void dfs(int x)
{
    vis1[x] = true;
    cout << x << " ";
    for (int i = 0; i < e[x].size(); i++)
    {
        int t = s[e[x][i]].v;
        if (!vis1[t])
        {
            dfs(t);
        }
    }
}
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    cout << x << " ";
    vis1[x] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 0; i < e[t].size(); i++)
        {
            int tt = s[e[t][i]].v;
            if (!vis1[tt])
            {
                vis1[tt] = true;
                q.push(tt);
                cout << tt << " ";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    read();
    dfs(1);
    memset(vis1, false, sizeof(vis1));
    cout << endl;
    bfs(1);
    return 0;
}