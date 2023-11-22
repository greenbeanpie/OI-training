#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

namespace sol {

constexpr int maxn = 500010;

int n, m, q, sid, a[maxn], b[maxn], ta[maxn], tb[maxn];
int mn[maxn << 2], mx[maxn << 2];

#define mid ((l + r) >> 1)

void build(int c, int l, int r) {
  if (l == r) return mn[c] = mx[c] = b[l], void();
  build(c << 1, l, mid), build(c << 1 | 1, mid + 1, r);
  mn[c] = min(mn[c << 1], mn[c << 1 | 1]);
  mx[c] = max(mx[c << 1], mx[c << 1 | 1]);
}

int presmall(int c, int l, int r, int x, int v) {
  if (mn[c] > v || l > x) return -1;
  if (l == r) return l;
  int res = presmall(c << 1 | 1, mid + 1, r, x, v);
  if (res != -1) return res;
  return presmall(c << 1, l, mid, x, v);
}

int prebig(int c, int l, int r, int x, int v) {
  if (mx[c] < v || l > x) return -1;
  if (l == r) return l;
  int res = prebig(c << 1 | 1, mid + 1, r, x, v);
  if (res != -1) return res;
  return prebig(c << 1, l, mid, x, v);
}

int sufsmall(int c, int l, int r, int x, int v) {
  if (mn[c] > v || r < x) return -1;
  if (l == r) return l;
  int res = sufsmall(c << 1, l, mid, x, v);
  if (res != -1) return res;
  return sufsmall(c << 1 | 1, mid + 1, r, x, v);
}

int sufbig(int c, int l, int r, int x, int v) {
  if (mx[c] < v || r < x) return -1;
  if (l == r) return l;
  int res = sufbig(c << 1, l, mid, x, v);
  if (res != -1) return res;
  return sufbig(c << 1 | 1, mid + 1, r, x, v);
}

#undef mid

int solve() {
  if (a[1] == b[1] || a[n] == b[m]) return 0;
  build(1, 1, m);
  if (a[1] < b[1]) {
    if (a[n] >= b[m]) return 0;
    int pos = m;
    per (i, n, 1) {
      if (a[i] < b[pos]) {
        int res = presmall(1, 1, m, pos, a[i]);
        if (res == -1) pos = 1;
        else pos = res + 1;
      } else {
        int res = sufbig(1, 1, m, pos, a[i] + 1);
        if (res == -1) return 0;
        pos = res;
      }
    }
    return pos == 1;
  }
  if (a[1] > b[1]) {
    if (a[n] <= b[m]) return 0;
    int pos = m;
    per (i, n, 1) {
      if (a[i] > b[pos]) {
        int res = prebig(1, 1, m, pos, a[i]);
        if (res == -1) pos = 1;
        else pos = res + 1;
      } else {
        int res = sufsmall(1, 1, m, pos, a[i] - 1);
        if (res == -1) return 0;
        pos = res;
      }
    }
    return pos == 1;
  }
  return 0;
}

void work() {
  cin >> n >> m >> q;
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

}

namespace brute {

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

void work() {
  cin >> n >> m >> q;
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

}

int main() {
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  int sid;
  cin >> sid;
  if (sid <= 7) brute::work();
  else sol::work();
}

// g++ expand.cpp -o expand -O2 -std=c++14 -static && ./expand