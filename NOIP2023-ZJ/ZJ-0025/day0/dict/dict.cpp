#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

constexpr int maxn = 3010;
constexpr ull base = 19260817;

string s[maxn][2];
int n, m, res[maxn], vis[maxn];
pair<int, int> id[maxn * 2];
ull hsh[maxn][2][maxn];
int tax[30];

string srt(string s) {
  for (int i = 0; i < s.size(); ++i) ++tax[s[i] - 'a'];
  string res = "";
  for (int i = 0; i < 26; ++i) {
    while (tax[i]--) res += char(i + 'a');
    tax[i] = 0;
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  // cerr << srt("abandon");
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i][0];
    s[i][1] = s[i][0] = srt(s[i][0]);
    reverse(s[i][1].begin(), s[i][1].end());
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 1; k <= m; ++k) hsh[i][j][k] = hsh[i][j][k - 1] * base + s[i][j][k - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    id[i * 2 - 1] = {i, 0};
    id[i * 2] = {i, 1};
  }
  sort(id + 1, id + 1 + n * 2, [&](pair<int, int> x, pair<int, int> y) {
    if (hsh[x.first][x.second][m] == hsh[y.first][y.second][m]) return x.second < y.second;
    int l = 0, r = m - 1;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (hsh[x.first][x.second][mid] == hsh[y.first][y.second][mid]) l = mid;
      else r = mid - 1;
    }
    return s[x.first][x.second][l] > s[y.first][y.second][l];
  });
  int cnt = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    if (id[i].second == 1) ++cnt, vis[id[i].first] = 1;
    else res[id[i].first] = cnt - vis[id[i].first] == n - 1;
  }
  for (int i = 1; i <= n; ++i) cout << res[i];
  cout << '\n';
}