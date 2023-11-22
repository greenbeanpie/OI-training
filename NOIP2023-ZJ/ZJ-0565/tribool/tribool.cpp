#include<bits/stdc++.h>
#define T 100001
#define F 100002
#define U 100003
#define pii std::pair<int, int>
#define mp(x, y) std::make_pair(x, y)

char ch;
int C, t;
int n, m, cnt;
int f[100005], w[100005], k[100005], vis[100005], cir[100005];
int fand(int x) {
    if(f[x] == x) return x;
    else {
        int t = fand(f[x]);
        w[x] ^= w[f[x]];
        f[x] = t;
        return f[x];
    }
}

int circle(int bg, int x) {
    if(x == bg) return 0;
    return w[x] ^ circle(bg, f[x]);
}

void fu(int bg, int x, int hjx) {
    if(x == bg) return;
    fu(bg, f[x], hjx);
    f[x] = hjx;
}

void dfs(int x) {
    if(f[x] == T || f[x] == F || f[x] == U) return;
    if(x == f[x]) {
        if(w[x] == 1) f[x] = U;
        else f[x] = T;
    }
    if(vis[x]) {
        int hjx = w[x] ^ circle(x, f[x]);
        fu(x, f[x], hjx % 2 ? U : T);
        f[x] = hjx % 2 ? U : T;
    }
    vis[x] = 1;
    dfs(f[x]);
}

int main() {
    freopen("tribool.in", "r", stdin); freopen("tribool.out", "w", stdout);
    f[T] = T;
    f[F] = F;
    f[U] = U;
    scanf("%d%d", &C, &t);
    for(; t--; ) {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) f[i] = i, w[i] = 0;
        for(int i = 1, u, v, fu, fv; i <= m; i++) {
            scanf("\n%c", &ch);
            if(ch == '+') {
                scanf("%d%d", &u, &v);
                //f[u] = v;
                //w[u] = 0;

                fu = fand(u);
                fv = fand(v);
                if(fu == fv) { if(w[u] != w[v]) f[fu] = U, w[fu] = 0;}
                else f[u] = fv, w[u] = w[v];

            }
            else if(ch == '-') {
                scanf("%d%d", &u, &v);
                //f[u] = v;
                //w[u] = 1;

                fu = fand(u);
                fv = fand(v);
                if(fu == fv) { if(w[u] == w[v]) f[fu] = U, w[fu] = 0;}
                else f[u] = fv, w[u] = 1 ^ w[v];

            }
            else if(ch == 'T') {
                scanf("%d", &u);
                f[u] = T;
            }
            else if(ch == 'U') {
                scanf("%d", &u);
                f[u] = U;
            }
            else if(ch == 'F') {
                scanf("%d", &u);
                f[u] = F;
            }
        }
        /*
        for(int u = 1, fu; u <= n; u++) {
            if(f[u] == U) cnt++;
            else if(f[u] == T || f[u] == F) continue;
            else {
                fu = fand(u);
                if(w[fu] == 1) f[fu] = U, w[fu] = 0;
                if(fu == U) cnt++;
            }
        }*/

        for(int i = 1; i <= n; i++) {
            if(!vis[i]) dfs(i);
            if(fand(i) == U) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}


/*

10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
