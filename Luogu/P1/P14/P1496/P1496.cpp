#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
signed main() {
  int n;
  cin >> n;
  pair<int, int> diffe[n*2];
  for (int i = 0; i < n; i++) {
    diffe[i].second = 0;
  }
  int a, b;
  for (int i = 0; i < n; i += 2) {
    cin >> a >> b;
    diffe[i].first = a;
    diffe[i].second++;
    diffe[i + 1].first = b;
    diffe[i+1].second--;
  }
  sort(diffe, diffe + n, cmp);
  int sum = 0;
  int t = 0, start = -1;
  for (int i = 0; i < n; i++) {
    t += diffe[i].second;
    if (t > 0 && start == -1) {
      start = diffe[i].first;
    }
    if (t <= 0) {
      sum += diffe[i].first - start;
      start = -1;
    }
  }
  cout << sum;
  return 0;
}