#include <bits/stdc++.h>

template <typename Type>
Type read() {
    int ch, f = 0;
    while (!isdigit(ch = getchar())) f = ch == '-';
    Type x = ch ^ '0';
    while (isdigit(ch = getchar())) x = (x << 3) + (x << 1) + (ch ^ '0');
    return f ? -x : x;
}

template <typename Type>
void read(Type &x) {
    x = read<Type>();
}

template <typename Type, typename... Args>
void read(Type &x, Args &...args) {
    x = read<Type>();
    read(args...);
}

constexpr int64_t INT64_X3F = 0x3f3f3f3f3f3f3f3f;
constexpr int64_t INT64_X1F = 0x1f1f1f1f1f1f1f1f;
constexpr int N = 1000000005;
constexpr int M = 100005;
constexpr int G = M * 3;
constexpr int GM = 1 << std::__lg(G) + 2;

int64_t d;

std::vector<int> vals;

struct Node {
    int64_t max, tag;
    void create(int l, int r, int64_t val) {
        tag = INT64_X3F + val;
        max = val + vals[r] * d;
    }
    void addval(int64_t val) { max += val, tag += val; }
};

Node seg[GM];

void pushdown(int u, int l, int mid, int r) {
    if (seg[u].tag > INT64_X1F) {
        seg[u].tag -= INT64_X3F;
        seg[u << 1].create(l, mid, seg[u].tag);
        seg[u << 1 | 1].create(mid + 1, r, seg[u].tag);
        seg[u].tag = 0;
    } else if (seg[u].tag != 0) {
        seg[u << 1].addval(seg[u].tag);
        seg[u << 1 | 1].addval(seg[u].tag);
        seg[u].tag = 0;
    }
}

void pushup(int u) { seg[u].max = std::max(seg[u << 1].max, seg[u << 1 | 1].max); }

void setval(int u, int l, int r, int L, int R, int64_t val) {
    if (vals[l] >= L && vals[r] <= R) return seg[u].create(l, r, val);
    int mid = l + r >> 1, midv = vals[mid];
    pushdown(u, l, mid, r);
    if (L <= midv) setval(u << 1, l, mid, L, R, val);
    if (R > midv) setval(u << 1 | 1, mid + 1, r, L, R, val);
    pushup(u);
}

void addval(int u, int l, int r, int L, int R, int64_t val) {
    if (vals[l] >= L && vals[r] <= R) return seg[u].addval(val);
    int mid = l + r >> 1, midv = vals[mid];
    pushdown(u, l, mid, r);
    if (L <= midv) addval(u << 1, l, mid, L, R, val);
    if (R > midv) addval(u << 1 | 1, mid + 1, r, L, R, val);
    pushup(u);
}

int64_t query(int u, int l, int r, int L, int R) {
    if (seg[u].tag > INT64_X1F) return (seg[u].tag - INT64_X3F) + std::min(vals[r], R) * d;
    if (vals[l] >= L && vals[r] <= R) return seg[u].max;
    int mid = l + r >> 1, midv = vals[mid];
    int64_t ans = 0;
    if (L <= midv) ans = std::max(ans, query(u << 1, l, mid, L, R));
    if (R > midv) ans = std::max(ans, query(u << 1 | 1, mid + 1, r, L, R));
    return ans + seg[u].tag;
}

int main_single() {
    const int n = read<int>();
    const int m = read<int>();
    const int k = read<int>();
    d = read<int>();

    vals = {0, n};

    std::map<int, std::vector<std::pair<int, int> > > map;
    for (int qi = 0; qi < m; ++qi) {
        const int x = read<int>();
        const int y = read<int>();
        const int v = read<int>();
        map[x].emplace_back(x - y, v);
        vals.push_back(x - y);
        vals.push_back(x);
        if (x - k > 0) vals.push_back(x - k - 1);
    }

    if (n <= 1000 && m <= 1000) {
        std::vector<int64_t> f(n + 2);
        for (int i = 1; i <= n + 1; ++i) {
            for (auto [l, v] : map[i - 1]) {
                for (int j = std::max(i - k - 1, 0); j <= l; ++j) f[j] += v;
            }
            for (int j = std::max(i - k - 1, 0); j < i; ++j) {
                f[i] = std::max(f[i], f[j] - (i - j - int64_t(1)) * d);
            }
        }
        std::cout << f[n + 1] << '\n';
        return 0;
    }

    std::sort(vals.begin(), vals.end());
    int g = std::unique(vals.begin(), vals.end()) - vals.begin();
    vals.resize(g);
    --g;

    seg[1].create(0, g, 0);

    int last_pos = 0;
    int64_t last_val = 0;
    
    for (auto &[val, vec] : map) {
        int i = val + 1;
        setval(1, 0, g, last_pos, i - 1, last_val);
        for (auto [l, v] : vec) addval(1, 0, g, 0, l, v);
        int64_t now_val = query(1, 0, g, std::max(i - k - 1, 0), i - 1) - (i - 1) * d;
        last_pos = i;
        last_val = now_val;
    }

    std::cout << last_val << '\n';

    return 0;
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int Sub, T = 1;
    read(Sub, T);
    while (T--) main_single();

    return 0;
}
