#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

const int N = 2005;

int a[N], b[N], c[N], d[N], f[N][N], s[N][N], S[N][N], l[N][N], r[N][N];

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    int id = read();
    int n = read(), m = read(), q = read();

    for (int i = 1; i <= n; i++) {
        c[i] = a[i] = read();
    }

    for (int i = 1; i <= m; i++) {
        d[i] = b[i] = read();
    }

    auto calc = [&]() -> int {
        f[0][0] = s[0][0] = S[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            s[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                S[0][j] = 1;
                f[i][j] = s[i][j] = S[i][j] = l[i][j] = r[i][j] = 0;
                l[0][j] = 1;
            }
            r[i][0] = 1;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (c[i] > d[j]) {
                    r[i][j] = r[i][j - 1];
                    l[i][j] = l[i - 1][j];
                }
                else {
                    r[i][j] = j + 1;
                    l[i][j] = i + 1;
                }
                int x = S[i - 1][j - 1];
                if (r[i][j] > 1) x -= S[i - 1][r[i][j] - 2];
                if (x) f[i][j] = 1;
                x = s[i - 1][j - 1];
                if (l[i][j] > 1) x -= s[l[i][j] - 2][j - 1];
                if (x) f[i][j] = 1;
                s[i][j] = s[i - 1][j] + f[i][j];
                S[i][j] = S[i][j - 1] + f[i][j];
            }
        }

        ans |= f[n][m];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = s[i][j] = S[i][j] = l[i][j] = r[i][j] = 0;
                l[0][j] = 1;
            }
            r[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (c[i] < d[j]) {
                    r[i][j] = r[i][j - 1];
                    l[i][j] = l[i - 1][j];
                }
                else {
                    r[i][j] = j + 1;
                    l[i][j] = i + 1;
                }
                int x = S[i - 1][j - 1];
                if (r[i][j] > 1) x -= S[i - 1][r[i][j] - 2];
                if (x) f[i][j] = 1;
                x = s[i - 1][j - 1];
                if (l[i][j] > 1) x -= s[l[i][j] - 2][j - 1];
                if (x) f[i][j] = 1;
                s[i][j] = s[i - 1][j] + f[i][j];
                S[i][j] = S[i][j - 1] + f[i][j];
            }
        }

        ans |= f[n][m];

        return ans;
    };

    write(calc());

    while (q--) {
        int kx = read(), ky = read();

        for (int i = 1; i <= n; i++) {
            c[i] = a[i];
        }

        for (int i = 1; i <= m; i++) {
            d[i] = b[i];
        }

        for (int i = 1; i <= kx; i++) {
            int x = read(), y = read();
            c[x] = y;
        }

        for (int i = 1; i <= ky; i++) {
            int x = read(), y = read();
            d[x] = y;
        }

        write(calc());
    }
}