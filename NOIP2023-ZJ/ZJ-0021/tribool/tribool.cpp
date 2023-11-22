#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define MT make_tuple
#define IT iterator
#define fi first
#define se second
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Rep(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define CLR(a, v) memset(a, v, sizeof(a))
#define CPY(a, b) memcpy(a, b, sizeof(a))
#define debug cout << "ztxakking\n"
#define y0 ztxakioi
#define y1 ztxaknoi
using namespace std;
using ll = long long;
using ull = unsigned ll;
using uint = unsigned;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vi = vector <int>;
template <typename T>
using V = vector <T>;
mt19937 gen(time(0));
const int N = 1e5 + 7, inf = 1e9;
int n, m, x[N];
int no(int x) {
    if (x <= n) return -x;
    if (x == n + 1) return n + 2;
    if (x == n + 2) return n + 1;
    return n + 3;
}
V <pii> G[N];
bool vis[N];
vi ve;
void dfs(int u) {
    if (vis[u]) return ;
    vis[u] = 1;
    ve.pb(u);
    for (auto [v, w] : G[u]) {
        if (w == 1) x[v] = x[u];
        else x[v] = no(x[u]);
        dfs(v);
    }
}
void solve() {
    cin >> n >> m;
    For(i, 1, n) x[i] = i;
    while (m--) {
        char op; cin >> op;
        if (op == 'T' || op == 'U' || op == 'F') {
            int y; cin >> y;
            if (op == 'T') x[y] = n + 1;
            else if (op == 'U') x[y] = n + 3;
            else x[y] = n + 2;
        } else if (op == '+') {
            int i, j; cin >> i >> j;
            x[i] = x[j];
        } else {
            int i, j; cin >> i >> j;
            x[i] = no(x[j]);
        }
    }
    For(i, 1, n + 3) G[i].clear();
    auto add = [&] (int u, int v, int w) -> void {
        G[u].pb(MP(v, w)), G[v].pb(MP(u, w));
    };
    For(i, 1, n) {
        if (x[i] == n + 1) add(i, n + 1, 1);
        else if (x[i] == n + 2) add(i, n + 2, 1);
        else if (x[i] == n + 3) add(i, n + 3, 1);
        else {
            int v = abs(x[i]);
            if (x[i] < 0) add(i, v, -1);
            else add(i, v, 1);
        }
    }
    CLR(x, 0), CLR(vis, 0);
    For(i, n + 1, n + 3) x[i] = i;
    ve.clear();
    dfs(n + 1), dfs(n + 2), dfs(n + 3);
    int ans = 0;
    for (auto i : ve) if (i <= n && x[i] == n + 3) ++ans;
    For(i, 1, n) if (!vis[i]) {
        ve.clear();
        int now = inf;
        For(j, n + 1, n + 3) {
            for (auto k : ve) vis[k] = 0;
            ve.clear();
            x[i] = j;
            dfs(i);
            int num = 0;
            for (auto k : ve) {
                for (auto [v, w] : G[k]) {
                    if (w == 1 && x[v] != x[k]) num = inf;
                    if (w == -1 && x[v] != no(x[k])) num = inf;
                }
            }
            for (auto k : ve) if (k <= n && x[k] == n + 3) ++num;
            now = min(now, num);
        }
        ans += now;
    }
    cout << ans << '\n';
}
int main() {
    // double start = clock();
    freopen("tribool.in", "r", stdin), freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, t; cin >> c >> t;
    while (t--) solve();
    // cerr << (clock() - start) / CLOCKS_PER_SEC << '\n';
    return 0;
}