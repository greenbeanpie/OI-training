#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define y1 y114514

using namespace std;

const int N = 1e4 + 10;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A_1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    if (a.size() > b.size())
    {
        int len = a.size() - b.size();
        reverse(b.begin(), b.end());
        for (int i = 1; i <= len; i++)
            b = b + "0";
        reverse(b.begin(), b.end());
    }
    else if (a.size() < b.size())
    {
        int len = b.size() - a.size();
        reverse(a.begin(), a.end());
        for (int i = 1; i <= len; i++)
            a = a + "0";
        reverse(a.begin(), a.end());
    }

    int len = a.size();

    if (c == "or")
    {
        bool flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == '1' || b[i] == '1')
            {
                cout << 1;
                flag = 1;
            }
            else if (!flag)
                continue;
            else
                cout << 0;
        }
    }
    else if (c == "and")
    {
        bool flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                cout << 1;
                flag = 1;
            }
            else if (!flag)
                continue;
            else
                cout << 0;
        }
    }
    else if (c == "xor")
    {
        bool flag = 0;
        for (int i = 0; i < len; i++)
        {
            if ((a[i] == '1' && b[i] == '1') || (a[i] == '0' && b[i] == '0'))
            {
                cout << 1;
                flag = 1;
            }
            else if (!flag)
                continue;
            else
                cout << 0;
        }
    }
    return 0;
}