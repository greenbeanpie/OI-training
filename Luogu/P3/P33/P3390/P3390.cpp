#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 105
#define mod 1000000007

int n, k;
struct matrix {
  long long mat[max_matrix][max_matrix] = {0};
  void init() {
    for (int i = 1; i <= max_matrix; i++) {
      mat[i][i] = 1;
    }
  }
} a;
matrix operator*(matrix a, matrix b) {
  matrix c;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
        c.mat[i][j] %= mod;
      }
    }
  }
  return c;
}
matrix mquickpower(matrix a, int b) {
  matrix answer;
  answer.init();
  if (b == 0) {
    return answer;
  }
  while (b) {
    if (b & 1) {
      answer = answer * a;
    }
    a = a * a;
    b >>= 1;
  }
  return answer;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  matrix a;
  a.init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a.mat[i][j];
    }
  }
  mquickpower(a, k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a.mat[i][j] % mod << " ";
    }
    cout << endl;
  }
  return 0;
}