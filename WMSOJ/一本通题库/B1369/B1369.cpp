#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x*f;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B1369.in", "r", stdin);
#endif
    priority_queue<int, vector<int>, greater<int>> s;
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
    {
        t=read();
        s.push(t);
    }
    int sum = 0;
    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        sum += a + b;
        s.push(a + b);
    }
    cout << sum;
    return 0;
}