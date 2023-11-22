#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
struct Node {
    ll mx;
    int l, r;
    ll tag;
};
Node tree[400400];
int n, m, k, d;
vector<pii> tsk[100100];
void add(int x, ll y) {
    // printf("Add : %d %lld\n", x, y);
    tree[x].tag += y;
    tree[x].mx += y;
}
void pushUp(int x) {
    tree[x].mx = max(tree[x * 2].mx, tree[x * 2 + 1].mx);
}
void pushDown(int x) {
    add(x * 2, tree[x].tag);
    add(x * 2 + 1, tree[x].tag);
    tree[x].tag = 0;
}
void build(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;
    tree[x].tag = 0;
    if (l == r) {
        tree[x].mx = 0;
        return;
    }
    int mid = l + r >> 1;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    pushUp(x);
}
void modify(int x, int L, int R, ll y) {
    int l = tree[x].l, r = tree[x].r;
    if (l > R || L > r)
        return;
    if (L <= l && r <= R) {
        add(x, y);
        return;
    }
    pushDown(x);
    modify(x * 2, L, R, y);
    modify(x * 2 + 1, L, R, y);
    pushUp(x);
}
ll query(int x, int L, int R) {
    int l = tree[x].l, r = tree[x].r;
    if (l > R || L > r)
        return -1e18;
    if (L <= l && r <= R)
        return tree[x].mx;
    pushDown(x);
    return max(query(x * 2, L, R), query(x * 2 + 1, L, R));
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    for (int _ = 1; _ <= t; _++) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i = 1; i <= n; i++) {
            tsk[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            tsk[x].push_back(make_pair(y, c));
        }
        build(1, 0, n);
        modify(1, 1, n, -1e18);
        // printf("%lld\n", query(1, 1, 1));
        for (int i = 1; i <= n; i++) {
            ll mx = query(1, max(0, i - 1 - k), i - 1),
               ori = query(1, i, i);
            // printf("%lld\n", mx);
            modify(1, i, i, mx - ori);
            modify(1, max(0, i - k), i - 1, -d);
            for (pii p : tsk[i]) {
                if (i >= p.first && k >= p.first) {
                    modify(1, max(0, i - k), i - p.first, p.second);
                }
            }
        }
        printf("%lld\n", query(1, max(n - k, 0), n));
    }
}