#include <bits/stdc++.h>
using namespace std;
#define int long long
#define map unordered_map
#define multimap unordered_multimap

signed main() {
  //#ifndef ONLINE_JUDGE
  //  freopen("P1419.in", "r", stdin);
  //#endif
  int n;
  scanf("%lld", &n);
  long double s, t;
  scanf("%Le %Le", &s, &t);
  long double nums[n];
  for (int i = 0; i < n; i++) {
    scanf("%Le", nums + i);
  }
  long double sum[n + 1] = {0};
  sum[1] = nums[0];
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + nums[i - 1];
  }
  long double max_ave = -10005;
  for (int i = s; i <= t&& (double)clock() / CLOCKS_PER_SEC <= 0.95; i++) {
    for (int j = 0; j < n - i; j++) {
      max_ave = max(max_ave, (sum[j + i] - sum[j]) / i);
    }
  }
  cout << fixed << setprecision(3) << 1.0 * max_ave;
  return 0;
}