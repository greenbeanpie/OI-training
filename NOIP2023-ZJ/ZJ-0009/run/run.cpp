#include<bits/stdc++.h>
using namespace std;
#define int long long
#define L(i, l, r) for (int i = (l); i <= (r); i++)
#define R(i, l, r) for (int i = (l); i >= (r); i--)
#define pb push_back
inline int read() 
{
    int sum = 0, nega = 1; char ch = getchar(); 
    while(ch > '9' || ch < '0') {if(ch == '-') nega = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
    return sum * nega; 
}
const int N = 1e5 + 9; 
int tr[N << 2], tag[N << 2];
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p) {tr[p] = max(tr[lc(p)], tr[rc(p)]); return ;}
inline void push_down(int p) 
{
    if(tag[p] != 0) 
    {
        tag[lc(p)] += tag[p]; tag[rc(p)] += tag[p]; 
        tr[lc(p)] += tag[p], tr[rc(p)] += tag[p]; tag[p] = 0; return ;
    } 
    return ;
} 
inline void build(int l, int r, int p) 
{
    tr[p] = tag[p] = 0; 
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, lc(p)); build(mid + 1, r, rc(p));
    push_up(p); return ;
}
inline void update(int l, int r, int p, int L, int R, int v) 
{
    if(L <= l && r <= R) 
    {
        tag[p] += v, tr[p] += v; return ; 
    } 
    push_down(p);
    int mid = (l + r) >> 1; 
    if(mid >= L) update(l, mid, lc(p), L, R, v);
    if(mid < R) update(mid + 1, r, rc(p), L, R, v); 
    push_up(p); return ; 
} 
inline int query(int l, int r, int p, int L, int R) 
{
    if(L <= l && r <= R) return tr[p];
    push_down(p); 
    int mid = (l + r) >> 1, res = -1e17;
    if(mid >= L) res = max(res, query(l, mid, lc(p), L, R));
    if(mid < R) res = max(res, query(mid + 1, r, rc(p), L, R));
    return res;  
}
int C, T, n, m, k, d;
struct node 
{
    int t, v; 
};
vector<node> G[N];
inline void solve() 
{
    n = read() + 1, m = read(), k = read() + 1, d = read();
    L(i, 1, n) G[i].clear(); 
    L(i, 1, m) 
    {
        int x = read() + 1, y = read(), v = read();
        G[x].pb(node{x - y, v}); 
    }
    build(1, n, 1);     
    L(i, 2, n) 
    {     
        int l = max(1ll, i - k), r = i - 1;
        int val = query(1, n, 1, l, r); 
        update(1, n, 1, i, i, val); 
        update(1, n, 1, 1, i - 1, -d); 
        for (auto t : G[i]) 
        {
            int w = t.t, v = t.v; 
            update(1, n, 1, 1, w, v); 
        }
    }
    printf("%lld\n", query(1, n, 1, n - k + 1, n)); return ; 
}
inline void work() 
{
    n = read(), m = read(), k = read(), d = read();
    int ans = 0;  
    L(i, 1, m) 
    {
        int x = read(), y = read(), v = read(); 
        if(y <= k) ans += max(0ll, v - d * y); 
    }
    printf("%lld\n", ans); return ;
}
signed main() 
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout); 
    C = read(), T = read();
    if(C <= 14)
    {
        L(i, 1, T) solve();
    }
    else 
    {
        L(i, 1, T) work();
    } 
    return 0; 
}