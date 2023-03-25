#include <bits/stdc++.h>
using namespace std;
int n, h[305], pos[305], sum = 0, current = 0;
bool vis[305];
void dfs(int num)
{
    if (num == n)
    {
        sum += current;
    }
    int view = 0;
    for (int i = num - 1; i >= 0 && h[pos[i]] < h[pos[num]]; i--)
    {
        view++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            pos[num + 1] = h[i];
            current += view;
            dfs(num + 1);
            current -= view;
            pos[num + 1] = -1;
            vis[i]=false;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    memset(pos, -1, sizeof(pos));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    dfs(0);
    cout << fixed << setprecision(2) << 1.0 * (double)sum / (n * (n - 1)) << endl;
    return 0;
}