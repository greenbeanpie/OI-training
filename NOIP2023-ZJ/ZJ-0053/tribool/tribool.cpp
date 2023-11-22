#include <bits/stdc++.h>
using namespace std;
#define fo(v, a, b) for(int v = a; v <= b; v++)
#define fr(v, a, b) for(int v = a; v >= b; v--)
#define cl(a, v) memset(a, v, sizeof(a))

const int N = 1e5 + 10;

int n, m, ans;

struct sta {
    int o, v;
    inline sta inv() {  return {o, -v};  }
    // o = 0 stands for x_i = v (-1 = F, 0 = U, 1 = T)
    // o = 1 stands for x_i = x_v(v > 0) or x_i = -x_{-v}(v < 0)
} a[N];

int fa[N], siz[N]; vector<int> g[N];
int get(int x) {  return fa[x] == x ? x : fa[x] = get(fa[x]);  }
inline void merge(int x, int y) {  fa[get(x)] = get(y);  }

int col[N]; bool vis[N], ulim[N]; int S; bool ULIM;
void work(int x) {
    S += siz[x], ULIM |= ulim[x], vis[x] = true;
    for(int y : g[x]) if(!vis[y]) work(y);
}
bool dfs(int x) {
    for(int y : g[x]) {
        if(!col[y]) {
            col[y] = 3 - col[x];
            if(!dfs(y)) return false;
        } else if(col[x] == col[y])
            return false;
    }
    return true;
}

void reset() {
    cl(a, 0), ans = 0, cl(fa, 0), cl(siz, 0);
    cl(vis, 0), cl(col, 0), cl(ulim, 0);
    fo(i, 1, n) g[i].clear();
}
void Main() {
    scanf("%d%d", &n, &m), reset();
    fo(i, 1, n) a[i] = {1, i};
    fo(i, 1, m) {
        char s[10]; int x, y; scanf("%s%d", s, &x);
        if(s[0] == '+') {
            scanf("%d", &y), a[x] = a[y];
        } else if(s[0] == '-') {
            scanf("%d", &y), a[x] = a[y].inv();
        } else {
            a[x].o = 0;
            if(s[0] == 'T') a[x].v = 1;
            else if(s[0] == 'F') a[x].v = -1;
            else a[x].v = 0;
        }
    }

    // fo(i, 1, n) printf("i = %d %d %d\n", i, a[i].o, a[i].v);

    fo(i, 1, n) fa[i] = i;
    fo(i, 1, n) if(a[i].o && a[i].v > 0)
        merge(i, a[i].v);
    fo(i, 1, n) {
        siz[get(i)]++;
        if(a[i].o == 0 && a[i].v == 0)
            ulim[get(i)] = true;
    }
    fo(i, 1, n) if(a[i].o && a[i].v < 0) {
        int p = -a[i].v, u = get(i), v = get(p);
        g[u].push_back(v), g[v].push_back(u);
    }

    fo(i, 1, n) if(fa[i] == i && !vis[i]) {
        S = ULIM = 0, work(i), col[i] = 1;
        if(!dfs(i) || ULIM) ans += S;
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int ID, T; scanf("%d%d", &ID, &T);
    while(T--) Main();

    return 0;
}