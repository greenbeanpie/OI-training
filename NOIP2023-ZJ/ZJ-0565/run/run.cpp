#include<bits/stdc++.h>
#define lol long long

int C, T, n, m, k, d;

struct Y {
    int l, r;
    lol w;
} t[100005];

lol f[100005];
lol ans;
void solveA() {
    memset(f, 0, sizeof(0));
    ans = 0;
    int dis;
    lol wt;
    for(int i = 1; i <= m; i++) {
        dis = t[i].r - t[i].l + 1;
        wt = t[i].w;
        for(int j = i - 1; j >= 1; j--) {
            if(dis > k) break;
            if(t[j].r + 1 == t[i].l) {
                if(j) f[i] = std::max(f[i], f[j - 1] + wt - 1ll * dis * d);
                dis += t[j].r - t[j].l + 1;
                wt += t[j].w;
            }
            else {
                if(dis <= k) f[i] = std::max(f[i], f[j] + wt - 1ll * dis * d);
                break;
            }
        }
        if(t[i].r - t[i].l + 1 <= k) f[i] = std::max(f[i], t[i].w);
        ans = std::max(ans, f[i]);
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("run.in", "r", stdin); freopen("run.out", "w", stdout);
    scanf("%d%d", &C, &T);
    for(; T--; ) {
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%lld", &t[i].r, &t[i].l, &t[i].w);
            t[i].l = t[i].r - t[i].l + 1;
        }
        solveA();
    }
    return 0;
}
