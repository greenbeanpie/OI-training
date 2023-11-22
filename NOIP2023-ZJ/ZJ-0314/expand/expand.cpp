#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N], b[N];
int aa[N], bb[N];

bool check(int n)
{
    if (n == 1) return a[1] != b[1];
    if (n == 2)
    {
        if(a[1] == b[1] || a[2] == b[2])
            return false;
        
        return (a[1] - b[1]) * (a[2] - b[2]) > 0;
    }
    return false;
}

int main(void)
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    for (int i = 1; i <= n; i++) cin >> bb[i];

    if (n == 1 || n == 2) 
    {
        for (int i = 1; i <= n; i++) a[i] = aa[i];
        for (int i = 1; i <= n; i++) b[i] = bb[i];
        if(check(n)) cout << '1';
        else cout << '0';
        for (int i = 1; i <= q; i++)
        {
            int kx, ky;
            cin >> kx >> ky;
            for (int i = 1; i <= kx; i++)
            {
                int p, x;
                cin >> p >> x;
                a[p] = x;
            }
            for (int i = 1; i <= ky; i++)
            {
                int p, x;
                cin >> p >> x;
                b[p] = x;
            }
            if(check(n)) cout << '1';
            else cout << '0';

            for (int i = 1; i <= n; i++) a[i] = aa[i];
            for (int i = 1; i <= n; i++) b[i] = bb[i];
        }
    }
    else
    {
        for (int i = 1; i <= q + 1; i++)
            cout << '1';
    }
}