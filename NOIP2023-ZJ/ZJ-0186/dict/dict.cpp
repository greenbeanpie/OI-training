#include <bits/stdc++.h>
using namespace std;
namespace mycode
{
    constexpr int MaxN = 3005;
    int n, m, ans[MaxN];
    string s[MaxN * 2];
    int p[MaxN * 2];
    void main()
    {
        freopen("dict.in", "r", stdin);
        freopen("dict.out", "w", stdout);
        ios::sync_with_stdio(false); cin.tie(0);

        cin >> n >> m;

        if (n == 1) { cout << 1; return; }
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            sort(s[i].begin(), s[i].end());
            s[i + n] = s[i];
            reverse(s[i + n].begin(), s[i + n].end());

            p[i] = i;
            p[i + n] = i + n;
        }
        sort(p + 1, p + 1 + 2 * n, [](int x, int y)
            { return s[x] < s[y]; });

        for (int i = 1; i <= 2 * n; i++)
        {
            if (p[i] <= n) ans[p[i]] = 1;
            else
            {
                for (int j = i + 1; j <= 2 * n; j++)
                {
                    if (p[j] == p[i] - n)
                    {
                        ans[p[j]] = 1;
                        break;
                    }
                    else if (p[j] > n) break;
                }
                break;
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << '\n';
    }
}
signed main() { mycode::main(); }

/*
4 7
abandon
bananaa
baannaa
notnotn

aabd

*/