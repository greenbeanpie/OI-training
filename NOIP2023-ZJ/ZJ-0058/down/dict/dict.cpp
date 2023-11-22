#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

constexpr int maxn = 3010;
mt19937 rnd(random_device{}());

int n, m, cnt[maxn][26], l[maxn], r[maxn], p[maxn];
string str;

bool check(int x, int y) {
  // x 正序是否比 y 倒序的字典序小
  int i = l[x], j = r[y];
  while (j >= 0 && !cnt[y][j]) j--;
  if (i > j) return 0;
  if (i < j) return 1;
  if (cnt[x][i] != cnt[y][j]) return 0;
  return 0;
}

int main() {
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n >> m;
  rep (i, 1, n) {
    cin >> str, l[i] = 25, r[i] = 0;
    for (char ch : str) l[i] = min(l[i], ch - 'a'), r[i] = max(r[i], ch - 'a');
    for (char ch : str) cnt[i][ch - 'a'] += 1;
  }
  rep (i, 1, n) p[i] = i;
  shuffle(p + 1, p + n + 1, rnd);
  rep (i, 1, n) {
    bool ok = 1;
    rep (j, 1, n) if (p[j] != i) {
      ok &= check(i, p[j]);
      if (!ok) break;
    }
    cout << (ok ? 1 : 0);
  }
  cout << '\n';
}

// g++ dict.cpp -o dict -O2 -std=c++14 -static && ./dict