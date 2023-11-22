#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)

#define MAXN 100010

int n, m;

int T;

struct Node
{
    int opt, x, y;
} s[MAXN];

int a[MAXN];

void op(int i, int a[])
{
    int opt = s[i].opt;
    int x = s[i].x, y = s[i].y;
    if (opt == 1)
        a[x] = a[y];
    else if (opt == 2)
        a[x] = a[y] ^ 1;
    else if (opt == 3)
        a[x] = 0;
    else if (opt == 4)
        a[x] = 1;
    else
        a[x] = 2;
}

int tmp[MAXN];

bool check()
{
    memcpy(tmp, a, sizeof(tmp));
    fore(i, 1, m) op(i, tmp);
    fore(i, 1, n) if (tmp[i] <= 1 && tmp[i] != a[i] || tmp[i] >= 2 && a[i] < 2) return false;
    return true;
}

int ans = 0;

void dfs(int t, int cnt)
{
    if (t == n + 1)
    {
        if (check())
            ans = min(cnt, ans);
        return;
    }
    fore(i, 0, 2) a[t] = i, dfs(t + 1, (cnt + (i == 2)));
}

void in()
{
    cin >> n >> m;
    char opt;
    int x, y;
    fore(i, 1, m)
    {
        cin >> opt;
        if (opt == '+')
        {
            cin >> x >> y;
            s[i] = {1, x, y};
        }
        else if (opt == '-')
        {
            cin >> x >> y;
            s[i] = {2, x, y};
        }
        else if (opt == 'T')
        {
            cin >> x;
            s[i] = {3, x, 0};
        }
        else if (opt == 'F')
        {
            cin >> x;
            s[i] = {4, x, 0};
        }
        else if (opt == 'U')
        {
            cin >> x;
            s[i] = {5, x, 0};
        }
    }
}

void solve1()
{
    while (T--)
    {
        in();
        ans = n + 1;
        dfs(1, 0);
        cout << ans << endl;
    }
}

void solve2()
{
    while (T--)
    {
        ans = 0;
        in();
        fore(i, 1, m)
        {
            int opt = s[i].opt, x = s[i].x, y = s[i].y;
            a[x] = opt;
        }
        fore(i, 1, n) if (a[i] == 5) ans++;
        cout << ans << endl;
    }
}

void solve3()
{
    while (T--)
    {
        memset(a, 0, sizeof(a));
        ans = 0;
        in();
        fore(i, 1, m)
        {
            int opt = s[i].opt, x = s[i].x, y = s[i].y;
            if (opt == 5)
                a[x] = 2;
            if (opt == 1)
                a[x] = a[y];
        }
        fore(i, 1, n) if (a[i] == 2) ans++;
        cout << ans << endl;
    }
}

signed main()
{

    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int c;
    cin >> c >> T;
    if (c <= 2)
        solve1();
    if (c == 3 || c == 4)
        solve2();
    if (c == 5 || c == 6)
        solve3();

    return 0;
}
