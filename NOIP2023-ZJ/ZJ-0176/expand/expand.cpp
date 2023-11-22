#include<bits/stdc++.h>
using namespace std;

#define For(i, l, r) for (int i = (l); i <= (r); ++i)
const int N = 2e3 + 5;

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
    inline IO& operator >> (char &x) {
        while ((c = gc()) < 33 && ~c);
        x = c; return *this;
    }
#define pc(c) putchar(c)
    inline bool operator ~ () { return ~c; }
} io;

int n, m, p, q, kx, ky, x[N], y[N], a[N], b[N], c, T;
bool ok[N];

void solve() {
    int nn = n, mm = m;
    if (a[1] < b[1]) swap(a, b), swap(nn, mm);
    if (a[nn] <= b[mm] || a[1] == b[1]) { pc('0'); return; }
    memset(ok, 0, sizeof(ok));
    ok[0] = 1;
    For (i, 1, nn) {
    	For (j, 1, mm) ok[j] = (ok[j - 1] || ok[j]) && a[i] > b[j];
    	ok[0] = 0;
    }
    pc(ok[mm] + '0');
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    io >> c >> n >> m >> T;
    For (i, 1, n) io >> x[i];
    For (i, 1, m) io >> y[i];
    memcpy(a, x, sizeof(x));
    memcpy(b, y, sizeof(y));
    solve();

    while (T--) {
        memcpy(a, x, sizeof(x));
        memcpy(b, y, sizeof(y));
        io >> kx >> ky;
        For (i, 1, kx) io >> p >> q, a[p] = q;
        For (i, 1, ky) io >> p >> q, b[p] = q;
        solve();
    }

    return 0;
}
