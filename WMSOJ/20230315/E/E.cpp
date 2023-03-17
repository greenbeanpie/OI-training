#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5;

struct Node
{
    int l, r;
    int c;
};

int n, T, tot;
int dp[M];
vector<Node> s[M];

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> T;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        for (int j = 1; j <= x; j++)
        {

            int l, r;
            int c;
            cin >> l >> r >> c;

            s[r].push_back((Node){l, r, c});
        }
    }

    for (int i = 1; i <= T; i++)
    {
        dp[i] = dp[i - 1];

        for (int j = 0; j < (int)s[i].size(); j++)
        {
            Node v = s[i][j];
            dp[i] = max(dp[i], dp[v.l - 1] + v.c);
        }
    }

    cout << *max_element(seg(dp, 1, T));

    return 0;
}
