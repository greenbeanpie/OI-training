#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> road[50005];
bool vis[50005];
int max_road[50005] = {0};
int croom, droom, nroom;
queue<pair<int, int>> dis;
void bfs()
{
    dis.push((pair<int, int>){0,1});
    while (!dis.empty())
    {
        max_road[dis.front().second] = max_road[dis.front().first] + 1;
        
        for (int i = 0; i < (int)(road[dis.front().second].size()); i++)
        {
            int temp = road[dis.front().second][i];
            if (!max_road[temp] && !vis[temp])
            {
                vis[temp] = true;
                dis.push((pair<int, int>){dis.front().second, temp});
            }
        }

        dis.pop();
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        if (max_road[i] > droom)
        {
            droom = max_road[i];
            croom = i;
            nroom=1;
        }
        else if (max_road[i] == droom)
        {
            nroom++;
        }
    }
    cout << croom << " " << droom-1 << " " << nroom;
    return 0;
}