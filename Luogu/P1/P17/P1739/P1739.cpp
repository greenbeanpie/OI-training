#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  int a;
  char b;
  b = getchar();
  while (b != '@') {
    if (b == '(') {
      a++;
    }
    if (b == ')') {
      a--;
    }
    if (a < 0) {
      cout << "NO";
      return 0;
    }
    b = getchar();
  }
  if (a != 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}