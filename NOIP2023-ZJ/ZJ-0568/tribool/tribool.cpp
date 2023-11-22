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

constexpr int N = 1e5 + 10;

int n, m;
char ori[N], op[N];

char no(int i) {
    // if (op[i] == 'N') {
    //     op[i] = ori[i] = 'T';
    //     return 'F';
    // } else 
    if (op[i] == 'T') {
        return 'F';
    } else if (op[i] == 'F') {
        return 'T';
    } else {
        return 'U';
    }
}

struct Node {
    char o;
    int a, b;
    Node(char _o = 0, int _a = 0, int _b = 0)
        : o(_o), a(_a), b(_b) {
    }
};

Node a[N];

int ans;

void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= n; ++ i) {
            op[i] = ori[i];
        }
        for (int i = 1; i <= m; ++ i) {
            if (a[i].o == '+') {
                // if (op[a[i].b] == 'N') {
                //     op[a[i].b] = ori[a[i].b] = 'T';
                // }
                op[a[i].a] = op[a[i].b];
            } else if (a[i].o == '-') {
                op[a[i].a] = no(a[i].b);
            } else if (a[i].o == 'T' || a[i].o == 'F' || a[i].o == 'U') {
                op[a[i].a] = a[i].o;
            }
        }

        for (int i = 1; i <= n; ++ i) {
            if (op[i] != ori[i]) {
                return;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++ i) {
            cnt += (ori[i] == 'U');
        }
        // if (cnt == 1) {
        //     for (int i = 1; i <= n; ++ i) {
        //         printf("%c ", ori[i]);
        //     }
        //     puts("");
        //     for (int i = 1; i <= n; ++ i) {
        //         printf("%c ", op[i]);
        //     }
        //     puts("");
        // }
        ans = std::min(ans, cnt);

        return;
    }
    ori[x] = op[x] = 'T';
    dfs(x + 1);
    ori[x] = op[x] = 'F';
    dfs(x + 1);
    ori[x] = op[x] = 'U';
    dfs(x + 1);
}

std::vector<int> e[N];
bool vis[N];

void dfs2(int x) {
    for (const auto & y : e[x]) {
        if (!vis[y]) {
            vis[y] = true;
            if (op[x] == 'U' || op[y] == 'U') {
                op[x] = op[y] = 'U';
            }
            dfs(y);
        } else {
            if (op[x] == 'U' || op[y] == 'U') {
                op[x] = op[y] = 'U';
            }
        }
    }
}

signed main() {
    std::freopen("tribool.in", "r", stdin);
    std::freopen("tribool.out", "w", stdout);

    int test_case, T;

    read(test_case);
    read(T);

    while (T --) {
        read(n);
        read(m);

        for (int i = 1; i <= n; ++ i) {
            ori[i] = op[i] = 'N';
        }
        ans = n;

        for (int i = 1; i <= m; ++ i) {
            std::string s;
            read(s);
            if (s[0] == '+' || s[0] == '-') {
                int x, y;
                read(x);
                read(y);
                a[i] = {s[0], x, y};
            } else {
                int x;
                read(x);
                a[i] = {s[0], x, 0};
            }
        }
        
        if (test_case == 1 || test_case == 2) {
            dfs(1);
        } else {
            ans = 0;
            for (int i = 1; i <= 200000; ++ i) {
                e[i].clear();
                vis[i] = false;
            }
            int t = n;
            for (int i = 1; i <= m; ++ i) {
                if (a[i].o == 'U') {
                    ++ t;
                    op[t] = 'U';
                    e[a[i].a].emplace_back(t);
                    e[t].emplace_back(a[i].a);
                } else {
                    e[a[i].a].emplace_back(a[i].b);
                    e[a[i].b].emplace_back(a[i].a);
                }
            }
            for (int i = 1; i <= n; ++ i) {
                if (!vis[i]) {
                    vis[i] = true;
                    dfs2(i);
                }
            }
            for (int i = 1; i <= n; ++ i) {
                ans += (op[i] == 'U');
            }
        }
        // for (int i = 1; i <= n; ++ i) {
        //     printf("%c ", ori[i]);
        // }
        // puts("");

        printf("%d\n", ans);
    }

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
/*
0
3
1
*/
