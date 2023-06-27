#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> line, near[100010];
set<int> num;
signed main()
{
#ifdef CODESPACE
    freopen("A.in", "r", stdin);
#endif
#ifndef CODESPACE
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    line.push_back(0);
    int t;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        line.push_back(t);
        num.insert(t);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (line[i - 1] != line[i])
        {
            ans += line[i] > line[i - 1] ? line[i] - line[i - 1] : line[i - 1] - line[i];
            near[line[i]].push_back(line[i - 1]);
            near[line[i - 1]].push_back(line[i]);
        }
    }
    int minans = ans;
    while (num.size())
    {
        int now = *num.begin();
        num.erase(num.begin());
        sort(near[now].begin(), near[now].end());
        int nowans = ans;
        for (int i : near[now])
        {
            nowans -= abs(now - i);
        }
        int temp = near[now][near[now].size() / 2];
        for (int i : near[now])
        {
            nowans += abs(temp - i);
        }
        minans = min(minans, nowans);
    }
    cout << minans;
    return 0;
}