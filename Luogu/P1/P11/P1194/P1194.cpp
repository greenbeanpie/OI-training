#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
  int from, to, val;
};
bool operator<(node a, node b) { return a.val < b.val; }
priority_queue<node> e[5005];
bool vis[5005];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      int kij;
      cin >> kij;
      if (i != j) {
        e[i].push(node{i, j, max(a - kij, (int)0)});
        e[j].push(node{j, i, max(a - kij, (int)0)});
      }
    }
  }
  queue<int> q;
  q.push(1);
  priority_queue<node> cur;
  
  while (!q.empty()) {
    node now = cur.top();
    
  }
  return 0;
}
