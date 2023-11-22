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
  i32 n, m, ans;
  i32 a[N], u[N], v[N], cnt[N], back[N];
  char op[N], s[N], t[N];
  bool check(char c) {
    if (c == 'T') return true;
    if (c == 'F') return true;
    if (c == 'U') return true;
    if (c == '+') return true;
    if (c == '-') return true;
    return false;
  }
  char flip(char c) {
    if (c == 'T') return 'F';
    if (c == 'F') return 'T';
    if (c == 'U') return 'U';
    return '\0';
  }
  bool check() {
    for (i32 i = 1; i <= n; ++i) t[i] = s[i];
    for (i32 i = 1; i <= m; ++i) {
      if (op[i] == '+') {
        t[u[i]] = t[v[i]];
      } else if (op[i] == '-') {
        t[u[i]] = flip(t[v[i]]);
      } else {
        t[u[i]] = op[i];
      }
    }
    for (i32 i = 1; i <= n; ++i) if (s[i] != t[i]) return false;
    return true;
  }
  i32 trans(char c) {
    if (c == 'T') return 1;
    if (c == 'F') return 0;
    if (c == 'U') return -1;
    return 2;
  }
  void dfs(i32 x) {
    if (x == n + 1) {
      if (check()) {
        i32 cnt = 0;
        for (i32 i = 1; i <= n; ++i) if (s[i] == 'U') ++cnt;
        ans = std::min(ans, cnt);
      }
      return void();
    }
    s[x] = 'T'; dfs(x + 1);
    s[x] = 'F'; dfs(x + 1);
    s[x] = 'U'; dfs(x + 1);
    return void();
  }
  void solve() {
    n = read<i32>(), m = read<i32>();
    for (i32 i = 1; i <= n; ++i) back[i] = i, cnt[i] = 0, s[i] = 0, a[i] = 0;
    for (i32 i = 1; i <= m; ++i) {
      char ch = '\0';
      while (!check(ch)) ch = fgetc(fin);
      op[i] = ch;
      if (ch == '+') {
        u[i] = read<i32>(), v[i] = read<i32>();
        back[u[i]] = back[v[i]];
        cnt[u[i]] = cnt[v[i]];
      } else if (ch == '-') {
        u[i] = read<i32>(), v[i] = read<i32>();
        back[u[i]] = back[v[i]];
        cnt[u[i]] = cnt[v[i]] + 1;
      } else {
        u[i] = read<i32>();
        a[u[i]] = trans(ch);
        back[u[i]] = i + n;
      }
    }
    ans = 0;
    if (c == 1 || c == 2) {
      ans = n + 1;
      dfs(1);
    } else if (c == 3 || c == 4) {
      for (i32 i = 1; i <= n; ++i)
        if (a[i] == -1)
          ++ans;
    } else if (c == 5 || c == 6) {
      for (i32 i = 1; i <= n; ++i) s[i] = 'T';
      for (i32 i = 1; i <= n; ++i) if (back[i] > n) s[i] = op[back[i] - n];
      bool change_flag = true;
      while (change_flag) {
        change_flag = false;
        for (i32 i = 1; i <= n; ++i) t[i] = s[i];
        for (i32 i = 1; i <= m; ++i) {
          if (op[i] == '+') {
            s[u[i]] = s[v[i]];
          } else if (op[i] == '-') {
            s[u[i]] = flip(s[v[i]]);
          } else {
            s[u[i]] = op[i];
          }
        }
        for (i32 i = 1; i <= n; ++i)
          if (s[i] != t[i]) {
            s[i] = 'U';
            change_flag = true;
          }
      }
      for (i32 i = 1; i <= n; ++i)
        if (s[i] == 'U') ++ans;
    } else {
      for (i32 i = 1; i <= n; ++i) s[i] = 'T';
      for (i32 i = 1; i <= m; ++i) {
        if (op[i] == '+') {
          s[u[i]] = s[v[i]];
        } else if (op[i] == '-') {
          s[u[i]] = flip(s[v[i]]);
        } else {
          s[u[i]] = op[i];
        }
      }
      bool change_flag = true;
      while (change_flag) {
        change_flag = false;
        for (i32 i = 1; i <= n; ++i) t[i] = s[i];
        for (i32 i = 1; i <= m; ++i) {
          if (op[i] == '+') {
            s[u[i]] = s[v[i]];
          } else if (op[i] == '-') {
            s[u[i]] = flip(s[v[i]]);
          } else {
            s[u[i]] = op[i];
          }
        }
        for (i32 i = 1; i <= n; ++i)
          if (s[i] != t[i]) {
            s[i] = 'U';
            change_flag = true;
          }
      }
      for (i32 i = 1; i <= n; ++i)
        if (s[i] == 'U') ++ans;
    }
    fprintf(fout, "%d\n", ans);
    return void();
  }
  void main() {
    fin = stdin, fout = stdout, ferr = stderr;
    fin = fopen("tribool.in", "r");
    fout = fopen("tribool.out", "w");
    c = read<i32>();
    i32 t = read<i32>();
    while (t--) solve();
    return void();
  }
  /*
  g++ tribool.cpp -o tribool -lm -O2 -std=c++14 -Wall
  ./tribool
  */
} t;
signed main() {
  // std::cerr << sizeof(t) / 1024 / 1024 << "MB" << std::endl;
  return t.main(), 0;
}