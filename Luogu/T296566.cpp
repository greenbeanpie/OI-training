#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  #ifndef ONLINE_JUDGE
    freopen("T296566.in","r",stdin);
   #endif
  int n, xend, yend;
  cin >> n >> xend >> yend;
  pair<int, int> square[n];
  for (int i = 0; i < n; i++) {
    cin >> square[i].first >> square[i].second;
  }
  int sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (square[i].first > xend) {
      sum += square[i].first - xend;
    } else if (square[i].first + i < xend) {
      sum += xend - square[i].first-i;
    }
    if (square[i].second < yend) {
      sum += yend-square[i].second;
    } else if (square[i].second - i > yend) {
      sum += square[i].second-yend+i ;
    }
  }
  cout << sum;
  return 0;
}