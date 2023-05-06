#include <bits/stdc++.h>
using namespace std;
#define int long long
int mx[] = {1, 0, 0, -1};
int my[] = {0, 1, -1, 0};
int n, m;
bool map1[1005][1005];
int vis[1005][1005];
int val[1000005];
int t114514=0;
int bfs(int x, int y)
{

    if (val[vis[x][y]] != 0)
    {
        return val[vis[x][y]];
    }
    queue<int> qx, qy;
    int cnt = 0;
    qx.push(x);
    qy.push(y);
    t114514++;
    vis[x][y]=t114514;
    while (!qx.empty())
    {
        cnt++;
        int cx = qx.front();
        int cy = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 4; i++)
        {
            if (cx + mx[i] < 0 || cy + my[i] < 0 || cx + mx[i] >= n ||
                cy + my[i] >= n)
            {
                continue;
            }
            if (vis[cx + mx[i]][cy + my[i]] == 0 &&
                map1[cx + mx[i]][cy + my[i]] != map1[cx][cy])
            {
                qx.push(cx + mx[i]);
                qy.push(cy + my[i]);
                vis[cx + mx[i]][cy + my[i]] = t114514;
            }
        }
    }
    val[t114514] = cnt;
    return cnt;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P1141_1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    char t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            if (t == '0')
            {
                map1[i][j] = false;
            }
            else
            {
                map1[i][j] = true;
            }
        }
    }
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        cout << bfs(x - 1, y - 1) << "\n";
    }
    return 0;
}