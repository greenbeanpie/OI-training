#include<bits/stdc++.h>

int c, n, m, q;
int ta[500005], tb[500005];
int a[500005], b[500005];


int solve() {
    if(n == 1) return (a[1] != b[1]);
    else if(n == 2) return ((a[1] - b[1]) * (a[2] - b[2]) > 0);
    int f = 1;
    if((a[1] - b[1]) * (a[n] - b[n]) <= 0) return 0;
    if(a[1] - b[1] > 0) f = 1;
    else f = -1;
    int bi = 2;
    for(int i = 2; i <= n; i++) {
        for(; bi <= m && (a[i] - b[bi]) * f > 0; bi++);
        if(bi == m + 1) return 1;
        for(; bi >= 1 && (a[i] - b[bi]) * f < 0; bi--);
        if(bi == 0) return 0;
    }
    return 1;
}

int csolve() {
    return solve();
}

int main() {
    freopen("expand.in", "r", stdin); freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &ta[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &tb[i]);
    memcpy(a, ta, sizeof(ta));
    memcpy(b, tb, sizeof(tb));
    if(8 <= c && c <= 14) printf("%d", csolve());
    else printf("%d", solve());
    for(int kx, ky, px, vx, py, vy; q--; ) {
        memcpy(a, ta, sizeof(ta));
        memcpy(b, tb, sizeof(tb));
        scanf("%d%d", &kx, &ky);
        for(int i = 1; i <= kx; i++) {
            scanf("%d%d", &px, &vx);
            a[px] = vx;
        }
        for(int i = 1; i <= ky; i++) {
            scanf("%d%d", &py, &vy);
            b[py] = vy;
        }
        if(8 <= c && c <= 14) printf("%d", csolve());
        else printf("%d", solve());
    }
    puts("");
    return 0;
}
