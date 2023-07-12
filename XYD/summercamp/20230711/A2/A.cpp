#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  vector<long long> b(n), s(n);
  for (int i = 1; i < n; ++i) {
    b[i] = a[i] - a[i - 1];
  }
  sort(b.begin(), b.end());
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + b[i];
  }

  int nq;
  cin >> nq;
  for (long long l, r; nq--; ) {
    cin >> l >> r;
    long long d = r - l + 1;
    int p = upper_bound(b.begin(), b.end(), d) - b.begin() - 1;
    long long ans = s[p] + d * (n - p);
    cout << ans << " ";
  }
  cout << endl;
  
  return 0;
}