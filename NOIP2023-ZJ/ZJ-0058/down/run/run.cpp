#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

namespace brute {

constexpr int maxn = 100010;
constexpr ll inf = 1e18;

int n, m, k, d;
ll t[maxn << 2], lz[maxn << 2];
vector<pii> a[maxn];

#define mid ((l + r) >> 1)

void build(int c, int l, int r) {
  lz[c] = 0;
  if (l == r) return t[c] = -inf, void();
  build(c << 1, l, mid), build(c << 1 | 1, mid + 1, r);
  t[c] = max(t[c << 1], t[c << 1 | 1]);
}

void down(int c, int l, int r) {
  if (!lz[c]) return;
  t[c << 1] += lz[c], t[c << 1 | 1] += lz[c];
  lz[c << 1] += lz[c], lz[c << 1 | 1] += lz[c];
  lz[c] = 0;
}

void add(int c, int l, int r, int x, int y, ll v) {
  if (l == x && r == y) return t[c] += v, lz[c] += v, void();
  down(c, l, r);
  if (y <= mid) add(c << 1, l, mid, x, y, v);
  else if (x > mid) add(c << 1 | 1, mid + 1, r, x, y, v);
  else add(c << 1, l, mid, x, mid, v), add(c << 1 | 1, mid + 1, r, mid + 1, y, v);
  t[c] = max(t[c << 1], t[c << 1 | 1]);
}

void upd(int c, int l, int r, int x, ll v) {
  if (l == r) return t[c] = v, void();
  down(c, l, r);
  if (x <= mid) upd(c << 1, l, mid, x, v);
  else upd(c << 1 | 1, mid + 1, r, x, v);
  t[c] = max(t[c << 1], t[c << 1 | 1]);
}

ll qry(int c, int l, int r, int x, int y) {
  if (l == x && r == y) return t[c];
  down(c, l, r);
  if (y <= mid) return qry(c << 1, l, mid, x, y);
  else if (x > mid) return qry(c << 1 | 1, mid + 1, r, x, y);
  else return max(qry(c << 1, l, mid, x, mid), qry(c << 1 | 1, mid + 1, r, mid + 1, y));
}

#undef mid

void work() {
  cin >> n >> m >> k >> d;
  rep (i, 1, n) a[i].clear();
  rep (i, 1, m) {
    int x, y, v;
    cin >> x >> y >> v;
    a[x].emplace_back(y, v);
  }
  // rep (i, 0, n) rep (j, 0, n) f[i][j] = -inf;
  // f[0][0] = 0;
  build(1, 0, n), upd(1, 0, n, 0, 0);
  rep (i, 1, n) {
    ll res = qry(1, 0, n, 0, i - 1);
    add(1, 0, n, max(0, i - k - 1), i - 1, -d);
    upd(1, 0, n, i, res);
    // rep (j, 0, i - 1) {
    //   f[i][i] = max(f[i][i], f[i - 1][i - 1 - j]);
    //   f[i][i - j - 1] = max(f[i][i - j - 1], f[i - 1][i - j - 1] - d);
    // }
    for (pii reward : a[i]) {
      int x = reward.first, v = reward.second;
      // rep (j, x, i) f[i][i - j] += v;
      if (i - x >= 0) add(1, 0, n, max(0, i - k - 1), i - x, v);
    }
    if (i - k - 1 >= 0) upd(1, 0, n, i - k - 1, -inf);
    // rep (j, k + 1, i) f[i][i - j] = -inf;
  }
  cout << qry(1, 0, n, n - k, n) << '\n';
  // ll ans = -inf;
  // rep (j, 0, k) ans = max(ans, f[n][n - j]);
  // cout << ans << '\n';
}

}

namespace subA {

constexpr int maxn = 100010;
constexpr int maxk = 110;
constexpr ll inf = 1e18;

struct node {
  int x, y, v;
} a[maxn];

bool cmp(node x, node y) { return x.x < y.x; }

int n, m, k, d;
ll f[maxn][maxk];

void work() {
  cin >> n >> m >> k >> d;
  rep (i, 1, m) cin >> a[i].x >> a[i].y >> a[i].v;
  sort(a + 1, a + m + 1, cmp);
  rep (i, 0, m) rep (j, 0, k) f[i][j] = -inf;
  f[0][0] = 0, a[0].x = 0;
  rep (i, 1, m) {
    int day = a[i].x, spe = day - a[i - 1].x;
    ll mx = 0;
    rep (j, 0, k) mx = max(mx, f[i - 1][j]);
    rep (j, 0, k) {
      if (j < spe) f[i][j] = mx - 1ll * d * j;
      else f[i][j] = f[i - 1][j - spe] - 1ll * d * spe;
    }
    if (a[i].y > k) continue;
    rep (j, a[i].y, k) f[i][j] += a[i].v;
  }
  ll ans = 0;
  rep (i, 0, k) ans = max(ans, f[m][i]);
  cout << ans << '\n';
}

}

