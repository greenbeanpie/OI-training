#include<bits/stdc++.h>
using namespace std;

#define For(i, l, r) for (int i = (l); i <= (r); ++i)
typedef long long ll;
const int N = 1e3 + 5, M = 1e5 + 5;

struct IO {
    char c; int f;
#define gc() getchar()
    template<class C>
    inline IO& operator >> (C &x) {
        x = 0; f = 1;
        while (!isdigit(c = gc()) && ~c) f |= -!(c ^ 45);
        while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
        x *= f; return *this;
    }
#define pc(c) putchar(c)
    inline bool operator ~ () { return ~c; }
} io;

int c, T, n, m, k;
ll v, d, s[N][N], f[N], x, y;

namespace st {
    void init() {
        memset(s, 0, sizeof(s));
    }

    int main() {
        init();
        For (i, 1, m) {
            io >> x >> y >> v;
            int l = x - y + 1, r = x;
            s[1][r] += v; s[l + 1][r] -= v; 
        }
        For (i, 1, n) For (j, 1, n)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

        f[0] = 0;
        For (i, 1, n) {
            f[i] = f[i - 1];
            For (j, 1, min(i, k))
                f[i] = max(f[i], (j == i? 0: f[i - j - 1]) - 1ll * j * d + s[i - j + 1][i]);
        }

        printf("%lld\n", f[n]);

        return 0;
    }
}

namespace nd {
    ll ans;
    int main() {
        ans = 0;
        For (i, 1, m) {
            io >> x >> y >> v;
            if (y * d < v && y <= k) ans += v - y * d;
        }

        printf("%lld\n", ans);

        return 0;
    }
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    io >> c >> T;
    while (T--) {
        io >> n >> m >> k >> d;
        if (n <= 1000) st::main();
        else nd::main();
    }

    return 0;
}
