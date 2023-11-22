#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

int main() {
  system("g++ expand.cpp -o expand -O2 -std=c++14 -static");
  system("g++ brute.cpp -o brute -O2 -std=c++14 -static");
  system("g++ gen.cpp -o gen -O2 -std=c++14 -static");
  int tc = 0;
  while (true) {
    system("./gen > expand.in");
    system("./expand < expand.in > expand.out");
    system("./brute < expand.in > expand.ans");
    if (system("diff expand.out expand.ans")) break;
    cout << "Test Case " << ++tc << " passed." << endl;
  }
}