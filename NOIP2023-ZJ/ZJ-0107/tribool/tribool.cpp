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

const int N = 100010;

int C, T;
int n, m;
char op;
int x, y;
struct edge {
    int v;
    bool ty;
    edge(int v = 0, bool ty = false) : v(v), ty(ty) {}
};
vector<edge> g[N], invg[N];
int v[N];
bool t[N];
int ans[N];

inline int nt(int x) {
    if (x == 1) return 2;
    if (x == 2) return 1;
    if (x == 3) return 3;
    return -1;
}

inline void dfs(int x) {
    for (auto y : g[x]) {
        if (y.v == x) {
            if (y.ty == 1) {
                assert(ans[x] == 3);
            }
            continue;
        }
        if (ans[y.v] == -1) {
            if (y.ty == 0) {
                ans[y.v] = ans[x];
            } else {
                ans[y.v] = nt(ans[x]);
            }
            dfs(y.v);
        }
    }
}

stack<int> stk;
int ins[N], tot;
vector<int> cyc;

inline void findc(int x) {
    if (ins[x] == tot) {
        cyc.push_back(x);
        while (stk.top() != x) {
            cyc.push_back(stk.top());
            stk.pop();
        }
        return;
    }
    ins[x] = tot;
    stk.push(x);
    findc(v[x]);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    // unsigned clk = clock();
    C = read(); T = read();
    while (T--) {    
        n = read(); m = read();
        tot = 0;
        for (int i = 1; i <= n + 3; i++) {
            g[i].clear();
            invg[i].clear();
            v[i] = i;
            t[i] = 0;
            ans[i] = -1;
            ins[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            cin >> op;
            if (op == 'T') {
                x = read();
                v[x] = n + 1;
                t[x] = 0;
            } else if (op == 'F') {
                x = read();
                v[x] = n + 2;
                t[x] = 0;
            } else if (op == 'U') {
                x = read();
                v[x] = n + 3;
                t[x] = 0;
            } else if (op == '+') {
                x = read(); y = read();
                v[x] = v[y];
                t[x] = t[y];
            } else if (op == '-') {
                x = read(); y = read();
                v[x] = v[y];
                t[x] = !t[y];
            }
        }

        // cout << "v:" << endl;
        // for (int i = 1; i <= n + 3; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        for (int i = 1; i <= n + 3; i++) {
            g[v[i]].push_back(edge(i, t[i]));
            invg[i].push_back(edge(v[i], t[i]));
        }
        ans[n + 1] = 1;
        dfs(n + 1);
        ans[n + 2] = 2;
        dfs(n + 2);
        ans[n + 3] = 3;
        dfs(n + 3);
        for (int i = 1; i <= n; i++) {
            if (ans[i] == -1) {
                tot++;
                while (!stk.empty()) stk.pop();
                cyc.clear();
                findc(i);
                // cout << "cyc: ";
                // for (auto c : cyc) {
                //     cout << c << " ";
                // }
                // cout << endl;
                int cbeg = cyc[0];
                bool cnt = t[cbeg];            
                int x = v[cbeg];
                // cout << "? " << cbeg << " " << v[cbeg] << " " << t[cbeg] << endl;
                while (x != cbeg) {
                    cnt ^= t[x];
                    x = v[x];
                }
                // cout << "! " << cnt << endl;
                if (cnt) {
                    ans[cbeg] = 3;
                    dfs(cbeg);
                } else {
                    ans[cbeg] = 1;
                    dfs(cbeg);
                }
            }
        }
        int usum = 0;
        for (int i = 1; i <= n; i++) {
            // cout << "ans: " << ans[i] << endl;
            if (ans[i] == 3) {
                usum++;
            }
        }
        printf("%d\n", usum);
    }
    // cerr << clock() - clk << endl;
    return 0;
}
/*
duo ce ji de qing kong!!!!!!!!!!!!!!!!!!!

g++ tribool.cpp -Wl,--stack=536870912 -O2 -std=c++14 -o tribool
*/