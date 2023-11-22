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

const int N = 3010;
const int M = 3010;

int n, m, a[N][M], b[N][M], c[M];
int pre[N][M], suf[M];
bool ans[N];
// string s;
char s[M];

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    // unsigned clk = clock();
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        // cin >> s;
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1] - 'a' + 1;
            b[i][j] = a[i][j];
        }
        sort(b[i] + 1, b[i] + m + 1, greater<int>());
    }
    for (int i = 1; i <= m; i++) {
        pre[1][i] = b[1][i];
        pre[0][i] = 666;
        suf[i] = 666;
    }
    for (int i = 2; i <= n; i++) {
        bool bg = false;
        for (int j = 1; j <= m; j++) {
            if (b[i][j] < pre[i - 1][j]) {
                bg = true;
                break;
            } else if (b[i][j] > pre[i - 1][j]) {
                break;
            }
        }
        if (bg) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = b[i][j];
            }
        } else {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = pre[i - 1][j];
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            c[j] = a[i][j];
        }
        sort(c + 1, c + m + 1);

        bool sm1 = false;
        for (int j = 1; j <= m; j++) {
            if (c[j] < pre[i - 1][j]) {
                sm1 = true;
                break;
            } else if (c[j] > pre[i - 1][j]) {
                sm1 = false;
                break;
            }
        }

        ans[i] = false;
        bool sm2 = false;
        if (sm1) {
            for (int j = 1; j <= m; j++) {
                if (c[j] < suf[j]) {
                    sm2 = true;
                    break;
                } else if (c[j] > suf[j]) {
                    sm2 = false;
                    break;
                }
            }
            if (sm2) {
                ans[i] = true;
            }
        }

        bool bi = false;
        for (int j = 1; j <= m; j++) {
            if (b[i][j] < suf[j]) {
                bi = true;
                break;
            } else if (b[i][j] > suf[j]) {
                break;
            }
        }
        if (bi) {
            for (int j = 1; j <= m; j++) {
                suf[j] = b[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            printf("1");
        } else {
            printf("0");
        }
    }
    puts("");
    // cerr << clock() - clk << endl;
    return 0;
}
/*
template.cpp

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

const int N = 3010;
const int M = 3010;

int n, m, a[N][M];

int main() {
    // freopen("dict.in", "r", stdin);
    // freopen("dict.out", "w", stdout);
    n = read(); m = read();
}
*/