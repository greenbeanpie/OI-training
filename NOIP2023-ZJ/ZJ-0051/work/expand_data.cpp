#include <bits/stdc++.h>

std::mt19937_64 mt_rand(std::chrono::system_clock::now().time_since_epoch().count());

int64_t random(int64_t l, int64_t r) { return mt_rand() % (r - l + 1) + l; }

constexpr char CHAR_BEG = 'a';

int main() {
    // freopen("expand.in", "r", stdin);
    // freopen("expand.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int c = 0, n = 3000 - random(1, 5), m = 3000 - random(1, 5), q = 60;
    int nm = std::min(n, m), s = std::min(nm, int(5e5) / q);
    int vxl = 1, vxr = 9.9e8, vyl = 0.1e8, vyr = 10e8;

    std::cout << c << ' ' << n << ' ' << m << ' ' << q << '\n';

    for (int i = 0; i < n; ++i) std::cout << random(vxl, vxr) << " \n"[i + 1 == n];
    for (int j = 0; j < m; ++j) std::cout << random(vyl, vyr) << " \n"[j + 1 == m];

    for (int qi = 0; qi < q; ++qi) {
        std::vector<int> vx(s), vy(s);
        for (auto &x : vx) x = random(1, n);
        for (auto &x : vy) x = random(1, m);
        vx.resize((std::sort(vx.begin(), vx.end()), std::unique(vx.begin(), vx.end())) - vx.begin());
        vy.resize((std::sort(vy.begin(), vy.end()), std::unique(vy.begin(), vy.end())) - vy.begin());
        std::cout << vx.size() << ' ' << vy.size() << '\n';
        for (auto x : vx) std::cout << x << ' ' << random(vxl, vxr) << '\n';
        for (auto x : vy) std::cout << x << ' ' << random(vyl, vyr) << '\n';
    }

    return 0;
}
