#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
    r = 0; int ch = getchar(), f = 0;
    while (!isdigit(ch)) f ^= (ch == 45), ch = getchar();
    while (isdigit(ch)) (r *= 10) += ch - 48, ch = getchar();
    if (f) r = -r;
}

int __, n, m, q;

namespace brute_force {
    const int maxn = 2e2 + 5;
    bool dp[maxn][maxn];
    int a[maxn], b[maxn], ta[maxn], tb[maxn];
    void work() {
        if (a[1] == b[1] || a[n] == b[m] || ((a[1] < b[1]) ^ (a[n] < b[m]))) {
            putchar('0');
            return;
        }
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) dp[i][j] = true;
                else {
                    for (int k = j; k >= 1; k--) {
                        if (!((a[i] < b[k]) ^ (a[1] < b[1]))) dp[i][j] |= (dp[i][k] | dp[i - 1][k] | dp[i - 1][k - 1] | dp[i][k - 1]);
                        else break;
                    }
                    for (int k = i; k >= 1; k--) {
                        if (!((a[k] < b[j]) ^ (a[1] < b[1]))) dp[i][j] |= (dp[k][j] | dp[k - 1][j] | dp[k - 1][j - 1] | dp[k][j - 1]);
                        else break;
                    }
                }
            }
        }
        putchar(dp[n][m] ? '1' : '0');
    }
    void solve() {
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int j = 1; j <= m; j++) read(b[j]);
        memcpy(ta, a, sizeof ta); memcpy(tb, b, sizeof tb);
        work();
        while (q--) {
            int ka, kb; read(ka); read(kb); 
            memcpy(a, ta, sizeof a); memcpy(b, tb, sizeof b);
            for (int i = 1; i <= ka; i++) {
                int id, v; read(id); read(v);
                a[id] = v;
            }
            for (int j = 1; j <= kb; j++) {
                int id, v; read(id); read(v);
                b[id] = v;
            }
            work();
        }
    }
}

namespace AC {
    const int maxn = 5e5 + 5;
    int a[maxn], b[maxn], ta[maxn], tb[maxn];
    int st_max[20][maxn], st_min[20][maxn];
    void st_init() {
        for (int i = 1; i <= m; i++) st_max[0][i] = st_min[0][i] = b[i];
        for (int j = 1; j < 20; j++) {
            for (int i = 1; i + (1 << j) - 1 <= m; i++) {
                st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
                st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    void work() {
        if (a[1] == b[1] || a[n] == b[m] || ((a[1] < b[1]) ^ (a[n] < b[m]))) {
            putchar('0');
            return;
        }
        st_init();
        if (a[1] < b[1]) {
            int j = 0;
            for (int i = 1; i <= n; i++) {
                if (j < m && a[i] < b[j + 1]) {
                    int tj = j + 1;
                    for (int jj = 19; jj >= 0; jj--) {
                        if (tj + (1 << jj) - 1 > m) continue;
                        if (a[i] < st_min[jj][tj]) tj += (1 << jj);
                    }
                    j = tj - 1;
                } else if (a[i] > b[j]) {
                    int tj = j;
                    for (int jj = 19; jj >= 0; jj--) {
                        if (tj - (1 << jj) + 1 <= 0) continue;
                        if (a[i] >= st_max[jj][tj - (1 << jj) + 1]) tj -= (1 << jj);
                    }
                    j = tj;
                }
                if (!j) {
                    putchar('0');
                    return;
                }
            }
            putchar(j < m ? '0' : '1');
        }
        else {
            int j = 0;
            for (int i = 1; i <= n; i++) {
                if (j < m && a[i] > b[j + 1]) {
                    int tj = j + 1;
                    for (int jj = 19; jj >= 0; jj--) {
                        if (tj + (1 << jj) - 1 > m) continue;
                        if (a[i] > st_max[jj][tj]) tj += (1 << jj);
                    }
                    j = tj - 1;
                } else if (a[i] < b[j]) {
                    int tj = j;
                    for (int jj = 19; jj >= 0; jj--) {
                        if (tj - (1 << jj) + 1 <= 0) continue;
                        if (a[i] <= st_min[jj][tj - (1 << jj) + 1]) tj -= (1 << jj);
                    }
                    j = tj;
                }
                if (!j) {
                    putchar('0');
                    return;
                }
            }
            putchar(j < m ? '0' : '1');
        }
    }
    void solve() {
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int j = 1; j <= m; j++) read(b[j]);
        memcpy(ta, a, sizeof ta); memcpy(tb, b, sizeof tb);
        work();
        while (q--) {
            int ka, kb; read(ka); read(kb); 
            memcpy(a, ta, sizeof a); memcpy(b, tb, sizeof b);
            for (int i = 1; i <= ka; i++) {
                int id, v; read(id); read(v);
                a[id] = v;
            }
            for (int j = 1; j <= kb; j++) {
                int id, v; read(id); read(v);
                b[id] = v;
            }
            work();
        }
    }
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    read(__); read(n); read(m); read(q);
    if (__ <= 4) brute_force::solve();
    else AC::solve();
    return 0;
}