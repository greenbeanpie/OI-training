#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 5e5 + 10;
int c, n, m, q;
int x[N], y[N], X[N], Y[N];
struct sgt {
    #define mid ((l + r) >> 1)
    #define ls (p + 1)
    #define rs (p + ((mid - l + 1) << 1))
    pii mx[N << 1], mn[N << 1];
    void up(int p, int l, int r) {
        mx[p] = max(mx[ls], mx[rs]);
        mn[p] = min(mn[ls], mn[rs]);
    }
    void build(int p, int l, int r, int a[]) {
        if(l == r) {
            mx[p] = mn[p] = {a[l], l};
            return;
        }
        build(ls, l, mid, a), build(rs, mid + 1, r, a);
        up(p, l, r);
    }
    void mdf(int p, int l, int r, int x, int v) {
        if(l == r) {
            mx[p] = mn[p] = {v, x};
            return;
        }
        if(x <= mid) mdf(ls, l, mid, x, v);
        else mdf(rs, mid + 1, r, x, v);
        up(p, l, r);
    }
    pii qmx(int p, int l, int r, int L, int R) {
        if(L <= l && r <= R) return mx[p];
        if(R <= mid) return qmx(ls, l, mid, L, R);
        if(L > mid) return qmx(rs, mid + 1, r, L, R);
        return max(qmx(ls, l, mid, L, R), qmx(rs, mid + 1, r, L, R));
    }
    pii qmn(int p, int l, int r, int L, int R) {
        if(L <= l && r <= R) return mn[p];
        if(R <= mid) return qmn(ls, l, mid, L, R);
        if(L > mid) return qmn(rs, mid + 1, r, L, R);
        return min(qmn(ls, l, mid, L, R), qmn(rs, mid + 1, r, L, R));
    }
    #undef mid
    #undef ls
    #undef rs
}t1, t2;
int divide(int rx, int ry, int ox, int oy) {
    if(!ox && !oy) return 0;
    if(rx < 1 || ry < 1) return 1;
    int mx = t1.qmx(1, 1, n, 1, rx).y, nx = t1.qmn(1, 1, n, 1, rx).y;
    int my = t2.qmx(1, 1, m, 1, ry).y, ny = t2.qmn(1, 1, m, 1, ry).y;
    if(ox) {
        if(x[nx] > y[ny]) return divide(rx, ny - 1, 1, 1);
        else return divide(nx - 1, ry, 0, oy);
    } else {
        if(x[mx] > y[my]) return divide(mx - 1, ry, 1, 1);
        else return divide(rx, my - 1, ox, 0);
    }
    return -1;
}
int solveAB() {
    if(x[1] <= y[1]) return 0;
    if(x[n] <= y[m]) return 0;
    t1.build(1, 1, n, x), t2.build(1, 1, m, y);
    int mx = t1.mx[1].y, nx = t1.mn[1].y;
    int my = t2.mx[1].y, ny = t2.mn[1].y;
    if(x[mx] <= y[my]) return 0;
    if(x[nx] <= y[ny]) return 0;
    int ans = 1;
    ans &= divide(mx - 1, ny - 1, 1, 1);
    mx = n + 1 - mx;
    ny = m + 1 - ny;
    reverse(x + 1, x + n + 1);
    reverse(y + 1, y + m + 1);
    t1.build(1, 1, n, x), t2.build(1, 1, m, y);
    ans &= divide(mx - 1, ny - 1, 1, 1);
    reverse(x + 1, x + n + 1);
    reverse(y + 1, y + m + 1);
    return ans;
}
int solve() {
    if(x[1] < y[1]) {
        FOR(i, 1, max(n, m)) swap(x[i], y[i]);
        swap(n, m);
        int flag = solveAB();
        FOR(i, 1, max(n, m)) swap(x[i], y[i]);
        swap(n, m);
        return flag;
    }
    if(x[1] > y[1]) return solveAB();
    return 0;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> q;
    FOR(i, 1, n) cin >> x[i], X[i] = x[i];
    FOR(i, 1, m) cin >> y[i], Y[i] = y[i];
    cout << solve();
    FOR(i, 1, q) {
        int kx, ky;
        cin >> kx >> ky;
        FOR(j, 1, n) x[j] = X[j];
        FOR(j, 1, m) y[j] = Y[j];
        FOR(j, 1, kx) {
            int p, v;
            cin >> p >> v;
            x[p] = v;
        }
        FOR(j, 1, ky) {
            int p, v;
            cin >> p >> v;
            y[p] = v;
        }
        cout << solve();
    }
    cout << "\n";
}