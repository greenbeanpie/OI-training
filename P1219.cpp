#include <bits/stdc++.h>
int n;
bool number[14][14];
int t = 0;
using namespace std;

bool check(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        if (number[x][i] && i != y)
        {
            return false;
        }
        if (number[i][y] && i != x)
        {
            return false;
        }
    }
    for (int i = max(x + y - n, 0); i <= n && x + y - i <= n; i++)
    {
        if (number[i][x + y - i] && i != x)
        {
            return false;
        }
    }
    for (int i = max(1, y - x); i <= n && y - x + i <= 0; i++)
    {
        if (number[i][y - x + i] && i != x)
        {
            return false;
        }
    }
    return true;
}

void dfs(int x)
{ // x表示横向行数
    if (x == n - 1)
    {
        if (t < 3)
        {
            for (int i = 0; i < n; i++)
            {
                int j = 0;
                while (!j)
                {
                    j++;
                }
                cout << j << " ";
            }
            cout << endl;
        }
        t++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (check(x, i))
            {
                number[x][i] = 1;
                dfs(x + 1);
                number[x][i] = 0;
            }
        }
    }
}

int main()
{
    freopen("P1219.in", "r", stdin);
    // freopen("P1219.out","w",stdout);
    cin >> n;
    bool number[n][n];
    dfs(1);
    cout << t;
    return 0;
}