#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int a = 0; a < t; a++) {
    int n, k;
    cin >> n >> k;
    int loc[n + 5] = {0};
    for (int i = 1; i <= n; i++) {
      cin >> loc[i];
    }
    int w[n + 5] = {0};
    for (int i = 1; i <= n; i++) {
      cin >> w[i];
    }
    int dp[n + 5] = {0};
    int dpdis[n + 5] = {0};
    bool vis[n + 5] = {0};
    int maxinum=-1;
    for (int i = 1; i <= n; i++) {
      dp[i] = w[i];
      
      for (int j = 1; j <i&&loc[i]-loc[j]>k; j++) {

        dp[i] = max(dp[i], dp[j] + w[i]);
      }
      maxinum=max(maxinum,dp[i]);
    }
    cout << maxinum << endl;
  }
  return 0;
}
