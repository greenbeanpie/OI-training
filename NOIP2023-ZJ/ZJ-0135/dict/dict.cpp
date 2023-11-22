#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)

const int MAXN = 3010;

int n, m;

int mx[MAXN];
int mn[MAXN];

signed main()
{

    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fore(i, 1, n)
    {
        mx[i] = -1, mn[i] = 26;
        char c;
        fore(j, 1, m)
        {
            cin >> c;
            mx[i] = max(mx[i], c - 'a');
            mn[i] = min(mn[i], c - 'a');
        }
    }

    fore(i, 1, n)
    {
        bool flag = true;
        fore(j, 1, n)
        {
            if (i == j)
                continue;
            if (mn[i] >= mx[j])
                flag = false;
        }
        cout << flag;
    }
    cout << endl;

    return 0;
}
