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
constexpr ll MAXN = 3005;
int n, m;
char str[MAXN][MAXN];
int ch[MAXN * MAXN][26], sz[MAXN * MAXN], idx[MAXN * MAXN], cnt = 0;
il void ins(int id, const char * s) {
  int p = 0;
  For(i, 1, m) {
    // cerr << s[i] << "\n";
    if (!ch[p][s[i] - 'a'])
      ch[p][s[i] - 'a'] = ++cnt, idx[cnt] = id;
    p = ch[p][s[i] - 'a'];
    sz[p]++;
  }
}
il bool qry(int id) {
  int p = 0;
  ForDown(i, m, 1) {
    // cerr << id << ' ' << i << ' ' << str[id][i] << endl;
    For(j, 0, str[id][i] - 'a' - 1) {
      if (sz[ch[p][j]] > 1 || (sz[ch[p][j]] == 1 && idx[ch[p][j]] != id))
        return 0;
    }
    p = ch[p][str[id][i] - 'a'];
    if (!p)
      return 1;
  }
  if (sz[p] > 1)
    return 0;
  return 1;
}

il void Main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);

  read(n, m);
  For(i, 1, n) scanf("%s", str[i] + 1);

  if (n == 1)
    return puts("1"), void();

  For(i, 1, n) sort(str[i] + 1, str[i] + 1 + m, greater<>());
  For(i, 1, n) ins(i, str[i]);
  For(i, 1, n) putchar(qry(i) + '0');
}
}

signed main() { return Main(), 0; }