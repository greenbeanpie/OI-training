#include <bits/stdc++.h>
using namespace std;
// #define int long long

struct node
{
    int x, y, dis;
};
bool operator<(node a, node b)
{
    return a.dis < b.dis;
}
int wk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    bool mp[n + 1][n + 1];
    char c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == '1')
            {
                mp[i][j] = 1;
            }
            else
            {
                mp[i][j] = 0;
            }
        }
    }
    vector<pair<int, int>> liantong[2500];
    bool vis[n + 1][n + 1];
    memset(vis,0,sizeof(vis));
    int tot = 0;
    int startlt, endlt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j]||mp[i][j])
            {
                continue;
            }
            queue<pair<int, int>> q;
            q.push({i, j});
            liantong[++tot].push_back({i, j});
            vis[i][j] = true;
            while (q.size())
            {
                auto now = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tx = now.first + wk[i][0];
                    int ty = now.second + wk[i][1];
                    if (tx > 0 && tx <= n && ty > 0 && ty <= n && !vis[tx][ty] && !mp[tx][ty])
                    {
                        q.push({tx, ty});
                        liantong[tot].push_back({tx, ty});
                        vis[tx][ty] = 1;
                    }
                }
                if (now.first == sx && now.second == sy)
                {
                    startlt = tot;
                }
                if (now.first == ex && now.second == ey)
                {
                    endlt = tot;
                }
            }
        }
    }
    int min_dis=INT_MAX;
    for (auto start : liantong[startlt])
    {
        if (min_dis == 1)
        {
            break;
        }
        for (auto end : liantong[endlt])
        {
            if (min_dis == 1)
            {
                break;
            }
            min_dis = min(min_dis, (int)pow(abs(start.first - end.first), 2) + (int)pow(abs(start.second - end.second), 2));
        }
    }
    cout << min_dis;
    return 0;
}