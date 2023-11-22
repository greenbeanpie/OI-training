#include <bits/stdc++.h>
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define eb emplace_back
#define all(x) x.begin(), x.end()
FILE *fin, *fout, *ferr;
template<typename T>
T read() {
  T x = 0, f = 0;
  char ch = fgetc(fin);
  for (; !isdigit(ch); ch = fgetc(fin)) f |= (ch == '-');
  for (; isdigit(ch); ch = fgetc(fin)) x = (x * 10) + (ch - '0');
  return f ? -x : x;
}
struct Solution {
  static const i32 N = 100005;
  i32 c;
  i32 n, m, k, d, cnt;
  long long ans, now;
  bool run[N];
  i32 l[N], r[N], v[N];
  void dfs(i32 x) {
    if (x == n + 1) {
      long long add = 0;
      for (i32 i = 1; i <= m; ++i) {
        bool flag = true;
        for (i32 j = l[i]; j <= r[i]; ++j) flag &= run[j];
        if (flag) add += v[i];
      }
      ans = std::max(ans, now + add);
      return void();
    }
    i32 lst = cnt;
    run[x] = 0;
    cnt = 0;
    dfs(x + 1);
    cnt = lst;
    if (cnt < k) {
      run[x] = 1;
      now -= d, ++cnt;
      dfs(x + 1);
      now += d, --cnt;
    }
    return void();
  }
  void solve() {
    n = read<i32>(), m = read<i32>(), k = read<i32>(), d = read<i32>();
    for (i32 i = 1; i <= m; ++i) {
      static i32 ed, lon;
      ed = read<i32>(), lon = read<i32>();
      r[i] = ed, l[i] = ed - lon + 1;
      v[i] = read<i32>();
    }
    ans = 0;
    now = 0, cnt = 0;
    for (i32 i = 1; i <= n; ++i) run[i] = 0;
    dfs(1);
    fprintf(fout, "%lld\n", ans);
    return void();
  }
  void main() {
    fin = stdin, fout = stdout, ferr = stderr;
    fin = fopen("run.in", "r");
    fout = fopen("run.out", "w");
    c = read<i32>();
    i32 t = read<i32>();
    while (t--) solve();
    return void();
  }
  /*
  g++ run.cpp -o run -lm -O2 -std=c++14 -Wall -static
  ./run
  */
} t;
signed main() {
  // std::cerr << sizeof(t) / 1024 / 1024 << "MB" << std::endl;
  return t.main(), 0;
}