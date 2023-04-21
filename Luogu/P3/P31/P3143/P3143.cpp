#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
  int s, e, num;
};
bool operator<(node a, node b) { return a.num > b.num; }
bool operator==(node a, node b) { return a.s >= b.s && a.e <= b.e; }

signed main() {
#ifndef ONLINE_JUDGE
  freopen("P3143_3.in", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  int a[n];
  if (n <= 2 * k) {
    int sum = 0;
    int t;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &t);
      sum += t;
    }
    cout << sum;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  sort(a, a + n);
  deque<int> d;
  set<node> answer;
  for (int i = 0; i < n; i++) {
    while (!d.empty() && a[i] - d.back() > k) {
      d.pop_back();
    }
    d.push_front(a[i]);
    while (a[i] == a[i + 1]) {
      d.push_front(a[++i]);
    }
    answer.insert(node{d.back(), d.front(), (long long)d.size()});
  }
  auto start = answer.begin();
  int maxinum = -1;
  auto end = --answer.end();
  while (start != end) {
    auto temp = start;
    temp++;
    while (temp != end && !((*temp).e < (*start).s || (*temp).s > (*start).e)) {
      temp++;
    }
    if (temp != end) {
      end = temp;
      maxinum = max(maxinum, (*start).num + (*temp).num);
    }
    start++;
  }
  cout << maxinum;
  return 0;
}