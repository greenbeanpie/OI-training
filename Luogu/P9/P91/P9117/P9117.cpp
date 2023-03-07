#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, m, q;
        cin >> n >> m >> q;
        int paint[n][m];
        memset(paint, 0, sizeof(paint));
        int opt, x, c;
        for (int i = 0; i < q; i++)
        {
            cin >> opt >> x >> c;
            x--;
            if (opt == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    paint[x][j] = c;
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    paint[j][x] = c;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << paint[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}