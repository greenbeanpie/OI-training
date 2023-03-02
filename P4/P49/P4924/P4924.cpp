#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("P4924.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int number1[n + 1][n + 1];
    int c = 1;
    int number2[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            number1[i][j] = c;
            number2[i][j] = c;
            c++;
        }
    }
    int x, y, r, z;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> r >> z;

        if (z == 0)
        {
            for (int r = r; r >= 0; r--)
            {
                for (int i = x - r; i <= x + r; i++)
                {
                    for (int k = y - r; k <= y + r; k++)
                        number2[i][k] = number1[i][k];
                }
                int x1 = x + r, y1 = y - r;
                for (int i = x - r; i <= x + r; i++)
                {
                    for (int k = y - r; k <= y + r; k++)
                    {
                        number1[i][k] = number2[x1][y1];
                        x1--;
                    }
                    x1 = x + r, y1++;
                }
            }}
            else
            {
                for (int i = x - r; i <= x + r; i++)
                {
                    for (int k = y - r; k <= y + r; k++)
                        number2[i][k] = number1[i][k];
                }
                int x1 = x - r, y1 = y + r;
                for (int i = x - r; i <= x + r; i++)
                {
                    for (int k = y - r; k <= y + r; k++)
                    {
                        number1[i][k] = number2[x1][y1];
                        x1++;
                    }
                    y1--, x1 = x - r;
                }
            }
            for (int i = x - r; i <= x + r; i++)
            {
                for (int j = y - r; j <= y + r; j++)
                {
                    number1[i][j] = number2[i][j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << number1[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }