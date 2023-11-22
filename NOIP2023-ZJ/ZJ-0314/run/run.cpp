#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10, M = 1e3 + 10;
int c, t, n, m, k, d;
typedef pair<int, int> PII;
vector<PII> award[N];
int f[N][M];

signed main(void)
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> c >> t;
    while (t--) 
    {
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= n; i++) award[i].clear();
        int id, x, y;
        for (int i = 1; i <= m; i++)
        {
            cin >> id >> x >> y;
            // if(x == 0) puts("-----------------------------------------------");
            award[id].push_back(make_pair(x, y));
        }
        for (int i = 1; i <= n; i++)
        {
            if(!award[i].empty())
                sort(award[i].begin(), award[i].end());
            // for(auto g : award[i]) 
            // {
            //     printf("first = %d, second = %d\n", g.first, g.second);
            // }
        }

        memset(f, -0x3f, sizeof f);
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int prize = 0;
            int pos = 0;
            f[i][0] = f[i - 1][0];
            for (int j = 1; j <= min(i, k); j++)
            {
                while(pos < award[i].size() && award[i][pos].first <= j)
                {
                    prize += award[i][pos].second;
                    pos ++;
                    // printf("prize = %lld\n", prize);
                }

                f[i][j] = f[i - 1][j - 1] - d + prize;
                f[i][0] = max(f[i][0], f[i - 1][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            // printf("f[%d][%d] = %lld\n", n, i, f[n][i]);
            ans = max(ans, f[n][i]);
        }
        
        cout << ans << '\n';
    }
    return 0;
}