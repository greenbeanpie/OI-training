#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 1e5 + 10;
constexpr ll inf = 1e18;

int n, m, k, d;
ll f[maxn][2], t[maxn];
struct C {
  int l, r;
  ll v;
} a[maxn];

void add(int x, ll v) {
  for (int i = x; i <= n; i += i & -i) t[i] += v;
}
ll sum(int x) {
  ll res = 0;
  for (int i = x; i; i -= i & -i) res += t[i];
  return res;
}

void solve() {
  cin >> n >> m >> k >> d;
  for (int i = 0; i <= n; ++i) t[i] = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].r >> a[i].l >> a[i].v;
    a[i].l = a[i].r - a[i].l + 1;
    add(a[i].r, a[i].v);
  }
  for (int i = 1; i <= n; ++i) add(i, -d);
  sort(a + 1, a + 1 + m, [](C x, C y) {
    return x.l < y.l;
  });
  for (int i = 0; i <= n; ++i) f[i][0] = f[i][1] = -inf;
  f[0][0] = 0;
  int p = 1;
  for (int i = 0; i < n; ++i) {
    f[i + 1][0] = max(f[i][0], f[i][1]);
    while (p <= m && a[p].l <= i) add(a[p].r, -a[p].v), ++p;
    for (int j = i + 1; j <= min(n, i + k); ++j) f[j][1] = max(f[j][1], f[i][0] + sum(j));
    add(i + 1, d);
  }
  cout << max(f[n][0], f[n][1]) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  int c, t; cin >> c >> t;
  while (t--) solve();
}