namespace subB {

constexpr int maxn = 100010;

int n, m, k, d;

void work() {
  cin >> n >> m >> k >> d;
  ll ans = 0;
  rep (i, 1, m) {
    int x, y, v;
    cin >> x >> y >> v;
    int l = x - y + 1, r = x;
    ans += max(0ll, v - 1ll * d * (r - l + 1));
  }
  cout << ans << '\n';
}

}

namespace subC {

constexpr int maxn = 100010;
constexpr ll inf = 1e18;

struct node {
  int l, r, v;
  friend bool operator<(node x, node y) {
    return x.r < y.r;
  }
} a[maxn];

int n, m, k, d;
// ll f[maxn][maxn];

struct segtree {

  ll t[maxn << 2];

  #define mid ((l + r) >> 1)

  void build(int c, int l, int r) {
    if (l == r) return t[c] = -inf, void();
    build(c << 1, l, mid), build(c << 1 | 1, mid + 1, r);
    t[c] = max(t[c << 1], t[c << 1 | 1]);
  }

  void upd(int c, int l, int r, int x, ll v) {
    if (l == r) return t[c] = v, void();
    if (x <= mid) upd(c << 1, l, mid, x, v);
    else upd(c << 1 | 1, mid + 1, r, x, v);
    t[c] = max(t[c << 1], t[c << 1 | 1]);
  }

  ll qry(int c, int l, int r, int x, int y) {
    if (l == x && r == y) return t[c];
    if (y <= mid) return qry(c << 1, l, mid, x, y);
    else if (x > mid) return qry(c << 1 | 1, mid + 1, r, x, y);
    else return max(qry(c << 1, l, mid, x, mid), qry(c << 1 | 1, mid + 1, r, mid + 1, y));
  }

  #undef mid

} t1, t2;

void work() {
  cin >> n >> m >> k >> d;
  rep (i, 1, m) {
    int x, y;
    cin >> x >> y >> a[i].v;
    a[i].l = x - y + 1, a[i].r = x;
  }
  sort(a + 1, a + m + 1);
  // rep (i, 0, m) rep (j, 0, m) f[i][j] = -inf;
  // f[0][0] = 0;
  t1.build(1, 0, m), t1.upd(1, 0, m, 0, 0);
  t2.build(1, 0, m), t2.upd(1, 0, m, 0, 0);
  rep (i, 1, m) {
    // rep (j, 0, i - 1) f[i][j] = f[i - 1][j];
    int l = 1, r = i - 1, res = i, lim = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[i].r - a[mid].l + 1 <= k) res = mid, r = mid - 1;
      else l = mid + 1;
    }
    l = 1, r = i - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[i].l > a[mid].r + 1) lim = mid, l = mid + 1;
      else r = mid - 1;
    }
    ll mx = -inf;
    if (lim < res) {
      // [0, lim] [res, i)
      if (lim >= 0) mx = max(mx, t1.qry(1, 0, m, 0, lim) + a[i].v - 1ll * d * (a[i].r - a[i].l + 1));
      if (res < i) mx = max(mx, t2.qry(1, 0, m, res, i - 1) + a[i].v - 1ll * d * a[i].r);
    } else {
      // [0, lim] (lim, i)
      if (lim >= 0) mx = max(mx, t1.qry(1, 0, m, 0, lim) + a[i].v - 1ll * d * (a[i].r - a[i].l + 1));
      if (lim < i) mx = max(mx, t2.qry(1, 0, m, lim, i - 1) + a[i].v - 1ll * d * a[i].r);
    }
    // rep (j, 0, lim) mx = max(mx, f[i - 1][j] + a[i].v - 1ll * d * (a[i].r - a[i].l + 1));
    // rep (j, res, i - 1) mx = max(mx, f[i - 1][j] + a[i].v - 1ll * d * (a[i].r - a[j].r));
    if (a[i].r - a[i].l + 1 <= k) {
      t1.upd(1, 0, m, i, mx), t2.upd(1, 0, m, i, mx + 1ll * d * a[i].r);
    }
    // if (a[i].r - a[i].l + 1 <= k) f[i][i] = mx;
  }
  ll ans = -inf;
  // rep (i, 0, m) ans = max(ans, f[m][i]);
  ans = t1.qry(1, 0, m, 0, m);
  cout << ans << '\n';
}

}

int main() {
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  int sid, t;
  cin >> sid >> t;
  while (t--) {
    if (sid <= 14) brute::work();
    else if (sid >= 15 && sid <= 16) subA::work();
    else if (sid >= 17 && sid <= 18) subB::work();
    else if (sid >= 19 && sid <= 21) subC::work();
    else subB::work();
  }
  // cerr << 1. * clock() / CLOCKS_PER_SEC << endl;
}

// g++ run.cpp -o run -std=c++14 -O2 -static && ./run