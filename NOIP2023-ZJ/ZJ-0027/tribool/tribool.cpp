#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T &r) {
    r = 0; int ch = getchar(), f = 0;
    while (!isdigit(ch)) f ^= (ch == 45), ch = getchar();
    while (isdigit(ch)) (r *= 10) += ch - 48, ch = getchar();
    if (f) r = -r;
}

const int maxn = 1e5 + 5;
int __, _, n, m;
int a[maxn << 1], f[maxn << 1];
bool tag[maxn << 1], ans[maxn << 1];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    read(__); read(_);
    while (_--) {
        read(n); read(m);
        memset(ans, 0, sizeof ans);
        memset(tag, 0, sizeof tag);
        for (int i = 1; i <= n + 3; i++) a[i] = i;
        for (int i = 1; i <= 2 * n + 6; i++) f[i] = i;
        for (int i = 1; i <= m; i++) {
            char op = getchar(); while (!isalpha(op) && op != '+' && op != '-') op = getchar();
            if (op == 'T') {
                int id; read(id);
                a[id] = n + 1;
            } else if (op == 'F') {
                int id; read(id);
                a[id] = n + 2;
            } else if (op == 'U') {
                int id; read(id);
                a[id] = n + 3;
            } else if (op == '+') {
                int u, v; read(u); read(v);
                a[u] = a[v];
            } else {
                int u, v; read(u); read(v);
                a[u] = -a[v];
            }
        }
        for (int i = 1; i <= n + 3; i++) {
            // cerr << a[i] << " \n"[i == n + 3];
            int u = i, v = (a[i] < 0 ? -a[i] + n + 3 : a[i]);
            u = find(u), v = find(v);
            if (u != v) f[v] = u;
            u = i + n + 3, v = (a[i] < 0 ? -a[i] : a[i] + n + 3); 
            u = find(u), v = find(v);
            if (u != v) f[v] = u;
        }
        for (int i = 1; i <= n; i++) {
            if (find(i) == find(i + n + 3) || find(i) == find(n + 3) || find(i) == find(2 * n + 6)) {
                ans[i] = true; tag[find(i)] = true;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (tag[find(i)]) ans[i] = true;
            sum += ans[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}