#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)

#define MAXN 2010

int n, m;
int q;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

void print()
{
    fore(i, 1, n)
    {
        fore(j, 1, m) cerr << dp[i][j];
        cerr << endl;
    }
}

bool check()
{

    bool flag = false;

    if (a[1] > b[1])
    {

        memset(dp, 0, sizeof(dp));

        fore(i, 1, n)
        {
            dp[i][0] = 1;
            fore(j, 1, m)
            {
                if (a[i] > b[j])
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j - 1] | dp[i - 1][j];
                else
                    dp[i][j] = 0;
            }
        }
        print();

        flag |= dp[n][m];
    }

    if (a[1] < b[1])
    {

        memset(dp, 0, sizeof(dp));

        fore(j, 1, m)
        {
            dp[0][j] = 1;
            fore(i, 1, n)
            {
                if (a[i] < b[j])
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - 1] | dp[i][j - 1];
                else
                    dp[i][j] = 0;
                // cout<<dp[i][j];
            }
            // cout<<endl;
        }
        
        print();
        
        flag |= dp[n][m];
    }
    cerr<<endl;
    
    return flag;
}

int tmpa[MAXN];
int tmpb[MAXN];

void solve()
{
    fore(i, 1, n) cin >> a[i];
    fore(i, 1, m) cin >> b[i];

    cout << check();
    memcpy(tmpa, a, sizeof(a));
    memcpy(tmpb, b, sizeof(b));
    fore(i, 1, q)
    {
        
        int s, t;
        cin >> s >> t;
        fore(i, 1, s)
        {
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
        fore(i, 1, t)
        {
            int x, y;
            cin >> x >> y;
            b[x] = y;
        }
        cout << check();
        memcpy(a, tmpa, sizeof(a));
        memcpy(b, tmpb, sizeof(b));
    }
    cout << endl;
}

signed main()
{

    // freopen("a.txt", "r", stdin);
    // freopen("b.txt", "w", stdout);

    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int c;

    cin >> c >> n >> m >> q;

    solve();

    return 0;
}
