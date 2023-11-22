#include <bits/stdc++.h>

signed main() {
  std::ifstream fin("expand.in");
  std::ofstream fout("expand.out");

  int id, n, m, q;
  fin >> id >> n >> m >> q;

  std::vector<int> a(n), b(m), A(n), B(m), val;

  for (int i = 0; i < n; ++i) {
    fin >> a[i];
    A[i] = a[i];
    val.emplace_back(a[i]);
  }

  for (int i = 0; i < m; ++i) {
    fin >> b[i];
    B[i] = b[i];
    val.emplace_back(b[i]);
  }

  std::vector<int> ka(q), kb(q);
  std::vector<std::vector<std::tuple<int, int, int>>> modifya(q), modifyb(q);

  for (int i = 0; i < q; ++i) {
    fin >> ka[i] >> kb[i];
    modifya[i].resize(ka[i]);
    modifyb[i].resize(kb[i]);

    for (auto &[x, v, t] : modifya[i]) {
      fin >> x >> v;
      --x;
      val.emplace_back(v);
    }
    
    for (auto &[x, v, t] : modifyb[i]) {
      fin >> x >> v;
      --x;
      val.emplace_back(v);
    }
  }

  std::sort(val.begin(), val.end());
  val.erase(std::unique(val.begin(), val.end()), val.end());

  std::vector<int> posa(n), posb(m), posA(n), posB(m);

  for (int i = 0; i < n; ++i) {
    posa[i] = posA[i] = std::lower_bound(val.begin(), val.end(), a[i]) - val.begin();
  }

  for (int i = 0; i < m; ++i) {
    posb[i] = posB[i] = std::lower_bound(val.begin(), val.end(), b[i]) - val.begin();
  }

  for (int i = 0; i < q; ++i) {
    for (auto &[x, v, t] : modifya[i]) {
      t = std::lower_bound(val.begin(), val.end(), v) - val.begin();
    }

    for (auto &[x, v, t] : modifyb[i]) {
      t = std::lower_bound(val.begin(), val.end(), v) - val.begin();
    }
  }

  std::vector<int> preb(m), sufb(m), minb(val.size()), maxb(val.size());

  auto solve = [&]() {
    bool ok = true, ok1 = true;
    int Mina = *std::min_element(a.begin(), a.end()), Maxa = *std::max_element(a.begin(), a.end());
    int Minb = *std::min_element(b.begin(), b.end()), Maxb = *std::max_element(b.begin(), b.end());

    if (Mina <= Minb || Maxb >= Maxa) {
      ok = false;
    }

    if (Mina >= Minb || Maxb <= Maxa) {
      ok1 = false;
    }

    std::fill(minb.begin(), minb.end(), m);
    std::fill(maxb.begin(), maxb.end(), -1);

    for (int i = 0; i < m; ++i) {
      preb[i] = i == 0 ? b[i] : std::max(preb[i - 1], b[i]);
      minb[posb[i]] = std::min(minb[posb[i]], i);
      maxb[posb[i]] = std::max(maxb[posb[i]], i);
    }

    for (int i = m - 1; i >= 0; --i) {
      sufb[i] = i == m - 1 ? b[i] : std::max(sufb[i + 1], b[i]);
    }

    for (int i = 1; i < (int)val.size(); ++i) {
      minb[i] = std::min(minb[i], minb[i - 1]);
      maxb[i] = std::max(maxb[i], maxb[i - 1]);
    }

    int premax = 0;

    for (int i = 0; i < n && ok; ++i) {
      premax = std::max(premax, a[i]);
      int j = posa[i] == 0 ? m - 1 : minb[posa[i] - 1] - 1;

      if (j >= 0 && premax <= preb[j]) {
        ok = false;
        break;
      }
    }

    premax = 0;

    for (int i = n - 1; i >= 0 && ok; --i) {
      premax = std::max(premax, a[i]);
      int j = posa[i] == 0 ? 0 : maxb[posa[i] - 1] + 1;

      if (j < m && premax <= sufb[j]) {
        ok = false;
        break;
      }
    }

    //-------------------------------------------------------
    std::fill(minb.begin(), minb.end(), m);
    std::fill(maxb.begin(), maxb.end(), -1);

    for (int i = 0; i < m; ++i) {
      preb[i] = i == 0 ? b[i] : std::min(preb[i - 1], b[i]);
      minb[posb[i]] = std::min(minb[posb[i]], i);
      maxb[posb[i]] = std::max(maxb[posb[i]], i);
    }

    for (int i = m - 1; i >= 0; --i) {
      sufb[i] = i == m - 1 ? b[i] : std::min(sufb[i + 1], b[i]);
    }

    for (int i = (int)val.size() - 2; i >= 0; --i) {
      minb[i] = std::min(minb[i], minb[i + 1]);
      maxb[i] = std::max(maxb[i], maxb[i + 1]);
    }

    int premin = -1;

    for (int i = 0; i < n && ok1; ++i) {
      premin = premin == -1 ? a[i] : std::min(premin, a[i]);
      int j = posa[i] == (int)val.size() - 1 ? m - 1 : minb[posa[i] + 1] - 1;

      if (j >= 0 && premin >= preb[j]) {
        ok1 = false;
        break;
      }
    }

    premin = -1;

    for (int i = n - 1; i >= 0 && ok1; --i) {
      premin = premin == -1 ? a[i] : std::min(premin, a[i]);
      int j = posa[i] == (int)val.size() - 1 ? 0 : maxb[posa[i] + 1] + 1;

      if (j < m && premin >= sufb[j]) {
        ok1 = false;
        break;
      }
    }

    return ok || ok1;
  };

  fout << solve();

  for (int i = 0; i < q; ++i) {
    for (auto [x, v, t] : modifya[i]) {
      a[x] = v;
      posa[x] = t;
    }

    for (auto [x, v, t] : modifyb[i]) {
      b[x] = v;
      posb[x] = t;
    }

    fout << solve();

    for (auto [x, v, t] : modifya[i]) {
      a[x] = A[x];
      posa[x] = posA[x];
    }

    for (auto [x, v, t] : modifyb[i]) {
      b[x] = B[x];
      posb[x] = posB[x];
    }
  }
}