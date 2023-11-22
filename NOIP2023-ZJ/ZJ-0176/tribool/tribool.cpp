#include<bits/stdc++.h>
using namespace std;

#define For(i, l, r) for (int i = (l); i <= (r); ++i)
const int N = 2e5 + 5;

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

int c, t, n, m, x, y, fa[N], id[N], val[N], ans, tot;
bool isu[N];
char op;

int find(int k) {
    if (k == fa[k]) return k;
    int f = find(fa[k]);
    val[k] ^= val[fa[k]];
    isu[f] = isu[f] || isu[k];
    return fa[k] = f;
}

void init() {
    ans = 0;
    tot = n;
    memset(val, 0, sizeof(val));
    memset(isu, 0, sizeof(isu));
    For (i, 1, n) id[i] = fa[i] = i;
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    io >> c >> t;
    while (t--) {
        io >> n >> m;
        init();
        
        For (i, 1, m) {
            io >> op >> x;
            if (op == '+' || op == '-') io >> y, y = id[y];

            id[x] = ++tot; fa[tot] = tot;
            if (op == '+') {
                int u = tot, v = y;
                int fu = find(u), fv = find(v);
                fa[fu] = fv;
                val[fu] = val[v] ^ val[u];
            } else if (op == '-') {
                int u = tot, v = y;
                int fu = find(u), fv = find(v);
                fa[fu] = fv;
                val[fu] = 1 ^ val[v] ^ val[u];
            } else {
                isu[tot] = op == 'U';
            }
        }
        
        For (i, 1, n)  {
            int u = i, v = id[i];
            int fu = find(u), fv = find(v);
            if (fu ^ fv) {
                fa[fu] = fv;
                val[fu] = val[u] ^ val[v];
            } else {
                if (val[u] ^ val[v]) isu[u] = 1;
            }
        }

        For (i, 1, n) find(i), find(id[i]);

        For (i, 1, n) if (isu[find(i)]) ans++;

        printf("%d\n", ans);
    }

    return 0;
}
