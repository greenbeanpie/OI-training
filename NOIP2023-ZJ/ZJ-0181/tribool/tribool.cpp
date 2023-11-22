#include <bits/stdc++.h>
using namespace std;
int c, t;
inline int read_positive() noexcept {
    int x = 0, ch = 0;
    for (; !isdigit(ch); ch = getchar());
    for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    return x;
}
inline char getchar_without_blanks() noexcept {
    char ch = 0;
    for (; ch <= 32; ch = getchar());
    return ch;
}
namespace problem {

int n, m;
int a[100100];
bool flag[200200];
int fa[200200];
int getfa(int x) {
    // printf("getfa: %d %d\n", x, fa[x]);
    return fa[x] < 0 ? x : (fa[x] = getfa(fa[x]));
}
void merge(int x, int y) {
    int fx = getfa(x), fy = getfa(y);
    if (fx == fy)
        return ;
    if (fa[fx] > fa[fy])
        fa[fy] += fa[fx], fa[fx] = fy;
    else
        fa[fx] += fa[fy], fa[fy] = fx;
}
void main() {
    n = read_positive(), m = read_positive();
    // printf("%d %d\n", n, m);
    for (int i = 1; i <= n + 1; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        char op = getchar_without_blanks();
        int x = read_positive(), y;
        if (isupper(op)) {
            if (op == 'U')
                a[x] = 0;
            else if (op == 'T')
                a[x] = n + 1;
            else
                a[x] = -n - 1;
        } else {
            y = read_positive();
            if (op == '-')
                a[x] = -a[y];
            else
                a[x] = a[y];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n * 2 + 2; i++)
        fa[i] = -1, flag[i] = 0;
    for (int i = 1; i <= n; i++) {
        // printf("%d ", a[i]);
        if (a[i] > 0) {
            merge(i, a[i]);
            merge(n + i + 1, n + a[i] + 1);
        } else if (a[i] < 0) {
            merge(i, n + 1 - a[i]);
            merge(-a[i], n + 1 + i);
        } else 
            merge(i, 0);
    }
    for (int i = 1; i <= n; i++) {
        if (getfa(i) == getfa(0) || getfa(i) == getfa(n + i + 1))
            flag[getfa(i)] = flag[getfa(n + i + 1)] = 1;
    }
    // printf("\n");
    for (int i = 1; i <= n; i++) {
        ans += flag[getfa(i)];
    }
    printf("%d\n", ans);
}

} // namespace problem
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    // auto beg = chrono::steady_clock::now();
    c = read_positive(), t = read_positive();
    for (int _ = 1; _ <= t; _++)
        problem :: main();
    // auto ed = chrono::steady_clock::now();
    // cerr << (ed - beg).count() << endl;
    return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/