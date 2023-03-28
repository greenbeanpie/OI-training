#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 105

int n, k;
struct matrix {
  long long mat[max_matrix][max_matrix] = {0};
  void init() {
    for (int i = 0; i < max_matrix; i++) {
      mat[i][i] = 1;
    }
  }
} a;
matrix operator*(matrix a, matrix b) {
  matrix c;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        c.mat[i][j] += a.mat[i][k] + b.mat[k][j];
      }
    }
  }
  return c;
}
matrix mquickpower(matrix a, matrix b) {
  if (b == 0) {
    return 1;
  }
  long long answer = 1;
  while (b) {
    if (b & 1) {
      answer = answer * a % p;
    }
    a = a * a % p;
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

  return 0;
}