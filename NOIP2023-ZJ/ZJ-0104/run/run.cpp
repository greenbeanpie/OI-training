#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

const int N = 2e5 + 5, B = 1e6;

vector<pr> num[N];

int d, nx, ny;
int b[N], c[N], l[N], r[N], w[N];

struct SegTree {
    int tr[N << 2], lzy[N << 2];

    void update(int num) {
        tr[num] = max(tr[ls], tr[rs]);
    }

    void modify(int num, int val) {
        tr[num] = val;
        lzy[num] = val;
    }

    void pushdown(int num) {
        if (lzy[num] == -1) return;

        modify(ls, lzy[num]);
        modify(rs, lzy[num]);

        lzy[num] = -1;
    }

    void build(int l, int r, int num) {
        if (l > r) return;
        lzy[num] = -1;
        if (l == r) {
            tr[num] = 0;
            return;
        }

        build(l, mid, ls);
        build(mid + 1, r, rs);

        update(num);
    }

    void update(int l, int r, int x, int y, int k, int num) {
        if (x > y) return;

        if (x <= l && r <= y) {
            modify(num, k);
            return;
        }

        pushdown(num);

        if (x <= mid) update(l, mid, x, y, k, ls);
        if (y > mid) update(mid + 1, r, x, y, k, rs);

        update(num);
    }

    int find(int l, int r, int k, int num) {
        if (tr[num] < k) return r + 1;

        if (l == r) {
            return l;
        }

        pushdown(num);

        if (tr[ls] < k) return find(mid + 1, r, k, rs);
        return find(l, mid, k, ls);
    }
} Tr;

int tr[N << 2], tree[N << 2], tag[N << 2], lzy[N << 2], Lzy[N << 2];

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

void update(int num) {
    tr[num] = max(tr[ls], tr[rs]);
    tree[num] = max(tree[ls], tree[rs]);
}

void Mod(int num, int val) {
    tree[num] += val;
    tag[num] += val;
}

void modify(int num, int val, int l, int r) {
    tr[num] = val + tree[num];
    lzy[num] = val;
    Lzy[num] = 0;
}

void Modify(int num, int val) {
    tr[num] += val;
    if (lzy[num] == -1) Lzy[num] += val;
}

void pushdown(int num, int l, int r) {
    if (tag[num]) {
        Mod(ls, tag[num]);
        Mod(rs, tag[num]);
        tag[num] = 0;
    }
    if (lzy[num] != -1) {
        modify(ls, lzy[num], l, mid);
        modify(rs, lzy[num], mid + 1, r);
        lzy[num] = -1;
        return;
    }
    if (Lzy[num]) {
        Modify(ls, Lzy[num]);
        Modify(rs, Lzy[num]);
        Lzy[num] = 0;
    }
}

void build(int l, int r, int num) {
    if (l > r) return;
    lzy[num] = -1;
    Lzy[num] = tag[num] = 0;
    if (l == r) {
        tree[num] = tr[num] = b[l] * d;
        return;
    }

    build(l, mid, ls);
    build(mid + 1, r, rs);

    update(num);
}

void update(int l, int r, int x, int k, int num) {
    if (r <= x) {
        Mod(num, k);
        Modify(num, k);
        return;
    }

    pushdown(num, l, r);

    if (x <= mid) update(l, mid, x, k, ls);
    else Mod(ls, k), Modify(ls, k), update(mid + 1, r, x, k, rs);

    update(num);
}

void update(int l, int r, int x, int y, int k, int num) {
    if (x > y) return;

    if (x <= l && r <= y) {
        modify(num, k, l, r);
        return;
    }

    pushdown(num, l, r);

    if (x <= mid) update(l, mid, x, y, k, ls);
    if (y > mid) update(mid + 1, r, x, y, k, rs);

    update(num);
}

int query(int l, int r, int x, int y, int num) {
    if (x > y) return 0;

    if (x <= l && r <= y) {
        return tr[num];
    }

    pushdown(num, l, r);

    int res = 0;

    if (x <= mid) res = max(res, query(l, mid, x, y, ls));
    if (y > mid) res = max(res, query(mid + 1, r, x, y, rs));

    return res;
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    int t = read();
    t = read();

    while (t--) {
        int n = read(), m = read(), k = read();
        d = read();
        nx = 0, ny = 0;

        for (int i = 1; i <= m; i++) {
            int x = read(), y = read(), z = read();
            l[i] = x - y + 1;
            r[i] = x;
            w[i] = z;
            if (y <= k) {
                b[++nx] = l[i];
                c[++ny] = r[i];
            }
        }

        sort(b + 1, b + nx + 1);
        nx = unique(b + 1, b + nx + 1) - b - 1;
        sort(c + 1, c + ny + 1);
        ny = unique(c + 1, c + ny + 1) - c - 1;

        for (int i = 1; i <= m; i++) {
            if (r[i] - l[i] + 1 > k) continue;
            int x = lower_bound(c + 1, c + ny + 1, r[i]) - c;
            int y = lower_bound(b + 1, b + nx + 1, l[i]) - b;
            num[x].pb({y, w[i]});
        }

        build(1, nx, 1);
        Tr.build(1, nx, 1);
        int ans = 0;

        for (int i = 1; i <= ny; i++) {
            for (auto u : num[i]) {
                update(1, nx, u.first, u.second, 1);
            }

            num[i].clear();

            int L = lower_bound(b + 1, b + nx + 1, c[i] - k + 1) - b, R = lower_bound(b + 1, b + nx + 1, c[i] + 1) - b - 1;
            int now = query(1, nx, L, R, 1) - (c[i] + 1) * d;
            ans = max(ans, now);

            L = R + 1;
            if (L <= nx && b[L] == c[i] + 1) L++;

            R = Tr.find(1, nx, now + 1, 1) - 1;
            Tr.update(1, nx, L, R, now, 1);
            update(1, nx, L, R, now, 1);
        }

        write(ans);
        putchar('\n');
    }
}