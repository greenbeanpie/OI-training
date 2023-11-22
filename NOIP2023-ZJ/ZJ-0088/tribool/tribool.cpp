#include <bits/stdc++.h>

class dsu {
private:
  std::vector<int> fa;

  int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
  }

public:
  dsu(int n) : fa(n) {
    std::iota(fa.begin(), fa.end(), 0);
  }

  void merge(int u, int v) {
    int fu = get(u), fv = get(v);
    fa[fu] = fv;
  }

  int find(int u) {
    return get(u);
  }

  int query(int u, int v) {
    return get(u) == get(v);
  }
};

signed main() {
  std::ifstream fin("tribool.in");
  std::ofstream fout("tribool.out");

  int id, tt;
  fin >> id >> tt;

  while (tt--) {
    int n, m;
    fin >> n >> m;

    std::vector<std::pair<int, int>> a(n);

    for (int i = 0; i < n; ++i) {
      a[i] = {i, 0};
    }

    for (int i = 0; i < m; ++i) {
      char ch;
      int x, y;
      fin >> ch;

      if (ch == 'F') {
        fin >> x;
        --x;
        a[x] = {0, -1};
      }

      if (ch == 'T') {
        fin >> x;
        --x;
        a[x] = {1, -1};
      }

      if (ch == 'U') {
        fin >> x;
        --x;
        a[x] = {2, -1};
      }

      if (ch == '+') {
        fin >> x >> y;
        --x;
        --y;
        a[x] = a[y];
      }

      if (ch == '-') {
        fin >> x >> y;
        --x;
        --y;
        
        if (a[y].second == -1) {
          a[x].first = a[y].first < 2 ? a[y].first ^ 1 : 2;
          a[x].second = -1;
        } else {
          a[x].first = a[y].first;
          a[x].second = a[y].second ^ 1;
        }
      }
    }

    dsu T(n * 2);
    std::vector<int> col(n, -1);

    for (int i = 0; i < n; ++i) {
      if (a[i].second == -1) {
        col[i] = a[i].first;
      } else {
        if (a[i].second == 0) {
          T.merge(i, a[i].first);
          T.merge(i + n, a[i].first + n);
        } else {
          T.merge(i, a[i].first + n);
          T.merge(i + n, a[i].first);
        }
      }
    }

    std::vector<int> ban(n * 2);

    for (int i = 0; i < n; ++i) {
      if (col[i] == 2 || T.query(i, i + n)) {
        ban[T.find(i)] = 1;
        ban[T.find(i + n)] = 1;
      }
    }

    int res = 0;

    for (int i = 0; i < n; ++i) {
      if (col[i] != -1) {
        res += col[i] == 2;
      } else {
        res += ban[T.find(i)];
      }
    }

    fout << res << '\n';
  }
}