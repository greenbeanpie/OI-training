#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    int r, c, maxinum = -1;
    cin >> r >> c;
    int snowmap[r][c];
    int maxi = -1, maxj = -1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> snowmap[i][j];
            if (snowmap[i][j] > maxinum)
            {
                maxinum = snowmap[i][j];
                maxi = i, maxj = j;
            }
        }
    }
    int road[r][c];
    queue<int> x, y;
    x.push(maxi), y.push(maxj);
    road[maxi][maxj] = 1;
    int t = 0;
    while (!x.empty())
    {
        if (snowmap[x.back() - 1][y.back()] < snowmap[x.back()][y.back()])
        {
            road[x.back() - 1][y.back()] = max(road[x.back() - 1][y.back()], road[x.back()][y.back()] + 1);
            x.push(x.back() - 1);
            y.push(y.back());
        }
        if (snowmap[x.back() + 1][y.back()] < snowmap[x.back()][y.back()])
        {
            road[x.back() + 1][y.front()] = max(road[x.back() + 1][y.back()], road[x.back()][y.back()] + 1);
            x.push(x.back() + 1);
            y.push(y.back());
        }
        if (snowmap[x.back()][y.back() - 1] < snowmap[x.back()][y.back()])
        {
            road[x.back()][y.back() - 1] = max(road[x.back()][y.back() - 1], road[x.back()][y.back()] + 1);
            x.push(x.back());
            y.push(y.back() - 1);
        }
        if (snowmap[x.back()][y.back() + 1] < snowmap[x.back()][y.back()])
        {
            road[x.back()][y.back() + 1] = max(road[x.back()][y.back() + 1], road[x.back()][y.back()] + 1);
            x.push(x.back());
            y.push(y.back() + 1);
        }
        x.pop();
        y.pop();
        t++;
    }
    cout << t;
    return 0;
}