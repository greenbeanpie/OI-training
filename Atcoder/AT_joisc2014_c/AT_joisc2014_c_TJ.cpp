#include <bits/stdc++.h>
 
typedef long long ll;
const int N = 1e5 + 5;
ll n, m, Max, tot, a[N], b[N], st[N], ed[N], bel[N], ans[N], cnt[N], c[N];
 
struct Question {
    int l, r;
    int id;
} q[N];
 
bool cmp(Question x, Question y) {
    return bel[x.l] == bel[y.l] ? x.r < y.r : bel[x.l] < bel[y.l];
}
 
ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void add(int pos) {
    ++cnt[a[pos]];
    Max = std::max(Max, cnt[a[pos]] * b[a[pos]]);
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("AT_joisc2014_c.in", "r", stdin);
	freopen("AT_joisc2014_c_TJ.out", "w", stdout);
#endif
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = read();
    
    // discretization
    std::sort(b + 1, b + 1 + n);
    int len = std::unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(b + 1, b + 1 + len, a[i]) - b;
    
    // split block 
    ll block = sqrt(n);
    for (int i = 1; i <= block; ++i) {
        st[i] = n / block * (i - 1) + 1;
        ed[i] = n / block * i;
    }
    ed[block] = n;
    for (int i = 1; i <= block; ++i)
        for (int j = st[i]; j <= ed[i]; ++j)
            bel[j] = i;
 
    // sort question 
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(), q[i].r = read();
        q[i].id = i;
    }
    std::sort(q + 1, q + 1 + m, cmp);
 
    // mo
    int p = 1;
    for (int i = 1; i <= block; ++i) {
        int l;
        int r = ed[i];
        memset(cnt, 0, sizeof (cnt));
        Max = -1;
        while (bel[q[p].l] == i) {
            // std::cout << "sdasda";
            //Max = -1;
            tot = 0;
            l = ed[i] + 1;
            if (bel[q[p].l] == bel[q[p].r]) {
                ll cur = Max;
                for (int j = q[p].l; j <= q[p].r; ++j) {
                    ++cnt[a[j]];
                    c[++tot] = a[j];
                    Max = std::max(Max, cnt[a[j]] * b[a[j]]);
                }
                ans[q[p].id] = Max;
                for (int j = 1; j <= tot; ++j)
                    --cnt[c[j]];
                ++p;
                Max = cur;
                continue;
            }
            while (r < q[p].r)
                add(++r);
            ll cur = Max;
            //std::cout << "cur: " << cur << std::endl;
            while (l > q[p].l)
                add(--l);
            ans[q[p].id] = Max;
            Max = cur;
            while (l <= ed[i]) 
                --cnt[a[l++]];
            ++p;
        }
    }
 
    // output
    for (int i = 1; i <= m; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}