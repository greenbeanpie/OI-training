#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define MT make_tuple
#define IT iterator
#define fi first
#define se second
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Rep(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define CLR(a, v) memset(a, v, sizeof(a))
#define CPY(a, b) memcpy(a, b, sizeof(a))
#define debug cout << "ztxakking\n"
#define y0 ztxakioi
#define y1 ztxaknoi
using namespace std;
using ll = long long;
using ull = unsigned ll;
using uint = unsigned;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vi = vector <int>;
template <typename T>
using V = vector <T>;
mt19937 gen(time(0));
const int N = 2e5 + 7;
const ll inf = 1e18;
int n, m, k, d, l[N], r[N], w[N];
V <pii> v[N];
vi x;
struct segtree {
    struct node {
        int l, r;
        ll mx, tag;
    } tr[N * 4];
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    void pushup(int p) {
        tr[p].mx = max(tr[ls].mx, tr[rs].mx);
    }
    void build(int p, int l, int r) {
        tr[p].l = l, tr[p].r = r, tr[p].tag = 0;
        if (l == r) {
            tr[p].mx = 1ll * d * x[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid), build(rs, mid + 1, r);
        pushup(p);
    }
    void pushdown(int p) {
        if (tr[p].tag) {
            tr[ls].tag += tr[p].tag, tr[ls].mx += tr[p].tag;
            tr[rs].tag += tr[p].tag, tr[rs].mx += tr[p].tag;
            tr[p].tag = 0;
        }
    }
    void update(int p, int x, int y, ll k) {
        if (tr[p].l >= x && tr[p].r <= y) {
            tr[p].mx += k, tr[p].tag += k;
            return ;
        }
        pushdown(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) update(ls, x, y, k);
        if (mid < y) update(rs, x, y, k);
        pushup(p);
    }
    ll qry(int p, int x, int y) {
        if (x > y) return -inf;
        if (tr[p].l >= x && tr[p].r <= y) return tr[p].mx;
        pushdown(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        ll ans = -inf;
        if (x <= mid) ans = max(ans, qry(ls, x, y));
        if (mid < y) ans = max(ans, qry(rs, x, y));
        return ans;
    }
    #undef ls
    #undef rs
} Tree;
ll f[N][2];
void solve() {
    cin >> n >> m >> k >> d;
    x.clear(), x.pb(0), x.pb(n);
    For(i, 1, m) {
        cin >> r[i] >> l[i] >> w[i], l[i] = r[i] - l[i] + 1;
        x.pb(l[i] - 1), x.pb(r[i]);
    }
    sort(x.begin(), x.end()), x.erase(unique(x.begin(), x.end()), x.end());
    For(i, 0, x.size() - 1) v[i].clear();
    For(i, 1, m) {
        int L = lower_bound(x.begin(), x.end(), l[i] - 1) - x.begin();
        int R = lower_bound(x.begin(), x.end(), r[i]) - x.begin();
        v[R].pb(MP(L, w[i]));
    }
    Tree.build(1, 0, x.size() - 1);
    For(i, 0, x.size() - 1) f[i][0] = f[i][1] = 0;
    int p = 0;
    For(i, 1, x.size() - 1) {
        while (p < x.size() && x[i] - x[p] > k) ++p;
        for (auto [l, w] : v[i]) if (l >= p) Tree.update(1, 0, l, w);
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = Tree.qry(1, p, i - 1) - 1ll * d * x[i];
        Tree.update(1, i, i, f[i][0]);
    }
    cout << max(f[x.size() - 1][0], f[x.size() - 1][1]) << '\n';
}
int main() {
    // double start = clock();
    freopen("run.in", "r", stdin), freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, t; cin >> c >> t;
    while (t--) solve();
    // cerr << (clock() - start) / CLOCKS_PER_SEC << '\n';
    return 0;
}