#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define map unordered_map
#define multimap unordered_multimap

signed main() {
  //#ifndef ONLINE_JUDGE
  //  freopen("P1419.in", "r", stdin);
  //#endif
  int n;
  scanf("%lld", &n);
  int s, t;
  scanf("%lld %lld", &s, &t);
  int nums[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", nums + i);
  }
  int sum[n + 1] = {0};
  sum[1] = nums[0];
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + nums[i - 1];
  }
  int max_ave = -10005;
  for (int i = s; i <= t; i++) {
    for (int j = 0; j <= n - 1; j++) {
      max_ave = max(max_ave, (sum[j + i] - sum[j]) / i);
    }
  }
  cout << fixed << setprecision(3) << 1.0 * max_ave;
  return 0;
}