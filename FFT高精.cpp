#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
#define int long long
const long double Pi = acos(-1);
struct complex {
  long double real, imag;
  inline complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
  }
};
const complex I(0, 1);
complex operator+(complex a, complex b) {
  complex c(a.real + b.real, a.imag + b.imag);
  return c;
}
complex operator-(complex a, complex b) {
  complex c(a.real - b.real, a.imag - b.imag);
  return c;
}
complex operator*(complex a, complex b) {
  complex c(a.real * b.real, a.imag * b.imag);
  return c;
}

void change(complex y[], int len) {
  int k;
  for (int i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) {
      swap(y[i], y[j]);
    }
    k = len / 2;
    while (j >= k) {
      j = j - k;
      k = k / 2;
    }
    if (j < k) {
      j += k;
    }
  }
}

void fft(complex y[], int len, int op) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    complex wn(cos(2 * Pi / h), sin(op * 2 * Pi / h));
    for (int j = 0; j < len; j += h) {
      complex w(I);
      for (int k = j; k < j + h / 2; k++) {
        complex u = y[k];
        complex t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (op == -1) {
    for (int i = 0; i < len; i++) {
      y[i].real /= len;
    }
  }
}
int sum[200005];
complex x1[200005], x2[200005];
signed main() {
  ios::sync_with_stdio(false);
  string str1, str2;
  cin >> str1;
  cin >> str2;
  int len = 1;
  while (len < str1.size() * 2 || len < str2.size() * 2) {
    len <<= 1;
  }
  for (int i = 0; i < str1.length(); i++) {
    x1[i] = complex(str1[len - 1 - i] - '0', 0);
  }
  for (int i = str1.length(); i < len; i++) {
    x1[i] = complex(0, 0);
  }
  for (int i = 0; i < str2.length(); i++) {
    x1[i] = complex(str2[len - 1 - i] - '0', 0);
  }
  for (int i = str2.length(); i < len; i++) {
    x2[i] = complex(0, 0);
  }
  fft(x1, len, 1);
  fft(x2, len, 1);
  for (int i = 0; i < len; i++) {
    x1[i] = x1[i] * x2[i];
  }
  fft(x1, len, -1);
  for (int i = 0; i < len; i++) {
    sum[i] = x1[i].real + 0.5;
  }
  for (int i = 0; i < len; i++) {
    sum[i + 1] += sum[i] / 10;
    sum[i] %= 10;
  }
  for (int i = len; i >= 0; i--) {
    cout << sum[i];
  }
  return 0;
}