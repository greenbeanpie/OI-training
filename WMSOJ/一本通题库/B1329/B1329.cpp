#include <bits/stdc++.h>
using namespace std;
#define int long long
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("B1329.in","r",stdin);
    #endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  bool cell[n][m];
  memset(cell,0,sizeof(cell));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char t;
      cin >> t;
      if (t != '0') {
        cell[i][j] = true;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < m ; j++) {
      if (!cell[i][j]) {
        continue;
      }
      cnt++;
      queue<int> x, y;
      x.push(i);
      y.push(j);

      while (!x.empty()) {
        int a = x.front(), b = y.front();
        cell[a][b] = false;
        x.pop();
        y.pop();

        for (int f = 0; f < 4; f++) {
            if(a+mx[f]<0||a+mx[f]>=n||b+my[f]<0||b+my[f]>=m){
                continue;
            }
          if (cell[a + mx[f]][b + my[f]]) {
            x.push(a + mx[f]);
            y.push(b + my[f]);
            cell[a + mx[f]][b + my[f]]=false;
          }
        }
        
      }
    }
  }
  cout << cnt;
  return 0;
}