#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int x[500005], y[500005];
bool dp[3005][3005];
// set<pair<int,int>>s;
bool flag = true;
// #define cmp(a,b) (flag?((a)>(b)):((a)<(b)))
// bool dfs( int i, int j ) {
//     if ( s.count(make_pair(i,j))) return false;
//     s.emplace(i,j);
//     // cerr << i << " " << j << endl;
//     if ( i == n && j == m ) return true;
//     if ( i < n && j < m && cmp(x[i+1],y[j+1]) ) {
//         if ( dfs(i+1,j+1) ) return true;
//     }
//     if ( i < n && cmp(x[i+1],y[j]) ) {
//         if ( dfs(i+1,j) ) return true;
//     }
//     if ( j < m && cmp(x[i],y[j+1]) ) {
//         if ( dfs(i,j+1) ) return true;
//     }
//     return false;
// }
bool work() {
    if ( (x[1]-y[1]) > 0 && (x[n]-y[m]) > 0 ) {
        flag = true;
    } else if ( (x[1]-y[1]) < 0 && (x[n]-y[m]) < 0 ) {
        flag = false;
    } else return false;
    dp[1][1] = true;
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= m; ++j ) {
            if ( i == 1 && j == 1 ) continue;
            if ( flag ? ( x[i] > y[j] ) : ( x[i] < y[j] ) ) {
                dp[i][j] = (dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1]);
            }
            // cerr << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    // putchar(dfs(1,1)?'1':'0');
    putchar(dp[n][m]?'1':'0');
}
int main() {
    scanf("%*d%d%d%ds", &n, &m, &q);
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", x+i);
    }
    for ( int i = 1; i <= m; ++i ) {
        scanf("%d", y+i);
    }
    work();
}