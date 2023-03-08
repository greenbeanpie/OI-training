#include <bits/stdc++.h>
using namespace std;

double distance(pair<double, double> a, pair<double, double> b)
{
    return sqrtl(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    int n;
    cin >> n;
    pair<double, double> point[n];
    for (int i = 0; i < n; i++)
    {
        cin >> point[i].first >> point[i].second;
    }
    double dis[n][n];
    double answer[n][(1 << n)];
    memset(answer, 127, sizeof(answer));
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = distance(point[i], point[j]);
            dis[j][i] = dis[i][j];
        }
        answer[i][1 << i] = dis[i][0];
    }

    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((k & (1 << i)) == 0)
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if ((k & (1 << j)) == 0)
                {
                    continue;
                }
                if (i == j)
                {
                    continue;
                }
                answer[i][k] = min(answer[i][k], answer[j][k - (1 << i)] + dis[i][j]);
            }
        }
    }
    double mininum = DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        mininum = min(mininum, answer[i][(1 << n) - 1]);
    }
    cout << mininum;
    return 0;
}