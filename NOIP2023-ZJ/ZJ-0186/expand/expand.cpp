#include <bits/stdc++.h>
using namespace std;
namespace mycode
{
    constexpr int MaxN = 5e5 + 5;
    int C, N, M, Q;
    int xx[MaxN], yy[MaxN], x[MaxN], y[MaxN];

    int f[2005][2005];
    void solve1()
    {
        int ans = 0;
        if (x[1] > y[1])
        {
            memset(f, 0, sizeof(f));
            f[0][0] = 1;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= M; j++)
                {
                    if (x[i] <= y[j]) continue;
                    if (f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1])
                    {
                        f[i][j] = 1;
                    }
                }
            }
            ans |= f[N][M];
        }
        if (x[1] < y[1])
        {
            memset(f, 0, sizeof(f));
            f[0][0] = 1;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= M; j++)
                {
                    if (x[i] >= y[j]) continue;
                    if (f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1])
                    {
                        f[i][j] = 1;
                    }
                }
            }
            ans |= f[N][M];
        }
        
        cout << ans;
    }
    
    void solve2()
    {
        for (int i = 1; i <= N; i++)
        {
            if (x[i] >= y[M]) return cout << 0, void();
        }
        for (int i = 1; i <= M; i++)
        {
            if (y[i] <= x[N]) return cout << 0, void();
        }

        int j = 1;
        for (int i = 1; i <= N; i++) // j <= M
        {
            int las = 0;
            for (; j <= M && y[j] > x[i]; j++) las++;
            if (las == 0) { cout << 0; return; }
        }
        
        if (j > M) cout << 1;
        else cout << 0;
    }
    void main()
    {
        freopen("expand.in", "r", stdin);
        freopen("expand.out", "w", stdout);
        ios::sync_with_stdio(false); cin.tie(0);

        cin >> C >> N >> M >> Q;
        for (int i = 1; i <= N; i++) cin >> xx[i], x[i] = xx[i];
        for (int i = 1; i <= M; i++) cin >> yy[i], y[i] = yy[i];

        if (C >= 8 && C <= 14) solve2();
        else solve1();

        for (int kx, ky; Q--;)
        {
            for (int i = 1; i <= N; i++) x[i] = xx[i];
            for (int i = 1; i <= M; i++) y[i] = yy[i];

            cin >> kx >> ky;
            for (int p, val; kx--;) cin >> p >> val, x[p] = val;
            for (int p, val; ky--;) cin >> p >> val, y[p] = val;
            if (C >= 8 && C <= 14) solve2();
            else solve1();
        }
    }
}
signed main() { mycode::main(); }
/*
8 6 9
1 7 4
1 1 1
1 0 1
1 1 1

0 0 0
0 0 0
0 0 0
================
8 6 0
1 7 4
1 1 1
1 0 1
0 0 0

0 0 0
0 0 0
0 0 0
================
8 6 9
8 7 5

1 1 1
0 0 1
0 0 1

1 0 0
1 1 0
0 0 0
================
8 8 9
7 7 4
1 1 1
1 1 1
1 1 1

0 0 0
0 0 0
0 0 0
===============
*/