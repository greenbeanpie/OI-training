#include <bits/stdc++.h>
using namespace std;
pair<int, string> toy[100005];
int main()
{
    freopen("P1563.in", "r", stdin);
    int n, m, a, b, now = 0;
    cin >> n >> m;
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> toy[i].first >> toy[i].second;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if ((a == 0 && toy[now].first == 0) || (a == 1 && toy[now].first == 1))
        {
            now = (now - b + n) % n;
        }
        else
        {
            now = (now + b + n) % n;
        }
    }
    cout << toy[now].second;
    return 0;
}