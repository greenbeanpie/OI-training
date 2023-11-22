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

template <typename Type, Type *Fir, typename DataType>
class StaticPtr {
   protected:
    DataType x;

   public:
    StaticPtr(DataType x = 0) : x(x) {}
    operator DataType() { return x; }
    operator bool() { return bool(x); }
    Type *operator->() { return Fir + x; }
    Type &operator*() { return Fir[x]; }
};

constexpr int64_t INT64_X3F = 0x3f3f3f3f3f3f3f3f;
constexpr int64_t INT64_X1F = 0x1f1f1f1f1f1f1f1f;
constexpr int N = 1000000005;
constexpr int M = 100005;
constexpr int C = std::__lg(N) + 2;
constexpr int Z = (C * M) * (1 + 1) * 2;

uint32_t cnt;

int64_t d;

struct Node {
    static Node pool[];
    using Ptr = StaticPtr<Node, pool, uint32_t>;
    Ptr ls, rs;
    int64_t max, tag;
    void create(int l, int r, int64_t val) {
        // if (cnt >= Z - 5) std::cerr << "cnt = " << cnt << '\n';
        ls = 0, rs = 0;
        tag = INT64_X3F + val;
        max = val + r * d;
    }
    void addval(int64_t val) { max += val, tag += val; }
    void pushdown(int l, int mid, int r);
    void pushup() { max = std::max(ls->max, rs->max); }
};

Node Node::pool[Z];

Node::Ptr new_node() { return Node::Ptr(++cnt); }
void clear() {
    // memset(Node::pool + 1, 0, sizeof(Node) * cnt);
    cnt = 0;
}

void Node::pushdown(int l, int mid, int r) {
    if (tag > INT64_X1F) {
        tag -= INT64_X3F;
        (ls ? ls : ls = new_node())->create(l, mid, tag);
        (rs ? rs : rs = new_node())->create(mid + 1, r, tag);
        tag = 0;
    } else if (tag != 0) {
        ls->addval(tag);
        rs->addval(tag);
        tag = 0;
    }
}

void setval(Node::Ptr u, int l, int r, int L, int R, int64_t val) {
    if (l >= L && r <= R) return u->create(l, r, val);
    int mid = l + r >> 1;
    u->pushdown(l, mid, r);
    if (L <= mid) setval(u->ls, l, mid, L, R, val);
    if (R > mid) setval(u->rs, mid + 1, r, L, R, val);
    u->pushup();
}

void addval(Node::Ptr u, int l, int r, int L, int R, int64_t val) {
    if (l >= L && r <= R) return u->addval(val);
    int mid = l + r >> 1;
    u->pushdown(l, mid, r);
    if (L <= mid) addval(u->ls, l, mid, L, R, val);
    if (R > mid) addval(u->rs, mid + 1, r, L, R, val);
    u->pushup();
}

int64_t query(Node::Ptr u, int l, int r, int L, int R) {
    if (u->tag > INT64_X1F) return (u->tag - INT64_X3F) + std::min(r, R) * d;
    if (l >= L && r <= R) return u->max;
    int mid = l + r >> 1;
    int64_t ans = 0;
    if (L <= mid) ans = std::max(ans, query(u->ls, l, mid, L, R));
    if (R > mid) ans = std::max(ans, query(u->rs, mid + 1, r, L, R));
    return ans + u->tag;
}

constexpr size_t S = sizeof(Node::pool) +
                     sizeof(std::vector<std::pair<int, int> >) * M +
                     (8 * 2) * M;

int main_single() {
    const int n = read<int>();
    const int m = read<int>();
    const int k = read<int>();
    d = read<int>();

    std::map<int, std::vector<std::pair<int, int> > > map;
    for (int qi = 0; qi < m; ++qi) {
        const int x = read<int>();
        const int y = read<int>();
        const int v = read<int>();
        map[x].emplace_back(x - y, v);
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

    Node::Ptr root = new_node();
    root->create(0, n, 0);

    int last_pos = 0;
    int64_t last_val = 0;
    
    for (auto &[val, vec] : map) {
        int i = val + 1;
        setval(root, 0, n, last_pos, i - 1, last_val);
        for (auto [l, v] : vec) addval(root, 0, n, 0, l, v);
        int64_t now_val = query(root, 0, n, std::max(i - k - 1, 0), i - 1) - (i - 1) * d;
        last_pos = i;
        last_val = now_val;
    }

    std::cout << last_val << '\n';

    clear();

    return 0;
}

int main() {
    assert(S <= 512 * 1024 * 1024);
    // freopen("run.in", "r", stdin);
    // freopen("run.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int Sub, T = 1;
    read(Sub, T);
    while (T--) main_single();

    return 0;
}
