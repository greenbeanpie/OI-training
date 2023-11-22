#include <bits/stdc++.h>
using namespace std;
#define fo(v, a, b) for(int v = a; v <= b; v++)
#define fr(v, a, b) for(int v = a; v >= b; v--)
#define cl(a, v) memset(a, v, sizeof(a))

typedef long long ll;

const int N = 2e5 + 10;

int m; ll n, k, d;
struct bonus {  ll l, r, V;  } a[N];

ll val[N]; int tot; vector<int> vec[N];

struct node {
    int l, r; ll mx, tag;
} t[N << 2];
inline void update(int p) {
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
}
void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r; if(l == r) return ;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}
inline void apply(int p, ll V) {
    t[p].mx += V, t[p].tag += V;
}
inline void pushdown(int p) {
    if(t[p].tag) {
        apply(p << 1, t[p].tag), apply(p << 1 | 1, t[p].tag);
        t[p].tag = 0;
    }
}
void change(int p, int l, int r, ll V) {
    if(l <= t[p].l && t[p].r <= r) return apply(p, V);
    int mid = (t[p].l + t[p].r) >> 1; pushdown(p);
    if(l <= mid) change(p << 1, l, r, V);
    if(r > mid) change(p << 1 | 1, l, r, V);
    update(p);
}
ll query(int p, int l, int r) {
    if(l <= t[p].l && t[p].r <= r) return t[p].mx;
    int mid = (t[p].l + t[p].r) >> 1; pushdown(p);
    if(r <= mid) return query(p << 1, l, r);
    if(l > mid) return query(p << 1 | 1, l, r);
    return max(query(p << 1, l, r), query(p << 1 | 1, l, r));
}

ll ans[N];

void reset() {
    cl(val, 0), tot = 0, cl(t, 0), cl(ans, 0);
    fo(i, 1, 2 * m) vec[i].clear();
}
void Main() {
    scanf("%lld%d%lld%lld", &n, &m, &k, &d), reset();
    fo(i, 1, m) {
        ll x, y; scanf("%lld%lld%lld", &x, &y, &a[i].V);
        a[i].l = x - y + 1, a[i].r = x;
        val[++tot] = a[i].l, val[++tot] = a[i].r;
    }
    sort(val + 1, val + tot + 1);
    tot = unique(val + 1, val + tot + 1) - (val + 1);
    fo(i, 1, m) {
        int p = lower_bound(val + 1, val + tot + 1, a[i].r) - val;
        vec[p].push_back(i);
    }

    build(1, 1, tot);
    fo(i, 1, tot) {
        ll cur = d * (val[i] - 1);
        if(i == 1 || val[i - 1] + 1 < val[i])
            cur += ans[i - 1];
        else cur += ans[i - 2];
        change(1, i, i, cur);
        for(int id : vec[i]) {
            int p = lower_bound(val + 1, val + tot + 1, a[id].l) - val;
            change(1, 1, p, a[id].V);
        }
        int l = lower_bound(val + 1, val + tot + 1, val[i] - k + 1) - val,
            r = i;
        ans[i] = max(ans[i - 1], -d * val[i] + query(1, l, r));
    }
    printf("%lld\n", ans[tot]);
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    int Tid, T; scanf("%d%d", &Tid, &T);
    while(T--) Main();

    return 0;
}