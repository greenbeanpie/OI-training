#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010;
struct TBool {
  ll pre;
  bool isnot;
  char type;
  TBool() : pre(0), isnot(false), type(0) {}
  TBool(char v) : pre(0), isnot(false), type(v) {}
  TBool(ll x, bool c) : pre(x), isnot(c), type('V') {}
  TBool bar() {
    if (type == 'T') return TBool('F');
    if (type == 'F') return TBool('T');
    if (type == 'U') return TBool('U');
    return TBool(pre, !isnot);
  }
};
ll c, t;
ll n, m;
ll fa[MAXN * 2];
TBool lis[MAXN];
ll fd(ll x) {
  return fa[x] == x ? x : fa[x] = fd(fa[x]);
}
void init() {
  for (int i = 1; i <= n * 2 + 3; ++i) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    lis[i] = TBool(i, false);
  }
}
void merge(ll u, ll v) {
  ll fu = fd(u), fv = fd(v);
  if (fu != fv) fa[fu] = fv;
}
void solve() {
  char opt;
  ll u, v;
  cin >> n >> m;
  init();
  for (int i = 1; i <= m; ++i) {
    cin >> opt;
    if (opt == 'T' || opt == 'F' || opt == 'U') {
      cin >> u;
      lis[u] = TBool(opt);
    } else {
      cin >> u >> v;
      if (opt == '+')
        lis[u] = lis[v];
      else
        lis[u] = lis[v].bar();
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (lis[i].type == 'T') {
      merge(i, n * 2 + 1);
      merge(i + n, n * 2 + 2);
    } else if (lis[i].type == 'F') {
      merge(i, n * 2 + 2);
      merge(i + n, n * 2 + 1);
    } else if (lis[i].type == 'U') {
      merge(i, n * 2 + 3);
      merge(i + n, n * 2 + 3);
    } else {
      if (lis[i].isnot) {
        merge(i, lis[i].pre + n);
        merge(i + n, lis[i].pre);
      } else {
        merge(i + n, lis[i].pre + n);
        merge(i, lis[i].pre);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (fd(i) == fd(n * 2 + 3) || fd(i) == fd(i + n)) {
      ++ans;
    }
  }
  cout << ans << endl;
}
int main() {
#ifndef DEBUG
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin >> c >> t;
  while (t--) {
    solve();
  }
  return 0;
}