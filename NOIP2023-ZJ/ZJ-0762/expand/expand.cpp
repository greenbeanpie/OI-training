// #include<bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long
void file()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
}
const int N = 5e5 + 10;
int c, n, m, q;
int op[N], po[N], tmpx[N], tmpy[N];
signed main()
{
    file();
    cin >> c >> n >> m >> q;
    if (c == 1)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0;
        }
        int tmpa = a, tmpb = b;
        for (int i = 1; i <= q; i++)
        {
            int o, p;
            cin >> o >> p;
            for (int j = 1; j <= o; j++)
            {
                int l, k;
                cin >> l >> k;
                tmpa = k;
            }
            for (int j = 1; j <= p; j++)
            {
                int l, k;
                cin >> l >> k;
                tmpb = k;
            }
            if (tmpb == tmpa)
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
    }
    else if (c == 2)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a - b == 0 || c - d == 0)
        {
            cout << 0;
        }
        else if ((a > b && c > d) || (a < b && c < d))
        {
            cout << 1;
        }
        int tmpa = a, tmpb = b, tmpc = c, tmpd = d;
        while (q--)
        {
            for (int i = 1; i <= n; i++)
            {
                int op, x;
                cin >> op >> x;
                if (op == 1)
                {
                    tmpa = x;
                }
                else
                {
                    tmpb = x;
                }
            }
            for (int i = 1; i <= m; i++)
            {
                int op, x;
                cin >> op >> x;
                if (op == 1)
                {
                    tmpc = x;
                }
                else
                {
                    tmpd = x;
                }
            }
            if (tmpa - tmpb == 0 || tmpc - tmpd == 0)
            {
                cout << 0;
            }
            else if ((tmpa > tmpb && tmpc > tmpd) || (tmpa < tmpb && tmpc < tmpd))
            {
                cout << 1;
            }
            tmpa = a, tmpb = b, tmpc = c, tmpd = d;
        }
    }
    else
    {
        for (int i = 1; i <= q + 1; i++)
        {
            cout << 1;
        }
    }
}