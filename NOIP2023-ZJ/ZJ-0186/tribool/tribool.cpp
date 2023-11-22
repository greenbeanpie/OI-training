#include <bits/stdc++.h>
using namespace std;
namespace mycode
{
    constexpr int MaxN = 1e5 + 5;
    int N, M;
    struct qry { char op; int x; int y; } q[MaxN];

    int must[MaxN]; // 1 true  -1 false +- 2 unknown

    int need[MaxN];
    int vis[MaxN], ukn[MaxN], val[MaxN];
    int cnt;

    int dfs(int x)
    {
        // cout << x << '\n';
        ++cnt;
        int y = abs(need[x]);
        if (vis[y])
        {
            if (ukn[y])
            {
                return ukn[x] = 1;
            }

            int sho = vis[x];
            if (need[x] < 0) sho = -sho;
            // cout << sho << ':' << vis[y] << '\n';
            if (abs(sho) == abs(vis[y]) && sho != vis[y])
            {
                // cout << "2222";
                ukn[y] = ukn[x] = 1;
                return 1;
            }
            return 0;
        }
        
        vis[y] = vis[x];
        if (need[x] < 0) vis[y] = -vis[y];

        ukn[x] = dfs(y);
        if (must[x] == 2) ukn[x] = 1;

        return ukn[x];
    }

    int solve()
    {
        cin >> N >> M;
        for (int i = 1; i <= M; i++)
        {
            cin >> q[i].op >> q[i].x;
            if (q[i].op == '+' || q[i].op == '-') cin >> q[i].y;
        }

        memset(must, 0, sizeof(must));
        memset(need, 0, sizeof(need));
        memset(vis, 0, sizeof(vis));
        memset(ukn, 0, sizeof(ukn));
        memset(val, 0, sizeof(val));

        for (int i = 1; i <= M; i++)
        {
            char op = q[i].op;
            int x = q[i].x, y = q[i].y;
            if (op == '+')
            {
                must[x] = must[y];
            }
            else if (op == '-')
            {
                if (abs(must[y]) == 1) must[x] = - must[y];
            }
            else
            {
                if (op == 'T') must[x] = 1;
                else if (op == 'F') must[x] = -1;
                else if (op == 'U') must[x] = 2;
            }

            // for (int i = 1; i <= N; i++) cout << must[i] << '|';
            // cout << '\n';
        }

        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            if (must[i] == 2)
            {
                ans++;
                vis[i] = 1e9;
                ukn[i] = 1;
            }
        }


        for (int i = 1; i <= N; i++) need[i] = i;
        for (int i = 1; i <= M; i++)
        {
            char op = q[i].op;
            int x = q[i].x, y = q[i].y;
            if (op == '+') need[x] = need[y];
            else if (op == '-') need[x] = - need[y];

            // for (int i = 1; i <= N; i++) cout << need[i] << ' ';
            // cout << '\n';
        }


        int idx = 0;
        for (int i = 1; i <= N; i++)
        {
            if (must[i] == 0 && !vis[i])
            {
                cnt = 0;
                vis[i] = ++idx;
                dfs(i);
                if (ukn[i]) ans += cnt;
            }
        }

        // for (int i = 1; i <= N; i++) cout << vis[i] << ':';
        // cout << '\n';
        // for (int i = 1; i <= N; i++) cout << ukn[i] << '|';
        // cout << '\n';
        return ans;
    }
    void main()
    {
        freopen("tribool.in", "r", stdin);
        freopen("tribool.out", "w", stdout);
        ios::sync_with_stdio(false); cin.tie(0);

        int C, T;
        cin >> C >> T;
        while (T--) cout << solve() << '\n';
    }
}
signed main() { mycode::main(); }

/*
1
10 10
- 7 6
+ 4 1
+ 6 4
T 1
+ 2 9
- 9 10
U 10
+ 5 5
U 8
T 3
*/