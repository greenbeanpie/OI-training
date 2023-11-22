#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

inline int read() {
    char c; bool f = true;
    while (!isdigit(c = getchar())) f = c != '-';
    int x = c ^ 48;
    while (isdigit(c = getchar())) x = x * 10 + (c ^ 48);
    return f ? x : -x;
}

const int N = 500010;
const int Q = 70;

int C, n, m, q, a[N], b[N];
int qry, ans[Q];
int aa[N], bb[N], kx, ky, p, v;

inline void reset() {
    for (int i = 1; i <= n; i++) {
        aa[i] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        bb[i] = b[i];
    }
}

// namespace specialtask {

//     inline void solve() {
//         qry++;
//         int maxa = aa[2];
//         for (int i = 3; i <= n; i++) {
//             maxa = max(maxa, aa[i]);
//         }
//         int minb = bb[1];
//         for (int i = 2; i <= m - 1; i++) {
//             minb = min(minb, bb[i]);
//         }
//         if (aa[1] < minb && bb[m] > maxa) {
//             ans[qry] = 1;
//         } else {
//             ans[qry] = 0;
//         }
//     }

//     inline int main() {
//         solve();
//         for (int i = 1; i <= q; i++) {
//             for (int j = 1; j <= n; j++) {
//                 aa[j] = a[j];
//             }
//             for (int j = 1; j <= m; j++) {
//                 bb[j] = b[j];
//             }
//             kx = read(); ky = read();
//             for (int j = 1; j <= kx; j++) {
//                 p = read(); v = read();
//                 if (p == 1) {
//                     cerr << "change a[1] to " << v << endl;
//                 }
//                 aa[p] = v;
//             }
//             // cerr << "read x: " << kx << endl;
//             for (int j = 1; j <= ky; j++) {
//                 p = read(); v = read();
//                 if (p == 39582) {
//                     cerr << "change b[39582] to " << v << endl;
//                 }
//                 bb[p] = v;
//             }
//             // cerr << "read y: " << ky << endl;
//             solve();
//         }
//         for (int i = 1; i <= qry; i++) {
//             printf("%d", ans[i]);
//         }
//         puts("");
//         return 0;
//     }
// }

// namespace subtask1 {
//     const int M = 2010;
//     int f[M], val[M];
//     inline bool check() {
//         if (aa[1] == bb[1]) return false;

//         if (aa[1] > bb[1]) {
//             memset(f, -1, sizeof(f));
//             f[0] = 0;
//             for (int i = 1; i <= n; i++) {
//                 if (f[i - 1] == -1) continue;
//                 int minn = 0x7fffffff;
//                 int r = f[i - 1];
//                 // val[r] = 0;
//                 // while (r <= m) {
//                 //     r++;
//                 //     val[r] = max(val[r - 1], bb[r]);
//                 // }
//                 val[0] = 0;
//                 for (int j = 1; j <= m; j++) {
//                     val[j] = max(val[j - 1], bb[j]);
//                 }
//                 r = m;
//                 for (int j = i; j <= n; j++) {
//                     if (aa[j] < minn) {
//                         // zui xiao zhi geng xin le!
//                         minn = aa[j];
//                         while (r > 0 && val[r] >= minn) {
//                             r--;
//                         }
//                         if (r > 0) {
//                             f[j] = max(f[j], r);
//                         } else {
//                             break;
//                         }
//                     } else {
//                         f[j] = max(f[j], f[j - 1]);
//                     }
//                 }
//             }
//         } else {
//             return false;
//         }
//         return f[n] == m;
//     }
// }

inline bool dfs(int x, int y) {
    if (x == n + 1 && y == m + 1) {
        return true;
    } else if (x == n + 1 || y == m + 1) {
        return false;
    }
    int m1 = aa[x];
    for (int i = x; i <= n; i++) {
        int m2 = bb[y];
        m1 = min(m1, aa[i]);
        for (int j = y; j <= m; j++) {
            m2 = max(m2, bb[j]);
            if (m1 > m2) {
                if (dfs(i + 1, j + 1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

inline void solve() {
    ans[qry] |= dfs(1, 1);
    // if (C <= 7) {
    //     // cout << "SOLVING" << endl;
    //     // cout << "A: ";
    //     // for (int i = 1; i <= n; i++) {
    //     //     cout << aa[i] << " ";
    //     // }
    //     // puts("");
    //     // cout << "B: ";
    //     // for (int i = 1; i <= n; i++) {
    //     //     cout << bb[i] << " ";
    //     // }
    //     // puts("");

    //     ans[qry] |= subtask1::check();
    // }
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    C = read(), n = read(); m = read(), q = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        b[i] = read();
    }
    reset();
    qry++;
    solve();
    swap(aa, bb);
    swap(n, m);
    solve();
    swap(aa, bb);
    swap(n, m);
    for (int i = 1; i <= q; i++) {
        kx = read(); ky = read();
        for (int j = 1; j <= kx; j++) {
            p = read(); v = read();
            aa[p] = v;
        }
        for (int j = 1; j <= ky; j++) {
            p = read(); v = read();
            bb[p] = v;
        }
        qry++;
        solve();
        swap(aa, bb);
        swap(n, m);
        solve();
        swap(aa, bb);
        swap(n, m);
        reset();
    }
    for (int i = 1; i <= qry; i++) {
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
    // if (8 <= C && C <= 14) {
    //     return specialtask::main();
    // }
}
/*
bu hui kai shu ru fa!!!!
/fn
ba A B hua fen cheng ruo gan duan
ru guo a[1] > b[1] na me
dui yu mei yi duan dou you min{a} > max{b}
a[1] < b[1] jiu fan guo lai!
xian zhao dao min{a}
kao lv ba min{a} fang zai na yi duan (???)

3 3 3 0
8 6 9
1 7 4

3 3 3 0
8 6 0
1 7 4

4 6 6 0
908769963 747202998 695274448 912972658 681355925 855511382
741380908 725577864 753807716 615096979 827516564 688016923

4 6 6 0
8 4 12 2 6 10
3 7 11 1 9 5

8 4   12     2 6    10
3     7 11    1    9 5

4 6 6 0
11 7 4 12 2 10
6 5 8 1 9 3

4 3 3 0
11 2 10
6 9 3

4 2 2 0
11 10
6 9

4 912972658
6 855511382
1 908769963
5 681355925
3 695274448
2 747202998

3 753807716
1 741380908
6 688016923
5 827516564
4 615096979
2 725577864

xie le liang ge zuo fa
quan jia le
wo xie bao li le
/xs
*/