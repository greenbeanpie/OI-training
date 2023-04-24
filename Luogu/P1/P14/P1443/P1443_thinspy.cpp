#include <bits/stdc++.h>
#define N 500
using namespace std;
int n, m, x, y;
int walk[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
struct node
{
    int x, y;
} s[N];
queue<node> q;
int a[500][500];
bool vis[500][500];
int main()
{
    cin >> n >> m >> x >> y;
    q.push((node){x, y});
    memset(a, -1, sizeof a);
    memset(vis, 0, sizeof vis);
    a[x][y] = 0;
    vis[x][y] = 1;
    while (!q.empty())
    {
        node tt = q.front();
        q.pop();
        for (int i = 0; i <= 7; i++)
        {
            int ux = tt.x + walk[i][0], uy = tt.y + walk[i][1];
            if (ux <= n && ux >= 1 && uy <= n && uy >= 1 && vis[x][y] != 0)
            {
                a[ux][uy] = a[x][y] + 1, vis[ux][uy] = 1;
                q.push(node{ux, uy});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}