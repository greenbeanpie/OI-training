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
  static const i32 N = 3005;
  i32 n, m;
  char s[N];
  i32 tot[30];
  i32 sml[N], big[N];
  void main() {
    fin = stdin, fout = stdout, ferr = stderr;
    fin = fopen("dict.in", "r");
    fout = fopen("dict.out", "w");
    n = read<i32>(), m = read<i32>();
    for (i32 i = 1; i <= n; ++i) {
      fscanf(fin, "%s", s + 1);
      for (i32 j = 0; j < 26; ++j) tot[j] = 0;
      for (i32 j = 1; j <= m; ++j) ++tot[s[j] - 'a'];
      for (i32 j = 0; j < 26; ++j) if (tot[j]) { sml[i] = j; break; }
      for (i32 j = 25; j >= 0; --j) if (tot[j]) { big[i] = j; break; }
    }
    for (i32 i = 1; i <= n; ++i) {
      bool flag = true;
      for (i32 j = 1; j <= n; ++j)
        if (i != j) {
          if (sml[i] < big[j]) continue;
          if (sml[i] >= big[j]) { flag = false; break; }
        }
      fputc(flag ? '1' : '0', fout);
    }
    fputs("\n", fout);
    return void();
  }
  /*
  g++ dict.cpp -o dict -lm -O2 -std=c++14 -Wall -static
  ./dict
  */
} t;
signed main() { 
  // std::cerr << sizeof(t) / 1024 / 1024 << "MB" << std::endl;
  return t.main(), 0;
}