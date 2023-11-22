#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

constexpr int maxn = 100010;

struct node {
  int ty; // 0: 变量 1: 确定值
  int val, op; // val: 确定的值或来源的变量 op: + or -
  // 确定值：1 true 0 unkown -1 false
  node() {}
  node(int x) { ty = 0, val = x, op = 1; }
  node(int a, int b, int c) { ty = a, val = b, op = c; }
} a[maxn];

int n, m, col[maxn], ban[maxn];
vector<pii> e[maxn];

void dfs(int u, int c) {
  if (col[u] == -1) return ban[u] = 1, void();
  if (col[u] != -2) {
    if (col[u] == c) return;
    return ban[u] = 1, col[u] = -1, void();
  }
  col[u] = c;
  for (pii nxt : e[u]) {
    int v = nxt.first, w = nxt.second;
    dfs(v, c ^ w);
  }
}

void paint(int u) {
  if (ban[u]) return;
  ban[u] = 1;
  for (pii nxt : e[u]) paint(nxt.first);
}

void work() {
  cin >> n >> m;
  rep (i, 1, n) a[i] = node(i);
  while (m--) {
    char ch;
    int x, y;
    cin >> ch;
    while (!isupper(ch) && ch != '-' && ch != '+') cin >> ch;
    if (ch == 'T') {
      cin >> x, a[x] = node(1, 1, 1);
    } else if (ch == 'F') {
      cin >> x, a[x] = node(1, -1, 1);
    } else if (ch == 'U') {
      cin >> x, a[x] = node(1, 0, 1);
    } else if (ch == '+') {
      cin >> x >> y, a[x] = a[y];
    } else if (ch == '-') {
      cin >> x >> y, a[x] = a[y];
      if (a[x].ty == 0) a[x].op = -a[x].op;
      else a[x].val = -a[x].val;
    }
  }
  rep (i, 1, n) col[i] = -2, ban[i] = 0, e[i].clear();
  rep (i, 1, n) if (a[i].ty == 0) {
    if (a[i].op == 1) e[a[i].val].emplace_back(i, 0), e[i].emplace_back(a[i].val, 0);
    else e[a[i].val].emplace_back(i, 1), e[i].emplace_back(a[i].val, 1);
  }
  rep (i, 1, n) if (a[i].ty == 1) {
    if (a[i].val == 0) ban[i] = 1, col[i] = -1;
    else dfs(i, a[i].val == 1 ? 1 : 0);
  }
  rep (i, 1, n) if (col[i] == -2) dfs(i, 0);
  rep (i, 1, n) if (ban[i]) {
    for (pii nxt : e[i]) paint(nxt.first);
  }
  int ans = 0;
  rep (i, 1, n) if (ban[i]) ans++;
  cout << ans << '\n';
}

int main() {
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  int sid, t;
  cin >> sid >> t;
  while (t--) work();
}

// g++ tribool.cpp -o tribool -O2 -std=c++14 -static && ./tribool