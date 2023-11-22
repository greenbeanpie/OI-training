#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace mycode
{

    constexpr int MaxN = 1e5 + 5;
    int N, M, K, D;
    struct qry { int x, y, v; } q[MaxN];
    void cmax(int &x, int y)
    {
        if (y > x) x = y;
    }
    namespace solve2
    {
        bool check()
        {
            return true;
        }
        int f[MaxN][2];

        int g[MaxN];

        void solve()
        {
            memset(f, 0, sizeof(f));
            memset(g, 0, sizeof(g));
            sort(q + 1, q + 1 + M, [](qry a, qry b)
                { return a.x < b.x; });

            for (int i = 1, k = 1; i <= N; i++)
            {
                f[i][0] = max(f[i - 1][0], f[i - 1][1]);
                f[i][1] = max(f[i - 1][0], f[i - 1][1]) - D;

                for (; k <= M && q[k].x <= i; k++)
                    g[q[k].x - q[k].y + 1] += q[k].v;

                for (int j = 1, val = 0; j <= min(i, K); j++)
                {
                    val += g[i - j + 1];
                    cmax(f[i][1], f[i - j][0] - j * D + val);
                }
            }

            // for (int i = 1; i <= N; i++) cerr << f[i][0] << ' ';
            // cerr << '\n';
            // for (int i = 1; i <= N; i++) cerr << f[i][1] << ' ';
            // cerr << '\n';
            cout << max(f[N][0], f[N][1]) << '\n';
        }
    }
    void main()
    {
        freopen("run.in", "r", stdin);
        freopen("run.out", "w", stdout);
        ios::sync_with_stdio(false); cin.tie(0);
        int C, T;
        cin >> C >> T;
        while (T--)
        {
            cin >> N >> M >> K >> D;
            for (int i = 1; i <= M; i++)
                cin >> q[i].x >> q[i].y >> q[i].v;
            solve2::solve();
        }
    }
}
signed main() { mycode::main(); }
/*
1 1
10 3 4 1
6 3 12
7 3 2
10 2 5
*/