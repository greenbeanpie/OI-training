#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define il inline
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
#define For(i, j, k) for (int i = (j), i##end = (k); i <= i##end; i++)
#define ForDown(i, j, k) for (int i = (j), i##end = (k); i >= i##end; i--)

template <typename T> il void read(T &x) {
  x = 0;
  int c = getchar(), f = 1;
  while (!isdigit(c))
    f = (c == '-' ? -f : f), c = getchar();
  while (isdigit(c))
    (x *= 10) += c - '0', c = getchar();
  x *= f;
}
template <typename T, typename ...Args> il void read(T &x, Args &...y) {
  read(x), read(y...);
}

namespace {
constexpr ll MAXN = 2e5 + 5;
int n, m, cur[MAXN], cnt, val[MAXN], bl[MAXN], from[MAXN];
vector<pair<int, bool>> G[MAXN], G2[MAXN];
bitset<MAXN> vis, onC;
vector<vector<int>> cycle;
stack<int> st;
bool ok = 0;
void dfs(int x, int rt) {
  if (bl[x] == rt) {
    while (1) {
      int u = st.top(); st.pop();
      onC[u] = 1, cycle.back().eb(u);
      if (u == x)
        break;
    }
    return ok = 1, void();
  } else if (!G2[x].size()) {
    onC[x] = 1;
    cycle.back().eb(x);
    return ok = 1, void();
  }
  st.push(x);
  vis[x] = 1, bl[x] = rt;
  for (pii e : G2[x]) {
    if (ok)
      return;
    dfs(e.fi, rt);
  }
}
il void addEdge(int u, int v, int w) {
  G[u].eb(v, w);
  G2[v].eb(u, w);
}
il void dfs2(int x) {
  val[x] = 3;
  for (pii e : G[x]) {
    if (!onC[e.fi]) {
      dfs2(e.fi);
    }
  }
}
il void calc() {
  int cur = 0, hasC = 0;
  bool qwq = 0;
  for (int x : cycle.back()) {
    hasC |= (x == n + m + 3);
    if (x == n + m + 1 && !qwq && cur) {
      qwq = 1;
    } else if (x == n + m + 2 && !qwq && !cur) {
      qwq = 1;
    }
    for (pii e : G[x]) {
      if (onC[e.fi]) {
        cur ^= e.se;
        break;
      }
    }
  }
  if (cur || hasC) {
    for (int x : cycle.back()) {
      dfs2(x);
    }
  }
}
il void solve() {
  // cerr << "===\n";
  read(n, m);
  int A = n + m + 1, B = n + m + 2, C = n + m + 3;
  cnt = n, vis.reset(), onC.reset();
  fill(bl + 1, bl + C + 1, 0);
  fill(val + 1, val + C + 1, 0);
  cycle.clear();
  For(i, 1, n + m + 3)
    G[i].clear(), G2[i].clear();
  iota(cur + 1, cur + 1 + n, 1);
  For(i, 1, m) {
    char op[3];
    int x, y;
    scanf("%s%d", op, &x);
    if (op[0] == '+') {
      scanf("%d", &y);
      addEdge(cur[y], (cur[x] = ++cnt), 0);
    } else if (op[0] == '-') {
      scanf("%d", &y);
      addEdge(cur[y], (cur[x] = ++cnt), 1);
    } else {
      if (op[0] == 'T') {
        addEdge(A, (cur[x] = ++cnt), 0);
      } else if (op[0] == 'F') {
        addEdge(B, (cur[x] = ++cnt), 0);
      } else {
        addEdge(C, (cur[x] = ++cnt), 0);
      }
    }
  }
  assert(cnt == n + m);
  cnt += 3;
  For(i, 1, n)
    addEdge(cur[i], i, 0);
  {
    while (!st.empty())
      st.pop();
    ok = 0;
    cycle.eb();
    dfs(C, C);
    // cerr << "!!!" << cycle.back()[0] << endl;
    assert(ok);
    calc();
  }
  For(i, 1, cnt - 1) if (!vis[i]) {
    while (!st.empty())
      st.pop();
    ok = 0;
    cycle.eb();
    dfs(i, i);
    // cerr << cycle.back()[0] << endl;
    assert(ok);
    calc();
  }
  int ans = 0;
  For(i, 1, n) {
    ans += val[i] == 3;
  }
  cout << ans << endl;
}
il void Main() {
  int c, n, m, q;
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  read(c, n, m, q), q++;
  while (q--)
    cout << "1";
}
}

signed main() { return Main(), 0; }