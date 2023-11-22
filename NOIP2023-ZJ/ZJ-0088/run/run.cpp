#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = std::numeric_limits<i64>::max() / 2;

signed main() {
  std::ifstream fin("run.in");
  std::ofstream fout("run.out");

  int id, tt;
  fin >> id >> tt;

  while (tt--) {
    int n, m, k, d;
    fin >> n >> m >> k >> d;

    std::vector<std::vector<std::pair<i64, i64>>> th(n + 1);

    for (int i = 0; i < m; ++i) {
      int l, r, w;
      fin >> l >> r >> w;
      th[l].emplace_back(r, w);
    }

    std::vector<std::vector<i64>> f(n + 1, std::vector<i64>(k + 1, -INF));
    f[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        if (f[i - 1][j] == -INF) {
          continue;
        }

        if (j < k) {
          f[i][j + 1] = std::max(f[i][j + 1], f[i - 1][j] - d);
        }

        f[i][0] = std::max(f[i][0], f[i - 1][j]);
      }

      for (auto [l, w] : th[i]) {
        for (int j = l; j <= k; ++j) {
          if (f[i][j] != -INF) {
            f[i][j] += w;
          }
        }
      }
    }

    fout << *std::max_element(f[n].begin(), f[n].end()) << '\n';
  }
}