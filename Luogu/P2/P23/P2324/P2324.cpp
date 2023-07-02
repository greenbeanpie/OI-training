#include <bits/stdc++.h>
using namespace std;
#define int long long
int depth = 15;
int matrix[6][6], ans = 16;
int default_matrix[6][6]{
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1},
    {0, 0, 0, -1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}};
int step[9][2] = {
    {0, 0},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1}};
bool check(int x, int y)
{
    if (x <= 5 && x >= 1 && y <= 5 && y >= 1)
    {
        return true;
    }
    return false;
}
int evaluate()
{
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (matrix[i][j] != default_matrix[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
void A_star(int dep, int nx, int ny)
{
    if (dep == depth)
    {
        if (!evaluate())
        {
            ans = min(ans, dep);
        }
        return;
    }
    if (ans <= 15)
    {
        return;
    }

    for (int f = 1; f <= 8; f++)
    {
        int tx = nx + step[f][0], ty = ny + step[f][1];
        if (!check(tx, ty))
        {
            continue;
        }
        swap(matrix[nx][ny], matrix[tx][ty]);
        if (evaluate() + dep <= depth)
        {
            A_star(dep + 1, tx, ty);
        }
        swap(matrix[nx][ny], matrix[tx][ty]);
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("P2324.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    int sx, sy;
    for (int T = 0; T < t; T++)
    {
        char c;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                cin >> c;

                if (c == '1')
                {
                    matrix[i][j] = 1;
                }
                else if (c == '0')
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = -1;
                    sx = i, sy = j;
                }
            }
        }
        for (depth = 0; depth <= 15 && ans > 15; depth++)
        {
            A_star(0, sx, sy);
        }

        if (ans > 15)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
        ans = 16;
    }
    return 0;
}