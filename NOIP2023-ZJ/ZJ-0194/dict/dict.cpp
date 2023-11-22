#include <bits/stdc++.h>
using namespace std;
const int N = 3030;
int n, m;
char a[N][N];
struct Str{
    int id;
    char ch[N];
    bool operator<(const Str &x) const{
        for (int i = 1; i <= m; ++i)
            if (ch[i] != x.ch[i])
                return ch[i] < x.ch[i];
        return 0;
    }
} b[N];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        sort(a[i] + 1, a[i] + m + 1);
        for (int j = 1; j <= m; ++j)
            b[i].ch[j] = a[i][m - j + 1];
        b[i].id = i;
    }
    if (n == 1) {
        puts("1");
        return 0;
    }
    sort (b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        int px = 1;
        if (b[1].id == i)
            ++px;
        bool flag = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != b[px].ch[j]) {
                if (a[i][j] < b[px].ch[j])
                    flag = 1;
                else
                    flag = 0;
                break;
            }
        }
        if (flag == 1)
            putchar('1');
        else
            putchar('0');
    }
    puts("");
    return 0;
}