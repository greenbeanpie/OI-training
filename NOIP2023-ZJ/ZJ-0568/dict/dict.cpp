#include <bits/stdc++.h>

template<class T>
void read(T & x) {
    x = 0;
    bool f = false;
    char c = getchar();
    while (!isdigit(c)) f |= (c == '-'), c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    x = (f ? -x : x);
}

void read(std::string & x) {
    x = "";
    char c = getchar();
    while (!isgraph(c)) c = getchar();
    while (isgraph(c)) x += c, c = getchar();
}

constexpr int N = 3000 + 10;

int n, m;
std::string s[N];
char mx[N], mn[N];

signed main() {
    std::freopen("dict.in", "r", stdin);
    std::freopen("dict.out", "w", stdout);

    read(n);
    read(m);

    for (int i = 1; i <= n; ++ i) {
        read(s[i]);
        mn[i] = mx[i] = s[i][0];
        for (int j = 1; j < m; ++ j) {
            if (s[i][j] > mx[i]) {
                mx[i] = s[i][j];
            }
            if (s[i][j] < mn[i]) {
                mn[i] = s[i][j];
            }
        }
        // printf("%c %c\n", mn[i], mx[i]);
    }

    for (int i = 1; i <= n; ++ i) {
        bool ok = true;
        for (int j = 1; j <= n; ++ j) {
            if (i != j) {
                if (mn[i] >= mx[j]) {
                    ok = false;
                    break;
                }
            }
        }
        printf("%d", (int)(ok));
    }
    puts("");

    return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn

*/
/*
1110
*/
