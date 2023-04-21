#include <bits/stdc++.h>
using namespace std;
#define int long long
struct pair1
{
    int first, second;
};
int nmap[1005][1005], n, m;
bool vis[1005][1005];

bool check(int x, int y, bool pool)
{
    if (pool == 1)
    {
        if ((y == 0 || nmap[x][y] <= nmap[x][y - 1]) &&
            (y == m - 1 || nmap[x][y] <= nmap[x][y + 1]) &&
            (x == 0 || nmap[x][y] <= nmap[x - 1][y]) &&
            (x == n - 1 || nmap[x][y] <= nmap[x + 1][y]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (pool == 0)
    {
        if ((y == 0 || nmap[x][y] >= nmap[x][y - 1]) &&
            (y == m - 1 || nmap[x][y] >= nmap[x][y + 1]) &&
            (x == 0 || nmap[x][y] >= nmap[x - 1][y]) &&
            (x == n - 1 || nmap[x][y] >= nmap[x + 1][y]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
bool bfs(int x, int y, bool pool)
{
    queue<pair1> q;
    q.push(pair1{x, y});
    while (!q.empty())
    {
        if (!check(q.front().first, q.front().second, pool))
        {
            while (!q.empty())
            {
                if (q.front().second != m - 1 && !vis[q.front().first][q.front().second + 1] &&
                    nmap[q.front().first][q.front().second] ==
                        nmap[q.front().first][q.front().second + 1])
                {
                    vis[q.front().first][q.front().second + 1] = true;
                    q.push(pair1{q.front().first, q.front().second + 1});
                }
                if (q.front().second != 0 && !vis[q.front().first][q.front().second - 1] &&
                    nmap[q.front().first][q.front().second] ==
                        nmap[q.front().first][q.front().second - 1])
                {
                    vis[q.front().first][q.front().second - 1] = true;
                    q.push(pair1{q.front().first, q.front().second - 1});
                }
                if (q.front().first != n - 1 && !vis[q.front().first + 1][q.front().second] &&
                    nmap[q.front().first][q.front().second] ==
                        nmap[q.front().first + 1][q.front().second])
                {
                    vis[q.front().first + 1][q.front().second] = true;
                    q.push(pair1{q.front().first + 1, q.front().second});
                }
                if (q.front().first != 0 && !vis[q.front().first - 1][q.front().second] &&
                    nmap[q.front().first][q.front().second] ==
                        nmap[q.front().first - 1][q.front().second])
                {
                    vis[q.front().first - 1][q.front().second] = true;
                    q.push(pair1{q.front().first - 1, q.front().second});
                }
                q.pop();
            }
            return false;
        }
        if (!vis[q.front().first][q.front().second + 1] &&
            q.front().second != m - 1 &&
            nmap[q.front().first][q.front().second] ==
                nmap[q.front().first][q.front().second + 1])
        {
            vis[q.front().first][q.front().second + 1] = true;
            q.push(pair1{q.front().first, q.front().second + 1});
        }
        if (!vis[q.front().first][q.front().second - 1] && q.front().second != 0 &&
            nmap[q.front().first][q.front().second] ==
                nmap[q.front().first][q.front().second - 1])
        {
            vis[q.front().first][q.front().second - 1] = true;
            q.push(pair1{q.front().first, q.front().second - 1});
        }
        if (!vis[q.front().first + 1][q.front().second] &&
            q.front().first != n - 1 &&
            nmap[q.front().first][q.front().second] ==
                nmap[q.front().first + 1][q.front().second])
        {
            vis[q.front().first + 1][q.front().second] = true;
            q.push(pair1{q.front().first + 1, q.front().second});
        }
        if (!vis[q.front().first - 1][q.front().second] && q.front().first != 0 &&
            nmap[q.front().first][q.front().second] ==
                nmap[q.front().first - 1][q.front().second])
        {
            vis[q.front().first - 1][q.front().second] = true;
            q.push(pair1{q.front().first - 1, q.front().second});
        }
        q.pop();
    }
    return true;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int pool = 0, hill = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nmap[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = true;
                queue<pair1> q;
                bool flag;
                if (check(i, j, 1))
                {
                    flag = 1;
                }
                else if (check(i, j, 0))
                {
                    flag = 0;
                }
                else
                {
                    queue<pair1> q;
                    while (!q.empty())
                    {
                        if (q.front().second != m - 1 && !vis[q.front().first][q.front().second + 1] &&
                            nmap[q.front().first][q.front().second] ==
                                nmap[q.front().first][q.front().second + 1])
                        {
                            vis[q.front().first][q.front().second + 1] = true;
                            q.push(pair1{q.front().first, q.front().second + 1});
                        }
                        if (q.front().second != 0 && !vis[q.front().first][q.front().second - 1] &&
                            nmap[q.front().first][q.front().second] ==
                                nmap[q.front().first][q.front().second - 1])
                        {
                            vis[q.front().first][q.front().second - 1] = true;
                            q.push(pair1{q.front().first, q.front().second - 1});
                        }
                        if (q.front().first != n - 1 && !vis[q.front().first + 1][q.front().second] &&
                            nmap[q.front().first][q.front().second] ==
                                nmap[q.front().first + 1][q.front().second])
                        {
                            vis[q.front().first + 1][q.front().second] = true;
                            q.push(pair1{q.front().first + 1, q.front().second});
                        }
                        if (q.front().first != 0 && !vis[q.front().first - 1][q.front().second] &&
                            nmap[q.front().first][q.front().second] ==
                                nmap[q.front().first - 1][q.front().second])
                        {
                            vis[q.front().first - 1][q.front().second] = true;
                            q.push(pair1{q.front().first - 1, q.front().second});
                        }
                        q.pop();
                    }
                    continue;
                }
                if (bfs(i, j, flag))
                {
                    if (flag == 1)
                    {
                        pool++;
                    }
                    else
                    {
                        hill++;
                    }
                }
            }
        }
    }
    cout << pool << " " << hill;
    return 0;
}