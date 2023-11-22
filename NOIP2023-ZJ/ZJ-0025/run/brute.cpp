#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 1e5 + 10, maxm = 100 * maxn;
constexpr ll inf = 1e18;

int n, m, k, d;
ll f[maxn][2];
struct C {
  int l, r;
  ll v;
} a[maxn];
struct N {
  int lc, rc;
  ll v;
} t[maxm];
int tot, rt[maxn];

#define mid (l + r >> 1)

void up(int x) { t[x].v = t[t[x].lc].v + t[t[x].rc].v; }
int copynode(int x) {
  ++tot; t[tot] = t[x];
  return tot;
}

void upd(int &x, int l, int r, int a, ll v) {
  x = copynode(x);
  if (l == r) return t[x].v += v, void();
  if (a <= mid) upd(t[x].lc, l, mid, a, v);
  if (a > mid) upd(t[x].rc, mid + 1, r, a, v);
  up(x);
}
ll qry(int x, int l, int r, int a, int b) {
  if (a > r || l > b || !x) return 0;
  if (a <= l && r <= b) return t[x].v;
  return qry(t[x].lc, l, mid, a, b) + qry(t[x].rc, mid + 1, r, a, b);
}

#undef mid

ll cost(int l, int r) {
  return qry(rt[l], 1, n, 1, r);
}

void solve() {
  cin >> n >> m >> k >> d; tot = 0; rt[n + 1] = 0;
  for (int i = 1; i <= n; ++i) rt[i] = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].r >> a[i].l >> a[i].v;
    a[i].l = a[i].r - a[i].l + 1;
  }
  sort(a + 1, a + 1 + m, [](C x, C y) {
    return x.l > y.l;
  });
  int p = 1;
  for (int i = 1; i <= n; ++i) {
    rt[i] = rt[i + 1];
    while (p <= m && a[p].l >= i) upd(rt[i], 1, n, a[p].r, a[p].v), ++p;
    upd(rt[i], 1, n, i, -d);
  }
  for (int i = 0; i <= n; ++i) f[i][0] = f[i][1] = -inf;
  f[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    f[i + 1][0] = max(f[i][0], f[i][1]);
    for (int j = i + 1; j <= min(n, i + k); ++j) f[j][1] = max(f[j][1], f[i][0] + cost(i + 1, j)), cerr << i + 1 << ' ' << j << ": " << cost(i + 1, j) << '\n';
  }
  cout << max(f[n][0], f[n][1]) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen("run.in", "r", stdin);
  // freopen("run.out", "w", stdout);
  int c, t; cin >> c >> t;
  while (t--) solve();
}
