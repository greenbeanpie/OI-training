#include <bits/stdc++.h>

using u64 = unsigned long long;
constexpr int B = 13, B1 = 19;

signed main() {
  std::ifstream fin("dict.in");
  std::ofstream fout("dict.out");

  int n, m;
  fin >> n >> m;

  std::vector<std::string> a(n);
  std::vector<std::vector<u64>> hash(n, std::vector<u64>(m)), hash1(n, std::vector<u64>(m));

  for (int i = 0; i < n; ++i) {
    fin >> a[i];
    std::sort(a[i].begin(), a[i].end(), std::greater<>());
    u64 x = 0, y = 0;

    for (int j = 0; j < m; ++j) {
      x = x * B + a[i][j];
      y = y * B1 + a[i][j];
      hash[i][j] = x;
      hash1[i][j] = y;
    }
  }

  std::vector<u64> tmp(m), tmp1(m);

  for (int i = 0; i < n; ++i) {
    auto st = a[i];
    std::sort(st.begin(), st.end());
    u64 x = 0, y = 0;

    for (int j = 0; j < m; ++j) {
      x = x * B + st[j];
      y = y * B1 + st[j];
      tmp[j] = x;
      tmp1[j] = y;
    }

    bool ok = true;

    for (int j = 0; j < n; ++j) {
      if (i != j) {
        int l = 0, r = m - 1, pos = m;

        while (l <= r) {
          auto check = [&](int r) {
            auto get = [&](int x, int r) {
              if (x == -1) {
                return tmp[r];
              }

              return hash[x][r];
            };

            auto get1 = [&](int x, int r) {
              if (x == -1) {
                return tmp1[r];
              }

              return hash1[x][r];
            };

            return get(-1, r) == get(j, r) && get1(-1, r) == get1(j, r);
          };

          int mid = (l + r) / 2;

          if (!check(mid)) {
            pos = mid;
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }

        if (pos == m || st[pos] > a[j][pos]) {
          ok = false;
          break;
        }
      }
    }

    fout << ok;
  }
}