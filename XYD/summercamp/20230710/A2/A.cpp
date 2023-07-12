#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("10.in", "r", stdin);
  freopen("10.out", "w", stdout);

  int n;
  cin.tie(0);
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  vector<long long> vec;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; (i + 1) * (j + 1) <= n; ++j) {
      vec.push_back((long long)a[i] * b[j]);
    }
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < n; ++i) {
    cout << vec[i] << " \n"[i + 1 == n];
  }

  return 0;
}