#include <bits/stdc++.h>
const int N = 1e6 + 5;
int a[N], n, m;

signed main() {
    std::cin >> n >> m;
    auto read = []() { int x; std::cin >> x; return x; };
    std::generate(a + 1, a + n + 1, read);
    for(int x; m--; ) {
        std::cin >> x;
        int pos = std::lower_bound(a + 1, a + n + 1, x) - a;
        std::cout << (a[pos] == x ? pos : -1) << ' ';
    }
    return 0;
}