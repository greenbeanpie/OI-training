#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

inline int read() {
    char c; bool f = true;
    while (!isdigit(c = getchar())) f = c != '-';
    int x = c ^ 48;
    while (isdigit(c = getchar())) x = x * 10 + (c ^ 48);
    return f ? x : -x;
}

const int N = 100010;

int C, T;
int n, m, k, d;

namespace subtask1 {
    ll f[1010][1010], sum[1010];
    vector<pair<int, int> > c[1010];
    inline int main() {
        while (T--) {
            n = read(); m = read(); k = read(); d = read();
            for (int i = 1; i <= 1009; i++) {
                c[i].clear();
            }
            memset(f, -0x3f, sizeof(f));
            f[0][0] = 0;
            // cout << "? " << f[0][1] << endl;
            for (int i = 1; i <= m; i++) {
                int x = read(), y = read(), v = read();
                c[x].push_back(make_pair(y, v));
            }
            for (int i = 1; i <= n; i++) {
                f[i][0] = f[i - 1][0];
                for (int j = 1; j <= k; j++) {
                    f[i][0] = max(f[i][0], f[i - 1][j]);
                }
                for (int j = 1; j <= i && j <= k; j++) {
                    f[i][j] = f[i - 1][j - 1] - d;
                }
                for (int j = 0; j <= k; j++) {
                    sum[j] = 0;
                }
                for (auto ch : c[i]) {
                    if (ch.first > k) continue;
                    sum[ch.first] += ch.second;
                }
                for (int j = 0; j <= k; j++) {
                    sum[j + 1] += sum[j];
                    f[i][j] += sum[j];
                }
            }
            ll ans = 0;
            for (int j = 0; j <= k; j++) {
                ans = max(ans, f[n][j]);
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    C = read(); T = read();
    // if (C <= 9) {
        return subtask1::main();
    // }
}
/*
36pts i think
*/