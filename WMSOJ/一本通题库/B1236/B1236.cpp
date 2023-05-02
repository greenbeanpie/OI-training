#include <bits/stdc++.h>
#define y1 y114514

using namespace std;

const int N = 5e4 + 50;

struct node
{
    int l, r;
};

int n;
node a[N];

bool cmp(node a, node b)
{
    return a.l < b.l;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("problem10.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + n + 1, cmp);
    int now = a[1].r;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].l > now)
        {
            cout << "no" << endl;
            return 0;
        }
        else if (a[i].r > now)
        {
            now = a[i].r;
        }
    }
    cout << a[1].l << " " << now;
    return 0;
}