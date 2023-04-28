#include <bits/stdc++.h>
using namespace std;
#define int long long
int dabiao(int num) { return num * pow(10, max((long long)0, num - 1)); }
int count(int end, int num) {
  if (end == 0) {
    if (num == 0) {
      return 1;
    } else {
      return 0;
    }
  }
  if (end < 10) {
    if (num <= end) {
      return 1;
    } else {
      return 0;
    }
  }
  int dp[15] = {0};
  int current = 0;
  int len = 0;
  while (end) {
    current += end % 10 * pow(10, len++);
    dp[len] = dp[len - 1] + (end % 10) * dabiao(len - 1);

    if (end % 10 > num) {
      dp[len] += pow(10, len - 1);
    } else if (end % 10 == num) {
      dp[len] += current % (long long)pow(10, len - 1);
      dp[len]++;
    }
    end /= 10;
  }
  if (num == 0) {
    for (int i = 0; i < len; i++) {
      dp[len] -= pow(10, i);
    }
    dp[len]++;
  }
  return dp[len];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int s;
  cin >> s;
  for (int i = 0; i <= 9; i++) {
    cout << count(s, i) - count(0, i) << endl;
  }
  return 0;
}