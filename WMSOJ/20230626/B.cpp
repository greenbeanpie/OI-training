#include <bits/stdc++.h>
#define int long long
int n, ans, eat[100005], eaten[100005];
std::set<std::pair<int, int>> s;

signed main()
{
#ifdef CODESPACE
    freopen("B.in", "r", stdin);
#endif
#ifndef CODESPACE
    freopen("lions.in", "r", stdin);
    freopen("lions.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    ans = n - 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        s.insert({x, i});
    }
    for (int i = 1; i < n; i++)
    {
        auto min = *s.begin(), max = *s.rbegin();
        s.erase(min), s.erase(max);
        eaten[i] = min.second, eat[max.second] = i;
        s.insert({max.first - min.first, max.second});
    }
    for (int i = n - 1; i; i = std::min(i - 1, ans))
    {
        if (eat[eaten[i]])
        {
            ans = eat[eaten[i]] - 1;
        }
    }
    std::cout << ans << std::endl;
    std::sort(eaten + 1, eaten + ans + 1);
    for (int i = 1; i <= ans; i++)
    {
        std::cout << eaten[i] << " ";
    }
    return 0;
}