#include<bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 5e5 + 9; 
int px[N], py[N], c, n, m, q, x[N], y[N];
int ls[N], rs[N], rt, sta[N], top; 
int mx[N << 2], mn[N << 2]; 
int res = -1; 
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p) 
{
    mx[p] = max(mx[lc(p)], mx[rc(p)]);
    mn[p] = min(mn[lc(p)], mn[rc(p)]);
}
inline void build(int l, int r, int p) 
{
    if(l == r) {mx[p] = mn[p] = y[l]; return ;}
    int mid = (l + r) >> 1; 
    build(l, mid, lc(p)), build(mid + 1, r, rc(p)); push_up(p); return ;
}
inline int get1(int l, int r, int p, int L, int R, int v) 
{
    if(mn[p] >= v) return -1; 
    if(l == r) return l; 
    if(L <= l && r <= R) 
    {
        int mid = (l + r) >> 1; 
        if(mn[rc(p)] < v) return get1(mid + 1, r, rc(p), L, R, v);
        else return get1(l, mid, lc(p), L, R, v); 
    }
    int mid = (l + r) >> 1, pos = -1; 
    if(mid < R) pos = get1(mid + 1, r, rc(p), L, R, v);
    if(pos != -1) return pos; 
    if(mid >= L) pos = get1(l, mid, lc(p), L, R, v);
    return pos; 
}
inline int get2(int l, int r, int p, int L, int R, int v) 
{
    if(mx[p] < v) return -1; 
    if(l == r) return l;
    if(L <= l && r <= R) 
    {
        int mid = (l + r) >> 1; 
        if(mx[lc(p)] >= v) return get2(l, mid, lc(p), L, R, v);
        else return get2(mid + 1, r, rc(p), L, R, v);  
    }
    int mid = (l + r) >> 1, pos = -1; 
    if(mid >= L) pos = get2(l, mid, lc(p), L, R, v);
    if(pos != -1) return pos;
    if(mid < R) pos = get2(mid + 1, r, rc(p), L, R, v);
    return pos; 
}
inline void rebuild() 
{ 
    top = 0; 
    L(i, 1, n) ls[i] = rs[i] = 0; 
    L(i, 1, n) 
    {
        int le = 0, ri = 0; 
        while(top && x[sta[top]] > x[i]) le = sta[top], top--; 
        ls[i] = le; 
        if(top) rs[sta[top]] = i; 
        sta[++top] = i;
    }
    rt = sta[1]; 
    return ;
}
inline int solve(int id, int l, int r, int L, int R) 
{
    if(l > r) return L; 
    int mid = id;
    int t = solve(ls[id], l, mid - 1, L, R);
    if(t == -1) return -1; 
    int pos = -1; pos = get1(1, m, 1, 1, t, x[mid]); 
    if(pos < L) return -1;  
    if(mid == l) 
    {
        pos = get2(1, m, 1, pos, m, x[mid]); 
        if(pos == -1) pos = R; 
        else pos--;
    }
    return solve(rs[id], mid + 1, r, pos, R);  
}
inline void work(bool tt) 
{
    L(i, 1, max(n, m)) x[i] = y[i] = 0; 
    L(i, 1, n) x[i] = px[i];
    L(i, 1, m) y[i] = py[i]; 
    if(tt) 
    {
        int kx = read(), ky = read(); 
        L(i, 1, kx) 
        {
            int p = read(), v = read(); x[p] = v; 
        }    
        L(i, 1, ky) 
        {
            int p = read(), v = read(); y[p] = v; 
        }
    }
    bool fl = 0; 
    if(x[1] == y[1]) {putchar('0'); return ;}
    else if(x[1] < y[1]) 
    {
        swap(n, m); fl = 1;
        L(i, 1, max(n, m)) swap(x[i], y[i]); 
    }
    rebuild(); 
    build(1, m, 1); 
    if(solve(rt, 1, n, 1, m) == m) putchar('1');
    else putchar('0'); 
    if(fl) swap(n, m); 
}
signed main() 
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout); 
    c = read(), n = read(), m = read(), q = read(); 
    L(i, 1, n) px[i] = read();
    L(i, 1, m) py[i] = read();
    work(0); 
    L(i, 1, q) work(1); 
    puts("");
    return 0; 
}