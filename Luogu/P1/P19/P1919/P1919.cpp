#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
#define int long long
#define double long double
#define fft fast_fast_tle
const double Pi = acos(-1);
struct complex {
	double real=0, imag=0;
	inline complex(double r = 0, double i = 0) {
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
	return complex(a.real * b.real-a.imag*b.imag, a.real*b.imag + a.imag*b.real);
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
			k>>=1;
		}
		if (j < k) {
			j += k;
		}
	}
}

void fast_fast_tle(complex y[], int len, int op) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    complex wn(cos(2 * Pi / h), sin(op * 2 * Pi / h));
    for (int j = 0; j < len; j += h) {
      complex w(1,0);
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
	#ifndef ONLINE_JUDGE
		freopen("P1919.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int len = 1;
	while (len < (int)str1.size() * 2 || len < (int)str2.size() * 2) {//确保位数为2^n(n∈N)
		len <<= 1;
	}
	for (int i = 0; i < (int)str1.size(); i++) {
		x1[i] = complex(str1[str1.size() - 1 - i] - '0', 0);
	}
	for (int i = 0; i < (int)str2.size(); i++) {
		x2[i] = complex(str2[str2.size() - 1 - i] - '0', 0);
	}
	fft(x1, len, 1);
	fft(x2, len, 1);
	for (int i = 0; i < len; i++) {
		x1[i] = x1[i] * x2[i];
	}
	fft(x1, len, -1);
	for (int i = 0; i < len; i++) {
		sum[i] = (int)(x1[i].real + 0.5);
	}
	for (int i = 0; i < len; i++) {
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
	len=str1.size()+str2.size()-1;
	while(!sum[len]&&len>0){
		len--;
	}
	
	for (int i = len; i >= 0; i--) {
		cout << sum[i];
	}
	return 0;
}