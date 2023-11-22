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
  static const i32 N = 500005, M = 2005;
  i32 c, n, m, q;
  i32 a[N], b[N], aa[N], bb[N];
  i32 f[M][M];
  bool solve(i32 *a, i32 *b, i32 n, i32 m) {
    f[1][1] = 1;
    for (i32 i = 1; i <= n; ++i)
      for (i32 j = 1; j <= m; ++j) {
        if (!(i == 1 && j == 1)) f[i][j] = 0;
        if (i > 1) f[i][j] |= f[i - 1][j];
        if (j > 1) f[i][j] |= f[i][j - 1];
        if (i > 1 && j > 1) f[i][j] |= f[i - 1][j - 1];
        if (1LL * (a[i] - b[j]) * (a[1] - b[1]) <= 0) f[i][j] = 0;
      }
    return f[n][m];
  }
  void main() {
    fin = stdin, fout = stdout, ferr = stderr;
    fin = fopen("expand.in", "r");
    fout = fopen("expand.out", "w");
    c = read<i32>(), n = read<i32>(), m = read<i32>(), q = read<i32>();
    for (i32 i = 1; i <= n; ++i) a[i] = read<i32>();
    for (i32 i = 1; i <= m; ++i) b[i] = read<i32>();
    fputc(solve(a, b, n, m) ? '1' : '0', fout);
    while (q--) {
      i32 len1 = read<i32>(), len2 = read<i32>();
      for (i32 i = 1; i <= n; ++i) aa[i] = a[i];
      for (i32 i = 1; i <= m; ++i) bb[i] = b[i];
      for (i32 i = 1; i <= len1; ++i) {
        i32 p = read<i32>(), v = read<i32>();
        aa[p] = v;
      }
      for (i32 i = 1; i <= len2; ++i) {
        i32 p = read<i32>(), v = read<i32>();
        bb[p] = v;
      }
      fputc(solve(aa, bb, n, m) ? '1' : '0', fout);
    }
    fputs("\n", fout);
    return void();
  }
  /*
  g++ expand.cpp -o expand -lm -O2 -std=c++14 -Wall
  ./expand
  */
} t;
signed main() {
  // std::cerr << sizeof(t) / 1024 / 1024 << "MB" << std::endl;
  return t.main(), 0;
}