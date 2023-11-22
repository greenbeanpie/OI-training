#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

constexpr int maxn = 2010;

int n, m, q, sid, a[maxn], b[maxn], ta[maxn], tb[maxn];
bool f[maxn][maxn];

int solve() {
  rep (i, 1, n) rep (j, 1, m) f[i][j] = 0;
  if (a[1] == b[1]) return 0;
  if (a[1] > b[1]) {
    rep (j, 1, m) {
      if (a[1] <= b[j]) break;
      f[1][j] = 1;
    }
    rep (i, 2, n) {
      rep (j, 1, m) if (f[i - 1][j]) {
        if (a[i] > b[j]) f[i][j] = 1;
        if (j < m && a[i] > b[j + 1]) f[i][j + 1] = 1;
      }
      rep (j, 1, m) if (a[i] > b[j]) f[i][j] |= f[i][j - 1];
    }
    return f[n][m];
  } else {
    rep (j, 1, m) {
      if (a[1] >= b[j]) break;
      f[1][j] = 1;
    }
    rep (i, 2, n) {
      rep (j, 1, m) if (f[i - 1][j]) {
        if (a[i] < b[j]) f[i][j] = 1;
        if (j < m && a[i] < b[j + 1]) f[i][j + 1] = 1;
      }
      rep (j, 1, m) if (a[i] < b[j]) f[i][j] |= f[i][j - 1];
    }
    return f[n][m];
  }
}

int main() {
  // freopen("expand.in", "r", stdin);
  // freopen("expand.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> sid >> n >> m >> q;
  rep (i, 1, n) cin >> a[i], ta[i] = a[i];
  rep (i, 1, m) cin >> b[i], tb[i] = b[i];
  cout << solve();
  while (q--) {
    int kx, ky, x, y;
    cin >> kx >> ky;
    rep (i, 1, n) a[i] = ta[i];
    rep (i, 1, m) b[i] = tb[i];
    while (kx--) cin >> x >> y, a[x] = y;
    while (ky--) cin >> x >> y, b[x] = y;
    cout << solve();
  }
  cout << '\n';
}

// g++ brute.cpp -o brute -O2 -std=c++14 -static && ./brute