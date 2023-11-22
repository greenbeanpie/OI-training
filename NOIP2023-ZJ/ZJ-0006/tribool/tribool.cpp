#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 10;
int n, m;
vi g[N];
pii x[N];
int mp[256];
int done[N], cnt[4], vis[N], odd;
void adde(int u, int v) {g[u].emplace_back(v); }
void dfs(int u) {
    cnt[done[u]] += 1;
    for(auto v : g[u]) {
        if(vis[v] == -1) {
            vis[v] = vis[u] ^ 1;
            dfs(v);
        } else if(vis[v] != (vis[u] ^ 1)) {
            odd = 1;
        }
    }
}
void Main() {
    cin >> n >> m;
    FOR(i, 1, n) {
        x[i] = {i, 0};
        g[i].clear(), g[i + n].clear();
    }
    FOR(i, 1, m) {
        char op;
        cin >> op;
        if(op == '+') {
            int a, b;
            cin >> a >> b;
            x[a] = x[b];
        } else if(op == '-') {
            int a, b;
            cin >> a >> b;
            x[a] = x[b];
            x[a].second ^= 1;
        } else {
            int a, v;
            cin >> a;
            v = mp[op];
            x[a] = {-v, 0};
        }
    }
    FOR(i, 1, n) {
        done[i] = 3;
        adde(i, i + n), adde(i + n, i);
        if(x[i].first <= 0) {
            int t = -x[i].first;
            done[i] = min(t ^ x[i].second, 2);
        } else {
            int to = x[i].first;
            if(x[i].second) {
                adde(i, to), adde(to, i);
            } else {
                adde(i, to + n), adde(to + n, i);
            }
        }
    }
    FOR(i, 1, n * 2) vis[i] = -1;
    int ans = 0;
    FOR(i, 1, n) if(vis[i] == -1) {
        odd = 0;
        FOR(j, 0, 3) cnt[j] = 0;
        vis[i] = 0;
        dfs(i);
        int all = 0;
        FOR(j, 0, 3) all += cnt[j];
        if(odd || cnt[2]) ans += all / 2;
    }
    cout << ans << "\n";
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mp['T'] = 0, mp['F'] = 1, mp['U'] = 2;
    int c, t;
    cin >> c >> t;
    FOR(C, 1, t) Main();
}