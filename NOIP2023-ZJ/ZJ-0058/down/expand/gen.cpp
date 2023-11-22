#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

constexpr int maxn = 500010;
constexpr int maxv = 999999999;
mt19937 rnd(random_device{}());

int n, m, q, a[maxn], b[maxn];

int gen(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rnd);
}

int main() {
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  n = 500000, m = 500000, q = 60;
  rep (i, 1, n) a[i] = gen(0, maxv);
  rep (i, 1, m) b[i] = gen(a[i] + 1, maxv);
  cout << "0 " << n << " " << m << " " << q << "\n";
  rep (i, 1, n) cout << a[i] << " ";
  cout << "\n";
  rep (i, 1, m) cout << b[i] << " ";
  cout << "\n";
  while (q--) {
    int sum = 500000 / 60;
    int kx = gen(0, sum), ky = sum - kx;
    cout << kx << " " << ky << "\n";
    while (kx--) cout << 1 << " " << 1 << "\n";
    while (ky--) cout << 1 << " " << 114514<< "\n";
  }
}