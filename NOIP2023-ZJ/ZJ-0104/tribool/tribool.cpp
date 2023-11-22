#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

const int N = 1e5 + 5;

vector<pr> v[N];

int f[N], type[N], val[N], vis[N], Vis[N];
int cnt, now, Now;

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

char get() {
    char ch = getchar();
    while (ch != '-' && ch != '+' && ch != 'U' && ch != 'T' && ch != 'F') ch = getchar();
    return ch;
}

void dfs(int ro, int len) {
    if (vis[ro] == Now) {
        if (len & 1) now = 1;
        else now = 0;
        return;
    }

    if (vis[ro]) return;

    vis[ro] = Now;

    for (auto to : v[ro]) {
        int u = to.first, val = to.second;
        dfs(u, len + val);
    }
}

void solve(int ro) {
    cnt++;
    Vis[ro] = 1;

    for (auto to : v[ro]) {
        int u = to.first;
        if (!Vis[u]) solve(u);
    }
}

signed main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int t = read();
    t = read();

    while (t--) {
        int n = read(), q = read();

        for (int i = 1; i <= n; i++) f[i] = i, type[i] = val[i] = 0;

        while (q--) {
            char ch = get();

            if (ch == 'U') {
                int x = read();
                f[x] = x;
                type[x] = 0;
                val[x] = 4;
            }
            if (ch == 'T') {
                int x = read();
                f[x] = x;
                type[x] = 0;
                val[x] = 2;
            }
            if (ch == 'F') {
                int x = read();
                f[x] = x;
                type[x] = 0;
                val[x] = 3;
            }
            if (ch == '-') {
                int y = read(), x = read();
                if (val[x]) {
                    f[y] = y;
                    type[y] = 0;
                    if (val[x] == 4) val[y] = 4;
                    else val[y] = val[x] ^ 1;
                }
                else {
                    f[y] = f[x];
                    type[y] = type[x] ^ 1;
                    val[y] = 0;
                }
            }
            if (ch == '+') {
                int y = read(), x = read();
                if (val[x]) {
                    f[y] = y;
                    type[y] = 0;
                    val[y] = val[x];
                }
                else {
                    f[y] = f[x];
                    type[y] = type[x];
                    val[y] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++) vis[i] = Vis[i] = 0;

        for (int i = 1; i <= n; i++) {
            v[f[i]].pb({i, type[i]});
        }

        int ans = 0;
        Now = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            now = -1;
            Now++;
            dfs(i, 0);
            if (now != -1) {
                cnt = 0;
                solve(i);
                if (now || val[i] == 4) ans += cnt;
            }
        }

        for (int i = 1; i <= n; i++) v[i].clear();

        write(ans);
        putchar('\n');
    }
}