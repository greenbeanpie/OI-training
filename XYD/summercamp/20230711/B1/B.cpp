// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// 注：以上为原题解手动打开O2/O3优化代码
#include <bits/stdc++.h>
using namespace std;

const int N = 70005;
const double eps = 1e-7;
double x[N], v[N];
int n;

void merge(double &l1, double &r1, double l2, double r2) {
  l1 = max(l1, l2);
  r1 = min(r1, r2);
}
bool check(double tim) {
  double l, r;
  for (int i = 1; i <= n; i++) {
    double l_ = x[i] - tim * v[i];
    double r_ = x[i] + tim * v[i];
    if (i == 1) l = l_, r = r_;
    else merge(l, r, l_, r_);
  }
  return l <= r;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &x[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &v[i]);
  }
  double l = 0.0, r = 1000000000;
  while (r - l > eps) {
    double mid = (l + r) / 2.0;
    if (check(mid)) r = mid;
    else l = mid;
  }
  printf("%.5lf\n", l);
  return 0;
}