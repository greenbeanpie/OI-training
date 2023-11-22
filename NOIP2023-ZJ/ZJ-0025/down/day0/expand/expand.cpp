#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2010, maxm = 2e6 + 10;

int c, n, m, q, a[maxn], b[maxn], rea[maxn], reb[maxn], tax[maxm], tot;
vector<pair<int, int>> opa[100], opb[100];
bool f[maxn][maxn];

int sign(int x) {
  if (x == 0) return 0;
  if (x > 0) return 1;
  return -1;
}

void solve() {
  int cur = sign(a[1] - b[1]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = 0;
    }
  }
  f[1][1] = cur != 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i < n && cur * sign(a[i + 1] - b[j]) > 0) f[i + 1][j] |= f[i][j];
      if (j < m && cur * sign(a[i] - b[j + 1]) > 0) f[i][j + 1] |= f[i][j];
    }
  }
  cout << f[n][m];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  cin >> c >> n >> m >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i], tax[++tot] = a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i], tax[++tot] = b[i];
  for (int i = 1; i <= q; ++i) {
    int ka, kb; cin >> ka >> kb;
    for (int j = 1; j <= ka; ++j) {
      int x, y; cin >> x >> y, tax[++tot] = y;
      opa[i].emplace_back(x, y);
    }
    for (int j = 1; j <= kb; ++j) {
      int x, y; cin >> x >> y, tax[++tot] = y;
      opb[i].emplace_back(x, y);
    }
  }
  sort(tax + 1, tax + 1 + tot);
  tot = unique(tax + 1, tax + 1 + tot) - tax - 1;
  for (int i = 1; i <= n; ++i) rea[i] = a[i] = lower_bound(tax + 1, tax + 1 + tot, a[i]) - tax;
  for (int i = 1; i <= m; ++i) reb[i] = b[i] = lower_bound(tax + 1, tax + 1 + tot, b[i]) - tax;
  for (int i = 1; i <= q; ++i) {
    for (auto &e : opa[i]) e.second = lower_bound(tax + 1, tax + 1 + tot, e.second) - tax;
    for (auto &e : opb[i]) e.second = lower_bound(tax + 1, tax + 1 + tot, e.second) - tax;
  }
  solve();
  for (int i = 1; i <= q; ++i) {
    for (int i = 1; i <= n; ++i) a[i] = rea[i];
    for (int i = 1; i <= m; ++i) b[i] = reb[i];
    for (auto e : opa[i]) a[e.first] = e.second;
    for (auto e : opb[i]) b[e.first] = e.second;
    solve();
  }
  cout << '\n';
}