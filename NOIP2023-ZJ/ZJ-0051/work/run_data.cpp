#include <bits/stdc++.h>

std::mt19937_64 mt_rand(std::chrono::system_clock::now().time_since_epoch().count());

int64_t random(int64_t l, int64_t r) { return mt_rand() % (r - l + 1) + l; }

int main_single() {
    int n = 3000, m = 3000, k = random(1, n), V = 1e9;
    int T = n / m, S = V / (T + 2);
    int d = random(S / 2, S);
    int vl = std::max(1, d * (T - 1)), vr = std::min(V, d * (T + 1));
    std::cout << n << ' ' << m << ' ' << k << ' ' << d << '\n';

    for (int i = 0; i < m; ++i) {
        int x = random(1, n);
        int y = random(1, std::min(x, k));
        int v = random(vl, vr);
        std::cout << x << ' ' << y << ' ' << v << '\n';
    }
    
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int Sub = 7, T = 10;
    std::cout << Sub << ' ' << T << '\n';
    while (T--) main_single();

    return 0;
}
