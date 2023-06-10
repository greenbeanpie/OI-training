#include <iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("J.in","r",stdin);
        freopen("J1.out","w",stdout);
    #endif
  int a, b, c;
  cin >> a >> b >> c;
  int d = b - c;
  cout << ((a + d - 1) / d) << endl;
}