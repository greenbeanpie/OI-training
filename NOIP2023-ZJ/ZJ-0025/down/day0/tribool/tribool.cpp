#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 10;

int val[maxn], col[maxn], n, m, sz;
vector<pair<int, int>> ed[maxn];
bool f;

void dfs(int x) {
  ++sz;
  for (auto e : ed[x]) {
    int y = e.first, c;
    if (e.second) c = 3 - col[x];
    else c = col[x];
    if (col[y]) {
      f |= col[y] != c;
    } else {
      col[y] = c;
      dfs(y);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i <= n + 1; ++i) col[i] = 0, ed[i].clear();
  for (int i = 1; i <= n; ++i) val[i] = i + 1;
  for (int i = 1; i <= m; ++i) {
    char op; cin >> op;
    if (op == '+') {
      int x, y; cin >> x >> y; val[x] = val[y];
    } else if (op == '-') {
      int x, y; cin >> x >> y; val[x] = -val[y];
    } else if (op == 'T') {
      int x; cin >> x; val[x] = 1;
    } else if (op == 'F') {
      int x; cin >> x; val[x] = -1;
    } else if (op == 'U') {
      int x; cin >> x; val[x] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (val[i] >= 0) ed[i + 1].emplace_back(val[i], 0), ed[val[i]].emplace_back(i + 1, 0);
    else ed[i + 1].emplace_back(-val[i], 1), ed[-val[i]].emplace_back(i + 1, 1);
  }
  ed[0].emplace_back(0, 1);
  int ans = 0;
  for (int i = 0; i <= n + 1; ++i) if (!col[i]) {
    col[i] = 1, sz = 0, f = 0;
    dfs(i);
    if (f) ans += sz;
  }
  cout << ans - 1 << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  int c, t; cin >> c >> t;
  while (t--) solve();
}