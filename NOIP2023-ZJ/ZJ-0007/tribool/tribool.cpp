#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int C, T;
int n, m;
int lst[N], cnt, c[N << 1], tc[N << 1];
int head[N << 1], nxt[N << 2], ver[N << 2], edge[N << 2], idx;

inline void add(int u, int v, int w) {
    nxt[++idx] = head[u];
    head[u] = idx;
    ver[idx] = v;
    edge[idx] = w;
}

bool try_draw(int u, int col) {
    tc[u] = col;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ver[i], w = edge[i];
        if (tc[v] == 114514) {
            if (!try_draw(v, tc[u] * w))
                return 0;
        } else if (tc[v] != tc[u] * w)
            return 0;
    }
    return 1;
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> C >> T;
    while (T--) {
        cin >> n >> m;
        idx = 0; cnt = n;
        memset(lst, 0, sizeof lst);
        memset(head, 0, sizeof head);
        memset(nxt, 0, sizeof nxt);
        memset(ver, 0, sizeof ver);
        memset(edge, 0, sizeof edge);
        for (int i = 1; i <= n + m; i++)
            tc[i] = 114514;
        for (int i = 1; i <= n; i++)
            lst[i] = i, c[i] = 114514;
        for (int i = 1; i <= m; i++) {
            char furina;
            cin >> furina;
            if (furina == '+') {
                int u, v; cin >> u >> v;
                c[++cnt] = 114514;
                if (c[lst[v]] != 114514)
                    c[cnt] = c[lst[v]];
                add(lst[v], cnt, 1);
                add(cnt, lst[v], 1);
                lst[u] = cnt;
            } else if (furina == '-') {
                int u, v; cin >> u >> v;
                c[++cnt] = 114514;
                if (c[lst[v]] != 114514)
                    c[cnt] = -c[lst[v]];
                add(lst[v], cnt, -1);
                add(cnt, lst[v], -1);
                lst[u] = cnt;
            } else {
                int u; cin >> u;
                if (furina == 'T') c[++cnt] = 1;
                else if (furina == 'F') c[++cnt] = -1;
                else c[++cnt] = 0;
                lst[u] = cnt;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (c[lst[i]] != 114514)
                q.push(lst[i]);
            if (i != lst[i])
                add(i, lst[i], 1), add(lst[i], i, 1);
        }
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i; i = nxt[i]) {
                int v = ver[i], w = edge[i];
                if (c[v] == 114514) {
                    c[v] = c[u] * w;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            if (c[i] == 114514) {
                if (try_draw(i, 1)) c[i] = 1;
                else c[i] = 0;
                q.push(i);
                while (q.size()) {
                    int u = q.front(); q.pop();
                    for (int i = head[u]; i; i = nxt[i]) {
                        int v = ver[i], w = edge[i];
                        if (c[v] == 114514) {
                            c[v] = c[u] * w;
                            q.push(v);
                        }
                    }
                }
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (c[i] == 0)
                ans++;
        cout << ans << '\n';
    }
    return 0;
}