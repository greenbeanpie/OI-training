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
const int N = 1e5 + 9; 
int ans, id[N], bl[N], C, T, n, m;
vector<int> G[2][N]; 
int col[N]; 
char op[10]; 
int ok, nw, be; 
inline void dfs(int u) 
{
    nw++; 
    if(u == n + 1) be = 1;
    if(u == n + 2) be = 2; 
    for (auto v : G[0][u]) 
    {
        if(col[v] == -1) {col[v] = col[u]; dfs(v);}
        else if(col[u] != col[v]) ok = 1; 
    }
    for (auto v : G[1][u]) 
    {
        if(col[v] == -1) {col[v] = col[u] ^ 1; dfs(v);}
        else if(col[u] == col[v]) ok = 1;
    } return ; 
}
inline void solve() 
{
    n = read(), m = read();
    L(i, 1, n + 2) id[i] = i, bl[i] = 0, col[i] = -1;
    L(i, 1, n + 2) 
        L(j, 0, 1) G[j][i].clear();  
    L(i, 1, m) 
    {
        scanf("%s", op + 1); 
        if(op[1] == '+') 
        {
            int x = read(), y = read(); 
            id[x] = id[y], bl[x] = bl[y];
        }
        else if(op[1] == '-') 
        {
            int x = read(), y = read();
            id[x] = id[y], bl[x] = bl[y] ^ 1;  
        }
        else if(op[1] == 'U') 
        {
            int x = read(); id[x] = n + 1;
        }
        else 
        {
            int x = read(); id[x] = n + 2;
        }
    }
//    L(i, 1, n) cout << id[i] << " " << bl[i] << "awa" << endl; 
    ans = 0; 
    L(i, 1, n) G[bl[i]][i].pb(id[i]), G[bl[i]][id[i]].pb(i); 
    L(i, 1, n + 2) 
        if(col[i] == -1) 
        {
            ok = nw = be = 0; col[i] = 0; 
            dfs(i); 
            if(be == 1) ans += nw; 
            else if(be == 0 && ok) ans += nw; 
        }
    printf("%d\n", ans - 1); 
    return ; 
} 
signed main() 
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout); 
    C = read(), T = read();
    L(i, 1, T) solve();
    return 0; 
}