#include <bits/stdc++.h>
using namespace std;
const int N = 100100, inf = 0x3f3f3f3f;
int c, t, n, m, ans;
char ch;
int deg[N];
struct Circle{
    int k, x, b;
    void mem(int _x) {
        k = 1, x = _x, b = 0;
        return;
    }
    int calc(int val) {
        return k * val + b;
    }
    Circle() {}
    Circle(int _k, int _x, int _b)
        : k(_k), x(_x), b(_b) {}
} to[N];
void rdch(char &x) {
    x = getchar();
    while (x != 'T' && x != 'F' && x != 'U' && x != '+' && x != '-')
        x = getchar();
    return;
}
struct Edge{
    int nxt;
    int to;
    Circle w;
    Edge() {}
    Edge(int _nxt, int _to, Circle _w)
        : nxt(_nxt), to(_to), w(_w) {}
} e[N << 2];
int h[N], cnt;
void add(int u, int v, Circle w) {
    e[++cnt] = Edge(h[u], v, w);
    h[u] = cnt;
    return;
}
int val[N];
int fa[N];
int lst[N];
int vis[N];
bool cld[N];
bool OnCir[N << 2];
int Uncnt, cur, SpecEdge;
vector<int> Cirnode;
void Min(int &x, int y) {
    if (x > y)
        x = y;
    return;
}
void CalcTreeVal(int u) {
    vis[u] = cur;
    if (val[u] == 1)
        ++Uncnt;
    for (int i = h[u]; i; i = e[i].nxt) {
        if (OnCir[i])
            continue;
        int v = e[i].to;
        Circle w = e[i].w;
        val[v] = w.calc(val[u]);
        CalcTreeVal(v);
    }
    return;
}
void FindCircle(int u) {
    vis[u] = cur;
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) {
            int now = u;
            while (now != v) {
                Cirnode.push_back(now);
                OnCir[lst[now]] = 1;
                now = fa[now];
            }
            Cirnode.push_back(v);
            OnCir[i] = 1;
            SpecEdge = i;
            continue;
        }
        lst[v] = i;
        FindCircle(v);
    }
    return;
}
int CalcVal(int u) {
    Cirnode.clear(), Uncnt = 0, ++cur;
    int ans = inf;
    if (!u)
        return CalcTreeVal(u), Uncnt;
    FindCircle(u);
    if (!Cirnode.size()) {
        puts("situ 1");
        val[u] = 0, Uncnt = 0, CalcTreeVal(u), Min(ans, Uncnt);
        val[u] = 1, Uncnt = 0, CalcTreeVal(u), Min(ans, Uncnt);
        val[u] = 2, Uncnt = 0, CalcTreeVal(u), Min(ans, Uncnt);
        return ans;
    }
    u = Cirnode[0];
    int v = Cirnode[Cirnode.size() - 1];
    for (val[v] = 0; val[v] < 3; ++val[v]) {
        for (int i = Cirnode.size() - 1; i > 0; --i) {
            int uu = Cirnode[i], vv = Cirnode[i - 1];
            Circle chk = e[lst[vv]].w;
            val[vv] = chk.calc(val[uu]);
        }
        if (val[v] != e[SpecEdge].w.calc(val[u]))
            continue;
        Uncnt = 0;
        for (int x : Cirnode)
            CalcTreeVal(x);
        Min(ans, Uncnt);
    }
    return ans;
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for (int __ = 1; __ <= t; ++__) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            to[i].mem(i);
        memset(deg, 0, sizeof deg);
        memset(h, 0, sizeof h);
        memset(OnCir, 0, sizeof OnCir);
        memset(vis, 0, sizeof vis);
        memset(cld, 0, sizeof cld);
        cnt = cur = ans = 0;
        for (int i = 1, u, v; i <= m; ++i) {
            rdch(ch);
            if (ch == '+') {
                scanf("%d%d", &u, &v);
                to[u] = to[v];
            }
            else if (ch == '-') {
                scanf("%d%d", &u, &v);
                to[u] = to[v];
                to[u].k = - to[u].k, to[u].b = -to[u].b + 2;
            }
            else {
                scanf("%d", &u);
                to[u].k = to[u].x = to[u].b = 0;
                if (ch == 'U')
                    to[u].b = 1;
                else if (ch == 'T')
                    to[u].b = 2;
            }
        }
        for (int u = 1, v; u <= n; ++u) {
            v = to[u].x;
            fa[u] = v;
            add(v, u, to[u]);
            ++deg[u];
        }
        val[0] = 0;
        ans += CalcVal(0);
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
            	int u = i;
            	cld[u] = 1;
            	while (1) {
            		u = fa[u];
            		if (cld[u]) {
            			ans += CalcVal(u);
            			break;
					}
					cld[u] = 1;
				}
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}