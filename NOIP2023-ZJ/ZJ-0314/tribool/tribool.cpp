#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, oo = 0x3f3f3f3f;

int a[N];
int n, m;
int c, t;

long long qpow(long long a, long long x)
{
    long long res = 1LL;
    while(x) {
        if (x & 1LL) res *= a;
        a *= a;
        x >>= 1LL;
    }
    return res;
}

namespace force {
    char op[N];
    int x[N], y[N];
    void solve()
    {
        while (t--) 
        {
            cin >> n >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> op[i];
                if (op[i] == '+' || op[i] == '-')
                    cin >> x[i] >> y[i];
                else
                    cin >> x[i];
            }
            int rbound = qpow(3, n);
            int minucnt = n;
            for (int nn = 0; nn < rbound; nn++)
            {
                int ng = nn;
                int ucnt = 0;
                for (int i = 1; i <= n; i++)
                {
                    a[i] = ng % 3 - 1; // 0 1 2 -> -1 0 1
                    if (a[i] == 0) ucnt++;
                    ng /= 3;
                }
                for (int i = 1; i <= m; i++)
                {
                    switch (op[i]) {
                        case '+':
                            a[x[i]] = a[y[i]];
                            break;
                        case '-':
                            a[x[i]] = -a[y[i]];
                            break;
                        case 'T':
                            a[x[i]] = 1;
                            break;
                        case 'U':
                            a[x[i]] = 0;
                            break;
                        case 'F':
                            a[x[i]] = -1;
                            break;
                        default:
                            break;
                    }
                }

                bool flag = true;
                ng = nn;
                for (int i = 1; i <= n; i++)
                {
                    if(a[i] != ng % 3 - 1) // 0 1 2 -> -1 0 1
                    {
                        flag = false;
                        break;
                    }
                    ng /= 3;
                }
                
                if(flag) 
                    minucnt = min(minucnt, ucnt);
            }

            cout << minucnt << '\n';
        }
    }
}

namespace only {
    void solve() 
    {
        char op;
        int x;
        while (t--)
        {
            cin >> n >> m;
            int ans = 0;
            for (int i = 1; i <= m; i++)
            {
                cin >> op >> x;
                switch(op) {
                    case 'T':
                        a[x] = 1;
                        break;
                    case 'U':
                        a[x] = 0;
                        break;
                    case 'F':
                        a[x] = -1;
                        break;
                    default:
                        cin >> x;
                        break;
                }
            }
            for (int i = 1; i <= n; i++) if (a[i] == 0) ans++;
            cout << ans << '\n';
        }
    }
}

namespace uplus {
    using force::op;
    using force::x;
    using force::y;
    void solve() 
    {
        // char op;
        // int x, y;
        while (t--)
        {
            cin >> n >> m;
            int ans = 0;
            for (int i = 1; i <= n; i++) a[i] = 1;
            for (int i = 1; i <= m; i++)
            {
                cin >> op[i] >> x[i];
                if (op[i] == 'U') {
                    a[x[i]] = 0;
                }
                else {
                    cin >> y[i];
                }
            }
            for (int i = 1; i <= m; i++)
            {
                if (op[i] == '+' && (a[x[i]] == 0 || a[y[i]] == 0))
                    a[x[i]] = a[y[i]] = 0;
            }
            for (int i = 1; i <= n; i++) if (a[i] == 0) ans++;
            cout << ans << '\n';
        }
    }
}

int main(void)
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> t;

    if (c == 1 || c == 2) force::solve();
    else if (c == 3 || c == 4) only::solve(); 
    else if (c == 5 || c == 6) uplus::solve();

    return 0;
}