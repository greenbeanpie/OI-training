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
const int N = 5e5 + 7;
int c, n, m, q, a[N], b[N];
struct segtree {
    struct node {
        int l, r, mx, mn;
    } tr[N << 2];
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    void pushup(int p) {
        tr[p].mx = max(tr[ls].mx, tr[rs].mx);
        tr[p].mn = min(tr[ls].mn, tr[rs].mn);
    }
    void build(int p, int l, int r, const vi &y) {
        tr[p].l = l, tr[p].r = r;
        if (l == r) {
            tr[p].mx = tr[p].mn = y[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid, y), build(rs, mid + 1, r, y);
        pushup(p);
    }
    int qry1(int p, int x, int k) { // the lst one <= x which val < k
        if (tr[p].l > x) return -1;
        if (tr[p].mn >= k) return -1;
        if (tr[p].l == tr[p].r) return tr[p].l;
        int res = qry1(rs, x, k);
        if (res == -1) return qry1(ls, x, k);
        else return res;
    }
    int qry2(int p, int x, int k) { // the first one >= x which val >= k
        if (tr[p].r < x) return -1;
        if (tr[p].mx < k) return -1;
        if (tr[p].l == tr[p].r) return tr[p].l;
        int res = qry2(ls, x, k);
        if (res == -1) return qry2(rs, x, k);
        else return res;
    }
    #undef ls
    #undef rs
} Tree;
bool judge(vi x, vi y) {
    int n = x.size(), m = y.size();
    if (!n || !m) return 1;
    x.insert(x.begin(), 0), y.insert(y.begin(), 0);
    if (n > m) {
        swap(n, m), swap(x, y);
        For(i, 1, n) x[i] = -x[i];
        For(i, 1, m) y[i] = -y[i];
    }
    Tree.build(1, 1, m, y);
    int r = 0;
    For(i, 1, n) {
        int p = Tree.qry2(1, r + 1, x[i]);
        if (p == -1) return 1;
        if (p - 1 > r) r = p - 1;
        else {
            int t = min(10, r);
            while (t--) {
                if (y[r] < x[i]) break;
                --r;
            }
            if (!r) return 0;
            if (y[r] >= x[i]) {
                p = Tree.qry1(1, r, x[i]);
                if (p == -1) return 0;
                else r = p;
            }
        }
    }
    return 1;
}
#define P0 return cout << 0, void()
#define P1 return cout << 1, void()
void solve() {
    int mn1 = *min_element(a + 1, a + n + 1), mx1 = *max_element(a + 1, a + n + 1);
    int mn2 = *min_element(b + 1, b + m + 1), mx2 = *max_element(b + 1, b + m + 1);
    if (mx1 == mx2 || mn1 == mn2) P0;
    if (mx1 > mx2) {
        if (mn1 < mn2) P0;
        vi x, y;
        For(i, 1, n) {
            if (a[i] == mx1) break;
            x.pb(a[i]);
        }
        For(i, 1, m) {
            if (b[i] == mn2) break;
            y.pb(b[i]);
        }
        if (!judge(x, y)) P0;
        x.clear(), y.clear();
        Rep(i, n, 1) {
            if (a[i] == mx1) break;
            x.pb(a[i]);
        }
        Rep(i, m, 1) {
            if (b[i] == mn2) break;
            y.pb(b[i]);
        }
        if (!judge(x, y)) P0;
        P1;
    } else {
        if (mn2 < mn1) P0;
        vi x, y;
        For(i, 1, n) {
            if (a[i] == mn1) break;
            x.pb(a[i]);
        }
        For(i, 1, m) {
            if (b[i] == mx2) break;
            y.pb(b[i]);
        }
        if (!judge(y, x)) P0;
        x.clear(), y.clear();
        Rep(i, n, 1) {
            if (a[i] == mn1) break;
            x.pb(a[i]);
        }
        Rep(i, m, 1) {
            if (b[i] == mx2) break;
            y.pb(b[i]);
        }
        if (!judge(y, x)) P0;
        P1;
    }
}
int main() {
    // double start = clock();
    freopen("expand.in", "r", stdin), freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> n >> m >> q;
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) cin >> b[i];
    solve();
    For(i, 1, q) {
        int kX, kY; cin >> kX >> kY;
        V <pii> vX, vY;
        For(j, 1, kX) {
            int p, v; cin >> p >> v;
            vX.pb(MP(p, a[p])), a[p] = v;
        }
        For(j, 1, kY) {
            int p, v; cin >> p >> v;
            vY.pb(MP(p, b[p])), b[p] = v;
        }
        solve();
        for (auto [x, y] : vX) a[x] = y;
        for (auto [x, y] : vY) b[x] = y;
    }
    // cerr << (clock() - start) / CLOCKS_PER_SEC << '\n';
    return 0;
}