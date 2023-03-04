#include <bits/stdc++.h>
using namespace std;
// SB DFS waste my teenage,FUCK YOU!
/*int n;
double mininum = 1000000000;
ool pflag[15];
pair<double, double> point[15];
double t = 0;
double s = 0;
double temp;
double dfs(double x, double y)
{
    double temp1;
    if (t == n)
    {
        if (mininum > s)
        {
            mininum = s;
        }
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!pflag[i])
        {
            pflag[i] = true;
            t++;
            temp = sqrt(pow((point[i].first - x), 2) + pow((point[i].second - y),2));
            temp1 = s;
            s += temp;
            dfs(point[i].first, point[i].second);
            s = temp1;
            t--;
            pflag[i] = false;
        }
    }
    return mininum;
}

int main()
{
    //freopen("P1433.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> point[i].first >> point[i].second;
    }
    cout << fixed << setprecision(2) << dfs(0, 0);
    return 0;
}*/

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    //freopen("P1433.in","r",stdin);
    int n;
    cin >> n;
    if(n==0){
        cout << 0;
        return 0;
    }
    pair<double, double> point[n+1];
    point[0].first=0;
    point[0].second=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> point[i].first >> point[i].second;
    }
    double a[n + 1][1 << n];
    double dis[n + 1][n + 1];
    dis[0][0] = 0;
    memset(a, 127, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dis[i][j] = distance(point[i].first, point[i].second, point[j].first, point[j].second);
            dis[j][i] = dis[i][j];
        }
        dis[i][0] = distance(point[i].first, point[i].second, 0, 0);
        dis[0][i] = dis[i][0];
        a[i][1 << (i - 1)] = dis[0][i];
    }
    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((k & (1 << (i - 1))) == 0)
            {
                continue;
            }
            for(int j=1;j<=n;j++)
            {
                if (i == j)
                {
                    continue;
                }
                if ((k & (1 << (j - 1))) == 0)
                {
                    continue;
                }
                a[i][k] = min(a[i][k], a[j][k - (1 << (i - 1))] + dis[i][j]);
            }
        }
    }
    double mininum = DBL_MAX;
    for (int i = 0; i <= n; i++)
    {
        if (a[i][(1 << n)-1] < mininum)
        {
            mininum = a[i][(1 << n)-1];
        }
    }
    cout << fixed << setprecision(2) << mininum;
    return 0;
}